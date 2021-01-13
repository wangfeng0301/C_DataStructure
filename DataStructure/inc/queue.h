#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "type.h"

/* 队列数据结构体 */
typedef struct
{
	//char c;
	int element;
}QueueData_t;

typedef struct  
{
	int size;//队列大小
	int front;//队头
	int rear;//队尾
	QueueData_t *qu;//数组存放数据
}Queue_t;

void CreateQueue(Queue_t *q,int size);
bool EnQueue(Queue_t *q,QueueData_t dat);
bool DeQueue(Queue_t *q, QueueData_t *dat);
void ClearQueue(Queue_t *q);

void testQueue(void);

#endif