#include <iostream>
#include <memory>
using std::cout, std::endl, std::unique_ptr, std::make_unique;

/* 类A */
class A {
public:
  explicit A(int n);
  A();
  A(const A &a);
  ~A();
  void setNum(int v);

  void info() const; // 后置const限定函数内不能修改成员值

private:
  int num = 0;
};
A::A(int n) : num(n) {
  std::cout << "A的带参构造函数,num=" << num << std::endl;
}
A::A() { std::cout << "A的默认构造函数，num=" << num << std::endl; }
A::A(const A &a) { "A的拷贝构造函数\n"; }
A::~A() { std::cout << "A的析构函数,num=" << num << std::endl; }
void A::info() const { std::cout << "info信息,num=" << num << std::endl; }
void A::setNum(int v) { num += v; }
/* 类A end */

/* 函数中创建的智能指针return出函数 */
unique_ptr<A> get_uniq_ptr(int v = 0) {
  unique_ptr<A> a;
  if (v)
    a = make_unique<A>(v);
  else
    a = make_unique<A>();

  cout << "address a.get():" << a.get()
       << endl;                        // address a.get():0x187c37521e0
  cout << "address &a:" << &a << endl; // address &a:0x4e587ffca8
  /* 智能指针的.get()得到的地址和直接&得到的地址不同 */
  return a; // 返回函数内创建的智能指针
}

void change_direction(/* const */ unique_ptr<A> &a) {
  
  cout << "change_direction\n";
  a = get_uniq_ptr(); // 如果const 修饰形参后，就不可以改变源数据的指向
  //这里a被重新赋值指向另外的对象，源数据a背后的析构函数将会被调用
  return;
}

int main(int argc, char const *argv[]) {
  unique_ptr<A> a_in_main = get_uniq_ptr();
  a_in_main->info(); // 可以正常访问在函数中创建的智能指针

  get_uniq_ptr(11)->info(); // 直接调用时可以链式访问函数内创建的智能指针

  unique_ptr<A> aa = make_unique<A>(100);
  change_direction(aa);
  cout << "change_direction end.\n";
  // 在调用的函数中修改了智能指针的指向，源数据aa的析构函数将被调用
  aa->info();   //将访问的是新指向的数据中的

  cout<<"---------main end ----------\n";
  return 0;
}