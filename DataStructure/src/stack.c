/*********************************************************************
*ջ����������ջ����ջ��ѹջ�����ջ
*��ʽջ����������ջ����ջ��ѹջ�����ջ��
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

/************************˳��ջ������ȳ�***********************************/

/************************************************************************
 *���ܣ�����ջ
 *���룺s��ջָ�� 
 *		size:ջ�Ĵ�С
 *�������
 *���أ���
************************************************************************/
void CreateStack(Stack_t *s,int size)
{
	 s->size = size;
	 s->top = -1;//ջ����Ҳ��ʾ��ǰջ��Ԫ�صĸ�����1
	 s->st = (StackData_t *)malloc(size*sizeof(StackData_t));//����size���ֽڿռ�
}
/************************************************************************
 *���ܣ�ѹջ
 *���룺s��ջָ�� 
 *		dat:ѹջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Push(Stack_t *s,StackData_t dat)
{
	if(s->top < s->size-1)//ջ��С��ջ��������
	{
		(s->top)++;//ջ����1
		s->st[s->top] = dat;//ջ��ֵ
		return TRUE;
	}
	else
	{
		printf("ջ�����\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ���ջ
 *���룺s��ջָ�� 
 *		dat:��ջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Pop(Stack_t *s,StackData_t *dat)
{
	if(s->top > -1)//ջ�ǿ�
	{
		*dat = s->st[s->top];
		(s->top)--;
		return TRUE;
	}
	else
	{
		printf("ջ��\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ����ջ
 *���룺s��ջָ�� 
 *�������
 *���أ���
************************************************************************/
void Clear(Stack_t *s)
{
	s->top = -1;
}

/************************************************************************
 *���ܣ���ȡջ��Ԫ�ظ���
 *���룺s��ջָ�� 
 *�������
 *���أ�ջ��Ԫ�ظ���
************************************************************************/
int GetTop(Stack_t *s)
{
	return (s->top)+1;
}

/***************************��ʽջ*************************************/
/************************************************************************
 *���ܣ�����ջ,��ʽջ������ǰ���ٴ�С��������ѹջʱ��̬���ٿռ�
 *���룺s��ջָ�� 
 *�������
 *���أ���
************************************************************************/
void CreateLinkStack(LinkStack_t *s)
{
	s->size = 0;//��ʼ��Ϊ��ջ
	s->top = NULL;//ָ���
}
/************************************************************************
 *���ܣ�ѹջ,����ײ���ڵ㣬��Ϊ����ڵ�
 *���룺s��ջָ�� 
 *		dat:ѹջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool LSpush(LinkStack_t *s,StackData_t dat)
{
	LinkStackNode_t *temp = (LinkStackNode_t *)malloc(sizeof(LinkStackNode_t));//���ٿռ�,��СΪLinkStackNode_t
	if(s->top == NULL)		//��һ��ѹջ��Ԫ��
	{
		s->top = temp;		//ջ��ָ��ǰ�ռ�
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;//�½��ڵ�ָ��֮ǰ�Ľڵ㣬�൱����֮ǰ�ڵ�������½ڵ�
		s->top = temp;
	}
	s->top->data = dat;		//��ֵ
	s->size++;				//ջ��С��1
	return TRUE;
}

/************************************************************************
 *���ܣ���ջ
 *���룺s��ջָ�� 
 *		dat:��ջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool LSpop(LinkStack_t *s, StackData_t *dat)
{
	LinkStackNode_t *tempNode;//��ʱ�ڵ�
	if(s->top != NULL)//ջ�ǿ�
	{
		*dat = s->top->data;//��ȡԪ��
		tempNode = s->top;//��ǰ�ڵ����ʱ�ڵ�
		s->top = s->top->next;//ָ����һ���ڵ�
		free(tempNode);
		tempNode = NULL;
		s->size--;//ջ��С��1

		return TRUE;
	}
	else
	{
		printf("ջ��\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ����ջ
 *���룺s��ջָ�� 
 *�������
 *���أ���
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
		printf("��ջ�ɹ���\r\n");
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
		printf("ջ��ʣ��ڵ�������%d\r\n",GetTop(&data));
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

	printf("��ջ��\r\n");
	while(linkstack.top != NULL)
	{
		LSpop(&linkstack,&dat);
		printf("data->[] = %d\r\n",dat.element);	
	}
	LSclear(&linkstack);
	if(TRUE == LSpop(&linkstack,&dat))
		printf("%d\r\n",dat.element);
}