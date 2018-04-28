#include<iostream>


static int num;

static int** aa;
static int** bb;
static int** cc;


int getlen(int *ps)
{
	int len(0);
	while(ps[len] != 0 && len < num) len++;
	
	return len;
}


void showdetail()
{
	int *intps[3]={static_cast<int*>(*aa),static_cast<int*>(*bb),static_cast<int*>(*cc)};
	int destlen=0;	
	for(int i=0;i<3;i++)
	{
		destlen = getlen(intps[i]);
//		std::cout<<"destlen "<<destlen<<std::endl;
		std::cout<<"第"<<i<<"列";
		for(int j=0;j<destlen;j++){
			std::cout<<intps[i][j]<<"\t";
		}
		std::cout<<std::endl;
	}
}


void movetop(int *src,int *dest)
{//将src数组中的最高位置处的元素移动到目的数组中的当前最高位的后一位
	int srclen=0,destlen=0;
	srclen = getlen(src);
	destlen = getlen(dest);
	dest[destlen] = src[srclen-1];
	src[srclen-1] = 0;
	showdetail();
}






void han(int *a,int *b,int *c,int n)
{
	if(n>=1){
		han(a,c,b,n-1);
		std::cout<<a<<"->"<<c<<std::endl;
		movetop(a,c);
		han(b,a,c,n-1);
	}
	else
	{
		return ;
	}
}	



int main()
{
	std::cout<<"num =";
	std::cin>>num;
	std::cout<<num<<std::endl;
	int *col1 = new int[num];
	int *col2 = new int[num];
	int *col3 = new int[num];
	aa = &col1;
	bb = &col2;
	cc = &col3;



	std::cout<<"col1 = "<<col1<<std::endl;
	std::cout<<"col2 = "<<col2<<std::endl;
	std::cout<<"col3 = "<<col3<<std::endl;
	int tmpnum = num;
	for(int i=0;i<num;i++)
	{
		col1[i] = tmpnum;
		tmpnum--;
	}

	showdetail();
	han(col1,col2,col3,num);
		
	delete [] col1;
	delete [] col2;
	delete [] col3;	






	return 0;
}
