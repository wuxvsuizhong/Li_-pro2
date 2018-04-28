//final和override关键字针对virtual函数
//当在基类中的成员函数被final关键字修饰以后，拒绝重载，在子类中也无法被重写
//override
#include<iostream>

class ye
{
public:
	virtual void print() final
	{
		std::cout<<"爷爷\n";
	}
	virtual void run()
	{
		std::cout<<"yr run()\n";
	}
};

class ba:public ye
{
public:
	void print()
	{
		std::cout<<"爸爸\n";
	}


};

int main()
{
	
	
	
	return 0;
}
