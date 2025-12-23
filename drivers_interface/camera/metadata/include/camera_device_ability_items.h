/*
 * Copyright (c) 2021-2023 Huawei Device Co., Ltd.
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

#ifndef CAMERA_DEVICE_ABILITY_ITEMS_H
#define CAMERA_DEVICE_ABILITY_ITEMS_H

typedef enum camera_ability_section {
    // Camera attribute information: position(facing), type, connection, description, sensor, lens description
    OHOS_CAMERA_PROPERTIES = 0,
    OHOS_CAMERA_LENS,
    OHOS_CAMERA_SENSOR,
    OHOS_CAMERA_SENSOR_INFO,
    OHOS_CAMERA_STATISTICS,

    // Camera device image acquisition
    OHOS_DEVICE_CONTROL = 0x1000, // Overall control, such as turning off automatic 3A, operating mode
    OHOS_DEVICE_EXPOSURE,
    OHOS_DEVICE_FOCUS,
    OHOS_DEVICE_WHITE_BLANCE,
    OHOS_DEVICE_FLASH,
    OHOS_DEVICE_ZOOM,
    OHOS_LIGHT_STATUS,

    // Camera effects & algorithms
    OHOS_CAMERA_EFFECT = 0x2000,

    // Camera flow control related
    OHOS_STREAM_ABILITY = 0x3000,
    OHOS_STREAM_CONTROL, // General control: frame rate, resolution, mirroring
    OHOS_STREAM_JPEG,
    OHOS_STREAM_VIDEO, // Video encoding related
    OHOS_STREAM_DEPTH,
    OHOS_STREAM_METADATA,
    OHOS_STREAM_METADATA_FACE,
    OHOS_STREAM_METADATA_BODY,

    // Secure camera control related
    OHOS_CAMERA_SECURE = 0x4000,
    // Xmage camera ability
    OHOS_XMAGE_COLOR_ABILITY = 0x5000,

    OHOS_ABILITY_SECTION_END = 0x6000,

    // Start vendor tag section
    OHOS_VENDOR_SECTION = 0X8000
} camera_ability_section_t;

typedef enum camera_device_metadata_section_start {
    OHOS_CAMERA_PROPERTIES_START = OHOS_CAMERA_PROPERTIES << 16,
    OHOS_CAMERA_LENS_START = OHOS_CAMERA_LENS << 16,
    OHOS_CAMERA_SENSOR_START = OHOS_CAMERA_SENSOR << 16,
    OHOS_CAMERA_SENSOR_INFO_START = OHOS_CAMERA_SENSOR_INFO << 16,
    OHOS_CAMERA_STATISTICS_START = OHOS_CAMERA_STATISTICS << 16,

    OHOS_DEVICE_CONTROL_START = OHOS_DEVICE_CONTROL << 16,
    OHOS_DEVICE_EXPOSURE_START = OHOS_DEVICE_EXPOSURE << 16,
    OHOS_DEVICE_FOCUS_START = OHOS_DEVICE_FOCUS << 16,
    OHOS_DEVICE_WHITE_BLANCE_START = OHOS_DEVICE_WHITE_BLANCE << 16,
    OHOS_DEVICE_FLASH_START = OHOS_DEVICE_FLASH << 16,
    OHOS_DEVICE_ZOOM_START = OHOS_DEVICE_ZOOM << 16,

    OHOS_CAMERA_EFFECT_START = OHOS_CAMERA_EFFECT << 16,

    OHOS_STREAM_ABILITY_START = OHOS_STREAM_ABILITY << 16,
    OHOS_STREAM_CONTROL_START = OHOS_STREAM_CONTROL << 16,
    OHOS_STREAM_JPEG_START = OHOS_STREAM_JPEG << 16,
    OHOS_STREAM_VIDEO_START = OHOS_STREAM_VIDEO << 16,
    OHOS_STREAM_DEPTH_START = OHOS_STREAM_DEPTH << 16,
    OHOS_STREAM_METADATA_START = OHOS_STREAM_METADATA << 16,
    OHOS_STREAM_METADATA_FACE_START = OHOS_STREAM_METADATA_FACE << 16,
    OHOS_STREAM_METADATA_BODY_START = OHOS_STREAM_METADATA_BODY << 16,

    OHOS_CAMERA_SECURE_START = OHOS_CAMERA_SECURE << 16,

    OHOS_XMAGE_COLOR_MODES_START = OHOS_XMAGE_COLOR_ABILITY << 16,
    OHOS_VENDOR_SECTION_START = OHOS_VENDOR_SECTION << 16,
    OHOS_LIGHT_STATUS_START = OHOS_LIGHT_STATUS << 16,
} camera_device_info_section_start_t;

typedef enum camera_device_metadata_tag {
    // Camera attribute related item
    /**
     * ohos.ability.cameraPositon [static, enum, public]
     *
     * camera device property, report current camera position
     * (i.e. enum: FRONT/BACK/OTHER ...)
     */
    OHOS_ABILITY_CAMERA_POSITION = OHOS_CAMERA_PROPERTIES_START,
    /**
     * ohos.ability.cameraType [static, enum, public]
     *
     * camera device property, report current camera type
     * (i.e. enum: WIDE_ANGLE/ULTRA_WIDE/TELTPHOTO/TRUE_DEAPTH/LOGICAL/UNSPECIFIED ...)
     */
    OHOS_ABILITY_CAMERA_TYPE,
    /**
     * ohos.ability.cameraConnectionType [static, enum, public]
     *
     * camera device property, report current camera connection type
     * (i.e. enum: BUILTIN/USB_PLUGIN/REMOTE ...)
     */
    OHOS_ABILITY_CAMERA_CONNECTION_TYPE,
    /**
     * ohos.ability.memoryType [static, enum, public]
     *
     * camera device property, report current camera memory type
     * (i.e. enum: mmap/userptr/overlay/dmabuf ...)
     */
    OHOS_ABILITY_MEMORY_TYPE,
    /**
     * ohos.ability.fpsRanges [static, int32[], public]
     *
     * camera device property, report current camera support frame/second range
     * (i.e. int32[]: rangeMin1, rangeMax1, rangeMin2, rangeMax2, ...)
     */
    OHOS_ABILITY_FPS_RANGES,
    /**
     * ohos.ability.flashAvailable [static, enum, public]
     *
     * camera device property, report current camera flash on/off available
     * (i.e. enum: false/true)
     */
    OHOS_ABILITY_FLASH_AVAILABLE,
    /**
     * ohos.camera.streamId [static, int32[], public]
     *
     * camera device property, set current camera stream id
     * (i.e. int32[]: streamId, streamId, ...)
     */
    OHOS_CAMERA_STREAM_ID,
    /**
     * ohos.ability.prelaunchAvailable [static, enum, public]
     *
     * camera device property, report current camera device prelaunch supported
     * (i.e. enum: enable/disable..)
     */
    OHOS_ABILITY_PRELAUNCH_AVAILABLE,
    /**
     * ohos.ability.customVideoFps [static, int32[], public]
     *
     * camera device property, report current camera support custom opreationMode video fps range
     * (i.e. int32[] ... )
     */
    OHOS_ABILITY_CUSTOM_VIDEO_FPS,
    /**
     * ohos.ability.cameraModes [static, enum[], public]
     *
     * camera device property, report current camera support camera mode
     * (i.e. enum[]: capture, video ...)
     */
    OHOS_ABILITY_CAMERA_MODES,
    /**
     * ohos.ability.sketchEnableRatio [static, float[], public]
     *
     * camera device property, report current camera device sketch camera mode support ratio
     * (i.e. float[]: mode, ratio, mode, ratio, ...)
     */
    OHOS_ABILITY_SKETCH_ENABLE_RATIO,
    /**
     * ohos.ability.sketchReferenceFovRatio [static, float[], public]
     *
     * camera device property, report current camera device sketch camera mode enable ratio
     * (i.e. float[]: mode, ratio, mode, ratio, ...)
     */
    OHOS_ABILITY_SKETCH_REFERENCE_FOV_RATIO,
    /**
     * ohos.ability.sketchInfoNotification [static, int[], public]
     *
     * camera device property, report all supported sketch info notify modes of the current camera device
     * (i.e. int[]: mode1, mode2, ...)
     */
    OHOS_ABILITY_SKETCH_INFO_NOTIFICATION,
    /**
     * ohos.ability.cameraFoldScreen [static, enum, public]
     *
     * camera device property, report current camera device fold screen
     * (i.e. enum: other/inner/outer ...)
     */
    OHOS_ABILITY_CAMERA_FOLDSCREEN_TYPE,
    /**
     * ohos.ability.availableColorSpaces [static, int32[], public]
     *
     * camera device property, report current camera device support color spaces
     * (i.e. int32[]: mode, colorSpaces[], -1, mode, colorSpaces[], -1, ...)
     */
    OHOS_ABILITY_AVAILABLE_COLOR_SPACES,
    /**
     * ohos.ability.nightModeSupportedExposureTime [static, int32[], public]
     *
     * camera device property, report current camera device the shutter duration supported by the night mode
     * (i.e. int32[]: time (millisecond), time, ...)
     */
    OHOS_ABILITY_NIGHT_MODE_SUPPORTED_EXPOSURE_TIME,
    /**
     * ohos.camera.mesureExposureTime [static, uint32, public]
     *
     * camera device property, report current camera device long exposure time by the night mode
     * (i.e. uint32: time(millisecond) ...)
     */
    OHOS_CAMERA_MESURE_EXPOSURE_TIME,
    /**
     * ohos.camera.exposureModePreviewState [static, uint32, public]
     *
     * camera device property, report current camera device exposure mode perview state by the night mode
     * (i.e. uint32 ...)
     */
    OHOS_CAMERA_EXPOSURE_MODE_PREVIEW_STATE,
    /**
     * ohos.camera.userId [static, int32[], public]
     *
     * camera device property, set userIds can be delivered during stream creation
     * to identify the user whose images are stored
     * (User IDs are bound when original images are flushed to disks.)
     * (i.e. int32[] ...)
     */
    OHOS_CAMERA_USER_ID,
    /**
     * ohos.ability.moonCaptureBoost [static, uint32[], public]
     *
     * camera device property, report current camera device moon-gazing mode
     * (i.e. uint32[] ...)
     */
    OHOS_ABILITY_MOON_CAPTURE_BOOST,
    /**
     * ohos.control.moonCaptureBoost [static, enum, public]
     *
     * camera device property, set current camera device moon-gazing mode
     * (i.e. enum: disable/enable ...)
     */
    OHOS_CONTROL_MOON_CAPTURE_BOOST,
    /**
     * ohos.status.moonCaptureDetection [static, uint32, public]
     *
     * camera device property, query current camera device detection moon-gazing mode status
     * (i.e. uint32 ...)
     */
    OHOS_STATUS_MOON_CAPTURE_DETECTION,
    /**
     * ohos.ability.captureDurationSupported [static, enum, public]
     *
     * camera device property, report current camera device
     * (i.e. enum: support/unsupport ...)
     */
    OHOS_ABILITY_CAPTURE_DURATION_SUPPORTED,
    /**
     * ohos.camera.customSnapshotDuration [static, uint32, public]
     *
     * camera device property, query current camera device
     * (i.e. uint32 ...)
     */
    OHOS_CAMERA_CUSTOM_SNAPSHOT_DURATION,
    /**
     * ohos.ability.movingPhoto [static, int32[], public]
     *
     * camera device property, report  current camera device different mode whether support living photo
     * (i.e. int32[]: mode, value, -1, ...)
     */
    OHOS_ABILITY_MOVING_PHOTO,
    /**
     * ohos.ability.flashSuggestionSupported [static, uint32[], public]
     *
     * camera device property, report current camera whether support flash suggestion
     * (i.e. uint32[]: open/close ...)
     */
    OHOS_ABILITY_FLASH_SUGGESTION_SUPPORTED,
    /**
     * ohos.control.flashSuggestionSwitch [static, enum, public]
     *
     * camera device property, set current camera whether support flash suggestion
     * (i.e. enum: support/notSupport ...)
     */
    OHOS_CONTROL_FLASH_SUGGESTION_SWITCH,
    /**
     * ohos.status.flashSuggestion [static, enum, public]
     *
     * camera device property, query current camera whether support flash suggestion
     * (i.e. enum: support/notSupport ...)
     */
    OHOS_STATUS_FLASH_SUGGESTION,
    /**
     * ohos.ability.highQualitySupport [static, byte, public]
     *
     * camera device property, report current camera whether support high quality
     * (i.e. byte: support/notSupport ...)
     */
    OHOS_ABILITY_HIGH_QUALITY_SUPPORT,
    /**
     * ohos.ability.cameraFoldStatus [static, enum, public]
     *
     * camera device property, report current camera fold status
     * (i.e. enum: nonFoldable/expanded/folded ...)
     */
    OHOS_ABILITY_CAMERA_FOLD_STATUS,
    /**
     * ohos.status.cameraFoldStatus [static, byte, public]
     *
     * camera device property, query current camera occlusion detection
     * (i.e. byte: ...)
     */
    OHOS_STATUS_CAMERA_OCCLUSION_DETECTION,
    /**
     * ohos.ability.statisticsDetectType [static, enum[], public]
     *
     * camera device property, report current camera support statistice detect type
     * (i.e. enum[]: [humanFace/human/catFace/cat/dogFace/dog/salient/barCode] ...)
     */
    OHOS_ABILITY_STATISTICS_DETECT_TYPE,
    /**
     * ohos.control.statisticsDetectSetting [static, enum[], public]
     *
     * camera device property, set current camera what statistice detect type ware supported
     * (i.e. enum[]: [humanFace/human/catFace/cat/dogFace/dog/salient/barCode] ...)
     */
    OHOS_CONTROL_STATISTICS_DETECT_SETTING,
    /**
     * ohos.ability.availableExtendedStreamInfoTypes [static, int32[], public]
     *
     * camera device property, report current camera extended streams supported by different streams in the mode
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_EXTENDED_STREAM_INFO_TYPES,
    /**
     * ohos.ability.autoDeferredVideoEnhance [static, enum, public]
     *
     * camera device property, report current camera whether support auto deferred video enhance
     * (i.e. enum: OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED ...)
     */
    OHOS_ABILITY_AUTO_DEFERRED_VIDEO_ENHANCE,
    /**
     * ohos.ability.movingPhotoMicroVideoEnhance [static, enum, public]
     *
     * camera device property, report current camera whether support dynamic photo enhancement processing
     * (i.e. enum: OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED ...)
     */
    OHOS_ABILITY_MOVING_PHOTO_MICRO_VIDEO_ENHANCE,
    /**
     * ohos.control.autoDeferredVideoEnhance [static, enum, public]
     *
     * camera device property, set current camera whether support auto deferred video enhance
     * (i.e. enum: OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED ...)
     */
    OHOS_CONTROL_AUTO_DEFERRED_VIDEO_ENHANCE,
    /**
     * ohos.ability.autoCloudImageEnhance [static, int32[], public]
     *
     * camera device property, report current camera whether support auto cloud image enhance by mode
     * (i.e. int32[]: [mode, OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED, mode ...] ...)
     */
    OHOS_ABILITY_AUTO_CLOUD_IMAGE_ENHANCE,
    /**
     * ohos.control.autoCloudImageEnhance [static, enum, public]
     *
     * camera device property, set current camera whether support auto cloud image enhance
     * (i.e. enum: OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED ...)
     */
    OHOS_CONTROL_AUTO_CLOUD_IMAGE_ENHANCE,
    /**
     * ohos.ability.tripodDetection [static, int32[], public]
     *
     * camera device property, report current camera what mode support tripod detection
     * (i.e. int32[]: [mode, mode ...] ...)
     */
    OHOS_ABILITY_TRIPOD_DETECTION,
    /**
     * ohos.control.tripodDetection [static, byte, public]
     *
     * camera device property, set current camera whether enable tripod detection
     * (i.e. byte: 0-false/1-true ...)
     */
    OHOS_CONTROL_TRIPOD_DETECTION,
    /**
     * ohos.control.tripodStablitation [static, byte, public]
     *
     * camera device property, set current camera whether enable tripod stablitation algorithm
     * (i.e. byte: 0-false/1-true ...)
     */
    OHOS_CONTROL_TRIPOD_STABLITATION,
    /**
     * ohos.status.tripodDetectionStatus [static, enum, public]
     *
     * camera device property, query current camera tripod detection status
     * (i.e. enum: TRIPOD_STATUS_INVALID/TRIPOD_STATUS_ACTIVE/TRIPOD_STATUS_ENTER/TRIPOD_STATUS_EXITING ...)
     */
    OHOS_STATUS_TRIPOD_DETECTION_STATUS,
    /**
     * ohos.status.sketchPoint [static, float[], public]
     *
     * camera device property, query current camera sketch center point position
     * (i.e. float[]: [px, py] ...)
     */
    OHOS_STATUS_SKETCH_POINT,
    /**
     * ohos.status.sketchStreamInfo [static, float[], public]
     *
     * camera device property, query current camera sketch stream info
     * (i.e. float[]: [OHOS_CAMERA_SKETCH_STREAM_UNSUPPORT/OHOS_CAMERA_SKETCH_STREAM_SUPPORT, zoom ratio])
     */
    OHOS_STATUS_SKETCH_STREAM_INFO,
    /**
     * ohos.ability.lowLightBoost [static, int32[], public]
     *
     * camera device property, report current camera whether low light boost by mode
     * (i.e. int32[]: [mode, OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED, mode ...] ...)
     */
    OHOS_ABILITY_LOW_LIGHT_BOOST,
    /**
     * ohos.control.lowLightDetect [static, byte, public]
     *
     * camera device property, set current camera whether low light detect
     * (i.e. byte: 0-false/1-true ...)
     */
    OHOS_CONTROL_LOW_LIGHT_DETECT,
    /**
     * ohos.control.lowLightBoost [static, byte, public]
     *
     * camera device property, set current camera whether low light boost
     * (i.e. byte: 0-false/1-true ...)
     */
    OHOS_CONTROL_LOW_LIGHT_BOOST,
    /**
     * ohos.status.lowLightDetection [static, byte, public]
     *
     * camera device property, query current camera low light detection status
     * (i.e. byte: 0-false/1-true ...)
     */
    OHOS_STATUS_LOW_LIGHT_DETECTION,
    /**
     * ohos.status.cameraLensDirtyDetection [static, byte, public]
     *
     * camera device property, query current camera lens dirty detection
     * (i.e. byte: 0-false/1-true ...)
     */
    OHOS_STATUS_CAMERA_LENS_DIRTY_DETECTION,
    /**
     * ohos.device.protectionState [static, enum, public]
     *
     * camera device property, query current camera device protection state
     * (i.e. enum: DeviceProtectionStatus ...)
     */
    OHOS_DEVICE_PROTECTION_STATE,
    /**
     * ohos.device.tofsensorabnormal [static, int32, public]
     *
     * camera device property, query current camera tof sensor abnormal state
     * (i.e. int32 ...)
     */
    OHOS_STATUS_TOF_SENSOR_ABNORMAL,
    /**
     * ohos.ability.sunBlockPreviewTypes [static, byte[], public]
     *
     * camera device property, report current camera sun block types supported in proview
     * (i.e. byte[]: [0-notSupport|1-RGB|2-UV|...])
     */
    OHOS_ABILITY_SUN_BLOCK_PREVIEW_TYPES,
    /**
     * ohos.ability.sunBlockBlendColors [static, byte[], public]
     *
     * camera device property, report current camera sun block supports blend colors
     * (i.e. byte[]: [0-notSupport|1-purple|2-silver|3-gold|...])
     */
    OHOS_ABILITY_SUN_BLOCK_BLEND_COLORS,
    /**
     * ohos.ability.sunBlockRgbCropRegion [static, float[], public]
     *
     * camera device property, report current camera RGB image cropping coefficient, which is the normalized coordinate
     * (i.e. float[] ...)
     */
    OHOS_ABILITY_SUN_BLOCK_RGB_CROP_REGION,
    /**
     * ohos.ability.sunBlockRgbUvRegion [static, float[], public]
     *
     * camera device property, report current camera UV image cropping coefficient, which is the normalized coordinate
     * (i.e. float[] ...)
     */
    OHOS_ABILITY_SUN_BLOCK_RGB_UV_REGION,
    /**
     * ohos.status.sunBlockHint [static, byte, public]
     *
     * camera device property, queries the status returned by the current camera running the sun protection detection
     * (i.e. byte ...)
     */
    OHOS_STATUS_SUN_BLOCK_HINT,
    /**
     * ohos.ability.cameraLimitedCapabilityes [static, double[], public]
     *
     * Camera capability set for limited concurrent scenarios.
     * This item contains other capability items for device capability control,
     * such as OHOS_ABILITY_FLASH_MODES or other 3A capabilities.
     * Resolution is reported through OHOS_ABLE_AVAILABLE_PROFILE_LEVEL.
     * (i.e. OHOS_ABILITY_FLASH_MODES, length, flashMode, flashMode, ...)
     * @since 5.1
     * @version 1.0
     */
    OHOS_ABILITY_CAMERA_LIMITED_CAPABILITIES,
    /**
     * ohos.ability.cameraConcurrentType [static, byte, public]
     *
     * Indicates whether the current camera is in full concurrency mode or limited concurrency mode.
     * (i.e. byte)
     * @since 5.1
     * @version 1.0
     */
    OHOS_ABILITY_CAMERA_CONCURRENT_TYPE,
    /**
     * ohos.ability.cameraConcurrentType [static, int32, public]
     *
     * Concurrent camera combinations are supported. The camera combinations are separated by - 1.
     * (i.e. int32[] [2, 3, -1, 1, 2])
     * @since 5.1
     * @version 1.0
     */
    OHOS_ABILITY_CONCURRENT_SUPPORTED_CAMERAS,
    /**
     * ohos.ability.autoAigcPhoto [static, byte[], public]
     *
     * camera device property, report current camera whether support auto auto aigc photo by mode
     * (i.e. byte[]: [mode, OHOS_CAMERA_NOT_SUPPORTED/OHOS_CAMERA_SUPPORTED, mode ...] ...)
     * @since 5.1
     * @version 1.0
     */
    OHOS_ABILITY_AUTO_AIGC_PHOTO,
    /**
     * ohos.control.autoAigcPhoto [static, enum, public]
     *
     * camera device property, set current camera whether support auto aigc photo
     * (i.e. byte: 0-false/1-true ...)
     * @since 5.1
     * @version 1.0
     */
    OHOS_CONTROL_AUTO_AIGC_PHOTO,
    /**
     * ohos.camera.propertiesEnd
     *
     * camera property end
     */
    OHOS_CAMERA_PROPERTIES_END,

    /**
     * ohos.sensor.exposureTime [static, int64, public]
     *
     * camera device property, query current camera exposure time
     * (i.e. int64 ...)
     */
    OHOS_SENSOR_EXPOSURE_TIME = OHOS_CAMERA_SENSOR_START,
    /**
     * ohos.sensor.colorCorrectionGains [static, float, public]
     *
     * camera device property, query current camera color correction gains
     * (i.e. float ...)
     */
    OHOS_SENSOR_COLOR_CORRECTION_GAINS,
    /**
     * ohos.sensor.orientation [static, int32, public]
     *
     * camera device property, query current camera orientation
     * (i.e. int32 ...)
     */
    OHOS_SENSOR_ORIENTATION,
    /**
     * ohos.ability.muteModes [static, enum[], public]
     *
     * camera device property, report current camera mute modes
     * (i.e. enum[]: OFF, solidColorBlack ...)
     */
    OHOS_ABILITY_MUTE_MODES,
    /**
     * ohos.control.muteMode [static, enum, public]
     *
     * camera device property, set current camera mute mode
     * (i.e. enum: OFF/solidColorBlack ...)
     */
    OHOS_CONTROL_MUTE_MODE,
    /**
     * ohos.control.rotateAngle [static, int32, public]
     *
     * camera device property, set current camera rotate angle
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_ROTATE_ANGLE,
    /**
     * ohos.ability.sensorOrientationVariable [static, int32[], public]
     *
     * camera device property, query sensor orientation whether change with fold status
     * (i.e. int32 ...)
     */
    OHOS_ABILITY_SENSOR_ORIENTATION_VARIABLE,
    /**
     * ohos.fold.state.sensor.orientation.map [static, int32, public]
     *
     * camera device property, query sensor orientation of all fold state
     * (i.e. int32 ...)
     */
    OHOS_FOLD_STATE_SENSOR_ORIENTATION_MAP,
    /**
     * ohos.camera.sensorEnd
     *
     * camera sensor endChar
     */
    OHOS_CAMERA_SENSOR_END,

    /**
     * ohos.sensorInfo.activeArraySize [static, int32[], public]
     *
     * camera device property, report current camera support active array size
     * (i.e. int32[]: left, top, right, bottom ...)
     */
    OHOS_SENSOR_INFO_ACTIVE_ARRAY_SIZE = OHOS_CAMERA_SENSOR_INFO_START,
    /**
     * ohos.sensorInfo.sensitivityRange [static, int32[], public]
     *
     * camera device property, report current camera support sensitivity range
     * (i.e. int32[]: min, max ...)
     */
    OHOS_SENSOR_INFO_SENSITIVITY_RANGE,
    /**
     * ohos.sensorInfo.maxFrameDuration [static, int64, public]
     *
     * camera device property, report current camera support max frame duration
     * (i.e. int64: maxFrame ...)
     */
    OHOS_SENSOR_INFO_MAX_FRAME_DURATION,
    /**
     * ohos.sensorInfo.physicalSize [static, float[], public]
     *
     * camera device property, report current camera support physical size of sensor
     * (i.e. float[] ...)
     */
    OHOS_SENSOR_INFO_PHYSICAL_SIZE,
    /**
     * ohos.sensorInfo.pixelArraySize [static, int32[], public]
     *
     * camera device property, report current camera support pixel array size
     * (i.e. int32[] ...)
     */
    OHOS_SENSOR_INFO_PIXEL_ARRAY_SIZE,
    /**
     * ohos.sensorInfo.timestamp [static, int64, public]
     *
     * camera device property, report current camera support timestamp
     * (i.e. int64 ...)
     */
    OHOS_SENSOR_INFO_TIMESTAMP,
    /**
     * ohos.camera.sensorInfoEnd
     *
     * camera sensorInfoEnd
     */
    OHOS_CAMERA_SENSOR_INFO_END,

    /**
     * ohos.statistics.faceDetectMode [static, enum, public]
     *
     * camera device property, report current camera support face detect support mode
     * (i.e. enum: OFF/SIMPLE ...)
     */
    OHOS_STATISTICS_FACE_DETECT_MODE = OHOS_CAMERA_STATISTICS_START,
    /**
     * ohos.statistics.faceDetectSwitch [static, enum, public]
     *
     * camera device property, set current camera face detect support switch
     * (i.e. enum: OFF/SIMPLE ...)
     */
    OHOS_STATISTICS_FACE_DETECT_SWITCH,
    /**
     * ohos.statistics.faceDetectMaxNum [static, byte, public]
     *
     * camera device property, report current camera support face detect max num
     * (i.e. byte ...)
     */
    OHOS_STATISTICS_FACE_DETECT_MAX_NUM,
    /**
     * ohos.statistics.histogramMode [static, enum, public]
     *
     * camera device property, report current camera support histogram mode
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_STATISTICS_HISTOGRAM_MODE,
    /**
     * ohos.statistics.faceIds [static, int32[], public]
     *
     * camera device property, set current camera face ids
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_FACE_IDS,
    /**
     * ohos.statistics.faceLandMarks [static, int32[], public]
     *
     * camera device property, report current camera support face land marks
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_FACE_LANDMARKS,
    /**
     * ohos.statistics.faceLandMarks [static, int32[], public]
     *
     * camera device property, report current camera support face land marks
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_FACE_RECTANGLES,
    /**
     * ohos.statistics.faceScores [static, int32[], public]
     *
     * camera device property, query current camera face scores
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_FACE_SCORES,
    /**
     * ohos.statistics.detectHumanFaceInfos [static, int32[], public]
     *
     * camera device property, query current camera detect human face informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_HUMAN_FACE_INFOS,
    /**
     * ohos.statistics.detectHumanBodyInfos [static, int32[], public]
     *
     * camera device property, query current camera detect human body informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_HUMAN_BODY_INFOS,
    /**
     * ohos.statistics.detectCatFaceInfos [static, int32[], public]
     *
     * camera device property, query current camera detect cat face informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_CAT_FACE_INFOS,
    /**
     * ohos.statistics.detectCatBodyInfos [static, int32[], public]
     *
     * camera device property, query current camera detect cat body informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_CAT_BODY_INFOS,
    /**
     * ohos.statistics.detectDogFaceInfos [static, int32[], public]
     *
     * camera device property, query current camera detect dog face informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_DOG_FACE_INFOS,
    /**
     * ohos.statistics.detectDogBodyInfos [static, int32[], public]
     *
     * camera device property, query current camera detect dog body informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_DOG_BODY_INFOS,
    /**
     * ohos.statistics.detectSalientInfos [static, int32[], public]
     *
     * camera device property, query current camera detect salient informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_SALIENT_INFOS,
    /**
     * ohos.statistics.detectBarCodeInfos [static, int32[], public]
     *
     * camera device property, query current camera detect bar code informations
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_BAR_CODE_INFOS,
    /**
     * ohos.statistics.baseFaceInfo [static, int32[], public]
     *
     * camera device property, query current camera detect base face information
     * (i.e. int32[] ...)
     */
    OHOS_STATISTICS_DETECT_BASE_FACE_INFO,
    /**
     * ohos.camera.statisticsEnd
     *
     * camera statisticsEnd
     */
    OHOS_CAMERA_STATISTICS_END,

    /**
     * ohos.control.aeAntibandingMode [static, enum, public]
     *
     * camera device property, set current camera support ae antibanding mode
     * (i.e. enum: OFF/50HZ/60HZ/AUTO ...)
     */
    OHOS_CONTROL_AE_ANTIBANDING_MODE = OHOS_DEVICE_CONTROL_START,
    /**
     * ohos.control.aeExposureCompensation [static, int32, public]
     *
     * camera device property, set current camera ae exposure compensation
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_AE_EXPOSURE_COMPENSATION,
    /**
     * ohos.control.aeLock [static, enum, public]
     *
     * camera device property, set current camera ae lock
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_AE_LOCK,
    /**
     * ohos.control.aeMode [static, enum, public]
     *
     * camera device property, set current camera ae mode
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_AE_MODE,
    /**
     * ohos.control.aeRegions [static, float[], public]
     *
     * camera device property, set current camera ae regions
     * (i.e. float[] ...)
     */
    OHOS_CONTROL_AE_REGIONS,
    /**
     * ohos.control.aeTargetFpsRange [static, int32[], public]
     *
     * camera stream property, set current camera ae target fps range
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_AE_TARGET_FPS_RANGE,
    /**
     * ohos.control.fpsRanges [static, int32[], public]
     *
     * camera device property, set current camera fps ranges
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_FPS_RANGES,
    /**
     * ohos.control.afMode [static, enum, public]
     *
     * camera device property, set current camera af mode
     * (i.e. enum: OFF/AUTO ...)
     */
    OHOS_CONTROL_AF_MODE,
    /**
     * ohos.control.afRegions [static, float[], public]
     *
     * camera device property, set current camera af regions
     * (i.e. float[] ...)
     */
    OHOS_CONTROL_AF_REGIONS,
    /**
     * ohos.control.afTrigger [static, enum, public]
     *
     * camera device property, set current camera af trigger
     * (i.e. enum: IDLE/START/CANCEL ...)
     */
    OHOS_CONTROL_AF_TRIGGER,
    /**
     * ohos.control.afTriggerId [static, int32, public]
     *
     * camera device property, set current camera af trigger id
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_AF_TRIGGER_ID,
    /**
     * ohos.control.afState [static, enum, public]
     *
     * camera device property, set current camera af state
     * (i.e. enum: INACTIVE/PASSIVE_SCAN ...)
     */
    OHOS_CONTROL_AF_STATE,
    /**
     * ohos.control.awbLock [static, enum, public]
     *
     * camera device property, set current camera awb lock
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_AWB_LOCK,
    /**
     * ohos.control.awbMode [static, enum, public]
     *
     * camera device property, set current camera awb mode
     * (i.e. enum: OFF/AUTO ...)
     */
    OHOS_CONTROL_AWB_MODE,
    /**
     * ohos.control.awbRegions [static, int32[], public]
     *
     * camera device property, set current camera awb regions
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_AWB_REGIONS,
    /**
     * ohos.control.aeAvailableAntibandingModes [static, byte[], public]
     *
     * camera device property, set current camera ae available antibanding modes
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_AE_AVAILABLE_ANTIBANDING_MODES,
    /**
     * ohos.control.aeAvailableModes [static, byte[], public]
     *
     * camera device property, set current camera ae available modes
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_AE_AVAILABLE_MODES,
    /**
     * ohos.control.aeAvailableTargetFpsRanges [static, int32[], public]
     *
     * camera device property, set current camera ae available target fps ranges
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_AE_AVAILABLE_TARGET_FPS_RANGES,
    /**
     * ohos.ability.aeCompensationRange [static, int32[], public]
     *
     * camera device property, report current camera support ae compensation range
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AE_COMPENSATION_RANGE,
    /**
     * ohos.ability.aeCompensationStep [static, rational, public]
     *
     * camera device property, set current camera support ae compensation step
     * (i.e. rational ...)
     */
    OHOS_ABILITY_AE_COMPENSATION_STEP,
    /**
     * ohos.control.aeCompensationRange [static, int32[], public]
     *
     * camera device property, set current camera ae compensation range
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_AE_COMPENSATION_RANGE,
    /**
     * ohos.control.aeCompensationStep [static, rational, public]
     *
     * camera device property, set current camera ae compensation step
     * (i.e. rational ...)
     */
    OHOS_CONTROL_AE_COMPENSATION_STEP,
    /**
     * ohos.control.afAvailableModes [static, enum[], public]
     *
     * camera device property, set current camera af available modes
     * (i.e. enum[]: OFF, AUTO, ...)
     */
    OHOS_CONTROL_AF_AVAILABLE_MODES,
    /**
     * ohos.control.awbAvailableModes [static, byte[], public]
     *
     * camera device property, set current camera awb available modes
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_AWB_AVAILABLE_MODES,
    /**
     * ohos.control.captureMirrorSupported [static, enum, public]
     *
     * camera device property, set current camera capture mirror supported
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_CAPTURE_MIRROR_SUPPORTED,
    /**
     * ohos.control.captureMirror [static, enum, public]
     *
     * camera device property, set current camera capture mirror
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_CAPTURE_MIRROR,
    /**
     * ohos.control.focusState [static, enum, public]
     *
     * camera device property, set current camera focus state
     * (i.e. enum: SCAN/FOCUSED/UNFOCUSED ...)
     */
    OHOS_CONTROL_FOCUS_STATE,
    /**
     * ohos.control.meterPoint [static, int32[], public]
     *
     * camera device property, set current camera meter point
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_METER_POINT,
    /**
     * ohos.control.meterMode [static, enum, public]
     *
     * camera device property, set current camera meter mode
     * (i.e. enum: SPOT_METERING/REGION_METERING ...)
     */
    OHOS_CONTROL_METER_MODE,
    /**
     * ohos.control.exposureState [static, byte, public]
     *
     * camera device property, set current camera exposure state
     * (i.e. byte ...)
     */
    OHOS_CONTROL_EXPOSURE_STATE,
    /**
     * ohos.control.focusedPoint [static, int32[], public]
     *
     * camera device property, set current camera focused point
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_FOCUSED_POINT,
    /**
     * ohos.control.nightModeTpyAe [static, byte, public]
     *
     * camera device property, set current camera night mode
     * (i.e. byte ...)
     */
    OHOS_CONTROL_NIGHT_MODE_TRY_AE,
    /**
     * ohos.control.maualExposureTime [static, uint32[], public]
     *
     * camera device property, set current camera manually set the exposure time
     * (i.e. uint32[] ...)
     */
    OHOS_CONTROL_MANUAL_EXPOSURE_TIME,
    /**
     * ohos.status.cameraCurrentFps [static, uint32, public]
     *
     * camera device property, set current camera camera current fps
     * (i.e. uint32 ...)
     */
    OHOS_STATUS_CAMERA_CURRENT_FPS,
    /**
     * ohos.ability.isoValues [static, int32[], public]
     *
     * camera device property, report current camera support iso values
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_ISO_VALUES,
    /**
     * ohos.control.isoValue [static, int32, public]
     *
     * camera device property, set current camera iso value
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_ISO_VALUE,
    /**
     * ohos.status.isoValue [static, int32, public]
     *
     * camera device property, query current camera iso value
     * (i.e. int32 ...)
     */
    OHOS_STATUS_ISO_VALUE,
    /**
     * ohos.ability.sensorExposureTimeRange [static, int32, public]
     *
     * camera device property, report current camera support sensor exposure time range
     * (i.e. int32 ...)
     */
    OHOS_ABILITY_SENSOR_EXPOSURE_TIME_RANGE,
    /**
     * ohos.ability.sensorExposureTime [static, rational, public]
     *
     * camera device property, set current camera sensor exposure time
     * (i.e. rational ...)
     */
    OHOS_CONTROL_SENSOR_EXPOSURE_TIME,
    /**
     * ohos.status.sensorExposureTime [static, rational, public]
     *
     * camera device property, query current camera sensor exposure time
     * (i.e. rational ...)
     */
    OHOS_STATUS_SENSOR_EXPOSURE_TIME,
    /**
     * ohos.control.movingPhoto [static, enum, public]
     *
     * camera device property, set current camera whether support live photo
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_MOVING_PHOTO,
    /**
     * ohos.ability.sensorWbValues [static, int32[], public]
     *
     * camera device property, report current camera support sensor wb values
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_SENSOR_WB_VALUES,
    /**
     * ohos.control.sensorWbValues [static, int32, public]
     *
     * camera device property, set current camera sensor wb values
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_SENSOR_WB_VALUE,
    /**
     * ohos.control.highQualityMode [static, enum, public]
     *
     * camera stream property, set current camera high quality mode
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_HIGH_QUALITY_MODE,
    /**
     * ohos.control.appHint [static, enum, public]
     *
     * camera device property, set current camera hint
     * (i.e. enum: NONE/LIVE_STREAM/AGGRESSIVE_RESOURCE ...)
     */
    OHOS_CONTROL_APP_HINT,
    /**
     * ohos.control.burstCapture [static, enum, public]
     *
     * camera device property, set current camera device burst capture mode
     * (i.e. enum: begin/end ...)
     */
    OHOS_CONTROL_BURST_CAPTURE,
    /**
     * ohos.control.cameraUsedAsPosition [static, byte, public]
     *
     * camera device property, set current camera used as position
     * (i.e. byte ...)
     */
    OHOS_CONTROL_CAMERA_USED_AS_POSITION,
    /**
     * ohos.control.cameraSessionUsage [static, enum[], public]
     *
     * camera device property, set current camera session usage type whether enable
     * (i.e. enum[]: [CameraSessionUsageType, CameraSessionUsageControlType] ...)
     */
    OHOS_CONTROL_CAMERA_SESSION_USAGE,
    /**
     * ohos.control.ejectRetry [static, byte, public]
     *
     * camera device property, set current camera lens retry eject
     * (i.e. byte: 0-false/1true ...)
     */
    OHOS_CONTROL_EJECT_RETRY,
    /**
     * ohos.control.fallProtection [static, byte, public]
     *
     * camera device property, set current camera lens fall protection
     * (i.e. byte: 0-false/1true ...)
     */
    OHOS_CONTROL_FALL_PROTECTION,
    /**
     * ohos.control.sunBlockPreviewType [static, byte, public]
     *
     * camera device property, sets the sun protection detection type under the current camera preview
     * (i.e. byte: 0-RGB/1-UV/2-RGB+UV)
     */
    OHOS_CONTROL_SUN_BLOCK_PREVIEW_TYPE,
    /**
     * ohos.control.sunBlockBlendColor [static, byte, public]
     *
     * camera device property, sets the sun protection detection blend color for the current camera
     * (i.e. byte: 0-none/1-purple/2-silver/3-gold)
     */
    OHOS_CONTROL_SUN_BLOCK_BLEND_COLOR,
    /**
     * ohos.ability.qualityPrioritization [static, byte, public]
     *
     * camera device property, set current camera quality prioritization
     * (i.e. byte ...)
     */
    OHOS_CONTROL_QUALITY_PRIORITIZATION,
    /**
     * ohos.control.systemCapture [static, uint8, public]
     *
     * camera device property, set current camera device system application capture
     * (i.e. uint8: 0-false/1-true ...)
     */
    OHOS_CONTROL_SYSTEM_CAPTURE,
    /**
     * ohos.ability.photoQualityPrioritization [static, int32_t[], public]
     *
     * camera device property, report current camera support photo quality prioritization
     * (i.e. int32_t[] ...)
     */
    OHOS_ABILITY_PHOTO_QUALITY_PRIORITIZATION,
    /**
     * ohos.control.photoQualityPrioritization [static, byte, public]
     *
     * camera device property, set current camera photo quality prioritization
     * (i.e. byte ...)
    */
    OHOS_CONTROL_PHOTO_QUALITY_PRIORITIZATION,
    /**
     * ohos.control.removeSensorRestraint [static, uint8, public]
     *
     * camera device property, set current camera device remove sensor restraint
     * (i.e. uint8: 0-false/1-true ...)
    */
    OHOS_CONTROL_REMOVE_SENSOR_RESTRAINT,
    /**
     * ohos.device.controlEnd
     *
     * device controlEnd
     */
    OHOS_DEVICE_CONTROL_END,

    // Camera device image acquisition related
    /**
     * ohos.ability.deviceAvailableExposureModes [static, byte[], public]
     *
     * camera device property, report current camera support device available exposure modes
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_DEVICE_AVAILABLE_EXPOSUREMODES = OHOS_DEVICE_EXPOSURE_START,
    /**
     * ohos.control.exposureMode [static, enum, public]
     *
     * camera device property, set current camera exposure mode
     * (i.e. enum: MANUAL/CONTINUOUS_AUTO/LOCKED/AUTO ...)
     */
    OHOS_CONTROL_EXPOSUREMODE,
    /**
     * ohos.ability.exposureModes [static, enum[], public]
     *
     * camera device property, report current camera support exposure modes
     * (i.e. enum[]: MANUAL, CONTINUOUS_AUTO, LOCKED, AUTO ...)
     */
    OHOS_ABILITY_EXPOSURE_MODES,
    /**
     * ohos.control.exposureMode [static, enum, public]
     *
     * camera device property, set current camera exposure mode
     * (i.e. enum: MANUAL/CONTINUOUS_AUTO/LOCKED/AUTO ...)
     */
    OHOS_CONTROL_EXPOSURE_MODE,
    /**
     * ohos.ability.meterModes [static, enum[], public]
     *
     * camera device property, report current camera support meter modes
     * (i.e. enum[]: SPOT_METERING, REGION_METERING, OVERALL_METERING, CENTER_WEIGHTED_METERING ...)
     */
    OHOS_ABILITY_METER_MODES,
    /**
     * ohos.ability.sceneExposureModes [static, byte[], public]
     *
     * camera device property, report current camera support scene exposure time
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_SCENE_EXPOSURE_MODES,
    /**
     * ohos.ability.exposureTime [static, byte[], public]
     *
     * camera device property, report current camera support exposure time
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_EXPOSURE_TIME,
    /**
     * ohos.ability.aeLock [static, enum[], public]
     *
     * camera device property, report current camera support ae lock
     * (i.e. enum[]: OFF, ON ...)
     */
    OHOS_ABILITY_AE_LOCK,
    /**
     * ohos.device.exposureEnd
     *
     * camera device exposureEnd
     */
    OHOS_DEVICE_EXPOSURE_END,

    /**
     * ohos.ability.deviceAvailableFocusModes [static, byte[], public]
     *
     * camera device property, report current camera support device available focus modes
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_DEVICE_AVAILABLE_FOCUSMODES = OHOS_DEVICE_FOCUS_START,
    /**
     * ohos.ability.focusMode [static, byte, public]
     *
     * camera device property, set current camera focus mode
     * (i.e. byte ...)
     */
    OHOS_CONTROL_FOCUSMODE,
    /**
     * ohos.ability.focusModes [static, enum[], public]
     *
     * camera device property, report current camera support focus modes
     * (i.e. enum[]: MANUAL, CONTINUOUS_AUTO, AUTO, LOCKED ...)
     */
    OHOS_ABILITY_FOCUS_MODES,
    /**
     * ohos.ability.focusMode [static, enum, public]
     *
     * camera device property, set current camera focus mode
     * (i.e. enum: MANUAL/CONTINUOUS_AUTO/AUTO/LOCKED ...)
     */
    OHOS_CONTROL_FOCUS_MODE,
    /**
     * ohos.ability.focalLength [static, float, public]
     *
     * camera device property, report current camera support focal length
     * (i.e. float ...)
     */
    OHOS_ABILITY_FOCAL_LENGTH,
    /**
     * ohos.ability.sceneFocusModes [static, byte[], public]
     *
     * camera device property, report current camera support secene focus modes
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_SCENE_FOCUS_MODES,
    /**
     * ohos.ability.focusAssistFlashSupportedModes [static, enum[], public]
     *
     * camera device property, report current camera focus assist flash supported modes
     * (i.e. enum[]: DEFAULT, AUTO, ON, OFF ...)
     */

    OHOS_ABILITY_FOCUS_ASSIST_FLASH_SUPPORTED_MODES,
    /**
     * ohos.control.focusAssistFlashSupportedMode [static, byte, public]
     *
     * camera device property, set current camera focus assist flash supported mode
     * (i.e. byte ...)
     */
    OHOS_CONTROL_FOCUS_ASSIST_FLASH_SUPPORTED_MODE,
    /**
     * ohos.ability.lensInfoMinimumFocusDistance [static, float, public]
     *
     * camera device property, report current camera support lens info minimum focus distance
     * (i.e. float ...)
     */
    OHOS_ABILITY_LENS_INFO_MINIMUM_FOCUS_DISTANCE,
    /**
     * ohos.ability.lensFocusDistance [static, float, public]
     *
     * camera device property, set current camera lens focus distance
     * (i.e. float ...)
     */
    OHOS_CONTROL_LENS_FOCUS_DISTANCE,
    /**
     * ohos.ability.equivalentFocus [static, int32[], public]
     *
     * camera device property, report current camera support equivalent focus
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_EQUIVALENT_FOCUS,
    /**
     * ohos.ability.lensEquivalentFocus [static, int32[], public]
     *
     * camera device property, report current camera support lens equivalent focus
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_LENS_EQUIVALENT_FOCUS,
    /**
     * ohos.ability.focusDistance [static, float, public]
     *
     * camera device property, set current camera support focus distance
     * (i.e. float ...)
     */
    OHOS_CONTROL_FOCUS_DISTANCE,
    /**
     * ohos.ability.focusRangeTypes [static, enum[], public]
     *
     * camera device property, report current camera support focus range types
     * (i.e. enum[]: AUTO, NEAR ...)
     */
    OHOS_ABILITY_FOCUS_RANGE_TYPES,
    /**
     * ohos.control.focusRangeType [static, enum, public]
     *
     * camera device property, set current camera focus range type
     * (i.e. enum: AUTO/NEAR ...)
     */
    OHOS_CONTROL_FOCUS_RANGE_TYPE,
    /**
     * ohos.control.focusTrackingMode [static, enum, public]
     *
     * camera device property, set current camera focus tracking mode
     * (i.e. enum: AUTO ...)
     */
    OHOS_CONTROL_FOCUS_TRACKING_MODE,
    /**
     * ohos.ability.focusTrackingRegion [static, int32[], public]
     *
     * camera device property, report current camera focus tracking region
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_FOCUS_TRACKING_REGION,
    /**
     * ohos.ability.focusDrivenTypes [static, enum[], public]
     *
     * camera device property, report current camera support focus driven types
     * (i.e. enum[]: AUTO, FACE ...)
     */
    OHOS_ABILITY_FOCUS_DRIVEN_TYPES,
    /**
     * ohos.control.focusDrivenType [static, enum, public]
     *
     * camera device property, set current camera focus driven type
     * (i.e. enum: AUTO/FACE ...)
     */
    OHOS_CONTROL_FOCUS_DRIVEN_TYPE,
    /**
     * ohos.ability.focusTrackingMechAvailable [static, enum[], public]
     *
     * camera device property, report current camera mech modes
     * (i.e. enum[]: OFF, not support mech ...)
     */
    OHOS_ABILITY_FOCUS_TRACKING_MECH_AVAILABLE,
    /**
     * ohos.control.focusTrackingMech [static, enum, public]
     *
     * camera device property, set current camera mech mode
     * (i.e. enum: OFF/ON ...)
     */
    OHOS_CONTROL_FOCUS_TRACKING_MECH,

    /**
     * ohos.control.focusTrackingObjectId [static, enum, public]
     *
     * camera device property, report current camera support focus object id
     * (i.e. enum: AUTO/FACE ...)
     */
    OHOS_CONTROL_FOCUS_TRACKING_OBJECT_ID,
    /**
     * ohos.device.focusEnd
     *
     * camera device focusEnd
     */
    OHOS_DEVICE_FOCUS_END,

    /**
     * ohos.ability.deviceAvailableAwbModes [static, float, public]
     *
     * camera device property, report current camera device support available awb modes
     * (i.e. float ...)
     */
    OHOS_ABILITY_DEVICE_AVAILABLE_AWBMODES = OHOS_DEVICE_WHITE_BLANCE_START,
    /**
     * ohos.ability.awbModes [static, enum[], public]
     *
     * camera device property, report current camera support awb modes
     * (i.e. enum[]: OFF, AUTO, INCANDESCENT, FLUORESCENT, WARM_FLUORESCENT,
     *  DAYLIGHT, CLOUDY_DAYLIGHT, TWILIGHT, SHADE ...)
     */
    OHOS_ABILITY_AWB_MODES,
    /**
     * ohos.ability.awbLock [static, byte, public]
     *
     * camera device property, report current camera support awb lock
     * (i.e. byte ...)
     */
    OHOS_ABILITY_AWB_LOCK,
    /**
     * ohos.device.whiteBlanceEnd
     *
     * camera device whiteBlanceEnd
     */
    OHOS_DEVICE_WHITE_BLANCE_END,

    /**
     * ohos.ability.deviceAvailableFlashModes [static, byte[], public]
     *
     * camera device property, report current camera support device available flash modes
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_DEVICE_AVAILABLE_FLASHMODES = OHOS_DEVICE_FLASH_START,
    /**
     * ohos.control.flashMode [static, enum, public]
     *
     * camera device property, set current camera flash mode
     * (i.e. enum: CLOSE/OPEN/AUTO/ALWAYS_OPEN ...)
     */
    OHOS_CONTROL_FLASHMODE,
    /**
     * ohos.ability.flashModes [static, enum[], public]
     *
     * camera device property, report current camera support flash modes
     * (i.e. enum[]: CLOSE, OPEN, AUTO, ALWAYS_OPEN ...)
     */
    OHOS_ABILITY_FLASH_MODES,
    /**
     * ohos.control.flashMode [static, byte, public]
     *
     * camera device property, set current camera flash mode
     * (i.e. byte ...)
     */
    OHOS_CONTROL_FLASH_MODE,
    /**
     * ohos.control.flashState [static, enum, public]
     *
     * camera device property, set current camera flash state
     * (i.e. enum: UNAVAILABLE/CHARGING/READY/FLASHING/UNKNOWN ...)
     */
    OHOS_CONTROL_FLASH_STATE,
    /**
     * ohos.ability.sceneFlashModes [static, byte[], public]
     *
     * camera device property, report current camera support scene flash modes
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_SCENE_FLASH_MODES,
    /**
     * ohos.device.flashEnd
     *
     * camera device flashEnd
     */
    OHOS_DEVICE_FLASH_END,

    /**
     * ohos.ability.zoomRatioRange [static, float[], public]
     *
     * camera device property, report current camera support zoom ratio range
     * (i.e. float[] ...)
     */
    OHOS_ABILITY_ZOOM_RATIO_RANGE = OHOS_DEVICE_ZOOM_START,
    /**
     * ohos.control.zoomRatio [static, float, public]
     *
     * camera device property, set current camera zoom ratio
     * (i.e. float ...)
     */
    OHOS_CONTROL_ZOOM_RATIO,
    /**
     * ohos.control.zoomCropRegion [static, int32[], public]
     *
     * camera device property, set current camera zoom crop region
     * (i.e. int32[] ...)
     */
    OHOS_CONTROL_ZOOM_CROP_REGION,
    /**
     * ohos.ability.zoomCrop [static, int32[], public]
     *
     * camera device property, report current camera zoom crop
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_ZOOM_CAP,
    /**
     * ohos.ability.sceneZoomCap [static, int32[], public]
     *
     * camera device property, report current camera scene zoom crop
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_SCENE_ZOOM_CAP,
    /**
     * ohos.status.cameraCurrentZoomRatio [static, uint32, public]
     *
     * camera device property, query current camera zoom ratio
     * (i.e. uint32 ...)
     */
    OHOS_STATUS_CAMERA_CURRENT_ZOOM_RATIO,
    /**
     * ohos.control.smoothZoomRatios [static, uint32[], public]
     *
     * camera device property, set current camera smooth zoom ratios
     * (i.e. uint32[] ...)
     */
    OHOS_CONTROL_SMOOTH_ZOOM_RATIOS,
    /**
     * ohos.control.prepareZoom [static, enum, public]
     *
     * camera device property, set current camera prepare zoom
     * (i.e. enum: DISABLE/ENABLE...)
     */
    OHOS_CONTROL_PREPARE_ZOOM,
    /**
     * ohos.control.cameraZoomPerformance [static, byte, public]
     *
     * camera device property, set current camera support camera zoom performance
     * (i.e. byte ...)
     */
    OHOS_ABILITY_CAMERA_ZOOM_PERFORMANCE,
    /**
     * ohos.status.cameraCurrentZoomPerformance [static, byte, public]
     *
     * camera device property, set current camera zoom performance
     * (i.e. byte ...)
     */
    OHOS_STATUS_CAMERA_ZOOM_PERFORMANCE,
     /**
     * ohos.control.zoomBezierCurvePoint [static, byte, public]
      *
      * camera device property, set current camera support camera BEZIER_CURVC_POINT
      * (i.e. byte ...)
      */
    OHOS_ABILITY_CAMERA_ZOOM_BEZIER_CURVC_POINT,
    /**
     * ohos.control.zoomCenterPoint [static, float[], public]
     *
     * camera device property, set current camera zoom center point
     * (i.e. float[] ...)
     */
    OHOS_CONTROL_ZOOM_CENTER_POINT,
    /**
     * ohos.control.zoomCenterPointSupported [static, enum, public]
     *
     * camera device property, report current camera zoom center point supported/nosupported
     * (i.e. enum: support/unsupport ...)
     */
    OHOS_ABILITY_ZOOM_CENTER_POINT_SUPPORTED,
     /**
     * ohos.device.zoomEnd
     *
     * camera device zoomEnd
     */
    OHOS_DEVICE_ZOOM_END,

    // Camera flow control related
    /**
     * ohos.ability.streamAvailableBasicConfigurations [static, int32[], public]
     *
     * camera device property, current camera support stream available basic configurations
     * (i.e. int32[]: RGBA_8888, YCBCR_420_888, YCRCB_420_SP, YCBCR_420_SP, JPEG, YCBCR_P010,
     *  YCRCB_P010, DNG, 422_YUYV, IMPLEMENTATION_DEFINED ...)
     */
    OHOS_ABILITY_STREAM_AVAILABLE_BASIC_CONFIGURATIONS = OHOS_STREAM_ABILITY_START,
    /**
     * ohos.ability.availableFormats [static, int32[], public]
     *
     * camera device property, query camera support available formats
     * (i.e. int32[]: RGBA_8888/YCBCR_420_888/YCRCB_420_SP/YCBCR_420_SP/JPEG/YCBCR_P010/
     *  YCRCB_P010/DNG/422_YUYV/IMPLEMENTATION_DEFINED ...)
     */
    OHOS_STREAM_AVAILABLE_FORMATS,
    /**
     * ohos.ability.streamAvailableExtendConfigurations [static, int32[], public]
     *
     * camera device property, query camera support stream available extend configurations
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_STREAM_AVAILABLE_EXTEND_CONFIGURATIONS,
    /**
     * ohos.ability.streamQuickThumbnailAvailable [static, enum, public]
     *
     * camera device property, report camera support stream quick thumbnail available
     * (i.e. enum: false/true ...)
     */
    OHOS_ABILITY_STREAM_QUICK_THUMBNAIL_AVAILABLE,
    /**
     * ohos.ability.portraitResolusion [static, int32[], public]
     *
     * camera device property, report camera support portrait resolusion
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_PORTRAIT_RESOLUSION,
    /**
     * ohos.ability.sceneStreamQuickThumbnailAvailable [static, byte[], public]
     *
     * camera device property, report camera support scene stream quick thumbnail available
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_SCENE_STREAM_QUICK_THUMBNAIL_AVAILABLE,
    /**
     * ohos.ability.deferredImageDelivery [static, byte[], public]
     *
     * camera device property, report camera support deferred image delivery
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_DEFERRED_IMAGE_DELIVERY,
    /**
     * ohos.ability.deferredImageDelivery [static, byte[], public]
     *
     * camera stream property, set camera support deferred image delivery
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_DEFERRED_IMAGE_DELIVERY,
    /**
     * ohos.ability.autoVideoFrameRate [static, byte[], public]
     *
     * Camera device property, reporting that the camera supports automatic frame rate adjustment
     * (i.e. byte[] ...)
     * @since 5.1
     * @version 1.0
     */
    OHOS_ABILITY_AUTO_VIDEO_FRAME_RATE,
    /*
     * ohos.ability.changeToOfflineStreamOpeator [static, byte[], public]
     *
     * camera stream property, get camera support offline stream
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_CHANGETO_OFFLINE_STREAM_OPEATOR,
    /**
     * ohos.control.changeToOfflineStreamOpeator [static, byte[], public]
     *
     * camera stream property, set camera support offline stream
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_CHANGETO_OFFLINE_STREAM_OPEATOR,
    /**
     * ohos.ability.rotationinipssupported [static, uint8, public]
     *
     * camera device property, query camera support ips rotation
     * (i.e. uint8: 0-false/1-true ...)
     */
    OHOS_ABILITY_ROTATION_IN_IPS_SUPPORTED,
    /**
     * ohos.control.delayAlloc [static, uint8, public]
     *
     * camera device property, whether delay alloc.
     * (i.e. uint8: 0-false/1-true ...)
     */
    OHOS_CONTROL_DELAY_ALLOC,
    /**
     * ohos.ability.prerecord [static, int32[], public]
     *
     * camera device property, query camera support prerecord and duration
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_PRERECORD,
    /**
     * ohos.stream.abilityEnd
     *
     * camera stream abilityEnd
     */
    OHOS_STREAM_ABILITY_END,

    /**
     * ohos.control.autoVideoFrameRate [static, byte[], public]
     *
     * camera stream property, set camera support automatic frame rate adjustment
     * (i.e. byte[] ...)
     * @since 5.1
     * @version 1.0
     */
    OHOS_CONTROL_AUTO_VIDEO_FRAME_RATE = OHOS_STREAM_CONTROL_START,
    /**
     * ohos.control.prerecord.mode [static, enum, public]
     *
     * camera stream property, set current camera prerecord mode
     * (i.e. enum: ON/OFF ...)
     */
    OHOS_CONTROL_PRERECORD_MODE,
    /**
     * ohos.control.record.state [static, enum, public]
     *
     * camera stream property, set current camera record state
     * (i.e. enum: PRERECORD_START/RECORD_START/RECORD_END  ...)
     */
    OHOS_CONTROL_RECORD_STATE,
    /**
     * ohos.stream.controlEnd
     *
     * camera stream controlEnd
     */
    OHOS_STREAM_CONTROL_END,

    /**
     * ohos.jpeg.gpsCoordinates [static, double[], public]
     *
     * camera stream property, report current camera support jpeg gps coordinates
     * (i.e. double[] ...)
     */
    OHOS_JPEG_GPS_COORDINATES = OHOS_STREAM_JPEG_START,
    /**
     * ohos.jpeg.gpsProcessingMethod [static, byte, public]
     *
     * camera stream property, report current camera support jpeg gps processing method
     * (i.e. byte ...)
     */
    OHOS_JPEG_GPS_PROCESSING_METHOD,
    /**
     * ohos.jpeg.gpsTimestamp [static, int64, public]
     *
     * camera stream property, report current camera support jpeg gps timestamp
     * (i.e. int64 ...)
     */
    OHOS_JPEG_GPS_TIMESTAMP,
    /**
     * ohos.jpeg.orientation [static, int32, public]
     *
     * camera stream property, report current camera support jpeg gps orientation
     * (i.e. int32: 0/90/180/270 ...)
     */
    OHOS_JPEG_ORIENTATION,
    /**
     * ohos.jpeg.quality [static, enum, public]
     *
     * camera stream property, report current camera support jpeg quality
     * (i.e. enum: LOW/MIDDLE/HIGH ...)
     */
    OHOS_JPEG_QUALITY,
    /**
     * ohos.jpeg.thumbnailQuality [static, byte, public]
     *
     * camera stream property, report current camera support jpeg thumbnail quality
     * (i.e. byte ...)
     */
    OHOS_JPEG_THUMBNAIL_QUALITY,
    /**
     * ohos.jpeg.thumbnailSize [static, int32[], public]
     *
     * camera stream property, report current camera support jpeg thumbnail size
     * (i.e. int32[] ...)
     */
    OHOS_JPEG_THUMBNAIL_SIZE,
    /**
     * ohos.jpeg.availableThumbnailSizes [static, int32[], public]
     *
     * camera stream property, report current camera support available thumbnail sizes
     * (i.e. int32[] ...)
     */
    OHOS_JPEG_AVAILABLE_THUMBNAIL_SIZES,
    /**
     * ohos.jpeg.maxSize [static, int32, public]
     *
     * camera stream property, report current camera support max size
     * (i.e. int32 ...)
     */
    OHOS_JPEG_MAX_SIZE,
    /**
     * ohos.jpeg.size [static, int32, public]
     *
     * camera stream property, report current camera support size
     * (i.e. int32 ...)
     */
    OHOS_JPEG_SIZE,
    /**
     * ohos.stream.jpegEnd
     *
     * camera stream jpegEnd
     */
    OHOS_STREAM_JPEG_END,

    /**
     * ohos.ability.videoStabilizationModes [static, enum[], public]
     *
     * camera device property, report current camera support video stabilization modes
     * (i.e. enum[]: OFF, LOW, MIDDLE, HIGH, AUTO ...)
     */
    OHOS_ABILITY_VIDEO_STABILIZATION_MODES = OHOS_STREAM_VIDEO_START,
    /**
     * ohos.control.videoStabilizationMode [static, enum, public]
     *
     * camera stream property, set current camera support video stabilization mode
     * (i.e. enum: OFF/LOW/MIDDLE/HIGH/AUTO ...)
     */
    OHOS_CONTROL_VIDEO_STABILIZATION_MODE,
    /**
     * ohos.control.videoDebugSwitch [static, byte, public]
     *
     * camera device property, set current camera video debug switch
     * (i.e. byte ...)
     */
    OHOS_CONTROL_VIDEO_DEBUG_SWITCH,
    /**
     * ohos.stream.videoEnd
     *
     * camera stream videoEnd
     */
    OHOS_STREAM_VIDEO_END,

    // camera effects & algorithms
    /**
     * ohos.ability.sceneFilterTypes [static, enum[], public]
     *
     * camera device property, report current camera support scene filter types
     * (i.e. enum[]: OFF, NONE, CLASSIC, DAWN, PURE, GREY, NATURAL, MORI, FAIR, PINK ...)
     */
    OHOS_ABILITY_SCENE_FILTER_TYPES = OHOS_CAMERA_EFFECT_START,
    /**
     * ohos.control.filterTypes [static, enum, public]
     *
     * camera device property, set current camera support filter types
     * (i.e. enum: OFF/NONE/CLASSIC/DAWN/PURE/GREY/NATURAL/MORI/FAIR/PINK ...)
     */
    OHOS_CONTROL_FILTER_TYPE,
    /**
     * ohos.ability.scenePortraitEffectTypes [static, enum[], public]
     *
     * camera device property, report current camera support scene portrait effect types
     * (i.e. enum[]: OFF, CIRCLES, HEART, ROTATED, STUDIO, THEATER ...)
     */
    OHOS_ABILITY_SCENE_PORTRAIT_EFFECT_TYPES,
    /**
     * ohos.control.scenePortraitEffectType [static, enum, public]
     *
     * camera device property, set current camera support scene portrait effect type
     * (i.e. enum: OFF/CIRCLES/HEART/ROTATED/STUDIO/THEATER ...)
     */
    OHOS_CONTROL_PORTRAIT_EFFECT_TYPE,
    /**
     * ohos.ability.sceneBeautyTypes [static, enum[], public]
     *
     * camera device property, report current camera support scene beauty types
     * (i.e. enum[]: OFF, AUTO, SKIN_SMOOTH, FACE_SLENDER, SKIN_TONE ...)
     */
    OHOS_ABILITY_SCENE_BEAUTY_TYPES,
    /**
     * ohos.control.sceneBeautyTypes [static, enum, public]
     *
     * camera device property, set current camera support scene beauty types
     * (i.e. enum: OFF/AUTO/SKIN_SMOOTH/FACE_SLENDER/SKIN_TONE ...)
     */
    OHOS_CONTROL_BEAUTY_TYPE,
    /**
     * ohos.ability.beautyAutoValues [static, byte[], public]
     *
     * camera device property, report current camera support beauty auto values
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_BEAUTY_AUTO_VALUES,
    /**
     * ohos.control.beautyAutoValue [static, byte, public]
     *
     * camera device property, set current camera support beauty auto value
     * (i.e. byte ...)
     */
    OHOS_CONTROL_BEAUTY_AUTO_VALUE,
    /**
     * ohos.ability.beautyFaceSlenderValues [static, byte[], public]
     *
     * camera device property, report current camera support beauty face slender values
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_BEAUTY_FACE_SLENDER_VALUES,
    /**
     * ohos.control.beautyFaceSlenderValues [static, byte, public]
     *
     * camera device property, set current camera support beauty face slender value
     * (i.e. byte ...)
     */
    OHOS_CONTROL_BEAUTY_FACE_SLENDER_VALUE,
    /**
     * ohos.ability.beautySkinToneValues [static, int32[], public]
     *
     * camera device property, report current camera support beauty skin tone values
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_BEAUTY_SKIN_TONE_VALUES,
    /**
     * ohos.ability.beautySkinToneValue [static, int32, public]
     *
     * camera device property, set current camera support beauty skin tone value
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_BEAUTY_SKIN_TONE_VALUE,
    /**
     * ohos.ability.beautySkinSmoothValues [static, byte[], public]
     *
     * camera device property, report current camera support beauty skin smooth values
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_BEAUTY_SKIN_SMOOTH_VALUES,
    /**
     * ohos.ability.beautySkinSmoothValue [static, byte, public]
     *
     * camera device property, set current camera support beauty skin smooth value
     * (i.e. byte ...)
     */
    OHOS_CONTROL_BEAUTY_SKIN_SMOOTH_VALUE,
    /**
     * ohos.ability.camera [static, enum, public]
     *
     * camera device property, report current camera macro
     * (i.e. enum: supported/nosupported ...)
     */
    OHOS_ABILITY_CAMERA_MACRO_SUPPORTED,
    /**
     * ohos.ability.sceneMacroCap [static, int32[], public]
     *
     * camera device property, report current camera different macro capAbility
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_SCENE_MACRO_CAP,
    /**
     * ohos.status.camera [static, enum, public]
     *
     * camera device property, query current camera macro
     * (i.e. enum: disbale/enable ...)
     */
    OHOS_CAMERA_MACRO_STATUS,
    /**
     * ohos.control.camera [static, enum, public]
     *
     * camera device property, set current camera macro
     * (i.e. enum: disbale/enable ...)
     */
    OHOS_CONTROL_CAMERA_MACRO,
    /**
     * ohos.ability.cameraVirtualApertureRange [static, float[], public]
     *
     * camera device property, report current camera virtual aperture range
     * (i.e. float[] ...)
     */
    OHOS_ABILITY_CAMERA_VIRTUAL_APERTURE_RANGE,
    /**
     * ohos.control.cameraVirtualApertureValue [static, float, public]
     *
     * camera device property, set current camera virtual aperture value
     * (i.e. float ...)
     */
    OHOS_CONTROL_CAMERA_VIRTUAL_APERTURE_VALUE,
    /**
     * ohos.control.cameraPhysicalAperttureRange [static, float[], public]
     *
     * camera device property, set current camera physical aperture range
     * (i.e. float[] ...)
     */
    OHOS_ABILITY_CAMERA_PHYSICAL_APERTURE_RANGE,
    /**
     * ohos.control.cameraPhysicalAperttureValue [static, float, public]
     *
     * camera device property, set current camera physical aperture value
     * (i.e. float ...)
     */
    OHOS_CONTROL_CAMERA_PHYSICAL_APERTURE_VALUE,
    /**
     * ohos.status.cameraApertureValue [static, float, public]
     *
     * camera device property, query current camera aperture value
     * (i.e. float ...)
     */
    OHOS_STATUS_CAMERA_APERTURE_VALUE,
    /**
     * ohos.device.exitCameraEvent [static, byte, public]
     *
     * camera device property, set current camera exitCamera event
     * (i.e. byte ...)
     */
    OHOS_DEVICE_EXITCAMERA_EVENT,
    /**
     * ohos.control.motionDetectionCheckArea [static, float[], public]
     *
     * camera device property, report current camera motion detection check area
     * (i.e. float[] ...)
     */
    OHOS_CONTROL_MOTION_DETECTION_CHECK_AREA,
    /**
     * ohos.status.slowMotionDetection [static, enum, public]
     *
     * camera device property, query current camera slow motion recording status
     * (i.e. enum: disable/ready/start/recording/finish ...)
     */
    OHOS_STATUS_SLOW_MOTION_DETECTION,
    /**
     * ohos.ability.motionDetectionSupport [static, enum, public]
     *
     * camera device property, report current camera motion detection
     * (i.e. enum: support/nosupport ...)
     */
    OHOS_ABILITY_MOTION_DETECTION_SUPPORT,
    /**
     * ohos.control.motionDetection [static, enum, public]
     *
     * camera device property, set current camera operation status detection switch
     * (i.e. enum: disable/enable ...)
     */
    OHOS_CONTROL_MOTION_DETECTION,
    /**
     * ohos.ability.exposureHintSupported [static, byte, public]
     *
     * camera device property, report current camera screen exposure
     * (i.e. byte ...)
     */
    OHOS_ABILITY_EXPOSURE_HINT_SUPPORTED,
    /**
     * ohos.control.exposureHintMode [static, byte, public]
     *
     * camera device property, set current camera screen exposure
     * (i.e. byte ...)
     */
    OHOS_CONTROL_EXPOSURE_HINT_MODE,
    /**
     * ohos.status.algoMeanY [static, uint32, public]
     *
     * camera device property, query current camera screen exposure
     * (i.e. uint32 ...)
     */
    OHOS_STATUS_ALGO_MEAN_Y,
    /**
     * ohos.status.previewPhysicalCameraId [static, byte, public]
     *
     * camera device property, query current camera preview shot id
     * (i.e. byte ...)
     */
    OHOS_STATUS_PREVIEW_PHYSICAL_CAMERA_ID,
    /**
     * ohos.ability.captureExpectTime [static, uint32[], public]
     *
     * camera device property, report current camera expect time
     * (i.e. uint32[] ...)
     */
    OHOS_ABILITY_CAPTURE_EXPECT_TIME,
    /**
     * ohos.ability.effectSuggestionSupported [static, int32[], public]
     *
     * camera device property, report current camera supported effect suggestion, report by mode
     * (i.e. int32[] {mode1, effectNumber, enum, enum2, ..., -1, ...}...)
     */
    OHOS_ABILITY_EFFECT_SUGGESTION_SUPPORTED,
    /**
     * ohos.control.effectSuggestion [static, enum, public]
     *
     * camera device property, set current camera enable or disable effect suggestion, set by mode
     * (i.e. enum 0(disable)/1(enable) ...)
     */
    OHOS_CONTROL_EFFECT_SUGGESTION,
    /**
     * ohos.control.effectSuggestionDetection [static, byte[], public]
     *
     * camera device property, init effect suggestion, set current camera enable or disable effect suggestion
     * (i.e. byte[] [enum, 0(disable)/1(enable), enum2, 0(disable)/1(enable) ...] ...)
     */
    OHOS_CONTROL_EFFECT_SUGGESTION_DETECTION,
    /**
     * ohos.camera.effectSuggestionType [static, enum, public]
     *
     * camera device property, query current camera effect suggestion type
     * (i.e. enum  NONE/PORTRAIT/FOOD/SKY/SUNRISE_SUNSET ...)
     */
    OHOS_CAMERA_EFFECT_SUGGESTION_TYPE,
    /**
     * ohos.control.effectSuggestionType [static, byte[], public]
     *
     * camera device property, set current effect suggestion enable or disable
     * (i.e. byte[] [enum, 0(disable)/1(enable)] ...)
     */
    OHOS_CONTROL_EFFECT_SUGGESTION_TYPE,
    /**
     * ohos.ability.availableProfileLevel [static, int32[], public]
     *
     * camera device property, report current camera available profile level
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_PROFILE_LEVEL,
    /**
     * ohos.ability.availablePreviewProfile [static, int32[], public]
     *
     * camera device property, report current camera available preview profile
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_PREVIEW_PROFILE,
    /**
     * ohos.ability.availablePhotoProfile [static, int32[], public]
     *
     * camera device property, report current camera available photo profile
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_PHOTO_PROFILE,
    /**
     * ohos.ability.availableVideoProfile [static, int32[], public]
     *
     * camera device property, report current camera available video profile
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_VIDEO_PROFILE,
    /**
     * ohos.ability.availableMetadataProfile [static, int32[], public]
     *
     * camera device property, report current camera available metadata profile
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_METADATA_PROFILE,
    /**
     * ohos.ability.availableConfigurations [static, int32[], public]
     *
     * camera device property, report current camera available configurations
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_AVAILABLE_CONFIGURATIONS,
    /**
     * ohos.ability.conflictConfigurations [static, int32[], public]
     *
     * camera device property, report current camera conflict configurations
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_CONFLICT_CONFIGURATIONS,
    /**
     * ohos.ability.lightPaintingType [static, byte[], public]
     *
     * camera device property, report current camera light painting type
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_LIGHT_PAINTING_TYPE,
    /**
     * ohos.control.lightPaintingType [static, byte[], public]
     *
     * camera device property, set current camera light painting type
     * (i.e. byte[] [enum, 0(car)/1(star)/2(water)/3(light)])
     */
    OHOS_CONTROL_LIGHT_PAINTING_TYPE,
    /**
     * ohos.control.lightPaintingFlash [static, byte[], public]
     *
     * camera device property, set current camera light painting flash
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_LIGHT_PAINTING_FLASH,
    /**
     * ohos.control.timeLapseInterval [static, uint32_t[], public]
     *
     * camera device property, set current camera time lapse interval
     * (i.e. uint32_t[] ...)
     */
    OHOS_CONTROL_TIME_LAPSE_INTERVAL,
    /**
     * ohos.control.timeLapseTryaeState [static, byte[], public]
     *
     * camera device property, set current camera time lapse tryae state
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_TIME_LAPSE_TRYAE_STATE,
    /**
     * ohos.status.timeLapsePreviewType [static, byte[], public]
     *
     * camera device property, query current camera time lapse preview type
     * (i.e. byte[] ...)
     */
    OHOS_STATUS_TIME_LAPSE_PREVIEW_TYPE,
    /**
     * ohos.status.timeLapseTryaeHint [static, byte[], public]
     *
     * camera device property, query current camera time lapse tryae hint
     * (i.e. byte[] ...)
     */
    OHOS_STATUS_TIME_LAPSE_TRYAE_HINT,
    /**
     * ohos.status.timeLapseCaptureInterval [static, uint32_t[], public]
     *
     * camera device property, query current camera time lapse capture interval
     * (i.e. uint32_t[] ...)
     */
    OHOS_STATUS_TIME_LAPSE_CAPTURE_INTERVAL,
    /**
     * ohos.status.timeLapseTryaeDone [static, byte[], public]
     *
     * camera device property, query current camera time lapse tryae done
     * (i.e. byte[] ...)
     */
    OHOS_STATUS_TIME_LAPSE_TRYAE_DONE,
    /**
     * ohos.control.timeLapseRecordState [static, byte[], public]
     *
     * camera device property, set current camera time lapse record state
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_TIME_LAPSE_RECORD_STATE,
    /**
     * ohos.control.timeLapsePreviewType [static, byte[], public]
     *
     * camera device property, set current camera time lapse preview type
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_TIME_LAPSE_PREVIEW_TYPE,
    /**
     * ohos.ability.timeLapseIntervalRange [static, uint32_t[], public]
     *
     * camera device property, report current camera time lapse interval range
     * (i.e. uint32_t[] ...)
     */
    OHOS_ABILITY_TIME_LAPSE_INTERVAL_RANGE,
    /**
     * ohos.ability.lcdFlash [static, int32_t[], public]
     *
     * camera device property, report current camera lcd flash
     * (i.e. int32_t[] ...)
     */
    OHOS_ABILITY_LCD_FLASH,
    /**
     * ohos.control.lcdFlashDetection [static, byte[], public]
     *
     * camera device property, set current camera lcd flash detection
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_LCD_FLASH_DETECTION,
    /**
     * ohos.control.lcdFlash [static, byte[], public]
     *
     * camera device property, set current camera lcd flash
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_LCD_FLASH,
    /**
     * ohos.status.lcdFlashStatus [static, int32_t[], public]
     *
     * camera device property, quiry current camera lcd flash status
     * (i.e. int32_t[] ...)
     */
    OHOS_STATUS_LCD_FLASH_STATUS,
    /**
     * ohos.ability.depthDataDelivery [static, int32_t[], public]
     *
     * camera device property, report current camera depth data delivery
     * (i.e. int32_t[] ...)
     */
    OHOS_ABILITY_DEPTH_DATA_DELIVERY,
    /**
     * ohos.control.depthDataDeliverySwitch [static, byte[], public]
     *
     * camera device property, set current camera depth data delivery switch
     * (i.e. byte[] ...)
     */
    OHOS_CONTROL_DEPTH_DATA_DELIVERY_SWITCH,
    /**
     * ohos.ability.depthDataProfiles [static, int32_t[], public]
     *
     * camera device property, report current camera depth data profiles
     * (i.e. int32_t[] ...)
     */
    OHOS_ABILITY_DEPTH_DATA_PROFILES,
    /**
     * ohos.control.depthDataAccuracy [static, int32_t[], public]
     *
     * camera device property, set current camera depth data accuracy
     * (i.e. int32_t[] ...)
     */
    OHOS_CONTROL_DEPTH_DATA_ACCURACY,
    /**
     * ohos.ability.cameraIsRetractable [static, byte, public]
     *
     * camera device property, report current camera retractable
     * (i.e. byte ...)
     */
    OHOS_ABILITY_CAMERA_IS_RETRACTABLE,
    /**
     * ohos.control.closeAfterSeconds [static, uint32, public]
     *
     * camera device property, set current camera close after seconds
     * (i.e. uint32 ...)
     */
    OHOS_CONTROL_CAMERA_CLOSE_AFTER_SECONDS,
    /**
     * ohos.status.movingPhotoBufferDuration [static, uint32[], public]
     *
     * camera device property, report current moving photo buffer duration
     * (i.e. uint32[] ...)
     */
    OHOS_MOVING_PHOTO_BUFFER_DURATION,
    /**
     * ohos.movingPhotoStart [static, uint32[], public]
     *
     * camera device property, report current moving photo start time
     * (i.e. uint32[] ...)
     */
    OHOS_MOVING_PHOTO_START,
    /**
     * ohos.movingPhotoEnd [static, int64[], public]
     *
     * camera device property, report current moving photo end time
     * (i.e. int64[] ...)
     */
    OHOS_MOVING_PHOTO_END,
    /**
     * ohos.ability.captureMacroDepthFusionSupported [static, byte, public]
     *
     * camera device property, report current capture macro depth fusion supported
     * (i.e. byte ...)
     */
    OHOS_ABILITY_CAPTURE_MACRO_DEPTH_FUSION_SUPPORTED,
    /**
     * ohos.ability.captureMacroDepthFusionZoomRange [static, float[], public]
     *
     * camera device property, report current capture macro depth fusion zoom range
     * (i.e. float[] ...)
     */
    OHOS_ABILITY_CAPTURE_MACRO_DEPTH_FUSION_ZOOM_RANGE,
    /**
     * ohos.control.captureMacroDepthFusion [static, byte, public]
     *
     * camera device property, set current capture macro depth fusion
     * (i.e. byte ...)
     */
    OHOS_CONTROL_CAPTURE_MACRO_DEPTH_FUSION,
    /**
     * ohos.ability.cameraPortraitThemeSupported [static, byte, public]
     *
     * camera device property, report current camera portrait theme supported
     * (i.e. byte ...)
     */
    OHOS_ABILITY_CAMERA_PORTRAIT_THEME_SUPPORTED,
    /**
     * ohos.ability.cameraPortraitThemeTypes [static, byte[], public]
     *
     * camera device property, report current camera supported portrait theme types
     * (i.e. byte[] ...)
     */
    OHOS_ABILITY_CAMERA_PORTRAIT_THEME_TYPES,
    /**
     * ohos.control.cameraPortraitThemeType [static, byte, public]
     *
     * camera device property, set current camera portrait theme type
     * (i.e. byte ...)
     */
    OHOS_CONTROL_CAMERA_PORTRAIT_THEME_TYPE,
    /**
     * ohos.ability.cameraVideoRotationSupported [static, byte, public]
     *
     * camera device property, report current camera video rotation supported
     * (i.e. byte ...)
     */
    OHOS_ABILITY_CAMERA_VIDEO_ROTATION_SUPPORTED,
    /**
     * ohos.ability.cameraVideoRotation [static, int32[], public]
     *
     * camera device property, report current camera supported video rotation
     * (i.e. int32[] ...)
     */
    OHOS_ABILITY_CAMERA_VIDEO_ROTATION,
    /**
     * ohos.control.cameraVideoRotation [static, int32, public]
     *
     * camera device property, set current camera video rotation
     * (i.e. int32 ...)
     */
    OHOS_CONTROL_CAMERA_VIDEO_ROTATION,
    /**
     * ohos.ability.colorReservationTypes [static, enum[], public]
     *
     * camera device property, report current camera support color reservation types
     * (i.e. enum[]: NONE, PORTRAIT ...)
     */
    OHOS_ABILITY_COLOR_RESERVATION_TYPES,
    /**
     * ohos.control.colorReservationType [static, enum, public]
     *
     * camera device property, set current camera color reservation type
     * (i.e. enum: NONE/PORTRAIT ...)
     */
    OHOS_CONTROL_COLOR_RESERVATION_TYPE,
    /**
     * ohos.ability.camera [static, enum, public]
     *
     * camera device property, report current camera control center supported
     * (i.e. enum: support/unsupport ...)
     */
    OHOS_ABILITY_CONTROL_CENTER_SUPPORTED,
    /**
     * ohos.ability.camera [static, enum[], public]
     *
     * camera device property, report current camera support control center effect type
     * (i.e. enum[]: [BEAUTY, PORTRAIT] ...)
     */
    OHOS_ABILITY_CONTROL_CENTER_EFFECT_TYPE,
    /**
     * ohos.camera.effectEnd
     *
     * camera effect end
     */
    OHOS_CAMERA_EFFECT_END,

    // camera secure related
    /**
     * ohos.control.secureFaceMode [static, uint32, public]
     *
     * camera device property, set current camera secure face mode
     * (i.e. uint32 ...)
     */
    OHOS_CONTROL_SECURE_FACE_MODE = OHOS_CAMERA_SECURE_START,
    /**
     * ohos.control.secureFaceInfo [static, uint32[], public]
     *
     * camera device property, set current camera secure face info
     * (i.e. uint32[] ...)
     */
    OHOS_CONTROL_SECURE_FACE_INFO,
    /**
     * ohos.control.secureFaceAuthResult [static, uint32, public]
     *
     * camera device property, set current camera face auth result
     * (i.e. uint32 ...)
     */
    OHOS_CONTROL_SECURE_FACE_AUTH_RESULT,
    /**
     * ohos.control.secureFlashSeq [static, uint32[], public]
     *
     * camera device property, set current camera secure flash seq
     * (i.e. uint32[] ...)
     */
    OHOS_CONTROL_SECURE_FLASH_SEQ,
    /**
     * ohos.control.secureIrLedSwitch [static, byte, public]
     *
     * camera device property, set current camera IR lens
     * (i.e. byte ...)
     */
    OHOS_CONTROL_SECURE_IR_LED_SWITCH,
    /**
     * ohos.control.secureIrLockAeSwitch [static, byte, public]
     *
     * camera device property, set current camera IR lens lockae
     * (i.e. byte ...)
     */
    OHOS_CONTROL_SECURE_IR_LOCKAE_SWITCH,
    /**
     * ohos.camera.secureEnd
     *
     * camera secure end
     */
    OHOS_CAMERA_SECURE_END,

    //XMAGE MODE
    /**
     * ohos.control.supportedColorModes [static, enum[], public]
     *
     * camera device property, report current camera color modes
     * (i.e. enum[]: normal, bright, soft, mono ...)
     */
    OHOS_ABILITY_SUPPORTED_COLOR_MODES = OHOS_XMAGE_COLOR_MODES_START,
    /**
     * ohos.control.supportedColorModes [static, enum, public]
     *
     * camera device property, set current camera color modes
     * (i.e. enum: normal/bright/soft/mono ...)
     */
    OHOS_CONTROL_SUPPORTED_COLOR_MODES,
    /**
     * ohos.xmage.colorMoodesEnd
     *
     * camera xmage end
     */
    OHOS_XMAGE_COLOR_MODES_END,
    /**
     * ohos.camera.abilityLightStatus [static, uint8, public]
     *
     * camera ability light status
     * (i.e. enum 0(disable)/1(enable) ...)
     */
    OHOS_ABILITY_LIGHT_STATUS = OHOS_LIGHT_STATUS_START,
    /**
     * ohos.camera.controlLightStatus [static, uint8, public]
     *
     * camera control light status
     * (i.e. enum 0(disable)/1(enable) ...)
     */
    OHOS_CONTROL_LIGHT_STATUS,
    /**
     * ohos.camera.lightStatus [static, enum, public]
     *
     * camera light status
     * (i.e. enum 0(true)/1(false) ...)
     */
    OHOS_STATUS_LIGHT_STATUS,
    /**
     * ohos.camera.lightStatus [static, enum, public]
     *
     * camera light status end
     */
    OHOS_LIGHT_STATUS_END,
} camera_device_metadata_tag_t;

