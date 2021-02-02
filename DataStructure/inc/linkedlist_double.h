#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__
#include "type.h"

/*双向链表节点结构体*/
typedef struct DoubleLinkNode
{
	void *data;	
	struct DoubleLinkNode *pre;//前驱
	struct DoubleLinkNode *next;//后继
}DoubleLinkNode_t;

typedef struct
{
	int datlen;//节点数据类型长度
	DoubleLinkNode_t *node;//节点
}DoubleLinkList_t;

bool DoubleLink_IsExist(DoubleLinkList_t *list);
bool DoubleLink_IsEmpty(DoubleLinkList_t *list);
bool DoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen);//创建链表
bool DoubleLink_Traverse(DoubleLinkList_t *list);//遍历链表
bool DoubleLink_ChangeNodeValue(DoubleLinkList_t *list, unsigned int n, void *dat);//修改第n个节点的值
bool DoubleLink_InsertNode(DoubleLinkList_t *list, unsigned int n, void *dat);//在第n个节点前插入新节点
bool DoubleLink_GetNodeValue(DoubleLinkList_t *list, unsigned int n, void *dat);//获取第n个节点的值
bool DoubleLink_DeleteNode(DoubleLinkList_t *list, unsigned int n);//删除第n个节点
bool DoubleLink_Clear(DoubleLinkList_t *list);
bool DoubleLink_Destroy(DoubleLinkList_t *list);//销毁链表

bool CycDoubleLink_IsExist(DoubleLinkList_t *list);
bool CycDoubleLink_IsEmpty(DoubleLinkList_t *list);
bool CycDoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen);//创建双向循环链表
bool CycDoubleLink_Traverse(DoubleLinkList_t *list);//遍历循环链表
bool CycDoubleLink_ChangeNodeValue(DoubleLinkList_t * list,unsigned int n, void *dat);//修改节点值
bool CycDoubleLink_InsertNode(DoubleLinkList_t *list,unsigned int n, void *dat);
bool CycDoubleLink_AddNode(DoubleLinkList_t *list, void *dat);
bool CycDoubleLink_GetNodeValue(DoubleLinkList_t *list,unsigned int n, void *dat);
bool CycDoubleLink_DeleteNode(DoubleLinkList_t *list,unsigned int n);//删除指定节点
bool CycDoubleLink_Clear(DoubleLinkList_t *list);
bool CycDoubleLink_Destroy(DoubleLinkList_t *list);

void testDoubleLink(void);
void testCycDoubleLink(void);
#endif