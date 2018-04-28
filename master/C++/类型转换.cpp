#include<iostream>


class MyClass
{
private:
	int a;
	int b;
public:
	explicit MyClass(int aa = 0,int bb = 0)
		:a(aa),b(bb)
	{}

	void print()
	{
		std::cout<<a<<"\t"<<b<<std::endl;
	}
	friend class fushu;
};




class fushu
{
public:
	explicit fushu(int num)
	//fushu(int num)
	{
		x = num;
		y = num;
	}
	
	fushu(MyClass m)
	{
		x = m.a;
		y = m.b;
	}

	void print()
	{
		std::cout<<x<<"+"<<y<<"i"<<std::endl;
	}
	
	operator int()//类的类型转换为基本数据类型int,无返回值，类与类之间转换不支持友元函数，只能是成员函数
	{
		return x + y;		
	}

	operator MyClass()//类型转换
	{
		MyClass temp;
		temp.a = x;
		temp.b = y;
		return temp;
	}
protected:
private:
	int x;
	int y;
};



int main()
{
	int num = (int) 10.8;
	fushu f1 = (fushu)10.8;//运用构造函数进行类型转换，用()可以转换构造函数带explicit
	fushu f2  (10.8);//同上句

	int data = f2;
	int data2 (f2);
	int data3 = int(f2);
	int data4 = (int)f2;
	int data5 (int(f2));
	std::cout<<data<<std::endl;
	std::cout<<data2<<std::endl;
	std::cout<<data3<<std::endl;
	std::cout<<data4<<std::endl;
	std::cout<<data5<<std::endl;

	MyClass m1(11,22);

	fushu f3 = m1;
	fushu f4 = static_cast<fushu>(m1);
	f3.print();
	f4.print();

	fushu f5(0);
	MyClass m2(10,20);
	m2 = f5;//使用opertor T()形式的类型的转换函数进行类型转换	
	m2.print();
		


	return 0;
}
