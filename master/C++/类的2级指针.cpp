#include<iostream>
#include<stdlib.h>
class demo
{
private:
	int num1;
	int num2;
public:
	demo(int n1=0,int n2=0):num1(n1),num2(n2)
	{
		std::cout<<"demo 创建"<<std::endl;		
	}
	~demo()
	{
		std::cout<<"demo 销毁"<<std::endl;
	}
	void showdetail()
	{
		std::cout<<num1<<"\t"<<num2<<"\t"<<std::endl;
	}

};




#if 0
int main()
{
//	demo*p = new demo;
	demo *p(new demo(11,22));
	p->shoetail();

	demo **pp = &p;
	(*pp)->showdetail();//类的一级指针
	(**pp).showdetail();//类的2级指针

	return 0;
}
#endif


#if 0
demo d1(111,222);
demo d2(1111,2222);

void change1(demo **pp)//副本形参pp为2级指针
{
	*pp = &d2;
}

void change2(demo * &p)//副本形参为指针引用
{
	p = &d1;
}

#endif
int main()
{
#if 0
	demo *p = &d1;
	p->showdetail();

	change1(&p);//传递类型为2级指针
	p->showdetail();

	change2(p);
	p->showdetail();//传递指针，传递过程时为引用类型
#endif
	demo *pd = new demo(10,20);
	delete pd;//delete 会调用类的析构函数

	demo *fpd = (demo *)malloc(sizeof(demo));
	free(fpd);//free不会调用析构函数
		
	return 0;
}
