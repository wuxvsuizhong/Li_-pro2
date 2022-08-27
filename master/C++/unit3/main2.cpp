#include <iostream>
#include "man.h"

/**********
 * 类的典型实现
 * ********/



using namespace std;

int main(int argc, char *argv[])
{
    classman m;

//    classman m1("zhangsan");
//    cout << m1.get_name() <<endl;

    classman* m1= new classman("zhangsan");
    cout << m1->get_name() <<endl;
    cout << m1->get_info() <<endl;

    delete m1;
    //new出来的实例必须用delete释放

    return 0;
}
