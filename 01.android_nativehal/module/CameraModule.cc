#include "CameraModule.h"
#include "../include/log.h"

extern "C" {
#include <dlfcn.h>
}

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "CAMERA_MODULE"

static void camera_device_status_change(
    const struct camera_module_callbacks* callbacks,
    int camera_id,
    int new_status)
{
}

static void torch_mode_status_change(
    const struct camera_module_callbacks* callbacks,
    const char* camera_id,
    int new_status)
{
}

CameraModule::CameraModule()
{
    this->camera_device_status_change = ::camera_device_status_change;
    this->torch_mode_status_change = ::torch_mode_status_change;
}

// 定义 HAL 库导出符号的名称，标准规定就是 "HMI"
constexpr char HAL_MODULE_INFO[] = "HMI";

// Qcom HAL 库路径
constexpr char HAL_DRIVER_PATH[] = "/vendor/lib64/hw/camera.qcom.so";

CameraModule::~CameraModule()
{
    if (nullptr != camera_handle) {
        dlclose(camera_handle);
        camera_handle = nullptr;
    }
}

int CameraModule::Setup()
{
    void* handle = dlopen(HAL_DRIVER_PATH, RTLD_NOW);
    if (!handle) {
        LOGE("dlopen %s failed!", HAL_DRIVER_PATH);
        return -1;
    }
    camera_handle = handle;

    camera_module_t* module = (camera_module_t*)dlsym(handle, HAL_MODULE_INFO);
    if (!module) {
        LOGE("dlsym %s failed!", HAL_MODULE_INFO);
        return -1;
    }
    camera_module = module;

    if (nullptr != camera_module->get_vendor_tag_ops) {
        camera_module->get_vendor_tag_ops(&vendor_tag_ops);
    }

    if (nullptr != camera_module->init) {
        camera_module->init();
    }

    int number = -1;
    if (nullptr != camera_module->get_number_of_cameras) {
        number = camera_module->get_number_of_cameras();
    }
    if (-1 >= number) {
        LOGE("get_number_of_cameras failed!");
        return -1;
    } else {
        number_of_cameras = number;
        LOGI("number_of_cameras: %d", number_of_cameras);
    }

    return 0;
}