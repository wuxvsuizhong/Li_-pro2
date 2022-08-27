#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main1()
{
    cout << "hello world!"<<endl;
    int i=0;
    cin >> i;
    cout << "new line" << '\n';
    cout << "i = " << i << endl;
    return 0;
}

struct man
{
    char name[100];
    int age;
    int gender;
};

int main2()
{
    man m;
    strcpy(m.name,"tom");
    m.age=20;
    m.gender=1;
    cout << m.name << endl;
    return 0;
}

class man2
{
public:
    char name[100];

private:
    int age;

public:
    int gender;
};

int main3()
{
    man m;
    strcpy(m.name,"tom");
    m.gender=1;
    cout << m.name << " " << m.gender << endl;
    return 0;
}

int main4()
{
    volatile int i=0;
    //volatile 关键字是告知编译器不要优化该变量

    //两次连续的加操作，在没有volatile 关键字的时候，编译器可能会对其进行优化为 i += 15
    i += 5;
    i += 10;

    cout << i << endl;

}
