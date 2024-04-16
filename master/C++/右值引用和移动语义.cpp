#include <iostream>
using namespace std;

class UseLess {
  private:
    int n;
    char *pc;
    static int ct;
    void ShowObject() const;

  public:
    UseLess();
    explicit UseLess(int k);
    UseLess(int k, char ch);
    UseLess(const UseLess &f);
    UseLess(UseLess &&f);
    ~UseLess();
    UseLess operator+(const UseLess &f) const;
    void ShowData() const;
};

int UseLess::ct = 0;

UseLess::UseLess() {
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "默认的构造函数被调用,对象的个数:" << ct << endl;
    ShowObject();
}

UseLess::UseLess(int k) : n(k) {
    ++ct;
    cout << "int类型入参的构造函数被调用，对象的个数:" << ct << endl;
    pc = new char[n];
    ShowObject();
}

UseLess::UseLess(int k, char ch) : n(k) {
    ++ct;
    cout << "int,char 类型的入参构造函数被调用，对象的个数：" << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

UseLess::UseLess(const UseLess &f) : n(f.n) { // 拷贝构造函数
    ++ct;
    cout << "拷贝构造函数被调用,对象的个数：" << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

UseLess::UseLess(UseLess &&f) : n(f.n) { // 移动构造函数
    // 移动构造函数一般都会被g++编译器优化掉，为了看出效果，需要在g++编译时加上
    // -fno-elide-constructors 编译选项
    ++ct;
    cout << "移动构造函数被调用，对象的个数：" << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    ShowObject();
}

UseLess::~UseLess() {
    cout << "析构函数被调用，对象的个数:" << --ct << endl;
    cout << "销毁对象:\n";
    ShowObject();
    delete[] pc;
}

UseLess UseLess::operator+(const UseLess &f) const {
    cout << "调用+运算符重载函数\n";
    UseLess temp = UseLess(
        n + f.n); // 注意这里是两个操作对象的n的和，也就是temp的数组长度增加了
    for (int i = 0; i < n; i++) // 第一个因子的n对应的数组
        temp.pc[i] = pc[i];
    for (int i = n; i < temp.n; i++) // 第二个因子f.n对应的长度
        temp.pc[i] = f.pc[i - n];
    cout << "临时对象temp:\n";
    cout << "+运算符函数调用完毕\n";
    return temp; // 注意这里返回的是临时对象temp
}

void UseLess::ShowObject() const {
    cout << "数组元素个数：" << n;
    cout << "数组地址:" << (void *)pc << endl;
}

void UseLess::ShowData() const {
    if (n == 0)
        cout << "(空对象)";
    else {
        for (int i = 0; i < n; i++)
            cout << pc[i];
    }
    cout << endl;
}

int main() {
    {
        UseLess one(10, 'x');   // 会调用int,char入参类型的构造函数
        UseLess two = one;      // 会调用拷贝构造函数
        UseLess three(20, 'o'); // 会调用int,char入参类型的构造函数
        UseLess four(one + three); // 会调用operator + 运算符重载函数
        cout << "Object one:";
        one.ShowData();
        cout << "Object two:";
        two.ShowData();
        cout << "Object three:";
        three.ShowData();
        cout << "Object four:";
        four.ShowData();
    }
    cout << "回到main\n";
}