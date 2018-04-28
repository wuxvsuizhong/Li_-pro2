#include<iostream>
#include<fstream>
#define read 0 
#define write 0
#define rw 0 
#define rw2 1 



using namespace std;
int main()
{
#if write 
	ofstream fout;//输出到文件
	fout.open("./1.txt");
	fout<<"昔我往矣,杨柳依依;"<<endl;
	fout<<"今我来思,雨雪霏霏;"<<endl;
	fout<<"行道迟迟, 载渴载饥;"<<endl;
	fout<<"我心伤悲,莫知我哀;"<<endl;

	fout.close();

#endif

#if read
	ifstream fin("./1.txt");//创建读取文件
	/*
	char str1[100] = {0};
	fin>>str1;//读取到内存,遇到空格或者换行终止
	cout<<"读出->"<<str1<<endl;
*/	
	for(int i=0;i<4;i++){
		char str2[50] = {0};
		fin.getline(str2,30);//按照行读取，每一行最多读取30个字节（不会自动加换行）,utf8汉字占据3个字节
		cout<<str2;	//
	}
	fin.close();
#endif

#if rw
	fstream fio("./2.txt",ios::in|ios::out);//读和写模式打开文件,但是文件必须先要存在
	fio<<"昔我往矣,杨柳依依"<<endl;
	fio<<"今我来思,雨雪霏霏;"<<endl;
	fio<<"行道迟迟, 载渴载饥;"<<endl;
	fio<<"我心伤悲,莫知我哀;"<<endl;
//	fio.close();
//	fio.open("./2.txt",ios::in|ios::out);//读和写模式打开文件
	fio.seekg(ios::beg);//beg重新定位文件指针到开头
	for(int i=0;i<4;i++){
		char str[50] = {0};
		fio.getline(str,50);
		cout<<str<<endl;//如果想要成功输出内容，需要重定位文件指针到文件开头
	}
	fio.close();
#endif

#if rw2
	ofstream fout;
	fout.open("./o.txt");
	fout<<"ABC"<<" "<<123<<" "<<'e'<<endl;//" "是为方便提取数据
	fout.close();
	ifstream fin("./o.txt");
	char str[10]={0};
	int num=0;
	char ch = '\0';
	fin>>str>>num>>ch;//提取数据
	cout<<str<<"\t"<<num<<"\t"<<ch<<endl;
#endif
	return 0;
}
