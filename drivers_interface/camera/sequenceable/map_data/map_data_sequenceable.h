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

#ifndef OHOS_HDI_MAP_DATA_H
#define OHOS_HDI_MAP_DATA_H

#include <parcel.h>
#include <string>
#include <vector>
#include <any>
#include <map>
#include <mutex>
namespace OHOS {
namespace HDI {
namespace Camera {
namespace V1_0 {
using OHOS::Parcelable;
using OHOS::Parcel;
using OHOS::sptr;

class MapDataSequenceable : public Parcelable {
public:
    MapDataSequenceable() = default;
    virtual ~MapDataSequenceable() = default;

    int32_t Get(const std::string &key, int32_t &value) const;
    int32_t Get(const std::string &key, uint32_t &value) const;
    int32_t Get(const std::string &key, int64_t &value) const;
    int32_t Get(const std::string &key, double &value) const;
    int32_t Get(const std::string &key, std::string &value) const;
    int32_t Set(const std::string &key, int32_t value);
    int32_t Set(const std::string &key, uint32_t value);
    int32_t Set(const std::string &key, int64_t value);
    int32_t Set(const std::string &key, double value);
    int32_t Set(const std::string &key, const std::string& value);

    bool Marshalling(Parcel &parcel) const override;

    static sptr<MapDataSequenceable> Unmarshalling(Parcel &parcel);

private:
    enum class MapDataType : int32_t {
        I32,
        I64,
        F64,
        STRING,
        U32,
    };
    template<class T>
    int32_t Get(const std::string &key, MapDataType type, T &value) const;
    int32_t Set(const std::string &key, MapDataType type, const std::any& val);

    struct MapData {
        std::any val;
        MapDataType type;
    };
    std::map<std::string, struct MapData> datas_;
    mutable std::mutex mtx_;
};
} // V1_0
} // Camera
} // HDI
} // OHOS
#endif // OHOS_HDI_MAP_DATA_H
