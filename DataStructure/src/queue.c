#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*循环队列，队列为先进先出*/
//创建队列
void CreateQueue(Queue *q,int size)
{
	q->qu = (char *)malloc((size+1)*sizeof(char));//开辟size+1个字节空间
	q->front = q->rear = 0;
	q->size = size+1;
}

//进队列
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

void testQueue()
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