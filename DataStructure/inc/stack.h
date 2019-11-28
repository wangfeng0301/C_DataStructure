#ifndef __STACK_H__
#define __STACK_H__
#include "link.h"

//�ض�����������
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;


typedef struct  
{
	int size;//ջ�Ĵ�С
	int top;//ջ��
	char *st;//���ջԪ�ص�����
}stack;

//��ʽջ�ṹ��
typedef struct
{
	LinkNode *top;//����ṹ��
	int size;
}LinkStack;

void CreateStack(stack *s,int size);//����ջ
void push(stack *s,char c);
char pop(stack *s);//��ջ
void clear(stack *s);//���ջ

void CreateLinkStack(LinkStack *s);//
void LSpush(LinkStack *s,int c);//ѹջ
int LSpop(LinkStack *s);//��ջ
void LSclear(LinkStack *s);

long factorial_recursion(long n);//n�Ľ׳ˣ��ݹ鷽ʽ
long factorial_iteration(long n);//n�Ľ׳ˣ�������ʽ
unsigned char knap_recursion(int s,int n,int* w);//�������⣬�ݹ鷽ʽ
unsigned char nonRecKnap(int s,int n,int* w);//�������⣬�ǵݹ鷽ʽ
unsigned char nonRecknapOpt(int s,int n, int* w);//�������⣬�Ż��ǵݹ鷽ʽ

void testStack();
void testLinkStack();
void testRecursion();
#endif