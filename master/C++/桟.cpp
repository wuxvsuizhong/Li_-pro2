/*利用桟实现把一个数字转换成2进制的形式*/
#include<iostream>
#include<stack>

using namespace std;

int main()
{
	{
		int a[10] = {1,2,3,4,5,6,7,8,9,10};
		stack<int> mystack;
		for(int i=0;i<10;i++){
			mystack.push(a[i]);
		}
		while(!mystack.empty()){
			cout<<mystack.top()<<endl;
			mystack.pop();
		}
	}
	{
		int num;
		cin>>num;
		stack<int> mystack;
		for(;num;num/=2){
			mystack.push(num%2);
			cout<<"当前元素个数"<<mystack.size()<<endl;
		}
		cout<<"输入的数字对应的2进制数为";
		while(!mystack.empty()){
			int num = mystack.top();
			cout<<num;
			mystack.pop();
		}
		cout<<endl;
	}
	return 0;
}
