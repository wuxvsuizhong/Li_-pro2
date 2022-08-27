#include <stdio.h>
#include <iostream>

using namespace std;

/******************
1. c++函数模板
*******************/

template <class T>
T myadd(T a,T b)
{
    return a + b;
}


int main5()
{
    int n1 = 10;
    int n2 = 100;
    printf("%d\n",myadd(n1,n2));

    double d1 = 20.5;
    double d2 = 10.1;
    printf("%.2f\n",myadd(d1,d2));

}

/******************
2. c++函数模板重载
函数模板的形参个数不同，可以重载
函数模板可以设置缺省参数
*******************/

template <class T>
T myadd(T n)
{
    return n;
}

int main6()
{
    int n1 = 10;
    int n2 = 100;
    printf("%d\n",myadd(n1,n2));

    cout << myadd("hello boy!") << endl;

    return 0;
}

