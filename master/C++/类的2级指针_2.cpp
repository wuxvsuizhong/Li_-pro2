#include<iostream>

class demo
{
private:
	int num1;
	int num2;
public:
	demo(int n1=0,int n2=0):num1(n1),num2(n2)
	{}
	~demo()
	{}
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



demo d1(111,222);
demo d2(1111,2222);

void change1(demo **pp)//副本形参pp为2级指针
{
	*pp = &d2;
}

void change2(demo * &p)//副本形参为指针引用，其实就是一个一级指针
{
	p = &d1;  //把传进来的指针p修改指向d1
}


int maina()
{
	demo *p = &d1;
	p->showdetail();

	change1(&p);//传递类型为2级指针
	p->showdetail();

	change2(p);
	p->showdetail();//传递指针，传递过程时为引用类型



		
	return 0;
		
}