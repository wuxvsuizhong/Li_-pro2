#include<iostream>
#include<memory>//auto_ptr和unique_ptr智能指针头文件



int main()
{
	for(int i=0;i<10000000;i++)
	{
		double *p = new double;
		std::auto_ptr<double> autop(p);//将p包装成智能指针,c98版的智能指针

		std::unique_ptr<double> pdb(new double);//c++版智能指针,无需依赖已有指针
	}
	return 0;
}	
