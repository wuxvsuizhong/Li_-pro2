#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<set>
using namespace std;

template<typename T>
class show
{
public:
	void operator()(const T& t)
	{
		cout<<t<<endl;
	}	
};


int main()
{
	vector<int> myv;
	myv.push_back(1);
	myv.push_back(3);
	myv.push_back(21);
	myv.push_back(7);
	myv.push_back(100);
	myv.push_back(9);

	for_each(myv.begin(),myv.end(),[](int v){cout<<v<<endl;});
	cout<<"find_if >4 -->";	
	auto i = find_if(myv.begin(),myv.end(),[](int v)->bool{return v>4;});
	//返回第一个值为大于4的元素
	if(i == myv.end()){	cout<<"not find"<<endl;	}
	else{cout<<*i<<endl;}//

	cout<<"find_if_not >4 -->";
	auto i2 = find_if_not(myv.begin(),myv.end(),[](int v)->bool{return v>4;});
	//返回第一个值不大于4的元素
	if(i2 == myv.end()){	cout<<"not find"<<endl;	}
	else{cout<<*i2<<endl;}

	random_shuffle(myv.begin(),myv.end());//把顺序打
	for_each(myv.begin(),myv.end(),[](int v){cout<<v<<endl;});
	
	list<int> list1;
	list1.push_back(12);
	list1.push_back(121);
	list1.push_back(10);
	list1.push_back(1);
	list1.push_back(3);

//	sort(list1.begin(),list1.end());//排序,list不能支持
	sort(myv.begin(),myv.end());

	fill(myv.begin()+2,myv.end(),10);//指定界限内的数据填充为10,list不支持
	cout<<"list1-->"<<endl;
	for_each(list1.begin(),list1.end(),show<int>());
	cout<<"myv-->"<<endl;
	for_each(myv.begin(),myv.end(),show<int>());

	multiset<int> myset;
	myset.insert(3);
	myset.insert(1);
	myset.insert(11);
	myset.insert(39);
	myset.insert(100);
	myset.insert(99);
	myset.insert(3);
	myset.insert(39);
	myset.insert(11);
	myset.insert(99);
	myset.insert(11);

	cout<<"myset-->"<<endl;
	for_each(myset.begin(),myset.end(),[](int n){cout<<n<<endl;});
	
	int ii=0;
	for(auto ib=myset.begin(),ie = myset.end();ib!=ie;ib++,ii++){
		cout<<"set的节点个数为"<<ii<<endl;
	}

	int num = count(myset.begin(),myset.end(),11);//统计值相应的树节点数量
	cout<<"myset 中值为11的节点有"<<num<<"个"<<endl;

	auto it = adjacent_find(myset.begin(),myset.end());
	cout<<*it<<endl;
	it++;
	cout<<*it<<endl;
	it++;
	cout<<*it<<endl;
	it++;
	it++;
	cout<<*it<<endl;
	cout<<*it<<endl;
	it = adjacent_find(it,myset.end());//从制定范围查找相同的数据
	cout<<*it<<endl;
	it++;
	cout<<*it<<endl;

	


	return 0;
}
