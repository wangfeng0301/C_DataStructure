#ifndef __LINK_H__
#define __LINK_H__

/* ����ڵ������ݵĽṹ�� */
typedef struct
{
	int element;
}Data_t;
/*����ڵ�ṹ��*/
typedef struct ListNode
{
	Data_t data;
	struct ListNode* next;
}LinkNode_t;

LinkNode_t *CreatLinkList(int n, Data_t *dat);//��������
void TraverseList(LinkNode_t *list);//��������
void InsertNode(LinkNode_t *list,int n, Data_t dat);//�ڵ�n���ڵ�ǰ�����½ڵ�
void ChangeNodeValue(LinkNode_t * list,int n, Data_t dat);//�޸ĵ�n���ڵ��ֵ
void DeleteNode(LinkNode_t *list,int n);//ɾ����n���ڵ�
void DeleteLinkList(LinkNode_t *list);//ɾ������
void ReverseLinkList(LinkNode_t *list);//��ת����
void testLink(void);

#endif