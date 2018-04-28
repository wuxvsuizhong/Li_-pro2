#include<iostream>

class A
{
public:
	A()
	{
		std::cout<<"create A"<<std::endl;
	}
	virtual ~A()
	{
		std::cout<<"destroy A"<<std::endl;
	}
};

class B:public A
{
public:
	B()
	{
		std::cout<<"create A"<<std::endl;
	}
	~B()
	{
		std::cout<<"destroy B"<<std::endl;
	}
};


int main()
{
	//B b;
	A *pb = new B;
	delete pb;

	return 0;
}



/**
血的教训,如果B从A继承而来，B类型的指针指向B类型的变量，那么没有关系，delete的时候先调用子类的析构，在自动调用父类的析构
但是如果利用多态特性，用A类的指针指向B类的对象，delete这个指针的时候只会调用子类的析构，父类析构不会调用(注意一定要是父类的指针指向子类的情况，不是这种情况的父类的指针仍然会正常自动调用)
**/
