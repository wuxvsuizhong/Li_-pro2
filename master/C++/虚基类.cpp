#include<iostream>

class obj 
{
public:
	int num;
	obj(int data):num(data)
	{
		std::cout<<"obj create"<<std::endl;
	}
	~obj()	
	{
		std::cout<<"obj destroy"<<std::endl;
	}

};

class Aobj:virtual public obj
{
public:
	Aobj(int data):obj(data)
	{
		std::cout<<"Aobj create"<<std::endl;

	}
	~Aobj()
	{
		std::cout<<"Aobj destroy"<<std::endl;

	}
};

class Bobj:virtual public obj
{
public:
	Bobj(int data):obj(data)
	{
		std::cout<<"Bobj create"<<std::endl;

	}
	~Bobj()
	{
		std::cout<<"Bobj destroy"<<std::endl;

	}
};

class ABobj:public Aobj,public Bobj
{
public:
	ABobj(int num1,int num2):Aobj(num1),Bobj(num2)
	{
		std::cout<<"ABobj create"<<std::endl;

	}
	~ABobj()
	{
		std::cout<<"ABobj destroy"<<std::endl;

	}
};

int main()
{
	ABobj *p = new ABobj(11,22);
//	std::cout<<p->num<<std::endl;
	std::cout<<p->Aobj::num<<std::endl;
	std::cout<<p->Bobj::num<<std::endl;

	delete p;
	return 0;
}
