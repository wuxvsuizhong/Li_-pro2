#include<iostream>
#include<fstream>
#include<strings.h>
using namespace std;
#define wenben 0
#define Binary 0
#define Binary2 1
struct S
{
	char *p = "结构体字符串";
	int num=10;
	double db = 11.1;
	char ch = 'c';
};//C++中结构体可以直接初始化赋值

struct SS
{
	char *p;
	int num ;
	double db;
	char ch;
};


int main()
{
#if wenben
	ofstream fout("./wen.txt",ios::out);
	ifstream fin("./wen.txt");//默认是以文本形式写入到文件的
	cout<<sizeof(S)<<endl;

	S s1;
	s1.p = "无拉拉拉拉拉拉拉拉拉拉拉拉拉拉";
	cout<<sizeof(S)<<endl;
	fout<<s1.p<<" "<<s1.num<<" "<<s1.db<<" "<<s1.ch<<"\n";
	fout.close();

	char buf[80]={0};
	fin.getline(buf,sizeof(buf),0)>>buf;//提取字符串，以0作为结束符号
	cout<<buf<<endl;
	fin.close();
#endif

#if Binary
	S s1;
	s1.p ="我额外阿我额外阿我额外阿我额外阿我额外";
	ofstream fout("./wen.bin",ios::binary);
	fout.write((char *)&s1,sizeof(s1));//2进制的方式写，参数为要写到文件的内存的地址和要写入的数据长度
	fout.close();
	ifstream fin("./wen.bin",ios::binary);
	S ss;
	bzero(&ss,sizeof(ss));
	fin.read((char *)&ss,sizeof(ss));//以2进制的方式读,参数为要读到内存的
	cout<<ss.p<<ss.num<<ss.db<<ss.ch<<endl;
	fin.close();
#endif

#if Binary2
	SS ss[3] = {
		"第一个结构体初始化",11,11.1,'a',
		"第二个结构体初始化",22,22.2,'e',
		"第三个结构体初始化",33,33.3,'s'
		};//结构体列表初始化不能和结构体默认值同时使用
	ofstream fout("./二进制数组.bin",ios::binary);
	fout.write((char *)ss,sizeof(ss));
	fout.close();

	ifstream fin("./二进制数组.bin",ios::binary);
	SS ss2[3];
	fin.read((char *)ss2,sizeof(ss2));
	for(int i=0;i<3;i++){
		cout<<ss2[i].p<<"\t"<<ss2[i].num<<"\t"<<ss2[i].db<<"\t"<<ss2[i].ch<<endl;
	}
#endif



	return 0;
}
