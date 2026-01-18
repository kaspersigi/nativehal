#include "device/Camera3Device.h"
#include <chrono>
#include <thread>

// export LD_LIBRARY_PATH=/vendor/lib64:/system/lib64:/apex/com.android.vndk.v30/lib64:/apex/com.android.vndk.v31/lib64:/apex/com.android.vndk.v32/lib64:/apex/com.android.vndk.v33/lib64:$LD_LIBRARY_PATH

auto main(int argc, char* argv[]) -> int
{
    Camera3Device camera3_device;
    camera3_device.Setup();
    camera3_device.OpenCamera(0);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    camera3_device.CloseCamera(0);

    return 0;
}