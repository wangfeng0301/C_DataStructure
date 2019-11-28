#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>

/*˫����ڵ�ṹ��*/
typedef struct DoubleListNode
{
	int Element;
	struct DoubleListNode* pre;//ǰ��
	struct DoubleListNode* next;//���
}DoubleLinkNode;

DoubleLinkNode *CreatDoubleLinkList(unsigned int n);//��������
void TraverseDoubleList(DoubleLinkNode *list);//��������
void ChangeDoubleNodeValue(DoubleLinkNode * list,unsigned int n);//�޸ĵ�n���ڵ��ֵ
void InsertDoubleNode(DoubleLinkNode *list,unsigned int n);//�ڵ�n���ڵ�ǰ�����½ڵ�
void DeleteDoubleNote(DoubleLinkNode *list,unsigned int n);//ɾ����n���ڵ�
void DeleteDoubleLinkList(DoubleLinkNode *list);//ɾ������

DoubleLinkNode *CreatCycDoubleLinkList(unsigned int n);
void TraverseCycDoubleList(DoubleLinkNode *list);//����ѭ������
void ChangeCycDoubleNodeValue(DoubleLinkNode * list,unsigned int n);//�޸Ľڵ�ֵ
void InsertCycDoubleNode(DoubleLinkNode *list,unsigned int n);
void AddCycDoubleNode(DoubleLinkNode *list,unsigned int num);
void DeleteCycDoubleNote(DoubleLinkNode *list,unsigned int n);//ɾ��ָ���ڵ�
void DeleteCycDoubleLinkList(DoubleLinkNode *list);

void josephus(unsigned int n,unsigned int s,unsigned int m);

void testDoubleLink();
void testCycDoubleLink();
#endif