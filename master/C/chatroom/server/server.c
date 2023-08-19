#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <string.h>

void process_conn(LPVOID conn);


int initServer() {
    WORD wdversion = MAKEWORD(2, 2);
    WSADATA wdsockmsg;
    int nres = WSAStartup(wdversion, &wdsockmsg);
    if (nres != 0) {
        puts("nres != 0");
        return -1;
    }

    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (slisten == INVALID_SOCKET) {
        puts("socket error!");
        return -1;
    }
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) {
        puts("bind error !");
        return -1;
    }

    if (listen(slisten, 5) == SOCKET_ERROR) {
        puts("listen error");
        return -1;
    }

    struct sockaddr_in remoteaddr;
    int naddrLen = sizeof(remoteaddr);

    while (1) {
        printf("%s\n","等待客户端连接...\n");
        SOCKET sclient =
            accept(slisten, (struct sockaddr *)&remoteaddr, &naddrLen);
        // char buf[8192] = {0};
        if (sclient == INVALID_SOCKET) {
            puts("accept error");
            continue;
        }
        puts("接收到客户端的连接！");

        // process_conn(sclient);
        CreateThread(NULL,0,process_conn,(LPVOID)sclient,0,NULL);
        // closesocket(sclient);

    }
}

void process_conn(LPVOID socketfd) {
    SOCKET conn = (SOCKET)socketfd;
    char buf[8192] = {0};
    while (1) {
        printf("%s","<<");
        int readLen = recv(conn, buf, sizeof(buf), 0);
        if (readLen > 0) {
            buf[readLen] = 0;
            printf("%s\n",buf);
        } else if(readLen == 0 || readLen == SOCKET_ERROR){
            puts("连接断开!");
            closesocket(conn);
            return;
        }

        memset(buf, 0, sizeof(buf));

        char *sendData = "你好，您已登录!";
        send(conn, sendData, strlen(sendData), 0);
    }
}

void main() { initServer(); }
