#include "message.h"
#include "cJSON.h"
#include "comm.h"
#include <stdio.h>
#include <stdlib.h>

message *msgJson2Struct(const char *s,) {
    cJSON *root = cJSON_Parse(s);

    cJSON *itemType = cJSON_GetObjectItem(root, "type");
    cJSON *itemData = cJSON_GetObjectItem(root, "data");
    printf("消息类型是：%d\n", itemType->valueint);
    printf("消息内容:%s\n", itemData->valuestring);

    message msg;
    
}

message *readpack(SOCKET conn) {
    unsigned int dataLen = 0;

    int ret = recv(conn, (char *)&dataLen, sizeof(dataLen), 0);
    if (ret > 0) {
        printf("%d\n", ret);
    } else if (ret == SOCKET_ERROR || ret == 0) {
        printf("%s\n", "readpack error");
        return NULL;
    }
    int len = (unsigned int)dataLen;
    char *msgpack = (char *)calloc(sizeof(char), len);
    message *msg=;
    ret = recv(conn, msgpack, len, 0);
    if (ret > 0) {
        printf("%d\n", len);
        // 从接收到的pack中的json格式字符串解析出数据
        msg = msgJson2Struct(msgpack);
        Free(&msgpack);
    } else if (ret == SOCKET_ERROR || ret == 0) {
        printf("%s\n", "readpack readdata error");
        Free(&msgpack);
        return NULL;
    }

    return 0;
}

int sendpack(message *msg, SOCKET conn) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "type", cJSON_CreateNumber(msg->type));
    cJSON_AddItemToObject(root, "data", cJSON_CreateString(msg->data));
    char *msg_str = cJSON_Print(root);
    free(root);

    unsigned int l = strlen(msg_str);
    char *buf = calloc(sizeof(l) + l + sizeof(int), sizeof(char));
    memcpy(buf, &l, sizeof(l));
    strcpy(buf, msg_str);
    free(msg_str);
    int ret = send(conn, buf, l + sizeof(unsigned int), 0);
    if (ret == 0 || ret == SOCKET_ERROR) {
        puts("sendpack error");
        free(buf);
        buf = NULL;
        return -1;
    }

    // free(buf);
    printf("before Free:%p\n", buf);
    Free((void *)&buf);
    printf("after Free:%p\n", buf);

    return 0;
}