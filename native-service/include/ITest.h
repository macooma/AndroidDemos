#ifndef __ITEST_H__
#define __ITEST_H__

#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include "ITestClient.h"

namespace android {

class ITest : public IInterface {
protected:
    enum {
        GET_test = IBinder::FIRST_CALL_TRANSACTION,
        SET_test,
        REGISTER_CLIENT
    };
public:
    DECLARE_META_INTERFACE(Test);
    virtual int getTest() = 0;
    virtual void setTest(int val) = 0;
    virtual void registerClient(const sp<ITestClient>& client) = 0;
};

class BnTest : public BnInterface<ITest> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

};

#endif
