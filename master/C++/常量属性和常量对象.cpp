#include <iostream>
using namespace std;

class A {
  private:
    const int a;    //同const修饰的类成员数据，即使类的常量类成员
    int b;

  public:
    A();
    ~A();

    void setB(int n);
    void getA() const;
    void getB() const { cout << "b:" << b << endl; }
};

A::A() : a(100), b(11) {
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

A::~A() {}

void A::setB(int n) {   //如果是要在成员函数中修改类成员变量，就不能加后置const修饰
    b = n;
    return;
}

void A::getA() const {  //类成员函数使用了后置const修饰就不能再函数中修改数据
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

int main(int argc, char *argv[]) {
    A a;

    const A aa;
    // aa.setB(111);
    aa.getA();
    aa.getB();
    return 0;
}
