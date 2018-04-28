#include<iostream>

class fu
{
public:
int n;
	fu(int data):n(data)
	{
		std::cout<<"fu create\n"<<"n = "<<n<<"\n";
	}
	~fu()
	{
		std::cout<<"fu destory\n";
	}

	void print()
	{
		std::cout<<"fu print()\n";
	}

	void fufu()
	{
		std::cout<<"fu fufu()\n";
	}
};

class zi:public fu
{
public:
int n2;
	zi(int data):fu(data),n2(data)
	{
		
	}
	void print(int a)
	{
		std::cout<<"zi print()\n"<<"n2 ="<<this->n2<<"\n";

	}
	void print()
	{
		std::cout<<"zi print()\n";

	}
	void zizi()
	{
		std::cout<<"zi zizi()\n";
	}
};

int main()
{
#if 0
	fu fu1(1);
	fu1.print();
	fu1.fufu();
#endif

#if 0
	zi *pzi = new zi(1);
	pzi->print();
	pzi->zizi();
#endif
#if 0

	fu *pfu = new fu(1);
	pfu->print();
//	pfu->zizi();
//	pfu->fufu();
//	zi *pzi = dynamic_cast<zi*>(pfu);
	zi *pzi = static_cast<zi*>(pfu);
	pzi->zizi();
	pzi->fufu();
	pzi->print();
#endif

	zi* zi2(nullptr);
	zi2->zizi();//可以执行,对于类中的成员函数如果没有引用内部变量，即使不用实例化也可以调用函数
	zi2->print();//同上
	zi2->fu::print();//同上
	zi2->print(1);//段错误



	return 0;
}
