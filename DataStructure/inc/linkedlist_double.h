#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>
/* ����ڵ������ݵĽṹ�� */
typedef struct
{
	int element;
}DoubleLinkData_t;
/*˫������ڵ�ṹ��*/
typedef struct DoubleListNode
{
	DoubleLinkData_t data;	
	struct DoubleListNode* pre;//ǰ��
	struct DoubleListNode* next;//���
}DoubleLinkNode_t;

DoubleLinkNode_t *Double_CreatLinkList(unsigned int n, DoubleLinkData_t *dat);//��������
void Double_TraverseList(DoubleLinkNode_t *list);//��������
void Double_ChangeNodeValue(DoubleLinkNode_t * list,unsigned int n, DoubleLinkData_t dat);//�޸ĵ�n���ڵ��ֵ
void Double_InsertNode(DoubleLinkNode_t *list,unsigned int n, DoubleLinkData_t dat);//�ڵ�n���ڵ�ǰ�����½ڵ�
void Double_DeleteNode(DoubleLinkNode_t *list,unsigned int n);//ɾ����n���ڵ�
void Double_DeleteLinkList(DoubleLinkNode_t *list);//ɾ������

DoubleLinkNode_t *CycDouble_CreatLinkList(unsigned int n, DoubleLinkData_t *dat);//����˫��ѭ������
void CycDouble_TraverseList(DoubleLinkNode_t *list);//����ѭ������
void CycDouble_ChangeNodeValue(DoubleLinkNode_t * list,unsigned int n, DoubleLinkData_t dat);//�޸Ľڵ�ֵ
void CycDouble_InsertNode(DoubleLinkNode_t *list,unsigned int n, DoubleLinkData_t dat);
void CycDouble_AddNode(DoubleLinkNode_t *list, DoubleLinkData_t dat);
void CycDouble_DeleteNode(DoubleLinkNode_t *list,unsigned int n);//ɾ��ָ���ڵ�
void CycDouble_DeleteLinkList(DoubleLinkNode_t *list);

void testDoubleLink(void);
void testCycDoubleLink(void);
#endif