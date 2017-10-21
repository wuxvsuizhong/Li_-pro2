/*
生产者创建链表节点，采用头插法插入新的节点
消费者删除节点，一次删除一个头节点
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef struct link
{
	int data;
	struct link* next;
}Node;

pthread_mutex_t mutex;
pthread_cond_t cond;

Node *head = NULL;



void *producer(void *arg)
{
	while(1)//持续的进行生产
	{	
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = rand()%99;//取随机数字
		newNode->next = head;
		pthread_mutex_lock(&mutex);//上锁
		head = newNode;
		printf("%lu ======produce %d\n",pthread_self(),newNode->data);
		pthread_mutex_unlock(&mutex);//解锁
		pthread_cond_signal(&cond);//通知消费者线程
		sleep(rand()%3);
	}
	return NULL;
}

void *customer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);//加锁
		if(head == NULL)//判断链表是否是空
		{
			//continue;
			pthread_cond_wait(&cond,&mutex);//条件变量使得线程阻塞等待
			//该函数内部会对互斥锁先解锁,返回前加锁
		}
		Node *ph = head;
		head=head->next;
		printf("%lu ========concume %d\n",pthread_self(),ph->data);
		free(ph);
		pthread_mutex_unlock(&mutex);//解锁
	}
	return NULL;
}


int main()
{
	pthread_t cre,consumer;
	//初始化互斥量
	pthread_mutex_init(&mutex,NULL);
	//初始化条件变量
	pthread_cond_init(&cond,NULL);
	//创建生产消费线程
	pthread_create(&cre,NULL,producer,NULL);
	pthread_create(&consumer,NULL,customer,NULL);

	//回收子线程
	 pthread_join(cre,NULL);
	pthread_join(consumer,NULL);

	//销毁条件变量和互斥量
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}
