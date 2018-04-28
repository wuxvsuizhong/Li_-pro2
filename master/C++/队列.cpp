#include<typeinfo>
#include<queue>//队列
#include<deque>//双端队列
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	queue<char *>myq;
	myq.push("first");
	myq.push("second");
	myq.push("third");
	/*for(int i =0 ;i<myq.size();i++){
		cout<<myq[i]<<endl;
	}*/
	/*单端队列没有[]操作*/
	{
		/*单端队列无法用迭代器访问*/
		/*auto ib = myq.begin();
		auto ie = myq.end();
		cout<<"迭代器访问queue"<<endl;
		for(;ib!=ie;ib++){
			cout<<(*ib)<<endl;
		}*/
	}

	while(!myq.empty())
	{
		char *p = myq.front();
		cout<<p<<endl;
		myq.pop();
	}

	deque<int> mydq;
	mydq.push_back(1);
	mydq.push_back(11);
	mydq.push_back(111);
	mydq.push_back(1111);
	mydq.push_back(11111);
	mydq.push_back(12);
	mydq.push_back(122);
	mydq.insert(mydq.begin()+3,100);//使用迭代器在指定位置插入数据
	mydq.erase(mydq.begin());//使用迭代器删除指定位置的数据
	mydq.erase(mydq.end()-1);//删除尾部最后一个数据的时候需要注意迭代器的最后一个指向的是数据范围之外，需要减1

	cout<<"双端队列的最大容量是:"<<mydq.max_size()<<endl;
	cout<<"双端队列的首元素:"<<mydq.front()<<endl;
	cout<<"双端队列的末尾元素："<<mydq.back()<<endl;
	for(int i =0 ;i<mydq.size();i++){
		cout<<mydq[i]<<endl;
	/*用[]访问遍历*/
	}
	cout<<"弹出头部数据"<<endl;	
	mydq.pop_front();
	cout<<"弹出尾部的数据"<<endl;
	mydq.pop_back();
	//mydq.clear();//清空
	/*用迭代器访问*/
	auto ib = mydq.begin();
	auto ie = mydq.end();
	for(;ib!=ie;ib++){
		cout<<(*ib)<<endl;
	}

	deque<int> ide;
	ide.push_back(10);
	ide.push_back(20);
	ide.push_back(30);
	ide.push_back(40);
	cout<<"交换两个队列,mydq成为交换后的值"<<endl;	
	mydq.swap(ide);//交换两个队列
	{
		auto ib = mydq.begin();
		cout<<typeid(ib).name()<<endl;
		auto ie = mydq.end();
		for(;ib!= ie;ib++){
			cout<<(*ib)<<endl;
		}
	}


	return 0;
}
