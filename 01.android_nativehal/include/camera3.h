#pragma once

#include "camera_metadata.h"
#include "graphics.h"
#include "hardware.h"
#include "native_handle.h"
#include <stdint.h>

typedef struct camera3_stream {
    int stream_type;
    uint32_t width;
    uint32_t height;
    int format;
    uint32_t usage;
    uint32_t max_buffers;
    void* priv;
    android_dataspace_t data_space;
    int rotation;
    void* reserved[6];
} camera3_stream_t;

typedef struct camera3_stream_buffer {
    camera3_stream_t* stream;
    buffer_handle_t* buffer;
    int status;
    int acquire_fence;
    int release_fence;
} camera3_stream_buffer_t;

typedef struct camera3_capture_request {
    uint32_t frame_number;
    const camera_metadata_t* settings;
    camera3_stream_buffer_t* input_buffer;
    uint32_t num_output_buffers;
    const camera3_stream_buffer_t* output_buffers;
    uint32_t num_physcam_settings;
    const char** physcam_id;
    const camera_metadata_t** physcam_settings;
} camera3_capture_request_t;

typedef struct camera3_capture_result {
    uint32_t frame_number;
    const camera_metadata_t* result;
    uint32_t num_output_buffers;
    const camera3_stream_buffer_t* output_buffers;
    const camera3_stream_buffer_t* input_buffer;
    uint32_t partial_result;
    uint32_t num_physcam_metadata;
    const char** physcam_ids;
    const camera_metadata_t** physcam_metadata;
} camera3_capture_result_t;

typedef enum camera3_msg_type {
    CAMERA3_MSG_ERROR = 1,
    CAMERA3_MSG_SHUTTER = 2,
    CAMERA3_NUM_MESSAGES
} camera3_msg_type_t;

typedef enum camera3_error_msg_code {
    CAMERA3_MSG_ERROR_DEVICE = 1,
    CAMERA3_MSG_ERROR_REQUEST = 2,
    CAMERA3_MSG_ERROR_RESULT = 3,
    CAMERA3_MSG_ERROR_BUFFER = 4,
    CAMERA3_MSG_NUM_ERRORS
} camera3_error_msg_code_t;

typedef struct camera3_error_msg {
    uint32_t frame_number;
    camera3_stream_t* error_stream;
    int error_code;
} camera3_error_msg_t;

typedef struct camera3_shutter_msg {
    uint32_t frame_number;
    uint64_t timestamp;
} camera3_shutter_msg_t;

typedef struct camera3_notify_msg {
    int type;
    union {
        camera3_error_msg_t error;
        camera3_shutter_msg_t shutter;
        uint8_t generic[32];
    } message;
} camera3_notify_msg_t;

typedef enum camera3_buffer_request_status {
    CAMERA3_BUF_REQ_OK = 0,
    CAMERA3_BUF_REQ_FAILED_PARTIAL = 1,
    CAMERA3_BUF_REQ_FAILED_CONFIGURING = 2,
    CAMERA3_BUF_REQ_FAILED_ILLEGAL_ARGUMENTS = 3,
    CAMERA3_BUF_REQ_FAILED_UNKNOWN = 4,
    CAMERA3_BUF_REQ_NUM_STATUS
} camera3_buffer_request_status_t;

typedef struct camera3_buffer_request {
    camera3_stream_t* stream;
    uint32_t num_buffers_requested;
} camera3_buffer_request_t;

typedef enum camera3_stream_buffer_req_status {
    CAMERA3_PS_BUF_REQ_OK = 0,
    CAMERA3_PS_BUF_REQ_NO_BUFFER_AVAILABLE = 1,
    CAMERA3_PS_BUF_REQ_MAX_BUFFER_EXCEEDED = 2,
    CAMERA3_PS_BUF_REQ_STREAM_DISCONNECTED = 3,
    CAMERA3_PS_BUF_REQ_UNKNOWN_ERROR = 4,
    CAMERA3_PS_BUF_REQ_NUM_STATUS
} camera3_stream_buffer_req_status_t;

typedef struct camera3_stream_buffer_ret {
    camera3_stream_t* stream;
    camera3_stream_buffer_req_status_t status;
    uint32_t num_output_buffers;
    camera3_stream_buffer_t* output_buffers;
} camera3_stream_buffer_ret_t;

typedef struct camera3_callback_ops {
    void (*process_capture_result)(const struct camera3_callback_ops*,
        const camera3_capture_result_t* result);
    void (*notify)(const struct camera3_callback_ops*,
        const camera3_notify_msg_t* msg);
    camera3_buffer_request_status_t (*request_stream_buffers)(
        const struct camera3_callback_ops*,
        uint32_t num_buffer_reqs,
        const camera3_buffer_request_t* buffer_reqs,
        /*out*/ uint32_t* num_returned_buf_reqs,
        /*out*/ camera3_stream_buffer_ret_t* returned_buf_reqs);
    void (*return_stream_buffers)(
        const struct camera3_callback_ops*,
        uint32_t num_buffers,
        const camera3_stream_buffer_t* const* buffers);
} camera3_callback_ops_t;

typedef struct camera3_stream_configuration {
    uint32_t num_streams;
    camera3_stream_t** streams;
    uint32_t operation_mode;
    const camera_metadata_t* session_parameters;
} camera3_stream_configuration_t;

typedef struct camera3_stream_buffer_set {
    camera3_stream_t* stream;
    uint32_t num_buffers;
    buffer_handle_t** buffers;
} camera3_stream_buffer_set_t;

typedef struct camera3_device_ops {
    int (*initialize)(const struct camera3_device*,
        const camera3_callback_ops_t* callback_ops);
    int (*configure_streams)(const struct camera3_device*,
        camera3_stream_configuration_t* stream_list);
    int (*register_stream_buffers)(const struct camera3_device*,
        const camera3_stream_buffer_set_t* buffer_set);
    const camera_metadata_t* (*construct_default_request_settings)(
        const struct camera3_device*,
        int type);
    int (*process_capture_request)(const struct camera3_device*,
        camera3_capture_request_t* request);
    void (*get_metadata_vendor_tag_ops)(const struct camera3_device*,
        vendor_tag_query_ops_t* ops);
    void (*dump)(const struct camera3_device*, int fd);
    int (*flush)(const struct camera3_device*);
    void (*signal_stream_flush)(const struct camera3_device*,
        uint32_t num_streams,
        const camera3_stream_t* const* streams);
    int (*is_reconfiguration_required)(const struct camera3_device*,
        const camera_metadata_t* old_session_params,
        const camera_metadata_t* new_session_params);
    void* reserved[6];
} camera3_device_ops_t;

typedef struct camera3_device {
    hw_device_t common;
    camera3_device_ops_t* ops;
    void* priv;
} camera3_device_t;