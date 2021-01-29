/************************************************************************
 *���������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *2019.11.29-2020.12.7
 *2020.12.7  ��������ת
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist_single.h"

/************************************************************************
 *���ܣ���������ͨ�ã������������͸ı���ı�
 *���룺list:������ʼ��ַ
 *		n������ڵ�������������׽ڵ�
 *		dat:Ҫ���������Ԫ��ָ�룬��n=0,�Ĳ����ɴ�NULL
 *		datlen:�������͵ĳ���
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Link_Create(LinkList_t *list, uint n, void *dat, uint datlen)
{
	uint i;
	LinkNode_t *pHead,*pNode,*pTail;						//�����׽�㣬��ͨ�ڵ㣬β�ڵ�
	//pHead = (LinkNode_t *)malloc(sizeof(LinkNode_t));//Ϊͷ�������ڴ�ռ䣬ͷ��㲻�����ݣ�ָ���׽ڵ㣨��һ���ڵ㣩
	pHead = list->node;										//ͷ������ⲿ����
	if(pHead == NULL)										//�ж��Ƿ�����ڴ�ɹ�
	{
		printf("�ռ����ʧ��");
		return FALSE;
	}
	pTail = pHead;											//β�ڵ��ʼָ���׽��

	for(i=0;i<n;i++)
	{
		pNode = (LinkNode_t *)malloc(sizeof(LinkNode_t));	//Ϊ��ͨ�ڵ����ڵ�ṹ���ڴ�
		pNode->data = (void *)malloc(datlen);				//Ϊ��ͨ�ڵ���������ڴ�
		if(pNode == NULL || pNode->data == NULL)			//�ж��Ƿ�����ڴ�ɹ�
		{
			printf("�ռ����ʧ��");
			return FALSE;
		}
		memcpy(pNode->data, (void *)((uint)dat+i*datlen), datlen);//��ֵ
		//pNode->data = dat[i];
		pTail->next = pNode;								//β�ڵ�ָ���µĽڵ㣬ͬʱβ�ڵ��ǰһ���ڵ�Ҳָ����pNode
		pTail = pNode;										//�½ڵ㸳ֵ��β�ڵ�,�½ڵ�ͱ����β�ڵ�
	}
	pTail->next = NULL;										//β�ڵ�ָ��NULL,��������
	list->datlen = datlen;									//ָ���������ͳ���
	return TRUE;
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *		dat:�޸ĺ��ֵ
 *�������
 *���أ���
************************************************************************/
bool Link_ChangeNodeValue(LinkList_t * list,int n, void *dat)
{
	LinkNode_t *t = list->node->next;
	int i = 0;

	while(i < n && t != NULL)								//�ҵ���n���ڵ�
	{
		t = t->next;
		i++;
	}
	if(t != NULL)
	{
		printf("�޸Ľڵ�%d��ֵ��",n);
		//t->data = dat;
		memcpy(t->data,dat,list->datlen);
		return TRUE;
	}
	else
	{
		printf("�ڵ㲻���ڣ�");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ������ڵ�
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
bool Link_Traverse(LinkList_t *list)
{
	LinkNode_t *p = list->node->next;
	uchar temp[8];

	printf("��������\r\n");
	if(p == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(p != NULL)
	{
		memcpy(temp,p->data,list->datlen);
		printf("%d\r\n",*temp);//��ӡ�ڵ�����
		p = p->next;//ָ����һ���ڵ�
	}
	return TRUE;
}
#if 0
/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
 *		n:��n���ڵ�
 *		dat:�����ֵ
 *�������
 *���أ���
************************************************************************/
void InsertNode(LinkNode_t *list, int n, Data_t dat)
{
	LinkNode_t *p = list;//����LinkNode_t��ָ��ָ���׽ڵ�
	LinkNode_t *in;//�²���ڵ�
	printf("�ڽڵ�%dǰ�����½ڵ�\r\n",n);
	while(p != NULL && n--)//��λ����n���ڵ㣬�ڴ˽ڵ�ǰ�����½ڵ�
	{
		p = p->next;//
	}
	if(p != NULL)
	{
		in = (LinkNode_t*)malloc(sizeof(LinkNode_t));//Ϊ�²���ڵ�����ڴ�
		//printf("���������ڵ�����ݣ�");
		//scanf("%d",&in->Element);
		in->data = dat;
		in->next = p->next;//����ڵ�ָ����һ���ڵ�
		p->next = in;//Դ�ڵ�ָ���²���ڵ�
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
	}
}

/************************************************************************
 *���ܣ�ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
		n:��n���ڵ�,��0��ʼ��
 *�������
 *���أ���
************************************************************************/
void DeleteNode(LinkNode_t *list,int n)
{
	LinkNode_t *p = list;//����ָ��ָ���׽ڵ�
	LinkNode_t *temp;//��ʱ����
	printf("��%d���ڵ㽫��ɾ��\r\n",n);
	while(p != NULL && n--)//�ƶ�����n���ڵ㣬ɾ��
	{
		p = p->next;
	}
	if(p != NULL)
	{
		temp = p->next;
		p->next = temp->next;
		free(temp);//�ͷ���ʱ����
		temp = NULL;
	}
	else
	{
		printf("��ɾ���ڵ㲻���ڣ�\r\n");
	}
}

/************************************************************************
 *ɾ����������
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void DeleteLinkList(LinkNode_t *list)
{
	LinkNode_t *p = list->next;//ָ���׽ڵ����һ���ڵ�
	LinkNode_t *temp;//��ʱ����
	list->next = NULL;//�׽ڵ�ָ���ָ��
	while(p != NULL)//ÿ���ڵ㰤��ɾ��
	{
		temp = p->next;//��ʱ����ָ����һ���ڵ�
		free(p);//�ͷŵ�ǰ�ڵ��ڴ�
		p = temp;
	}
	if(p == NULL)
	{
		free(temp);//�ͷ���ʱ�����ڴ�
		temp = NULL;
		printf("ɾ������ɹ���\r\n");
	}
}

/************************************************************************
 *��ת��������
 *���룺list:�����ַ
 *�����list:��ת�������
 *���أ���
************************************************************************/
void ReverseLinkList(LinkNode_t *list)
{
	LinkNode_t *currNode;//��ǰҪ�嵽head�����node
	LinkNode_t *nextNode;//����ڵ�ǰ�ڵ����һ���ڵ�
	LinkNode_t *preNode; //����ڵ�ǰ�ڵ����һ���ڵ�
	LinkNode_t *headNode;//ͷ���

	if(list->next == NULL)
	{
		printf("����Ϊ��\r\n");
		return;
	}
	headNode = list;
	preNode = list->next;
	currNode = preNode->next;
	printf("��ת��������\r\n");
	while(preNode->next != NULL)
	{
		nextNode = currNode->next;//����next�ڵ�
		preNode->next = currNode->next;
		currNode->next = headNode->next;
		headNode->next = currNode;

		currNode = nextNode;
	}
}
#endif
void testLink(void)
{
	int age[3] = {10,11,12};
	int dat;
	LinkList_t student;//����һ������

	if(Link_Create(&student, 3, age, sizeof(age[0])))//����3���ڵ������,�������׽ڵ�
		Link_Traverse(&student);//��������
	
	/*dat.element = 1;
	InsertNode(student,3,dat);//�ڵ�n���ڵ�ǰ�����½ڵ�
	TraverseList(student);//��������

	dat.element = 2;
	ChangeNodeValue(student,0,dat);//�޸ĵ�0���ڵ��ֵ
	TraverseList(student);//��������

	dat.element = 3;
	InsertNode(student,3,dat);//�ڵ�n���ڵ�ǰ�����½ڵ�
	TraverseList(student);//��������

	DeleteNode(student,0);//ɾ���ڵ�
	TraverseList(student);//��������
	
	ReverseLinkList(student);//��ת����
	TraverseList(student);//��������
	
	DeleteLinkList(student);//ɾ������
	TraverseList(student);//��������*/
}
