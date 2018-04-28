#include<iostream>

using namespace std;

class box
{
private:
	int len;
public:
	box(int data)
	{
		cout<<"create box"<<endl;
		if(data == 0)
		{
			cout<<"p"<<endl;
			zero z1(21);
			z1.seterrorcode(22);
			throw z1;
		}
		else if(data >0 && data <= 100)
		{
			throw small();
		}
		else if(data > 100 && data <= 10000)
			len = data;
		else if(data > 10000)
			throw big();
		else
			throw wrong();
	}

	const int getValue()
	{
		return len*len*len;
	}

	class small//两种错误的处理方式都接受
	{};
	class zero:public small
	{
	public:
		int errorcode;
		zero(int i):errorcode(i)
		{}
		void seterrorcode(int i)
		{
			errorcode = i;
		}
	
	};
	
	class wrong
	{
	public:
		virtual void show()
		{
			cout<<"wrong"<<endl;
		}
	};

	class big:public wrong
	{
	public:
		void show()
		{
			cout<<"big wrong"<<endl;
		}
	};
};


int main()
{
	try
	{
		//{box b1(0);}
		//{box b1(20);}
		//{box b1(10010);}
		{box b1(-1);}
	}
	catch(box::small)//可以捕获接收small和zero两种类型的异常
	{//如果别处不catch有zero类型的异常，那么zero类型的异常在此处被捕获(zaro继承于small)
		cout<<"太小"<<endl;
	}
	catch(box::zero w)
	{
		if(w.errorcode == 22)
			cout<<"捕获22号错误"<<endl;
		else
			cout<<"非22号错误"<<endl;
	}
	/*catch(box::big& e)
	{
		e.show();
		cout<<"太大"<<endl;
	}*/
	catch(box::wrong& e)//基类中使用虚函数的异常类，会根据throw的类型自动调用到底是基类还是派生类的方法(多态)
	{
		e.show();
		cout<<"异常"<<endl;
	}

	return 0;
}


/*总结：异常的继承中，在基类的catch中可以捕获基类和派生类的异常，如果基类的catch处于派生类的catch的前面，那么派生类的catch也会优先在基类中做出处理，如果派生类有throw但是没有单独的匹配的catch,那么在基类的catch中处理，如果基类和派生类都有catch并且派生类的catch位于基类的前面，那么对于派生类的throw在派生类中处理，总之谁在前，谁优先*/
