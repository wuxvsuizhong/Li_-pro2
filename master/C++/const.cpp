#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	const int b = 15;
	int *const p1 = &a;
	//int *const p2 = &b;
	cout<<"*p1 = "<<*p1<<endl;
	a = 11;
	cout<<"after change,*p1 = "<<*p1<<endl;

}
