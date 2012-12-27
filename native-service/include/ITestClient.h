#ifndef __ITESTCLIENT_H__
#define __ITESTCLIENT_H__

#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {
class ITestClient : public IInterface {
protected:
    enum {
        NOTIFY_CALLBACK = IBinder::FIRST_CALL_TRANSACTION
    };
public:
    DECLARE_META_INTERFACE(TestClient);    
    virtual void notifyCallback(int32_t type) = 0;
};

class BnTestClient : public BnInterface<ITestClient> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

};

#endif
