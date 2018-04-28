#include<iostream>
#include<set>
using namespace std;
struct student
{
	int id;
	char name[30];
};

struct stuless
{
	bool operator()(const student &s1,const student &s2)
	{
		return s1.id < s2.id;
	}
};

//mutiset每一个节点又是一个链表,set的每一个节点仅仅是一个节点
int main()
{
	student sarray[3] = {	{11,"first"},
							{2,"second"},
							{35,"third"}
						};
	multiset<student,stuless>myset(sarray,sarray+3,stuless());
	student st1 = {15,"add"};
	myset.insert(st1);
	myset.insert(st1);
	myset.insert(st1);//mutiset可以重复插入
	auto ib = myset.begin();
	auto ie = myset.end();
	for(;ib!=ie;ib++){
		cout<<(*ib).id<<"\t"<<(*ib).name<<endl;
	}



	return 0;
}