// switch type tag enumeration values
typedef enum camera_switch_enum {
    OHOS_CAMERA_SWTICH_OFF = 0,
    OHOS_CAMERA_SWTICH_ON,
} camera_switch_enum_t;

// OHOS_ABILITY_CAMERA_USED_AS_POSITION enumeration values
// OHOS_ABILITY_CAMERA_POSITION enumeration values
typedef enum camera_position_enum {
    OHOS_CAMERA_POSITION_FRONT = 0,
    OHOS_CAMERA_POSITION_BACK,
    OHOS_CAMERA_POSITION_OTHER
} camera_position_enum_t;

// OHOS_ABILITY_CAMERA_TYPE enumeration values
typedef enum camera_type_enum {
    OHOS_CAMERA_TYPE_WIDE_ANGLE = 0,
    OHOS_CAMERA_TYPE_ULTRA_WIDE,
    OHOS_CAMERA_TYPE_TELTPHOTO,
    OHOS_CAMERA_TYPE_TRUE_DEAPTH,
    OHOS_CAMERA_TYPE_LOGICAL,
    OHOS_CAMERA_TYPE_UNSPECIFIED,
} camera_type_enum_t;

// OHOS_ABILITY_CAMERA_CONNECTION_TYPE enumeration values
typedef enum camera_connection_type {
    OHOS_CAMERA_CONNECTION_TYPE_BUILTIN = 0,
    OHOS_CAMERA_CONNECTION_TYPE_USB_PLUGIN,
    OHOS_CAMERA_CONNECTION_TYPE_REMOTE,
} camera_connection_type_t;

