#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// 单例模式演示类 懒汉式
class Singleton {

public:
  // 公有接口获取唯一实例
  static Singleton &getInstance() {
    cout << "获取实例" << endl;
    static Singleton instance;
    cout << "地址为:" << &instance << endl;
    return instance;
  }

private:
  // 私有构造函数
  Singleton() { cout << "构造函数启动。" << endl; };

  // 私有析构函数
  ~Singleton() { cout << "析构函数启动。" << endl; };
};

//单例 恶汉模式 
class SingletonHungery {
private:
  static SingletonHungery *PSingleton;

  SingletonHungery() { cout << "SingletonHungery构造函数\n"; }
  ~SingletonHungery() { cout << "~SingletonHungery析构函数\n"; }

public:
  static SingletonHungery *getInstance() { return PSingleton; }
};
SingletonHungery *SingletonHungery::PSingleton = new SingletonHungery;

using namespace std;
int main() {

  cout << "main开始" << endl;\
  /*
  thread t1([] { Singleton &s1 = Singleton::getInstance(); });
  thread t2([] { Singleton &s2 = Singleton::getInstance(); });

  t1.join();
  t2.join();
  */
  thread tt1([] { SingletonHungery *s1 = SingletonHungery::getInstance(); });
  thread tt2([] { SingletonHungery *s2 = SingletonHungery::getInstance(); });

  tt1.join();
  tt2.join();

  cout << "main结束" << endl;
  
  return 0;
}