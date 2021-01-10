#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>

/*双向链表节点结构体*/
typedef struct DoubleListNode
{
	int Element;
	struct DoubleListNode* pre;//前驱
	struct DoubleListNode* next;//后继
}DoubleLinkNode;

DoubleLinkNode *Double_CreatLinkList(unsigned int n);//创建链表
void Double_TraverseList(DoubleLinkNode *list);//遍历链表
void Double_ChangeNodeValue(DoubleLinkNode * list,unsigned int n);//修改第n个节点的值
void Double_InsertNode(DoubleLinkNode *list,unsigned int n);//在第n个节点前插入新节点
void Double_DeleteNote(DoubleLinkNode *list,unsigned int n);//删除第n个节点
void Double_DeleteLinkList(DoubleLinkNode *list);//删除链表

DoubleLinkNode *CycDouble_CreatLinkList(unsigned int n);//创建双向循环链表
void CycDouble_TraverseList(DoubleLinkNode *list);//遍历循环链表
void CycDouble_ChangeNodeValue(DoubleLinkNode * list,unsigned int n);//修改节点值
void CycDouble_InsertNode(DoubleLinkNode *list,unsigned int n);
void CycDouble_AddNode(DoubleLinkNode *list);
void CycDouble_DeleteNote(DoubleLinkNode *list,unsigned int n);//删除指定节点
void CycDouble_DeleteLinkList(DoubleLinkNode *list);

void testDoubleLink(void);
void testCycDoubleLink(void);
#endif