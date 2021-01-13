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

//��ն���
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
void CreateLinkQueue(Queue_t *q)
{

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