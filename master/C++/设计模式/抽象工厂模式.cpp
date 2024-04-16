#include <iostream>

using std::cout, std::endl, std::string;

// 抽象的苹果
class AbstractApple {
public:
  virtual void showName() = 0;
  virtual ~AbstractApple() { cout << "~AbstractApple\n"; }
};

// 中国苹果
class ChinaApple : public AbstractApple {
public:
  virtual void showName() { cout << "中国苹果\n"; }
  virtual ~ChinaApple() { cout << "~ChinaApple\n"; }
};
// 美国苹果
class USAApple : public AbstractApple {
public:
  virtual void showName() { cout << "美国苹果\n"; }
  virtual ~USAApple() { cout << "~USAApple\n"; }
};
// 日本
class JanpenApple : public AbstractApple {
public:
  virtual void showName() { cout << "日本苹果\n"; }
  virtual ~JanpenApple() { cout << "~JanpenApple\n"; }
};

// 抽象香蕉
class AbstractBanana {
public:
  virtual void showName() = 0;
  virtual ~AbstractBanana() { cout << "~AbstractBanana\n"; }
};

// 中国香蕉
class ChinaBanana : public AbstractBanana {
public:
  virtual void showName() { cout << "中国香蕉\n"; }
  virtual ~ChinaBanana() { cout << "~ChinaBanana\n"; }
};

// 美国香蕉
class USABanana : public AbstractBanana {
public:
  virtual void showName() { cout << "美国香蕉\n"; }
  virtual ~USABanana() { cout << "~USABanana\n"; }
};

// 日本香蕉
class JanpenBanana : public AbstractBanana {
public:
  void showName() { cout << "日本香蕉\n"; }
  virtual ~JanpenBanana() { cout << "~JanpenBanana\n"; }
};

// 抽象的梨
class AbstractPear {
public:
  virtual void showName() = 0;
  virtual ~AbstractPear() { cout << "~AbstractPear\n"; }
};

// 中国的梨
class ChinaPear : public AbstractPear {
public:
  virtual void showName() { cout << "中国的梨\n"; }
  virtual ~ChinaPear() { cout << "~ChinaPear\n"; }
};

// 美国的梨
class USAPear : public AbstractPear {
public:
  virtual void showName() { cout << "美国的梨\n"; }
  virtual ~USAPear() { cout << "~USAPear\n"; }
};

// 日本的梨
class JanpenPear : public AbstractPear {
public:
  virtual void showName() { cout << "日本的梨\n"; }
  virtual ~JanpenPear() { cout << "~JanpenPear\n"; }
};

// 抽象工厂 针对产品族
class AbstrtactFactory {
public:
  virtual AbstractApple *createApple() = 0;
  virtual AbstractBanana *createBanana() = 0;
  virtual AbstractPear *createPear() = 0;
};

// 中国工厂
class ChinaFatory : public AbstrtactFactory {
public:
  AbstractApple *createApple() { return new ChinaApple(); }
  AbstractBanana *createBanana() { return new ChinaBanana(); }
  AbstractPear *createPear() { return new ChinaPear(); }
};

// 美国工厂
class UASFatory : public AbstrtactFactory {
public:
  AbstractApple *createApple() { return new USAApple(); }
  AbstractBanana *createBanana() { return new USABanana(); }
  AbstractPear *createPear() { return new USAPear(); }
};

// 日本工厂
class JanpenFatory : public AbstrtactFactory {
public:
  AbstractApple *createApple() { return new JanpenApple(); }
  AbstractBanana *createBanana() { return new JanpenBanana(); }
  AbstractPear *createPear() { return new JanpenPear(); }
};

int main(int argc, char const *argv[]) {
  // 中国工厂生产的水果
  AbstrtactFactory *cFac = new ChinaFatory();

  AbstractApple *apple = cFac->createApple();
  AbstractBanana *banana = cFac->createBanana();
  AbstractPear *pear = cFac->createPear();

  apple->showName();
  banana->showName();
  pear->showName();

  delete apple;
  delete banana;
  delete pear;
  delete cFac;

  return 0;
}

/* 抽象工厂模式是可以在工厂类生产出一批次的不同类型的产品，产品的品牌是跟随工厂走的；
比如这里的美国水果和中国水果，分别对应各自的工厂。
不同的工厂但是有相似的接口产出同类型的产品，但是每个工厂的一批产品中，产品类型各不相同
 */