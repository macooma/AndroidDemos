#include "ITestClient.h"

namespace android {

class BpTestClient : public BpInterface<ITestClient> {
public:
    BpTestClient(const sp<IBinder>& impl)
        :BpInterface<ITestClient>(impl) {
    }
    
    virtual void notifyCallback(int32_t type) {
        Parcel data, reply;
        data.writeInt32(type);
        remote()->transact(NOTIFY_CALLBACK, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(TestClient, "android.Test.ITestClient");

// ----------------------------------------------------------------------

status_t BnTestClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
    switch(code) {
        case NOTIFY_CALLBACK: {
            notifyCallback(data.readInt32());
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }              
}

};
