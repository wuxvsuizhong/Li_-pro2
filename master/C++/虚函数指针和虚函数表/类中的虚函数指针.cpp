#include <iostream>

using std::cout, std::endl;

class A {
public:
  A();
  void show();
  ~A();
};

A::A() { cout << "A的构造函数!\n"; }
void A::show() { cout << "A的成员函数show()\n"; }
A::~A() { cout << "A的析构函数!\n"; }

class VA {
public:
  VA();
  virtual void show();
  virtual void info();
  ~VA();
};

VA::VA() { cout << "VA的构造函数\n"; }
VA::~VA() { cout << "VA的析构函数\n"; }
void VA::show() { cout << "VA的虚函数show()\n"; }
void VA::info() { cout << "VA的虚函数info()\n"; }

class RA : public VA {
public:
  RA();
  ~RA();
};

RA::RA() { cout << "RA的构造函数\n"; }
RA::~RA() { cout << "RA的析构函数\n"; }

class RA2 : public VA {
public:
  RA2();
  ~RA2();
  void show();
};

RA2::RA2() { cout << "RA2的构造函数\n"; }
RA2::~RA2() { cout << "RA2的析构函数\n"; }
void RA2::show() { cout << "RA2重写父类的show方法\n"; }

/*
class VA2 {
public:
  VA2();
  ~VA2();
  virtual void show();
  virtual void info(); //只要类中存在没有实现的虚函数，那么该类就不能实例化
};


VA2::VA2() {}
VA2::~VA2() {}
void VA2::show() {}
*/

int main(int argc, char const *argv[]) {
  A a;
  A *pa = &a;
  cout << pa << endl;

  RA ra;
  VA *pra = &ra;
  cout << pra << endl;

  RA2 ra2, ra2_2;

  cout << sizeof(a) << endl; // 1
  cout << sizeof(ra)
       << endl; // 8   含有虚函数的类，会多一个虚函数表指针，用于指向虚函数表
  cout << sizeof(ra2)
       << endl; // 8 虚函数表的指针大小是固定的，和虚函数的个数无关
  cout << sizeof(ra2) << endl; // 虚函数表是归属于类的；
  // 每个实例都有一个虚函数表指针，但同一个类的众多实例化对象，都指向同一份类中的虚函数表

  /* 使用gdb调试命令
    p ra 查看ra详情
    info vtbl ra 可以查看ra的虚函数表的详情
   */

  /*
  如下是分别查看ra和ra2以及ra2_2的信息：

(gdb) p ra
$1 = {<VA> = {_vptr.VA = 0x7ff698805620 <vtable for RA+16>}, <No data fields>}
(gdb) info vtbl ra
vtable for 'RA' @ 0x7ff698805620 (subobject @ 0x1ae91ff5d0):
[0]: 0x7ff6988016b0 <VA::show()>
[1]: 0x7ff6988016dc <VA::info()>
(gdb) p ra2
$2 = {<VA> = {_vptr.VA = 0x7ff698805660 <vtable for RA2+16>}, <No data fields>}
(gdb) info vtbl ra2
vtable for 'RA2' @ 0x7ff698805660 (subobject @ 0x1ae91ff5c8):
[0]: 0x7ff698801ac0 <RA2::show()>
[1]: 0x7ff6988016dc <VA::info()>
(gdb) p ra2_2
$3 = {<VA> = {_vptr.VA = 0x7ff698805660 <vtable for RA2+16>}, <No data fields>}
(gdb) info vtbl ra2_2
vtable for 'RA2' @ 0x7ff698805660 (subobject @ 0x1ae91ff5c0):
[0]: 0x7ff698801ac0 <RA2::show()>
[1]: 0x7ff6988016dc <VA::info()>
*/

  /* 从调试输出可以看出，ra2和ra2_2因为都是类RA2的实例化，他们指向的是同一份虚函数表
      而ra和他们不是同一个类，它指向的虚函数表就和RA2的实例不一样；

      但是具体的虚函数表中的指针是指向具体的虚函数的；
      在ra中，因为RA类，没有重新任何父类VA的虚函数。所以ra的虚函数表中具体的每一个函数指针指向的丢失父类VA得我虚函数；
      在ra2和ra2_2中,因为RA2类，重写了父类的其中一个虚函数show(),所以他们的虚函数表中的对应show的函数指针就是指向RA2类自己的函数，
      而另外一个函数info在RA2中没有重新，所以指向还是父类VA的show()
      可以得出以下结论：
      1. 虚函数表附属于类，同一个类的众多实例共享一份类的虚函数表；
      2.
     类中的虚函数表中的一个函数指针，指向的是具体的虚函数；虚函数表是被子类所继承的
      3.
     只要子类没有重新定义父类的某个或者某些虚函数。那么子类的虚函数表中，会沿用从父类继承过来的这些虚函数
      4.
     只要子类重新定义了的虚函数，那么在子类的虚函数表中，就会使用自己新定义的函数；
  */

//  VA2 va2;

  cout << "\n--------main end---------\n";
  return 0;
}
