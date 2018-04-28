#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int yu=0;
	int num;
	cin>>num;
	stack<int> mystack;
	while(1){
		yu = num%2;
		num/=2;
		if(yu==0 && num == 0)
			break;
		mystack.push(yu);
	}
	while(!mystack.empty()){
		cout<<mystack.top();
		mystack.pop();
	}
	cout<<endl;
	return 0;
}
