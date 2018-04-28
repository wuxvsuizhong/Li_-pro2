#include<iostream>
#include<functional>


namespace space
{
	template<class T> using ptr = T*;
}	


int add(int a,int b)
{
	return a+b;
}

typedef int(*ADD)(int,int);//c别名
//using FUNC = int (*)(int a,int b);//C++别名

int main()
{
	ADD p = add;
	std::cout<<p(1,2)<<std::endl;
	//FUNC func = add;
	//std::cout<<func(1,2)<<std::endl;
	
	space::ptr<int> pint(new int(3));
	std::cout<<*pint<<"\t"<<pint<<std::endl;



	return 0;
}
