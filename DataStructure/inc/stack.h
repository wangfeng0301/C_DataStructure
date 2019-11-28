#ifndef __STACK_H__
#define __STACK_H__
#include "link.h"

//重定义数据类型
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;


typedef struct  
{
	int size;//栈的大小
	int top;//栈顶
	char *st;//存放栈元素的数组
}stack;

//链式栈结构体
typedef struct
{
	LinkNode *top;//链表结构体
	int size;
}LinkStack;

void CreateStack(stack *s,int size);//创建栈
void push(stack *s,char c);
char pop(stack *s);//出栈
void clear(stack *s);//清空栈

void CreateLinkStack(LinkStack *s);//
void LSpush(LinkStack *s,int c);//压栈
int LSpop(LinkStack *s);//出栈
void LSclear(LinkStack *s);

long factorial_recursion(long n);//n的阶乘，递归方式
long factorial_iteration(long n);//n的阶乘，迭代方式
unsigned char knap_recursion(int s,int n,int* w);//背包问题，递归方式
unsigned char nonRecKnap(int s,int n,int* w);//背包问题，非递归方式
unsigned char nonRecknapOpt(int s,int n, int* w);//背包问题，优化非递归方式

void testStack();
void testLinkStack();
void testRecursion();
#endif