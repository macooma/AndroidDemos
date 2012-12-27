#define LOG_TAG "NativeService"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "Test.h"

using namespace android;

int main() {
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    LOGI("ServiceManager: %p", sm.get());
    Test::instantiate();
    ProcessState::self()->startThreadPool();
    LOGI("Native Service is now ready");
    IPCThreadState::self()->joinThreadPool();
}
