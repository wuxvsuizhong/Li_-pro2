// weak_ptr 是为了解决循环依赖的问题，
// 所谓的循环依赖是指在超过一个类实例时，实例a中包含有实例b成员的智能指针，而实例b中同样有a的智能指针
// 析构时，a析构前需要先析构b，f但是b中有a的指针，又需要先析构a,
// 这就导致循环引用。

//  weak_ptr无法单独存在，需要依靠shared_ptr

#include <iostream>
#include <memory>
using std::cout, std::endl, std::shared_ptr, std::make_shared, std::weak_ptr;

// A class strat
class A {
public:
  explicit A(int n);
  A();
  A(const A &a);
  ~A();
  void setNum(int v);
  void setFriend(shared_ptr<A> f);
  void setFriendWeak(shared_ptr<A> f);
  void info() const; // 后置const限定函数内不能修改成员值

private:
  int num = 0;
  shared_ptr<A> A_frined; // 危险！这里使用shared_ptr可能会存在循环依赖问题
  weak_ptr<A> A_friend_weak; // 设置为weak_ptr类型更安全
};
A::A(int n) : num(n) {
  std::cout << "A的带参构造函数,num=" << num << std::endl;
}
A::A() { std::cout << "A的默认构造函数，num=" << num << std::endl; }
A::A(const A &a) { "A的拷贝构造函数\n"; }
A::~A() { std::cout << "A的析构函数,num=" << num << std::endl; }
void A::info() const { std::cout << "info信息,num=" << num << std::endl; }
void A::setNum(int v) { num += v; }
void A::setFriend(shared_ptr<A> f) { A_frined = f; }
void A::setFriendWeak(shared_ptr<A> f) { A_friend_weak = f; }
// 虽然成员A_friend_weak时weak_ptr,不是shared_ptr类型，但是可以自动从shared_ptr转换为weak_ptr被传唤为
//  入参类型直接设置为shared_ptr即可

// A class end

int main(int argc, char const *argv[]) {

  /* weak_ptr的使用方式：从shared_ptr初始化创建 */
  shared_ptr<A> sa1 = make_shared<A>(10);
  weak_ptr<A> weaka(sa1); // weak_ptr依赖shared_ptr

  cout << "sa1.use_count:" << sa1.use_count() << endl;
  cout << "weaka.use_count:" << weaka.use_count() << endl;
  /* shared_ptr转成weak_ptr不影响引用计数 */

  /* weak_ptr调用.lock()转换为shared_ptr */
  shared_ptr<A> sa_locked = weaka.lock();
  cout << "-----调用.lock()转换为shared_ptr智能指针后-----\n";
  cout << "这里sa1/weaka/sa_locked其实包装的是同一份内存\n";
  cout << "sa1.use_count:" << sa1.use_count() << endl;
  cout << "weaka.use_count:" << weaka.use_count() << endl;
  cout << "sa_locked.use_count:" << sa_locked.use_count() << endl;
  /* weak_ptr转换成shared_ptr会增加引用计数+1 */

  {
    cout << "----------类成员数据的循环依赖 strat---------\n";
    shared_ptr<A> ra1 = make_shared<A>(11);
    shared_ptr<A> ra2 = make_shared<A>(22);

    // 危险！ 设置了循环依赖
    // ra1->setFriend(ra2);
    // ra2->setFriend(ra1);
    // ra1和ra2之间的A_friend成员存在循环依赖，会导致运行时ra1,ra2无法正常析构,内存泄漏

    // OK! 成员A_fiend_weak是weak_ptr类型，可以循环依赖
    ra1->setFriendWeak(ra2);
    ra2->setFriendWeak(ra1);
    // 设置weak_ptr成员，如果有循环依赖，也可以正常析构
  }
  cout << "----------类成员数据的循环依赖 end  ---------\n";

  cout << "------------------ main end ------------------\n";
  return 0;
}

/* 总结：在类中，如果成员数据存在循环依赖的可能，那么需要把成员变量设置为weak_ptr类型
 */