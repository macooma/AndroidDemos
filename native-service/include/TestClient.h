#ifndef __TESTCLIENT_H__
#define __TESTCLIENT_H__

#include "ITestClient.h"

namespace android {

class TestClient : public BnTestClient {
public:
    void notifyCallback(int32_t type);
};

};


#endif
