#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::function;

template<typename T,typename F>
T run(T v,F f)
{
	static int count = 0;
	count++;
	cout<<"单个参数包装器执行"<<count<<"次"<<endl;
	if(count > 2){
		T vx(0);
		return vx;
	}
	
	return f(v);
}

template<typename T,typename F>
T run(T v1,T v2,F f)
{
	return f(v1,v2);
}


int cheng(int a,int b)
{
	return a*b;
}


int main()
{
	double db = 12.2;
	function<double(double)>func1=[](double u)
	{
		return u*u;
	};
//	cout<<run(db,func1)<<endl;
	
	int num=12;
	int num2 = 5;
	function<int(int)>func2=[](int u){return u+u;};
	cout<<run(num,func2)<<endl;
	cout<<run(num2,func2)<<endl;//func2被调用两次
	cout<<run(num,func2)<<endl;//第三次返回0;

	function<int(int,int)>func3=[](int u1,int u2){return u1*u2;};
	cout<<run(num,num2,func3)<<endl;

	function<int(int,int)>func4=cheng;
	cout<<"包装器调用管理外部函数"<<run(num,num2,func4)<<endl;//函数包装器管理调用外部函数
	




	return 0;
}
