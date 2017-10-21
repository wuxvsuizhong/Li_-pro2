#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc,char **argv)
{
	int fd[2];
	if(pipe(fd) == -1)
	{
		perror("pipe error ");
		exit(1);
	}

	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork error ");
		exit(1);
	}

	//父进程关闭管道读
	if(pid > 0)//父进程
	{
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);//标准输出重定向到管道写端,即输出到管道的写端
		execlp("ps","ps","-ef",NULL);
		perror("execlp error ");
		exit(1);
	}
	if(pid == 0)//子进程关闭管道写端
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);//标准输入重定向到管道读端，即数据从管道读端流入
		execlp("grep","grep","bash","--color=auto",NULL);
		perror("execlp error ");
	}

	close(fd[0]);
	close(fd[1]);
	printf("at end\n");//如果重定向成功，此处的3句编码是不能执行到的
	return 0;
}

