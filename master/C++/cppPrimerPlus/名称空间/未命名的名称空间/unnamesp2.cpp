#include <iostream>

// extern int ice;  
// 编译报错，因为ice在另一个文件unnamesp.cpp中是被包含在匿名的namespace中的，无法被其他文件引用到
extern int other();

void modulefunc()
{
  // std::cout<<ice<<std::endl;
  std::cout<<"in another file call unnnamesp func...\n";
  other();
}

