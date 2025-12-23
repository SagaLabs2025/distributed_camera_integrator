/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

#include "buffer_producer_sequenceable.h"

#include "hdi_log.h"
#include <message_parcel.h>

namespace OHOS {
namespace HDI {
namespace Camera {
namespace V1_0 {
bool BufferProducerSequenceable::Marshalling(Parcel &parcel) const
{
    if (producer_ == nullptr) {
        return false;
    }

    OHOS::MessageParcel &dataParcel = static_cast<OHOS::MessageParcel &>(parcel);

    if (!dataParcel.WriteRemoteObject(producer_->AsObject())) {
        return false;
    }

    return true;
}

sptr<BufferProducerSequenceable> BufferProducerSequenceable::Unmarshalling(Parcel &parcel)
{
    sptr<BufferProducerSequenceable> sequenceData(new BufferProducerSequenceable());

    OHOS::MessageParcel &dataParcel = static_cast<OHOS::MessageParcel &>(parcel);

    sptr<IRemoteObject> remoteObj = dataParcel.ReadRemoteObject();
    if (remoteObj == nullptr) {
        HDI_CAMERA_LOGE("Remote object is null.");
        return nullptr;
    }
    sptr<OHOS::IBufferProducer> bufferProducer = OHOS::iface_cast<OHOS::IBufferProducer>(remoteObj);
    sequenceData->producer_ = bufferProducer;

    return sequenceData;
}

BufferProducerSequenceable &BufferProducerSequenceable::operator=(const BufferProducerSequenceable &other)
{
    if (&other != this) {
        producer_ = other.producer_;
    }
    return *this;
}
} // V1_0
} // Camera
} // HDI
} // OHOS
