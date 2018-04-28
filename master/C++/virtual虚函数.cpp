#include<iostream>

class fu
{
public:
	virtual void name()
	{
		std::cout<<"父类\n";
	}
	void go()
	{
	}
	virtual ~fu()
	{}
};

class zi:public fu 
{
public:
#if 0
	virtual void name(int n)
	{
		std::cout<<"子类\n";//要使得虚特性能够延续，函数的名，返回和参数必须是相同的，否则虚特性丢失
	}
#endif
	virtual void name()
	{
		std::cout<<"子类\n";
	}

};

class sun:public zi
{
public:
	virtual void name()
	{
		std::cout<<"孙类\n";
	}

};


int main()
{
#if 0
	fu *pfu = new fu;
	pfu->name();
	zi* pzi = new zi;
	pzi->name();
	sun* psun =  new sun;
	psun->name();
#endif
	fu *p1 = new fu;
	fu *p2 = new zi;
	fu *p3 = new sun;
	p1->name();
	p2->name();
	p3->name();
	std::cout<<"sizof(*p1)"<<sizeof(*p1)<<"\n";
	std::cout<<"sizof(*p2)"<<sizeof(*p2)<<"\n";
	std::cout<<"sizof(*p3)"<<sizeof(*p3)<<"\n";//1个或者多个虚函数都占据4字节，因为无论多少个虚函数，都由一个虚函数表的指针指向
	
	fu fu2;
	std::cout<<"sizof(fu2)"<<sizeof(fu2)<<"\n";
		
	return 0;
}
