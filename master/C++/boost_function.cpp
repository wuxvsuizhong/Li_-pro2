#include<boost/function.hpp>
#include<boost/bind.hpp>
#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;
using namespace boost;

int main1()
{
	boost::function<int(char *)> fun = atoi;//int为返回值类型，char *为参数类型,boost::function为atoi做了封装并起了别名fun
	cout<<fun("123")+fun("234")<<endl;
	fun = strlen;//strlen和atoi的入参和返回值类型是同类型的，所以可以仍然用fun代替
	cout<<fun("123")+fun("234")<<endl;
	fun = boost::bind(strcmp,"ABC",_1);//fun封装了一个绑定函数，而这个绑定函数绑定后入参和返回值同上
	cout<<fun("123")<<endl;
	cout<<fun("ABC")<<endl;

	return 0;

}

class manager
{
public:
	void allstart()
	{
		for(int i=0;i<10;i++)
		{
			if(workid)
			{
				workid(i);
			}
		}
	}

	void setcallback(boost::function<void(int)> newid)
	{
		workid = newid;
	}
public:
	boost::function<void(int)> workid;

};

class worker
{
public:
	void run(int toid)
	{
		id = toid;
		cout<<id<<"工作"<<endl;
	}
public:
	int id;
};

int main()
{
	manager m;
	worker w;
	m.setcallback(boost::bind(&worker::run,&w,_1));
	/*boost的绑定的另一个用法就是绑定类的成员函数，基于如果要调用类的成员函数而且成员函数有访问类的成员变量，那么必须由实例化的对象或其指针调用的特性，在绑定类的成员函数时，需要明确指定对象,可以是具体实例化的对象，或者其指针或者引用等，如上例中的&w,这样牺牲了一个放置占位符号的地方用来放置了实例化的对象,占位符则表示发起调用时传递的参数位于哪一个位置*/
	m.allstart();
	return 0;
}
