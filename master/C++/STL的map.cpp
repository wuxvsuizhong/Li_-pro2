#include<iostream>
#include<map>

using namespace std;

struct stu
{
	int age;
	char name[30];
};

struct stuinfo
{
	int id;
	stu s;
};

int main()
{
	map<const char *,int> mymap;
	mymap["first"] = 1;//map映射赋值，类似与python中的字典
	mymap["second"] = 3;
	mymap["third"] = 4;
	mymap["forth"] = 73;
	mymap["fifth"] = 63;
	cout<<mymap["first"]<<endl;

	map<int,const char *> mymap2;
	mymap2[1] = "first";
	mymap2[2] = "second";
	mymap2[3] = "third";
	cout<<mymap2[3]<<endl;

	stuinfo info[3] = { {1,{21,"first"}},
				   {2,{24,"second"}},
				   {3,{31,"thord"}}
				 };

	map<int,stu> stumap;
	for(int i=0;i<3;i++){
		stumap[info[i].id] = info[i].s;
	}
	stu ss = {23,"forth"};
	stumap[4] = ss;
	auto sb = stumap.begin();//迭代器返回的是pair类型
	auto se = stumap.end();
	for(;sb!=se;sb++){
		cout<<(*sb).first<<"\t"<<(*sb).second.age<<"\t"
			<<(*sb).second.name<<endl;
	}


	return 0;
}

