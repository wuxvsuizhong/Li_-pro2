/*
通用可变参数模板，处理不限个数的参数，处理不同类型
*/

#include<iostream>


void showall()//空函数,用于结束递归
{

}

//函数可以修改副本的参数传递 T value,Args...args
//函数不可以修改副本和原数据的参数传递 const T value,const Args...args
//可以修改原数据(引用) T &value,Args &...args
//可以引用原数据，但是不可以修改的参数传递const T &value,const Args &...args
template<typename T,typename...Args>
void showall(T value,Args...args)
{
	std::cout<<value<<std::endl;
	showall(args...);//递归继续传递
}

int main()
{
	int num1 = 10,num2 = 9,num3 = 8;
	double db1 = 10.1,db2 = 10.2;
	char str[40] = "一层";
	char ch = 'A';
	showall(num1);
	std::cout<<std::endl;
	showall(num1,num2,num3);
	std::cout<<std::endl;
	showall(db1,db2,num1,ch,str);
	std::cout<<std::endl;


	return 0;
}
