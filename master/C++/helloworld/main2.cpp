#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main()
{
//============ C风格 ==========
    int *p=(int *)malloc(sizeof(int));
    *p = 100;
    printf("%d\n",*p);
//    cout << *p <<endl;
    free(p);

//============= C++ 风格 =================
    int *p2 = new int(10);  //new的同时给其赋值
    cout << *p2 << endl;
    delete p2;

    //new 分配的内存只能用delete 释放，不能用其他的操作如delete 去释放
//    ---------------------
    int *p3 = new int[5];
    for(int i=0;i<5;i++){
        p3[i] = i;
    }


    for(int i=0;i<5;i++){
        printf("%d\n",p3[i]);
    }
//    delete p3;
//如果new的是一个数组 int[n],那么释放的时候需要带上[]p,只有delete p就只会释放数组的第一个元素，会导致内存泄漏
    delete []p3;

    return 0;
}
