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

//清空队列
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