// OHOS_CONTROL_EXPOSUREMODE
// and OHOS_ABILITY_EXPOSURE_MODES enumeration values
typedef enum camera_exposure_mode_enum {
    OHOS_CAMERA_EXPOSURE_MODE_MANUAL = 0,
    OHOS_CAMERA_EXPOSURE_MODE_CONTINUOUS_AUTO,
    OHOS_CAMERA_EXPOSURE_MODE_LOCKED,
    OHOS_CAMERA_EXPOSURE_MODE_AUTO
} camera_exposure_mode_enum_t;

// OHOS_CONTROL_FOCUS_MODE and OHOS_ABILITY_FOCUS_MODES enumeration values
typedef enum camera_focus_mode_enum {
    OHOS_CAMERA_FOCUS_MODE_MANUAL = 0,
    OHOS_CAMERA_FOCUS_MODE_CONTINUOUS_AUTO,
    OHOS_CAMERA_FOCUS_MODE_AUTO,
    OHOS_CAMERA_FOCUS_MODE_LOCKED
} camera_focus_mode_enum_t;

// OHOS_ABILITY_FOCUS_ASSIST_FLASH_SUPPORTED_MODES enumeration values
typedef enum camera_focus_assist_flash_mode_enum {
    OHOS_CAMERA_FOCUS_ASSIST_FLASH_MODE_DEFAULT = 0,
    OHOS_CAMERA_FOCUS_ASSIST_FLASH_MODE_AUTO,
    OHOS_CAMERA_FOCUS_ASSIST_FLASH_MODE_ON,
    OHOS_CAMERA_FOCUS_ASSIST_FLASH_MODE_OFF
} camera_focus_assist_flash_mode_enum_t;

