#include<iostream>
#include<string>
#include<typeinfo>

template <class T,int n=0>
class myarray
{
public:
	myarray();
	~myarray();
	T get(int index);
	void set(T& t,int i); 
	int size();
private:
	T *pt;
};


template<class T,int n>
myarray<T,n>::myarray()
{
	pt = nullptr;
	if(n > 0){
		pt = new T[n];
	}	
}

template<class T,int n>
myarray<T,n>::~myarray()
{
	if(pt != nullptr){
		delete [] pt;
	}
}

template<class T,int n>
T myarray<T,n>::get(int i)
{
	if(i < 0||i>n){
		T *p(nullptr);
		return *p;
	}
	return *(pt+i);
}


template<class T,int n>
void myarray<T,n>::set(T& t,int i)
{
	if(i<0||i>n){
		return ;
	}
	*(pt+i) = t;
	return ;
}

template<class T,int n>
int myarray<T,n>::size()
{
	return n;
}


template <class T,int n>
void print(myarray<T,n> &arrays)//类模板作为函数参数传递的时候必须明确类型
{
	for(int i=0;i<arrays.size();i++){
		std::cout<<arrays.get(i)<<std::endl;
	}
}



int main()
{
	std::string s1("test");
	myarray<std::string,5> m1;
	for(int i=0;i<5;i++){
		s1+='X';
		m1.set(s1,i);
	//	std::cout<<m1.get(i)<<std::endl;

	}

	print(m1);//明确的模板类型m1
	return 0;
}
