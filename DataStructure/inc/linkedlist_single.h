#ifndef __LINK_H__
#define __LINK_H__
#include "type.h"

/*链表节点结构体*/
typedef struct LinkNode
{
	void *data;//节点数据类型不定
	struct LinkNode* next;
}LinkNode_t;
typedef struct
{
	int datlen;//节点数据类型长度
	LinkNode_t *node;//节点
}LinkList_t;

bool Link_Create(LinkList_t *list, uint n, void *dat, uint datlen);//创建链表
bool Link_Traverse(LinkList_t *list);//遍历链表
bool Link_InsertNode(LinkList_t *list,int n, void *dat);//在第n个节点前插入新节点
bool Link_ChangeNodeValue(LinkList_t * list,int n, void *dat);//修改第n个节点的值
bool Link_DeleteNode(LinkList_t *list,int n);//删除第n个节点
bool Link_Clear(LinkList_t *list);
bool Link_Destroy(LinkList_t *list);//销毁链表
bool Link_Reverse(LinkList_t *list);//翻转链表
void testLink(void);

#endif