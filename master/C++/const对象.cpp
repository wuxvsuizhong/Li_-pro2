#include<iostream>

class area
{
private:
	int x;
	int y;
	mutable int z;
public:
	area():x(10),y(11)
	{

	}

	void print() const
	{
		std::cout<<x<<"\t"<<y<<"\t"<<std::endl;
		z+=11;//mutable变量不受const函数约束
	}		

	void add(int n)
	{
		x+=n;
		y-=n;
	}
	void go()
	{

	}
};


int main()
{
	const area a1;
	a1.print();
//	a1.add();//const对象只能调用const修饰的函数
//	a1.go();//
}
