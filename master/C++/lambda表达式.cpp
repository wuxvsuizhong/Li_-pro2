#include <algorithm> //STL算法，for_each
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class add {
public:
  void operator()(T &t) // 重载()运算符
  {
    t *= t;
    cout << t << endl;
  }
};

class test {
public:
  vector<int> myv;
  int num;

public:
  test() {
    num = 1;
    myv.push_back(10);
    myv.push_back(11);
  }

  void add() {
    int x = 3;
    // auto fun = [this,x](int
    // v){cout<<v+this->num<<endl;};//[this,x]访问块语句类的局部变量，有副本机制，无法修改源数据
    auto fun = [&](int v) {
      cout << v + this->num << endl;
    }; //[&]引用所有的局部变量外加this指针，无副本机制，可以直接修改源数据

    for_each(this->myv.begin(), myv.end(), fun);
  }
};

template <typename T> void go(T &t) {
  t *= 2;
  cout << t << endl;
}

int main() {
  vector<int> myv;
  myv.push_back(5);
  myv.push_back(6);
  myv.push_back(7);
  myv.push_back(8);
  myv.push_back(9);

  /*
  add<int> AddInt;//实例化一个
  //方式1
  for_each(myv.begin(),myv.end(),AddInt);//for_each算法，会把AddInt当成一个函数指针来用，为其自动调用，所以之前重在了AddInt的()方法
   */

  /*
  //方式2
  for_each(myv.begin(),myv.end(),add<int>());//实例化临时变量
   */

  /*
  //方式3，函数实现
  for_each(myv.begin(),myv.end(),go<int>);
  */

  // 方式4，调用lambda表达式
  auto func = [](int a, int b) { return a + b; }; // lambda表达式
  cout << func(1, 3) << endl;
  cout << "-----------\n";
  auto funAdd = [](int a) {
    a *= 2;
    cout << a << endl;
  };
  for_each(myv.begin(), myv.end(), funAdd);

  // 方式5，直接编辑lambda
  cout << "------------\n";
  for_each(myv.begin(), myv.end(), [](int a) {
    a *= 2;
    cout << a << endl;
  });

  int num = 10;
  cout << "lambda [=]-->" << endl;
  for_each(myv.begin(), myv.end(), [=](int a) {
    a += num;
    cout << a << endl;
  });
  //[=]用于捕获当前块语句中的局部变量num,有副本机制，可以读取变量，但是不能修改源变量
  cout << endl;

  cout << "lambda [&num]-->" << endl;
  for_each(myv.begin(), myv.end(), [&num](int a) {
    a += num;
    cout << a << endl;
    num += 1;
  });
  //[&a】引用变量num,可以读写num
  cout << endl;

  []() { cout << "hello world!" << endl; }(); // lambda表达式加上()可以直接调用

  auto function = []() -> double {
    return 6.0 / 5;
  }; // 带返回值的lambda表达式，按照 []()->类型{}  格式
  cout << function() << endl;
  auto function2 = [](int a, double b) -> decltype(a / b) {
    return a / b;
  }; // decltype自动获取返回值的类型
  cout << function2(11.0, 5) << endl;

  return 0;
}
