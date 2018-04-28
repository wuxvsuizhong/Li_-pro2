#include<iostream>

template <class T>
class myclass
{
private:
	T x;
public:
	myclass()
	{}
	myclass(const T& t):x(t)
	{}
	void set(const T& t)
	{
		x = t;
	}

	~myclass()
	{
		std::cout<<"myclass 销毁\n";
	}
	void print()
	{
		std::cout<<"x="<<x<<std::endl;
	}
	
	virtual void go()//类模板中的virtual关键字同普通类的功能，一旦函数经过virtual修饰以后，在子类中该函数将会被隐藏，即使采用父类型的指针也只会调起子类的同名方法，不会调起父类的方法
	{
		std::cout<<"myclass go()\n";
	}

	virtual void goa()=0;//模板一旦有纯虚函数，就构成了不能被实例化的模板抽象类(但是可以创建模板抽象类的指针)
};


//类模板继承类模板
template <class T>
class newclass:public myclass<T>
{
private:
	T y;
public:
	newclass()
	{
		
	}

	newclass(const T& t1,const T& t2)
		:myclass<T>::myclass(t1),y(t2)//类模板继承初始化，基类一定要明确类型(即异地那该要是带上 模板类名<T> ::模板类(参数)   形式)
	{
		
	}
	
	~newclass()
	{
		std::cout<<"newclass 销毁\n";
	}
	void set(const T& t1,const T& t2)
	{
		myclass<T>::set(t1);
		this->y = t2;
	}
	void print()
	{
		myclass<T>::print(); 
		std::cout<<"y="<<(this->y)<<std::endl;
	}

	void go()
	{
		std::cout<<"newclass go()\n";
	}
	void goa()//要想子类能够初始化，那么子类就需要实现基类的纯虚函数，否则子类仍然是抽象类
	{}
};

//类模板继承自普通类
class xyz
{
private:
	int x;
	int y;
	int z;
public:
	xyz(int xx,int yy,int zz):x(xx),y(yy),z(zz)
	{
	}

	~xyz()
	{
		std::cout<<"xyz 销毁\n";
	}
	void print()
	{
		std::cout<<"class xyz"<<std::endl<<"x="<<x
			<<"\t"<<"y="<<y<<"\t"<<"z="<<z<<std::endl;
	}




};

template <class T>
class newxyz:public xyz
{
private:
	T a;
public:
	newxyz(const T& t,int xx,int yy,int zz):a(t),xyz(xx,yy,zz)
	{}

	~newxyz()
	{
		std::cout<<"newxyz 销毁\n";
	}
	
	void print()
	{
		std::cout<<"class newxyz"<<std::endl<<"a="<<a<<std::endl;
		xyz::print();
	}
};


//普通类继承自模板类
class xyzrun:public newxyz<int>//普通类继承自模板类需要制定具体类型
{
private:
	int d;
public:
	xyzrun(int dd,int aa,int xx,int yy,int zz)
		:d(dd),newxyz(aa,xx,yy,zz)
	{
		
	}
	~xyzrun()
	{
		std::cout<<"zyxrun 销毁\n";
	}
	void print()
	{
		std::cout<<"class xyzrun"<<std::endl<<"d="<<d<<std::endl;
		newxyz::print();
	}
};




int main()
{
	newclass<std::string> n1;
	n1.set("aaa","bbb");
	n1.print();
	newclass<int> n2(11,22);
	n2.print();

	newxyz<std::string> nx1("xxx",10,11,12);
	nx1.print();
	
	xyzrun xr1(20,21,22,23,24);	
	xr1.print();

	myclass<std::string> *pm1 = new newclass<std::string>("new newclass","newclass a");
	pm1->go();//有virtual修饰，只会调起子类的方法
	
	newclass<std::string> *pnew1= static_cast<newclass<std::string>*>(pm1);
	pnew1->go();//有virtual修饰，只会调起子类的方法

//	myclass<int> m1(111);//语法错误，myclass是纯虚模板类不能实例化
	myclass<int> *pmi = new newclass<int>(111,222);//但是可以使用抽象模板基类的指针
	pmi->print();
	return 0;	
}
