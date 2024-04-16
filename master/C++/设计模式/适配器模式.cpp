#include <algorithm>
#include <iostream>

using std::cout, std::endl, std::vector, std::for_each;

// 在cpp中，struct可以当做类内使用，和class申明不同的是，struct中的成员默认是public的，
// class中只有添加了public的成员才是public
struct MyPrint { // 此处把struct当做类来使用，
  void operator()(int v1, int v2) { cout << v1 + v2 << endl; }
  // 这里直接定义()操作符，用于传递两个参数然后对两个参数进行加和计算
};

class Adaptor : public MyPrint {
public:
  MyPrint print;
  int param;
  void operator()(int v) {
    print(v, param);
  } // 这里operator()的重定义，相当于给Adaptor定义了一个即时掉用方法，只要初始化Adaptor()经相当于调用和函数用于调用print(v,param)
  Adaptor(int param) {
    this->param = param;
  } // 通过构建是传递一个参数设置param,然后后续和operator()中传入的参数进行加和
};

int main(int argc, char const *argv[]) {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  for_each(v.begin(), v.end(), MyPrint());
  // 编译报错，因为for_each接受的第三个参数是一个函数指针，只接受一个参数用于把迭代的每一项都传给该函数指针，
  // 这里MyPrint()实例化的对象，是一个操作函数，但是他需要两个参数的，不符合for_each的第三个参数的函数要求

  for_each(v.begin(), v.end(), Adaptor(100));
  /* 使用了适配器Adaptor之后，既可以正常应用foir_each的第三个参数了
  输出：
  100
  101
  102
  103
  104
  105
  106
  107
  108
  109
  */
  return 0;
}
