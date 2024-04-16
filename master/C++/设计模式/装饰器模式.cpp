/* 装饰器模式， 一般使用继承实现内的功能扩展，可以动态的给一个类添加功能
  以游戏场景中的人物为例，一开始有人物这个类，然后可以给人物增加装备，更换皮肤，
  那么这些动作都是对原来的人物类的功能的扩展
*/

#include <iostream>

using std::cout, std::endl;

// 定义角色的抽象类
class AbstractHuman {
private:
  int HP, AT, DF; // 血量 攻击值 防御值
public:
  virtual void showStatus() = 0;
};

// 通过继承扩展角色功能和属性
class AbstractHero : public AbstractHuman {

public:
  int HP, AT, DF;

  AbstractHero() { HP = AT = DF = 0; }
  virtual void showStatus() {
    cout << "PH:" << HP << "\n"
         << "AT:" << AT << "\n"
         << "DF:" << DF << endl;
  }
};

// 仍然是通过抽象类的继承，
class AbstractEquipmentHero : public AbstractHero {
public:
  AbstractHero *pHero;

  AbstractEquipmentHero(AbstractHero *hero) { pHero = hero; }
};

class WeaponEquipment : public AbstractEquipmentHero {
public:
  WeaponEquipment(AbstractHero *hero) : AbstractEquipmentHero(hero) {
    addWeapon();
  }
  void addWeapon() {
    this->HP = pHero->HP;
    this->AT = pHero->AT + 80; // 装备武器后，攻击力+80
    this->DF = pHero->DF;
  }

  void showStatus() {
    cout << "-----------装备上武器之后----------" << endl;
    cout << "PH:" << HP << "\n"
         << "AT:" << AT << "\n"
         << "DF:" << DF << endl;
  }
};

class ArmorEquipment : public AbstractEquipmentHero {
public:
  ArmorEquipment(AbstractHero *hero) : AbstractEquipmentHero(hero) {
    addArmor();
  }

  void addArmor() {
    this->AT = pHero->AT;
    this->DF = pHero->DF + 80; //装配上铠甲之后，防御力增加80
    this->HP = pHero->HP;
  }

  void showStatus() {
    cout << "-----------装备上铠甲之后----------" << endl;
    cout << "PH:" << HP << "\n"
         << "AT:" << AT << "\n"
         << "DF:" << DF << endl;
  }
};

int main(int argc, char const *argv[]) {
  AbstractHero *hero = new AbstractHero();
  hero->showStatus();

  hero = new WeaponEquipment(hero);
  hero->showStatus();

  hero = new ArmorEquipment(hero);
  hero->showStatus();

  return 0;
}
