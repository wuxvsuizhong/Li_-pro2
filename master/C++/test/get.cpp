#include<iostream>

int main()
{
	char buf[10]={0};
	while(1){
		while(std::cin.getline(buf,sizeof(buf)))
			std::cout<<"--"<<buf;
		}
	return 0;

}
