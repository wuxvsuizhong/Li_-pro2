#include"server.h"
#include<iostream>
using namespace std;

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		cout<<"缺少参数"<<endl;
		exit(1);
	}

	Server s(argv[1]);


	return 0;
}
