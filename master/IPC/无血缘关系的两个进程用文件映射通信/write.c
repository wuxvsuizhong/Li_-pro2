#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 4096



int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		perror("缺少参数");
		exit(1);
	}

	int fd = open(argv[1],O_RDWR|O_CREAT,0664);
	ftruncate(fd,SIZE);
	void *ptr = mmap(NULL,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error ");
		exit(1);
	}
	int count=0;
	while(1)
	{	
		count++;
		sprintf((char *)ptr,"%s,%d","写入数据",count);
		sleep(2);
	}
	
	if(munmap(ptr,SIZE) == -1)
	{
		perror("munmap error ");
		exit(1);
	}

	return 0;
}

