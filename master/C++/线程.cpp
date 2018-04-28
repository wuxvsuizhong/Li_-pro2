#include<iostream>
#include<thread>
#include<string>
#define DEBUG 1
#define tharray 1
using namespace std;

void h1()
{
	cout<<"hello 1"<<endl;
}

void h2()
{
	cout<<"hello 2"<<endl;
}
void h3()
{
	cout<<"hello 3"<<endl;
}

void func(int n)
{
	cout<<"hello\t"<<n<<endl;
}

int main()
{
#if tharray == 0
	std::thread t1(h1);
	std::thread t2(h2);
	std::thread t3(h3);
#if DEBUG
	cout<<DEBUG<<"detach"<<endl;
	t1.detach();//c++中需要加上detach属性,或者使用t1.join(),否则会出现terminate called without an active exception 程序运行报错
	t2.detach();
	t3.detach();
#else
	cout<<DEBUG<<"join"<<endl;
	t1.join();
	t2.join();
	t3.join();

#endif
	cin.get();
#endif

#if tharray == 1
	thread *p[10];
	for(int i=0;i<10;i++){
		p[i] = new thread(func,i);
//		p[i]->join();//等待执行后在继续执行
		p[i]->detach();//detach,线程分离属性，并行乱序执行
	}
#endif
	return 0;
}
