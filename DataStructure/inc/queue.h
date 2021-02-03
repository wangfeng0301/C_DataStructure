#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "type.h"

typedef struct  
{
	int size;//队列大小
	int front;//队头
	int rear;//队尾
	void *qu;//数组存放数据
	int qulen;//每个元素的大小（字节）
}Queue_t;

/*链式队列节点结构体*/
typedef struct LinkQueueNode
{
	void *data;
	struct LinkQueueNode* next;
}LinkQueueNode_t;
/* 链式队列结构体 */
typedef struct 
{
	int datlen;				//节点数据类型长度
	int size;				//队列大小
	LinkQueueNode_t *front;	//队头
	LinkQueueNode_t *rear;	//队尾
}LinkQueue_t;

bool Queue_IsEmpty(Queue_t *q);
bool Queue_IsFull(Queue_t *q);
bool Queue_Create(Queue_t *q, int size, uint datlen);
bool Queue_En(Queue_t *q, void *dat);
bool Queue_De(Queue_t *q, void *dat);
void Queue_Clear(Queue_t *q);
void Queue_Destroy(Queue_t *q);

bool LinkQueue_IsEmpty(LinkQueue_t *q);
void LinkQueue_Create(LinkQueue_t *q, uint datlen);
bool LinkQueue_En(LinkQueue_t *q, void *dat);
bool LinkQueue_De(LinkQueue_t *q, void *dat);
void LinkQueue_Clear(LinkQueue_t *q);
void LinkQueue_Destroy(LinkQueue_t *q);

void testQueue(void);
void testLinkQueue(void);

#endif