// OHOS_CONTROL_FLASHMODE and OHOS_ABILITY_FLASH_MODES enumeration values
typedef enum camera_flash_mode_enum {
    OHOS_CAMERA_FLASH_MODE_CLOSE = 0,
    OHOS_CAMERA_FLASH_MODE_OPEN,
    OHOS_CAMERA_FLASH_MODE_AUTO,
    OHOS_CAMERA_FLASH_MODE_ALWAYS_OPEN
} camera_flash_mode_enum_t;

// OHOS_CONTROL_FLASH_STATE enumeration values
typedef enum camera_flash_state_enum {
    OHOS_CAMERA_FLASH_STATE_UNAVAILABLE = 0,
    OHOS_CAMERA_FLASH_STATE_CHARGING,
    OHOS_CAMERA_FLASH_STATE_READY,
    OHOS_CAMERA_FLASH_STATE_FLASHING,
    OHOS_CAMERA_FLASH_STATE_UNKNOWN
} camera_flash_state_enum_t;

// OHOS_CONTROL_AE_ANTIBANDING_MODE enumeration values
typedef enum camera_ae_antibanding_mode {
    OHOS_CAMERA_AE_ANTIBANDING_MODE_OFF,
    OHOS_CAMERA_AE_ANTIBANDING_MODE_50HZ,
    OHOS_CAMERA_AE_ANTIBANDING_MODE_60HZ,
    OHOS_CAMERA_AE_ANTIBANDING_MODE_AUTO,
} camera_ae_antibanding_mode_t;

