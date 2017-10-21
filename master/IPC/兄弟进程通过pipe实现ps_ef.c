#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main()
{
	int fd[2];
	if(pipe(fd) == -1)
	{
		perror("pipe error ");
		exit(1);
	}

	int i=0;
	for(i=0;i<2;i++)
	{
		if(fork() == 0)
		{
			break;
		}
	}
	if(i == 2)
	{
		close(fd[0]);
		close(fd[1]);
	}



	if(i == 0)//第一个子进程，写入数据
	{//关闭管道的读端
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("netstat","netstat","-an",NULL);
		perror("execlp error ");
		exit(1);
	}	
	if(i == 1)//第二个子进程
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("grep","grep","8050",NULL);
		perror("execlp error ");
		exit(1);
	}
	if(i == 2)
	{
		pid_t wpid;
		int statu;
		while((wpid = wait(&statu)) != -1)
		{
			printf("child %d died, statu is %d\n",wpid,statu);
		}
	}

	return 0;
}
