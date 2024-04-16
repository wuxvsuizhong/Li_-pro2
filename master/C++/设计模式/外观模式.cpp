#include <iostream>

using std::cout, std::endl;

class Lock {
public:
  void On() { cout << "门锁打开\n"; }
  void Off() { cout << "门锁关闭\n"; }
};

class Light {
public:
  void On() { cout << "灯打开\n"; }
  void Off() { cout << "灯关闭\n"; }
};

class TV {
public:
  void On() { cout << "电视打开\n"; }
  void Off() { cout << "电视关闭\n"; }
};

class Audio {
public:
  void On() { cout << "音响打开\n"; }
  void Off() { cout << "音响关闭\n"; }
};

class Contoller {
private:
  Light *light;
  TV *tv;
  Audio *audio;
  Lock *lock;

public:
  Contoller() {
    light = new Light();
    tv = new TV();
    audio = new Audio();
    lock = new Lock();
  }

  ~Contoller() {
    delete light;
    delete tv;
    delete audio;
    delete lock;
  }

  void whenBackHome() {
    cout << "----------回家了-----------" << endl;
    lock->On();
    light->On();
    tv->On();
    audio->On();
  }

  void whenLeave() {
    cout << "--------出门了-------" << endl;
    lock->Off();
    light->Off();
    tv->Off();
    audio->Off();
  }
};

int main(int argc, char const *argv[]) {
  Contoller *ctrl = new Contoller();
  ctrl->whenBackHome();

  ctrl->whenLeave();
  delete ctrl;
  return 0;
}
