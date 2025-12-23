/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#include "securec.h"
#include <message_parcel.h>
#include "buffer_handle_sequenceable.h"
#include "buffer_util.h"
#include "hdi_log.h"
#include "native_buffer.h"

namespace OHOS {
namespace HDI {
namespace Camera {
namespace V1_0 {
using namespace OHOS::HDI::Base;

class BufferHandleSequenceable::BufferHandleWrap {
public:
    explicit BufferHandleWrap(BufferHandle *bufferHandle = nullptr)
    {
        nativeBuffer_ = new (std::nothrow) NativeBuffer();
        if (nativeBuffer_ == nullptr) {
            HDI_CAMERA_LOGE("Native buffer object create failed.");
            return;
        }
        nativeBuffer_->SetBufferHandle(bufferHandle);
    }
    sptr<NativeBuffer> nativeBuffer_;
};

BufferHandleSequenceable::BufferHandleSequenceable(const BufferHandle &bufferHandle)
{
    auto newBufferHandle = NewBufferHandle(bufferHandle.reserveFds, bufferHandle.reserveInts);
    bufferHandleWrap_ = std::make_shared<BufferHandleWrap>(newBufferHandle);
}

BufferHandleSequenceable::BufferHandleSequenceable(BufferHandle *bufferHandle)
{
    bufferHandleWrap_ = std::make_shared<BufferHandleWrap>(bufferHandle);
}

BufferHandle* BufferHandleSequenceable::NewBufferHandle(uint32_t reserveFds, uint32_t reserveInts)
{
    return AllocateNativeBufferHandle(reserveFds, reserveInts);
}

void BufferHandleSequenceable::SetBufferHandle(BufferHandle *handle)
{
    if (bufferHandleWrap_->nativeBuffer_ != nullptr) {
        bufferHandleWrap_->nativeBuffer_->SetBufferHandle(handle);
    }
}
BufferHandle* BufferHandleSequenceable::GetBufferHandle()
{
    if (bufferHandleWrap_->nativeBuffer_ == nullptr) {
        return nullptr;
    }
    return bufferHandleWrap_->nativeBuffer_->GetBufferHandle();
}

bool BufferHandleSequenceable::Marshalling(Parcel &parcel) const
{
    if (bufferHandleWrap_->nativeBuffer_ == nullptr) {
        return false;
    }
    return bufferHandleWrap_->nativeBuffer_->Marshalling(parcel);
}

sptr<BufferHandleSequenceable> BufferHandleSequenceable::Unmarshalling(Parcel &parcel)
{
    sptr<BufferHandleSequenceable> sequenceObj(new BufferHandleSequenceable());
    if (sequenceObj->bufferHandleWrap_ == nullptr) {
        return nullptr;
    }
    sequenceObj->bufferHandleWrap_->nativeBuffer_ = NativeBuffer::Unmarshalling(parcel);
    return sequenceObj;
}

} // V1_0
} // Camera
} // HDI
} // OHOS