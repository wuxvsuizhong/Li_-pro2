#include<amp.h>
#include<iostream>

using namespace concurrency;
using namespace std;


int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	array_view<int> arrv(10,a);//GPU计算结构，arrv存储到GPU显存
	parallel_for_each(arrv.exent,[=](index<1>inx) //[=]直接造作arrv,无副本机制
	restrict (amp) //restrict子限定在那里执行（此处限定在gpu中执行）
	{
		arrv[inx]+=1;
	}
						);

	for(int i=0;i<10;i++){
		cout<<a[i]<<endl;
	}


	return 0;
}	
