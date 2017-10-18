#include"client.h"
#include<iostream>

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		std::cout<<"缺少参数(IP或者端口号)!"<<std::endl;
		return -1;
	}
	Client(argv[1],argv[2]);

	return 0;
}
