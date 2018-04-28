#include<iostream>
#include<functional>//ref引用那个包装器头文件,



template<class T>
void com(T arg)//函数模板,引用无效,引用包装器
{
	arg++;
}







int main()
{
	int count = 10;
	int & rcount = count;
	com(count);
	std::cout<<count<<std::endl;//10
	
	com(rcount);
	std::cout<<count<<std::endl;//10
		
	com(std::ref(count));//使用ref传递引用类型
	std::cout<<count<<std::endl;//11


	return 0;
}
