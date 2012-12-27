#ifndef __Test_H__
#define __Test_H__

#include "ITest.h"

namespace android {

class Test : public BnTest {
public:
    Test();
    static void instantiate();
    int getTest();
    void setTest(int val);
    void registerClient(const sp<ITestClient>& client);
private:
    int mVal;
    sp<ITestClient> mClient;
};

};

#endif
