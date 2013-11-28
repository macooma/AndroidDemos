AndroidDemos
============

Collected Android application Demos

native-service
native-service是一个android本地服务的实现，其中实现了三个具有代表性的方法：setTest,getTest和registerClient。registerClient
可以传递给服务端一个接口，服务器跨进程回调接口提供的方法。

使用方法：
分别编译动态库libnativeservice.so，可执行文件nativeservice和nativeservice-client
adb push libnativeservice.so /system/lib
adb push nativeservice /system/bin
adb push nativeservice-client /system/bin

nativeservice将把libnativeservice库中定义的service native.service添加到servicemanager，
nativeservice-client将从servicemanager中取出service进行调用。

master commit 1
master commit 2
master commit 3
Dev branch add
master commit 4
commit 1
commit 2
dev commit 1
dev commit 2
master commit 5 
