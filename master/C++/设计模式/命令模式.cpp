// 命令模式，通过把请求封装为一个对象，客户端要发送请求时只需要简单的调用即可实现；
// 而在具体的命令类中，通过内置服务端侧的命令执行接口来实现自己自主需要调用哪个处理方法
// 然后在服务段就可以实现把一个个的请求加入到等到队列中，或者是延迟，撤掉等操作。

#include <iostream>
#include <queue>
#include <windows.h>

using std::cout, std::endl, std::queue;

// 处理客户端各种命令的方式
class HandleClientProtocal {
public:
  void AddMoney() { cout << "给玩家增加金币\n"; }

  void AddDiamond() { cout << "给玩家增加钻石\n"; }

  void AddEquipment() { cout << "给玩家增加装备\n"; }

  void addLevel() { cout << "给玩家升级\n"; }
};

class AbstractCommand {
public:
  virtual void handle() = 0;
};

// 给玩家增加钱币的请求
class AddMoneyComamnd : public AbstractCommand {
private:
  HandleClientProtocal *pProtocal;

public:
  AddMoneyComamnd(HandleClientProtocal *protocal) {
    this->pProtocal = protocal;
  }

  virtual void handle() { this->pProtocal->AddMoney(); }
};

// 给玩家增加钻石的请求
class AddDiamondCommand : public AbstractCommand {
private:
  HandleClientProtocal *pProtocal;

public:
  AddDiamondCommand(HandleClientProtocal *protocal) {
    this->pProtocal = protocal;
  }

  virtual void handle() { this->pProtocal->AddDiamond(); }
};

// 给玩家增加装备的请求
class AddEquipmentCommand : public AbstractCommand {
private:
  HandleClientProtocal *pProtocal;

public:
  AddEquipmentCommand(HandleClientProtocal *protocal) {
    this->pProtocal = protocal;
  }

  virtual void handle() { this->pProtocal->AddEquipment(); }
};

// 给玩家升级的请求
class AddLevelCommand : public AbstractCommand {
private:
  HandleClientProtocal *pProtocal;

public:
  AddLevelCommand(HandleClientProtocal *protocal) {
    this->pProtocal = protocal;
  }

  virtual void handle() { this->pProtocal->addLevel(); }
};

// 服务器端
class Server {
public:
  queue<AbstractCommand *> qCommands;

  void addRequest(AbstractCommand *cmd) { this->qCommands.push(cmd); }
  void startHandle() {
    while (!qCommands.empty()) {
      Sleep(1000);
      AbstractCommand *cmd = qCommands.front();
      cmd->handle();
      qCommands.pop();
    }
  }
};

int main(int argc, char const *argv[]) {
  // 创建处理客户端的处理协议的类实例
  HandleClientProtocal *handleProtocal = new HandleClientProtocal();
  // 客户端的增加金币的请求
  AddMoneyComamnd *addMoney = new AddMoneyComamnd(handleProtocal);
  // 客户端增加钻石的请求
  AddDiamondCommand *addDiamond = new AddDiamondCommand(handleProtocal);
  // 客户端增加装备的请求
  AddEquipmentCommand *addEquipment = new AddEquipmentCommand(handleProtocal);
  // 客户端升级等级的请求
  AddLevelCommand *addLevelCommand = new AddLevelCommand(handleProtocal);

  Server *server = new Server();
  server->addRequest(addMoney); // 把各个请求加入到服务端的处理队列中
  server->addRequest(addDiamond);
  server->addRequest(addEquipment);
  server->addRequest(addLevelCommand);

  // 服务器开始处理请求
  server->startHandle();

  return 0;
}

/* 命令模式的好处在，非常方便扩展，比如本例中此时要在原来的基础上增加一个给玩家提升PH血量的方法，
那么只需要在协议中增加相应的协议方式（也可以继承或者组合原协议），然后再增加一个对应的命令类即可，
而在Server类中，无需任何的修改 */