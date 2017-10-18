#ifndef _SERVER_H
#define _SERVER_H


#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

class Server
{
private:
	struct sockaddr_in  *servaddr;
	int listenFd;
	pthread_attr_t *attr;
public:
	explicit Server(const char *portStr);
	~Server();
	int toAccept();//接收客户端链接，成功的话返回分配给客户端链接的套接字，失败返回-1
	int toServer(int clientFd);
	static void* servForPerClient(void *arg);
	void del();
};


#endif
