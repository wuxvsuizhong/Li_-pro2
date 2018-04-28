#include<iostream>

template <class T>
class ren
{
public:
	T name;
	ren(T t):name(t)
	{}
	friend std::ostream& operator <<(std::ostream& os,ren<T>& t)
	{
		os<<t.name<<std::endl;
		return os;
	}
};

//类模版作为参数，其中template class<T> class为类型说明，T1为实参
template <template<class T> class T1>
class people
{
public:
	T1<std::string> str;
	people(T1<std::string> t1):str(t1)
	{}
};

int main()
{
	ren<std::string> r1("hello");
	std::cout<<r1.name<<std::endl;

	people<ren> p1(r1);
	std::cout<<p1.str<<std::endl;
	return 0;
}

