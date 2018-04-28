/*
友元函数可以访问类的私有成员变量和私有成员函数
*/


#include<iostream>


class info
{
public:
	info()
	{
		std::cout<<"构建info"<<std::endl;
	};
	~info()
	{
		std::cout<<"析构info"<<std::endl;
	}
	void func()
	{
		std::cout<<"info public func"<<std::endl;
	}
private:
	void prifunc()
	{
		std::cout<<"info prifunc"<<std::endl;
	}

};








class MyClass
{
private:
	info *pi;
	void go()
	{
		std::cout<<"MyClass private funcfion go()"<<std::endl;	
	}
	void friend ffunc(MyClass* p);
	
};

void ffunc(MyClass *p)
{
	p->pi = new info;//在MyClass中new出info
	p->pi->func();
	p->go();
}


int main()
{
	MyClass c;
	ffunc(&c);
	return 0;
}
