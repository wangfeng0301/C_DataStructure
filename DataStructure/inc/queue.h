#ifndef __QUEUE_H__
#define __QUEUE_H__
typedef struct  
{
	int size;//队列大小
	int front;//队头
	int rear;//队尾
	char *qu;//数组存放数据
}Queue;

void CreateQueue(Queue *q,int size);
void enQueue(Queue *q,char c);
char deQueue(Queue *q);
void ClearQueue(Queue *q);

void testQueue();

#endif