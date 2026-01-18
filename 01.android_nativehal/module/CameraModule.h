#pragma once

extern "C" {
#include "../include/camera_common.h"
}

class CameraModule : public camera_module_callbacks_t {
public:
    CameraModule();
    ~CameraModule();

    int Setup();

private:
    camera_module_t* camera_module = nullptr;
};