#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd = open("temp",O_CREAT|O_RDWR,0664);
	if(fd < 0)
	{
		perror("open errror ");
		exit(1);
	}

	pid_t pid = fork();
	if(pid == -1)
	{
		perror("for error ");
		exit(1);
	}

	if(pid > 0)
	{
		char *p = "这是一段写入文件的字符串数据";
		write(fd,p,strlen(p)+1);
		close(fd);//父进程关闭文件描述符
	}
	else if(pid == 0)
	{
		sleep(1);//子进程睡眠一会儿保证父进程写入了文件内容
		char buf[1024];
		lseek(fd,0,SEEK_SET);//父进程写入了文件，那么文件指针已经改变，子进程读取文件需要重新定位文件指针
		int n=read(fd,buf,sizeof(buf));
		printf("%s\n",buf);
		close(fd);//子进程文件描述符
	}
	
	return 0;

}
