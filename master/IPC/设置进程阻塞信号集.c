#include<stdio.h>
#include<signal.h>
#include<unistd.h>


int main()
{
	sigset_t pendset;
	sigemptyset(&pendset);

	sigaddset(&pendset,SIGINT);
	sigaddset(&pendset,SIGQUIT);
	sigaddset(&pendset,SIGKILL);//设置到内核会无效，应为SIGKILL不能被阻塞

	sigprocmask(SIG_BLOCK,&pendset,NULL);





	while(1)
	{
		sigpending(&pendset);
		for(int i=1;i<=32;i++)
		{
			if(sigismember(&pendset,i))//循环判断32位
				printf("1");
			else
				printf("0");
		}
		printf("\n");
		sleep(1);
	}







	return 0;
}
