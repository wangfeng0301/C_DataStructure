#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>

/*˫������ڵ�ṹ��*/
typedef struct DoubleListNode
{
	int Element;
	struct DoubleListNode* pre;//ǰ��
	struct DoubleListNode* next;//���
}DoubleLinkNode;

DoubleLinkNode *Double_CreatLinkList(unsigned int n);//��������
void Double_TraverseList(DoubleLinkNode *list);//��������
void Double_ChangeNodeValue(DoubleLinkNode * list,unsigned int n);//�޸ĵ�n���ڵ��ֵ
void Double_InsertNode(DoubleLinkNode *list,unsigned int n);//�ڵ�n���ڵ�ǰ�����½ڵ�
void Double_DeleteNote(DoubleLinkNode *list,unsigned int n);//ɾ����n���ڵ�
void Double_DeleteLinkList(DoubleLinkNode *list);//ɾ������

DoubleLinkNode *CycDouble_CreatLinkList(unsigned int n);//����˫��ѭ������
void CycDouble_TraverseList(DoubleLinkNode *list);//����ѭ������
void CycDouble_ChangeNodeValue(DoubleLinkNode * list,unsigned int n);//�޸Ľڵ�ֵ
void CycDouble_InsertNode(DoubleLinkNode *list,unsigned int n);
void CycDouble_AddNode(DoubleLinkNode *list);
void CycDouble_DeleteNote(DoubleLinkNode *list,unsigned int n);//ɾ��ָ���ڵ�
void CycDouble_DeleteLinkList(DoubleLinkNode *list);

void testDoubleLink(void);
void testCycDoubleLink(void);
#endif