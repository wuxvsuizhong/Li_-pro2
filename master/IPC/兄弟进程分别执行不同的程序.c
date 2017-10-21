#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>



int main()
{
	int n=-1;
	pid_t pid;
	for(n=0;n<3;n++)
	{
		pid = fork();
		if(pid == 0)
		{
			printf("break--------- \n");
			break;
		}
	}

	if(n == 0)//第一个子进程
	{
		execlp("ls","ls","-l",NULL);
		perror("execlp ls ");//子进程1进入execlp后就不会执行到后面的代码
		exit(1);
	}
	if(n == 1)//第二个子进程
	{
		execl("/home/zhww/practice/hello","a.out",NULL);
		perror("execl error ");
		exit(1);
	}
	if(n == 2)//第三个子进程
	{
		execl("./error","error",NULL);//执行不存在的程序，会错误
		perror("execl error ");
		exit(1);
	}
	if(n == 3)//父进程回收子进程资源
	{
		int status;
		pid_t wpid;
		//while((wpid = waitpid(-1,&status,WNOHANG)) != -1)
		while((wpid = wait(&status)) != -1)//循环回收多个子进程
		{
			sleep(1);
			printf("--------child %d died\n",wpid);//打印回收的进程id
			if(WIFEXITED(status))
			{
				printf("return value is %d\n",WEXITSTATUS(status));
			}
			if(WIFSIGNALED(status))
			{
				printf("termed by signal %d\n",WTERMSIG(status));
			}
		}
	}
	return 0;
}
