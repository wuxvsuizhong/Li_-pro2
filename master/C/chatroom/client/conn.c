#include "conn.h"
#include <WinSock2.h>
#include <cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login() {
    WORD wdversion = MAKEWORD(2, 2);
    WSADATA wdsockmsg;
    int nres = WSAStartup(wdversion, &wdsockmsg);
    if (nres != 0) {
        puts("nres != 0\n");
        return -1;
    }

    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sclient == INVALID_SOCKET) {
        puts("socket error!\n");
        return -1;
    }
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (connect(sclient, (struct sockaddr *)&sin, sizeof(sin)) ==
        SOCKET_ERROR) {
        puts("connect error\n");
        closesocket(sclient);
        return -1;
    }

    char recvBuf[8192] = {0};
    // char msgBuf[8192] = {0};
    char *msgBuf;

    while (1) {
        message msg = getInputMsg();
        // send(sclient, msgBuf, strlen(msgBuf), 0);
        sendpack(&msg, sclient);
        printf("msg.data before Free:%p\n", msg.data);
        Free((void *)&msg.data);
        printf("msg.data after Free:%p\n", msg.data);

        int recvLen = recv(sclient, recvBuf, sizeof(recvBuf), 0);
        if (recvLen > 0) {
            recvBuf[recvLen] = 0;
            printf("%s\n", recvBuf);
            memset(recvBuf, 0, sizeof(recvBuf));
        } else if (recvLen == 0 || recvLen == SOCKET_ERROR) {
            closesocket(sclient);
            return;
        }
    }
}

int getLoginInfo(loginInfo *info) {
    // malloc()

    memset(info, 0, sizeof(loginInfo));
    printf("%s", "请输入ID:");
    scanf("%s", &(info->id));
    printf("%s", "请输入账户名:");
    scanf("%s", info->name);
    printf("%s", "请输入密码");
    scanf("%s", info->passwd);

    return 0;
}

message getInputMsg() {
    loginInfo info;
    getLoginInfo(&info);

    cJSON *root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "id", cJSON_CreateNumber(info.id));
    cJSON_AddItemToObject(root, "name", cJSON_CreateString(info.name));
    cJSON_AddItemToObject(root, "passwd", cJSON_CreateString(info.passwd));
    // json转换为字符串，注意在函数内部会new出字符串空间记得及时释放
    char *json_str = cJSON_Print(root);
    printf("%s\n", json_str);
    cJSON_Delete(root);
    size_t l = strlen(json_str);
    printf("strlen json_str:%d\n", l);

    message msg;
    msg.type = loginMsgType;
    msg.data = json_str;

    // strcpy(msgbuf, json_str);
    // Free(json_str);
    return msg;
}