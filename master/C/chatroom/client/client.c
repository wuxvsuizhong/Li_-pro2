#include "conn.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void main() {
    int choice = 0;
    bool keeploop = true;
    while (keeploop) {
        puts("--------------------欢迎登录多用户聊天室--------------------");
        puts("--------------------1.用  户  登  录--------------------");
        puts("--------------------2.用  户  注  册--------------------");
        puts("--------------------3.退          出--------------------");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            puts("用户登录");
            login();
            break;
        case 2:
            puts("用户注册");
            break;
        case 3:
            puts("退出!");
            keeploop = false;
            break;
        default:
            puts("非法输入,请重试!");
            break;
        }
    }
}
