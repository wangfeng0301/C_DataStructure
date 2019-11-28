#ifndef __LINK_H__
#define __LINK_H__

//#include <stdio.h>



/*链表节点结构体*/
typedef struct ListNode
{
	int Element;
	struct ListNode* next;
}LinkNode;

LinkNode *CreatLinkList(int n);//创建链表
void TraverseList(LinkNode *list);//遍历链表
void InsertNode(LinkNode *list,int n);//在第n个节点前插入新节点
void ChangeNodeValue(LinkNode * list,int n);//修改第n个节点的值
void DeleteNote(LinkNode *list,int n);//删除第n个节点
void DeleteLinkList(LinkNode *list);//删除链表

void testLink();

#endif