// OHOS_ABILITY_AE_LOCK
// OHOS_CONTROL_AE_LOCK enumeration values
typedef enum camera_ae_lock {
    OHOS_CAMERA_AE_LOCK_OFF,
    OHOS_CAMERA_AE_LOCK_ON,
} camera_ae_lock_t;

// OHOS_CONTROL_AE_MODE enumeration values
typedef enum camera_ae_mode {
    OHOS_CAMERA_AE_MODE_OFF,
    OHOS_CAMERA_AE_MODE_ON,
    OHOS_CAMERA_AE_MODE_ON_AUTO_FLASH,
    OHOS_CAMERA_AE_MODE_ON_ALWAYS_FLASH,
    OHOS_CAMERA_AE_MODE_ON_AUTO_FLASH_REDEYE,
    OHOS_CAMERA_AE_MODE_ON_EXTERNAL_FLASH,
} camera_ae_mode_t;

// OHOS_CONTROL_AF_MODE
// and OHOS_CONTROL_AF_AVAILABLE_MODES enumeration values
typedef enum camera_af_mode {
    OHOS_CAMERA_AF_MODE_OFF,
    OHOS_CAMERA_AF_MODE_AUTO,
    OHOS_CAMERA_AF_MODE_MACRO,
    OHOS_CAMERA_AF_MODE_CONTINUOUS_VIDEO,
    OHOS_CAMERA_AF_MODE_CONTINUOUS_PICTURE,
    OHOS_CAMERA_AF_MODE_EDOF,
} camera_af_mode_t;

