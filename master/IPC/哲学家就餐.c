#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int chopsticks[5];//5根筷子，元素值为0代表没有没有被任何人抢到，如果不为0，那么元素的值代表抢到筷子的人的编号
pthread_mutex_t mutexs[5];

int getNearByNo(int selfNo)//获取相邻位置的号码
{
	if(selfNo>=0 && selfNo<4)//号码在0到4之间的响铃位置就是比自己大1的号码
		return selfNo+1;
	else
		return 0;//号码是4的相邻位置就是0
}


void *getChops(void *arg)
{
	usleep(rand()%10);	
	int no = (int)arg;
	int nearbyNum = getNearByNo(no);
	//每个哲学家线程只能抢占相邻位置的筷子资源和自己的资源
	if(pthread_mutex_trylock(&mutexs[no]) == 0)//先抢自己的筷子
	{
		if(chopsticks[no]!=0)
		{//筷子已经被抢过了
			pthread_mutex_unlock(&mutexs[no]);
			printf("哲学家%d默然离开,什么都没拿到\n",no);
			pthread_exit(0);
		}
		else
		{
			chopsticks[no] = no+1;//抢到筷子后筷子被标记为自己的号码加1
			//然后抢相邻位置的筷子
			if(pthread_mutex_trylock(&mutexs[nearbyNum]) == 0)
			{
				if(chopsticks[nearbyNum]!=0)//相邻位置的筷子已经被抢过
				{
					pthread_mutex_unlock(&mutexs[no]);//退出之前解锁
					pthread_mutex_unlock(&mutexs[nearbyNum]);//解锁相邻位置的筷子
					printf("哲学家%d:倒霉，只有一根筷子！\n",no);
					pthread_exit(0);//相邻位置的筷子已经抢走
				}
				chopsticks[nearbyNum] = no+1;//抢到筷子后筷子被标记为自己的号码加1
				printf("哲学家%d:OH YEAH,我拿到筷子了!\n",no);
				pthread_mutex_unlock(&mutexs[no]);//退出前解锁抢到的自己和相邻的位子的筷子
				pthread_mutex_unlock(&mutexs[nearbyNum]);
			}
			else
			{
				pthread_mutex_unlock(&mutexs[no]);
				printf("哲学家%d:倒霉，只有一根筷子！\n",no);
			}
		}
	}
	else
		printf("哲学家%d默然离开,什么都没拿到\n",no);

	return NULL;
}

int main()
{
	for(int i=0;i<5;i++)
	{
		chopsticks[i] = 0;
		pthread_mutex_init(&mutexs[i],NULL);//初始化5把互斥锁
	}

	pthread_t th[5];

	for(int i =0;i<5;i++)
	{
		pthread_create(&th[i],NULL,getChops,(void *)i);//创建5个哲学家线程
	}

	

	for(int i=0;i<5;i++)
	{
		pthread_join(th[i],NULL);//线程回收
		pthread_mutex_destroy(&mutexs[i]);
	}
	for(int i=0;i<5;i++)
	{
		printf("%d\t ",chopsticks[i]-1);
	}
	printf("\n");

	return 0;
}
