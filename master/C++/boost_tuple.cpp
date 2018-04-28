#include<iostream>
#include<boost/typeof/typeof.hpp>
#include<boost/tuple/tuple.hpp>
#include<string>
using namespace std;

boost::tuple<int,std::string,char,double> return_group()//返回值类型为一个包含四个数据类型的tuple集合
{
	return boost::make_tuple(1,"12345",'a',23.232);
}


int main()
{
	//BOOST_AUTO(t,boost::make_tuple(1,"12345",'a',23.342));//BOOST_AUTO为boost的自动类型
	BOOST_AUTO(t,return_group());
	cout<<t.get<0>()<<endl;
	cout<<t.get<1>()<<endl;
	cout<<t.get<2>()<<endl;
	cout<<t.get<3>()<<endl;

	return 0;
}
