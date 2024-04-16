#include <iostream>
using namespace std;

class A {
  private:
    /* data */

  public:
    char ch;
    A(const char &ch);
    // A(const A &f);
    ~A();
};

A::A(const char &ch) : ch(ch) { cout << "A 构造函数被调用" << ch << endl; }
// A::A(const A &f) : ch(f.ch) { cout << "A 拷贝构造函数被调用" << ch << endl; }
A::~A() { cout << "A 析构函数被调用" << ch << endl; }

class B : public A {
  public:
    B(const char &ch);
    // B(const B &b);
    ~B();
};

B::B(const char &ch) : A(ch) { cout << "B 构造函数被调用" << ch << endl; }
// B::B(const B &b) { cout << "B 拷贝构造函数被调用" << endl; }
B::~B() { cout << "B 析构函数被调用" << ch << endl; }

int main(int argc, char const *argv[]) {
    {
        B *b = new B('b');
        delete b;
    }
    cout << "in main1" << endl;
    // 输出如下：
    // A 构造函数被调用b
    // B 构造函数被调用b
    // B 析构函数被调用b
    // A 析构函数被调用b
    // in main1
    // 总结:在new创建对象的时候，会先调用父类的构造函数，在调用子类的构造函数
    // 在delete 析构的时候，会先调用子类的析构函数，然后调用父类的析构函数
    {
        B β = B('B');
        // 这里没有使用new,是创建在栈空间上的
    }
    cout << "in main2" << endl;

    // 输出
    // A 构造函数被调用B
    // B 构造函数被调用B
    // B 析构函数被调用B
    // A 析构函数被调用B
    // B 析构函数被调用B
    // A 析构函数被调用B
    // in main2

    // 这里析构函数和构造函数不成对3出现的原因是，在栈上使用了=,是会调用拷贝构造函数的
    //  但是在自定义类的时候，如果没有定义拷贝构造函数，那么编译器会自动生成一个拷贝构造函数
    //  拷贝构造函数会创建一个临时对象temp，然后把temp赋给目标值，再销毁temp.
    //  于是在创建temp的时候，因为没有自定义拷贝构造函数，就会调用默认的拷贝构造函数，但是默认的拷贝构造函数是不打印任何信息的
    //  而相应的因为多了一个同类型的temp临时对象，所以在销毁时也会多调用一次析构函数。
    //  所以，其实构造和销毁是成对出现的，只是因为拷贝构造调用的是默认的，所以少了一次输出而已
    return 0;
}
