#include<iostream>
using namespace std;
#define GET 0
#define CIN 0
#define GETLINE 1



int main()
{
#if GET
	{
		char buf[80];
		cin.get(buf,80,'x');//x为设置的结束标志符号,只会获取x之前的输入数据,80为获取规定长度
		cout<<buf<<endl;
	}
	{
		char buf[80];
		cin.get(buf,80,'x');//x为设置的结束标志符号,只会获取x之前的输入数据
		cout<<buf<<endl;
	}//第二个块并没有执行,因为get按照指定的字符结束(如果不设置，那么以回车默认作为结束符号)，不会再次获取
#endif

#if CIN
	char buf2[80];
	cin>>buf2;//cin无法获取空格，遇空格就会中止
	cout<<buf2;
#endif

#if GETLINE
	//getline默认换行符号\n结束当前次获取，但是可以设定成其他符号结束当前次的获取
	char buf3[80];
	cin.getline(buf3,80,'x');//逐行读取,当前次只获取x之前的数据,x之后的数据放在下一次获取（与get不同的是get遇到结束标志就结束了获取）
	cout<<buf3<<endl;
	cin.getline(buf3,80,'x');//getline还会2次获取,继续获取上一个结束符号之后的数据
	cout<<buf3<<endl;
	cin.get(buf3,80,'x');//一次性读取，遇到结束
	cout<<buf3<<endl;
//	cin.get(buf3,80,'x');//之前的get一旦获取结束，该句不会被执行
//	cout<<buf3<<endl;


#endif
	return 0;
}
