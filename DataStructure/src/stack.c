/*********************************************************************
*栈：包括创建栈、出栈、压栈、清空栈
*链式栈：包括创建栈、出栈、压栈、清空栈等
*参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

/************************顺序栈：后进先出***********************************/

/************************************************************************
 *功能：创建栈
 *输入：s：栈指针 
 *		size:栈的大小
 *输出：无
 *返回：无
************************************************************************/
void CreateStack(Stack_t *s,int size)
{
	 s->size = size;
	 s->top = -1;//栈顶，也表示当前栈中元素的个数减1
	 s->st = (StackData_t *)malloc(size*sizeof(StackData_t));//开辟size个字节空间
}
/************************************************************************
 *功能：压栈
 *输入：s：栈指针 
 *		dat:压栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Push(Stack_t *s,StackData_t dat)
{
	if(s->top < s->size-1)//栈顶小于栈的最大个数
	{
		(s->top)++;//栈顶加1
		s->st[s->top] = dat;//栈赋值
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
bool Pop(Stack_t *s,StackData_t *dat)
{
	if(s->top > -1)//栈非空
	{
		*dat = s->st[s->top];
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
 *功能：清空栈
 *输入：s：栈指针 
 *输出：无
 *返回：无
************************************************************************/
void Clear(Stack_t *s)
{
	s->top = -1;
}

/************************************************************************
 *功能：获取栈中元素个数
 *输入：s：栈指针 
 *输出：无
 *返回：栈中元素个数
************************************************************************/
int GetTop(Stack_t *s)
{
	return (s->top)+1;
}

/***************************链式栈*************************************/
/************************************************************************
 *功能：创建栈,链式栈不用提前开辟大小，可以在压栈时动态开辟空间
 *输入：s：栈指针 
 *输出：无
 *返回：无
************************************************************************/
void CreateLinkStack(LinkStack_t *s)
{
	s->size = 0;//初始化为空栈
	s->top = NULL;//指向空
}
/************************************************************************
 *功能：压栈,向表首插入节点，作为后入节点
 *输入：s：栈指针 
 *		dat:压栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LSpush(LinkStack_t *s,StackData_t dat)
{
	LinkStackNode_t *temp = (LinkStackNode_t *)malloc(sizeof(LinkStackNode_t));//开辟空间,大小为LinkStackNode_t
	if(s->top == NULL)		//第一个压栈的元素
	{
		s->top = temp;		//栈顶指向当前空间
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;//新建节点指向之前的节点，相当于在之前节点插入了新节点
		s->top = temp;
	}
	s->top->data = dat;		//赋值
	s->size++;				//栈大小加1
	return TRUE;
}

/************************************************************************
 *功能：出栈
 *输入：s：栈指针 
 *		dat:出栈数据
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool LSpop(LinkStack_t *s, StackData_t *dat)
{
	LinkStackNode_t *tempNode;//临时节点
	if(s->top != NULL)//栈非空
	{
		*dat = s->top->data;//提取元素
		tempNode = s->top;//当前节点给临时节点
		s->top = s->top->next;//指向下一个节点
		free(tempNode);
		tempNode = NULL;
		s->size--;//栈大小减1

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
 *返回：无
************************************************************************/
void LSclear(LinkStack_t *s)
{
	LinkStackNode_t *temp;
	while(s->top != 0)
	{
		temp = s->top->next;
		free(s->top);
		s->top = temp;
	}
	if(s->top == NULL)
	{
		s->size = 0;
		printf("清栈成功！\r\n");
	}
}


void testStack(void)
{
	Stack_t data;
	StackData_t dat;
	
	CreateStack(&data,10);
	dat.element = 10;
	Push(&data,dat);
	dat.element = 20;
	Push(&data,dat);
	while(data.top > -1)
	{
		Pop(&data,&dat);
		printf("data->[%d] = %d\r\n",data.top,dat.element);	
		printf("栈中剩余节点数量：%d\r\n",GetTop(&data));
	}
}

void testLinkStack(void)
{
	LinkStack_t linkstack;
	StackData_t dat;

	CreateLinkStack(&linkstack);
	dat.element = 100;
	LSpush(&linkstack,dat);
	dat.element = 200;
	LSpush(&linkstack,dat);
	dat.element = 300;
	LSpush(&linkstack,dat);

	printf("出栈：\r\n");
	while(linkstack.top != NULL)
	{
		LSpop(&linkstack,&dat);
		printf("data->[] = %d\r\n",dat.element);	
	}
	LSclear(&linkstack);
	if(TRUE == LSpop(&linkstack,&dat))
		printf("%d\r\n",dat.element);
}