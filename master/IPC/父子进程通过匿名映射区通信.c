#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<wait.h>

int main(int argc,char **argv)
{

	int len = 4096;

	void *mptr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);

	if(mptr  == MAP_FAILED)
	{
		perror("mmap error ");
		exit(1);
	}
	
	pid_t pid;
	if((pid = fork()) == -1)
	{
		perror("fork error ");	
		exit(1);
	}
	if(pid == 0)
	{
		//子进程读数据
		printf("子进程读取到 %s\n",(char *)mptr);
	}
	if(pid > 0)
	{
		//父进程写数据
		strcpy(mptr,"父进程写入超长");//写入数据超出映射区长度，可能发生段错误
		wait(NULL);//父进程回收子进程
		if(munmap(mptr,len) == -1)
		{
			perror("munmap error ");
			exit(1);
		}

	}


	return 0;
}
