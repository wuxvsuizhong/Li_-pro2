#include<iostream>
#include<string>
using namespace std;
int wrong()
{
	return -1;
}



class wrongClass
{
private:
	int errNo;
public:
	wrongClass(int n):errNo(n)
	{}

	const int& operator()()
	{
		return errNo;
	}
};


class Array
{
private:
	int *p;
	int num;
public:
	Array(int num)
	{
		p = new int[num];
		if(num <= 0)
		{
			throw wrongClass(2); 
		}
		for(int i=0;i<num;i++)
		{
			p[i] = 0;
		}
	}
	~Array()
	{
		delete[] p;
	}

	int& operator[](int i)
	{
		if(i < 0 || i > num)
		{
			throw wrongClass(3);
		}
		return p[i];
	}
};


int main()
{
/*
	int x,y;
	cout<<"请输入数据:";
	while(cin>>x>>y)
	{
		try
		{
			if(y == 0 || y == 0  )
			{
				throw wrong();
			}
			cout<<(x/y)<<endl;
			break;
		}
		catch(int data)
		{
			if(data == -1)
			{
				cout<<"输入数据异常，请重新输入:";
				continue;
			}
		}
	}
*/
	/*类的异常*/
	
	try
	{
		Array myarr(5);
		//Array myarr2(0);//数组初始化异常
		myarr[-1];//数组访问异常
	}
	catch(wrongClass e)
	{
		if(e() == 2)
			cout<<"程序发生异常，数组大小需大于0"<<endl;
		else if(e() == 3)
			cout<<"数组下标越界"<<endl;
	}
	/*
	catch()//可以跟多个catch
	{
	}*/
	
}


