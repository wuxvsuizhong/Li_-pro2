class C
{
private:
	int num1;
	mutable int num2;
public:
	C(){};
	~C(){}
	void func() const//对用mutable申明过的变量约束无效
	{
	//	num1 = 11;
		num2 = 22; //用mutable申明的变量不受const约束
	}

};

int main()
{
	C c1;
	c1.func();
	return 0;
}
