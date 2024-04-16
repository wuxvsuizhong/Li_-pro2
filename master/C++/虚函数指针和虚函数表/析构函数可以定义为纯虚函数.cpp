// 类的析构函数可以被定义为虚函数，但是这样会占据内存，一般我们不把类的析构函数定义为纯虚函数
// 但是如果作为虚基类的话，为了能够让基类的指针指向子类new出的对象时，在析构时也能够调用子类的析构函数，
// 最好是把虚基类的析构函数申明为虚函数

#include <iostream>

using std::cout, std::endl;
class VA {
public:
  VA() { cout << "VA的构造函数!\n"; }
  virtual ~VA() { cout << "VA的析构函数\n"; }
};

class RA : public VA {
public:
  RA() { cout << "RA的构造函数\n"; }
  ~RA() { cout << "RA的析构函数\n"; }
};

class A {
public:
  A() { cout << "A的构造函数\n"; }
  ~A() { cout << "A的析构函数\n"; }
};

class B : public A {
public:
  B() { cout << "B的构造函数\n"; };
  ~B() { cout << "B的析构函数\n"; };
};

int main(int argc, char const *argv[]) {

  VA *p = new RA();
  A *pa = new B();

  delete p; // RA继承自VA,父类VA的析构函数是虚函数，虽然使用父类的指针指向子类new出的对象，但是析构时会自动调用子类的析构函数
  delete pa; // 这里普通类B继承自普通类A,
  // pa是使用的父类A的类型指针指向子类的new出的对象，析构时不会调用子列的析构函数，只会调用父类A的

  // B *ptra = (B *)pa;
  // delete ptra; // 普通类经过类型转换后，可以正常调用子列的析构函数
  // return 0;
}

/* 总结：如果基类中是含有virtual函数的虚基类，尽量把基类的析构函数也声明为虚函数，
这样可以避免当父类对象指向new出的子类时，在析构中不调用子类的析构函数的情况出现
*/
