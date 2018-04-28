#include<iostream>

template <typename T>
class myclass
{
private:
	static int data;//静态的私有变量只能通过类的静态函数访问
public:
	static int num;
	T a;
	myclass(T t):a(t)
	{
		num++;
		data++;
	}

	static int getdata()
	{
		return data;
	}
};

template <typename T> int myclass<T>::num = 0;//类模版静态成员初始化
template <typename T> int myclass<T>::data = 0;

int main()
{
	myclass<std::string> m1("test");//只创建了一个string类型的变量。static变量为1
	myclass<double> m2(10.1);
	myclass<double> m3(11.1);//double 类型创建了两个实例，对应的static变量为2
	std::cout<<m1.num<<"\t"<<m2.num<<std::endl;
	std::cout<<myclass<double>::num<<std::endl;//访问某个类型的静态公有成员，同上
	std::cout<<&m1.num<<"\t"<<&m2.num<<std::endl;//静态变量在类模版中并不是只存在一个，静态类会根据送的类型为该类型生成一个static变量
	//类型相同的共享一个变量，类型不同的不共享静态变量
//	std::cout<<m1.data<<std:endl;//私有静态变量，不能直接访问:
//	std::cout<<myclass<double>::data<<std::endl;//同上
	std::cout<<m2.getdata()<<std::endl;
	std::cout<<m3.getdata()<<std::endl;
	return 0;

}
