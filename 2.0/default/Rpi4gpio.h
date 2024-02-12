#ifndef ANDROID_HARDWARE_RPI4GPIO_V2_0_Rpi4GPIO_H
#define ANDROID_HARDWARE_RPI4GPIO_V2_0_Rpi4GPIO_H

#include <android/hardware/rpi4gpio/2.0/IRpi4gpio.h>
#include <android/hardware/rpi4gpio/2.0/IRpi4gpioCallback.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <log/log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "TEST_Rpi4GPIO_HAL_20"
#define UEVENT_MSG_LEN 2048

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
using ::android::hardware::rpi4gpio::V2_0::IRpi4gpioCallback;
using ::android::hardware::rpi4gpio::V2_0::LedStatus;

struct Rpi4gpio : public IRpi4gpio {

    public:
        Rpi4gpio();  // Add manually
        ~Rpi4gpio();  // Add manually
        // Methods from ::android::hardware::rpi4gpio::V2_0::IRpi4gpio follow.
        Return<LedStatus> get() override;
        Return<int32_t> set(LedStatus val) override;
        Return<void> on() override;
        Return<void> off() override;
        Return<void> registerCallback(const sp<IRpi4gpioCallback>& cb) override;

    	sp<IRpi4gpioCallback> mCallback;
        pthread_mutex_t mutexSW = PTHREAD_MUTEX_INITIALIZER;
        pthread_cond_t conditionSW;
    // Methods from ::android::hidl::base::V1_0::IBase follow.
    private:
        LedStatus state;
        int valid;

        pthread_t mPoll;
        pthread_mutex_t mLock = PTHREAD_MUTEX_INITIALIZER;

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IRpi4gpio* HIDL_FETCH_IRpi4gpio(const char* name);

}  // namespace implementation
}  // namespace V2_0
}  // namespace rpi4gpio
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_Rpi4GPIO_V2_0_Rpi4GPIO_H
