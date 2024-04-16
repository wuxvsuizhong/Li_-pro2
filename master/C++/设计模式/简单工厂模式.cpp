// 类的构成过程可能会比较复杂，而在具体使用类的时候，我们并不需要知道具体的创建过程。
// 期望一种可以通过调用，然后直接获取到可用的类实例的方式，这就是简单工厂模式的使用场景

#include <iostream>

using std::cout, std::endl, std::string;

class AbstractFruit {
public:
  virtual void showName() = 0;
};

class Apple : public AbstractFruit {
public:
  Apple(){};
  void showName() { cout << "苹果" << endl; }
};

class Banana : public AbstractFruit {
public:
  Banana(){};
  void showName() { cout << "香蕉" << endl; }
};

// 水果工厂类
class FruitFactory {
public:
  static AbstractFruit *CreateFruit(string t) {
    if (t == "苹果")
      return new Apple();
    if (t == "香蕉")
      return new Banana();
  }
};

int main(int argc, char const *argv[]) {
  FruitFactory *factory = new FruitFactory();
  AbstractFruit *f1 = factory->CreateFruit("苹果");
  f1->showName();
  delete f1;

  AbstractFruit *f2 = factory->CreateFruit("香蕉");
  f2->showName();
  delete f2;

  /* 输出：
  苹果
  香蕉
   */

  return 0;
}

/* 简单工厂的工厂类返回的是具体的类实例，而入参是由用户设定的足够少的参数用于确定产品类型
  但是简单工厂模式不太符合开闭原则，因为如果扩展产品类型的时候，会需要直接修改工厂类的源码。
  但是好的一点是，工厂类的存在，在调用者层面，无需知道具体产品的实现细节。
 */