// OHOS_CONTROL_AF_TRIGGER enumeration values
typedef enum camera_af_trigger {
    OHOS_CAMERA_AF_TRIGGER_IDLE,
    OHOS_CAMERA_AF_TRIGGER_START,
    OHOS_CAMERA_AF_TRIGGER_CANCEL,
} camera_af_trigger_t;

// OHOS_CONTROL_AF_STATE enumeration values
typedef enum camera_af_state {
    OHOS_CAMERA_AF_STATE_INACTIVE,
    OHOS_CAMERA_AF_STATE_PASSIVE_SCAN,
    OHOS_CAMERA_AF_STATE_PASSIVE_FOCUSED,
    OHOS_CAMERA_AF_STATE_ACTIVE_SCAN,
    OHOS_CAMERA_AF_STATE_FOCUSED_LOCKED,
    OHOS_CAMERA_AF_STATE_NOT_FOCUSED_LOCKED,
    OHOS_CAMERA_AF_STATE_PASSIVE_UNFOCUSED,
} camera_af_state_t;

// OHOS_CONTROL_AWB_LOCK enumeration values
typedef enum camera_awb_lock {
    OHOS_CAMERA_AWB_LOCK_OFF,
    OHOS_CAMERA_AWB_LOCK_ON,
} camera_awb_lock_t;

