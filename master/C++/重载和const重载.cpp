#include<iostream>

class A
{
public:
	void go()
	{
		std::cout<<"A--go()\n";
	}
	void go(int n)
	{
		std::cout<<"A--go(int n)\n";
	}
	void go(char *str)
	{
		std::cout<<"a--go(char* str)\n";
	}
};

class B:public A
{
public:
	void go()
	{
		std::cout<<"B--go()\n";		
	}
	void go() const
	{
		std::cout<<"B--go() const\n";		
	}

	void go(int n)
	{
		std::cout<<"B--go(int n)\n";
	}

	void go(char * str)
	{
		std::cout<<"B--gp(char *str)\n";
	}
};


int main()
{
	B *pb = new B;
	pb->go();
	pb->A::go();
	pb->A::go(NULL);//NULL在c++中是一个经过define的0,会调用int
	pb->A::go(nullptr);//nullptr才是c++中的空指针

	const B *ppb = new B;
	ppb->go();//调用const修饰的函数
//	ppb->go(NULL);语法报错，const 限定的对象，调用的成员函数需要const修饰

	return 0;
}
