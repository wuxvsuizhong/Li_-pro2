/*
对于函数指针而言，取值使用和直接使用是相同的功用
*/

#include<stdio.h>
#include<iostream>
#include<typeinfo>
#define CMODE 0

#if CMODE
int addC(int a,int b)
{
	return a+b;
}

#endif

void add(int a,int b)
{
	std::cout<< (a+b) <<std::endl;
}

class com
{
private:
	int a;
	int b;
public:
	com(int n1,int n2):a(n1),b(n2)
	{}
	int jia(int a,int b)//形参和类成员变量相同,那么类的成员函数可以脱离类实例被调用
	{
		return a+b;
	}

	int jian(int a,int b)
	{
		return a-b;
	}
};


int main()
{
#if CMODE 
	int(*p)(int,int) = addC;
	printf("%d\n",p(1,2));
	printf("%d\n",(*p)(1,2));
	printf("%d\n",(*********p)(1,2));//和*p功能一样
	printf("%p,%p,%p\n",&p,*p,p);
#endif

#if 0
	void (*fp)(int,int) = add;
	fp(1,2);
	(*fp)(1,2);//()括号的结合优先级比*高，如果fp是一个函数指针，那么就必须为p取地址
	(********fp)(1,2);//无论多少的*号,同上句
//	(&fp)fp(1,2);//取地址无法调用
	(*&fp)(1,2);
	std::cout<<(void *)fp<<"\t"<<(void *)(*fp)<<std::endl;
	std::cout<<typeid(fp).name()<<"\n";
	std::cout<<typeid(*fp).name()<<"\n";
	std::cout<<typeid(&fp).name()<<"\n";
#endif
	
	com c1(100,10);
	auto fun1 = &com::jia;
	int(com::*p)(int,int) = &com::jia;
	std::cout<<(c1.*p)(10,30)<<std::endl;
	std::cout<<typeid(p).name()<<std::endl;
	std::cout<<typeid(fun1).name()<<std::endl;
	
	int(com::*fun2[2])(int,int) = {&com::jia,&com::jian};//类成员函数指针数组fun2
	for(int i=0;i<2;i++)
	{
		std::cout<<(c1.*fun2[i])(10,20)<<std::endl;//用c1实例调用
//		std::cout<<(com::*fun2[i])(10,20)<<std::endl;//类成员函数指针直接用类的域名无法调用函数指针，需要用实例对象来调用
		printf("%p\n",fun2[i]);//输出地址
			
	}

	int(com::**funps)(int,int) =fun2;
	for(;funps<fun2+2;funps++)
	{
		std::cout<<(c1.**funps)(10,20)<<std::endl;
//		std::cout<<(com.**funps)(10,20)<<std::endl;//无法调用，需要使用实例对象
		//std::cout<<"地址"<<*funps<<std::endl;//输出地址需要格式化
		printf("%p\n",*funps);//输出地址
	}

	return 0;
}
