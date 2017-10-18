#include"client.h"
#include<string.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



Client::Client(const char *IPStr,const char *portStr)
	:servaddr(nullptr),sockfd(-1)
{
	servaddr = new struct sockaddr_in;
	memset(servaddr,0,sizeof(*servaddr));
	servaddr->sin_family = AF_INET;
	inet_pton(AF_INET,IPStr,&servaddr->sin_addr.s_addr);
	servaddr->sin_port = htons(atoi(portStr));
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("create socket error ");
		exit(1);
	}
	
	if(connect(sockfd,(const struct sockaddr *)servaddr,sizeof(*servaddr)) < 0)
	{
		perror("connect error ");
		exit(1);
	}

	if(toWork() < 0)
	{
		printf("系统错误！\n");
		exit(1);
	}

}


Client::~Client()
{
	del();
}

void Client::del()
{
	if(servaddr == nullptr)
		delete servaddr;
	if(sockfd != 0)
		close(sockfd);
}


int Client::toWork()
{
	pthread_attr_t attr;
	if(pthread_attr_init(&attr) != 0)
	{
		perror("pthread_attr_init error ");
		return -1;
	}
	if(pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED) != 0)
	{
		perror("pthread_attr_setdetachstate error ");
		return -1;
	}

	pthread_t th;
	pthread_create(&th,&attr,withTheWork,(void *)sockfd);//先给线程函数什么都不传递
	while(1);//保持主线程不退出
	pthread_attr_destroy(&attr);
}



void* Client::withTheWork(void *arg)
{
	int fd = (int)arg;
	while(1)
	{
		sleep(1);
		printf("sockfd = %d\n",fd);		
	}
}
