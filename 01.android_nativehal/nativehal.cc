#include "device/Camera3Device.h"
#include <chrono>
#include <thread>

// mv /system/bin/cameraserver /system/bin/cameraserver.bak
// mv /vendor/bin/hw/vendor.qti.camera.provider@2.7-service_64 /vendor/bin/hw/vendor.qti.camera.provider@2.7-service_64.bak
// stop cameraserver
// pkill -f camera*

// adb push /mnt/develop/android-ndk-r27d/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/lib/aarch64-linux-android/libc++_shared.so /data/local/tmp/
// export LD_LIBRARY_PATH=/system/lib64:.:/vendor/lib64:/apex/com.android.vndk.v30/lib64:/apex/com.android.vndk.v31/lib64:/apex/com.android.vndk.v32/lib64:/apex/com.android.vndk.v33/lib64
// ./nativehal

auto main(int argc, char* argv[]) -> int
{
    Camera3Device camera3_device;
    camera3_device.Setup();
    camera3_device.OpenCamera(0);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    camera3_device.CloseCamera(0);

    return 0;
}