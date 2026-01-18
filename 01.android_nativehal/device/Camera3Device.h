#pragma once

extern "C" {
#include "../include/camera3.h"
}
#include "../module/CameraModule.h"

class Camera3Device : public camera3_callback_ops_t {
public:
    Camera3Device();
    ~Camera3Device();

    void Setup();
    void OpenCamera(int cameraId);
    void CloseCamera(int cameraId);
    void ProcessCaptureResult(const camera3_capture_result* result);
    void sNotify(const camera3_notify_msg* msg);
    camera3_buffer_request_status_t RequestStreamBuffers(uint32_t num_buffer_reqs, const camera3_buffer_request_t* buffer_reqs,
        uint32_t* num_returned_buf_reqs, camera3_stream_buffer_ret_t* returned_buf_reqs);
    void ReturnStreamBuffers(uint32_t num_buffers, const camera3_stream_buffer_t* const* buffers);

private:
    CameraModule camera_module;
    camera3_device_t* camera3_device = nullptr;
};