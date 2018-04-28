#include<iostream>
#include<typeinfo>

class A
{
public:
	void go()
	{
		std::cout<<"A::go()"<<std::endl;
	}
};

class B:public A
{
public:	
	void go()
	{
		std::cout<<"B::go()"<<std::endl;
	}		
};

class C:public A
{
	void go()
	{
		std::cout<<"C::go()"<<std::endl;
	}
};	

void test_func(A* a)
{
	a->go();
	std::cout<<typeid(*a).name()<<std::endl;
	A *pc;
	B *pb;
#if 0
	if(pb = dynamic_cast<B*>(a))
	{
		std::cout<<"coming is B";
	}
	if(pc = dynamic_cast<C*>(a))
	{
		std::cout<<"coming is A";
	}
#endif
}


int main()
{
	A* p1= new B;
	A* p2= new C;
	test_func(p1);	
	test_func(p2);	
	p1->go();
	p2->go();

	return 0;
}
