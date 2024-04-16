// 观察者模式中分为蒸菜观察的观察者，和被观察的对象
// 当被观察的对象发生某种变化的时候，它可以通知众多的观察者，以便观察者做出相应的动作

// 以游戏中的场景为例，当有多个角色在攻击关卡中的BOSS的时候，当BOSS死亡时，玩家都停止攻击
// 这里的BOSS就是被观察者，而玩家就是观察者

#include <iostream>
#include <list>

using std::cout, std::endl;

// 游戏角色可以有多个，那么关卡BOSS也可以有多个，他们都可以实现上层抽象

// 抽象的英雄角色
class AbstratctHero {
public:
  virtual void Update() = 0;
};

class HeroA : public AbstratctHero {
public:
  HeroA() { cout << "英雄A正在攻击...\n"; }
  virtual void Update() { cout << "英雄A停止攻击，等待状态...\n"; }
};

class HeroB : public AbstratctHero {
public:
  HeroB() { cout << "英雄B正在攻击...\n"; }
  virtual void Update() { cout << "英雄B停止攻击，等待状态...\n"; }
};

class HeroC : public AbstratctHero {
public:
  HeroC() { cout << "英雄C正在攻击...\n"; }
  virtual void Update() { cout << "英雄C停止攻击，等待状态...\n"; }
};

// 抽象的关卡BOSS
class AbstractBOSS {
public:
  virtual void recvChallenge(AbstratctHero *hero) = 0;
  virtual void deleteChallenge(AbstratctHero *hero) = 0;
  virtual void updateChallenge() = 0;
};

class BOSSA : public AbstractBOSS {
private:
  std::list<AbstratctHero *> challengeList;

public:
  BOSSA() {}

  virtual void recvChallenge(AbstratctHero *hero) {
    cout << "BOSSA 接受挑战...\n";
    challengeList.push_back(hero);
  }
  virtual void deleteChallenge(AbstratctHero *hero) {
    challengeList.remove(hero);
  }
  virtual void updateChallenge() {
    for (std::list<AbstratctHero *>::iterator it = challengeList.begin();
         it != challengeList.end(); it++) {
      (*it)->Update();
    }
  }
};

// 还可以实现其他的关卡BOSS...

int main(int argc, char const *argv[]) {
  HeroA *h1 = new HeroA();
  HeroB *h2 = new HeroB();
  HeroC *h3 = new HeroC();

  BOSSA *boss = new BOSSA();
  boss->recvChallenge(h1);
  boss->recvChallenge(h2);
  boss->recvChallenge(h3);

  boss->deleteChallenge(h1);
  cout << "英雄A死亡" << endl;

  cout << "BOSSA 死亡..." << endl;

  boss->updateChallenge(); // 通知所有的观察者更新状态
  return 0;
}
