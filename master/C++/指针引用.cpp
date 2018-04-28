#include<iostream>
using namespace std;


/*
不要返回位于栈上的变量的引用，因为栈上的变量在函数调用结束后变得不可控
但是可以返回位于栈上的指针变量的引用，且这个指针指向堆内存,在这种情况下，需要及时保存返回的值，否则栈上的指针变量会因为栈的重用被刷新为不可知的值
*/



int * &getp()
{
	int *p;
	p=new int;
	*p =10;
	int *& rp = p;//引用初始化
	cout<<"*p ="<<*p<<endl;
	cout<<"p="<<p<<endl;
	cout <<"rp="<<rp<<endl;
	return rp;//返回指针的引用
}


int main()
{
	int num1(5);
	int num2(10);
	int *pnum(&num1);
	int * & rpnum=pnum;//引用指针（引用的是一个int类型的指针）,此处rpnum引用的是指针pnum,而pnum又指向num1
	cout<<*pnum<<endl;
	//cout<<num1<<endl;
	rpnum = &num2;//此处被rpnum引用的指针pnum重新赋值指向num2,即通过引用改变指针的值 
	cout<<*pnum<<endl;
	//cout<<num2<<endl;
	//引用始终是引用的指针pnum，但是pnum的指向却是可以改变的
	
	*rpnum = 1111;//通过引用改变指针指向的值
	cout<<*pnum<<endl;
	
	//int * & rrpnum = &num1; //对于num1取地址的操作为一个右值，不能单独应用(语法报错)
	//int * && rrpnum = &num1;
//	int *gpp;//如果采用先分配变量，然后复制的做法，必须提前分配用于保存栈指针的引用的变量，因为如果在函数调用返回后再分配栈变量,那么栈会被刷

	int * &gp = getp();//引用栈指针
	int *gpp = gp;//采用即时分配变量并初始化的方式，保存栈指针的内容
	cout<<"*gp ="<<*gp<<endl;//在语句执行完成之后，栈被重新刷新重用，gp引用的栈内容变得不可预知
//	cout<<"*gp ="<<*gp<<endl;//再次执行会发生段错误，因为栈已经被刷新,通过指针引用访问分配的对内容已不能实现
	cout<<"gp ="<<gp<<endl;//此处通过引用打印出的栈内容以不是函数调用中分配的堆内存地址
	cout<<"   "<<endl;
	cout<<"gp ="<<gp<<endl;
	cout<<"*gpp = "<<*gpp<<endl;

	delete gpp;
	cout<<"gpp = "<<gpp<<endl;
	cout<<"*gpp = "<<*gpp<<endl;

//	delete gp;
	cout<<"gp ="<<gp<<endl;
//	cout<<"*gp ="<<*gp<<endl;

	int *pnum2 = new int;
	*pnum2 = 11;
	cout<<"pnum2 ="<<pnum2<<endl;
	cout<<"*pnum2 ="<<*pnum2<<endl;

	int * &ppnum2 = pnum2;
	delete pnum2;
	cout<<"pnum2 ="<<pnum2<<endl;//delete完成后，指针变量中存储的指针仍然存在,所以对于释放一个指针后，防止它变成一个野指针，很有必要将其置为NULL
	cout<<"*pnum2 ="<<*pnum2<<endl;//delete完一个指针之后，会将指针指向的内存的值变为0
	
//	pnum2 = NULL;//直接将指针变量赋值为NULL
//	ppnum2 = NULL;//通过引用将指针变量置为NULL
	cout<<"ppnum2 ="<<ppnum2<<endl;//如果将pnum2指针变量置为NULL，那么此处会发生段错误
	cout<<"*ppnum2 ="<<*ppnum2<<endl;

	int c = 33;
	int & lc = c;
	//int * && rc = &c;//一个指针右值引用，只有c++11才支持右值引用
	

	return 0;
}
