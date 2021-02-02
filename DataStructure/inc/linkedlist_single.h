#ifndef __LINK_H__
#define __LINK_H__
#include "type.h"

/*����ڵ�ṹ��*/
typedef struct LinkNode
{
	void *data;//�ڵ��������Ͳ���
	struct LinkNode* next;
}LinkNode_t;
typedef struct
{
	int datlen;//�ڵ��������ͳ���
	LinkNode_t *node;//�ڵ�
}LinkList_t;

bool Link_Create(LinkList_t *list, uint n, void *dat, uint datlen);//��������
bool Link_Traverse(LinkList_t *list);//��������
bool Link_InsertNode(LinkList_t *list,int n, void *dat);//�ڵ�n���ڵ�ǰ�����½ڵ�
bool Link_ChangeNodeValue(LinkList_t * list,int n, void *dat);//�޸ĵ�n���ڵ��ֵ
bool Link_DeleteNode(LinkList_t *list,int n);//ɾ����n���ڵ�
bool Link_Clear(LinkList_t *list);
bool Link_Destroy(LinkList_t *list);//��������
bool Link_Reverse(LinkList_t *list);//��ת����
void testLink(void);

#endif