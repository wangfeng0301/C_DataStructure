/*********************************************************************
*栈：包括创建栈、出栈、压栈、清空栈
*链式栈：包括创建栈、出栈、压栈、清空栈等
*参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
*wangfeng
*E-mail:fengwang0301@163.com
*CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
*GitHub:https://github.com/wangfeng0301
*2019.11.28-2021.2.3
*2021.2.2   修改，不受数据类型限制
*2021.2.3	增加，Stack_GetTop和LinkStack_GetTop
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "stack.h"

/************************顺序栈：后进先出***********************************/

/************************************************************************
 *功能：创建栈
 *输入：s：栈指针 
 *		size:栈的大小
 *		datlen:栈元素数据类型大小
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_Create(Stack_t *s, int size, uint datlen)
{
	 s->size = size;
	 s->top = -1;							//栈顶，也表示当前栈中元素的个数减1
	 s->st = (void *)malloc(size*datlen);	//开辟size个字节空间
	 s->stlen = datlen;
	 return TRUE;
}
/************************************************************************
 *功能：判断栈是否存在
 *输入：s：栈指针 
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_IsExist(Stack_t *s)
{
	if(s->st == NULL)
	{
		printf("栈不存在\r\n");
		return FALSE;
	}
	return TRUE;
}
/************************************************************************
 *功能：判断栈是否空
 *输入：s：栈指针 
 *输出：无
 *返回：栈空返回FALSE;非空返回TRUE
************************************************************************/
bool Stack_IsEmpty(Stack_t *s)
{
	if(Stack_IsExist(s))
	{
		if(s->top > (-1))
			return TRUE;
		else
			printf("栈空\r\n");
	}
	return FALSE;
}
/************************************************************************
 *功能：判断栈是否满
 *输入：s：栈指针 
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_IsFull(Stack_t *s)
{
	if(Stack_IsExist(s))
	{
		if(s->top < s->size-1)//栈顶小于栈的最大个数
			return TRUE;
		else
			printf("栈满\r\n");
	}
	return TRUE;
}
/************************************************************************
 *功能：压栈
 *输入：s：栈指针 
 *		dat:压栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_Push(Stack_t *s, void *dat)
{
	if(!Stack_IsFull(s))
		return FALSE;
	if(s->top < s->size-1)//栈顶小于栈的最大个数
	{
		(s->top)++;//栈顶加1
		//s->st[s->top] = dat;//栈赋值
		memcpy((void *)((uint)(s->st) + (s->top)*(s->stlen)), dat, s->stlen);
		return TRUE;
	}
	else
	{
		printf("栈满溢出\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：出栈
 *输入：s：栈指针 
 *		dat:出栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_Pop(Stack_t *s, void *dat)
{
	if(!Stack_IsEmpty(s))
		return FALSE;
	if(s->top > -1)//栈非空
	{
		//*dat = s->st[s->top];
		memcpy(dat, (void *)((uint)(s->st) + (s->top)*(s->stlen)), s->stlen);
		(s->top)--;
		return TRUE;
	}
	else
	{
		printf("栈空\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：获取栈顶元素值，但不弹出
 *输入：s：栈指针 
 *		dat:出栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_GetTop(Stack_t *s, void *dat)
{
	if(!Stack_IsEmpty(s))
		return FALSE;
	if(s->top > -1)//栈非空
	{
		//*dat = s->st[s->top];
		memcpy(dat, (void *)((uint)(s->st) + (s->top)*(s->stlen)), s->stlen);
		return TRUE;
	}
	else
	{
		printf("栈空\r\n");
		return FALSE;
	}
}
/************************************************************************
 *功能：清空栈
 *输入：s：栈指针 
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_Clear(Stack_t *s)
{
	s->top = -1;
	return TRUE;
}

/************************************************************************
 *功能：获取栈中元素个数
 *输入：s：栈指针 
 *输出：无
 *返回：栈中元素个数
************************************************************************/
int Stack_GetSize(Stack_t *s)
{
	return (s->top)+1;
}

