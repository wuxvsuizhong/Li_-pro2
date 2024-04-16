#include<iostream>
#include<functional>

using namespace std;
using namespace std::placeholders;

//彷函数，引用一个结构体内的函数

struct MyStruct
{
	void fu(int a)
	{
		cout<<a<<endl;
	}

	void fu2(int a,int b)
	{
		cout<<a+b<<endl;
	}
};


int main()
{
	MyStruct s1;
	auto func = bind(&MyStruct::fu,&s1,_1);
	func(100);

	auto func2 = bind(&MyStruct::fu2,&s1,_1,_2);
	//_1，_2为绑定的函数的入参同时占位
	func2(1222,22);

	void(MyStruct::*p)(int a,int b) = &MyStruct::fu2;
//	p(11,12);


/* 使用bind可以实现把目标可执行的函数和参数进行绑定的功能 */


	return 0;
}
