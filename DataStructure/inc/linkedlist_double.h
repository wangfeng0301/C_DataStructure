#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>
/* 链表节点中数据的结构体 */
typedef struct
{
	int element;
}DoubleLinkData_t;
/*双向链表节点结构体*/
typedef struct DoubleListNode
{
	DoubleLinkData_t data;	
	struct DoubleListNode* pre;//前驱
	struct DoubleListNode* next;//后继
}DoubleLinkNode_t;

DoubleLinkNode_t *Double_CreatLinkList(unsigned int n, DoubleLinkData_t *dat);//创建链表
void Double_TraverseList(DoubleLinkNode_t *list);//遍历链表
void Double_ChangeNodeValue(DoubleLinkNode_t * list,unsigned int n, DoubleLinkData_t dat);//修改第n个节点的值
void Double_InsertNode(DoubleLinkNode_t *list,unsigned int n, DoubleLinkData_t dat);//在第n个节点前插入新节点
void Double_DeleteNode(DoubleLinkNode_t *list,unsigned int n);//删除第n个节点
void Double_DeleteLinkList(DoubleLinkNode_t *list);//删除链表

DoubleLinkNode_t *CycDouble_CreatLinkList(unsigned int n, DoubleLinkData_t *dat);//创建双向循环链表
void CycDouble_TraverseList(DoubleLinkNode_t *list);//遍历循环链表
void CycDouble_ChangeNodeValue(DoubleLinkNode_t * list,unsigned int n, DoubleLinkData_t dat);//修改节点值
void CycDouble_InsertNode(DoubleLinkNode_t *list,unsigned int n, DoubleLinkData_t dat);
void CycDouble_AddNode(DoubleLinkNode_t *list, DoubleLinkData_t dat);
void CycDouble_DeleteNode(DoubleLinkNode_t *list,unsigned int n);//删除指定节点
void CycDouble_DeleteLinkList(DoubleLinkNode_t *list);

void testDoubleLink(void);
void testCycDoubleLink(void);
#endif