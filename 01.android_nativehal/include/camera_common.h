#pragma once

#include "camera_metadata.h"
#include "camera_metadata_tags.h"
#include "camera_vendor_tags.h"
#include "graphics.h"
#include "hardware.h"
#include <stdint.h>

#define CAMERA_HARDWARE_MODULE_ID "camera"

#define CAMERA_MODULE_API_VERSION_1_0 HARDWARE_MODULE_API_VERSION(1, 0)
#define CAMERA_MODULE_API_VERSION_2_0 HARDWARE_MODULE_API_VERSION(2, 0)
#define CAMERA_MODULE_API_VERSION_2_1 HARDWARE_MODULE_API_VERSION(2, 1)
#define CAMERA_MODULE_API_VERSION_2_2 HARDWARE_MODULE_API_VERSION(2, 2)
#define CAMERA_MODULE_API_VERSION_2_3 HARDWARE_MODULE_API_VERSION(2, 3)
#define CAMERA_MODULE_API_VERSION_2_4 HARDWARE_MODULE_API_VERSION(2, 4)
#define CAMERA_MODULE_API_VERSION_2_5 HARDWARE_MODULE_API_VERSION(2, 5)

#define CAMERA_MODULE_API_VERSION_CURRENT CAMERA_MODULE_API_VERSION_2_5

#define CAMERA_DEVICE_API_VERSION_1_0 HARDWARE_DEVICE_API_VERSION(1, 0) // DEPRECATED
#define CAMERA_DEVICE_API_VERSION_2_0 HARDWARE_DEVICE_API_VERSION(2, 0) // NO LONGER SUPPORTED
#define CAMERA_DEVICE_API_VERSION_2_1 HARDWARE_DEVICE_API_VERSION(2, 1) // NO LONGER SUPPORTED
#define CAMERA_DEVICE_API_VERSION_3_0 HARDWARE_DEVICE_API_VERSION(3, 0) // NO LONGER SUPPORTED
#define CAMERA_DEVICE_API_VERSION_3_1 HARDWARE_DEVICE_API_VERSION(3, 1) // NO LONGER SUPPORTED
#define CAMERA_DEVICE_API_VERSION_3_2 HARDWARE_DEVICE_API_VERSION(3, 2)
#define CAMERA_DEVICE_API_VERSION_3_3 HARDWARE_DEVICE_API_VERSION(3, 3)
#define CAMERA_DEVICE_API_VERSION_3_4 HARDWARE_DEVICE_API_VERSION(3, 4)
#define CAMERA_DEVICE_API_VERSION_3_5 HARDWARE_DEVICE_API_VERSION(3, 5)
#define CAMERA_DEVICE_API_VERSION_3_6 HARDWARE_DEVICE_API_VERSION(3, 6)

#define CAMERA_DEVICE_API_VERSION_CURRENT CAMERA_DEVICE_API_VERSION_3_5

typedef struct camera_stream {
    int stream_type;
    uint32_t width;
    uint32_t height;
    int format;
    uint32_t usage;
    android_dataspace_t data_space;
    int rotation;
    const char* physical_camera_id;
} camera_stream_t;

typedef struct camera_stream_combination {
    uint32_t num_streams;
    camera_stream_t* streams;
    uint32_t operation_mode;
} camera_stream_combination_t;

typedef struct camera_module_callbacks {
    void (*camera_device_status_change)(const struct camera_module_callbacks*,
        int camera_id,
        int new_status);

    void (*torch_mode_status_change)(const struct camera_module_callbacks*,
        const char* camera_id,
        int new_status);

} camera_module_callbacks_t;

typedef struct camera_module {
    hw_module_t common;
    int (*get_number_of_cameras)(void);
    int (*get_camera_info)(int camera_id, struct camera_info* info);
    int (*set_callbacks)(const camera_module_callbacks_t* callbacks);
    void (*get_vendor_tag_ops)(vendor_tag_ops_t* ops);
    int (*open_legacy)(const struct hw_module_t* module, const char* id,
        uint32_t halVersion, struct hw_device_t** device);
    int (*set_torch_mode)(const char* camera_id, bool enabled);
    int (*init)();
    int (*get_physical_camera_info)(int physical_camera_id,
        camera_metadata_t** static_metadata);
    int (*is_stream_combination_supported)(int camera_id,
        const camera_stream_combination_t* streams);
    void (*notify_device_state_change)(uint64_t deviceState);
    int (*get_camera_device_version)(int camera_id, uint32_t* version);
    void* reserved[1];
} camera_module_t;