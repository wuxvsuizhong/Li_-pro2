#include<iostream>
#include<hash_set>//哈希
#include<hash_map>
#include<algorithm>

using namespace std;
using namespace __gnu_cxx;  //hash_map和hash_set是声明在__gnu_cxx命名空间里的
int main()
{
	hash_set<int> hs;
	hs.insert(11);
	hs.insert(23);
	hs.insert(34);
	hs.insert(35);
	hs.insert(62);
	auto ib=hs.begin();
	auto ie=hs.end();

	for(;ib!=ie;ib++){
		cout<<(*ib)<<endl;
	}

	auto pfind = hs.find(24);//查找算法
	if(pfind == ie)
		cout<<"not found"<<endl;
	else 
		cout<<(*pfind)<<endl;

	hash_map<int,const char *> hsmap;
	hsmap.insert(pair<int,const char *>(10,"first"));//以pair的形式插入
	hsmap.insert(pair<int,const char *>(13,"second"));
	hsmap.insert(pair<int,const char *>(16,"third"));
	hsmap.insert(pair<int,const char *>(1,"torth"));
	hsmap.insert(pair<int,const char *>(10,"first"));//相同的键值不会插入成功
	auto hmb = hsmap.begin();//迭代器是pair类型
	auto hme = hsmap.end();
	for(;hmb!=hme;hmb++){
		cout<<(*hmb).first<<"\t"<<(*hmb).second<<endl;
	}		
	auto tofind = hsmap.find(17);
	if(tofind == hme){
		cout<<"not found"<<endl;
	}
	else
		cout<<(*tofind).first<<"\t"<<(*tofind).second<<endl;
	

	return 0;
}
