// 对扩展开放，对修改关闭，增加功能通过增加代码实现，而不是修改源码。

// 如下以一个计算器类为例

#include <iostream>
#include <memory>
#include <string>

using std::cout, std::endl, std::string, std::unique_ptr, std::make_unique,
    std::move;

class Cacculator {
private:
  int a, b;
  string op;

public:
  Cacculator(int a, int b, string oper) {
    this->a = a;
    this->b = b;
    this->op = oper;
  }
  ~Cacculator(){};

  int getResult() {
    if (op.compare("+") == 0)
      return a + b;
    else if (op.compare("-") == 0) {
      return a - b;
    } else if (op.compare("*") == 0) {
      return a * b;
    } else if (op.compare("/") == 0) {
      return a / b;
    }
  }
};

// Cacculator 类不是一个好的设计，对于后续如果要扩展功能来说，是非常不便的
// 比如要增加取余等操作类型，那么就需要修改类中的成员函数中的源代码，这不符合开闭原则
// 应该尽量移增加类或者函数的方式来扩展

// 抽象类定制计算器接口
class Calc {
public:
  virtual int getResult() = 0;
  virtual void setOpNums(int a, int b) = 0;
  virtual ~Calc() { cout << "Calc 析构\n"; };
};

// 各个计算类型依照抽象类，实现自己的操作
class AddCalc : public Calc {
public:
  int a, b;
  void setOpNums(int a, int b) {
    this->a = a;
    this->b = b;
  }
  virtual int getResult() { return a + b; }

  AddCalc() { cout << "AddCalc 构造\n"; };
  ~AddCalc() { cout << "AddCalc析构\n"; };
};

class SubCalc : public Calc {
public:
  int a, b;
  void setOpNums(int a, int b) {
    this->a = a;
    this->b = b;
  }
  virtual int getResult() { return a - b; }
};

class MulCalc : public Calc {
public:
  int a, b;
  void setOpNums(int a, int b) {
    this->a = a;
    this->b = b;
  }
  virtual int getResult() { return a * b; }
};

int main(int argc, char const *argv[]) {
  Calc *cal = new AddCalc;
  cal->setOpNums(5, 6);
  cout << cal->getResult() << endl;
  unique_ptr<Calc> ucalc(cal); // 这里使用智能指针

  ucalc = move(
      make_unique<MulCalc>()); // 智能指针重新赋值需要move移动语义转让所有权
  ucalc->setOpNums(11, 12);
  cout << ucalc->getResult() << endl;

  return 0;
}

// 在这个例子中，通过抽象类Calc规定了各种方式的计算器的接口，然后具体的某一种计算方式的计算器直接继承自抽象类Calc，然后实现自己的额计算细节即可
//  而且各个计算方式之间的代码结构之间都类似，对于增加功能来说是比较方便的
//  增加功能就不需要再去修改类中的源码了，只需要新增类即可