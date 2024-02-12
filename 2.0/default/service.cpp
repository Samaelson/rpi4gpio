#define LOG_TAG "android.hardware.rpi4gpio@2.0-service"
 
#include <android/hardware/rpi4gpio/2.0/IRpi4gpio.h>
#include <hidl/LegacySupport.h>
#include "Rpi4gpio.h"
using android::hardware::rpi4gpio::V2_0::IRpi4gpio;
using android::hardware::rpi4gpio::V2_0::implementation::Rpi4gpio;
using android::hardware::defaultPassthroughServiceImplementation;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;
 
 
int main() {
// Binder approach
  sp<IRpi4gpio> service = new Rpi4gpio();
  configureRpcThreadpool(3, true /*callerWillJoin*/);
    if(android::OK !=  service->registerAsService())
      return 1; 
    joinRpcThreadpool();
}
