#include<stdio.h>
#include<signal.h>
#include<unistd.h>


int main()
{
	sigset_t set;
	while(1)
	{
		sigpending(&set);
		for(int i=1;i<32;i++)
		{
			if(sigismember(&set,i))//循环判断32位
				printf("1");
			else
				printf("0");
		}
		printf("\n");
		sleep(1);
	}







	return 0;
}
