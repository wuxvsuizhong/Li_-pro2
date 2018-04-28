#include<set>
#include<bitset>
#include<iostream>
using namespace std;

int main()
{
	bitset<8>bs(215);//215是构造的数据
	for(int i=0;i<8;i++){
		cout<<bs[i];//存储的顺序是反的

	}
	cout<<endl;

	for(int i=7;i>=0;i--){
		cout<<bs[i];
	}
	cout<<endl;

	/*2进制数据取反*/
	cout<<"2进制取反"<<endl;
	for(int i =0;i<8;i++){
		cout<<~bs[i];//取反
	}
	string str = bs.to_string();
	cout<<"转化成字符串"<<endl;
	cout<<str<<endl;

	cout<<"设置第一位和第7位为0"<<endl;
	bs.set(0,0);
	bs.set(7,0);
	for(int i=7;i>=0;i--){
		cout<<bs[i];
	}
	cout<<endl;
	cout<<"bs.size()"<<bs.size()<<endl;
	//cout<<"bs.reset()"<<bs.reset()<<endl;//全部清零
	cout<<"测试是否越界:"<<bs.none()<<endl;//测试是否越界


	return 0;
}
