#include <stdio.h>
#include "TestClient.h"
namespace android {

void TestClient::notifyCallback(int32_t type) {
    printf("recieve call back %d\n", (int)type);
}

};

