#include<iostream>
#include<assert.h>

using namespace std;


int  main()
{
	int num = 100;
	cout<<num<<endl;
	cout<<"当前文件名："<<__FILE__<<endl;//__FILE__宏为当前文件名
	cout<<"当前行数:"<<__LINE__<<endl;
	cout<<"当前日期："<<__DATE__<<endl;
	cout<<"编译时间："<<__TIME__<<endl;
	cout<<"当前所在函数"<<__FUNCTION__<<endl;
//	static_assert(sizeof(num) >4,"条件不符合");//静态断言,可以在编译阶段定制编译规则
	static_assert(sizeof(num) >=4,"条件不符合");//静态断言,可以在编译阶段定制编译规则
	

	return 0;
}
