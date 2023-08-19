#include "conn.h"

#include "message.h"
#include <WinSock2.h>
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
    char msgBuf[8192] = {0};
    while (1) {
        getInputMsg(msgBuf, sizeof(msgBuf));
        send(sclient, msgBuf, strlen(msgBuf), 0);
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

size_t getLoginInfo(loginInfo *info) {
    malloc()


    info->name = char mname[1024] = {0};
    info->passwd = char mpasswd[2018] = {0};

    printf("%s", "请输入ID:");
    scanf("%s", &(info->id));
    printf("%s", "请输入账户名:");
    scanf("%s", info->name);
    printf("%s", "请输入密码");
    scanf("%s", info->passwd);

    size_t l = sizeof(info->id);
    l += strlen(info->name);
    l += strlen(info->passwd);

    return l;
}

void getInputMsg(char *msgbuf, int len) {
    memset(msgbuf, 0, len);
    // printf(">>");
    // scanf("%s", msgbuf);
}