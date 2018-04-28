#include<iostream>
#include<typeinfo>
#define DEBUG 0

class A
{
public:
	int num;
	static int data;
#if DEBUG
	virtual void run()
	{
		std::cout<<"A run\n";
	}
#endif
};

class B:public A
{
public:
	int num;
	static int data;
	void run()
	{
		std::cout<<"B run()\n";
	}

	void test()//test函数没有访问类成员，可以用空指针访问，但是如果test是有virtual修饰，那么也不能用空指针访问
	{
		std::cout<<"B test()\n";
	}
};
int A::data = 1;
int B::data = 2;


int main()
{
	B b1;
	b1.num = 10;
	b1.A::num = 20;
	std::cout<<b1.num<<"\t"<<b1.A::num<<std::endl;
	std::cout<<b1.data<<"\t"<<b1.A::data<<std::endl;//基类和子类的同名对象会覆盖，子类只能访问子类的对象，要想访问父类的同名对象，需要加上::与运算符
	A *p1 = new A;
	A *p2 = new B;            

	A aa;
	B bb;
	A *pp1 = &aa;
	A *pp2 = &bb;


	std::cout<<typeid(p1).name()<<"\n";
	std::cout<<typeid(p2).name()<<"\n";//单纯的指针类型智慧根据声明的类型来判断,都是 A*类型,无论有无virtual函数
	std::cout<<typeid(*p1).name()<<"\n";
	std::cout<<typeid(*p2).name()<<"\n";//如果基类中存在没有虚函数,只会根据指针类型来推断类型,和上句的结果一样,不会根据指针所指向的对象的类型来实时动态判断
	//如果基类有虚函数的存在，那么会根据指针的所指对象类型来判断,
	std::cout<<(typeid(p1) == typeid(p2))<<"\n";
	std::cout<<(typeid(*p1) == typeid(*p2))<<"\n";

	std::cout<<(typeid(pp1) == typeid(pp2))<<"\n";
	std::cout<<(typeid(*pp1) == typeid(*pp2))<<"\n";
	std::cout<<typeid(pp1).name()<<"\n";
	std::cout<<typeid(pp2).name()<<"\n";
	std::cout<<typeid(*pp1).name()<<"\n";
	std::cout<<typeid(*pp2).name()<<"\n";//如果基类中存在没有虚函数,只会根据指针类型来推断类型,和上句的结果一样,不会根据指针所指向的对象的类型来实时动态判断
#if DEBUG
	B *pb(nullptr);
	pb->test();//空指针可以调用类中不访问类数据成员的成员函数
//	pb->run();//但是virtual成员函数不行不能用空指针访问，即使virtual函数没有访问类数据成员
	pb = dynamic_cast<B*>(pp2);//使用dynamic时必须要有虚函数，没有虚函数转换会失败，且如果转换成实体不存在的类类型的指针,也会失败,指针被赋值为0
//	pb = dynamic_cast<B*>(pp1);//转换会失败，因为pp1指向的对象没有B类型的实体,pb的值会是0
	//转换失败指针为空
	std::cout<<"pb="<<pb<<std::endl;
	pb->run();//转换如果成功，pb此处不再是空指针，可以访问
#endif
/*****综上可知：要使得空指针类中的函数，该函数中要不调用类成员，且该函数不能是虚函数*********************************/	
	
	B *pbs(nullptr);
	pbs = static_cast<B *>(pp2);//static转换带有强制性，直接复制类的地址，即使基类中没有虚函数也可以转换，不会把指针赋值为空指针
//	pbs = static_cast<B *>(pp1);
	pbs->run();
	std::cout<<"pbs="<<pbs<<std::endl;
	pbs->run();
	pbs->test();//如果test有virtual也无法被访问
/*********不论dynamic还是ststic要想使得转换失败或转换成实体不存在的类类型的指针能够访问类里的函数，那么该函数不能调用类成员，且函数不能是虚函数***************/

	return 0;
}
