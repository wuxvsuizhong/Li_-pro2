#include<iostream>
#include<vector>//动态数组，位于堆上
#include<array>//静态数组，位于桟上
#include<tuple>
#include<list>//适用于经常插入和删除的场合

using namespace std;

#define DEBUG 1

void listmerge()
{	
	cout<<"链表合并\n";
	int a[5] = {11,33,22,44,55};
	int b[5] = {109,103,103,104,105};
	list<int> l1(a,a+5);
	list<int> l2(b,b+5);
	l1.sort();//排序list
	l1.merge(l2);//合并两个list
	auto ibegin = l1.begin();
	auto iend = l1.end();
	for(;ibegin!=iend;ibegin++){
		cout<<(*ibegin)<<endl;
	}
}

void listunique()
{
	cout<<"链表去重\n";
	int a[6] = {2,4,22,15,22,30};
	list<int> l1(a,a+6);
	l1.sort();
	l1.unique();//链表去重之前需要先排序
	auto ibegin = l1.begin();
	auto iend = l1.end();
	for(;ibegin!=iend;ibegin++){
		cout<<(*ibegin)<<endl;
	}

}



int main()
{
	array<int,5> myarray = {1,2,3,4,5};
	
	vector<int> myvector;
	myvector.push_back(1);

#if DEBUG == 0
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
#else
	int a[5]={1,2,3,4,5};
	list<int> mylist(a,a+5);//用数组对list进行初始化
#endif

	mylist.push_back(99);//起始位置插入
	mylist.push_front(11);//末位插入
/*
	auto i = mylist.begin();
	i++;
	i++;
	mylist.erase(i);//链式存储，不允许用下标访问，只能用迭代器，迭代器可以自增
//	mylist[1];//list无下标
*/
	auto i = mylist.end();//end指向返回的是最后一个元素的后一个指针，要删除最后一个，需要迭代器向前移动
	i--;
	mylist.erase(i);
//	mylist.clear();//清空链表
	auto ibegin = mylist.begin();
	auto iend = mylist.end();
	for(;ibegin!=iend;ibegin++){
		if((*ibegin) == 2){
			mylist.erase(ibegin);//删除一个元素以后，end发生变化,不能再次使用原来的end继续遍历
			break;
		}
		cout<<*ibegin<<endl;
	}
	cout<<"-----------\n";
	{
		auto ibegin = mylist.begin();
		auto iend = mylist.end();
		for(;ibegin!=iend;ibegin++){
			if((*ibegin) == 3){
				mylist.insert(ibegin,300);
				break;//插入新元素后，end发生变化，不能在使用原来的迭代
			}
		}
	}
//	mylist.remove(300);//直接根据元素来删除
	cout<<"============\n";
	{
		auto ibegin = mylist.begin();
		auto iend = mylist.end();
		for(;ibegin!=iend;ibegin++){
			cout<<(*ibegin)<<endl;
		}
	}
	/*逆序访问链表*/
	{
		cout<<"逆序访问\n";
		auto rb = mylist.rbegin();
		auto re = mylist.rend();
		for(;rb!=re;rb++){
			cout<<(*rb)<<endl;
		}
	}
	listmerge();	
	listunique();
	return 0;

}	
