#include <iostream>

using namespace std;

namespace aaa {

void func()
{
    cout << "in aaa space" <<endl;
}

}

namespace bbb {

void func()
{
    cout << "in bbb space" << endl;
}

}

int main(int argc, char *argv[])
{
//    func();  直接调用 找不到func
    using namespace aaa;
    func(); //调用aaa命令空间的func

    bbb::func();   //调用bbb命名空间的func

    return 0;
}

