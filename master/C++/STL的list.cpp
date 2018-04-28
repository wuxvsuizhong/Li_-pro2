#include<iostream>
#include<list>
#include<stdio.h>
//list容器使用于经常插入和删除的场合
using namespace std;
int main()
{
/*
	list<int> mylist;
	mylist.push_back(11);
	mylist.push_back(12);
	mylist.push_back(13);
	mylist.push_back(14);
	mylist.push_back(15);
	mylist.push_back(16);
	//第一种初始化方式
*/
	int a[6] = {1,2,3,4,5,6};
	list<int> mylist(a,a+6);
	mylist.push_front(111);//头部插入
	mylist.insert(mylist.begin(),300);//用迭代器在制定位置插入
	//第二种初始化方式
	auto ib = mylist.begin();
	auto ie = mylist.end();

	/*使用迭代器访问*/
	for(;ib!=ie;ib++){
		cout<<(*ib)<<endl;
		printf("%p\n",ib);
	}
	cout<<"erase mylist.begin()"<<endl;
	mylist.erase(mylist.begin());
//	mylist.erase(mylist.begin()+1);//list的erase方法不支持迭代器+操作，但是可以支持迭代器++
	cout<<"erase mylist.begin()++"<<endl;
	mylist.erase(mylist.begin()++);
	mylist.remove(6);//根据元素的值来删除
	
	ib = mylist.begin();
	ie = mylist.end();
	cout<<"(*ie)"<<endl;
	//cout<<(*ie);//迭代器的最后一个不再数据数据容器范围内，指向的是一个不确定的值
	for(;ib!=ie;ib++){
		cout<<(*ib)<<endl;
		printf("%p\n",ib);
//		erase(i);//list为链式存储，不允许直接的下标访问,只能用迭代器++或--访问
	}
	
	auto rib = mylist.rbegin();
	auto rie = mylist.rend();
	cout<<"逆序迭代:"<<endl;	
	for(;rib!=rie;rib++){
		cout<<(*rib)<<endl;
	}

	/*同其他容器的删除或插入操作一样，删除或者插入一个数据后。迭代器的end或begin会发生变化需意注意*/


	int b[6] = {11,22,66,44,55,11};
	list<int> mylist2(b,b+6);
//	mylist2.sort();//排序
	mylist2.unique();//去重之前进行排序才有效果
	mylist.merge(mylist2);
	{
		auto rib = mylist.rbegin();
		auto rie = mylist.rend();
		cout<<"列表合并:"<<endl;	
		for(;rib!=rie;rib++){
			cout<<(*rib)<<endl;
		}
	}
	



	return 0;
}
