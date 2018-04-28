#include<iostream>
#include<boost/scoped_ptr.hpp>
#include<boost/scoped_array.hpp>
#include<boost/shared_ptr.hpp>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	{
		/*scoped_ptr独占型智能指针*/
		cout<<"scoped_ptr-->"<<endl;
		boost::scoped_ptr<int> p(new int);
		*p = 10;
		cout<<*p.get()<<endl;
		p.reset(new int);
		*p.get() = 3;
		cout<<*p.get()<<endl;

		boost::scoped_ptr<int> pa(nullptr);
	//	boost::scoped_ptr<int> pa(p);//语法错误，scoped_ptr为独占内存，不能另外初始化
		//pa = p;//语法错误，scoped_ptr为独占内存，不能另外赋值
	}

	{
		/*scoped_array,独占型数组智能指针*/
		cout<<"scoped_aray-->"<<endl;
		boost::scoped_array<int> p(new int[5]);
		//boost::scoped_array<int> pa(p);//语法错误，不能再赋值
		*p.get() = 1;
		p[3] = 2;
		for(int i =0;i<5;i++) cout<<p[i]<<"\t"<<endl;
		p.reset(new int[5]);

	}
	
	{
		/*shared_ptr,共享指针*/
		vector<boost::shared_ptr<int>> v;
		boost::shared_ptr<int> p1(new int(11));
		boost::shared_ptr<int> p2(new int(12));
		boost::shared_ptr<int> p3(p1);
		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);
		for_each(v.begin(),v.end(),[](boost::shared_ptr<int> p){cout<<*p<<endl;});
		

	}
	return 0;
};

