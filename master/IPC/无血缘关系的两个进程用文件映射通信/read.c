#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>



#define SIZE 4096



int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		perror("缺少参数");
		exit(1);
	}

	int fd = open(argv[1],O_RDWR|O_CREAT,0664);//如果文件不存在就创建
	ftruncate(fd,SIZE);//扩展文件大小到SIZE大小
	void *ptr = mmap(NULL,SIZE,PROT_READ,MAP_SHARED,fd,0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error ");
		exit(1);
	}

	while(1)
	{
		sleep(1);
		printf("读到的内容：%s\n",(char *)ptr);

	}

	if(munmap(ptr,SIZE))
	{
		perror("munmap error ");
		exit(1);
	}
	
	return 0;
}
