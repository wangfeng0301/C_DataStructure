#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "type.h"

/* �������ݽṹ�� */
typedef struct
{
	//char c;
	int element;
}QueueData_t;

typedef struct  
{
	int size;//���д�С
	int front;//��ͷ
	int rear;//��β
	QueueData_t *qu;//����������
}Queue_t;

/*��ʽ���нڵ�ṹ��*/
typedef struct LinkQueueNode
{
	QueueData_t data;
	struct LinkQueueNode* next;
}LinkQueueNode_t;
/* ��ʽ���нṹ�� */
typedef struct 
{
	int size;//���д�С
	LinkQueueNode_t *front;//��ͷ
	LinkQueueNode_t *rear;//��β
	//LinkQueueNode_t *qu;//����������
}LinkQueue_t;

void CreateQueue(Queue_t *q,int size);
bool EnQueue(Queue_t *q,QueueData_t dat);
bool DeQueue(Queue_t *q, QueueData_t *dat);
void ClearQueue(Queue_t *q);

void testQueue(void);
void testLinkQueue(void);

#endif