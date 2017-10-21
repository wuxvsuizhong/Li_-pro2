#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		perror("缺少参数 ");
		exit(1);
	}


	int fd = open(argv[1],O_RDWR|O_APPEND);
	int len = lseek(fd,0,SEEK_END);

	void *mptr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(mptr  == MAP_FAILED)
	{
		perror("mmap error ");
		exit(1);
	}
	printf("%s\n",(char *)mptr);

	printf("add %s\n",strcpy((char *)mptr,"添加的内容"));
	printf("%s\n",(char *)mptr);
	close(fd);
	if(munmap(mptr,len) == -1)
	{
		perror("munmap error ");
		exit(1);
	}

	return 0;
}
