/*
3个写线程，5个读线程访问共享资源
*/
#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>


int number = 0;

pthread_rwlock_t rwlock;


void *writefunc(void *arg)
{
	//循环写入
	while(1)
	{
		//加上写锁
		pthread_rwlock_wrlock(&rwlock);
		number++;
		printf("%lu write to number:%d\n",pthread_self(),number);
		pthread_rwlock_unlock(&rwlock);
		usleep(500);
	}
}


void *readfunc(void *arg) 
{
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		printf("%lu read from number %d\n",pthread_self(),number);
		pthread_rwlock_unlock(&rwlock);
		usleep(500);
	}
}



int main()
{
	//初始化读写锁

	pthread_rwlock_init(&rwlock,NULL);
	pthread_t th[8];
	for(int i=0;i<3;i++)
	{
		pthread_create(&th[i],NULL,writefunc,NULL);
	}

	for(int i=0;i<5;i++)
	{
		pthread_create(&th[i],NULL,readfunc,NULL);
	}

	for(int i=0;i<8;i++)
	{
		pthread_join(th[i],NULL);
	}
	pthread_rwlock_destroy(&rwlock);
	return 0;
}
