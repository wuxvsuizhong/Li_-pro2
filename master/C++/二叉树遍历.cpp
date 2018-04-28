#include<iostream>
#include<string>
#include<stack>

using namespace std;


struct MyStruct
{
	int Nodedata = 0;
	MyStruct *pLeft = nullptr;
	MyStruct *pRight = nullptr;
}BTree,*pBTree;
/*
MyStruct *insertnode(MyStruct *proot,int num)
{

}
*/
void show(MyStruct *proot,int n)
{
	if(proot == nullptr)
		return ;
	else
	{
		show(proot->pLeft,n+1);
		for(int i=0;i<n;i++)
		{
			cout<<"\t";
		}
		cout<<proot->Nodedata<<endl;
		show(proot->pRight,n+1);
	}

}	

void middle_show(MyStruct *proot)
{
/*中序遍历*/
	if(proot == nullptr)
		return ;
	if(proot->pLeft != nullptr)
	{
		middle_show(proot->pLeft);
	}
	cout<<proot->Nodedata<<endl;
	if(proot->pRight!= nullptr)
	{
		middle_show(proot->pRight);
	}
}

void back_show(MyStruct *proot)
{  
	/*后序遍历*/
	if(proot == nullptr)
		return ;
	if(proot->pLeft!=nullptr)
		back_show(proot->pLeft);
	if(proot->pLeft!=nullptr)
		back_show(proot->pRight);
	cout<<proot->Nodedata<<endl;
}

void stack_middle_show_1(MyStruct *proot)
{
	MyStruct *pcurrent = proot;
	MyStruct *mystack[100];
	int top = 0;
	while(top !=0 || pcurrent != nullptr)
	{
		while(pcurrent != nullptr)
		{
			mystack[top++] = pcurrent;
			pcurrent = pcurrent->pLeft;
		}
		if(top > 0)
		{
			top--;
			pcurrent = mystack[top];
			cout<<"\t"<<pcurrent->Nodedata<<endl;
			pcurrent = pcurrent->pRight;
		}
	}
}

void stack_middlw_show_2(MyStruct *proot)
{
	MyStruct *pcurrent = proot;
	stack<MyStruct *>mystack;

	while(!mystack.empty() || pcurrent != nullptr)
	{
		while(pcurrent!=nullptr){	
			mystack.push(pcurrent);
			pcurrent = pcurrent->pLeft;
		}
		cout<<pcurrent->Nodedata<<endl;
		mystack.pop();
		pcurrent = mystack.top().pRight();

	}
}


int main()
{
	MyStruct *pRoot;
	MyStruct sarray[100];
	pRoot = sarray;

	for(int i=0;i<100;i++)
	{
		sarray[i].Nodedata = i+1;
	}
	for(int i=0;i<=49;i++)
	{
		sarray[i].pLeft = &sarray[2*i+1];
		if(i<49){
			sarray[i].pRight = &sarray[2*i+2];
		}
	}
	cout<<"before show"<<endl;
	show(pRoot,1);
	//middle_show(pRoot);
	//back_show(pRoot);
	//stack_middle_show(pRoot);
	return 0;
}
