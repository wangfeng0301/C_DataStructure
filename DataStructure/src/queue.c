/************************************************************************
 *队列：先进先出的一种数据结构
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *2019.11.29-2020.12.7
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/************************************************************************
 *功能：创建队列
 *输入：q:队列指针
 *		size:队列大小
 *输出：q:队列指针
 *返回：无
************************************************************************/
void CreateQueue(Queue *q,int size)
{
	q->qu = (char *)malloc((size+1)*sizeof(char));//开辟size+1个字节空间
	q->front = q->rear = 0;
	q->size = size+1;
}

/************************************************************************
 *功能：进队列
 *输入：q:队列指针
 *		c:队列大小
 *输出：q:队列指针
 *返回：无
************************************************************************/
void enQueue(Queue *q,char c)
{
	if((q->rear+1)%q->size == q->front)//
	{
		printf("队列已满\r\n");
		return;
	}
	else
	{
		q->qu[q->rear] = c;//队尾存入数据
		q->rear = (q->rear+1)%q->size;//循环后继
	}
}

//出队列
char deQueue(Queue *q)
{
	char temp;
	if(q->front == q->rear)
	{
		printf("队列为空\r\n");
		return 0;
	}
	else
	{
		temp = q->qu[q->front];
		q->front = (q->front+1)%(q->size);//循环后继
		return temp;
	}
}

//清空队列
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