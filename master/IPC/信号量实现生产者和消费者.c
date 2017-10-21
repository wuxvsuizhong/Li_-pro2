#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>



typedef struct link
{
	int data;
	struct link* next;
}Node;

Node *head = NULL;

sem_t producSem;
sem_t consumSem;
void *consumer(void *arg)
{
	//循环创建链表
	while(1)
	{
		sem_wait(&producSem);//先消耗一个资源,如果当前信号量为0那么生产者阻塞
		Node* newNode = (Node *)malloc(sizeof(Node));
		newNode->data = rand()%99;
		newNode->next = head;
		head = newNode;
		printf("%lu =====生产了一个产品%d\n",pthread_self(),newNode->data);
		sem_post(&consumSem);//消费者信号量加1
		sleep(rand()%3);
	}

}

void *producer(void *arg)
{
	while(1)
	{
		//消费者不断删除链表头节点
		sem_wait(&consumSem);//消费一个资源，如果信号量为0就阻塞
		Node *fp = head;
		head=head->next;
		printf("%lu =====消费了一个产品%d\n",pthread_self(),fp->data);
		free(fp);
		sem_post(&producSem);//生产者信号量加1
		sleep(rand()%3);
	}
}





int main()
{
	sem_init(&producSem,0,5);//初始化生产者占据5个资源
	sem_init(&consumSem,0,0);//初始化消费者占据0个资源

	pthread_t create,customer;
	//创建生产者消费者线程
	pthread_create(&create,NULL,producer,NULL);
	pthread_create(&customer,NULL,consumer,NULL);

	//回收线程资源
	pthread_join(create,NULL);
	pthread_join(customer,NULL);

	sem_destroy(&producSem);
	sem_destroy(&consumSem);


	return 0;
}

