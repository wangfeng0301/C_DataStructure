/************************************************************************
 *���У��Ƚ��ȳ���һ�����ݽṹ
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.3
 *2021.2.3	�޸ģ�����������������
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
/************************ ˳����� ***********************************/
/************************************************************************
 *���ܣ������Ƿ�Ϊ��
 *���룺q:����ָ��
 *�������
 *���أ��շ���TRUE;�ǿշ���FALSE
************************************************************************/
bool Queue_IsEmpty(Queue_t *q)
{
	if(q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}
/************************************************************************
 *���ܣ������Ƿ�Ϊ��
 *���룺q:����ָ��
 *�������
 *���أ�������TRUE;δ������FALSE
************************************************************************/
bool Queue_IsFull(Queue_t *q)
{
	if((q->rear+1)%q->size == q->front)
		return TRUE;
	else
		return FALSE;
}
/************************************************************************
 *���ܣ���������
 *���룺q:����ָ��
 *		size:���д�С
 *		datlen:����Ԫ���������ʹ�С���ֽڣ�
 *�������
 *���أ���
************************************************************************/
bool Queue_Create(Queue_t *q, int size, uint datlen)
{
	q->qu = (void *)malloc((size + 1) * datlen);//����size+1���������Ϳռ�
	if(q->qu == NULL)
		return FALSE;
	q->front = q->rear = 0;
	q->size = size+1;
	q->qulen = datlen;
	return TRUE;
}

/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��
 *		dat:�����е�����
 *�����q:����ָ��
 *���أ�TRUE or FLASE
************************************************************************/
bool Queue_En(Queue_t *q,void *dat)
{
	if(Queue_IsFull(q))
	{
		printf("��������\r\n");
		return FALSE;
	}
	else
	{
		//q->qu[q->rear] = dat;//��β��������
		memcpy((void *)((uint)(q->qu) + (q->rear)*(q->qulen)), dat, q->qulen);
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
bool Queue_De(Queue_t *q, void *dat)
{
	//if(q->front == q->rear)
	if(Queue_IsEmpty(q))
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	else
	{
		//*dat = q->qu[q->front];
		memcpy(dat, (void *)((uint)(q->qu) + (q->front)*(q->qulen)), q->qulen);
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
void Queue_Clear(Queue_t *q)
{
	q->front = q->rear = 0;
}
/************************************************************************
 *���ܣ����ٶ���
 *���룺q:����ָ��	
 *�������
 *���أ���
************************************************************************/
void Queue_Destroy(Queue_t *q)
{
	Queue_Clear(q);
	free(q->qu);
	q->qu = NULL;
}

/************************ ��ʽ���� ***********************************/
/************************************************************************
 *���ܣ������Ƿ�Ϊ��
 *���룺q:����ָ��
 *�������
 *���أ��շ���TRUE;�ǿշ���FALSE
************************************************************************/
bool LinkQueue_IsEmpty(LinkQueue_t *q)
{
	if(q->size == 0)
		return TRUE;
	else
		return FALSE;
}
/************************************************************************
 *���ܣ���������,��ʽ���в�����ǰ���ٴ�С�������������ʱ��̬���ٿռ�
 *���룺q:����ָ��
 *		size:���д�С
 *�����q:����ָ��
 *���أ���
************************************************************************/
void LinkQueue_Create(LinkQueue_t *q, uint datlen)
{
	/* Ϊ���ٷ��ʶ��׽ڵ��ʱ����ۣ���ʹ��ר�ñ�ͷ��ڵ� */
	q->size = 0;
	q->front = q->rear = NULL;
	q->datlen = datlen;
}
/************************************************************************
 *���ܣ�������
 *���룺q:����ָ��
 *		dat:�����е�����
 *�����q:����ָ��
 *���أ�TRUE or FLASE
************************************************************************/
bool LinkQueue_En(LinkQueue_t *q, void *dat)
{
	LinkQueueNode_t *temp;

	temp = (LinkQueueNode_t *)malloc(sizeof(LinkQueueNode_t));//�����½ڵ�
	temp->data = (void *)malloc(q->datlen);//����������
	if(temp == NULL || temp->data == NULL)
	{
		printf("�����ڴ�ʧ��r\n");
		return FALSE;
	}
	//temp->data = dat;//�½ڵ㸳ֵ
	memcpy(temp->data, dat, q->datlen);
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
bool LinkQueue_De(LinkQueue_t *q, void *dat)
{
	LinkQueueNode_t *temp;

	//if(q->rear == NULL)
	if(LinkQueue_IsEmpty(q))
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	//*dat = q->front->data;//ȡ����
	memcpy(dat, q->front->data, q->datlen);
	temp = q->front;
	q->front = q->front->next;
	free(temp->data);						//�ͷ�ȡ���Ľڵ�������
	temp->data = NULL;
	free(temp);								//�ͷ�ȡ���Ľڵ�
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
void LinkQueue_Clear(LinkQueue_t *q)
{
	LinkQueueNode_t *temp;
	while(q->front != NULL)
	{
		temp = q->front;
		free(temp->data);
		temp->data = NULL;
		free(temp);
		q->front = q->front->next;
	}
	q->rear = NULL;
	q->size = 0;
	printf("��ն��гɹ�\r\n");
}
/************************************************************************
 *���ܣ����ٶ���
 *���룺q:����ָ��	
 *�������
 *���أ���
************************************************************************/
void LinkQueue_Destroy(LinkQueue_t *q)
{
	LinkQueue_Clear(q);
}
void testQueue(void)
{
	Queue_t q;
	int dat;
	int i;

	Queue_Create(&q, 3, sizeof(dat));
	dat = 10;
	Queue_En(&q, &dat);
	dat = 20;
	Queue_En(&q, &dat);
	dat = 30;
	Queue_En(&q, &dat);
	dat = 40;
	Queue_En(&q, &dat);
	dat = 50;
	Queue_En(&q, &dat);
	for(i = 0;i<5;i++)
	{
		if(TRUE == Queue_De(&q, &dat))
			printf("%d\r\n",dat);
	}
	Queue_Clear(&q);
	if(TRUE == Queue_De(&q,&dat))
		printf("%d\r\n",dat);	
}

void testLinkQueue(void)
{
	LinkQueue_t q;
	int dat;
	int i;

	LinkQueue_Create(&q, sizeof(dat));
	dat = 10;
	LinkQueue_En(&q, &dat);
	dat = 20;
	LinkQueue_En(&q, &dat);
	dat = 30;
	LinkQueue_En(&q, &dat);
	dat = 40;
	LinkQueue_En(&q, &dat);
	dat = 50;
	LinkQueue_En(&q, &dat);
	for(i = 0;i<5;i++)
	{
		if(TRUE == LinkQueue_De(&q, &dat))
			printf("%d\r\n",dat);
	}
	LinkQueue_Clear(&q);
	if(TRUE == LinkQueue_De(&q, &dat))
		printf("%d\r\n",dat);
	
}