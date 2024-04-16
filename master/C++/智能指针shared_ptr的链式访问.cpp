#include <iostream>
#include <memory>
using std::cout, std::endl, std::shared_ptr, std::make_shared;

// A class strat
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
// A class end

shared_ptr<A> get_shared() {
  shared_ptr<A> a_in_block = make_shared<A>(30);
  cout << "返回函数中创建的shared_ptr前，a_in_block.use_count:"
       << a_in_block.use_count() << endl;
  return a_in_block;
}

int main(int argc, char const *argv[]) {
  shared_ptr<A> a_in_main = get_shared();
  cout << "回到函数中创建的shared_ptr前，a_in_main.use_count:"
       << a_in_main.use_count() << endl;

  /* 在被调用的函数中创建的shared_ptr，返回主调后，引用计数不会增加 */

  get_shared()->info(); // shared_ptr的链式访问
  return 0;
}
