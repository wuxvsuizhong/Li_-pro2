//delete可以禁用默认的函数，禁用构造将无法实例化
//禁用拷贝构造，可以实现禁止调用拷贝对象

#include<iostream>

class MyClass
{
public:
//	MyClass() = delete;//删除默认构造函数
	MyClass() = default;//默认存在
//	Myclass(const MyClass &) = delete;//禁止拷贝构造		
	MyClass(const MyClass &) = default;//使用默认拷贝构造
	~MyClass()
	{

	}
};



int main()
{
	MyClass m1;
	MyClass m2(m1);



	return 0;
}
