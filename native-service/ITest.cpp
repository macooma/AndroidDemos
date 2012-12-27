#include <binder/IInterface.h>
#include "ITest.h"

namespace android {

class BpTest : public BpInterface<ITest> {
public:
    BpTest(const sp<IBinder>& impl)
        :BpInterface<ITest>(impl) {
    }
    
    virtual int getTest() {
        Parcel data, reply;
        remote()->transact(GET_test, data, &reply);
        return reply.readInt32();
    }
    
    virtual void setTest(int val) {
        Parcel data, reply;
        data.writeInt32((int32_t)val);
        remote()->transact(SET_test, data, &reply);
    }
    
    virtual void registerClient(const sp<ITestClient>& client) {
        Parcel data, reply;
        data.writeStrongBinder(client->asBinder());
        remote()->transact(REGISTER_CLIENT, data, &reply);
    }
};

// BnTest
// BnTest是一个虚类，它继承了ITest，但是没有实现getTest和setTest，需要它的子类来实现，而Test类就是它的子类
IMPLEMENT_META_INTERFACE(Test, "android.Test.ITest");

// ----------------------------------------------------------------------

status_t BnTest::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case GET_test: {
            //CHECK_INTERFACE(ITest, data, reply);
            reply->writeInt32((int32_t)getTest());
            return NO_ERROR;
        } break;
        case SET_test: {
            //CHECK_INTERFACE(ITest, data, reply);
            setTest(data.readInt32());
            return NO_ERROR;
        } break;
        case REGISTER_CLIENT: {
            sp<ITestClient> client = interface_cast<ITestClient>(data.readStrongBinder());
            registerClient(client);
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

};
