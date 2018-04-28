#include <iostream>
#include <boost/bind.hpp>//boost绑定bind
#include <string>
#include <vector>
#include <algorithm>
#include <functional>//c++的bind1st

using namespace std;
using namespace boost;

class add:public std::binary_function<int,int,void>//继承于binary_function才能被bind1st绑定，两个int表示入参为两个int类型，void表示返回值为void
{
public:
	void operator()(int i,int j)const
	{
		cout<< i + j<<endl;
	}

};

void fadd(int i,int j)
{
	cout<<i + j<<endl;
}



int main()
{
	std::vector<int> myv;
	myv.push_back(11);
	myv.push_back(12);
	myv.push_back(13);

	/*C++风格*/
	for_each(myv.begin(),myv.end(),bind1st(add(),10));//bindlst绑定一个默认值到函数add

	/*boost风格*/
	for_each(myv.begin(),myv.end(),bind(fadd,11,_1));//绑定的函数为fadd,绑定的值为11，_1为占位符，代表要传递到fadd函数的第一个入参的值
	return 0;


	/*boost的bind的首个参数必须是一个地址类型，如果绑定的是函数，那么首个参数之后的入参就全是要传递到绑定函数的参数，类似于_1,_2，_3这样的就是占位符号,这写表示的是要传递参数的位置，例如_1代表要传递到被绑定函数的第一个入参，如果直接写明确了数据诸如1，2，3这样明确的数据，那么就指定了入参的值*/
}
