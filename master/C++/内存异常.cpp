#include<iostream>

using namespace std;

class stu
{
private:
public:
	bool flag = false;
	void *mp = nullptr;
	stu()
	{
		cout<<"create str->"<<this<<endl;
		flag = true;
		mp = this;
	}
	~stu()
	{
		cout<<"destroy stu"<<this<<endl;
		mp = nullptr;
	}
};

class wrong
{
private:
	void *p;

public:
	wrong(void *mp):p(mp)
	{
	}

	void show()
	{
		cout<<"内存泄露-->"<<p<<endl;		
	}
};

void run()
{
/*
	stu *p = new stu;
	void **fp = &(p->mp);
	//delete p;
	if(p->flag == true && (*fp)!= nullptr)
		throw wrong(p);
*/	
	void **fp = nullptr;
	stu* ss1 = nullptr;
	{
		stu s1;
		ss1 = &s1;
		fp = &(s1.mp);
	}
	if((*ss1).flag == true && (*fp)!= nullptr)
		throw wrong(ss1);
	
}





int main()
{
	try
	{
		run();
	}
	catch (wrong e)
	{
		e.show();
	}
	


}
