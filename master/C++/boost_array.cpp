#include<iostream>
#include<string>
#include<boost/array.hpp>

using namespace std;


int main()
{
	boost::array<int ,10> booarr= {1,2,3,4,5,6,7,8,9,10};
	boost::array<int ,10>::iterator ib = booarr.begin();
	boost::array<int ,10>::iterator ie = booarr.end();
	for(;ib!=ie;ib++)
	{
		cout<<*ib<<endl;
	}
	booarr[0] = 10;
	booarr.at(4) = 20;
	int *p = booarr.data();//存储数组的指针
	for(int i=0;i<booarr.size();i++)
	{
		cout<<booarr[i]<<"\t"<<p[i]<<endl;
	}



	return 0;
}
