#include<iostream>
#include<set>

using namespace std;



int main()
{
	multiset<int> myset;
	myset.insert(100);
	myset.insert(101);
	myset.insert(100);
	myset.insert(103);
	myset.insert(100);

	auto pfind = myset.find(100);
	cout<<*pfind<<endl;
	cout<<"查找所有:"<<endl;
	auto allfind = myset.equal_range(100);
	for(auto it = allfind.first;it!=allfind.second;it++){
		cout<<*it<<endl;
	}

	return 0;
}
