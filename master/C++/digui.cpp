#include<iostream>


void recprint(int *p,int l)
{
	if(l <= 1){
		if(l !=0) 
			std::cout<<p[l-1]<<std::endl;
		return ;
	}
	else if(l > 1){
		recprint(p,l-1);
		std::cout<<p[l-1]<<std::endl;
	}

}







int main(int argc,char* argv[])
{	
	int lens = atoi(argv[1]);
	int *p = new int[lens];
	for(int i=0;i<lens;i++){
		p[i] =i+1;
	}
	std::cout<<&p<<std::endl;
	recprint(p,lens);
}
