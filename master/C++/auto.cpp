#include <iostream>
#include <cstdarg>
#include <typeinfo>

using namespace std;

template<typename T>
T MAX(T* t,const int n)
{
	//    T maxdata = t[0];
    T maxdata(t[0]);
    for (int i=1;i<n;i++)
    {
        if(maxdata < t[i])
	            maxdata = t[i];
    }
    return maxdata;
}

template<class NT>
NT sum(int count,NT data1,...)//"..."为可变参数（n个）
{
    va_list arg_ptr;//参数列表的指针
    va_start(arg_ptr,count);//限定从arg_ptr开始，限定多少个参数
    NT sumres(0);
//    cout<<typeid(NT).name()<<endl;
    for(int i=0;i<count;i++)
    {
	    sumres += va_arg(arg_ptr,NT);
	}
	va_end(arg_ptr);//结束
	return sumres;

}


int main()
{
	int n[10]={1,2,23,24,56,78,99,45645,2325,2342536};
	double d[10]={1,23,1.01,34.9,2352.0,14233.0,1234.5,78.0,564,4564.7};
	cout<<MAX(n,10)<<endl;
	cout<<MAX(d,10)<<endl;
	cout<<sum(6,1.0,2.0,3.0,4.0,5.0,6.0)<<endl;
	cout<<sum(3,1,2,3)<<endl;
	return 0;
}

