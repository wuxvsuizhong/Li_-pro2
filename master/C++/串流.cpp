#include<iostream>
#include<sstream>//istringstream ostringstream
#include<string>
#include<strstream>
#include<stdlib.h>
#include<string.h>
#define debug 0
#define debug1 0
#define debug2 0
#define debug3 0
#define debug4 1



using namespace std;
struct MyStr
{
	string str1,str2,str3;
	double db;
	int num;
	char ch1;
	char ch2;
};
int main()
{
#if debug
	string mystr("china google zhww 12.1 123 A a");
	MyStr s1;
	istringstream input(mystr);//创建一个字符串扫描流
	input>>s1.str1>>s1.str2>>s1.str3>>s1.db>>s1.num>>s1.ch1>>s1.ch2;
	cout<<s1.str1<<endl;
	cout<<s1.str2<<endl;
	cout<<s1.str3<<endl;
	cout<<s1.db<<endl;
	cout<<s1.num<<endl;
	cout<<s1.ch1<<endl;
	cout<<s1.ch2<<endl;
	cout<<"+++++++++++++++++++++\n";
#endif
#if debug1
//	char str[100]={0};
	ostringstream MYOUT;//构建一个输出流
//	ostringstream MYOUT(str,sizeof(str));//ostringstream无法创建时同时初始化
	char *strr = "s1234f";
	MYOUT<<"a123b"<<123<<23.1<<'g'<<strr<<endl;
	cout<<MYOUT.str();
#endif
	
#if debug2
	char str[100] = {0};
	ostrstream MYOUT(str,sizeof(str));//ostream可以创建时初始化,以str初始化缓冲区
	char str1[50] = "a12312413f";
	MYOUT<<"a123"<<str1<<ends<<'#'<<ends;//ends终止字符串,相当于<<'\0';,ends后的输入不会接收
	cout<<MYOUT.str()<<endl;//endl终止一行并刷新缓冲区,相当于<<'\n'<<fflush;
	cout<<str<<endl;
#endif

#if debug3 
	stringstream mystr2("INIT");
	cout<<mystr2.str()<<endl;
	mystr2.put('X').put('Y');//输出到字符串mystr，会覆盖掉put操作之前的数据
	mystr2<<"ADD";
	cout<<mystr2.str()<<endl;

	string strec = mystr2.str();//定义一个字符串接受值
	char ch;
	mystr2 >> ch;//输出一个字符到ch中，但是不影响原字符串
	cout.put(ch)<<endl;
	cout<<strec<<endl;
#endif

#if debug4
	stringstream mystr;
	char cmd1[30] = {0};
	char cmd2[30] = {0};
	cin.getline(cmd1,sizeof(cmd1)).getline(cmd2,sizeof(cmd2));
	mystr<<cmd1<<"&"<<cmd2;//并行执行cmd1和cmd2(如ls和pstree)
	system(mystr.str().c_str());//转换成c风格

	/*******提取字符串***************/
	char cmdstr1[30]={0};
	char cmdstr2[30]={0};
	char cstr[50]={0};
	strcpy(cstr,mystr.str().c_str());
	for(char *p = cstr;(*p) != '\0';p++ ){
		if(*p == '&'){
			*p = ' ';
		}
	}
	stringstream cmdstrs(cstr);
	cmdstrs>>cmdstr1>>cmdstr2;
	cout<<cmdstr1<<"\t"<<cmdstr2<<endl;
#endif
	return 0;
}

