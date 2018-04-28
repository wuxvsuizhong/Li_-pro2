#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str("1234567890");
	auto ib = str.begin();
	auto ie = str.end();
	cout<<"str-->";
	for(;ib!=ie;ib++){
		cout<<*ib;
	}
	cout<<endl;
	cout<<"str.erase(str.begin())-->";
	str.erase(str.begin());//利用迭代器删除一个字符
	cout<<str<<endl;
	
	cout<<"str.erase(str.begin()+2,str.end()-2)-->";
	str.erase(str.begin()+2,str.end()-2);//指定界限删除数据
	cout<<str<<endl;
	
	cout<<"str.append(\"abcdefiaghijaklmanapqrst\")-->";
	str.append("abcdefiaghijaklmanapqrst");//追加数据
	cout<<str<<endl;
	
	cout<<"str.replace(0,3,\"11\")";
	str.replace(0,3,"11");//从位置0开始，连续3个字符被替换成”11“
	cout<<str<<endl;
	
	cout<<"str.replace(1,0,\"11\")";//从位置开始，0个字符被替换成字符”11“，相当于插入
	str.replace(1,0,"11");
	cout<<str<<endl;
	
	cout<<"str.find(\"c\")-->",
	cout<<str.find("c")<<endl;
	
	cout<<"(int)str.find(\"o\")-->",
	cout<<(int)str.find("o")<<endl;//找不到返回-1
	
	cout<<"str.rfind(\"c\")-->",
	cout<<str.rfind("c")<<endl;//反向查找
	
	cout<<"str.find_first_of(\"a\")-->";//查找”a“第一次出现的位置
	cout<<str.find_first_of("a")<<endl;

	cout<<"(int)str.find_last_of(\"u\")-->";//查找”a“最后一次出现的位置,找不到返回-1
	cout<<(int)str.find_last_of("u")<<endl;
	
	cout<<"str.find_last_of(\"a\")-->";//查找”a“最后一次出现的位置
	cout<<str.find_last_of("a")<<endl;
	
	cout<<"str.find_first_not_of(\"a\")-->";//最后一个不匹配”a“的位置
	cout<<str.find_first_not_of("a")<<endl;
	
	cout<<"str.find_last_not_of(\"a\")-->";//第一个不匹配”a“的位置
	cout<<str.find_last_not_of("a")<<endl;

	cout<<"str.find(\"a\",2)-->";//从指定的位置2开始查找，返回第一次找到的位置
	cout<<str.find("a",2)<<endl;

	int pos = str.find("a",2);
	while(pos != -1){
		cout<<"pos-->"<<pos<<endl;
		pos = str.find("a",pos+string("a").size());//循环查找
	}

	cout<<"const char *p = str.c_str()-->";//返回字符串在内存中的指针
	const char *p = str.c_str();

	string stra = "abc";
	string strb = "ABC";
	char strA[5]="efg";
	char strB[5]="EFG";
	cout<<(stra == strb)<<endl;//重载了运算符
	cout<<(strA == strB)<<endl;//比较地址


	return 0;
}
