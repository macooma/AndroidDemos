#define LOG_TAG "TestService"

#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <string.h>
#include "Test.h"

namespace android {

// class Test
Test::Test()
    :mVal(0){
}

void Test::instantiate() {
    defaultServiceManager()->addService(String16("native.service"), new Test());
    LOGI("native.service is added to servicemanager");
}

int Test::getTest() {
    LOGI("getTest %d\n", mVal);
    return mVal;
}
    
void Test::setTest(int val) {
    mVal = val;
    LOGI("setTest %d\n", mVal);
}

};
