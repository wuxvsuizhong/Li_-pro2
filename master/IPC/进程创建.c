#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int i=0;
#if 0
	for(int i=0;i<3;i++){
		fork();//此处一共有8个进程(包含主进程),因为子进程是父进程的副本的关系，数据直接拷贝到子进程
	}
#endif

	int ret;
	for(int j=0;j<3;j++)
	{
		if((ret = fork()) == 0)//如果返回的是子进程，就暂时退出
			break;//创建3个进程,加上主父进程，一共4个进程
	}

	if(ret == 0)
	{
		while(1){
			sleep(1);
			printf("child %d is running...\n",getpid());
		}
	}
	while(1);//主父进程不退出
	
}
