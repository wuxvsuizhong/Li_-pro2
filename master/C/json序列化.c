#include <cJSON.h>
#include <stdio.h>
#include <stdlib.h>

/* 定义一个结构体类型 */
typedef struct Person {
    char *name;
    int age;
    float height;
} Person;
/* 将结构体类型转换为JSON格式 */
char *json_serialize_person(Person *p) {
    cJSON *root = cJSON_CreateObject(); /* 创建JSON对象 */
    cJSON_AddItemToObject(root, "name",
                          cJSON_CreateString(p->name)); /* 添加字段name */
    cJSON_AddItemToObject(root, "age",
                          cJSON_CreateNumber(p->age)); /* 添加字段age */
    cJSON_AddItemToObject(root, "height",
                          cJSON_CreateNumber(p->height)); /* 添加字段height */
    char *json_str = cJSON_Print(root); /* 将JSON对象转换为字符串 */
    cJSON_Delete(root);                 /* 释放JSON对象所占的内存 */
    return json_str;                    /* 返回JSON格式的字符串 */
}

// json格式的字符串解析为struct
void json2struct() {
    char *data = "{\"name\":\"张三\",\"age\":30,\"height\":180.00}";
    cJSON *root = cJSON_Parse(data);

    Person p;

    // 从jcon数据中获取键值
    cJSON *itemName = cJSON_GetObjectItem(root, "name");
    printf("itemName:%s\n", itemName->valuestring);
    cJSON *itemAge = cJSON_GetObjectItem(root, "age");
    printf("itemAge:%d\n", itemAge->valueint);
    cJSON *itemHeight = cJSON_GetObjectItem(root, "height");
    printf("itemHeight:%.2f\n", itemHeight->valuedouble);
    p.age = itemAge->valueint;
    p.name = itemName->valuestring;
    p.height = itemHeight->valuedouble;

    cJSON_free(root);
}

void main() {
    /* 定义一个Person结构体数据 */
    Person p = {"张三", 18, 1.75};
    /* 将结构体数据序列化为JSON格式的字符串 */
    char *json_str = json_serialize_person(&p);
    /* 打印JSON格式的字符串 */
    printf("Person JSON: %s\n", json_str);
    /* 释放JSON格式的字符串所占的内存 */
    free(json_str);

    //
    json2struct();
}