#include "man.h"
#include <iostream>
#include <string.h>

using namespace std;


//在构造函数之后加:gender(1) 形如’:成员变量(值)’ 叫做初始化成员列表
//类成员变量是const修饰的时候，必须使用初始化成员列表来初始化
classman::classman():gender(1)
{
    cout << "classman init..." << endl;
    age = 0;
    memset(name,0,sizeof(name));
    isworker=false;

//    gender=0;
    //const修饰的成员变量不能在构造函数或者其他函数中修改或者设置初始值，必须要在构造函数定义处进行初始化成员列表

    info = new char[1000]();   //加上()使其在new的同时进行空间初始化为0
    //    一定要在析构函数中释放new出来的空间，否则会有内存泄漏
}

//构造函数可以通过形参重载
classman::classman(const char *namestr,bool iworker):gender(1)
{
    strcpy(name,namestr);
    info = new char[1000]();
    //    一定要在析构函数中释放new出来的空间，否则会有内存泄漏

    strcpy(info,"there some extral info!");
}

classman::~classman()
{
    cout << "~classman...";
    if(!strcmp(name,""))
        cout << "i have no name,";
    else
        cout << "my name is " << name;

    if(isworker)
        cout << " I'm a worker" << endl;
    else
        cout << " i'm not a worker" << endl;

//    一定要在析构函数中释放new出来的空间，否则会有内存泄漏
    delete []info;
}

void classman::set_name(const char *namestr)
{
    strcpy(name,namestr);
}

void classman::set_age(int n)
{
    age = n;
}

const char* classman::get_name()
{
    return (const char*)name;
}

const int classman::get_age()
{
    return (const int)age;
}

char* classman::get_info()
{
    return info;
}
