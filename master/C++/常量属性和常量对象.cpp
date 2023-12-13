#include <iostream>
using namespace std;

class A {
  private:
    const int a;
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

void A::setB(int n) {
    b = n;
    return;
}

void A::getA() const {
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
