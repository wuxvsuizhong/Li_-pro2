#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[])
{
	if(argc < 3){
		cout<<"缺少参数!\n";
		exit(1);
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	if(!fin||!fout)//打开文件如果失败
	{
		cout<<"文件打开失败!\n";
		return 0;
	}
	char ch;
	while(fout && fin.get(ch))
	{
		fout.put(ch);
	}
	fin.close();
	fout.close();//关闭文件，起到重置缓冲区,把内存当中的文件刷新到文件中

/********文件追加********/
	ofstream fout2(argv[2],ios::app);//app追加方式打开
	fout2<<"我啊！不是那高尚的人"<<endl;
	fout2.close();
	return 0;
}
