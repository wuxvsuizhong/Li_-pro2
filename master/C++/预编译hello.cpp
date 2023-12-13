#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    cout << "hello!" << endl;
    return 0;
}

// 如下命令预编译cpp文件为另外一个a.cpp
//  g++ -E .\预编译hello.cpp -o a.cpp
// 预编译的结果就是把源文件头上include的.h以及相关的库文件替换为对应的.h或者库文件的实际内容