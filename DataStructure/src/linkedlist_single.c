/************************************************************************
 *���������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.2
 *2020.12.7  ��������ת
 *2021.2.2   �޸ģ��������Ͳ�������
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
	pHead = (LinkNode_t *)malloc(sizeof(LinkNode_t));		//Ϊͷ�������ڴ�ռ䣬ͷ��㲻�����ݣ�ָ���׽ڵ㣨��һ���ڵ㣩
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
			printf("�½ڵ�%d�ռ����ʧ�ܣ�\r\n",i);
			return FALSE;
		}
		memcpy(pNode->data, (void *)((uint)dat+i*datlen), datlen);//��ֵ
		//pNode->data = dat[i];
		pTail->next = pNode;								//β�ڵ�ָ���µĽڵ㣬ͬʱβ�ڵ��ǰһ���ڵ�Ҳָ����pNode
		pTail = pNode;										//�½ڵ㸳ֵ��β�ڵ�,�½ڵ�ͱ����β�ڵ�
	}
	pTail->next = NULL;										//β�ڵ�ָ��NULL,��������
	list->datlen = datlen;									//ָ���������ͳ���
	list->node = pHead;										//ָ���׽ڵ�
	list->node->data = NULL;								//һ��Ҫ��ʼ���׽ڵ�������
	return TRUE;
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *		dat:�޸ĺ��ֵ
 *�������
 *���أ�TRUE or FALSE
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
		printf("�޸Ľڵ�%d��ֵ\r\n",n);
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
 *���أ�TRUE or FALSE
************************************************************************/
bool Link_Traverse(LinkList_t *list)
{
	LinkNode_t *p = list->node;
	uchar temp[32];

	printf("��������\r\n");
	if(p == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	p = p->next;
	if(p == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(p != NULL)
	{
		memcpy(temp,p->data,list->datlen);
		printf("%d\r\n",*temp);						//��ӡ�ڵ�����
		p = p->next;								//ָ����һ���ڵ�
	}
	return TRUE;
}

/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
 *		n:��n���ڵ�
 *		dat:�����ֵ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Link_InsertNode(LinkList_t *list, int n, void *dat)
{
	LinkNode_t *p = list->node;						//����LinkNode_t��ָ��ָ���׽ڵ�
	LinkNode_t *in;									//�²���ڵ�
	printf("�ڽڵ�%dǰ�����½ڵ�\r\n",n);
	while(p != NULL && n--)							//��λ����n���ڵ㣬�ڴ˽ڵ�ǰ�����½ڵ�
	{
		p = p->next;
	}
	if(p != NULL)
	{
		in = (LinkNode_t*)malloc(sizeof(LinkNode_t));//Ϊ�²���ڵ�����ڴ�
		in->data = (void *)malloc(list->datlen);	//Ϊ��ͨ�ڵ���������ڴ�
		if(in == NULL || in->data == NULL)
		{
			printf("�ռ����ʧ��\r\n");
			return FALSE;
		}
		//printf("���������ڵ�����ݣ�");
		//scanf("%d",&in->Element);
		//in->data = dat;
		memcpy(in->data,dat,list->datlen);
		in->next = p->next;							//����ڵ�ָ����һ���ڵ�
		p->next = in;								//Դ�ڵ�ָ���²���ڵ�
		return TRUE;
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ�ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
		n:��n���ڵ�,��0��ʼ��
 *�������
 *���أ���
************************************************************************/
bool Link_DeleteNode(LinkList_t *list,int n)
{
	LinkNode_t *p = list->node;						//����ָ��ָ���׽ڵ�
	LinkNode_t *temp;								//��ʱ�ڵ����
	printf("��%d���ڵ㽫��ɾ��\r\n",n);
	while(p != NULL && n--)							//�ƶ�����n���ڵ㣬ɾ��
	{
		p = p->next;
	}
	if(p != NULL)
	{
		temp = p->next;
		p->next = temp->next;
		free(temp->data);							//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		temp->data = NULL;
		free(temp);									//�ͷ���ʱ�ڵ����
		temp = NULL;
	}
	else
	{
		printf("��ɾ���ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
	return TRUE;
}

/************************************************************************
 *���ܣ������������
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool Link_Clear(LinkList_t *list)
{
	LinkNode_t *p = list->node->next;				//ָ���һ����ͨ�ڵ�
	LinkNode_t *temp;								//��ʱ�ڵ����
	list->node->next = NULL;						//�׸���ͨ�ڵ�ָ���ָ��
	while(p != NULL)								//ÿ���ڵ㰤��ɾ��
	{
		temp = p->next;								//��ʱ����ָ����һ���ڵ�
		if(p->data != NULL)
			free(p->data);							//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		p->data = NULL;
		free(p);									//�ͷŵ�ǰ�ڵ��ڴ�
		p = temp;
	}
	if(p == NULL)
	{
		printf("�������ɹ���\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *���ܣ�������������
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
bool Link_Destroy(LinkList_t *list)
{
	LinkNode_t *p = list->node;						//ָ���׽ڵ�
	LinkNode_t *temp;								//��ʱ�ڵ����
	list->node = NULL;								//�׽ڵ�ָ���ָ��
	list->datlen = 0;								//�������ݳ�������
	while(p != NULL)								//ÿ���ڵ㰤��ɾ��
	{
		temp = p->next;								//��ʱ����ָ����һ���ڵ�
		if(p->data != NULL)
			free(p->data);							//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		p->data = NULL;
		free(p);									//�ͷŵ�ǰ�ڵ��ڴ�
		p = temp;
	}
	if(p == NULL)
	{
		/*if(p->data != NULL)
			free(p->data);							//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		p->data = NULL;
		free(temp);									//�ͷ���ʱ�����ڴ�
		temp = NULL;*/
		printf("��������ɹ���\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *���ܣ���ת��������
 *���룺list:�����ַ
 *�����list:��ת�������
 *���أ���
************************************************************************/
bool Link_Reverse(LinkList_t *list)
{
	LinkNode_t *currNode;							//��ǰҪ�嵽head�����node
	LinkNode_t *nextNode;							//����ڵ�ǰ�ڵ����һ���ڵ�
	LinkNode_t *preNode;							//����ڵ�ǰ�ڵ����һ���ڵ�
	LinkNode_t *headNode;							//ͷ���

	if(list->node->next == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	headNode = list->node;
	preNode = list->node->next;
	currNode = preNode->next;
	printf("��ת��������\r\n");
	while(preNode->next != NULL)
	{
		nextNode = currNode->next;					//����next�ڵ�
		preNode->next = currNode->next;
		currNode->next = headNode->next;
		headNode->next = currNode;

		currNode = nextNode;
	}
	return TRUE;
}

void testLink(void)
{
	int age[3] = {10,11,12};
	int dat;
	LinkList_t student;//����һ������

	if(Link_Create(&student, 3, age, sizeof(age[0])))//����3���ڵ������,�������׽ڵ�
		Link_Traverse(&student);//��������
	
	dat = 1;
	if(Link_InsertNode(&student,3,&dat))//�ڵ�n���ڵ�ǰ�����½ڵ�
		Link_Traverse(&student);//��������

	dat = 2;
	if(Link_ChangeNodeValue(&student,0,&dat))//�޸ĵ�0���ڵ��ֵ
		Link_Traverse(&student);//��������

	dat = 3;
	if(Link_InsertNode(&student,3,&dat))//�ڵ�n���ڵ�ǰ�����½ڵ�
		Link_Traverse(&student);//��������

	if(Link_DeleteNode(&student,0))//ɾ���ڵ�
		Link_Traverse(&student);//��������
	
	if(Link_Reverse(&student))//��ת����
		Link_Traverse(&student);//��������

	if(Link_Clear(&student))//��ת����
		Link_Traverse(&student);//��������
	
	if(Link_Destroy(&student))//ɾ������
		Link_Traverse(&student);//��������
}
