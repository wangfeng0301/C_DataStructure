#ifndef __LINK_H__
#define __LINK_H__

//#include <stdio.h>



/*����ڵ�ṹ��*/
typedef struct ListNode
{
	int Element;
	struct ListNode* next;
}LinkNode;

LinkNode *CreatLinkList(int n);//��������
void TraverseList(LinkNode *list);//��������
void InsertNode(LinkNode *list,int n);//�ڵ�n���ڵ�ǰ�����½ڵ�
void ChangeNodeValue(LinkNode * list,int n);//�޸ĵ�n���ڵ��ֵ
void DeleteNote(LinkNode *list,int n);//ɾ����n���ڵ�
void DeleteLinkList(LinkNode *list);//ɾ������

void testLink();

#endif