// OHOS_ABILITY_AWB_MODES and OHOS_CONTROL_AWB_MODE enumeration values
typedef enum camera_awb_mode {
    OHOS_CAMERA_AWB_MODE_OFF,
    OHOS_CAMERA_AWB_MODE_AUTO,
    OHOS_CAMERA_AWB_MODE_INCANDESCENT,
    OHOS_CAMERA_AWB_MODE_FLUORESCENT,
    OHOS_CAMERA_AWB_MODE_WARM_FLUORESCENT,
    OHOS_CAMERA_AWB_MODE_DAYLIGHT,
    OHOS_CAMERA_AWB_MODE_CLOUDY_DAYLIGHT,
    OHOS_CAMERA_AWB_MODE_TWILIGHT,
    OHOS_CAMERA_AWB_MODE_SHADE,
} camera_awb_mode_t;

// OHOS_STATISTICS_FACE_DETECT_MODE
// and OHOS_STATISTICS_FACE_DETECT_SWITCH enumeration values
typedef enum camera_face_detect_mode {
    OHOS_CAMERA_FACE_DETECT_MODE_OFF,
    OHOS_CAMERA_FACE_DETECT_MODE_SIMPLE
} camera_face_detect_mode_t;

// OHOS_STATISTICS_HISTOGRAM_MODE enumeration values
typedef enum camera_histogram_mode {
    OHOS_CAMERA_HISTOGRAM_MODE_OFF,
    OHOS_CAMERA_HISTOGRAM_MODE_ON,
} camera_histogram_mode_t;

// OHOS_STREAM_AVAILABLE_FORMATS
// and OHOS_ABILITY_STREAM_AVAILABLE_BASIC_CONFIGURATIONS enumeration values
typedef enum camera_format {
    OHOS_CAMERA_FORMAT_RGBA_8888 = 1,
    OHOS_CAMERA_FORMAT_YCBCR_420_888,
    OHOS_CAMERA_FORMAT_YCRCB_420_SP,
    OHOS_CAMERA_FORMAT_YCBCR_420_SP,
    OHOS_CAMERA_FORMAT_JPEG,
    OHOS_CAMERA_FORMAT_YCBCR_P010,
    OHOS_CAMERA_FORMAT_YCRCB_P010,
    OHOS_CAMERA_FORMAT_DNG,
    OHOS_CAMERA_FORMAT_422_YUYV,
    OHOS_CAMERA_FORMAT_DEPTH_16,
    OHOS_CAMERA_FORMAT_DEPTH_32,
    OHOS_CAMERA_FORMAT_HEIC,
    OHOS_CAMERA_FORMAT_DNG_XDRAW,
    OHOS_CAMERA_FORMAT_422_UYVY,
    OHOS_CAMERA_FORMAT_MJPEG,
    OHOS_CAMERA_FORMAT_IMPLEMENTATION_DEFINED = 0x1000,
} camera_format_t;

// OHOS_ABILITY_STREAM_QUICK_THUMBNAIL_AVAILABLE enumeration values
typedef enum camera_quick_thumbnail_available {
    OHOS_CAMERA_QUICK_THUMBNAIL_FALSE = 0,
    OHOS_CAMERA_QUICK_THUMBNAIL_TRUE,
} camera_quick_thumbnail_available_t;

// OHOS_CONTROL_FOCUS_STATE enumeration values
typedef enum camera_focus_state {
    OHOS_CAMERA_FOCUS_STATE_SCAN,
    OHOS_CAMERA_FOCUS_STATE_FOCUSED,
    OHOS_CAMERA_FOCUS_STATE_UNFOCUSED,
} camera_focus_state_t;

// OHOS_CONTROL_METER_MODE and OHOS_ABILITY_METER_MODES enumeration values
typedef enum camera_meter_mode {
    OHOS_CAMERA_SPOT_METERING = 0,
    OHOS_CAMERA_REGION_METERING,
    OHOS_CAMERA_OVERALL_METERING,
    OHOS_CAMERA_CENTER_WEIGHTED_METERING,
} camera_meter_mode_t;

typedef enum camera_exposure_state {
    OHOS_CAMERA_EXPOSURE_STATE_SCAN,
    OHOS_CAMERA_EXPOSURE_STATE_CONVERGED,
} camera_exposure_state_t;

// OHOS_CONTROL_CAPTURE_MIRROR enumeration values
typedef enum camera_mirror {
    OHOS_CAMERA_MIRROR_OFF = 0,
    OHOS_CAMERA_MIRROR_ON,
} camera_mirror_t;

// OHOS_CONTROL_CAPTURE_MIRROR_SUPPORTED
enum CameraMirrorSupport {
    OHOS_CAMERA_MIRROR_NOT_SUPPORT = 0,
    OHOS_CAMERA_MIRROR_CAPTURE,
    OHOS_CAMERA_MIRROR_CAPTURE_VIDEO,
};

// OHOS_JPEG_ORIENTATION enumeration values
typedef enum camera_jpeg_orientation {
    OHOS_CAMERA_JPEG_ROTATION_0 = 0,
    OHOS_CAMERA_JPEG_ROTATION_90 = 90,
    OHOS_CAMERA_JPEG_ROTATION_180 = 180,
    OHOS_CAMERA_JPEG_ROTATION_270 = 270,
} camera_jpeg_orientation_t;

// OHOS_JPEG_QUALITY enumeration values
typedef enum camera_jpeg_quality {
    OHOS_CAMERA_JPEG_LEVEL_LOW = 0,
    OHOS_CAMERA_JPEG_LEVEL_MIDDLE,
    OHOS_CAMERA_JPEG_LEVEL_HIGH,
} camera_jpeg_quality_t;

// OHOS_ABILITY_VIDEO_STABILIZATION_MODES
// and OHOS_CONTROL_VIDEO_STABILIZATION_MODE enumeration values
typedef enum camera_video_stabilization_mode {
    OHOS_CAMERA_VIDEO_STABILIZATION_OFF = 0,
    OHOS_CAMERA_VIDEO_STABILIZATION_LOW,
    OHOS_CAMERA_VIDEO_STABILIZATION_MIDDLE,
    OHOS_CAMERA_VIDEO_STABILIZATION_HIGH,
    OHOS_CAMERA_VIDEO_STABILIZATION_AUTO,
} CameraVideoStabilizationMode;

// OHOS_ABILITY_FLASH_AVAILABLE enumeration values
typedef enum camera_flash_available {
    OHOS_CAMERA_FLASH_FALSE = 0,
    OHOS_CAMERA_FLASH_TRUE,
} CameraFlashAvailable;

// OHOS_ABILITY_MEMORY_TYPE enumeration values
typedef enum camera_memory_type_enum {
    OHOS_CAMERA_MEMORY_MMAP = 1,
    OHOS_CAMERA_MEMORY_USERPTR,
    OHOS_CAMERA_MEMORY_OVERLAY,
    OHOS_CAMERA_MEMORY_DMABUF,
} camera_memory_type_enum_t;

// OHOS_ABILITY_MUTE_MODES and OHOS_CONTROL_MUTE_MODE enumeration values
typedef enum camera_mute_mode {
    OHOS_CAMERA_MUTE_MODE_OFF,
    OHOS_CAMERA_MUTE_MODE_SOLID_COLOR_BLACK,
} camera_mute_mode_t;

// OHOS_ABILITY_MUTE_MODES and OHOS_CONTROL_MECH_MODE enumeration values
typedef enum camera_mech_mode {
    OHOS_CAMERA_MECH_MODE_OFF,
    OHOS_CAMERA_MECH_MODE_ON,
} camera_mech_mode_t;

// OHOS_ABILITY_SCENE_FILTER_TYPES enumeration values
typedef enum camera_filter_type {
    OHOS_CAMERA_FILTER_TYPE_OFF = 0,
    OHOS_CAMERA_FILTER_TYPE_NONE,
    OHOS_CAMERA_FILTER_TYPE_CLASSIC,
    OHOS_CAMERA_FILTER_TYPE_DAWN,
    OHOS_CAMERA_FILTER_TYPE_PURE,
    OHOS_CAMERA_FILTER_TYPE_GREY,
    OHOS_CAMERA_FILTER_TYPE_NATURAL,
    OHOS_CAMERA_FILTER_TYPE_MORI,
    OHOS_CAMERA_FILTER_TYPE_FAIR,
    OHOS_CAMERA_FILTER_TYPE_PINK,
} camera_filter_type_t;

// OHOS_ABILITY_SCENE_PORTRAIT_EFFECT_TYPES enumeration values
typedef enum camera_portrait_effect_type {
    OHOS_CAMERA_PORTRAIT_EFFECT_OFF = 0,
    OHOS_CAMERA_PORTRAIT_CIRCLES,
    OHOS_CAMERA_PORTRAIT_HEART,
    OHOS_CAMERA_PORTRAIT_ROTATED,
    OHOS_CAMERA_PORTRAIT_STUDIO,
    OHOS_CAMERA_PORTRAIT_THEATER,
} camera_portrait_effect_type_t;

// OHOS_ABILITY_SCENE_BEAUTY_TYPES enumeration values
typedef enum camera_beauty_type {
    OHOS_CAMERA_BEAUTY_TYPE_OFF = 0,
    OHOS_CAMERA_BEAUTY_TYPE_AUTO,
    OHOS_CAMERA_BEAUTY_TYPE_SKIN_SMOOTH,
    OHOS_CAMERA_BEAUTY_TYPE_FACE_SLENDER,
    OHOS_CAMERA_BEAUTY_TYPE_SKIN_TONE,
} camera_beauty_type_t;

//OHOS_ABILITY_SUPPORTED_COLOR_MODES and OHOS_CONTROL_SUPPORTED_COLOR_MODES enumeration
typedef enum camera_xmage_color_type {
    CAMERA_CUSTOM_COLOR_NORMAL = 0,
    CAMERA_CUSTOM_COLOR_BRIGHT,
    CAMERA_CUSTOM_COLOR_SOFT,
    CAMERA_CUSTOM_COLOR_MONO,
} camera_xmage_color_type_t;

// OHOS_ABILITY_CAMERA_FOLDSCREEN_TYPE enumeration values
typedef enum camera_fold_screen_enum {
    OHOS_CAMERA_FOLDSCREEN_OTHER = 0,
    OHOS_CAMERA_FOLDSCREEN_INNER,
    OHOS_CAMERA_FOLDSCREEN_OUTER,
} camera_foldscreen_enum_t;

// OHOS_ABILITY_CAMERA_MACRO_SUPPORTED enumeration values
typedef enum camera_macro_supported_type {
    OHOS_CAMERA_MACRO_NOT_SUPPORTED = 0,
    OHOS_CAMERA_MACRO_SUPPORTED,
} camera_macro_supported_type_t;

// OHOS_CAMERA_MACRO_STATUS and OHOS_CONTROL_CAMERA_MACRO enumeration values
typedef enum camera_macro_status_control_type {
    OHOS_CAMERA_MACRO_DISABLE = 0,
    OHOS_CAMERA_MACRO_ENABLE,
} camera_macro_status_control_type_t;

