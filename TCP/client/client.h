#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>


class Client
{
private:
	struct sockaddr_in *servaddr;
	int sockfd;	
public:
	Client(const char* IPStr,const char *portStr);
	~Client();
	void del();
	int toWork();
	static void* withTheWork(void *arg);
};