/************************************************************************
 *功能：销毁栈
 *输入：s：栈指针 
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Stack_Destroy(Stack_t *s)
{
	if(!Stack_IsExist(s))
		return FALSE;
	s->size = 0;
	s->stlen = 0;
	s->top = 0;
	free(s->st);
	s->st = NULL;
	return TRUE;
}


/***************************链式栈*************************************/
/************************************************************************
 *功能：判断栈是否空
 *输入：s：栈指针 
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LinkStack_IsEmpty(LinkStack_t *s)
{
	if(s->size > 0)
		return TRUE;
	else
		printf("栈空\r\n");
	return FALSE;
}
/************************************************************************
 *功能：创建栈,链式栈不用提前开辟大小，可以在压栈时动态开辟空间
 *输入：s：栈指针 
 *输出：无
 *返回：无
************************************************************************/
bool LinkStack_Create(LinkStack_t *s, uint datlen)
{
	s->size = 0;//初始化为空栈
	s->top = NULL;//指向空
	s->datlen = datlen;
	return TRUE;
}
/************************************************************************
 *功能：压栈,向表首插入节点，作为后入节点
 *输入：s：栈指针 
 *		dat:压栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LinkStack_Push(LinkStack_t *s, void *dat)
{
	LinkStackNode_t *temp = (LinkStackNode_t *)malloc(sizeof(LinkStackNode_t));//开辟空间,大小为LinkStackNode_t
	if(temp == NULL)
	{
		printf("申请空间失败\r\n");
		return FALSE;
	}
	temp->data = (void *)malloc(s->datlen);			//开辟数据空间
	if(temp->data == NULL)
	{
		printf("申请空间失败\r\n");
		return FALSE;
	}
	if(s->top == NULL)								//第一个压栈的元素
	{
		s->top = temp;								//栈顶指向当前空间
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;						//新建节点指向之前的节点，相当于在之前节点插入了新节点
		s->top = temp;
	}
	//s->top->data = dat;								//赋值
	memcpy(s->top->data, dat, s->datlen);
	s->size++;										//栈大小加1
	return TRUE;
}

/************************************************************************
 *功能：出栈
 *输入：s：栈指针 
 *		dat:出栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LinkStack_Pop(LinkStack_t *s, void *dat)
{
	LinkStackNode_t *tempNode;					//临时节点

	if(!LinkStack_IsEmpty(s))
		return FALSE;
	if(s->top != NULL)							//栈非空
	{
		//*dat = s->top->data;					//提取元素
		memcpy(dat, s->top->data, s->datlen);
		tempNode = s->top;						//当前节点给临时节点
		s->top = s->top->next;					//指向下一个节点
		free(tempNode->data);					//释放数据区
		tempNode->data = NULL;
		free(tempNode);
		tempNode = NULL;
		s->size--;								//栈大小减1
		return TRUE;
	}
	else
	{
		printf("栈空\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：获取栈顶元素，不出栈
 *输入：s：栈指针 
 *		dat:出栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LinkStack_GetTop(LinkStack_t *s, void *dat)
{
	if(!LinkStack_IsEmpty(s))
		return FALSE;
	if(s->top != NULL)							//栈非空
	{
		//*dat = s->top->data;					//提取元素
		memcpy(dat, s->top->data, s->datlen);
		return TRUE;
	}
	else
	{
		printf("栈空\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：清空栈
 *输入：s：栈指针 
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LinkStack_Clear(LinkStack_t *s)
{
	LinkStackNode_t *temp;

	if(!LinkStack_IsEmpty(s))
		return FALSE;
	while(s->top != 0)
	{
		temp = s->top->next;
		free(s->top->data);					//释放数据区
		s->top->data = NULL;
		free(s->top);
		s->top = temp;
	}
	if(s->top == NULL)
	{
		s->size = 0;
		printf("清栈成功！\r\n");
		return TRUE;
	}
	return FALSE;
}
bool LinkStack_Destroy(LinkStack_t *s)
{
	return LinkStack_Clear(s);
}


void testStack(void)
{
	Stack_t data;
	int dat;
	
	if(!Stack_Create(&data,10, sizeof(dat)))
		printf("Stack_Create Error\r\n");
	dat = 10;
	if(!Stack_Push(&data, &dat))
		printf("Stack_Create Error\r\n");
	dat = 20;
	if(!Stack_Push(&data, &dat))
		printf("Stack_Create Error\r\n");
	dat = 30;
	if(!Stack_Push(&data, &dat))
		printf("Stack_Create Error\r\n");
	while(data.top > -1)
	{
		if(Stack_Pop(&data, &dat))
		{
			printf("data->[%d] = %d\r\n",data.top + 1, dat);	
			printf("栈中剩余节点数量：%d\r\n",Stack_GetSize(&data));

		}
	}
}

void testLinkStack(void)
{
	LinkStack_t linkstack;
	int dat;

	LinkStack_Create(&linkstack, sizeof(int));
	dat = 100;
	LinkStack_Push(&linkstack, &dat);
	dat = 200;
	LinkStack_Push(&linkstack, &dat);
	dat = 300;
	LinkStack_Push(&linkstack, &dat);

	printf("出栈：\r\n");
	while(linkstack.top != NULL)
	{
		LinkStack_Pop(&linkstack, &dat);
		printf("data->[] = %d\r\n",dat);	
	}
	LinkStack_Clear(&linkstack);
	if(TRUE == LinkStack_Pop(&linkstack, &dat))
		printf("%d\r\n",dat);

}