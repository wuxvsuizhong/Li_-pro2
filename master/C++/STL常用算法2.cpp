#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isok(int num)
{
//	return num == 5;//只把5提出来分开
	return num <= 5;//把小于等于5的都提出来分开
//	return num > 5;//把大于5的提出来分开
}

int main()
{
	vector<int> v1;
	for(int i = 0;i<10;i++){
		v1.push_back(i);
	}
	random_shuffle(v1.begin(),v1.end());//打乱顺序
	for_each(v1.begin(),v1.end(),[](int n) {cout<<n<<"\t";});
	cout<<endl;

	partition(v1.begin(),v1.end(),isok);//分块，服务于快排,在指定范围内根据isok的内部条件进行分块
	for_each(v1.begin(),v1.end(),[](int n){cout<<n<<"\t";});
	cout<<endl;

	partial_sort(v1.begin()+2,v1.begin()+4,v1.end());//排序后，v1.begin()到v1.begin()+2之间的元素是最小有序的，且是递增的，且都小于v1.begin()+2位置之后的元素的值
	for_each(v1.begin(),v1.end(),[](int n){cout<<n<<"\t";});
	cout<<endl;

	cout<<"rotate(v1.begin(),v1.begin()+3,v1.end())-->"<<endl;
	rotate(v1.begin(),v1.begin()+3,v1.end());//旋转，指定范围内的值与其后方的值旋转
	for_each(v1.begin(),v1.end(),[](int n){cout<<n<<"\t";});
	cout<<endl;
/*
	int a[5] = {11,1,23,2,54};
	do
	{
		for(int i=0;i<(sizeof(a)/sizeof(int));i++){
			cout<<a[i]<<"\t";
		}
		cout<<endl;
	}while(prev_permutation(a,a+sizeof(a)/sizeof(int)));//排序
*/
	return 0;
}
