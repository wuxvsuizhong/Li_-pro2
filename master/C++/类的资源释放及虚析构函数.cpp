#include<iostream>

class fu
{
public:
	fu()
	{
		std::cout<<"fu create\n";
	}
#if 0
	virtual ~fu()//父类的析构函数如果不是虚函数，在使用父类指针应用生成子类后，子类析构不会调用父类的析构函数，造成内存泄露
	{
		std::cout<<"fu destroy\n";
	}
#endif
	~fu()
	{
		std::cout<<"fu destroy\n";
	}

};

class zi:public fu
{
public:
	zi()
	{
		std::cout<<"zi creatr\n";
	}
	~zi()
	{
		std::cout<<"zi destory\n";
	}
};

int main()
{
#if 0
	fu *p = new zi;//使用父类的指针指向子类时，如果父类的析构函数不是虚函数，那么在子类析构后不会调用父类的析构
	delete p;
#endif

	zi *p = static_cast<zi *>(new fu);
	delete p;//会调用到子类的析构函数，但是new出的对象无子类数据成员实体，所以如果子类的析构函数中有操作子类的成员变量的时候会发生访问越界


	return 0;
}
		

