#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define MAX 10000
int number = 0;
pthread_mutex_t mutex;

void *thfun1(void *arg)
{
	int i=0;
	int cur = 0;
	for(i=0;i<MAX;i++)
	{
		pthread_mutex_lock(&mutex);
		cur = number;
		cur++;
		number = cur;
		printf("th1 number  = %d\n",number);
		pthread_mutex_unlock(&mutex);
		usleep(10);
	}
}

void *thfun2(void *arg)
{
	int i=0;
	int cur =0;
	for(i=0;i<MAX;i++)
	{
		pthread_mutex_lock(&mutex);
		cur=number;
		cur++;
		number = cur;
		printf("th2 number = %d\n",number);
		pthread_mutex_unlock(&mutex);
		usleep(10);
	}
}

void main()
{
	pthread_t th1,th2;

	pthread_mutex_init(&mutex,NULL);



	pthread_create(&th1,NULL,thfun1,NULL);
	pthread_create(&th2,NULL,thfun2,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_mutex_destroy(&mutex);

	return NULL;
}

