问：makefile文件怎么用?
答：在命令行中使用 make src=.\3维数组.c DEBUG=1 可以单独编译某个c文件，如果去掉DEBUG=1 直接使用make src=.\3维数组.c 那么不生成调试信息，也就是不能使用gdb调试。
    如果直接使用make命令，会把makefile所在的文件夹下的所有的每个.c文件都编译为相应的exe文件.
