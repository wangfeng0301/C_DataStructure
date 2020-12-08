/************************************************************************
 *���������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *wangfeng
 *2019.11.29-2020.12.7
 *2020.12.7  ��������ת
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "link.h"

/************************************************************************
 *���ܣ���������
 *���룺n ����ڵ�������������׽ڵ�
 *�������
 *���أ������׵�ַ
************************************************************************/
LinkNode *CreatLinkList(int n)
{
	int i;
	LinkNode *pHead,*pNode,*pTail;//�����׽�㣬��ͨ�ڵ㣬β�ڵ�
	pHead = (LinkNode *)malloc(sizeof(LinkNode));//Ϊͷ�������ڴ�ռ䣬ͷ��㲻�����ݣ�ָ���׽ڵ㣨��һ���ڵ㣩
	if(pHead == NULL)//�ж��Ƿ�����ڴ�ɹ�
	{
		printf("�ռ����ʧ��");
		exit(-1);
	}
	pTail = pHead;//β�ڵ��ʼָ���׽��

	for(i=0;i<n;i++)
	{
		pNode = (LinkNode*)malloc(sizeof(LinkNode));//Ϊ��ͨ�ڵ�����ڴ�
		if(pNode == NULL)//�ж��Ƿ�����ڴ�ɹ�
		{
			printf("�ռ����ʧ��");
			exit(-1);
		}
		printf("�������%d���ڵ����ݣ�",i);
		scanf("%d",&(pNode->Element));//���ڵ�Ԫ�ظ�ֵ
		pTail->next = pNode;//β�ڵ�ָ���µĽڵ㣬ͬʱβ�ڵ��ǰһ���ڵ�Ҳָ����pNode
		pTail = pNode;//�½ڵ㸳ֵ��β�ڵ�,�½ڵ�ͱ����β�ڵ�
	}
	pTail->next = NULL;//β�ڵ�ָ��NULL,��������

	return pHead;//����ͷ�ڵ��ַ
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *�������
 *���أ���
************************************************************************/
void ChangeNodeValue(LinkNode * list,int n)
{
	LinkNode *t = list->next;
	int i=0;
	while(i<n && t!=NULL)//�ҵ���n���ڵ�
	{
		t = t->next;
		i++;
	}
	if(t != NULL)
	{
		printf("����Ҫ�޸ĵĽڵ�%dֵ��",n);
		scanf("%d",&t->Element);
	}
	else
	{
		printf("�ڵ㲻���ڣ�");
	}
}

/************************************************************************
 *���ܣ������ڵ�
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void TraverseList(LinkNode *list)
{
	LinkNode *p = list->next;
	if(p == NULL)
	{
		printf("����Ϊ��\r\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d\r\n",p->Element);//��ӡ�ڵ�����
		p = p->next;//ָ����һ���ڵ�
	}
}

/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺n:��n���ڵ�
 *�������
 *���أ���
************************************************************************/
void InsertNode(LinkNode *list,int n)
{
	LinkNode *p = list;//����LinkNode��ָ��ָ���׽ڵ�
	LinkNode *in;//�²���ڵ�
	printf("�ڽڵ�%dǰ�����½ڵ�\r\n",n);
	while(p != NULL && n--)//��λ����n���ڵ㣬�ڴ˽ڵ�ǰ�����½ڵ�
	{
		p = p->next;//
	}
	if(p != NULL)
	{
		in = (LinkNode*)malloc(sizeof(LinkNode));//Ϊ�²���ڵ�����ڴ�
		printf("���������ڵ�����ݣ�");
		scanf("%d",&in->Element);
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
void DeleteNote(LinkNode *list,int n)
{
	LinkNode *p = list;//����ָ��ָ���׽ڵ�
	LinkNode *temp;//��ʱ����
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
void DeleteLinkList(LinkNode *list)
{
	LinkNode *p = list->next;//ָ���׽ڵ����һ���ڵ�
	LinkNode *temp;//��ʱ����
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
void ReverseLinkList(LinkNode *list)
{
	LinkNode *currNode;//��ǰҪ�嵽head�����node
	LinkNode *nextNode;//����ڵ�ǰ�ڵ����һ���ڵ�
	LinkNode *preNode; //����ڵ�ǰ�ڵ����һ���ڵ�
	LinkNode *headNode;//ͷ���

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
void testLink(void)
{
	LinkNode *student = CreatLinkList(3);//����3���ڵ������,�������׽ڵ�
	unsigned n=500,s=60,m=51;

	TraverseList(student);//��������
	InsertNode(student,3);//�ڵ�n���ڵ�ǰ�����½ڵ�
	TraverseList(student);//��������
	ChangeNodeValue(student,0);//�޸ĵ�3���ڵ��ֵ
	TraverseList(student);//��������
	InsertNode(student,3);//�ڵ�n���ڵ�ǰ�����½ڵ�
	TraverseList(student);//��������
	DeleteNote(student,0);//ɾ���ڵ�
	TraverseList(student);//��������
	ReverseLinkList(student);//��ת����
	TraverseList(student);//��������
	DeleteLinkList(student);//ɾ������
	TraverseList(student);//��������
}