#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <WinSock2.h>

typedef struct message {
    int type;
    char *data;
} message;

enum msgType {
    loginMsgType,
    loginResType,
    registerType,
    registerResType,
};

typedef struct logininfo {
    unsigned int id;
    char name[1024];
    char passwd[2018];
} loginInfo;

message readpack(SOCKET conn);
int sendpack(message *msg, SOCKET conn);

#endif