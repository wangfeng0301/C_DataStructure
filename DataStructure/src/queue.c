/************************************************************************
 *队列：先进先出的一种数据结构
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.3
 *2021.2.3	修改，不受数据类型限制
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
/************************ 顺序队列 ***********************************/
/************************************************************************
 *功能：队列是否为空
 *输入：q:队列指针
 *输出：无
 *返回：空返回TRUE;非空返回FALSE
************************************************************************/
bool Queue_IsEmpty(Queue_t *q)
{
	if(q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}
/************************************************************************
 *功能：队列是否为满
 *输入：q:队列指针
 *输出：无
 *返回：满返回TRUE;未满返回FALSE
************************************************************************/
bool Queue_IsFull(Queue_t *q)
{
	if((q->rear+1)%q->size == q->front)
		return TRUE;
	else
		return FALSE;
}
/************************************************************************
 *功能：创建队列
 *输入：q:队列指针
 *		size:队列大小
 *		datlen:队列元素数据类型大小（字节）
 *输出：无
 *返回：无
************************************************************************/
bool Queue_Create(Queue_t *q, int size, uint datlen)
{
	q->qu = (void *)malloc((size + 1) * datlen);//开辟size+1个数据类型空间
	if(q->qu == NULL)
		return FALSE;
	q->front = q->rear = 0;
	q->size = size+1;
	q->qulen = datlen;
	return TRUE;
}

/************************************************************************
 *功能：进队列
 *输入：q:队列指针
 *		dat:进队列的数据
 *输出：q:队列指针
 *返回：TRUE or FLASE
************************************************************************/
bool Queue_En(Queue_t *q,void *dat)
{
	if(Queue_IsFull(q))
	{
		printf("队列已满\r\n");
		return FALSE;
	}
	else
	{
		//q->qu[q->rear] = dat;//队尾存入数据
		memcpy((void *)((uint)(q->qu) + (q->rear)*(q->qulen)), dat, q->qulen);
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
bool Queue_De(Queue_t *q, void *dat)
{
	//if(q->front == q->rear)
	if(Queue_IsEmpty(q))
	{
		printf("队列为空\r\n");
		return FALSE;
	}
	else
	{
		//*dat = q->qu[q->front];
		memcpy(dat, (void *)((uint)(q->qu) + (q->front)*(q->qulen)), q->qulen);
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
void Queue_Clear(Queue_t *q)
{
	q->front = q->rear = 0;
}
/************************************************************************
 *功能：销毁队列
 *输入：q:队列指针	
 *输出：无
 *返回：无
************************************************************************/
void Queue_Destroy(Queue_t *q)
{
	Queue_Clear(q);
	free(q->qu);
	q->qu = NULL;
}

/************************ 链式队列 ***********************************/
/************************************************************************
 *功能：队列是否为空
 *输入：q:队列指针
 *输出：无
 *返回：空返回TRUE;非空返回FALSE
************************************************************************/
bool LinkQueue_IsEmpty(LinkQueue_t *q)
{
	if(q->size == 0)
		return TRUE;
	else
		return FALSE;
}
/************************************************************************
 *功能：创建队列,链式队列不用提前开辟大小，可以在入队列时动态开辟空间
 *输入：q:队列指针
 *		size:队列大小
 *输出：q:队列指针
 *返回：无
************************************************************************/
void LinkQueue_Create(LinkQueue_t *q, uint datlen)
{
	/* 为减少访问队首节点的时间代价，不使用专用表头虚节点 */
	q->size = 0;
	q->front = q->rear = NULL;
	q->datlen = datlen;
}
/************************************************************************
 *功能：进队列
 *输入：q:队列指针
 *		dat:进队列的数据
 *输出：q:队列指针
 *返回：TRUE or FLASE
************************************************************************/
bool LinkQueue_En(LinkQueue_t *q, void *dat)
{
	LinkQueueNode_t *temp;

	temp = (LinkQueueNode_t *)malloc(sizeof(LinkQueueNode_t));//申请新节点
	temp->data = (void *)malloc(q->datlen);//申请数据区
	if(temp == NULL || temp->data == NULL)
	{
		printf("申请内存失败r\n");
		return FALSE;
	}
	//temp->data = dat;//新节点赋值
	memcpy(temp->data, dat, q->datlen);
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
bool LinkQueue_De(LinkQueue_t *q, void *dat)
{
	LinkQueueNode_t *temp;

	//if(q->rear == NULL)
	if(LinkQueue_IsEmpty(q))
	{
		printf("队列为空\r\n");
		return FALSE;
	}
	//*dat = q->front->data;//取数据
	memcpy(dat, q->front->data, q->datlen);
	temp = q->front;
	q->front = q->front->next;
	free(temp->data);						//释放取出的节点数据区
	temp->data = NULL;
	free(temp);								//释放取出的节点
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
	printf("清空队列成功\r\n");
}
/************************************************************************
 *功能：销毁队列
 *输入：q:队列指针	
 *输出：无
 *返回：无
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