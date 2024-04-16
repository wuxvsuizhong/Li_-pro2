/* 智能指针shared_ptr是一个内部有引用计数的智能指针
  1.
  在离开定义shared_ptr的代码块或者作用域时，而有没有进行return返回出来，只能指针将调用类型的析构；
  2.  不同于unique_ptr,
  shared_ptr可以定义同类型的指针变量，使用已有的shared_ptr对其进行赋值，
      相当于新增指针对同一份内存对象进行指向；同时引用计数加1；
  3.
  对同一个数据源的智能指针，如果某个shared_ptr赋值为nullptr，那么引用计数减1；
  4. 当引用计数减小到0时，自动调用类型的析构函数；
  .use_count()接口可以查看当前的引用数目

 */
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

/* shared_ptr的指针值传递 */
void func(shared_ptr<A> a) {
  cout << "进入值传递的函数，引用计数：" << a.use_count() << endl;
  a->info();
  a->setNum(30); // 修改源数据的内容
}

/* shared_ptr的引用传递 */
void func2(shared_ptr<A> &a) {
  cout << "进入引用传递的函数，引用计数：" << a.use_count() << endl;
  a->info();
  a->setNum(40);
}

int main(int argc, char const *argv[]) {
  /* 创建shared_ptr方式1:直接new类型，构造给shared_ptr */
  shared_ptr<int> sint_newptr = shared_ptr<int>{new int(10)};
  cout << *sint_newptr << " use_count:" << sint_newptr.use_count() << endl;

  shared_ptr<A> sa_newptr = shared_ptr<A>{new A(100)};
  sa_newptr->info();
  cout << " use_count:" << sa_newptr.use_count() << endl;

  /* 创建shared_ptr方式2:使用make_shared方法 */
  shared_ptr<int> sint_makeptr = make_shared<int>(11);
  cout << *sint_makeptr << " use_count" << sint_makeptr.use_count() << endl;

  shared_ptr<A> sa_makeptr = make_shared<A>(12);
  sa_makeptr->info();
  cout << " use count:" << sa_makeptr.use_count() << endl;

  /* 使用已有的shared_ptr指针对新定义的指针赋值，会增加引用计数 */
  shared_ptr<int> sint_newptr2 = sint_newptr;
  shared_ptr<A> sa_newptr2 = sa_newptr;
  cout << "sint_newptr2.use_count: " << sint_newptr2.use_count()
       << " sint_newptr2.use_count " << sa_newptr2.use_count() << endl;

  shared_ptr<int> sint_makeptr2 = sint_makeptr;
  shared_ptr<A> sa_makeptr2 = sa_makeptr;
  cout << "sint_makeptr2.use_count: " << sint_makeptr2.use_count()
       << " sa_makeptr2.use_count " << sa_makeptr2.use_count() << endl;

  /* 对已有的shared_ptr使用新的shared_ptr赋值，相当于增加了一个指针指向，但实际上的数据还是同一份
  只要通过新旧任意一个指针重新给变量的操作，那么也会反映到另外一个指针上来
   */
  *sint_newptr2 *= 10;
  cout << *sint_newptr << " " << *sint_newptr2 << endl;
  *sint_makeptr *= 10;
  cout << *sint_makeptr2 << " " << *sint_makeptr << endl;

  /* 对已有的shared_ptr使用新的shared_ptr赋值，相当于增加了一个指针指向，
  如果把新旧指针任意一个智能指针的值赋值为null,那么只要有剩下的有不为空的指针，剩下的指针依然是有效的,
  在每赋空值一个指针后，相应的智能指针的计数会减少1
  如果所有的智能指针都被赋空值，那么计数会减少到0,同时会调用类型的析构函数
   */

  cout << "-----------shared_ptr指针赋空值，直到计数为0 strat------------\n";
  sa_newptr = nullptr;
  sa_newptr2->info();
  cout << "sa_newptr2.use_count(): " << sa_newptr2.use_count() << endl;
  sa_newptr2 = nullptr;
  cout << "shared_ptr引用计数降到0后，自动调用类型的析构函数.\n";
  cout << "sa_newptr2.use_count(): " << sa_newptr2.use_count() << endl;
  cout << "-----------shared_ptr指针赋空值，直到计数为0 end------------\n";

  cout << "-------------shared_ptr 的指针值传递 start ----------------\n";
  shared_ptr<A> a_trans{new A(5)};
  cout << "指针值传递后，a_trans.info:";
  a_trans->info();
  cout << "指针值传递前，a_trans.use_count:" << a_trans.use_count() << endl;
  func(a_trans);
  cout << "指针值传递后，a_trans.use_count:" << a_trans.use_count() << endl;
  cout << "指针值传递后，a_trans.info:";
  a_trans->info();
  cout << "-------------shared_ptr 的指针值传递 end ----------------\n";
  /* 在shared_ptr进行指针值传递时，会使得引用计数+1，
      在调用结束后，会自动将引用计数-1恢复调用前的状态。
     */
  cout << "-------------shared_ptr 的指针引用传递 start ----------------\n";
  shared_ptr<A> a_ref = make_shared<A>(60);
  cout << "指针引用传递前，a_ref.info:";
  a_ref->info();
  cout << "指针引用传递前，a_ref.use_count:" << a_ref.use_count() << endl;
  func2(a_ref);
  cout << "指针引用传递后，a_ref.use_count:" << a_ref.use_count() << endl;
  cout << "指针引用传递后，a_ref.info:";
  a_ref->info();
  cout << "-------------shared_ptr 的指针引用传递 end ----------------\n";
  /* shared_ptr使用引用传递时，不会增加应用计数 */

  /* 离开定义的作用域或者代码块时，不论引用计数是否为0，都会调用析构 */
  {
    cout << "******代码块内部的shared_ptr strat******";
    shared_ptr<A> will_del{new A(1)};
    shared_ptr<A> another_will_del = will_del;
    cout << "another_will_del.use_count:" << another_will_del.use_count()
         << endl;
  }
  cout << "******代码块内部的shared_ptr end******";

  cout << "-----------delete shared_ptr  start ----------\n";
  A *adel = new A(2);
  shared_ptr<A> handle_del(adel);
  shared_ptr<A> handle_del2 = handle_del;

  delete adel;
  handle_del->info();   //通过原始指针删除对象后，用shared_ptr访问对象将变，结果是不确定的
  handle_del2->info();

  cout << "-----------delete shared_ptr  end ----------\n";

  return 0;
}
