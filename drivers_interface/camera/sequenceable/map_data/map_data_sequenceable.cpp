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

#include "map_data_sequenceable.h"
#include "hdi_log.h"
#include <message_parcel.h>
namespace OHOS {
namespace HDI {
namespace Camera {
namespace V1_0 {
constexpr int32_t BUFFER_DATA_MAGIC = 0x4567;
constexpr int32_t BUFFER_MAX_USER_DATA_COUNT = 1000;

enum ErrorCode : int32_t {
    ERROR_OK = 0,
    ERROR_INTERNAL = -1,
    ERROR_NO_ENTRY = -2,
    ERROR_TYPE_ERROR = -3,
    ERROR_OUT_OF_RANGE = -4,
};

#define SET_DATA_FROM_POINTER(data, pointer) do { \
    if ((pointer) != nullptr) { \
        (data) = *(pointer); \
    } \
} while (0)

sptr<MapDataSequenceable> MapDataSequenceable::Unmarshalling(Parcel &parcel)
{
    int32_t magic;
    if (parcel.ReadInt32(magic) == false || magic != BUFFER_DATA_MAGIC) {
        HDI_CAMERA_LOGW("read failed, magic is error");
        return nullptr;
    }

    int32_t size = parcel.ReadInt32();
    if (size < 0 || size > BUFFER_MAX_USER_DATA_COUNT) {
        HDI_CAMERA_LOGE("invalid size: %{public}d obtained from Parcel", size);
        return nullptr;
    }
    sptr<MapDataSequenceable> sequenceData(new MapDataSequenceable());

    int32_t ret = ERROR_OK;
    for (int32_t i = 0; i < size; i++) {
        auto key = parcel.ReadString();
        auto type = static_cast<MapDataType>(parcel.ReadInt32());
        switch (type) {
            case MapDataType::I32: {
                ret = sequenceData->Set(key, type, parcel.ReadInt32());
                break;
            }
            case MapDataType::I64: {
                ret = sequenceData->Set(key, type, parcel.ReadInt64());
                break;
            }
            case MapDataType::F64: {
                ret = sequenceData->Set(key, type, parcel.ReadDouble());
                break;
            }
            case MapDataType::STRING: {
                ret = sequenceData->Set(key, type, parcel.ReadString());
                break;
            }
            case MapDataType::U32: {
                ret = sequenceData->Set(key, type, parcel.ReadUint32());
                break;
            }
            default: break;
        }

        if (ret != ERROR_OK) {
            HDI_CAMERA_LOGE("Set extra data failed, return %{public}d", ret);
            return nullptr;
        }
    }
    return sequenceData;
}

bool MapDataSequenceable::Marshalling(Parcel &parcel) const
{
    OHOS::MessageParcel &dataParcel = static_cast<OHOS::MessageParcel &>(parcel);
    std::lock_guard<std::mutex> lockGuard(mtx_);
    dataParcel.WriteInt32(BUFFER_DATA_MAGIC);
    dataParcel.WriteInt32(datas_.size());
    for (const auto &[key, data] : datas_) {
        dataParcel.WriteString(key);
        dataParcel.WriteInt32(static_cast<int32_t>(data.type));
        switch (data.type) {
            case MapDataType::I32: {
                int32_t i32 = -1;
                auto pVal = std::any_cast<int32_t>(&data.val);
                SET_DATA_FROM_POINTER(i32, pVal);
                dataParcel.WriteInt32(i32);
                break;
            }
            case MapDataType::I64: {
                int64_t i64 = -1;
                auto pVal = std::any_cast<int64_t>(&data.val);
                SET_DATA_FROM_POINTER(i64, pVal);
                dataParcel.WriteInt64(i64);
                break;
            }
            case MapDataType::F64: {
                double f64 = -1;
                auto pVal = std::any_cast<double>(&data.val);
                SET_DATA_FROM_POINTER(f64, pVal);
                dataParcel.WriteDouble(f64);
                break;
            }
            case MapDataType::STRING: {
                std::string string = "-1";
                auto pVal = std::any_cast<std::string>(&data.val);
                SET_DATA_FROM_POINTER(string, pVal);
                dataParcel.WriteString(string);
                break;
            }
            case MapDataType::U32: {
                uint32_t u32 = 0;
                auto pVal = std::any_cast<uint32_t>(&data.val);
                SET_DATA_FROM_POINTER(u32, pVal);
                dataParcel.WriteUint32(u32);
                break;
            }
            default:
                break;
        }
    }
    return true;
}

int32_t MapDataSequenceable::Get(const std::string &key, int32_t &value) const
{
    return Get<int32_t>(key, MapDataType::I32, value);
}

int32_t MapDataSequenceable::Get(const std::string &key, uint32_t &value) const
{
    return Get<uint32_t>(key, MapDataType::U32, value);
}

int32_t MapDataSequenceable::Get(const std::string &key, int64_t &value) const
{
    return Get<int64_t>(key, MapDataType::I64, value);
}

int32_t MapDataSequenceable::Get(const std::string &key, double &value) const
{
    return Get<double>(key, MapDataType::F64, value);
}

int32_t MapDataSequenceable::Get(const std::string &key, std::string &value) const
{
    return Get<std::string>(key, MapDataType::STRING, value);
}

int32_t MapDataSequenceable::Set(const std::string &key, int32_t value)
{
    return Set(key, MapDataType::I32, value);
}

int32_t MapDataSequenceable::Set(const std::string &key, uint32_t value)
{
    return Set(key, MapDataType::U32, value);
}

int32_t MapDataSequenceable::Set(const std::string &key, int64_t value)
{
    return Set(key, MapDataType::I64, value);
}

int32_t MapDataSequenceable::Set(const std::string &key, double value)
{
    return Set(key, MapDataType::F64, value);
}

int32_t MapDataSequenceable::Set(const std::string &key, const std::string& value)
{
    return Set(key, MapDataType::STRING, value);
}

template<class T>
int32_t MapDataSequenceable::Get(const std::string &key, MapDataType type, T &value) const
{
    std::lock_guard<std::mutex> lockGuard(mtx_);
    auto it = datas_.find(key);
    if (it == datas_.end()) {
        return ERROR_NO_ENTRY;
    }
    if (it->second.type != type) {
        return ERROR_TYPE_ERROR;
    }
    auto pVal = std::any_cast<T>(&it->second.val);
    if (pVal == nullptr) {
        return ERROR_TYPE_ERROR;
    }
    value = *pVal;
    return ERROR_OK;
}

int32_t MapDataSequenceable::Set(const std::string &key, MapDataType type, const std::any& val)
{
    std::lock_guard<std::mutex> lockGuard(mtx_);
    auto it = datas_.find(key);
    if (it == datas_.end() && datas_.size() > BUFFER_MAX_USER_DATA_COUNT) {
        HDI_CAMERA_LOGW("SurfaceBuffer has too many extra data, cannot save one more!!!");
        return ERROR_OUT_OF_RANGE;
    }
    datas_[key].type = type;
    datas_[key].val = val;
    return ERROR_OK;
}

}
}
}
}