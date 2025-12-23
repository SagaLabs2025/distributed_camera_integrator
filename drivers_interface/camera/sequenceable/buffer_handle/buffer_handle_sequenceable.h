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

#ifndef OHOS_HDI_BUFFER_HANDLE_SEQUENCEABLE_H
#define OHOS_HDI_BUFFER_HANDLE_SEQUENCEABLE_H

#include <parcel.h>
#include <string>
#include <vector>
#include "buffer_handle.h"

namespace OHOS {
namespace HDI {
namespace Camera {
namespace V1_0 {
using OHOS::Parcelable;
using OHOS::Parcel;
using OHOS::sptr;
class BufferHandleSequenceable : public Parcelable {
public:
    virtual ~BufferHandleSequenceable() = default;

    explicit BufferHandleSequenceable(BufferHandle *bufferHandle = nullptr);
    explicit BufferHandleSequenceable(const BufferHandle &bufferHandle);

    bool Marshalling(Parcel &parcel) const override;
    static sptr<BufferHandleSequenceable> Unmarshalling(Parcel &parcel);
    static BufferHandle* NewBufferHandle(uint32_t reserveFds, uint32_t reserveInts);
    void SetBufferHandle(BufferHandle *handle);
    BufferHandle* GetBufferHandle();
private:
    class BufferHandleWrap;
    std::shared_ptr<BufferHandleWrap> bufferHandleWrap_;
};
} // V1_0
} // Camera
} // HDI
} // OHOS
#endif // OHOS_HDI_BUFFER_HANDLE_SEQUENCEABLE_H
