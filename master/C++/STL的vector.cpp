#include<iostream>
#include<vector>//容器
#include<algorithm>//算法
#include<array>
using namespace std;
//实现一个类模板，专门用于打印
template <typename T>
class myvectorprint
{
public:
	void operator ()(const T &t)//重载()运算符
	{
		cout<<t<<endl;
	}
};


int main()
{
	vector<int> myvector;
	myvector.push_back(11);
	myvector.push_back(21);
	myvector.push_back(31);
	myvector.push_back(41);
	myvector.push_back(51);
	myvectorprint<int >print;//对于打印进行实例化
	array<int,10> myarray = {10,9,8,7,6,5,4,3,2,1};
	for_each(myvector.begin(),myvector.end(),print);
	cout<<"+++++++++++++++++\n";
	for_each(myarray.begin(),myarray.end(),print);
	//for_each为针对元素的访问方法
	/*
	for_each是一个算法，它可以适用于每一种容器
	*/
	
	cout<<"myarray[1] = "<<myarray[1]<<endl;

	return 0;
}
