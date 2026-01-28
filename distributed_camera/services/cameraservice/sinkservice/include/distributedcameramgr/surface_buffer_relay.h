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

#ifndef OHOS_SURFACE_BUFFER_RELAY_H
#define OHOS_SURFACE_BUFFER_RELAY_H

#include "surface.h"
#include "surface_buffer.h"
#include "ibuffer_consumer_listener.h"
#include <functional>
#include <map>
#include <mutex>
#include <vector>
#include <atomic>

namespace OHOS {
namespace DistributedHardware {

// IMU数据key
constexpr uint32_t ATTRKEY_ROI_METADATA = 4101;
constexpr size_t IMU_DATA_SIZE = 768;

// IMU数据回调
using ImuDataCallback = std::function<void(uint32_t frameIndex, const std::vector<uint8_t>& imuData)>;

class SurfaceBufferRelay : public IBufferConsumerListener {
public:
    SurfaceBufferRelay();
    ~SurfaceBufferRelay() override;
    
    // 初始化
    int32_t Init(uint32_t width, uint32_t height, int32_t format);
    
    // 获取Camera使用的Surface
    sptr<Surface> GetCameraSurface();
    
    // 设置编码器Surface
    int32_t SetEncoderSurface(sptr<Surface> encoderSurface);
    
    // 设置IMU数据回调
    void SetImuDataCallback(ImuDataCallback callback);
    
    // IBufferConsumerListener接口
    void OnBufferAvailable() override;
    
    // 释放
    void Release();
    
private:
    // 从Camera Surface获取Buffer并中继
    void RelayBufferFromCamera();
    
    // 提取IMU数据
    bool ExtractImuData(sptr<SurfaceBuffer> buffer, std::vector<uint8_t>& imuData);
    
    // 将Buffer传递给编码器(使用AttachAndFlushBuffer)
    int32_t AttachBufferToEncoder(sptr<SurfaceBuffer> buffer);
    
    // 编码器释放Buffer回调
    void OnEncoderReleaseBuffer(sptr<SurfaceBuffer>& buffer, int32_t fence);
    
    // 将Buffer归还Camera
    int32_t ReturnBufferToCamera(sptr<SurfaceBuffer> buffer, int32_t fence);
    
private:
    // Camera Surface (Consumer)
    sptr<IConsumerSurface> cameraConsumerSurface_;
    sptr<Surface> cameraProducerSurface_;
    
    // Encoder Surface (Producer)
    sptr<Surface> encoderSurface_;
    
    // Buffer追踪
    std::mutex bufferMapMutex_;
    std::map<void*, sptr<SurfaceBuffer>> bufferMap_;
    
    // IMU数据回调
    ImuDataCallback imuCallback_;
    
    // 帧计数
    std::atomic<uint32_t> frameIndex_;
    
    // 状态
    std::atomic<bool> isRunning_;
};

} // namespace DistributedHardware
} // namespace OHOS
#endif // OHOS_SURFACE_BUFFER_RELAY_H
