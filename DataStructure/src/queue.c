/************************************************************************
 *���У��Ƚ��ȳ���һ�����ݽṹ
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *2019.11.29-2021.1.12
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/************************ ˳����� ***********************************/
/************************************************************************
 *���ܣ���������
 *���룺q:����ָ��
 *		size:���д�С
 *�����q:����ָ��
 *���أ���
************************************************************************/
void CreateQueue(Queue_t *q,int size)
{
	q->qu = (QueueData_t *)malloc((size+1)*sizeof(QueueData_t));//����size+1���ֽڿռ�
	q->front = q->rear = 0;
	q->size = size+1;
}

/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��
 *		dat:�����е�����
 *�����q:����ָ��
 *���أ�TRUE or FLASE
************************************************************************/
bool EnQueue(Queue_t *q,QueueData_t dat)
{
	if((q->rear+1)%q->size == q->front)//
	{
		printf("��������\r\n");
		return FALSE;
	}
	else
	{
		q->qu[q->rear] = dat;//��β��������
		q->rear = (q->rear+1)%q->size;//ѭ�����
		return TRUE;
	}
}

/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��	
 *�����dat:�����е�����
 *���أ�TRUE or FLASE
************************************************************************/
bool DeQueue(Queue_t *q, QueueData_t *dat)
{
	if(q->front == q->rear)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	else
	{
		*dat = q->qu[q->front];
		q->front = (q->front+1)%(q->size);//ѭ�����
		return TRUE;
	}
}

/************************************************************************
 *���ܣ���ն���
 *���룺q:����ָ��	
 *�������
 *���أ���
************************************************************************/
void ClearQueue(Queue_t *q)
{
	q->front = q->rear = 0;
}

/************************ ��ʽ���� ***********************************/
/************************************************************************
 *���ܣ���������,��ʽ���в�����ǰ���ٴ�С�������������ʱ��̬���ٿռ�
 *���룺q:����ָ��
 *		size:���д�С
 *�����q:����ָ��
 *���أ���
************************************************************************/
void CreateLinkQueue(LinkQueue_t *q)
{
	/* Ϊ���ٷ��ʶ��׽ڵ��ʱ����ۣ���ʹ��ר�ñ�ͷ��ڵ� */
	q->size = 0;
	q->front = q->rear = NULL;
}
/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��
 *		dat:�����е�����
 *�����q:����ָ��
 *���أ�TRUE or FLASE
************************************************************************/
bool EnLinkQueue(LinkQueue_t *q,QueueData_t dat)
{
	LinkQueueNode_t *temp;

	temp = (LinkQueueNode_t*)malloc(sizeof(LinkQueueNode_t));//�����½ڵ�
	if(temp == NULL)
	{
		printf("�����ڴ�ʧ��r\n");
		exit(-1);
	}
	temp->data = dat;//�½ڵ㸳ֵ
	temp->next = NULL;
	if(q->rear == NULL)//����Ϊ��
	{	
		q->front = q->rear = temp;
	}
	else
	{
		q->rear->next = temp;//�½ڵ���ڶ�β
		q->rear = q->rear->next;
	}
	q->size ++;
	return TRUE;
}
/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��	
 *�����dat:�����е�����
 *���أ�TRUE or FLASE
************************************************************************/
bool DeLinkQueue(LinkQueue_t *q, QueueData_t *dat)
{
	LinkQueueNode_t *temp;

	if(q->rear == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	*dat = q->front->data;//ȡ����
	temp = q->front;
	q->front = q->front->next;
	free(temp);//�ͷ�ȡ���Ľڵ�
	temp = NULL;
	if(q->front == NULL)
		q->rear = NULL;
	q->size --;
	return TRUE;
}
/************************************************************************
 *���ܣ���ն���
 *���룺q:����ָ��	
 *�������
 *���أ���
************************************************************************/
void ClearLinkQueue(LinkQueue_t *q)
{
	LinkQueueNode_t *temp;
	while(q->front != NULL)
	{
		temp = q->front;
		free(temp);
		q->front = q->front->next;
	}
	q->rear = NULL;
	q->size = 0;
	printf("��ն��гɹ�\r\n");
}

void testQueue(void)
{
	Queue_t q;
	QueueData_t dat;
	int i;

	CreateQueue(&q,3);
	dat.element = 10;
	EnQueue(&q,dat);
	dat.element = 20;
	EnQueue(&q,dat);
	dat.element = 30;
	EnQueue(&q,dat);
	dat.element = 40;
	EnQueue(&q,dat);
	dat.element = 50;
	EnQueue(&q,dat);
	for(i = 0;i<5;i++)
	{
		if(TRUE == DeQueue(&q,&dat))
			printf("%d\r\n",dat.element);
	}
	ClearQueue(&q);
	if(TRUE == DeQueue(&q,&dat))
		printf("%d\r\n",dat.element);
	
}

void testLinkQueue(void)
{
	LinkQueue_t q;
	QueueData_t dat;
	int i;

	CreateLinkQueue(&q);
	dat.element = 10;
	EnLinkQueue(&q,dat);
	dat.element = 20;
	EnLinkQueue(&q,dat);
	dat.element = 30;
	EnLinkQueue(&q,dat);
	dat.element = 40;
	EnLinkQueue(&q,dat);
	dat.element = 50;
	EnLinkQueue(&q,dat);
	for(i = 0;i<5;i++)
	{
		if(TRUE == DeLinkQueue(&q,&dat))
			printf("%d\r\n",dat.element);
	}
	ClearLinkQueue(&q);
	if(TRUE == DeLinkQueue(&q,&dat))
		printf("%d\r\n",dat.element);
	
}