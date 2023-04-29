#include <iostream>
#include <stdio.h>
#include "man.h"
#include "stu.h"

using namespace std;

//在类实例传递的过程中会拷贝类数据，此时会调用类的拷贝构函数
//当类成员数据量很大的时候，拷贝构造会导致开销很大，不建议直接传递类实例，而是使用指针或者引用
void func(man m)
{
    cout << "func called" << endl;
    cout << "name " << m.get_name();
    cout << " age: " << m.get_age() << endl;
}



int main1()
{
    man m("zhangsan");
    cout << m.get_name() << endl;

    man m2=m;
    cout << m2.get_name() <<endl;
    m2.set_name("lisi");
    cout << m2.get_name() << endl;

    func(m2);  //传递类实例，会调用类的拷贝构造函数

    //explicit 关键字的作用,禁止=操作符去调用重载的构造函数
//    man m3 = 20;
    man m3(20);
    cout << m3.get_age() << endl;

    return 0;
}

//普通的静态变量
void test()
{
    //i 因为是静态变量，其存在与静态区，静态变量只会初始化1次
    //静态变量在程序加载后就一直存在，直到程序退出后才清理
    //j 普通变量，存在于栈中，每次函数被调用都会在栈中初始化
    static int i=0;
    int j=0;
    i++;
    j++;
    cout << "i,j=" << i << "," << j << endl;
}


int main()
{
    stu s("zhangsan",20);
    cout<< " name:" << s.get_name()<< "age:" <<s.get_age() <<endl;
    printf("&s:%p\n",&s);
    printf("s->this:%p\n",s.returnthis());  //this指针的值和取s的地址的一样，说明this指针和就是类实例化后的地址

    for(int i=0;i<10;i++){
        test();
    }
    //在s实例中修改类静态成员变量num的值为100
    s.set_num(100);

    stu s1("lisu",22);
    //在s1实例中访问类静态成员变量的值是在s实例修改后的值了
    //说明类的静态成员变量和类实例没有关系
    cout << "num:" << s1.get_num() << endl;

    //访问类静态成员甚至可以不实例化任何类对象，直接用类名访问，stu::num,但是前提是变量是public的
    //不论类的实例有多少个，类的静态成员变量都只有一份

    s1.set_num2(33);
    cout << "num2:" << s1.get_num2() << endl;

    //静态 类成员函数可以直接使用类名进行访问
    stu::set_num2(44);
    cout<< " name:" << stu::get_num2()<<endl;

}
