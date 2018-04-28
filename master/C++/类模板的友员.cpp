#include<iostream>


//
template <class T> class myclass;
//增加友元函数申明，而申明需要用到模板类所有又要先申明类模板
template <class T>
void print(myclass<T>& m);

template <class T>
class friendclass;

template <class T>
class myclass
{
private:
	T x;
	T y;
public:
	myclass(T t1,T t2):x(t1),y(t2)
	{}

	friend void print<T>(myclass<T>& m);//需要在函数名后加上<>表明他是之前申明的函数模板的实例
	
	friend class friendclass<T>;//申明模板友元类需要加上<T>

	void operator ()(const myclass<T>& t)//实现类模板的()方法，方便函数包装器使用
	{
		std::cout<<"x="<<x+t.x<<"\t"<<"y="<<y+t.y<<std::endl;
	}
	void operator ()(int data)
	{
		std::cout<<"x="<<x+data<<"\t"<<"y="<<y+data<<std::endl;
	}

	friend myclass* operator +(const myclass<T> &m1,const myclass<T> &m2 )
	{
		myclass *p = new myclass(m1.x + m2.x,m1.y + m2.y); 
		return p;
	}

};

template <class T>
void print(myclass<T>& m)
{
	std::cout<<"x="<<m.x<<"\t"<<"y="<<m.y<<std::endl;
}

//函数模板包装器
template <class T,class F>
void run(T t,F func)
{
	func(t);
}

template <class T>
class friendclass
{
public:
	void printA(myclass<T>& m)
	{
		std::cout<<"x="<<m.x<<"\t"<<"y="<<m.y<<std::endl;
	}

};



int main()
{
	myclass<int> m1(11,22);
	print(m1);
	myclass<int> m2(12,13);
	myclass<int> *ps = m1+m2; 
	print(*ps);
	print(*(m1+m2));
	
	run(m1,m1);
	run(m2,m1);

	friendclass<int> f1;
	f1.printA(m1);

	
	return 0;
}
