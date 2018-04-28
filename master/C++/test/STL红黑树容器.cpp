#include<iostream>
#include<set>
#include<string.h>
using namespace std;


struct strless
{
	bool operator()(const char *str1,const char* str2)
	{
		return strcmp(str1,str2) < 0;
	}
};



int main()
{
	const char *strs[5] = {"first","second","third","forth","fifth"};
	set<const char *,strless> myset(strs,strs+5,strless());
	pair<set<const char*>::iterator,bool> p = myset.insert("add");
	cout<<*(p.first)<<"\t"<<p.second<<endl;
	
	auto ib = myset.begin();
	auto ie = myset.end();
	for(;ib!=ie;ib++){
		
		cout<<(*ib)<<endl;
	}
	cout<<"-------------\n";
	int nums[]={1,2,3,4,5};
	set<int> mi(nums,nums+5);
	auto bn = mi.begin();
	auto en = mi.end();
	for(;bn!=en;bn++){
		cout<<(*bn)<<endl;
	}
	cout<<"pair\n";
	pair<set<int>::iterator,bool> pn = mi.insert(6);
	cout<<(*pn.first)<<"\t"<<pn.second<<endl;









	return 0;
}
