#include "module/CameraModule.h"

// export LD_LIBRARY_PATH=/vendor/lib64:/system/lib64:/apex/com.android.vndk.v30/lib64:/apex/com.android.vndk.v31/lib64:/apex/com.android.vndk.v32/lib64:/apex/com.android.vndk.v33/lib64:$LD_LIBRARY_PATH

auto main(int argc, char* argv[]) -> int
{
    CameraModule camera_module;
    camera_module.Setup();

    return 0;
}