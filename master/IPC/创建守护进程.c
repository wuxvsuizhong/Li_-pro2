#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<time.h>
#include<sys/stat.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


void sigfunc(int signo)
{
	if(signo == SIGALRM)
	{
		int fd = open("temp++",O_WRONLY|O_CREAT,0664);
		if(fd!= -1)
		{
			time_t curtime;
			time(&curtime);
			char *pt = ctime(&curtime);
			write(fd,pt,strlen(pt));
		}
		close(fd);
	}
}


int main()
{
	pid_t pid = fork();
	if(pid > 0)
	{
		exit(1);
		//kill(getpid(),SIGKILL);

	}

	if(pid == 0)
	{
		setsid();
		//chdir(".");
		close(0);
		close(2);
		umask(0);
		struct sigaction act;
		act.sa_handler=sigfunc;
		act.sa_flags=0;
		sigemptyset(&act.sa_mask);

		struct itimerval itime;
		itime.it_interval.tv_sec = 2;
		itime.it_interval.tv_usec = 0;//定时器循环周期

		itime.it_value.tv_sec = 2;
		itime.it_value.tv_usec = 0;//定时器开始时间

		setitimer(ITIMER_REAL,&itime,NULL);
		sigaction(SIGALRM,&act,NULL);
		while(1);//保持子进程不退出
	}


	return 0;
}
