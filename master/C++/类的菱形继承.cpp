// 菱形继承是值，在一开始有某个基类A，被超过1个的子类B,C继承,后续又有新的子类同时继承了B,C
// 整体的继承关系结构像一个菱形，结构如下
/*
    A
  /   \
 B     C
  \   /
    D
 */

// 存在的问题：因为B,A都有A的数据成员，这会导致D在访问父类时不知道访问哪一边的问题
#include <iostream>

using std::cout, std::endl;

class A {
public:
  int num = 0;

  A(int n) : num(n) {}
  A() {
  } // 如果是带哟初始化参数列表的情况，在菱形继承中，需要原始的基类有不带参的构造函数
  ~A(){};
};

class B : public A {
public:
  B(int n) : A(n){};
  ~B(){};
};
class C : public A {
public:
  C(int n) : A(n){};
  ~C(){};
};

// D同时继承B,C
class D : public B, public C {
public:
  D(int n) : B(n), C(n){};
  ~D(){};
};

// 如果多继承的时候，统计父类之间有共同的祖先，那么使用虚继承
class B1 : virtual public A {
public:
  B1(int n) : A(n) {}
  ~B1(){};
};

class C1 : virtual public A {
public:
  C1(int n) : A(n) {}
  ~C1(){};
};

class D1 : public C1, public B1 {
public:
  D1(int n) : C1(n), B1(n){};
  ~D1(){};
};

int main(int argc, char const *argv[]) {
  A a(1);
  B b(2);
  C c(3);
  D d(4);

  cout << "a.num:" << a.num << endl; // a.num:1
  cout << "b.num:" << b.num << endl; // b.num:2
  cout << "c.num:" << c.num << endl; // c.num:3
  // cout << "d.num:" << d.num << endl;
  // //报错，d.num不明确没需要指明访问那个父类的变量
  cout << "d.B::num:" << d.B::num << "addr d.B::num:" << &d.B::num
       << endl; // d.B::num:4addr d.B::num:0xf685fff77c
  cout << "d.C::num:" << d.C::num << "addr d.C::num:" << &d.C::num
       << endl; // d.C::num:4addr d.C::num:0xf685fff780

  // 从类D的实例d中，知名要访问的父类的成员的全路径，取地址观察是两个不同的地址，
  // 这意味着D同时集成B和C的时候，B中有一个num，C中也有一个num,
  // 在访问d.num时不知道访问B和C中哪一个类的中的变量，导致不明确

  // 这种菱形继承存在着资源的浪费，因为只要是开始的基类A中有的数据成员，在D被继承下来后，都会有两份分别存在B，C中

  B1 b1(5);
  C1 c1(6);
  D1 d1(7);
  cout << "c1.num:" << c1.num << endl; // c1.num:6
  // 如下观察数据成员num的地址：
  cout << "d1.num:" << d1.num << "addr d1.num:" << &d1.num << endl;
  cout << "d1.C1::num:" << d1.C1::num << "d1.C1::num:" << &d1.C1::num << endl;
  cout << "d1.B1::num:" << d1.B1::num << "d1.B1::num:" << &d1.B1::num << endl;
  cout << "d1.C1::A::num:" << d1.C1::A::num
       << "d1.C1::A::num:" << &d1.C1::A::num << endl;
  cout << "d1.B1::A::num:" << d1.B1::A::num
       << "d1.B1::A::num:" << &d1.B1::A::num << endl;

  /* 输出
    d1.num:0addr d1.num:0x62e5bffba0
    d1.C1::num:0d1.C1::num:0x62e5bffba0
    d1.B1::num:0d1.B1::num:0x62e5bffba0
    d1.C1::A::num:0d1.C1::A::num:0x62e5bffba0
    d1.B1::A::num:0d1.B1::A::num:0x62e5bffba0
   */

  // 从输出可以看出，使用了虚继承的方式后，在实例对象d1中，num只存在一份
  //  而无论是全路径d1.C1::num 还是 d1.B1::num 的地址都是同一个且和 d1.num相同

  // 注意：因为是虚继承，参数列表传递只在菱形的尾部D1的最近一层父类进行，对于再上层的基类，会调用不会带参的构造函数
  // 所以需要原始基类A具有无参的构造函数，用于在构造过程中无参构建初始基类A

  return 0;
}
