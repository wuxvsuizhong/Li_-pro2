#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
#define INIT_SIZE 5
#define INFOQUANTITY 7
#define LEN 8

    char ***res = (char ***)malloc(sizeof(char **) * INIT_SIZE);
    for (int i = 0; i < INIT_SIZE; i++) {
        res[i] = (char **)calloc(INFOQUANTITY, sizeof(char *));
        for (int j = 0; j < INFOQUANTITY; j++)
            res[i][j] = (char *)calloc(LEN, sizeof(char));
    }

    // 赋值
    for (int i = 0; i < INIT_SIZE; i++) {
        for (int j = 0; j < INFOQUANTITY; j++)
            strcpy(res[i][j], "world");
    }

    // 打印
    for (int i = 0; i < INIT_SIZE; i++) {
        for (int j = 0; j < INFOQUANTITY; j++)
            printf("%s ", res[i][j]);
        printf("\n");
    }
    // 打印地址
    printf("------------------\n");
    for (int i = 0; i < INIT_SIZE; i++) {
        printf("%p ", res[i]);
        printf("&: %p ", &res[i]);
    }
    printf("\n");

    // expansion
    size_t beforeSize = INIT_SIZE;
    size_t extendSize = INIT_SIZE * 2;
    res = (char ***)realloc(res, sizeof(char **) * extendSize);
    for (int i = beforeSize; i < extendSize; i++) {
        res[i] = (char **)calloc(INFOQUANTITY, sizeof(char *));
        for (int j = 0; j < INFOQUANTITY; j++)
            res[i][j] = (char *)calloc(LEN, sizeof(char));
    }

    // 赋值
    for (int i = 0; i < extendSize; i++) {
        for (int j = 0; j < INFOQUANTITY; j++)
            strcpy(res[i][j], "hello");
    }

    // 打印
    for (int i = 0; i < extendSize; i++) {
        for (int j = 0; j < INFOQUANTITY; j++)
            printf("%s ", res[i][j]);
        printf("\n");
    }

    // 打印地址
    printf("------------------\n");
    for (int i = 0; i < extendSize; i++) {
        printf("%p ", res[i]);
        printf("&: %p ", &res[i]);
    }
    printf("\n");

    // free
    for (int i = 0; i < extendSize; i++) {
        for (int j = 0; j < INFOQUANTITY; j++)
            free(res[i][j]);
        free(res[i]);
    }
    free(res);
    return 0;
}