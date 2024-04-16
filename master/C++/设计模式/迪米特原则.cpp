// 又称为最小值知识原则,就是当对象需要和其他的类对象进行交互式，应尽可能少的对其他的类了解

// 如下是生活中的一个买房子的案例
/* 当用户需要去买房时，面对各种各样的楼盘类型，高精装，毛坯房的，预售等等。
如果是自己一个个去了解，就比较耗时，这时候就有了中介这个职业，
用户只需要告诉中介需要什么样的房子，那么中介会帮用户筛选后，返回给用户需要的信息…
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string;

class AbstractBuild {
public:
  virtual void sale() = 0;
  virtual string getQuantity() = 0;
};

class BuildingA : public AbstractBuild {
private:
  string quantity = "";

public:
  BuildingA() { quantity = "高品质楼盘"; }
  virtual void sale() { cout << "楼盘" << quantity << "被售卖" << endl; }
  virtual string getQuantity() { return quantity; }
};

class BuildNormal : public AbstractBuild {
private:
  string quantity = "";

public:
  BuildNormal() { quantity = "普通楼盘"; }
  virtual void sale() { cout << "楼盘" << quantity << "被售卖" << endl; }
  string getQuantity() { return quantity; }
};

// 中介类
class Mediator {
private:
  std::vector<AbstractBuild *> resources;

public:
  Mediator() {
    AbstractBuild *building = new BuildingA();
    resources.push_back(building);
    building = new BuildNormal();
    resources.push_back(building);
  }
  ~Mediator() {
    for (std::vector<AbstractBuild *>::iterator it = resources.begin();
         it != resources.end(); it++) {
      if (*it != NULL) {
        delete *it;
      }
    }
  }

  // 对外暴露的接口
  AbstractBuild *findBuild(string quantity) {
    for (std::vector<AbstractBuild *>::iterator it = resources.begin();
         it != resources.end(); it++) {
      if ((*it)->getQuantity() == quantity)
        return *it;
    }
    return NULL;
  }
};

int main(int argc, char const *argv[]) {
  Mediator *m = new Mediator();
  AbstractBuild *building = m->findBuild("普通楼盘");
  if (building)
    building->sale();
  else
    cout << "没有符合条件的楼盘\n";

  return 0;
}

// 在这个例子中，多有的资源掌握在Mediator这个类的手中，对于需要特定信息的客户，只需调用该类的实例
// 并提供需求，Mediator会返回需要的信息；