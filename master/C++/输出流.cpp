#include<iostream>
#include<iomanip>//控制输出流
using namespace std;
#define level1 0
#define level2 0
#define level3 0
#define level4 1


int main()
{
#if level1
	cout.put('A').put('B').put('C').put('\n');//put输出单个字符
	char str[]="124134xdfbfxgn shsgh345";
	cout.write(str,10);//10限制最大输出长度，不包含\0
	cout<<"\n";
	
	int num= 01070;
	cout<<num;//默认按照10进制输出
	cout<<hex;//16进制的强制表示，endl无法结束
	cout<<num<<endl;
	cout<<oct;//8进制的强制标示，endl无法结束
	cout<<num<<endl;

	double db = 2.33331112232342343423;
	cout<<db<<endl;//cout默认显示小数点位数为6位(包含小数点的位数)
	cout<<setprecision(10)<<db;//设置显示精度，显示小数点后的（带小数点）的多少位
	cout<<endl;

	cout.width(20);//设置了输出宽度
//	cout.fill('*');//填充
	cout<<"hello world";//在上一步设置了字符串填充，如果输出不满宽度20位，将前向填充
//	cout.width(20);//
//	cout.fill('*');//上一步设置了填充，填充宽度为20（包含\0）
	cout<<endl;

	cout.width(20);//设置宽度，如果实际的字符串长度小于设定值，将字符串右移动
//	cout.width(4);//如果设置宽度小于实际的字符串长度，按照实际默认（左对齐）输出
	cout.setf(ios::left);
	cout.setf(ios::right,ios::left);//清除左对齐，设置右对齐
	cout<<"hello world";//如果不填充，就以空格填充
#endif

#if level2
	int num;
	cin.setf(ios::hex,ios::basefield);//以16进制读入数据，如果出错转为0
	cin>>num;
//	cout.setf(ios::hex,ios::basefield);//默认以10进制输出，更改设置以16进制输出，
	1cout<<num<<endl;

	int num2;
	cin.setf(ios::dec,ios::basefield);//以10进制读入数据，出错转为0
	cin>>num2;
	cout.setf(ios::dec,ios::basefield);//默认以10进制输出，更改设置以10进制输出，
	cout<<num2<<endl;

	int num3;
	cin.setf(ios::oct,ios::basefield);
	cin>>num3;
//	cout.setf(ios::oct,ios::basefield);//默认以10进制输出，更改设置以8进制输出，
	cout<<num3<<endl;
#endif

#if level3
	double db = 100/7.0;
	cout.setf(ios::fixed|ios::showpoint);//fixe定点的，showpoint显示小数点
	cout<<db<<endl;
	for(int i=0;i<10;i++)
	{
		cout.precision(i);
		cout<<db<<endl;
	}
	//db = 10.12345893400000000000000001;
	cout.setf(ios::scientific,ios::fixed|ios::showpoint);//scientific科学计数法,实数根据方便自动选择指数或者定点小数
	cout<<db<<endl;
#endif

#if level4
	const int num= 8848;
	cout<<setw(10)<<setfill('*')<<setiosflags(ios::left)<<num<<endl;
	cout<<setw(10)<<setfill('*')<<setiosflags(ios::right)<<num<<endl;
	cout<<resetiosflags(ios::right)<<setw(10)<<setbase(8)<<setfill('X')<<num<<endl;
	//resetiosflags清除标志。setw设置宽度，setbase设置基数（进制）


#endif

	cout<<"\n";
	return 0;
}
