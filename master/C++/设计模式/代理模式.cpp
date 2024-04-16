// 代理模式，就是控制用户对目标实例的访问，通过验证权限或者账号等行为
// 只有验证通过的场景下才能允许对目标对象访问

#include <iostream>

using std::cout, std::endl, std::string;

class
    AbstratctInterface { // 这里抽象出一个接口类是为了能够让单例的同名run方法，替换系统的run
  virtual void run() = 0;
};

class MySystem : public AbstratctInterface {
public:
  MySystem() { cout << "MySystem \n"; }
  ~MySystem() {}

  void run() { cout << "系统启动...\n"; };
};

class SystemProxy : public AbstratctInterface {
private:
  MySystem *sys;
  string userName;
  string password;

public:
  SystemProxy(string username, string password) {
    this->userName = username;
    this->password = password;
    this->sys = new MySystem; // 在代理内部初始化要访问的目标实例
  }

  ~SystemProxy() {
    if (this->sys) {
      delete this->sys;
    }
  }

  void run() {
    if (!checkAuth()) {
      cout << "验证未通过，权限不足!\n";
      return;
    }
    this->sys->run();
  }

  bool checkAuth() {
    if (this->userName != "admin" || this->password != "admin")
      return false;
    return true;
  }
};

int main(int argc, char const *argv[]) {
  SystemProxy *sysproxy = new SystemProxy("root", "admin");
  sysproxy->run();
  /* 输出：
  MySystem
  验证未通过，权限不足!
  */

  delete sysproxy;
  SystemProxy *sysproxy2 = new SystemProxy("admin", "admin");
  sysproxy2->run();
  /* 输出
  MySystem
  系统启动...
  */

  delete sysproxy2;
  return 0;
}

// 在代理模式中，用代理的接口来替代访问目标的接口，为了接口的同一，代理和目标实例都来自共同的抽象基类
// 然后在代理类中实例化目标类的实例,并用代理类的接口替代目标实例的接口