#include "Camera3Device.h"
#include "../include/log.h"
#include <string>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "CAMERA3_DEVICE"

static void aprocess_capture_result(
    const camera3_callback_ops* cb, //[in] fn pointer to callbacks
    const camera3_capture_result* result) //[in] capture result for a request
{

    Camera3Device* device = const_cast<Camera3Device*>(static_cast<const Camera3Device*>(cb));

    device->ProcessCaptureResult(result);
}

static void anotify(
    const camera3_callback_ops* cb, //[in] fn pointer to callback methods
    const camera3_notify_msg* msg) //[in] message notification
{
    Camera3Device* device = const_cast<Camera3Device*>(static_cast<const Camera3Device*>(cb));
    device->sNotify(msg);
}

static camera3_buffer_request_status_t arequest_stream_buffers(const struct camera3_callback_ops* cb, uint32_t num_buffer_reqs,
    const camera3_buffer_request_t* buffer_reqs, uint32_t* num_returned_buf_reqs,
    camera3_stream_buffer_ret_t* returned_buf_reqs)
{
    Camera3Device* device = const_cast<Camera3Device*>(static_cast<const Camera3Device*>(cb));
    if (num_buffer_reqs == 0 || buffer_reqs == nullptr || num_returned_buf_reqs == nullptr || returned_buf_reqs == nullptr) {
        LOGE("Invalid argument num_buffer_reqs %d | buffer_reqs could be null | num_returned_buf_reqs could be null |"
             " returned_buf_reqs could be null",
            num_buffer_reqs);
        return CAMERA3_BUF_REQ_FAILED_ILLEGAL_ARGUMENTS;
    }
    return device->RequestStreamBuffers(num_buffer_reqs, buffer_reqs, num_returned_buf_reqs, returned_buf_reqs);
}

static void areturn_stream_buffers(const struct camera3_callback_ops* cb, uint32_t num_buffers,
    const camera3_stream_buffer_t* const* buffers)
{
    Camera3Device* device = const_cast<Camera3Device*>(static_cast<const Camera3Device*>(cb));
    device->ReturnStreamBuffers(num_buffers, buffers);
}

Camera3Device::Camera3Device()
{
    camera3_callback_ops_t::process_capture_result = ::aprocess_capture_result;
    camera3_callback_ops_t::notify = ::anotify;
    camera3_callback_ops_t::request_stream_buffers = ::arequest_stream_buffers;
    camera3_callback_ops_t::return_stream_buffers = ::areturn_stream_buffers;
}

Camera3Device::~Camera3Device() { }

void Camera3Device::Setup()
{
    camera_module.Setup();
}

void Camera3Device::OpenCamera(int cameraId)
{
    hw_device_t* hw_device = nullptr;
    int ret = -1;
    if (nullptr != camera_module.GetCamModule()->common.methods->open) {
        ret = camera_module.GetCamModule()->common.methods->open(
            (const hw_module_t*)camera_module.GetCamModule(), std::to_string(cameraId).c_str(), &hw_device);
    }

    if (0 != ret) {
        LOGE("Can't open camera device %d", cameraId);
    } else if (nullptr != hw_device) {
        camera3_device = (camera3_device_t*)hw_device;
        LOGI("open camera device %d", cameraId);
    }

    if (nullptr != camera3_device->ops->initialize) {
        camera3_device->ops->initialize(camera3_device, this);
    }
}

void Camera3Device::CloseCamera(int cameraId)
{
    if (nullptr != camera3_device->common.close) {
        camera3_device->common.close((hw_device_t*)camera3_device);
        LOGI("close camera device %d", cameraId);
    }
}

void Camera3Device::ProcessCaptureResult(const camera3_capture_result* result) { }

void Camera3Device::sNotify(const camera3_notify_msg* msg) { }

camera3_buffer_request_status_t Camera3Device::RequestStreamBuffers(uint32_t num_buffer_reqs, const camera3_buffer_request_t* buffer_reqs,
    uint32_t* num_returned_buf_reqs, camera3_stream_buffer_ret_t* returned_buf_reqs) { }

void Camera3Device::ReturnStreamBuffers(uint32_t num_buffers, const camera3_stream_buffer_t* const* buffers) { }