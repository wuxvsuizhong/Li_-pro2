//用final修饰的函数表明该函数不能被重写(函数的返回值，函数名，入参类型都相同)
//用override修饰的函数表明该函数是一个重写函数，如果基类中没有该相同方法，则报错


#include<iostream>

class ye
{
public:
	virtual void print() final//不能被继承的类重写
	{
		std::cout<<"爷爷\n";
	}
	virtual void print(int i)//可以重载
	{
		std::cout<<"i="<<i<<std::endl;
	}

//#if 0

	virtual void runa() 
	{
		std::cout<<"ye runa()\n";
	}
//#endif
};

class ba:public ye
{
public:
#if 0
	void print()//若子类重写基类中的final方法，会报错
	{
		std::cout<<"爸爸\n";
	}
#endif

	void print(int i)
	{
		std::cout<<"ba print(int i)\n";
	}	

	void runa() override//申明该函数是一个重写的函数如果父类中没有该相同的方法，会报错
	{
		std::cout<<"ba runa()\n";
	}
	
	void run()
	{
		std::cout<<"ba run()\n";
	}

};

int main()
{
	ba ba1;
	ba1.print(1);

	return 0;
}
