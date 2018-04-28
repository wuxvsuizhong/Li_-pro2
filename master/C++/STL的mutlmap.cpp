#include<iostream>
#include<map>

using namespace std;

//map和mutimap的区别是map的每一个节点是一个映射，mutimapd的每一个节点是链表
int main()
{
	map<const char *,int> mymap;
	mymap.insert(pair<const char *,int>("键值1",12));
	mymap.insert(pair<const char *,int>("键值2",23));
	mymap.insert(pair<const char *,int>("键值3",45));
	mymap.insert(pair<const char *,int>("键值4",21));
	mymap.insert(pair<const char *,int>("键值5",47));
	mymap.insert(pair<const char *,int>("键值5",48));//相同的键值，插入会失败
	mymap["键值5"] = 50;//相同的键值会覆盖
	map<const char*,int>::iterator ib = mymap.begin();
	auto ie = mymap.end();
	for(;ib!=ie;ib++){
		cout<<(*ib).first<<"\t"<<(*ib).second<<endl;
	}

	multimap<const char *,int> mumap;
	mumap.insert(pair<const char *,int>("键值1",12));
	mumap.insert(pair<const char *,int>("键值2",23));
	mumap.insert(pair<const char *,int>("键值3",45));
	mumap.insert(pair<const char *,int>("键值4",21));
	mumap.insert(pair<const char *,int>("键值5",47));
	mumap.insert(pair<const char *,int>("键值5",48));//相同的键值会插入成功
	auto mb = mumap.begin();
	auto me = mumap.end();
	for(;mb!=me;mb++){
		cout<<(*mb).first<<"\t"<<(*mb).second<<endl;
	}

	return 0;
}
