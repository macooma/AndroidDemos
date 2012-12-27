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
private:
    int mVal;
};

};

#endif
