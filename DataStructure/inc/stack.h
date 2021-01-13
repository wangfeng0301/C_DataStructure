#ifndef __STACK_H__
#define __STACK_H__
#include "type.h"

/* ջ���ݽṹ�� */
typedef struct
{
	//char c;
	int element;
}StackData_t;
/* ջ�ṹ�� */
typedef struct  
{
	int size;//ջ�Ĵ�С
	int top;//ջ��
	StackData_t *st;//���ջԪ�ص�����
}Stack_t;

/*��ʽջ�ڵ�ṹ��*/
typedef struct LinkStackNode
{
	StackData_t data;
	struct LinkStackNode* next;
}LinkStackNode_t;
/* ��ʽջ�ṹ�壬ջ�ռ���������� */
typedef struct
{
	LinkStackNode_t *top;//����ṹ��
	int size;
}LinkStack_t;

void CreateStack(Stack_t *s,int size);//����ջ
bool Push(Stack_t *s,StackData_t dat);
bool Pop(Stack_t *s,StackData_t *dat);
void Clear(Stack_t *s);//���ջ
int GetTop(Stack_t *s);

void CreateLinkStack(LinkStack_t *s);
bool LSpush(LinkStack_t *s,StackData_t dat);
bool LSpop(LinkStack_t *s, StackData_t *dat);
void LSclear(LinkStack_t *s);

void testStack(void);
void testLinkStack(void);

#endif