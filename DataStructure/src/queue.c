/************************************************************************
 *队列：先进先出的一种数据结构
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *2019.11.29-2021.1.12
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/************************ 顺序队列 ***********************************/
/************************************************************************
 *功能：创建队列
 *输入：q:队列指针
 *		size:队列大小
 *输出：q:队列指针
 *返回：无
************************************************************************/
void CreateQueue(Queue_t *q,int size)
{
	q->qu = (QueueData_t *)malloc((size+1)*sizeof(QueueData_t));//开辟size+1个字节空间
	q->front = q->rear = 0;
	q->size = size+1;
}

/************************************************************************
 *功能：进队列
 *输入：q:队列指针
 *		dat:进队列的数据
 *输出：q:队列指针
 *返回：TRUE or FLASE
************************************************************************/
bool EnQueue(Queue_t *q,QueueData_t dat)
{
	if((q->rear+1)%q->size == q->front)//
	{
		printf("队列已满\r\n");
		return FALSE;
	}
	else
	{
		q->qu[q->rear] = dat;//队尾存入数据
		q->rear = (q->rear+1)%q->size;//循环后继
		return TRUE;
	}
}

/************************************************************************
 *功能：出队列
 *输入：q:队列指针	
 *输出：dat:出队列的数据
 *返回：TRUE or FLASE
************************************************************************/
bool DeQueue(Queue_t *q, QueueData_t *dat)
{
	if(q->front == q->rear)
	{
		printf("队列为空\r\n");
		return FALSE;
	}
	else
	{
		*dat = q->qu[q->front];
		q->front = (q->front+1)%(q->size);//循环后继
		return TRUE;
	}
}

/************************************************************************
 *功能：清空队列
 *输入：q:队列指针	
 *输出：无
 *返回：无
************************************************************************/
void ClearQueue(Queue_t *q)
{
	q->front = q->rear = 0;
}

/************************ 链式队列 ***********************************/
/************************************************************************
 *功能：创建队列,链式队列不用提前开辟大小，可以在入队列时动态开辟空间
 *输入：q:队列指针
 *		size:队列大小
 *输出：q:队列指针
 *返回：无
************************************************************************/
void CreateLinkQueue(LinkQueue_t *q)
{
	/* 为减少访问队首节点的时间代价，不使用专用表头虚节点 */
	q->size = 0;
	q->front = q->rear = NULL;
}
/************************************************************************
 *功能：进队列
 *输入：q:队列指针
 *		dat:进队列的数据
 *输出：q:队列指针
 *返回：TRUE or FLASE
************************************************************************/
bool EnLinkQueue(LinkQueue_t *q,QueueData_t dat)
{
	LinkQueueNode_t *temp;

	temp = (LinkQueueNode_t*)malloc(sizeof(LinkQueueNode_t));//申请新节点
	if(temp == NULL)
	{
		printf("申请内存失败r\n");
		exit(-1);
	}
	temp->data = dat;//新节点赋值
	temp->next = NULL;
	if(q->rear == NULL)//队列为空
	{	
		q->front = q->rear = temp;
	}
	else
	{
		q->rear->next = temp;//新节点加在队尾
		q->rear = q->rear->next;
	}
	q->size ++;
	return TRUE;
}
/************************************************************************
 *功能：出队列
 *输入：q:队列指针	
 *输出：dat:出队列的数据
 *返回：TRUE or FLASE
************************************************************************/
bool DeLinkQueue(LinkQueue_t *q, QueueData_t *dat)
{
	LinkQueueNode_t *temp;

	if(q->rear == NULL)
	{
		printf("队列为空\r\n");
		return FALSE;
	}
	*dat = q->front->data;//取数据
	temp = q->front;
	q->front = q->front->next;
	free(temp);//释放取出的节点
	temp = NULL;
	if(q->front == NULL)
		q->rear = NULL;
	q->size --;
	return TRUE;
}
/************************************************************************
 *功能：清空队列
 *输入：q:队列指针	
 *输出：无
 *返回：无
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
	printf("清空队列成功\r\n");
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