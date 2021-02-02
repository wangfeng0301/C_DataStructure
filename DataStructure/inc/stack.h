#ifndef __STACK_H__
#define __STACK_H__
#include "type.h"

/* 栈结构体 */
typedef struct  
{
	int size;	//栈的大小
	int top;	//栈顶
	void *st;	//存放栈元素的数组
	int stlen;	//每个元素的大小（字节）
}Stack_t;

/* 链式栈节点结构体 */
typedef struct LinkStackNode
{
	void *data;	//节点数据类型不定
	struct LinkStackNode *next;
}LinkStackNode_t;
/* 链式栈结构体，栈空间由链表组成 */
typedef struct
{
	int datlen;	//节点数据类型长度
	LinkStackNode_t *top;//链表结构体
	int size;	//栈大小
}LinkStack_t;

bool Stack_IsExist(Stack_t *s);
bool Stack_IsEmpty(Stack_t *s);
bool Stack_IsFull(Stack_t *s);
bool Stack_Create(Stack_t *s, int size, uint datlen);//创建栈
bool Stack_Push(Stack_t *s, void *dat);
bool Stack_Pop(Stack_t *s, void *dat);
bool Stack_Clear(Stack_t *s);//清空栈
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