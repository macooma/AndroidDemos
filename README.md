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

AndroidDemos network graph 图解释
---------------------------------
1. 创建master分支，并进行6次提交。

2. 创建dev及dev2分支。

3. dev执行一次提交后，merge入master分支，然后再执行两次提交后，merge入master分支，删除dev分支。

4. dev2执行两次提交后，merge入master分支，删除dev2分支。

5. dev dev2分支操作过程中，master分支有若干次提交。
