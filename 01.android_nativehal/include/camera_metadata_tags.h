#pragma once

typedef enum camera_metadata_section {
    ANDROID_COLOR_CORRECTION,
    ANDROID_CONTROL,
    ANDROID_DEMOSAIC,
    ANDROID_EDGE,
    ANDROID_FLASH,
    ANDROID_FLASH_INFO,
    ANDROID_HOT_PIXEL,
    ANDROID_JPEG,
    ANDROID_LENS,
    ANDROID_LENS_INFO,
    ANDROID_NOISE_REDUCTION,
    ANDROID_QUIRKS,
    ANDROID_REQUEST,
    ANDROID_SCALER,
    ANDROID_SENSOR,
    ANDROID_SENSOR_INFO,
    ANDROID_SHADING,
    ANDROID_STATISTICS,
    ANDROID_STATISTICS_INFO,
    ANDROID_TONEMAP,
    ANDROID_LED,
    ANDROID_INFO,
    ANDROID_BLACK_LEVEL,
    ANDROID_SYNC,
    ANDROID_REPROCESS,
    ANDROID_DEPTH,
    ANDROID_LOGICAL_MULTI_CAMERA,
    ANDROID_DISTORTION_CORRECTION,
    ANDROID_HEIC,
    ANDROID_HEIC_INFO,
    ANDROID_AUTOMOTIVE,
    ANDROID_AUTOMOTIVE_LENS,
    ANDROID_EXTENSION,
    ANDROID_JPEGR,
    ANDROID_SHARED_SESSION,
    ANDROID_DESKTOP_EFFECTS,
    ANDROID_SECTION_COUNT,

    VENDOR_SECTION = 0x8000
} camera_metadata_section_t;

typedef enum camera_metadata_section_start {
    ANDROID_COLOR_CORRECTION_START = ANDROID_COLOR_CORRECTION << 16,
    ANDROID_CONTROL_START = ANDROID_CONTROL << 16,
    ANDROID_DEMOSAIC_START = ANDROID_DEMOSAIC << 16,
    ANDROID_EDGE_START = ANDROID_EDGE << 16,
    ANDROID_FLASH_START = ANDROID_FLASH << 16,
    ANDROID_FLASH_INFO_START = ANDROID_FLASH_INFO << 16,
    ANDROID_HOT_PIXEL_START = ANDROID_HOT_PIXEL << 16,
    ANDROID_JPEG_START = ANDROID_JPEG << 16,
    ANDROID_LENS_START = ANDROID_LENS << 16,
    ANDROID_LENS_INFO_START = ANDROID_LENS_INFO << 16,
    ANDROID_NOISE_REDUCTION_START = ANDROID_NOISE_REDUCTION << 16,
    ANDROID_QUIRKS_START = ANDROID_QUIRKS << 16,
    ANDROID_REQUEST_START = ANDROID_REQUEST << 16,
    ANDROID_SCALER_START = ANDROID_SCALER << 16,
    ANDROID_SENSOR_START = ANDROID_SENSOR << 16,
    ANDROID_SENSOR_INFO_START = ANDROID_SENSOR_INFO << 16,
    ANDROID_SHADING_START = ANDROID_SHADING << 16,
    ANDROID_STATISTICS_START = ANDROID_STATISTICS << 16,
    ANDROID_STATISTICS_INFO_START = ANDROID_STATISTICS_INFO << 16,
    ANDROID_TONEMAP_START = ANDROID_TONEMAP << 16,
    ANDROID_LED_START = ANDROID_LED << 16,
    ANDROID_INFO_START = ANDROID_INFO << 16,
    ANDROID_BLACK_LEVEL_START = ANDROID_BLACK_LEVEL << 16,
    ANDROID_SYNC_START = ANDROID_SYNC << 16,
    ANDROID_REPROCESS_START = ANDROID_REPROCESS << 16,
    ANDROID_DEPTH_START = ANDROID_DEPTH << 16,
    ANDROID_LOGICAL_MULTI_CAMERA_START
    = ANDROID_LOGICAL_MULTI_CAMERA
        << 16,
    ANDROID_DISTORTION_CORRECTION_START
    = ANDROID_DISTORTION_CORRECTION
        << 16,
    ANDROID_HEIC_START = ANDROID_HEIC << 16,
    ANDROID_HEIC_INFO_START = ANDROID_HEIC_INFO << 16,
    ANDROID_AUTOMOTIVE_START = ANDROID_AUTOMOTIVE << 16,
    ANDROID_AUTOMOTIVE_LENS_START = ANDROID_AUTOMOTIVE_LENS << 16,
    ANDROID_EXTENSION_START = ANDROID_EXTENSION << 16,
    ANDROID_JPEGR_START = ANDROID_JPEGR << 16,
    ANDROID_SHARED_SESSION_START = ANDROID_SHARED_SESSION << 16,
    ANDROID_DESKTOP_EFFECTS_START = ANDROID_DESKTOP_EFFECTS << 16,
    VENDOR_SECTION_START = VENDOR_SECTION << 16
} camera_metadata_section_start_t;

