#include<iostream>
#include<fstream>
using namespace std;

#define r 0
#define w 0
#define Binaryr 1
#define Binaryw 0


int main()
{
#if r

	ofstream fout("./p.txt");
	fout<<"1234567890 asdfsdfsddfgsdf#";
	fout.close();

	ifstream fin("./p.txt");
	fin.seekg(3,ios::beg);//定位文件指针，beg为从起始处开始，3为从指定位置偏移的长度
	long size = fin.tellg();//获取当前位置距离文件开头多少个字节
	cout<<size<<endl;
	char ch;
	while(fin.get(ch)){
		cout<<ch;
	}
	cout<<endl;
	fin.close();
#endif

#if w 
	ofstream fout("./px.txt");
	fout<<"1234567890asfasf sdfsfg#";
	fout.close();
	
	ofstream fout2("./px.txt",ios::out|ios::in);
	char str[]="ABCDEFG";
	fout2.seekp(5,ios::beg);//从文件的起始位置向后偏移5个字节处写入
	long size = fout2.tellp();//获取当前位置距离begin有多少个字节
	cout<<size<<endl;
	fout2<<str;
	fout2.close();

	ifstream fin2("./px.txt");
	char ch;
	while(fin2.get(ch)){
		cout<<ch;
	}
	fin2.close();
#endif

#if Binaryr
	ofstream fout("./pb.bin",ios::binary);
	double db[8] = {1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8};
	fout.write((char *)db,sizeof(db));
	fout.close();

	ifstream fin("./pb.bin",ios::binary);
	double *pd = new double[8];
	fin.seekg(int(-4*sizeof(double)),ios::end);
	fin.read((char *)pd,sizeof(double)*4);
	for(int i=0;i<8;i++){
		cout<<pd[i]<<endl;
	}
	fin.close();

	ofstream fout2("./pb.bin",ios::binary|ios::in|ios::out);//指定位置写入，需要读取文件和写入文件所以需要输入输出模式打开
	double dd = 111.1;
	fout2.seekp(int(2*sizeof(double)),ios::beg);
	fout2.write((char *)&dd,sizeof(double));
	fout2.close();

	ifstream fin2("./pb.bin",ios::binary);
	fin2.seekg(0,ios::beg);
	double *pdd = new double[10];
	fin2.read((char *)pdd,sizeof(double)*10);
	cout<<"*******************\n";
	for(int i=0;i<10;i++){
		cout<<pdd[i]<<endl;
	}
	fin2.close();

#endif

	return 0;
}
