/*
函数模板可以通用，但是可以根据具体数据类型进行优化
*/
#include<iostream>
#include<string.h>

using std::string;

/*
拷贝构造在调用之前不会先调用构造函数,而是直接调用拷贝构造
*/

class info{
private://类有私有成员变量，就不能用{}进行初始化
	int num;
	char *p;
public:
	static int count;
	int data;
	char name[64];
	info()
	{
		count++;
		std::cout<<"create func,count="<<count<<std::endl;
		num = 0;
		p = nullptr;
	}
	~info()
	{
		if(this->p != nullptr)
		{
			delete [] p;
			p = nullptr;
		}
	}
	info(const info& i)
	{
		count++;
		std::cout<<"copycreate func,count="<<count<<std::endl;

		this->num = i.num;
		std::cout<<"before new"<<std::endl;
		if(i.p != nullptr){
			int len = strlen(i.p);
			this->p = new char[len + 1];
			strcpy(this->p,i.p);
		}
		strcpy(this->name,i.name);
		this->data  = i.data;
	}

	void setnum(const int i)
	{
		this->num = i;
	}	

	const int& getnum()
	{
		return num;
	}
	
	void setP(const char* c)
	{
		if(this->p != nullptr)
			delete [] p;
		int len = strlen(c);
		p = new char[len+1];
		strcpy(this->p,c);
	}

	const char* getP()
	{
		return this->p != nullptr ? this->p:"空";
	}

	void operator=(const info& in)
	{
		strcpy(this->name,in.name);
		this->data  = in.data;
		this->num = in.num;
		
		if(in.p != nullptr){
			if(this->p != nullptr)
				delete [] this->p;
			int len = strlen(in.p);
			p = new char[len+1];
			strcpy(this->p,in.p);
			
		}
		else{
			if(this->p != nullptr){
				delete[] this->p;
				this->p = in.p;
			}
		}
	}
	
	void showdetail()
	{
		std::cout<<this->name<<"\t"<<this->getnum()
			<<"\t"<<this->data<<"\t"<<this->getP()<<"\t"<<std::endl;
	
	}
};





template<typename T>
void swap(T &a,T &b)
{
	std::cout<<"通用函数模板"<<std::endl;
	T tmp = a;
	a = b;
	b = tmp;
}

template<>//函数模板覆盖，无需数据类型
void swap(info &infoa,info &infob)
{
	std::cout<<"特有函数模板"<<std::endl;
	info temp = infoa;
	infoa = infob;
	infob = temp;
	
}

int info::count = 0;


int main()
{
	int num1 = 100;
	int num2 = 10;
	swap(num1,num2);
	std::cout<<"\t"<<num1<<"\t"<<num2<<std::endl;

	info info1;
	info info2;
	strcpy(info1.name,"zhee1");
	strcpy(info2.name,"zhww2");
	info1.data = 11;
	info2.data = 22;
	info1.setnum(111);
	info2.setnum(222);
	info1.setP("test1");	

	swap(info1,info2);
	std::cout<<"info1\t"<<std::endl;
	info1.showdetail();
	std::cout<<"info2\t"<<std::endl;
	info2.showdetail();

	return 0;
}