typedef enum camera_metadata_tag {
    ANDROID_COLOR_CORRECTION_MODE = // enum         | public       | HIDL v3.2
    ANDROID_COLOR_CORRECTION_START,
    ANDROID_COLOR_CORRECTION_TRANSFORM, // rational[]   | public       | HIDL v3.2
    ANDROID_COLOR_CORRECTION_GAINS, // float[]      | public       | HIDL v3.2
    ANDROID_COLOR_CORRECTION_ABERRATION_MODE, // enum         | public       | HIDL v3.2
    ANDROID_COLOR_CORRECTION_AVAILABLE_ABERRATION_MODES,
    // byte[]       | public       | HIDL v3.2
    ANDROID_COLOR_CORRECTION_COLOR_TEMPERATURE, // int32        | public       | HIDL v3.11
    ANDROID_COLOR_CORRECTION_COLOR_TINT, // int32        | public       | HIDL v3.11
    ANDROID_COLOR_CORRECTION_COLOR_TEMPERATURE_RANGE, // int32[]      | public       | HIDL v3.11
    ANDROID_COLOR_CORRECTION_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.11
    ANDROID_COLOR_CORRECTION_END,

    ANDROID_CONTROL_AE_ANTIBANDING_MODE = // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_START,
    ANDROID_CONTROL_AE_EXPOSURE_COMPENSATION, // int32        | public       | HIDL v3.2
    ANDROID_CONTROL_AE_LOCK, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AE_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AE_REGIONS, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_AE_TARGET_FPS_RANGE, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_AE_PRECAPTURE_TRIGGER, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AF_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AF_REGIONS, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_AF_TRIGGER, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AWB_LOCK, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AWB_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AWB_REGIONS, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_CAPTURE_INTENT, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_EFFECT_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_SCENE_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_VIDEO_STABILIZATION_MODE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AE_AVAILABLE_ANTIBANDING_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_AE_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_AE_AVAILABLE_TARGET_FPS_RANGES, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_AE_COMPENSATION_RANGE, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_AE_COMPENSATION_STEP, // rational     | public       | HIDL v3.2
    ANDROID_CONTROL_AF_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_AVAILABLE_EFFECTS, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_AVAILABLE_SCENE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_AVAILABLE_VIDEO_STABILIZATION_MODES,
    // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_AWB_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_MAX_REGIONS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_CONTROL_SCENE_MODE_OVERRIDES, // byte[]       | system       | HIDL v3.2
    ANDROID_CONTROL_AE_PRECAPTURE_ID, // int32        | system       | HIDL v3.2
    ANDROID_CONTROL_AE_STATE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AF_STATE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AF_TRIGGER_ID, // int32        | system       | HIDL v3.2
    ANDROID_CONTROL_AWB_STATE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AVAILABLE_HIGH_SPEED_VIDEO_CONFIGURATIONS,
    // int32[]      | hidden       | HIDL v3.2
    ANDROID_CONTROL_AE_LOCK_AVAILABLE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AWB_LOCK_AVAILABLE, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_CONTROL_POST_RAW_SENSITIVITY_BOOST_RANGE, // int32[]      | public       | HIDL v3.2
    ANDROID_CONTROL_POST_RAW_SENSITIVITY_BOOST, // int32        | public       | HIDL v3.2
    ANDROID_CONTROL_ENABLE_ZSL, // enum         | public       | HIDL v3.2
    ANDROID_CONTROL_AF_SCENE_CHANGE, // enum         | public       | HIDL v3.3
    ANDROID_CONTROL_AVAILABLE_EXTENDED_SCENE_MODE_MAX_SIZES,
    // int32[]      | ndk_public   | HIDL v3.5
    ANDROID_CONTROL_AVAILABLE_EXTENDED_SCENE_MODE_ZOOM_RATIO_RANGES,
    // float[]      | ndk_public   | HIDL v3.5
    ANDROID_CONTROL_EXTENDED_SCENE_MODE, // enum         | public       | HIDL v3.5
    ANDROID_CONTROL_ZOOM_RATIO_RANGE, // float[]      | public       | HIDL v3.5
    ANDROID_CONTROL_ZOOM_RATIO, // float        | public       | HIDL v3.5
    ANDROID_CONTROL_AVAILABLE_HIGH_SPEED_VIDEO_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // int32[]      | hidden       | HIDL v3.6
    ANDROID_CONTROL_AF_REGIONS_SET, // enum         | fwk_only
    ANDROID_CONTROL_AE_REGIONS_SET, // enum         | fwk_only
    ANDROID_CONTROL_AWB_REGIONS_SET, // enum         | fwk_only
    ANDROID_CONTROL_SETTINGS_OVERRIDE, // enum         | public       | HIDL v3.9
    ANDROID_CONTROL_AVAILABLE_SETTINGS_OVERRIDES, // int32[]      | public       | HIDL v3.9
    ANDROID_CONTROL_SETTINGS_OVERRIDING_FRAME_NUMBER, // int32        | system       | HIDL v3.9
    ANDROID_CONTROL_AUTOFRAMING, // enum         | public       | HIDL v3.9
    ANDROID_CONTROL_AUTOFRAMING_AVAILABLE, // enum         | public       | HIDL v3.9
    ANDROID_CONTROL_AUTOFRAMING_STATE, // enum         | public       | HIDL v3.9
    ANDROID_CONTROL_LOW_LIGHT_BOOST_INFO_LUMINANCE_RANGE,
    // float[]      | public       | HIDL v3.10
    ANDROID_CONTROL_LOW_LIGHT_BOOST_STATE, // enum         | public       | HIDL v3.10
    ANDROID_CONTROL_ZOOM_METHOD, // enum         | fwk_public
    ANDROID_CONTROL_AE_PRIORITY_MODE, // enum         | public       | HIDL v3.11
    ANDROID_CONTROL_AE_AVAILABLE_PRIORITY_MODES, // byte[]       | public       | HIDL v3.11
    ANDROID_CONTROL_END,

    ANDROID_DEMOSAIC_MODE = // enum         | system       | HIDL v3.2
    ANDROID_DEMOSAIC_START,
    ANDROID_DEMOSAIC_END,

    ANDROID_EDGE_MODE = // enum         | public       | HIDL v3.2
    ANDROID_EDGE_START,
    ANDROID_EDGE_STRENGTH, // byte         | system       | HIDL v3.2
    ANDROID_EDGE_AVAILABLE_EDGE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_EDGE_END,

    ANDROID_FLASH_FIRING_POWER = // byte         | system       | HIDL v3.2
    ANDROID_FLASH_START,
    ANDROID_FLASH_FIRING_TIME, // int64        | system       | HIDL v3.2
    ANDROID_FLASH_MODE, // enum         | public       | HIDL v3.2
    ANDROID_FLASH_COLOR_TEMPERATURE, // byte         | system       | HIDL v3.2
    ANDROID_FLASH_MAX_ENERGY, // byte         | system       | HIDL v3.2
    ANDROID_FLASH_STATE, // enum         | public       | HIDL v3.2
    ANDROID_FLASH_STRENGTH_LEVEL, // int32        | public       | HIDL v3.10
    ANDROID_FLASH_SINGLE_STRENGTH_MAX_LEVEL, // int32        | public       | HIDL v3.10
    ANDROID_FLASH_SINGLE_STRENGTH_DEFAULT_LEVEL, // int32        | public       | HIDL v3.10
    ANDROID_FLASH_TORCH_STRENGTH_MAX_LEVEL, // int32        | public       | HIDL v3.10
    ANDROID_FLASH_TORCH_STRENGTH_DEFAULT_LEVEL, // int32        | public       | HIDL v3.10
    ANDROID_FLASH_END,

    ANDROID_FLASH_INFO_AVAILABLE = // enum         | public       | HIDL v3.2
    ANDROID_FLASH_INFO_START,
    ANDROID_FLASH_INFO_CHARGE_DURATION, // int64        | system       | HIDL v3.2
    ANDROID_FLASH_INFO_STRENGTH_MAXIMUM_LEVEL, // int32        | public       | HIDL v3.8
    ANDROID_FLASH_INFO_STRENGTH_DEFAULT_LEVEL, // int32        | public       | HIDL v3.8
    ANDROID_FLASH_INFO_END,

    ANDROID_HOT_PIXEL_MODE = // enum         | public       | HIDL v3.2
    ANDROID_HOT_PIXEL_START,
    ANDROID_HOT_PIXEL_AVAILABLE_HOT_PIXEL_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_HOT_PIXEL_END,

    ANDROID_JPEG_GPS_COORDINATES = // double[]     | ndk_public   | HIDL v3.2
    ANDROID_JPEG_START,
    ANDROID_JPEG_GPS_PROCESSING_METHOD, // byte         | ndk_public   | HIDL v3.2
    ANDROID_JPEG_GPS_TIMESTAMP, // int64        | ndk_public   | HIDL v3.2
    ANDROID_JPEG_ORIENTATION, // int32        | public       | HIDL v3.2
    ANDROID_JPEG_QUALITY, // byte         | public       | HIDL v3.2
    ANDROID_JPEG_THUMBNAIL_QUALITY, // byte         | public       | HIDL v3.2
    ANDROID_JPEG_THUMBNAIL_SIZE, // int32[]      | public       | HIDL v3.2
    ANDROID_JPEG_AVAILABLE_THUMBNAIL_SIZES, // int32[]      | public       | HIDL v3.2
    ANDROID_JPEG_MAX_SIZE, // int32        | system       | HIDL v3.2
    ANDROID_JPEG_SIZE, // int32        | system       | HIDL v3.2
    ANDROID_JPEG_END,

    ANDROID_LENS_APERTURE = // float        | public       | HIDL v3.2
    ANDROID_LENS_START,
    ANDROID_LENS_FILTER_DENSITY, // float        | public       | HIDL v3.2
    ANDROID_LENS_FOCAL_LENGTH, // float        | public       | HIDL v3.2
    ANDROID_LENS_FOCUS_DISTANCE, // float        | public       | HIDL v3.2
    ANDROID_LENS_OPTICAL_STABILIZATION_MODE, // enum         | public       | HIDL v3.2
    ANDROID_LENS_FACING, // enum         | public       | HIDL v3.2
    ANDROID_LENS_POSE_ROTATION, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_POSE_TRANSLATION, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_FOCUS_RANGE, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_STATE, // enum         | public       | HIDL v3.2
    ANDROID_LENS_INTRINSIC_CALIBRATION, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_RADIAL_DISTORTION, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_POSE_REFERENCE, // enum         | public       | HIDL v3.3
    ANDROID_LENS_DISTORTION, // float[]      | public       | HIDL v3.3
    ANDROID_LENS_DISTORTION_MAXIMUM_RESOLUTION, // float[]      | public       | HIDL v3.6
    ANDROID_LENS_INTRINSIC_CALIBRATION_MAXIMUM_RESOLUTION,
    // float[]      | public       | HIDL v3.6
    ANDROID_LENS_END,

    ANDROID_LENS_INFO_AVAILABLE_APERTURES = // float[]      | public       | HIDL v3.2
    ANDROID_LENS_INFO_START,
    ANDROID_LENS_INFO_AVAILABLE_FILTER_DENSITIES, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_INFO_AVAILABLE_FOCAL_LENGTHS, // float[]      | public       | HIDL v3.2
    ANDROID_LENS_INFO_AVAILABLE_OPTICAL_STABILIZATION, // byte[]       | public       | HIDL v3.2
    ANDROID_LENS_INFO_HYPERFOCAL_DISTANCE, // float        | public       | HIDL v3.2
    ANDROID_LENS_INFO_MINIMUM_FOCUS_DISTANCE, // float        | public       | HIDL v3.2
    ANDROID_LENS_INFO_SHADING_MAP_SIZE, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_LENS_INFO_FOCUS_DISTANCE_CALIBRATION, // enum         | public       | HIDL v3.2
    ANDROID_LENS_INFO_END,

    ANDROID_NOISE_REDUCTION_MODE = // enum         | public       | HIDL v3.2
    ANDROID_NOISE_REDUCTION_START,
    ANDROID_NOISE_REDUCTION_STRENGTH, // byte         | system       | HIDL v3.2
    ANDROID_NOISE_REDUCTION_AVAILABLE_NOISE_REDUCTION_MODES,
    // byte[]       | public       | HIDL v3.2
    ANDROID_NOISE_REDUCTION_END,

    ANDROID_QUIRKS_METERING_CROP_REGION = // byte         | system       | HIDL v3.2
    ANDROID_QUIRKS_START,
    ANDROID_QUIRKS_TRIGGER_AF_WITH_AUTO, // byte         | system       | HIDL v3.2
    ANDROID_QUIRKS_USE_ZSL_FORMAT, // byte         | system       | HIDL v3.2
    ANDROID_QUIRKS_USE_PARTIAL_RESULT, // byte         | hidden       | HIDL v3.2
    ANDROID_QUIRKS_PARTIAL_RESULT, // enum         | hidden       | HIDL v3.2
    ANDROID_QUIRKS_END,

    ANDROID_REQUEST_FRAME_COUNT = // int32        | hidden       | HIDL v3.2
    ANDROID_REQUEST_START,
    ANDROID_REQUEST_ID, // int32        | hidden       | HIDL v3.2
    ANDROID_REQUEST_INPUT_STREAMS, // int32[]      | system       | HIDL v3.2
    ANDROID_REQUEST_METADATA_MODE, // enum         | system       | HIDL v3.2
    ANDROID_REQUEST_OUTPUT_STREAMS, // int32[]      | system       | HIDL v3.2
    ANDROID_REQUEST_TYPE, // enum         | system       | HIDL v3.2
    ANDROID_REQUEST_MAX_NUM_OUTPUT_STREAMS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_REQUEST_MAX_NUM_REPROCESS_STREAMS, // int32[]      | system       | HIDL v3.2
    ANDROID_REQUEST_MAX_NUM_INPUT_STREAMS, // int32        | java_public  | HIDL v3.2
    ANDROID_REQUEST_PIPELINE_DEPTH, // byte         | public       | HIDL v3.2
    ANDROID_REQUEST_PIPELINE_MAX_DEPTH, // byte         | public       | HIDL v3.2
    ANDROID_REQUEST_PARTIAL_RESULT_COUNT, // int32        | public       | HIDL v3.2
    ANDROID_REQUEST_AVAILABLE_CAPABILITIES, // enum[]       | public       | HIDL v3.2
    ANDROID_REQUEST_AVAILABLE_REQUEST_KEYS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_REQUEST_AVAILABLE_RESULT_KEYS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_REQUEST_AVAILABLE_CHARACTERISTICS_KEYS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_REQUEST_AVAILABLE_SESSION_KEYS, // int32[]      | ndk_public   | HIDL v3.3
    ANDROID_REQUEST_AVAILABLE_PHYSICAL_CAMERA_REQUEST_KEYS,
    // int32[]      | ndk_public   | HIDL v3.3
    ANDROID_REQUEST_CHARACTERISTIC_KEYS_NEEDING_PERMISSION,
    // int32[]      | hidden       | HIDL v3.4
    ANDROID_REQUEST_AVAILABLE_DYNAMIC_RANGE_PROFILES_MAP,
    // enum[]       | ndk_public   | HIDL v3.8
    ANDROID_REQUEST_RECOMMENDED_TEN_BIT_DYNAMIC_RANGE_PROFILE,
    // int64        | java_public  | HIDL v3.8
    ANDROID_REQUEST_AVAILABLE_COLOR_SPACE_PROFILES_MAP,
    // enum[]       | ndk_public   | HIDL v3.9
    ANDROID_REQUEST_END,

    ANDROID_SCALER_CROP_REGION = // int32[]      | public       | HIDL v3.2
    ANDROID_SCALER_START,
    ANDROID_SCALER_AVAILABLE_FORMATS, // enum[]       | hidden       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_JPEG_MIN_DURATIONS, // int64[]      | hidden       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_JPEG_SIZES, // int32[]      | hidden       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_MAX_DIGITAL_ZOOM, // float        | public       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_PROCESSED_MIN_DURATIONS, // int64[]      | hidden       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_PROCESSED_SIZES, // int32[]      | hidden       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_RAW_MIN_DURATIONS, // int64[]      | system       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_RAW_SIZES, // int32[]      | system       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_INPUT_OUTPUT_FORMATS_MAP, // int32        | hidden       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_STREAM_CONFIGURATIONS, // enum[]       | ndk_public   | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_MIN_FRAME_DURATIONS, // int64[]      | ndk_public   | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_STALL_DURATIONS, // int64[]      | ndk_public   | HIDL v3.2
    ANDROID_SCALER_CROPPING_TYPE, // enum         | public       | HIDL v3.2
    ANDROID_SCALER_AVAILABLE_RECOMMENDED_STREAM_CONFIGURATIONS,
    // enum[]       | ndk_public   | HIDL v3.4
    ANDROID_SCALER_AVAILABLE_RECOMMENDED_INPUT_OUTPUT_FORMATS_MAP,
    // int32        | ndk_public   | HIDL v3.4
    ANDROID_SCALER_AVAILABLE_ROTATE_AND_CROP_MODES, // byte[]       | public       | HIDL v3.5
    ANDROID_SCALER_ROTATE_AND_CROP, // enum         | public       | HIDL v3.5
    ANDROID_SCALER_DEFAULT_SECURE_IMAGE_SIZE, // int32[]      | public       | HIDL v3.6
    ANDROID_SCALER_PHYSICAL_CAMERA_MULTI_RESOLUTION_STREAM_CONFIGURATIONS,
    // enum[]       | ndk_public   | HIDL v3.6
    ANDROID_SCALER_AVAILABLE_STREAM_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // enum[]       | ndk_public   | HIDL v3.6
    ANDROID_SCALER_AVAILABLE_MIN_FRAME_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_SCALER_AVAILABLE_STALL_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_SCALER_AVAILABLE_INPUT_OUTPUT_FORMATS_MAP_MAXIMUM_RESOLUTION,
    // int32        | hidden       | HIDL v3.6
    ANDROID_SCALER_MULTI_RESOLUTION_STREAM_SUPPORTED, // enum         | ndk_public   | HIDL v3.6
    ANDROID_SCALER_CROP_REGION_SET, // enum         | fwk_only
    ANDROID_SCALER_AVAILABLE_STREAM_USE_CASES, // enum[]       | public       | HIDL v3.8
    ANDROID_SCALER_RAW_CROP_REGION, // int32[]      | public       | HIDL v3.9
    ANDROID_SCALER_END,

    ANDROID_SENSOR_EXPOSURE_TIME = // int64        | public       | HIDL v3.2
    ANDROID_SENSOR_START,
    ANDROID_SENSOR_FRAME_DURATION, // int64        | public       | HIDL v3.2
    ANDROID_SENSOR_SENSITIVITY, // int32        | public       | HIDL v3.2
    ANDROID_SENSOR_REFERENCE_ILLUMINANT1, // enum         | public       | HIDL v3.2
    ANDROID_SENSOR_REFERENCE_ILLUMINANT2, // byte         | public       | HIDL v3.2
    ANDROID_SENSOR_CALIBRATION_TRANSFORM1, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_CALIBRATION_TRANSFORM2, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_COLOR_TRANSFORM1, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_COLOR_TRANSFORM2, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_FORWARD_MATRIX1, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_FORWARD_MATRIX2, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_BASE_GAIN_FACTOR, // rational     | system       | HIDL v3.2
    ANDROID_SENSOR_BLACK_LEVEL_PATTERN, // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_MAX_ANALOG_SENSITIVITY, // int32        | public       | HIDL v3.2
    ANDROID_SENSOR_ORIENTATION, // int32        | public       | HIDL v3.2
    ANDROID_SENSOR_PROFILE_HUE_SAT_MAP_DIMENSIONS, // int32[]      | system       | HIDL v3.2
    ANDROID_SENSOR_TIMESTAMP, // int64        | public       | HIDL v3.2
    ANDROID_SENSOR_TEMPERATURE, // float        | system       | HIDL v3.2
    ANDROID_SENSOR_NEUTRAL_COLOR_POINT, // rational[]   | public       | HIDL v3.2
    ANDROID_SENSOR_NOISE_PROFILE, // double[]     | public       | HIDL v3.2
    ANDROID_SENSOR_PROFILE_HUE_SAT_MAP, // float[]      | system       | HIDL v3.2
    ANDROID_SENSOR_PROFILE_TONE_CURVE, // float[]      | system       | HIDL v3.2
    ANDROID_SENSOR_GREEN_SPLIT, // float        | public       | HIDL v3.2
    ANDROID_SENSOR_TEST_PATTERN_DATA, // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_TEST_PATTERN_MODE, // enum         | public       | HIDL v3.2
    ANDROID_SENSOR_AVAILABLE_TEST_PATTERN_MODES, // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_ROLLING_SHUTTER_SKEW, // int64        | public       | HIDL v3.2
    ANDROID_SENSOR_OPTICAL_BLACK_REGIONS, // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_DYNAMIC_BLACK_LEVEL, // float[]      | public       | HIDL v3.2
    ANDROID_SENSOR_DYNAMIC_WHITE_LEVEL, // int32        | public       | HIDL v3.2
    ANDROID_SENSOR_OPAQUE_RAW_SIZE, // int32[]      | system       | HIDL v3.2
    ANDROID_SENSOR_OPAQUE_RAW_SIZE_MAXIMUM_RESOLUTION, // int32[]      | system       | HIDL v3.6
    ANDROID_SENSOR_PIXEL_MODE, // enum         | public       | HIDL v3.6
    ANDROID_SENSOR_RAW_BINNING_FACTOR_USED, // enum         | public       | HIDL v3.6
    ANDROID_SENSOR_READOUT_TIMESTAMP, // enum         | java_public  | HIDL v3.8
    ANDROID_SENSOR_END,

    ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE = // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_START,
    ANDROID_SENSOR_INFO_SENSITIVITY_RANGE, // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_COLOR_FILTER_ARRANGEMENT, // enum         | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_EXPOSURE_TIME_RANGE, // int64[]      | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_MAX_FRAME_DURATION, // int64        | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_PHYSICAL_SIZE, // float[]      | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_PIXEL_ARRAY_SIZE, // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_WHITE_LEVEL, // int32        | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_TIMESTAMP_SOURCE, // enum         | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_LENS_SHADING_APPLIED, // enum         | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_PRE_CORRECTION_ACTIVE_ARRAY_SIZE,
    // int32[]      | public       | HIDL v3.2
    ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE_MAXIMUM_RESOLUTION,
    // int32[]      | public       | HIDL v3.6
    ANDROID_SENSOR_INFO_PIXEL_ARRAY_SIZE_MAXIMUM_RESOLUTION,
    // int32[]      | public       | HIDL v3.6
    ANDROID_SENSOR_INFO_PRE_CORRECTION_ACTIVE_ARRAY_SIZE_MAXIMUM_RESOLUTION,
    // int32[]      | public       | HIDL v3.6
    ANDROID_SENSOR_INFO_BINNING_FACTOR, // int32[]      | public       | HIDL v3.6
    ANDROID_SENSOR_INFO_END,

    ANDROID_SHADING_MODE = // enum         | public       | HIDL v3.2
    ANDROID_SHADING_START,
    ANDROID_SHADING_STRENGTH, // byte         | system       | HIDL v3.2
    ANDROID_SHADING_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_SHADING_END,

    ANDROID_STATISTICS_FACE_DETECT_MODE = // enum         | public       | HIDL v3.2
    ANDROID_STATISTICS_START,
    ANDROID_STATISTICS_HISTOGRAM_MODE, // enum         | system       | HIDL v3.2
    ANDROID_STATISTICS_SHARPNESS_MAP_MODE, // enum         | system       | HIDL v3.2
    ANDROID_STATISTICS_HOT_PIXEL_MAP_MODE, // enum         | public       | HIDL v3.2
    ANDROID_STATISTICS_FACE_IDS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_STATISTICS_FACE_LANDMARKS, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_STATISTICS_FACE_RECTANGLES, // int32[]      | ndk_public   | HIDL v3.2
    ANDROID_STATISTICS_FACE_SCORES, // byte[]       | ndk_public   | HIDL v3.2
    ANDROID_STATISTICS_HISTOGRAM, // int32[]      | system       | HIDL v3.2
    ANDROID_STATISTICS_SHARPNESS_MAP, // int32[]      | system       | HIDL v3.2
    ANDROID_STATISTICS_LENS_SHADING_CORRECTION_MAP, // byte         | java_public  | HIDL v3.2
    ANDROID_STATISTICS_LENS_SHADING_MAP, // float[]      | ndk_public   | HIDL v3.2
    ANDROID_STATISTICS_PREDICTED_COLOR_GAINS, // float[]      | hidden       | HIDL v3.2
    ANDROID_STATISTICS_PREDICTED_COLOR_TRANSFORM, // rational[]   | hidden       | HIDL v3.2
    ANDROID_STATISTICS_SCENE_FLICKER, // enum         | public       | HIDL v3.2
    ANDROID_STATISTICS_HOT_PIXEL_MAP, // int32[]      | public       | HIDL v3.2
    ANDROID_STATISTICS_LENS_SHADING_MAP_MODE, // enum         | public       | HIDL v3.2
    ANDROID_STATISTICS_OIS_DATA_MODE, // enum         | public       | HIDL v3.3
    ANDROID_STATISTICS_OIS_TIMESTAMPS, // int64[]      | ndk_public   | HIDL v3.3
    ANDROID_STATISTICS_OIS_X_SHIFTS, // float[]      | ndk_public   | HIDL v3.3
    ANDROID_STATISTICS_OIS_Y_SHIFTS, // float[]      | ndk_public   | HIDL v3.3
    ANDROID_STATISTICS_LENS_INTRINSIC_TIMESTAMPS, // int64[]      | ndk_public   | HIDL v3.10
    ANDROID_STATISTICS_LENS_INTRINSIC_SAMPLES, // float[]      | ndk_public   | HIDL v3.10
    ANDROID_STATISTICS_END,

    ANDROID_STATISTICS_INFO_AVAILABLE_FACE_DETECT_MODES =
        // byte[]       | public       | HIDL v3.2
    ANDROID_STATISTICS_INFO_START,
    ANDROID_STATISTICS_INFO_HISTOGRAM_BUCKET_COUNT, // int32        | system       | HIDL v3.2
    ANDROID_STATISTICS_INFO_MAX_FACE_COUNT, // int32        | public       | HIDL v3.2
    ANDROID_STATISTICS_INFO_MAX_HISTOGRAM_COUNT, // int32        | system       | HIDL v3.2
    ANDROID_STATISTICS_INFO_MAX_SHARPNESS_MAP_VALUE, // int32        | system       | HIDL v3.2
    ANDROID_STATISTICS_INFO_SHARPNESS_MAP_SIZE, // int32[]      | system       | HIDL v3.2
    ANDROID_STATISTICS_INFO_AVAILABLE_HOT_PIXEL_MAP_MODES,
    // byte[]       | public       | HIDL v3.2
    ANDROID_STATISTICS_INFO_AVAILABLE_LENS_SHADING_MAP_MODES,
    // byte[]       | public       | HIDL v3.2
    ANDROID_STATISTICS_INFO_AVAILABLE_OIS_DATA_MODES, // byte[]       | public       | HIDL v3.3
    ANDROID_STATISTICS_INFO_END,

    ANDROID_TONEMAP_CURVE_BLUE = // float[]      | ndk_public   | HIDL v3.2
    ANDROID_TONEMAP_START,
    ANDROID_TONEMAP_CURVE_GREEN, // float[]      | ndk_public   | HIDL v3.2
    ANDROID_TONEMAP_CURVE_RED, // float[]      | ndk_public   | HIDL v3.2
    ANDROID_TONEMAP_MODE, // enum         | public       | HIDL v3.2
    ANDROID_TONEMAP_MAX_CURVE_POINTS, // int32        | public       | HIDL v3.2
    ANDROID_TONEMAP_AVAILABLE_TONE_MAP_MODES, // byte[]       | public       | HIDL v3.2
    ANDROID_TONEMAP_GAMMA, // float        | public       | HIDL v3.2
    ANDROID_TONEMAP_PRESET_CURVE, // enum         | public       | HIDL v3.2
    ANDROID_TONEMAP_END,

    ANDROID_LED_TRANSMIT = // enum         | hidden       | HIDL v3.2
    ANDROID_LED_START,
    ANDROID_LED_AVAILABLE_LEDS, // enum[]       | hidden       | HIDL v3.2
    ANDROID_LED_END,

    ANDROID_INFO_SUPPORTED_HARDWARE_LEVEL = // enum         | public       | HIDL v3.2
    ANDROID_INFO_START,
    ANDROID_INFO_VERSION, // byte         | public       | HIDL v3.3
    ANDROID_INFO_SUPPORTED_BUFFER_MANAGEMENT_VERSION, // enum         | system       | HIDL v3.4
    ANDROID_INFO_DEVICE_STATE_ORIENTATIONS, // int64[]      | ndk_public   | HIDL v3.7
    ANDROID_INFO_SESSION_CONFIGURATION_QUERY_VERSION, // enum         | fwk_java_public
    ANDROID_INFO_DEVICE_ID, // int32        | fwk_only
    ANDROID_INFO_END,

    ANDROID_BLACK_LEVEL_LOCK = // enum         | public       | HIDL v3.2
    ANDROID_BLACK_LEVEL_START,
    ANDROID_BLACK_LEVEL_END,

    ANDROID_SYNC_FRAME_NUMBER = // enum         | ndk_public   | HIDL v3.2
    ANDROID_SYNC_START,
    ANDROID_SYNC_MAX_LATENCY, // enum         | public       | HIDL v3.2
    ANDROID_SYNC_END,

    ANDROID_REPROCESS_EFFECTIVE_EXPOSURE_FACTOR = // float        | java_public  | HIDL v3.2
    ANDROID_REPROCESS_START,
    ANDROID_REPROCESS_MAX_CAPTURE_STALL, // int32        | java_public  | HIDL v3.2
    ANDROID_REPROCESS_END,

    ANDROID_DEPTH_MAX_DEPTH_SAMPLES = // int32        | system       | HIDL v3.2
    ANDROID_DEPTH_START,
    ANDROID_DEPTH_AVAILABLE_DEPTH_STREAM_CONFIGURATIONS,
    // enum[]       | ndk_public   | HIDL v3.2
    ANDROID_DEPTH_AVAILABLE_DEPTH_MIN_FRAME_DURATIONS, // int64[]      | ndk_public   | HIDL v3.2
    ANDROID_DEPTH_AVAILABLE_DEPTH_STALL_DURATIONS, // int64[]      | ndk_public   | HIDL v3.2
    ANDROID_DEPTH_DEPTH_IS_EXCLUSIVE, // enum         | public       | HIDL v3.2
    ANDROID_DEPTH_AVAILABLE_RECOMMENDED_DEPTH_STREAM_CONFIGURATIONS,
    // int32[]      | ndk_public   | HIDL v3.4
    ANDROID_DEPTH_AVAILABLE_DYNAMIC_DEPTH_STREAM_CONFIGURATIONS,
    // enum[]       | ndk_public   | HIDL v3.4
    ANDROID_DEPTH_AVAILABLE_DYNAMIC_DEPTH_MIN_FRAME_DURATIONS,
    // int64[]      | ndk_public   | HIDL v3.4
    ANDROID_DEPTH_AVAILABLE_DYNAMIC_DEPTH_STALL_DURATIONS,
    // int64[]      | ndk_public   | HIDL v3.4
    ANDROID_DEPTH_AVAILABLE_DEPTH_STREAM_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // enum[]       | ndk_public   | HIDL v3.6
    ANDROID_DEPTH_AVAILABLE_DEPTH_MIN_FRAME_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_DEPTH_AVAILABLE_DEPTH_STALL_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_DEPTH_AVAILABLE_DYNAMIC_DEPTH_STREAM_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // enum[]       | ndk_public   | HIDL v3.6
    ANDROID_DEPTH_AVAILABLE_DYNAMIC_DEPTH_MIN_FRAME_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_DEPTH_AVAILABLE_DYNAMIC_DEPTH_STALL_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_DEPTH_END,

    ANDROID_LOGICAL_MULTI_CAMERA_PHYSICAL_IDS = // byte[]       | ndk_public   | HIDL v3.3
    ANDROID_LOGICAL_MULTI_CAMERA_START,
    ANDROID_LOGICAL_MULTI_CAMERA_SENSOR_SYNC_TYPE, // enum         | public       | HIDL v3.3
    ANDROID_LOGICAL_MULTI_CAMERA_ACTIVE_PHYSICAL_ID, // byte         | public       | HIDL v3.4
    ANDROID_LOGICAL_MULTI_CAMERA_ACTIVE_PHYSICAL_SENSOR_CROP_REGION,
    // int32[]      | public       | HIDL v3.10
    ANDROID_LOGICAL_MULTI_CAMERA_END,

    ANDROID_DISTORTION_CORRECTION_MODE = // enum         | public       | HIDL v3.3
    ANDROID_DISTORTION_CORRECTION_START,
    ANDROID_DISTORTION_CORRECTION_AVAILABLE_MODES, // byte[]       | public       | HIDL v3.3
    ANDROID_DISTORTION_CORRECTION_END,

    ANDROID_HEIC_AVAILABLE_HEIC_STREAM_CONFIGURATIONS =
        // enum[]       | ndk_public   | HIDL v3.4
    ANDROID_HEIC_START,
    ANDROID_HEIC_AVAILABLE_HEIC_MIN_FRAME_DURATIONS, // int64[]      | ndk_public   | HIDL v3.4
    ANDROID_HEIC_AVAILABLE_HEIC_STALL_DURATIONS, // int64[]      | ndk_public   | HIDL v3.4
    ANDROID_HEIC_AVAILABLE_HEIC_STREAM_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // enum[]       | ndk_public   | HIDL v3.6
    ANDROID_HEIC_AVAILABLE_HEIC_MIN_FRAME_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_HEIC_AVAILABLE_HEIC_STALL_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.6
    ANDROID_HEIC_AVAILABLE_HEIC_ULTRA_HDR_STREAM_CONFIGURATIONS,
    // enum[]       | ndk_public   | HIDL v3.11
    ANDROID_HEIC_AVAILABLE_HEIC_ULTRA_HDR_MIN_FRAME_DURATIONS,
    // int64[]      | ndk_public   | HIDL v3.11
    ANDROID_HEIC_AVAILABLE_HEIC_ULTRA_HDR_STALL_DURATIONS,
    // int64[]      | ndk_public   | HIDL v3.11
    ANDROID_HEIC_AVAILABLE_HEIC_ULTRA_HDR_STREAM_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // enum[]       | ndk_public   | HIDL v3.11
    ANDROID_HEIC_AVAILABLE_HEIC_ULTRA_HDR_MIN_FRAME_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.11
    ANDROID_HEIC_AVAILABLE_HEIC_ULTRA_HDR_STALL_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.11
    ANDROID_HEIC_END,

    ANDROID_HEIC_INFO_SUPPORTED = // enum         | system       | HIDL v3.4
    ANDROID_HEIC_INFO_START,
    ANDROID_HEIC_INFO_MAX_JPEG_APP_SEGMENTS_COUNT, // byte         | system       | HIDL v3.4
    ANDROID_HEIC_INFO_END,

    ANDROID_AUTOMOTIVE_LOCATION = // enum         | public       | HIDL v3.8
    ANDROID_AUTOMOTIVE_START,
    ANDROID_AUTOMOTIVE_END,

    ANDROID_AUTOMOTIVE_LENS_FACING = // enum[]       | public       | HIDL v3.8
    ANDROID_AUTOMOTIVE_LENS_START,
    ANDROID_AUTOMOTIVE_LENS_END,

    ANDROID_EXTENSION_STRENGTH = // int32        | extension_passthrough | HIDL v3.9
    ANDROID_EXTENSION_START,
    ANDROID_EXTENSION_CURRENT_TYPE, // int32        | fwk_java_public
    ANDROID_EXTENSION_NIGHT_MODE_INDICATOR, // enum         | public       | HIDL v3.11
    ANDROID_EXTENSION_END,

    ANDROID_JPEGR_AVAILABLE_JPEG_R_STREAM_CONFIGURATIONS =
        // enum[]       | ndk_public   | HIDL v3.9
    ANDROID_JPEGR_START,
    ANDROID_JPEGR_AVAILABLE_JPEG_R_MIN_FRAME_DURATIONS,
    // int64[]      | ndk_public   | HIDL v3.9
    ANDROID_JPEGR_AVAILABLE_JPEG_R_STALL_DURATIONS, // int64[]      | ndk_public   | HIDL v3.9
    ANDROID_JPEGR_AVAILABLE_JPEG_R_STREAM_CONFIGURATIONS_MAXIMUM_RESOLUTION,
    // enum[]       | ndk_public   | HIDL v3.9
    ANDROID_JPEGR_AVAILABLE_JPEG_R_MIN_FRAME_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.9
    ANDROID_JPEGR_AVAILABLE_JPEG_R_STALL_DURATIONS_MAXIMUM_RESOLUTION,
    // int64[]      | ndk_public   | HIDL v3.9
    ANDROID_JPEGR_END,

    ANDROID_SHARED_SESSION_COLOR_SPACE = // enum         | fwk_only
    ANDROID_SHARED_SESSION_START,
    ANDROID_SHARED_SESSION_OUTPUT_CONFIGURATIONS, // int64[]      | fwk_only
    ANDROID_SHARED_SESSION_END,

    ANDROID_DESKTOP_EFFECTS_CAPABILITIES = // enum[]       | system       | HIDL v3.2
    ANDROID_DESKTOP_EFFECTS_START,
    ANDROID_DESKTOP_EFFECTS_BACKGROUND_BLUR_MODES, // byte[]       | system       | HIDL v3.2
    ANDROID_DESKTOP_EFFECTS_BACKGROUND_BLUR_MODE, // enum         | system       | HIDL v3.2
    ANDROID_DESKTOP_EFFECTS_FACE_RETOUCH_MODE, // enum         | system       | HIDL v3.2
    ANDROID_DESKTOP_EFFECTS_FACE_RETOUCH_STRENGTH, // byte         | system       | HIDL v3.2
    ANDROID_DESKTOP_EFFECTS_PORTRAIT_RELIGHT_MODE, // enum         | system       | HIDL v3.2
    ANDROID_DESKTOP_EFFECTS_END,

} camera_metadata_tag_t;