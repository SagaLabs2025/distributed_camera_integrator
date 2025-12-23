/*
 * Copyright (c) 2021 - 2023 Huawei Device Co., Ltd.
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

#ifndef CAMERA_METADATA_INFO_H
#define CAMERA_METADATA_INFO_H

#include <cstdio>
#include <cstdint>
#include <string>
#include <parcel.h>
#include "camera_metadata_operator.h"

static constexpr uint32_t MAX_SUPPORTED_TAGS = 1000;
static constexpr uint32_t MAX_SUPPORTED_ITEMS = (12000 * 2 * 2);
static constexpr uint32_t MAX_ITEM_CAPACITY = (1000 * 10);
static constexpr uint32_t MAX_DATA_CAPACITY = (1000 * 10 * 10 * 10);
static constexpr uint32_t MIN_VEC_SIZE = 12;

#define METADATA_PACKET_ALIGNMENT \
    MaxAlignment(MaxAlignment(DATA_ALIGNMENT, METADATA_ALIGNMENT), ITEM_ALIGNMENT)

namespace OHOS::Camera {
class CameraMetadata : public Parcelable {
public:
    CameraMetadata(size_t itemCapacity, size_t dataCapacity);
    ~CameraMetadata();

    bool addEntry(uint32_t item, const void *data, size_t data_count);
    bool updateEntry(uint32_t tag, const void *data, size_t data_count);
    common_metadata_header_t *get();
    const common_metadata_header_t *get() const;
    bool isValid() const;
    bool Marshalling(Parcel &parcel) const override;
    static CameraMetadata* Unmarshalling(Parcel &parcel);

private:
    common_metadata_header_t *metadata_;

    bool resize_add_metadata(uint32_t item, const void *data, size_t data_count);
    void replace_metadata(common_metadata_header_t *newMetadata);
    static uint32_t AlignTo(uint32_t val, uint32_t alignment);
    static uint32_t MaxAlignment(uint32_t dataAlignment, uint32_t metadataAlignment);
    static size_t CalculateCameraMetadataMemoryRequired(uint32_t itemCount, uint32_t dataCount);
    static int UpdateCameraMetadataItemSize(camera_metadata_item_entry_t *item, uint32_t dataCount,
        common_metadata_header_t *dst, const void *data);
    static int AddCameraMetadataItemVerify(common_metadata_header_t *dst,
        uint32_t item, const void *data, size_t dataCount, uint32_t *dataType);
    static int moveMetadataMemery(common_metadata_header_t *dst,
        camera_metadata_item_entry_t *itemToDelete, size_t dataBytes);
    static int copyMetadataMemory(common_metadata_header_t *dst, camera_metadata_item_entry_t *item,
        size_t dataPayloadSize, const void *data);
    static bool CheckItemDataType(camera_metadata_item_entry_t &item);

public:
    // Allocate a new camera metadata buffer and return the metadata header
    static common_metadata_header_t *AllocateCameraMetadataBuffer(uint32_t item_capacity, uint32_t data_capacity);

    // Is camera metadata item exist
    static bool IsCameraMetadataItemExist(const common_metadata_header_t *src, uint32_t item);

    // Find camera metadata item and fill the found item
    static int FindCameraMetadataItem(const common_metadata_header_t *src, uint32_t item,
        camera_metadata_item_t *metadataItem);

    // Find camera metadata item index if the item exists
    static int FindCameraMetadataItemIndex(const common_metadata_header_t *src, uint32_t item, uint32_t *index,
        bool isPrintLog = false);

    // Get camera metadata item name
    static const char *GetCameraMetadataItemName(uint32_t item);

    // Update camera metadata item and fill the updated item
    static int UpdateCameraMetadataItem(common_metadata_header_t *dst, uint32_t item, const void *data,
        uint32_t dataCount, camera_metadata_item_t *updatedItem);

    // Update camera metadata item by index and fill the updated item
    static int UpdateCameraMetadataItemByIndex(common_metadata_header_t *dst, uint32_t index, const void *data,
        uint32_t dataCount, camera_metadata_item_t *updated_item);

    // Add camera metadata item
    static int AddCameraMetadataItem(common_metadata_header_t *dst, uint32_t item, const void *data, size_t dataCount);

    // Delete camera metadata item
    static int DeleteCameraMetadataItem(common_metadata_header_t *dst, uint32_t item);

    // Delete camera metadata item by index
    static int DeleteCameraMetadataItemByIndex(common_metadata_header_t *dst, uint32_t index);

    // Free camera metadata buffer
    static void FreeCameraMetadataBuffer(common_metadata_header_t *dst);

    static std::string MetadataItemDump(const common_metadata_header_t *metadataHeader, uint32_t item);

    static std::string FormatCameraMetadataToString(const common_metadata_header_t *metadataHeader);

    // Internal use
    static camera_metadata_item_entry_t *GetMetadataItems(const common_metadata_header_t *metadataHeader);
    static uint8_t *GetMetadataData(const common_metadata_header_t *metadataHeader);
    static int GetCameraMetadataItem(const common_metadata_header_t *src, uint32_t index, camera_metadata_item_t *item);
    static uint32_t GetCameraMetadataItemCount(const common_metadata_header_t *metadata_header);
    static uint32_t GetCameraMetadataItemCapacity(const common_metadata_header_t *metadata_header);
    static uint32_t GetCameraMetadataDataSize(const common_metadata_header_t *metadata_header);
    static int32_t CopyCameraMetadataItems(common_metadata_header_t *newMetadata,
        const common_metadata_header_t *oldMetadata);
    static int32_t CalculateCameraMetadataItemDataSize(uint32_t type, size_t data_count);
    static int32_t GetCameraMetadataItemType(uint32_t item, uint32_t *data_type);
    static common_metadata_header_t *FillCameraMetadata(common_metadata_header_t *buffer, size_t memoryRequired,
        uint32_t itemCapacity, uint32_t dataCapacity);
    static int32_t GetMetadataSection(uint32_t itemSection, uint32_t *section);
    static int MetadataExpandItemMem(common_metadata_header_t *dst, camera_metadata_item_entry_t *item,
        size_t oldItemSize);
    static int32_t GetAllVendorTags(std::vector<vendorTag_t>& tagVec);
};
} // namespace Camera
#endif /* CAMERA_METADATA_INFO_H */
