#define LOG_TAG "TestService"

#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <string.h>
#include "Test.h"

namespace android {

// class Test
Test::Test()
    :mVal(0), mClient(NULL){
}

void Test::instantiate() {
    defaultServiceManager()->addService(String16("native.service"), new Test());
    LOGI("native.service is added to servicemanager");
}

int Test::getTest() {
    LOGI("%s", __func__);
    LOGI("getTest %d\n", mVal);
    return mVal;
}
    
void Test::setTest(int val) {
    LOGI("%s", __func__);
    mVal = val;
    LOGI("setTest %d\n", mVal);
}

void Test::registerClient(const sp<ITestClient>& client) {
    LOGI("%s", __func__);
    mClient = client;
    mClient->notifyCallback(1);
    LOGI("notify 1");
}

};
