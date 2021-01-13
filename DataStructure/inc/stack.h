#ifndef __STACK_H__
#define __STACK_H__
#include "type.h"

/* 栈数据结构体 */
typedef struct
{
	//char c;
	int element;
}StackData_t;
/* 栈结构体 */
typedef struct  
{
	int size;//栈的大小
	int top;//栈顶
	StackData_t *st;//存放栈元素的数组
}Stack_t;

/*链式栈节点结构体*/
typedef struct LinkStackNode
{
	StackData_t data;
	struct LinkStackNode* next;
}LinkStackNode_t;
/* 链式栈结构体，栈空间由链表组成 */
typedef struct
{
	LinkStackNode_t *top;//链表结构体
	int size;
}LinkStack_t;

void CreateStack(Stack_t *s,int size);//创建栈
bool Push(Stack_t *s,StackData_t dat);
bool Pop(Stack_t *s,StackData_t *dat);
void Clear(Stack_t *s);//清空栈
int GetTop(Stack_t *s);

void CreateLinkStack(LinkStack_t *s);
bool LSpush(LinkStack_t *s,StackData_t dat);
bool LSpop(LinkStack_t *s, StackData_t *dat);
void LSclear(LinkStack_t *s);

void testStack(void);
void testLinkStack(void);

#endif