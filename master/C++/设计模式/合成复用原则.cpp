// 合成复用原则，推荐的是优先使用类的组合，而不是类的继承

#include <iostream>
using std::cout, std::endl;

// 如下是一个支付渠道的例子
class Payment {
public:
  virtual void pay(int n) = 0;
};

class Alipay : public Payment {

public:
  void pay(int n) { cout << "支付宝支付" << n << "元\n"; };
};

class Wechat : public Payment {
public:
  void pay(int n) { cout << "微信支付" << n << "元\n"; }
};

class BankPay {
public:
  void cost(int n) { cout << "银行支付" << n << "元\n"; }
};

class CardPay {
public:
  void cost(int n) { cout << "刷卡支付" << n << "元\n"; }
};

// Alipay和WechatPay都有共同的基类Payment约束的接口，但是对于后来的BankPay和CardPay,不受Payment接口的约束

/* 方式1：使用继承的方式复用 */
// 以下是使用适配器适配后来的BankPay和CardPay
// 每一个新来的，接口不兼容的类型，都需要一个适配的类，并且至少要继承新支付类
class AdaptorBankPay : public Payment, public BankPay {
public:
  void pay(int n) { this->cost(n); }
};

class AdaptorCardPay : public Payment, public CardPay {
public:
  void pay(int n) { this->cost(n); }
};

/* 方式2：使用类组合的方式复用 */
class MobilePay {
  // 移动支付类
public:
  Payment *inner_pay = nullptr;
  MobilePay(Payment *payment) { inner_pay = payment; };

  void pay(int n) { this->inner_pay->pay(n); }
};

int main(int argc, char const *argv[]) {
  Payment *payment = new Alipay();
  payment->pay(10);
  delete payment;

  payment = new AdaptorBankPay();
  payment->pay(20);

  /* 上面的Alipay和Adaptor都可以正常输出，上述的输出结果是
    支付宝支付10元
    英银行支付20元
   */

  MobilePay *mpay = new MobilePay(payment);
  mpay->pay(100);
  Wechat *payment2 = new Wechat();
  MobilePay *mpay2 = new MobilePay(payment2);
  mpay2->pay(90);
  /* 输出
  银行支付100元
  微信支付90元
   */

  // 组合复用的优势是，避免了每一个案例都去实现一个集成的类，
  //  而是在构建的时候通过传入指定的类型实例来把新的功能计入到类中
  return 0;
}
