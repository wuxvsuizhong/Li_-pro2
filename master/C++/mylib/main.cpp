#include "mylib.h"
#include <iostream>
#include <stdio.h>

int main() {
  printf("%d\n", max(23, 45));
  std::cout << min(11, 20) << std::endl;
  return 0;
}

// cpp使用c文件的编译步骤
/*
1.先用gcc把.c编译为.o  如 gcc -c mylib.c mylib.o
2.再用g++把.cpp 和 上一步编译的.o一起编译 如 g++ main.cpp mylib.o -o main.exe
 */