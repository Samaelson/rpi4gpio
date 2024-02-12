#define LOG_TAG "TEST_Rpi4GPIO_HAL_CB_20"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/poll.h>
#include <sys/signalfd.h>
#include <sys/timerfd.h>
#include <string.h>
#include <log/log.h>
#include "Rpi4gpioCallback.h"

namespace android {
namespace hardware {
namespace rpi4gpio {
namespace V2_0 {
namespace implementation {

// Methods from ::android::hardware::rpi4gpio::V2_0::IRpi4gpioCallback follow.
Return<void> Rpi4gpioCallback::sendEvent(uint32_t event_id) {
    // TODO implement
    ALOGD("Rpi4gpioCallback sendEvent (%d)", event_id);
    return Void();
}

Return<void> Rpi4gpioCallback::sendData(const hidl_vec<uint8_t>& data) {
    // TODO implement
    ALOGD("Rpi4gpioCallback sendData (%x)", (uint32_t)&data);
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IRpi4gpioCallback* HIDL_FETCH_IRpi4gpioCallback(const char* /* name */) {
    //return new Rpi4gpioCallback();
//}
//
}  // namespace implementation
}  // namespace V2_0
}  // namespace rpi4gpio
}  // namespace hardware
}  // namespace android
