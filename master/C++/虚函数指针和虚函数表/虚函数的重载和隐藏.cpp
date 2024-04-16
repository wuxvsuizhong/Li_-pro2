#include <iostream>

using std::cout, std::endl;

class VA {
public:
  VA();
  ~VA();

  virtual void show(int n);
  virtual void show(char *s);
  virtual void show();
};

VA::VA() {}
VA::~VA() {}
void VA::show() { cout << "VA的show()方法\n"; }
void VA::show(int n) { cout << "VA的int入参show()方法\n"; }
void VA::show(char *s) { cout << "VA的char *入参show()方法\n"; }

//如果基类中的虚函数有重载版本，那么在子类中如果想要完整的使用基类的虚函数接口
// 要么是不重新定义子类的虚函数
// 如果子类需要重新定义自己的虚函数，需要把重载的所有版本的虚函数都实现，
// 否则在子类中，未定义的重载函数版本，将不会自动寻找基类的函数
class RA : public VA {
public:
  RA();
  virtual ~RA();

  void show(int n);
};

RA::RA() {}
RA::~RA() {}
void RA::show(int n) { cout << "RA的int入参show()方法\n"; }

class RA2 : public VA {
  public:
  RA2();
  ~RA2();
};

RA2::RA2(){}
RA2::~RA2(){}

int main(int argc, char const *argv[])
{
  RA ra1;
  ra1.show(2);
  // ra1.show(); //子类没有把所有的重载show()重新定义，所以无法主动调用父类的重载版本

  RA2 ra2;
  ra2.show();   //因为子类中没有实现任何重载版本的show虚函数，所以可以访问基类的重载方法
  ra2.show(2);
  ra2.show("abcdefg");
  return 0;
}


/* 也就是只要子类一旦定义了基类中的重载版本的某个虚函数，那么只能访问子类自己重写的这些函数，
  同时这样也会切断子类访问父类的重载版本函数的调用；

  如果子类没有重新定义任何的基类的重载版本的虚函数，那么子类可以调用父类的重载版本的虚函数；
  或者是，子类把父类的所有重载版本都一一重新实现，这样也可以调用父类的虚函数；

 */