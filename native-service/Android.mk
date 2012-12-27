LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= Test.cpp ITest.cpp

LOCAL_MODULE:= libnativeservice

LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES += \
		libbinder \
        libutils
                
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_SRC_FILES:= test_main.cpp

LOCAL_MODULE:= nativeservice

LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES += \
		libbinder \
        libutils \
        libnativeservice
                
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SRC_FILES:= testclient_main.cpp

LOCAL_MODULE:= nativeservice-client

LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES += \
		libbinder \
		libutils \
        libnativeservice
                
include $(BUILD_EXECUTABLE)
