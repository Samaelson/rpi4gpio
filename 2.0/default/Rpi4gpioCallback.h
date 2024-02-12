#ifndef ANDROID_HARDWARE_Rpi4GPIO_V2_0_Rpi4GPIOCALLBACK_H
#define ANDROID_HARDWARE_Rpi4GPIO_V2_0_Rpi4GPIOCALLBACK_H

#include <android/hardware/rpi4gpio/2.0/IRpi4gpioCallback.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace rpi4gpio {
namespace V2_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Rpi4gpioCallback : public IRpi4gpioCallback {
    // Methods from ::android::hardware::rpi4gpio::V2_0::IRpi4gpioCallback follow.
    Return<void> sendEvent(uint32_t event_id) override;
    Return<void> sendData(const hidl_vec<uint8_t>& data) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IRpi4gpioCallback* HIDL_FETCH_IRpi4gpioCallback(const char* name);

}  // namespace implementation
}  // namespace V2_0
}  // namespace rpi4gpio
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_Rpi4GPIO_V2_0_Rpi4GPIOCALLBACK_H
