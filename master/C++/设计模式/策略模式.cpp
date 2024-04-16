// 测落寞时通过定义和封装了一系列的算法，实现算法之间的相互替换，策略模式让算法独立于使用他的客户，独立变化。

// 以游戏中任务使用武器为例，一个个的武器就是一个个的策略，然后任务可以随时刚换策略更换武器
#include <iostream>

using std::cout, std::endl;

// 抽象武器策略
class WeaponStrategy {
public:
  virtual void UseWeapon() = 0;
};

class Knife : public WeaponStrategy {
public:
  virtual void UseWeapon() { cout << "使用匕首\n"; }
};

class AK47 : public WeaponStrategy {
public:
  virtual void UseWeapon() { cout << "使用AK47\n"; }
};

class Character {
private:
  WeaponStrategy *pWeapon;

public:
  ~Character() { delete pWeapon; }

  void setWeapon(WeaponStrategy *weapon) { // 角色设置武器
    this->pWeapon = weapon;
  }

  void brandishWeapon() { // 角色使用户武器
    this->pWeapon->UseWeapon();
  }
};

int main(int argc, char const *argv[]) {
  Character *c = new Character();
  Knife *knife = new Knife();
  AK47 *ak = new AK47();

  c->setWeapon(knife); // 配置策略
  c->brandishWeapon();

  c->setWeapon(ak); // 更换策略
  c->brandishWeapon();

  delete c;
  delete knife;
  delete ak;

  return 0;
}
