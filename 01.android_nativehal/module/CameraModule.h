#pragma once

extern "C" {
#include "../include/camera_common.h"
}

class CameraModule : public camera_module_callbacks_t {
public:
    CameraModule();
    ~CameraModule();

    int Setup();
    const camera_module_t* GetCamModule() const;

private:
    void* camera_handle = nullptr;
    camera_module_t* camera_module = nullptr;
    vendor_tag_ops_t vendor_tag_ops;
    int number_of_cameras = -1;
};