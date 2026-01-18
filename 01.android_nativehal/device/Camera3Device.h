#pragma once

extern "C" {
#include "../include/camera3.h"
}

class Camera3Device : public camera3_callback_ops_t { };