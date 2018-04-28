#include <iostream>
#include <typeinfo>
#include <map>

using namespace std;

int main()
{
    int int1 = 10;
    double double1 = 99.98;
    char ch = 'A';
    char *str = "hellochina";
    tuple<int,double,char,const char *> mytuple(int1,double1,ch,str);
    auto data0 = std::get<0>(mytuple);
    auto data1 = std::get<1>(mytuple);
    auto data2 = std::get<2>(mytuple);
    auto data3 = std::get<3>(mytuple);
    cout<<typeid(data0).name()<<"\t"<<typeid(data1).name()<<"\t"<<typeid(data2).name()<<"\t"<<typeid(data3).name()<<endl;
	cout<<data0<<"\t"<<data1<<"\t"<<data2<<"\t"<<data3<<endl;
    return 0;
}


