#ifndef __ITEST_H__
#define __ITEST_H__

#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class ITest : public IInterface {
protected:
    enum {
        GET_test = IBinder::FIRST_CALL_TRANSACTION,
        SET_test
    };
public:
    DECLARE_META_INTERFACE(Test);
    virtual int getTest() = 0;
    virtual void setTest(int val) = 0;
};

class BnTest : public BnInterface<ITest> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

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
};

};

#endif
