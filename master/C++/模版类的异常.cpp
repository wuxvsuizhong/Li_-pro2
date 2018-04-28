#include<iostream>
using namespace std;

template<typename T>
class Array
{
public:
	Array(int n)
	{
		if(n>0 && n<10)
		{
			throw small(n);
		}
		else if(n >= 10 && n <= 50)
		{
			p = new T[n];
			size = n;
		}
		else if(n > 50)
			throw big(n);
		else
		{
			throw wrong();
		}
	}

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
		int size;
		big(int n):size(n)
		{
					
		}

		void show()
		{
			cout<<"big wrong\t"<<size<<endl;
		}
	};
	
	
	class small:public wrong
	{
	public:
		int size;
		small(int n):size(n)
		{}

		void show()
		{
			cout<<"small wrong\t"<<size<<endl;
		}
	};
protected:
private:
	T *p;
	int size;
};




int main()
{
	try
	{
		//{Array<int> myarr(5);}
		//{Array<int> myarr(11);}
		//{Array<int> myarr(51);}
		{Array<int> myarr(-1);}
	}
	catch(Array<int>::wrong& e)//访问模版异常需要明确类型
	{
		e.show();
	}
	return 0;
}
