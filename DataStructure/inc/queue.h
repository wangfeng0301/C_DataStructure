#ifndef __QUEUE_H__
#define __QUEUE_H__
typedef struct  
{
	int size;//���д�С
	int front;//��ͷ
	int rear;//��β
	char *qu;//����������
}Queue;

void CreateQueue(Queue *q,int size);
void enQueue(Queue *q,char c);
char deQueue(Queue *q);
void ClearQueue(Queue *q);

void testQueue();

#endif