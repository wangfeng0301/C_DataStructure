/*********************************************************************
*ջ����������ջ����ջ��ѹջ�����ջ
*��ʽջ����������ջ����ջ��ѹջ�����ջ��
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*E-mail:fengwang0301@163.com
*CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
*GitHub:https://github.com/wangfeng0301
*2019.11.28-2021.2.3
*2021.2.2   �޸ģ�����������������
*2021.2.3	���ӣ�Stack_GetTop��LinkStack_GetTop
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "stack.h"

/************************˳��ջ������ȳ�***********************************/

/************************************************************************
 *���ܣ�����ջ
 *���룺s��ջָ�� 
 *		size:ջ�Ĵ�С
 *		datlen:ջԪ���������ʹ�С
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Stack_Create(Stack_t *s, int size, uint datlen)
{
	 s->size = size;
	 s->top = -1;							//ջ����Ҳ��ʾ��ǰջ��Ԫ�صĸ�����1
	 s->st = (void *)malloc(size*datlen);	//����size���ֽڿռ�
	 s->stlen = datlen;
	 return TRUE;
}
/************************************************************************
 *���ܣ��ж�ջ�Ƿ����
 *���룺s��ջָ�� 
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Stack_IsExist(Stack_t *s)
{
	if(s->st == NULL)
	{
		printf("ջ������\r\n");
		return FALSE;
	}
	return TRUE;
}
/************************************************************************
 *���ܣ��ж�ջ�Ƿ��
 *���룺s��ջָ�� 
 *�������
 *���أ�ջ�շ���FALSE;�ǿշ���TRUE
************************************************************************/
bool Stack_IsEmpty(Stack_t *s)
{
	if(Stack_IsExist(s))
	{
		if(s->top > (-1))
			return TRUE;
		else
			printf("ջ��\r\n");
	}
	return FALSE;
}
/************************************************************************
 *���ܣ��ж�ջ�Ƿ���
 *���룺s��ջָ�� 
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Stack_IsFull(Stack_t *s)
{
	if(Stack_IsExist(s))
	{
		if(s->top < s->size-1)//ջ��С��ջ��������
			return TRUE;
		else
			printf("ջ��\r\n");
	}
	return TRUE;
}
/************************************************************************
 *���ܣ�ѹջ
 *���룺s��ջָ�� 
 *		dat:ѹջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Stack_Push(Stack_t *s, void *dat)
{
	if(!Stack_IsFull(s))
		return FALSE;
	if(s->top < s->size-1)//ջ��С��ջ��������
	{
		(s->top)++;//ջ����1
		//s->st[s->top] = dat;//ջ��ֵ
		memcpy((void *)((uint)(s->st) + (s->top)*(s->stlen)), dat, s->stlen);
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
bool Stack_Pop(Stack_t *s, void *dat)
{
	if(!Stack_IsEmpty(s))
		return FALSE;
	if(s->top > -1)//ջ�ǿ�
	{
		//*dat = s->st[s->top];
		memcpy(dat, (void *)((uint)(s->st) + (s->top)*(s->stlen)), s->stlen);
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
 *���ܣ���ȡջ��Ԫ��ֵ����������
 *���룺s��ջָ�� 
 *		dat:��ջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Stack_GetTop(Stack_t *s, void *dat)
{
	if(!Stack_IsEmpty(s))
		return FALSE;
	if(s->top > -1)//ջ�ǿ�
	{
		//*dat = s->st[s->top];
		memcpy(dat, (void *)((uint)(s->st) + (s->top)*(s->stlen)), s->stlen);
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
 *���أ�TRUE or FALSE
************************************************************************/
bool Stack_Clear(Stack_t *s)
{
	s->top = -1;
	return TRUE;
}

/************************************************************************
 *���ܣ���ȡջ��Ԫ�ظ���
 *���룺s��ջָ�� 
 *�������
 *���أ�ջ��Ԫ�ظ���
************************************************************************/
int Stack_GetSize(Stack_t *s)
{
	return (s->top)+1;
}

