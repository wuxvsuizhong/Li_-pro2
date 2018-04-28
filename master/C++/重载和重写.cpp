#include<iostream>

class A
{
public:
	void func(int i)
	{
		std::cout<<"i = "<<i<<std::endl;
	}

	int func(int i,int n)
	{
		std::cout<<"i = "<<i<<"n = "<<n<<std::endl;
	}

	virtual void go()
	{
		std::cout<<"A::go()"<<std::endl;
	}
	void run()
	{
		std::cout<<"A::run()"<<std::endl;
	}

};

class B:public A
{
public:
	void func(int i)
	{
		std::cout<<"B::i= "<<i<<std::endl;
	}

	int func(int i,int n)
	{
		std::cout<<"B::i= "<<i<<"B::n = "<<n<<std::endl; 
	}

	int go()
	{
		std::cout<<"B::go()"<<std::endl;
	}

};


int main()
{
	A *b = new B;
	b->func(1);	
	b->func(1,2);
	b->go();
	b->A::go();
	//b->go();
	b->run();
	return 0;
}



