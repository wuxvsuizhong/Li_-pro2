/*
智能指针，其实是对原始指针的一层包装，有定义过程，赋值过程；
智能指针unique_ptr
1.脱离代码块或者是作用域后，自动调用类型的析构函数;
2.把原unique_ptr指针变量重新赋值给一个新创建的智能指针，原指针将调用类型的析构函数；
3.不能用同类型的新定义的unique_ptr智能指针变量，给其使用已有的unique_ptr指针对其直接进行赋值，
  需要使用move移动语义才能进行赋值。

.get()可以查看指针指向的内存区域地址
 */

#include <iostream>
#include <memory> //auto_ptr和unique_ptr智能指针头文件

using std::cout, std::endl;

#define CRE_intellect_ptr 0
#define check_free 0
#define use_intellect_ptr 1

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

using std::unique_ptr;
/* 智能指针的指针值传递 */
void func(unique_ptr<A> a) { a->info(); }   // 指针值传递
void func2(unique_ptr<A> &a) { a->info(); } // 指针引用传递
void func3(const unique_ptr<A> &a) {        // 指针引用传递
  a->setNum(10);
  a->info();
}

int main() {
#if CRE_intellect_ptr
  for (int i = 0; i < 10000000; i++) {
    double *p = new double;
    std::auto_ptr<double> autop(p); // 将p包装成智能指针,c98版的智能指针

    std::unique_ptr<double> pdb(new double); // c++版智能指针,无需依赖已有指针
  }
#endif

#if check_free

  // 栈上
  A a_arg(1); // 栈上创建的类实例化对象，会在函数retuen前会自动调用析构
  A a_noarg(); // 无参的构造函数可能会被优化

  // 堆上
  int *p1 = new int(100);
  A *a = new A(111); // 堆上new出的实例化对象，如果不调用delete会有内存泄漏
  {
    delete p1; // 如果要重用指针，需要在重用前delete旧的指向内存
    p1 = new int(200); // p1被重新使用，二次new改变了指向
    // delete p1;  【非法】在重用后delete，会导致之前p1指向的地址内存泄漏

    // 重用了外部的堆上的指针p1，但是后续没有delete,会有内存泄漏问题
    A(2); // 块中的栈实例化也会自动调用析构
  }

  std::cout << *p1 << std::endl;
  delete p1;
#endif

#if use_intellect_ptr // 使用智能指针
  cout << "------------智能指针使用 start---------------\n";

  /* ******智能指针使用方式1：把comm_a包装为智能指针ua **************/
  A *comm_a = new A(1000);
  std::unique_ptr<A> ua(comm_a);
  cout << "delete 原始指针前，原始指针和智能指针都可以访问" << endl;
  comm_a->info();
  ua->info();
  // delete comm_a;  //原始指针赋值为空即可，不可进行delete
  comm_a = nullptr;
  cout << "delete原始指针后,智能指针将不可以再用" << endl;
  // ua->info();
  cout << "delete原始指针后,原始指针不可以再使用" << endl;
  // comm_a->info();

  /* ******************* 方式1 end **************************** */

  /**************** 智能指针使用方式2:直接new类型构造给unique_ptr */
  /**************** std::unique_ptr<A> ua2(new A(1000)); *******/
  /* 或者 */ std::unique_ptr<A> ua2{new A(1001)};
  ua2->info();
  cout << "自定义类A 智能指针地址ua2 " << ua2.get() << endl;
  std::unique_ptr<int> uaint2{new int(10)};
  cout << "常规类型int 智能指针地址uaint2: " << uaint2.get() << endl;
  /* ************** 方式2 end ******************************** */

  /* ***【推荐】智能指针使用方式3：调用std::make_unique<T>创建类型T的智能指针*
   * ***/
  std::unique_ptr<A> ua3 = std::make_unique<A>(1002);
  cout << "自定义类A 智能指针地址ua3" << ua2.get() << endl;
  std::unique_ptr<int> uaint3 = std::make_unique<int>(12);
  cout << "常规类型int 智能指针地址uaint3:" << uaint3.get() << endl;
  /* ******************方式3 end ***************************** */

  {
    cout << "-------------内部代码块 start-------------\n";
    A *inner_a = new A(111);
    std::unique_ptr<A> inner_ua(inner_a); // 方式1
    inner_a->info();
    int *inner_i = new int(11);
    std::unique_ptr<int> inner_uinti(inner_i); // 方式1

    std::unique_ptr<A> inner_uanew(new A(112)); // 方式2
    inner_uanew->info();
    std::unique_ptr<int> inner_uintnew(new int(12)); // 方式2

    std::unique_ptr<A> inner_makea = std::make_unique<A>(113); // 方式3
    inner_makea->info();
    std::unique_ptr<int> inner_makeint = std::make_unique<int>(13); // 方式3
  }
  cout << "-------------内部代码块 end-------------\n";

#endif

  cout << "-----------------智能指针的指针值传递 start---------------\n";
  unique_ptr<A> uniq_a = std::make_unique<A>(50);
  // func(uniq_a);  //错误，智能指针传递指针值时需要移动语义后再进行传递
  cout << "*****智能指针值传递move，传递之前*****\n";
  func(std::move(uniq_a));
  cout << "*****智能指针值传递move，传递之后*****\n";
  // uniq_a->info();   //错误，智能指针在move被传递后，会被析构，将不可再访问

  /* ****************【智能指针传递指针值 总结】******************/
  /*智能指针的指针值传递，需要移动语义move；
    在move传递之后，智能指针将在被调用的功能函数或代码块结束后被释放，指针后续将不可用，无法在继续访问；
  */

  cout << "*****智能指针在传递时默认带有move移动语义*****\n";
  func(std::make_unique<A>());
  func(std::make_unique<A>(51));
  cout << "-----------------智能指针的指针值传递 end---------------\n";

  cout << "-----------------智能指针的指针引用传递 start---------------\n";
  unique_ptr<A> uniq_ca = std::make_unique<A>(52);
  func2(uniq_ca);
  uniq_ca->info(); // 智能指针引用传递结束后，智能指针不会被析构，还可以访问
  func3(uniq_ca);
  uniq_ca->info();
  cout << "-----------------智能指针的指针引用传递 end---------------\n";

  cout << "---------不能用同类型的新智能指针直接指向源智能指针 "
          "start----------\n";
  unique_ptr<A> ua_init(new A(111));
  // unique_ptr<A> another_ua = ua_init;  错误
  cout << "*****需要使用移动语义move对已有的智能指针更换所有权到新智能指针*****"
          "\n";
  unique_ptr<A> ua_will_move(new A(112));
  cout << "move之前，源数据:";
  ua_will_move->info();
  unique_ptr<A> ua_moved = std::move(ua_will_move);
  cout << "move之后，目标数据:";
  ua_moved->info();
  cout << "---------不能用同类型的新智能指针直接指向源智能指针 end----------\n";

  cout << "---------智能指针被重新复制后，原数据将调用析构 start--------\n";
  ua_init->info();
  ua_init = unique_ptr<A>(new A(222));
  ua_init->info();
  cout << "---------智能指针被重新复制后，原数据将调用析构 end--------\n";

  std::cout << "---------- main end-----------\n";
  return 0;
}
