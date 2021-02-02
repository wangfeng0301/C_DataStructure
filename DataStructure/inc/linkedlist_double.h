#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__
#include "type.h"

/*˫������ڵ�ṹ��*/
typedef struct DoubleLinkNode
{
	void *data;	
	struct DoubleLinkNode *pre;//ǰ��
	struct DoubleLinkNode *next;//���
}DoubleLinkNode_t;

typedef struct
{
	int datlen;//�ڵ��������ͳ���
	DoubleLinkNode_t *node;//�ڵ�
}DoubleLinkList_t;

bool DoubleLink_IsExist(DoubleLinkList_t *list);
bool DoubleLink_IsEmpty(DoubleLinkList_t *list);
bool DoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen);//��������
bool DoubleLink_Traverse(DoubleLinkList_t *list);//��������
bool DoubleLink_ChangeNodeValue(DoubleLinkList_t *list, unsigned int n, void *dat);//�޸ĵ�n���ڵ��ֵ
bool DoubleLink_InsertNode(DoubleLinkList_t *list, unsigned int n, void *dat);//�ڵ�n���ڵ�ǰ�����½ڵ�
bool DoubleLink_GetNodeValue(DoubleLinkList_t *list, unsigned int n, void *dat);//��ȡ��n���ڵ��ֵ
bool DoubleLink_DeleteNode(DoubleLinkList_t *list, unsigned int n);//ɾ����n���ڵ�
bool DoubleLink_Clear(DoubleLinkList_t *list);
bool DoubleLink_Destroy(DoubleLinkList_t *list);//��������

bool CycDoubleLink_IsExist(DoubleLinkList_t *list);
bool CycDoubleLink_IsEmpty(DoubleLinkList_t *list);
bool CycDoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen);//����˫��ѭ������
bool CycDoubleLink_Traverse(DoubleLinkList_t *list);//����ѭ������
bool CycDoubleLink_ChangeNodeValue(DoubleLinkList_t * list,unsigned int n, void *dat);//�޸Ľڵ�ֵ
bool CycDoubleLink_InsertNode(DoubleLinkList_t *list,unsigned int n, void *dat);
bool CycDoubleLink_AddNode(DoubleLinkList_t *list, void *dat);
bool CycDoubleLink_GetNodeValue(DoubleLinkList_t *list,unsigned int n, void *dat);
bool CycDoubleLink_DeleteNode(DoubleLinkList_t *list,unsigned int n);//ɾ��ָ���ڵ�
bool CycDoubleLink_Clear(DoubleLinkList_t *list);
bool CycDoubleLink_Destroy(DoubleLinkList_t *list);

void testDoubleLink(void);
void testCycDoubleLink(void);
#endif