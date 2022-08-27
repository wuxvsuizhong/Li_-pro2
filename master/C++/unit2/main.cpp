#include <iostream>
#include <stdio.h>

using namespace std;

inline int get_max(int a,int b)
{
    if(a>b)
        return a;

    return b;
}


/******************
1.inline 关键字，定义内联函数
内联函数不作为函数调用，而是直接把内联函数的代码嵌入到调用的语句处；
基于此特点，内联函数使用场景是：那些频繁使用但是到代码量不大的函数可使用内联函数，否则将导致代码大量展开
*******************/
int main1()
{
    for(int i=0;i<100;i++){
        int n = get_max(i,10); //此处使用内联函数get_max 会直接把get_max 的代码嵌入到这里
    }
    return 0;
}

/******************
2.引用和指针
引用就是变量的”别名”，而不是地址
*******************/

void myswap(int &a,int &b)
{
    int temp = a;
    a=b;
    b=temp;

}

int main2()
{
    int a = 5;
    int b = 10;
    myswap(a,b);
    cout << "a=" << a << '\n' << "b=" << b << endl;

//    ------------------
    int &c = a;
//    cout << "c=" << c << end;
    printf("c = %p\na = %p\n",&c,&a);
//    引用’c’的地址和a的地址完全一样
    return 0;
}


/******************
3.缺省参数
*******************/

void func(int a=5,int b=10)
{
    //默认参数必须位于形参列表的后方
    printf("a = %d\n",a);
    printf("b = %d\n",b);
}

void func2(int c,int d=100)
{
    printf("c = %d\n",c);
    printf("d = %d\n",d);
}

int main3()
{
    int num=100;
    func(); //不传递给func参数那么func使用形参默认值5和10
    func(110); // 只传递一个值，那么会修改第一个默认值，
    func(111,110); //传递了所有参数那么修改左右默认值

//    func2(); // func2的形参有一个不是默认参数必须要有传值
    func2(10);   //c=10; d是默认值100
    func2(111,222); //c=111,d=222
}

/******************
4. c++的函数重载
函数的名称可以一样，但是入参类型不同
c++的函数重载是根据入参类型的顺序来的
*******************/
void samename(int a)
{
    printf("%d\n",a);
}

void samename(const char *s)
{
    printf("%s\n",s);
}


//无法重载，即便入参带了const，但是大类型同为int
//void samename2(int n1,const int n2)
//{
//    printf("n1 = %d\n",n1);
//    printf("n2 = %d\n",n2);
//}

//void samename2(const int nn1,int nn2)
//{
//    printf("nn1 = %d\n",nn1);
//    printf("nn2 = %d\n",nn2);
//}

void samename2(int n,const char *s)
{
    printf("n = %d\n",n);
    printf("s = %s\n",s);
}

void samename2(const char *s,int n)
{
    printf("s = %s\n",s);
    printf("n = %d\n",n);
}

//有参和无参可以重载
void samename3(int num)
{
    printf("num = %d\n",num);
}

void samename3()
{
    printf("there is nothing here!\n");
}

//默认参数和无参容易导致二义性，不能重载
void samename4(int n=100)
{
    printf("n = %d\n",n);
}

void samename4()
{
    printf("nothing here!");
}

//参数相同，返回值不同不能重载
//其实参数相同就已经不能重载能，不用再看返回值是否相同
/*
int samename5(int n)
{
    printf("n = %d\n",n);
}

void samename5(int nn)
{
    printf("nothing here, return void!");
}
*/

int main4()
{
    samename(1000);
    samename("hello boy!");

    samename2(1111,"boy hello");
    samename2("hello ya",1002);

    samename3(1010);
    samename3();

//    samename4(); //默认参数和无参导致二义性，重载会失败
    samename4(100);

//    samename5(1000);
}