/************************************************************************
 *���ܣ�����ջ
 *���룺s��ջָ�� 
 *�������
 *���أ�TRUE or FALSE
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


/***************************��ʽջ*************************************/
/************************************************************************
 *���ܣ��ж�ջ�Ƿ��
 *���룺s��ջָ�� 
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool LinkStack_IsEmpty(LinkStack_t *s)
{
	if(s->size > 0)
		return TRUE;
	else
		printf("ջ��\r\n");
	return FALSE;
}
/************************************************************************
 *���ܣ�����ջ,��ʽջ������ǰ���ٴ�С��������ѹջʱ��̬���ٿռ�
 *���룺s��ջָ�� 
 *�������
 *���أ���
************************************************************************/
bool LinkStack_Create(LinkStack_t *s, uint datlen)
{
	s->size = 0;//��ʼ��Ϊ��ջ
	s->top = NULL;//ָ���
	s->datlen = datlen;
	return TRUE;
}
/************************************************************************
 *���ܣ�ѹջ,����ײ���ڵ㣬��Ϊ����ڵ�
 *���룺s��ջָ�� 
 *		dat:ѹջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool LinkStack_Push(LinkStack_t *s, void *dat)
{
	LinkStackNode_t *temp = (LinkStackNode_t *)malloc(sizeof(LinkStackNode_t));//���ٿռ�,��СΪLinkStackNode_t
	if(temp == NULL)
	{
		printf("����ռ�ʧ��\r\n");
		return FALSE;
	}
	temp->data = (void *)malloc(s->datlen);			//�������ݿռ�
	if(temp->data == NULL)
	{
		printf("����ռ�ʧ��\r\n");
		return FALSE;
	}
	if(s->top == NULL)								//��һ��ѹջ��Ԫ��
	{
		s->top = temp;								//ջ��ָ��ǰ�ռ�
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;						//�½��ڵ�ָ��֮ǰ�Ľڵ㣬�൱����֮ǰ�ڵ�������½ڵ�
		s->top = temp;
	}
	//s->top->data = dat;								//��ֵ
	memcpy(s->top->data, dat, s->datlen);
	s->size++;										//ջ��С��1
	return TRUE;
}

/************************************************************************
 *���ܣ���ջ
 *���룺s��ջָ�� 
 *		dat:��ջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool LinkStack_Pop(LinkStack_t *s, void *dat)
{
	LinkStackNode_t *tempNode;					//��ʱ�ڵ�

	if(!LinkStack_IsEmpty(s))
		return FALSE;
	if(s->top != NULL)							//ջ�ǿ�
	{
		//*dat = s->top->data;					//��ȡԪ��
		memcpy(dat, s->top->data, s->datlen);
		tempNode = s->top;						//��ǰ�ڵ����ʱ�ڵ�
		s->top = s->top->next;					//ָ����һ���ڵ�
		free(tempNode->data);					//�ͷ�������
		tempNode->data = NULL;
		free(tempNode);
		tempNode = NULL;
		s->size--;								//ջ��С��1
		return TRUE;
	}
	else
	{
		printf("ջ��\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ���ȡջ��Ԫ�أ�����ջ
 *���룺s��ջָ�� 
 *		dat:��ջ����
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool LinkStack_GetTop(LinkStack_t *s, void *dat)
{
	if(!LinkStack_IsEmpty(s))
		return FALSE;
	if(s->top != NULL)							//ջ�ǿ�
	{
		//*dat = s->top->data;					//��ȡԪ��
		memcpy(dat, s->top->data, s->datlen);
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
 *���أ�TRUE or FALSE
************************************************************************/
bool LinkStack_Clear(LinkStack_t *s)
{
	LinkStackNode_t *temp;

	if(!LinkStack_IsEmpty(s))
		return FALSE;
	while(s->top != 0)
	{
		temp = s->top->next;
		free(s->top->data);					//�ͷ�������
		s->top->data = NULL;
		free(s->top);
		s->top = temp;
	}
	if(s->top == NULL)
	{
		s->size = 0;
		printf("��ջ�ɹ���\r\n");
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
			printf("ջ��ʣ��ڵ�������%d\r\n",Stack_GetSize(&data));

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

	printf("��ջ��\r\n");
	while(linkstack.top != NULL)
	{
		LinkStack_Pop(&linkstack, &dat);
		printf("data->[] = %d\r\n",dat);	
	}
	LinkStack_Clear(&linkstack);
	if(TRUE == LinkStack_Pop(&linkstack, &dat))
		printf("%d\r\n",dat);

}