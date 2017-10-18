#include"server.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<iostream>



Server::Server(const char* portStr)
	:servaddr(nullptr),listenFd(0),attr(nullptr)
{
	//struct sockaddr_in servaddr;
	servaddr = new struct sockaddr_in;

	memset(servaddr,0,sizeof(*servaddr));
	//std::cout<<"sizeof(*servaddr) "<<sizeof(*servaddr)<<std::endl;
	servaddr->sin_family = AF_INET;
	servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr->sin_port = htons(atoi(portStr));
	
	//创建套接字

	if((listenFd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("create socket error ");
		exit(1);
	}


	int ret  = 0;
	socklen_t len = sizeof(*servaddr);
	//绑定
	if((ret = bind(listenFd,(const struct sockaddr*)servaddr,len))<0)
	{
		std::cout<<"p "<<ret<<std::endl;
		
		perror("bind socket error ");
		exit(1);
	}
	//监听
	if((ret = listen(listenFd,1000)) < 0)
	{
		perror("listen error ");
		exit(1);
	}
	int client_fd;
	while(1)
	{
		if((client_fd = toAccept())> 0)
		{
			toServer(client_fd);		
		}
	}
}

Server::~Server()
{
	del();	
}

int Server::toAccept()
{
	struct sockaddr clientaddr;
	socklen_t len = sizeof(clientaddr);
	memset(&clientaddr,0,sizeof(clientaddr));
	int clientsock;
	//接收客户端链接
	clientsock = accept(listenFd,&clientaddr,&len);
	if(clientsock < 0)
	{
		perror("accept error ");
		return -1;
	}
	return clientsock;//返回分配的套接字
}

void* Server::servForPerClient(void *arg)
{
	//服务器要处理的过程	
	int fd = (int)arg;
	std::cout<<"fd = "<<fd<<std::endl;

	std::cout<<"someone connected!"<<std::endl;
	char buf[1024]={0};
	int ret=0;
	while((ret = read(fd,buf,sizeof(buf)))>0)
	{
		std::cout<<"rec msg\n------------\n"<<buf
						  <<"------------\n"<<std::endl;
		std::cout<<ret<<std::endl;
	}
	std::cout<<"客户端断开"<<std::endl;
	
}

int Server::toServer(int clientFd)
{
	pthread_t th;
	attr = new pthread_attr_t;
	int err = 0; 
	//初始化线程属性
	if((err = pthread_attr_init(attr)) != 0)
	{
		perror("pthread_attr_init error ");
		return -1;
	}
	if((err = pthread_attr_setdetachstate(attr,PTHREAD_CREATE_DETACHED)) != 0)
	{
		perror("pthread_attr_setdetachstate error ");
		return -1;
	}
	if((err = pthread_create(&th,attr,servForPerClient,(void *)clientFd)) !=0)
	{
		perror("pthread_create error ");
		return -1;
	}
	return 0;
}
void Server::del()
{
	if(servaddr != nullptr)
		delete servaddr;
	if(attr != nullptr)
		delete attr;
	if(listenFd != 0)
		close(listenFd);
}
