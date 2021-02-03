#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "type.h"

typedef struct  
{
	int size;//���д�С
	int front;//��ͷ
	int rear;//��β
	void *qu;//����������
	int qulen;//ÿ��Ԫ�صĴ�С���ֽڣ�
}Queue_t;

/*��ʽ���нڵ�ṹ��*/
typedef struct LinkQueueNode
{
	void *data;
	struct LinkQueueNode* next;
}LinkQueueNode_t;
/* ��ʽ���нṹ�� */
typedef struct 
{
	int datlen;				//�ڵ��������ͳ���
	int size;				//���д�С
	LinkQueueNode_t *front;	//��ͷ
	LinkQueueNode_t *rear;	//��β
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