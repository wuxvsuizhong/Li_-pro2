#include<iostream>

template<class T>
class com
{
public:
	T a;
	T b;
	T add()
	{
		return a+b;
	}
};


int main()
{
	com<int> c1;
	c1.a = 10;
	c1.b = 21;
	std::cout<<c1.add()<<std::endl;
	
	com<double> c2;
	c2.a = 10;
	c2.b = 11.1;
	std::cout<<c2.add()<<std::endl;


	return 0;
}

