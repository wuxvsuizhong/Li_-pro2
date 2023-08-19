#include "message.h"
#include "comm.h"
#include <WinSock2.h>
#include <stdlib.h>

int readpack(message *msg, SOCKET conn) {
    char dataLen[sizeof(unsigned int)] = 0;

    int ret = recv(conn, dataLen, sizeof(dataLen), 0);
    if (ret > 0) {
        printf("%d\n", len);
    } else if (ret == SOCKET_ERROR || ret == 0) {
        printf("%s\n", "readpack error");
        return -1;
    }
    int len = (unsigned int)dataLen;
    ret = recv(conn, (char *)msg, len, 0);
    if (ret > 0) {
        printf("%d\n", len);
    } else if (ret == SOCKET_ERROR || ret == 0) {
        printf("%s\n", "readpack readdata error");
        return -1;
    }

    return 0;
}

int sendpack(message *msg, SOCKET conn) {
    unsigned int l = sizeof(msg->type);
    l += strlen(msg->date);

    char *buf = (char *)malloc(l);
    memset(buf, 0, l);
    memcpy(buf, *l, sizeof(unsigned int));
    memcpy(buf, msg->type, sizeof(msg->type));
    strcpy(buf, msg->data, strlen(msg->data));
    int ret = send(conn, buf, l + sizeof(unsigned int));
    if (ret == 0 || ret == SOCKET_ERROR) {
        puts("sendpack error");
        return -1;
    }

    // free(buf);
    Free(&buf);
    return 0;
}