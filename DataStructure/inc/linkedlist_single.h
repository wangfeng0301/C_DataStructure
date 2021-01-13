#ifndef __LINK_H__
#define __LINK_H__

/* 链表节点中数据的结构体 */
typedef struct
{
	int element;
}Data_t;
/*链表节点结构体*/
typedef struct ListNode
{
	Data_t data;
	struct ListNode* next;
}LinkNode_t;

LinkNode_t *CreatLinkList(int n, Data_t *dat);//创建链表
void TraverseList(LinkNode_t *list);//遍历链表
void InsertNode(LinkNode_t *list,int n, Data_t dat);//在第n个节点前插入新节点
void ChangeNodeValue(LinkNode_t * list,int n, Data_t dat);//修改第n个节点的值
void DeleteNode(LinkNode_t *list,int n);//删除第n个节点
void DeleteLinkList(LinkNode_t *list);//删除链表
void ReverseLinkList(LinkNode_t *list);//翻转链表
void testLink(void);

#endif