#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>

/*双链表节点结构体*/
typedef struct DoubleListNode
{
	int Element;
	struct DoubleListNode* pre;//前驱
	struct DoubleListNode* next;//后继
}DoubleLinkNode;

DoubleLinkNode *CreatDoubleLinkList(unsigned int n);//创建链表
void TraverseDoubleList(DoubleLinkNode *list);//遍历链表
void ChangeDoubleNodeValue(DoubleLinkNode * list,unsigned int n);//修改第n个节点的值
void InsertDoubleNode(DoubleLinkNode *list,unsigned int n);//在第n个节点前插入新节点
void DeleteDoubleNote(DoubleLinkNode *list,unsigned int n);//删除第n个节点
void DeleteDoubleLinkList(DoubleLinkNode *list);//删除链表

DoubleLinkNode *CreatCycDoubleLinkList(unsigned int n);
void TraverseCycDoubleList(DoubleLinkNode *list);//遍历循环链表
void ChangeCycDoubleNodeValue(DoubleLinkNode * list,unsigned int n);//修改节点值
void InsertCycDoubleNode(DoubleLinkNode *list,unsigned int n);
void AddCycDoubleNode(DoubleLinkNode *list,unsigned int num);
void DeleteCycDoubleNote(DoubleLinkNode *list,unsigned int n);//删除指定节点
void DeleteCycDoubleLinkList(DoubleLinkNode *list);

void josephus(unsigned int n,unsigned int s,unsigned int m);

void testDoubleLink();
void testCycDoubleLink();
#endif