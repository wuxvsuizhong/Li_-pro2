#ifndef _MESSAGE_H
#define _MESSAGE_H

typedef struct {
    int type;
    char *data;
} message;

enum msgType {
    loginMsgType,
    loginResType,
    registerType,
    registerResType,
};

typedef struct {
    unsigned int id;
    char *name;
    char *passwd;
} loginInfo;

#endif