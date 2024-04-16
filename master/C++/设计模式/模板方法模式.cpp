// 模板方法模式，通过在一个新的类中，抽象定制一套工序步骤，然后将该套工序步骤用于集成的具体类去实现不同功能，并产出

// 以冲泡茶叶和冲泡咖啡为例，不论哪种东西的冲泡，其步骤都是类似的，经历煮水，加料，倒水，加辅料的工序。
// 把这些相似的工序抽象出来，作为一个抽象基类，然后具体的东西的制作继承自该抽象基类即可
#include <iostream>

using std::cout, std::endl;

class DrinkTemplate {   //抽象出冲泡步骤
public:
  virtual void BoildWater() = 0;
  virtual void AddTo() = 0;
  virtual void PourInCup() = 0;
  virtual void AddSomething() = 0;
};

class Tea : public DrinkTemplate {
public:
  virtual void BoildWater() { cout << "烧开水...\n"; }
  virtual void AddTo() { cout << "添加茶叶...\n"; }
  virtual void PourInCup() { cout << "向杯中倒入开水...\n"; }
  virtual void AddSomething() { cout << "加糖，做奶茶...\n"; }

  void make() {
    BoildWater();
    AddTo();
    PourInCup();
    AddSomething();
  }
};

class Coffee : public DrinkTemplate {
public:
  virtual void BoildWater() { cout << "烧开水...\n"; }
  virtual void AddTo() { cout << "添加咖啡...\n"; }
  virtual void PourInCup() { cout << "向杯中倒入开水...\n"; }
  virtual void AddSomething() { cout << "加糖，加奶...\n"; }

  void make() {
    BoildWater();
    AddTo();
    PourInCup();
    AddSomething();
  }
};

int main(int argc, char const *argv[]) {
  Tea *tea = new Tea();
  tea->make();
  cout<<"------------------------\n";
  Coffee *coffee = new Coffee();
  coffee->make();

  delete tea;
  delete coffee;
  return 0;
}
