// 工厂方法模式在一定程度上解决了，简单工厂模式中的开闭原则问题
// 就是在简单工厂的基础上，增加一层工厂的抽象，然后每扩展一种产品类型就对应的扩展一种工厂类型
// 但是工厂方法模式也带来了新的问题，那就是当扩展的具体类过多时，类的数量就会成倍的增加，不利于维护

#include <iostream>
using std::cout, std::endl;

class AbstractFruit {
public:
  virtual void showname() = 0;
};

class Apple : public AbstractFruit {
public:
  void showname() { cout << "苹果" << endl; };
};

class Banana : public AbstractFruit {
public:
  void showname() { cout << "香蕉" << endl; };
};

class AbstractFactory {
public:
  virtual AbstractFruit *createFruit() = 0;
};

class AppleFactory : public AbstractFactory {
public:
  AbstractFruit *createFruit() { return new Apple(); };
};

class BananaFactory : public AbstractFactory {
public:
  AbstractFruit *createFruit() { return new Banana(); }
};

int main(int argc, char const *argv[]) {
  AppleFactory *appleFac = new AppleFactory();
  AbstractFruit *apple = appleFac->createFruit();

  BananaFactory *bananaFac = new BananaFactory();
  AbstractFruit *banana = bananaFac->createFruit();

  apple->showname();
  banana->showname();
  return 0;
}
