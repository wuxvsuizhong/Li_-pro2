#include<iostream>

class base
{
public:
	virtual void show()=0;//纯虚函数限定一个类不能实例化

	virtual void show2()=0;//纯虚函数可以没有实现

	void go()
	{
		std::cout<<"base  go()\n";	
	}
	virtual ~base()
	{
			
	}
};

void base::show()
{
	std::cout<<"base show()\n"<<std::endl;
}


base * func(base * p)//抽象类无法实例化，但是指针可以使用，可以作为返回值和入参
{
	base *pbase(nullptr);
	return pbase;
}



class run:public base//继承抽象类的子类必须实现抽象类中的所有纯虚函数
{
public:
	void show()
	{
		std::cout<<"run show()\n";		
	
	}
	void show2()
	{
		std::cout<<"run show2()\n";
	}
};


int main()
{
	
	run r1;
	r1.show();
	r1.go();

	base *pb(nullptr);
	pb = &r1;
	pb->show();
	pb->go();

	return 0;
}
