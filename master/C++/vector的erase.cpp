#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> myv;
	for(int i=0;i<10;i++)
	{
		myv.push_back(i);
	}

	vector<int>::iterator it=myv.begin();
	vector<int>::iterator it_front=myv.begin();

	for(;it!=myv.end();it++)
	{
		if(it_front!=myv.begin())	it_front=it--;
		if(*it%2 == 1){
			myv.erase(it);//执行erase后it变得不可访问
			it=it_front;
		}
	}

	it=myv.begin();
	for(;it!= myv.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;


	return 0;
}
