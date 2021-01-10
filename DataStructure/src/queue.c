/************************************************************************
 *���У��Ƚ��ȳ���һ�����ݽṹ
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *2019.11.29-2020.12.7
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/************************************************************************
 *���ܣ���������
 *���룺q:����ָ��
 *		size:���д�С
 *�����q:����ָ��
 *���أ���
************************************************************************/
void CreateQueue(Queue *q,int size)
{
	q->qu = (char *)malloc((size+1)*sizeof(char));//����size+1���ֽڿռ�
	q->front = q->rear = 0;
	q->size = size+1;
}

/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��
 *		c:���д�С
 *�����q:����ָ��
 *���أ���
************************************************************************/
void enQueue(Queue *q,char c)
{
	if((q->rear+1)%q->size == q->front)//
	{
		printf("��������\r\n");
		return;
	}
	else
	{
		q->qu[q->rear] = c;//��β��������
		q->rear = (q->rear+1)%q->size;//ѭ�����
	}
}

//������
char deQueue(Queue *q)
{
	char temp;
	if(q->front == q->rear)
	{
		printf("����Ϊ��\r\n");
		return 0;
	}
	else
	{
		temp = q->qu[q->front];
		q->front = (q->front+1)%(q->size);//ѭ�����
		return temp;
	}
}

//��ն���
void ClearQueue(Queue *q)
{
	q->front = q->rear = 0;
}

void testQueue(void)
{
	Queue q;
	CreateQueue(&q,3);
	enQueue(&q,10);
	enQueue(&q,20);
	enQueue(&q,30);
	enQueue(&q,40);
	enQueue(&q,50);
	printf("%d\r\n",deQueue(&q));
	ClearQueue(&q);
	printf("%d\r\n",deQueue(&q));
	printf("%d\r\n",deQueue(&q));
	printf("%d\r\n",deQueue(&q));
}