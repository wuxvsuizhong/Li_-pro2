#include "stu.h"
#include <string.h>

//类的静态成员变量的初始化不在构造函数，也不在构造函数的初始化列表中
//类的静态成员变量的初始化需要单独在类的外部进行
int stu::num = 0;
int stu::num2=0;

stu::stu()
{
    this->name = new char[1024]();
}

stu::stu(const char* name,int age)
{
    //this指针
    this->age=age;
    this->name = new char[1024]();
    this->set_name(name);
}

stu::~stu()
{
    delete []this->name;
}

void stu::set_name(const char *name)
{
    strcpy(this->name,name);
}

const char* stu::get_name() const
{
    return this->name;
}

const int stu::get_age()
{
    return this->age;
}

//this指针就是类实例化后的自身的地址
stu* stu::returnthis()
{
    return this;
}

void stu::set_num(int n)
{
    this->num = n;
}

int stu::get_num()
{
    return num;
}

void stu::set_num2(int n)
{
    num2=n;
    //静态类成员函数只能访问类的静态成员变量
//    this->age = 100;
}

int stu::get_num2()
{
    return num2;
}
