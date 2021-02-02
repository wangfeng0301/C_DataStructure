#ifndef __STACK_H__
#define __STACK_H__
#include "type.h"

/* ջ�ṹ�� */
typedef struct  
{
	int size;	//ջ�Ĵ�С
	int top;	//ջ��
	void *st;	//���ջԪ�ص�����
	int stlen;	//ÿ��Ԫ�صĴ�С���ֽڣ�
}Stack_t;

/* ��ʽջ�ڵ�ṹ�� */
typedef struct LinkStackNode
{
	void *data;	//�ڵ��������Ͳ���
	struct LinkStackNode *next;
}LinkStackNode_t;
/* ��ʽջ�ṹ�壬ջ�ռ���������� */
typedef struct
{
	int datlen;	//�ڵ��������ͳ���
	LinkStackNode_t *top;//����ṹ��
	int size;	//ջ��С
}LinkStack_t;

bool Stack_IsExist(Stack_t *s);
bool Stack_IsEmpty(Stack_t *s);
bool Stack_IsFull(Stack_t *s);
bool Stack_Create(Stack_t *s, int size, uint datlen);//����ջ
bool Stack_Push(Stack_t *s, void *dat);
bool Stack_Pop(Stack_t *s, void *dat);
bool Stack_Clear(Stack_t *s);//���ջ
int Stack_GetTop(Stack_t *s);
bool Stack_Destroy(Stack_t *s);

bool LinkStack_IsEmpty(LinkStack_t *s);
bool LinkStack_Create(LinkStack_t *s, uint datlen);
bool LinkStack_Push(LinkStack_t *s, void *dat);
bool LinkStack_Pop(LinkStack_t *s, void *dat);
bool LinkStack_Clear(LinkStack_t *s);
int Stack_GetSize(LinkStack_t *s);
bool LinkStack_Destroy(LinkStack_t *s);

void testStack(void);
void testLinkStack(void);

#endif