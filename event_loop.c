#include<unistd.h>
#include<event2/event.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<signal.h>
#include<stdio.h>

int wfd = -1;
char r_buf[16]="0";


void cb_func(evutil_socket_t fd,short what,void *arg)
{
	const char *data=arg;
	printf("Got an event on socket %d:%s%s%s%s [%s]\n",
		(int)fd,
		(what&EV_TIMEOUT) ? " timeout":"",
		(what&EV_READ) ? " read":"",
		(what&EV_WRITE) ? " write":"",
		(what&EV_SIGNAL) ? " signal":"",
		data);
	if(what&EV_READ)
		read(fd,r_buf,1);
	
}

void main_loop(evutil_socket_t fd1,evutil_socket_t fd2)
{
	struct event *ev1,*ev2;
	struct timeval five_seconds={5,0};//struct timeval 由秒和微秒两个部分组成
	struct event_base *base=event_base_new();

	ev1 = event_new(base,fd1,EV_TIMEOUT|EV_READ|EV_PERSIST,
					cb_func,"Reading event");
	
	ev2 = event_new(base,fd2,EV_WRITE,cb_func,"write event");

	event_add(ev1,&five_seconds);
	event_add(ev2,NULL);
	
	event_base_dispatch(base);

	event_free(ev1);
	event_free(ev2);
	event_base_free(base);
}

void sig_handle(int signo)
{
	if(signo == SIGALRM && wfd > 0)
	{
		write(wfd,"1111",1);
		alarm(1);
		printf("w sig\n");
	}
}



int main()
{
	const char *fifoName = "event.fifo";
	int fd1,fd2;
	unlink(fifoName);

	if(mkfifo(fifoName,0644) != 0)
	{
		perror("mkfifo error ");
		exit(1);
	}

	fd1 = open(fifoName,O_RDONLY|O_NONBLOCK|EV_PERSIST,0644);
	if(fd1 < 0)
	{
		perror("read open fifo error ");
		exit(1);
	}

	fd2 = open(fifoName,O_WRONLY|O_NONBLOCK,0644);
	if(fd2 < 0)
	{
		perror("write open fifo error ");
		exit(1);
	}
	wfd = fd2;
	alarm(1);
	signal(SIGALRM,sig_handle);

	main_loop(fd1,fd2);

	close(fd1);
	close(fd2);

}

