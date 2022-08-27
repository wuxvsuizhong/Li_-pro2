#include <iostream>
#include "man.h"

using namespace std;

//在类实例传递的过程中会拷贝类数据，此时会调用类的拷贝构函数
//当类成员数据量很大的时候，拷贝构造会导致开销很大，不建议直接传递类实例，而是使用指针或者引用
void func(man m)
{
    cout << "func called" << endl;
    cout << "name " << m.get_name();
    cout << " age: " << m.get_age() << endl;
}



int main()
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
