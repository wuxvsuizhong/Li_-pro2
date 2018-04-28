#include<iostream>
#include<string.h>
#include<set>//红黑树

using namespace std;

struct strless
{
	bool operator ()(const char *str1,const char *str2)
	{
		return strcmp(str1,str2)<0;
	}
};

void setstrcmp()
{
//	set<char *,strless> myset(strless());//默认构造
	const char *cmd[] = {"abc","calc","notepad","cnost","xyz"};
	set<const char *,strless> myset(cmd,cmd+5,strless());//构造
	myset.insert("1234");
	myset.insert("4567");

	//pair起到获取插入值，第一个类型，类型比对大小的方式
	pair<set<const char *>::iterator,bool> p = myset.insert("9876");
	cout<<"pair start"<<endl;
	cout<<*(p.first)<<"\t"<<p.second<<endl;//pair以迭代器的方式访问
	cout<<"pair over"<<endl;

	auto ib = myset.begin();
	auto ie = myset.end();
	for(;ib!=ie;ib++){
		cout<<*ib<<endl;
	}
	
	auto rb = myset.begin();
	auto re = myset.end();
	for(;rb!=re;rb++){
		cout<<*rb<<endl;
	}

	set<const char *,strless>::iterator pfind = myset.find("xyz");//查找
	cout<<"\n"<<*pfind<<endl;
}


int main()
{
	set<int>myset;
	myset.insert(10);//set会自动排序
	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	myset.insert(4);
	myset.insert(5);
	myset.insert(6);
	myset.insert(7);
//	myset.insert(1);//set重复的会被舍弃
	auto ib = myset.begin();
	auto ie = myset.end();
	for(;ib!=ie;ib++){
		cout<<*ib<<endl;//按照数值大小顺序输出
	}
	auto findpos = myset.find(10);
	cout<<"find->>"<<*findpos<<"\n";
	cout<<myset.size()<<"\n";

	setstrcmp();

	return 0;
}
