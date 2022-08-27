#include <iostream>
#include <string.h>

using namespace std;

int age=0;

void outfunc()
{
    cout << "i'm global function!" << endl;
}


class man
{
private:
    char name[100];
    int age;

public:
    void set_name(const char* namestr)
    {
        memset(name,0,sizeof(name));
        if(strcmp(namestr,"tom") == 0){
            return;
        }
        strcpy(name,namestr);
    }

    void set_age(int n)
    {
        age = n;
    }

    int get_age()
    {
        return age;
    }

    const char* get_name()
    {
        return name;
    }

    int get_out_age()
    {
        //在类的要访问外部的全局变量或者函数等需要在标识前加上::
        ::age += 50;
        cout << "age in out: " << ::age << endl;
    }

    void visit_outfunc()
    {
        //在类的要访问外部的全局变量或者函数等需要在标识前加上::
        ::outfunc();
    }
};

int main1()
{
    man m;
    m.set_name("tom");
    cout << "name: " << m.get_name() <<endl;
    m.set_name("zhangsan");
    cout << "name: " << m.get_name() << endl;

    m.set_age(30);
    cout << "age: " << m.get_age() <<endl;

    m.get_out_age();
    m.visit_outfunc();

    cout << sizeof(m) << endl;  //104
    cout << sizeof(man) << endl;    //104
    /*
     * 类的大小其实就是类的成员变量所占用的空间的和
     * 从类的大小尺寸维度来说，类成员函数是没有占用空间大小一说的；
     * 类的本质就是数据成员加可执行代码，统一提供封装，继承，多态；
     */

    return 0;
}
