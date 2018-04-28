#include<iostream>

int getdata(int n)
{
	if(n == 1 || n==2)
		return 1;
	else
		return getdata(n-1) + getdata(n-2); 

}





int main()
{
	std::cout<<getdata(40)<<std::endl;	




	return 0;
}
