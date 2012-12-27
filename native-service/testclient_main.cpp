#include <binder/IServiceManager.h>
#include <stdio.h>
#include "Test.h"
#include "TestClient.h"

namespace android {

void TestClient::notifyCallback(int32_t type) {
    printf("recieve call back %d\n", (int)type);
}

};

using namespace android;

int main() {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("native.service"));
    sp<ITest> testService = interface_cast<ITest>(binder);
    printf("old value is %d\n", testService->getTest());
    testService->setTest(10);
    printf("new value is %d\n", testService->getTest());
    sp<TestClient> client = new TestClient();
    testService->registerClient(client);
}
