#include<iostream>
using namespace std;
int main()
{
#if 0
	char ch;
	std::cin>>ch;
	cin.get();//吸收回车符号
	std::cout<<(char)(ch-32);//大些转换
	
	while((ch = cin.get())!='\t')
	{
		cin.get();
		cout.put(ch);
	}
#endif
	char str[30]={0};
	cin.getline(str,10);//10限定长度,会自动包含字符串末尾\0
	cout<<str;

	return 0;
}