// OHOS_CONTROL_MOON_CAPTURE_BOOST enumeration values
typedef enum camera_moon_capture_boost_control_type {
    OHOS_CAMERA_MOON_CAPTURE_BOOST_DISABLE = 0,
    OHOS_CAMERA_MOON_CAPTURE_BOOST_ENABLE,
} camera_moon_capture_boost_control_type_t;

// OHOS_CONTROL_PREPARE_ZOOM enumeration values
typedef enum camera_zoomsmooth_control_type {
    OHOS_CAMERA_ZOOMSMOOTH_PREPARE_DISABLE = 0,
    OHOS_CAMERA_ZOOMSMOOTH_PREPARE_ENABLE,
} camera_zoomsmooth_control_type_t;

// OHOS_STATUS_SUPER_SLOW_MOTION enumeration values
typedef enum camera_slow_motion_status_type {
    OHOS_CONTROL_SLOW_MOTION_STATUS_DISABLE = 0,
    OHOS_CONTROL_SLOW_MOTION_STATUS_READY,
    OHOS_CONTROL_SLOW_MOTION_STATUS_START,
    OHOS_CONTROL_SLOW_MOTION_STATUS_RECORDING,
    OHOS_CONTROL_SLOW_MOTION_STATUS_FINISH,
} camera_slow_motion_status_type_t;

// OHOS_ABILITY_MOTION_DETECTION_SUPPORT enumeration values
typedef enum camera_motion_detection_supported_type {
    OHOS_CAMERA_MOTION_DETECTION_NOT_SUPPORTED = 0,
    OHOS_CAMERA_MOTION_DETECTION_SUPPORTED,
} camera_motion_detection_supported_type_t;

//  OHOS_CONTROL_MOTION_DETECTION enumeration values
typedef enum camera_motion_detection_control_type {
    OHOS_CAMERA_MOTION_DETECTION_DISABLE = 0,
    OHOS_CAMERA_MOTION_DETECTION_ENABLE,
} camera_motion_detection_control_type_t;

// OHOS_ABILITY_MOVING_PHOTO
typedef enum moving_photo_enum {
    OHOS_CAMERA_MOVING_PHOTO_UNSUPPORT = 0,
    OHOS_CAMERA_MOVING_PHOTO_SUPPORT,
} moving_photo_enum_t;

// OHOS_CONTROL_MOVING_PHOTO
typedef enum control_moving_photo_enum {
    OHOS_CAMERA_MOVING_PHOTO_OFF = 0,
    OHOS_CAMERA_MOVING_PHOTO_ON,
} control_moving_photo_enum_t;

// OHOS_STATUS_FLASH_SUGGESTION enumeration values
typedef enum camera_flash_suggestion_supported_enum {
    OHOS_CAMERA_FLASH_SUGGESTION_SUPPORTED_CLOSE = 0,
    OHOS_CAMERA_FLASH_SUGGESTION_SUPPORTED_OPEN,
} camera_flash_suggestion_supported_enum_t;

// ABILITY_SUPPORTED_TAGS enumeration values
typedef enum camera_supported_enum {
    OHOS_CAMERA_NOT_SUPPORTED = 0,
    OHOS_CAMERA_SUPPORTED,
} camera_supported_enum_t;

// OHOS_CONTROL_HIGH_QUALITY_MODE
typedef enum ControlHighQualityModeEnum {
    OHOS_CONTROL_HIGH_QUALITY_MODE_OFF = 0,
    OHOS_CONTROL_HIGH_QUALITY_MODE_ON,
} ControlHighQualityModeEnumT;

// OHOS_CONTROL_APP_HINT
enum CameraAppHint {
    OHOS_CAMERA_APP_HINT_NONE = 0,
    OHOS_CAMERA_APP_HINT_LIVE_STREAM = 1 << 0,
    OHOS_CAMERA_APP_HINT_AGGRESSIVE_RESOURCE = 1 << 1,
};

// OHOS_CAMERA_EFFECT_SUGGESTION_TYPE
enum CameraEffectSuggestionType {
    OHOS_CAMERA_EFFECT_SUGGESTION_NONE = 0,
    OHOS_CAMERA_EFFECT_SUGGESTION_PORTRAIT,
    OHOS_CAMERA_EFFECT_SUGGESTION_FOOD,
    OHOS_CAMERA_EFFECT_SUGGESTION_SKY,
    OHOS_CAMERA_EFFECT_SUGGESTION_SUNRISE_SUNSET,
    OHOS_CAMERA_EFFECT_SUGGESTION_STAGE
};

// OHOS_ABILITY_CAMERA_FOLD_STATUS
enum CameraFoldStatus {
    OHOS_CAMERA_FOLD_STATUS_NONFOLDABLE = 0,
    OHOS_CAMERA_FOLD_STATUS_EXPANDED = 1,
    OHOS_CAMERA_FOLD_STATUS_FOLDED = 2,
};

// OHOS_CONTROL_BURST_CAPTURE
enum CameraBurstCaptureEnum {
    OHOS_CONTROL_BURST_CAPTURE_END = 0,
    OHOS_CONTROL_BURST_CAPTURE_BEGIN = 1,
};

// OHOS_ABILITY_LIGHT_PAINTING_TYPE
enum CameraLightPaintingType {
    OHOS_CAMERA_LIGHT_PAINTING_CAR = 0,
    OHOS_CAMERA_LIGHT_PAINTING_STAR,
    OHOS_CAMERA_LIGHT_PAINTING_WATER,
    OHOS_CAMERA_LIGHT_PAINTING_LIGHT,
};

//OHOS_CONTROL_TIME_LAPSE_TRYAE_STATE
enum TimeLapseRecordState {
    TIME_LAPSE_IDLE = 0,
    TIME_LAPSE_RECORDING = 1,
};

//OHOS_STATUS_TIME_LAPSE_PREVIEW_TYPE
enum TimeLapsePreviewType {
    TIME_LAPSE_PREVIEW_DARK = 1,
    TIME_LAPSE_PREVIEW_LIGHT = 2,
};

// OHOS_ABILITY_STATISTICS_DETECT_TYPE
enum StatisticsDetectType {
    OHOS_CAMERA_HUMAN_FACE_DETECT = 0,
    OHOS_CAMERA_HUMAN_BODY_DETECT = 1,
    OHOS_CAMERA_CAT_FACE_DETECT = 2,
    OHOS_CAMERA_CAT_BODY_DETECT = 3,
    OHOS_CAMERA_DOG_FACE_DETECT = 4,
    OHOS_CAMERA_DOG_BODY_DETECT = 5,
    OHOS_CAMERA_SALIENT_DETECT = 6,
    OHOS_CAMERA_BAR_CODE_DETECT = 7,
    OHOS_CAMERA_BASE_FACE_DETECT = 8,
    OHOS_CAMERA_BASE_TRACKING_REGION = 9,
};

// OHOS_STATUS_TRIPOD_DETECTION_STATUS
enum TripodStatus {
    TRIPOD_STATUS_INVALID = 0,
    TRIPOD_STATUS_ACTIVE = 1,
    TRIPOD_STATUS_ENTER = 2,
    TRIPOD_STATUS_EXITING = 3,
};

// OHOS_CONTROL_DEPTH_DATA_ACCURACY
enum DepthDataAccuracyType {
    OHOS_DEPTH_DATA_ACCURACY_RELATIVE = 1,
    OHOS_DEPTH_DATA_ACCURACY_ABSOLUTE,
};

// OHOS_CONTROL_CAMERA_SESSION_USAGE
enum CameraSessionUsageType {
    OHOS_CAMERA_SESSION_USAGE_BOKEH = 0,
};

// OHOS_CONTROL_CAMERA_SESSION_USAGE
enum CameraSessionUsageControlType {
    OHOS_CAMERA_SESSION_USAGE_DISABLE = 0,
    OHOS_CAMERA_SESSION_USAGE_ENABLE = 1,
};

// OHOS_DEVICE_PROTECTION_STATE
enum DeviceProtectionStatus {
    OHOS_DEVICE_SWITCH_FREQUENT = 0,
    OHOS_DEVICE_EXTERNAL_PRESS = 1,
    OHOS_DEVICE_EJECT_BLOCK = 2,
    OHOS_DEVICE_FALL_PROTECTION = 3,
};

enum StatisticsDetectEmotion {
    OHOS_EMOTION_NEUTRAL = 0,
    OHOS_EMOTION_SADNESS = 1,
    OHOS_EMOTION_SMILE = 2,
    OHOS_EMOTION_SURPRISE = 3,
};

// OHOS_ABILITY_CAMERA_PORTRAIT_THEME_SUPPORTED
enum CameraPortraitThemeSupportedType {
    OHOS_CAMERA_PORTRAIT_THEME_NOT_SUPPORTED = 0,
    OHOS_CAMERA_PORTRAIT_THEME_SUPPORTED,
};

// OHOS_ABILITY_CAMERA_PORTRAIT_THEME_TYPES
enum CameraPortraitThemeTypes {
    OHOS_CAMERA_PORTRAIT_THEME_TYPE_NATURAL = 0,
    OHOS_CAMERA_PORTRAIT_THEME_TYPE_DELICATE,
    OHOS_CAMERA_PORTRAIT_THEME_TYPE_STYLISH,
};

// OHOS_ABILITY_CAMERA_VIDEO_ROTATION_SUPPORTED
enum CameraVideoRotationSupportedType {
    OHOS_CAMERA_VIDEO_ROTATION_NOT_SUPPORTED = 0,
    OHOS_CAMERA_VIDEO_ROTATION_SUPPORTED,
};

// OHOS_ABILITY_SUN_BLOCK_PREVIEW_TYPES
// OHOS_CONTROL_SUN_BLOCK_PREVIEW_TYPE
enum CameraSunBlockPreviewType {
    OHOS_PREVIEW_TYPE_NOT_SUPPORTED = 0,
    OHOS_PREVIEW_TYPE_RGB,
    OHOS_PREVIEW_TYPE_UV,
    OHOS_PREVIEW_TYPE_RGB_UV,
};

// OHOS_ABILITY_SUN_BLOCK_BLEND_COLORS
// OHOS_CONTROL_SUN_BLOCK_BLEND_COLOR
enum CameraSunBlockBlendColor {
    OHOS_BLEND_COLOR_NOT_SUPPORTED = 0,
    OHOS_BLEND_COLOR_NONE = 0,
    OHOS_BLEND_COLOR_PURPLE = 1,
    OHOS_BLEND_COLOR_SILVER = 2,
    OHOS_BLEND_COLOR_GOLD = 3,
};

// OHOS_STATUS_SUN_BLOCK_HINT
enum CameraSunBlockHint {
    OHOS_HINT_NO_FACE_DETECTED = 2,
    OHOS_HINT_FACE_OUT_OF_BOUND = 3,
    OHOS_HINT_MOBILEPHONE_TOO_FAR = 4,
    OHOS_HINT_MOBILEPHONE_TOO_NEAR = 5,
    OHOS_HINT_FACE_TOO_RIGHT = 6,
    OHOS_HINT_FACE_TOO_LEFT = 7,
    OHOS_HINT_FACE_TOO_LOWER = 8,
    OHOS_HINT_FACE_TOO_TOP = 9,
    OHOS_HINT_SUNSCREEN_NO_FULL_COVERAGE = 20,
};

// OHOS_ABILITY_CAMERA_QUALITY_PRIORITIZATION
enum CameraQualityPrioritization {
    OHOS_CAMERA_QUALITY_PRIORITIZATION_HIGH_QUALITY = 0,
    OHOS_CAMERA_QUALITY_PRIORITIZATION_POWER_BALANCE,
};

// OHOS_ABILITY_AUTO_VIDEO_FRAME_RATE
enum CameraStreamAutoFpsControl {
    OHOS_STREAM_AUTO_FPS_DISABLE = 0,
    OHOS_STREAM_AUTO_FPS_ENABLE,
};

// OHOS_ABILITY_FOCUS_RANGE_TYPES
// OHOS_CONTROL_FOCUS_RANGE_TYPE
typedef enum camera_focus_range_type {
    OHOS_CAMERA_FOCUS_RANGE_AUTO = 0,
    OHOS_CAMERA_FOCUS_RANGE_NEAR
} camera_focus_range_type_t;

// OHOS_ABILITY_FOCUS_DRIVEN_TYPES
// OHOS_CONTROL_FOCUS_DRIVEN_TYPE
typedef enum camera_focus_driven_type {
    OHOS_CAMERA_FOCUS_DRIVEN_AUTO = 0,
    OHOS_CAMERA_FOCUS_DRIVEN_FACE
} camera_focus_driven_type_t;

// OHOS_CONTROL_FOCUS_TRACKING_MODE
typedef enum camera_focus_tracking_mode {
    OHOS_CAMERA_FOCUS_TRACKING_AUTO = 0,
} camera_focus_tracking_mode_t;

// OHOS_ABILITY_COLOR_RESERVATION_TYPES
// OHOS_CONTROL_COLOR_RESERVATION_TYPE
typedef enum camera_color_reservation_type {
    OHOS_CAMERA_COLOR_RESERVATION_NONE = 0,
    OHOS_CAMERA_COLOR_RESERVATION_PORTRAIT
} camera_color_reservation_type_t;

// OHOS_ABILITY_CONTROL_CENTER_SUPPORTED
enum ControlCenterSupportedType {
    OHOS_CAMERA_CONTROL_CENTER_NOT_SUPPORTED = 0,
    OHOS_CAMERA_CONTROL_CENTER_SUPPORTED,
};

// OHOS_ABILITY_CONTROL_CENTER_EFFECT_TYPE
enum CameraControlCenterEffectType {
    OHOS_CAMERA_CONTROL_CENTER_EFFECT_TYPE_BEAUTY = 0,
    OHOS_CAMERA_CONTROL_CENTER_EFFECT_TYPE_PORTRAIT,
};

// OHOS_CONTROL_PRERECORD_MODE
enum CameraPrerecordMode {
    OHOS_CAMERA_PRERECORD_MODE_ON = 1,
    OHOS_CAMERA_PRERECORD_MODE_OFF = 2,
};

// OHOS_CONTROL_RECORD_STATE
enum CameraRecordState {
    OHOS_CAMERA_RECORD_STATE_PRERECORD_START = 1,
    OHOS_CAMERA_RECORD_STATE_RECORD_START = 2,
    OHOS_CAMERA_RECORD_STATE_RECORD_STOP = 3,
};

// OHOS_ABILITY_CAMERA_CONCURRENT_TYPE
enum CameraConcurrentType {
    OHOS_CAMERA_COCURRENT_FULL = 0,
    OHOS_CAMERA_COCURRENT_LIIMITED,
};

// OHOS_STATUS_SKETCH_STREAM_INFO
enum SketchStreamInfoStatus {
    OHOS_CAMERA_SKETCH_STREAM_UNSUPPORT = 0,
    OHOS_CAMERA_SKETCH_STREAM_SUPPORT
};

// OHOS_ABILITY_PHOTO_QUALITY_PRIORITIZATION
// OHOS_CONTROL_PHOTO_QUALITY_PRIORITIZATION
typedef enum camera_photo_quality_prioritization {
    OHOS_CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY = 0,
    OHOS_CAMERA_PHOTO_QUALITY_PRIORITIZATION_SPEED,
} camera_photo_quality_prioritization_t;
#endif
