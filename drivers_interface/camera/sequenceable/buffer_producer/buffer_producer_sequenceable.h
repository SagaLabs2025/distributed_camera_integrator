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

#ifndef OHOS_HDI_SEQUENCE_DATA_H
#define OHOS_HDI_SEQUENCE_DATA_H

#include <parcel.h>
#include <string>
#include <vector>
#include "surface.h"

namespace OHOS {
namespace HDI {
namespace Camera {
namespace V1_0 {
using OHOS::Parcelable;
using OHOS::Parcel;
using OHOS::sptr;
using OHOS::IBufferProducer;

class BufferProducerSequenceable : public Parcelable {
public:
    BufferProducerSequenceable() = default;
    virtual ~BufferProducerSequenceable() = default;

    explicit BufferProducerSequenceable(const sptr<IBufferProducer> &producer):producer_(producer) {}
    BufferProducerSequenceable &operator=(const BufferProducerSequenceable &other);

    BufferProducerSequenceable(const BufferProducerSequenceable &other):producer_(other.producer_) {}

    bool Marshalling(Parcel &parcel) const override;

    static sptr<BufferProducerSequenceable> Unmarshalling(Parcel &parcel);

    sptr<IBufferProducer> producer_;
};
} // V1_0
} // Camera
} // HDI
} // OHOS
#endif // OHOS_HDI_SEQUENCE_DATA_H
