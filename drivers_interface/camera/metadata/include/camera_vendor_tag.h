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

#ifndef CAMERA_VENDOR_TAG_H
#define CAMERA_VENDOR_TAG_H

#include <vector>
#include "camera_device_ability_items.h"
#include "camera_metadata_operator.h"

namespace OHOS::Camera {
// Example vendor tag operator interfaces, vendor should implements these interfaces.
class CameraVendorTag {
public:
    CameraVendorTag() = default;
    virtual ~CameraVendorTag() = default;
    virtual uint32_t GetVendorTagCount() = 0;
    virtual const char* GetVendorTagName(const uint32_t tag) = 0;
    virtual int32_t GetVendorTagType(const uint32_t tag) = 0;
    virtual void GetAllVendorTags(std::vector<vendorTag_t>& tagVec) = 0;
};

typedef CameraVendorTag* CreateCameraVendorTag();
}
#endif /* CAMERA_VENDOR_TAG_H */
