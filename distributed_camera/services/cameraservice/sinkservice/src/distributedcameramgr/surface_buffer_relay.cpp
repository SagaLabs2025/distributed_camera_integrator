/*
 * Copyright (c) 2021-2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "surface_buffer_relay.h"
#include "distributed_hardware_log.h"
#include "distributed_camera_errno.h"
#include <unistd.h>

namespace OHOS {
namespace DistributedHardware {
SurfaceBufferRelay::SurfaceBufferRelay()
    : frameIndex_(0), isRunning_(false)
{
    DHLOGI("SurfaceBufferRelay created");
}

SurfaceBufferRelay::~SurfaceBufferRelay()
{
    Release();
    DHLOGI("SurfaceBufferRelay destroyed");
}

int32_t SurfaceBufferRelay::Init(uint32_t width, uint32_t height, int32_t format)
{
    DHLOGI("SurfaceBufferRelay Init: %ux%u, format=%d", width, height, format);
    
    // 创建Camera使用的Consumer Surface
    cameraConsumerSurface_ = IConsumerSurface::Create();
    if (cameraConsumerSurface_ == nullptr) {
        DHLOGE("Create camera consumer surface failed");
        return DCAMERA_INIT_ERR;
    }
    
    // 设置Surface属性
    cameraConsumerSurface_->SetDefaultWidthAndHeight(width, height);
    cameraConsumerSurface_->SetDefaultFormat(format);
    cameraConsumerSurface_->SetDefaultUsage(
        BUFFER_USAGE_CPU_READ | BUFFER_USAGE_MEM_DMA);
    
    // 注册Buffer可用监听
    GSError ret = cameraConsumerSurface_->RegisterConsumerListener(this);
    if (ret != GSERROR_OK) {
        DHLOGE("Register consumer listener failed: %d", ret);
        return DCAMERA_BAD_OPERATE;
    }
    
    // 创建Producer Surface供Camera使用
    sptr<IBufferProducer> producer = cameraConsumerSurface_->GetProducer();
    if (producer == nullptr) {
        DHLOGE("Get producer failed");
        return DCAMERA_INIT_ERR;
    }
    
    cameraProducerSurface_ = Surface::CreateSurfaceAsProducer(producer);
    if (cameraProducerSurface_ == nullptr) {
        DHLOGE("Create camera producer surface failed");
        return DCAMERA_INIT_ERR;
    }
    
    isRunning_ = true;
    DHLOGI("SurfaceBufferRelay initialized successfully");
    return DCAMERA_OK;
}

sptr<Surface> SurfaceBufferRelay::GetCameraSurface()
{
    return cameraProducerSurface_;
}

int32_t SurfaceBufferRelay::SetEncoderSurface(sptr<Surface> encoderSurface)
{
    if (encoderSurface == nullptr) {
        DHLOGE("Encoder surface is null");
        return DCAMERA_BAD_VALUE;
    }
    
    encoderSurface_ = encoderSurface;
    
    // 在Producer Surface上注册释放回调
    OnReleaseFuncWithFence releaseFunc = 
        [this](sptr<SurfaceBuffer>& buffer, int32_t fence) {
            OnEncoderReleaseBuffer(buffer, fence);
        };
    
    GSError ret = encoderSurface_->RegisterReleaseListener(releaseFunc);
    if (ret != GSERROR_OK) {
        DHLOGE("Register release listener failed: %d", ret);
        return DCAMERA_BAD_OPERATE;
    }
    
    DHLOGI("Encoder surface set successfully");
    return DCAMERA_OK;
}

void SurfaceBufferRelay::SetImuDataCallback(ImuDataCallback callback)
{
    imuCallback_ = callback;
}

void SurfaceBufferRelay::OnBufferAvailable()
{
    if (!isRunning_) {
        return;
    }
    
    DHLOGD("OnBufferAvailable called");
    RelayBufferFromCamera();
}

void SurfaceBufferRelay::RelayBufferFromCamera()
{
    if (cameraConsumerSurface_ == nullptr || encoderSurface_ == nullptr) {
        DHLOGE("Surface not ready");
        return;
    }
    
    // 1. 从Camera Surface获取Buffer
    sptr<SurfaceBuffer> buffer;
    int32_t fence = -1;
    int64_t timestamp = 0;
    Rect damage;
    
    GSError ret = cameraConsumerSurface_->AcquireBuffer(
        buffer, fence, timestamp, damage);
    if (ret != GSERROR_OK || buffer == nullptr) {
        DHLOGE("Acquire buffer from camera failed: %d", ret);
        return;
    }
    
    DHLOGD("Acquired buffer from camera: ts=%lld, fence=%d", timestamp, fence);
    
    // 等待fence
    if (fence >= 0) {
        close(fence);
    }
    
    // 2. 提取IMU数据
    std::vector<uint8_t> imuData;
    if (ExtractImuData(buffer, imuData)) {
        DHLOGI("Extracted IMU data: %zu bytes, frame=%u", 
               imuData.size(), frameIndex_.load());
        
        // 回调通知
        if (imuCallback_) {
            imuCallback_(frameIndex_.load(), imuData);
        }
    }
    
    // 3. 使用AttachAndFlushBuffer将Buffer传递给编码器
    ret = AttachBufferToEncoder(buffer);
    if (ret != DCAMERA_OK) {
        DHLOGE("Attach buffer to encoder failed: %d", ret);
        // 失败则直接归还给Camera
        cameraConsumerSurface_->ReleaseBuffer(buffer, -1);
        return;
    }
    
    // 4. 记录Buffer用于后续归还
    {
        std::lock_guard<std::mutex> lock(bufferMapMutex_);
        bufferMap_[buffer->GetVirAddr()] = buffer;
    }
    
    frameIndex_++;
}

bool SurfaceBufferRelay::ExtractImuData(
    sptr<SurfaceBuffer> buffer, std::vector<uint8_t>& imuData)
{
    if (buffer == nullptr) {
        return false;
    }
    
    // 使用GetMetadata获取IMU数据
    GSError ret = buffer->GetMetadata(ATTRKEY_ROI_METADATA, imuData);
    
    if (ret != GSERROR_OK) {
        DHLOGD("Get IMU metadata failed: %d (may not exist)", ret);
        return false;
    }
    
    if (imuData.size() != IMU_DATA_SIZE) {
        DHLOGW("IMU data size mismatch: %zu != %zu", 
               imuData.size(), IMU_DATA_SIZE);
        return false;
    }
    
    return true;
}

int32_t SurfaceBufferRelay::AttachBufferToEncoder(sptr<SurfaceBuffer> buffer)
{
    if (encoderSurface_ == nullptr || buffer == nullptr) {
        return DCAMERA_BAD_VALUE;
    }
    
    // 使用AttachAndFlushBuffer合并两次IPC为一次
    BufferFlushConfig flushConfig = {
        {0, 0, buffer->GetWidth(), buffer->GetHeight()}, 
        0  // timestamp
    };
    
    GSError ret = encoderSurface_->AttachAndFlushBuffer(buffer, -1, flushConfig);
    if (ret != GSERROR_OK) {
        DHLOGE("AttachAndFlushBuffer failed: %d", ret);
        return DCAMERA_BAD_OPERATE;
    }
    
    DHLOGD("Buffer attached to encoder successfully");
    return DCAMERA_OK;
}

void SurfaceBufferRelay::OnEncoderReleaseBuffer(
    sptr<SurfaceBuffer>& buffer, int32_t fence)
{
    DHLOGD("Encoder released buffer, fence=%d", fence);
    
    if (buffer == nullptr) {
        DHLOGE("Released buffer is null");
        return;
    }
    
    // 从编码器Surface分离Buffer
    GSError ret = encoderSurface_->RequestAndDetachBuffer(buffer, fence);
    if (ret != GSERROR_OK) {
        DHLOGW("RequestAndDetachBuffer failed: %d", ret);
    }
    
    // 归还给Camera
    ReturnBufferToCamera(buffer, fence);
    
    // 从追踪map中移除
    {
        std::lock_guard<std::mutex> lock(bufferMapMutex_);
        bufferMap_.erase(buffer->GetVirAddr());
    }
}

int32_t SurfaceBufferRelay::ReturnBufferToCamera(
    sptr<SurfaceBuffer> buffer, int32_t fence)
{
    if (cameraConsumerSurface_ == nullptr || buffer == nullptr) {
        return DCAMERA_BAD_VALUE;
    }
    
    // 归还Buffer给Camera
    GSError ret = cameraConsumerSurface_->ReleaseBuffer(buffer, fence);
    if (ret != GSERROR_OK) {
        DHLOGE("Release buffer to camera failed: %d", ret);
        return DCAMERA_BAD_OPERATE;
    }
    
    DHLOGD("Buffer returned to camera successfully");
    return DCAMERA_OK;
}

void SurfaceBufferRelay::Release()
{
    isRunning_ = false;
    
    if (cameraConsumerSurface_ != nullptr) {
        cameraConsumerSurface_->UnregisterConsumerListener();
        cameraConsumerSurface_ = nullptr;
    }
    
    cameraProducerSurface_ = nullptr;
    encoderSurface_ = nullptr;
    
    {
        std::lock_guard<std::mutex> lock(bufferMapMutex_);
        bufferMap_.clear();
    }
    
    DHLOGI("SurfaceBufferRelay released");
}

} // namespace DistributedHardware
} // namespace OHOS
