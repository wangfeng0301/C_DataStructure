/************************************************************************
 *˫�������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *˫��ѭ�������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.2
 *2021.2.2  �޸ģ��������Ͳ�������
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist_double.h"

/************************************************************************
 *���ܣ���������
 *���룺list:������ʼ��ַ
 *		n ����ڵ�������������׽ڵ�
 *		dat:Ҫ���������Ԫ��ָ�룬��n=0,�Ĳ����ɴ�NULL
 *		datlen:�������͵ĳ���
 *�����list:�����ַ
 *���أ�TRUE or FALSE
************************************************************************/
bool DoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen)
{
	unsigned int i=0;
	DoubleLinkNode_t *pHead,*pTail,*pNode;							//�����׽ڵ㡢β�ڵ㡢��ͨ�ڵ�

	pHead = (DoubleLinkNode_t *)malloc(sizeof(DoubleLinkNode_t));	//Ϊ�׽ڵ㿪�ٿռ䣬�׽ڵ�û������
	if(pHead == NULL)
	{
		printf("�׽ڵ�ռ����ʧ�ܣ�\r\n");
		return FALSE;
	}
	pHead->pre = NULL;												//�׽ڵ�ǰ��ָ���
	pTail = pHead;													//β�ڵ�ָ���׽ڵ�
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//�¿��ٿռ���½ڵ�
		pNode->data = (void *)malloc(datlen);						//Ϊ��ͨ�ڵ���������ڴ�
		if(pNode == NULL || pNode->data == NULL)
		{
			printf("�½ڵ�%d�ռ����ʧ�ܣ�\r\n",i);
			return FALSE;
		}
		//pNode->data = dat[i];
		memcpy(pNode->data, (void *)((unsigned int)dat+i*datlen), datlen);	//��ֵ
		pTail->next = pNode;										//�½��ڵ��ǰһ���ڵ���ָ���Լ�
		pNode->pre = pTail;											//�½��ڵ�ǰ��ָ��ǰһ���ڵ�
		pTail = pNode;												//�½ڵ㸳ֵ��β�ڵ㣬β�ڵ�ͱ���˵�ǰ�½��Ľڵ�
	}
	pTail->next = NULL;												//β�ڵ���ָ��գ���������
	list->datlen = datlen;											//ָ���������ͳ���
	list->node = pHead;												//ָ���׽ڵ�
	list->node->data = NULL;										//һ��Ҫ��ʼ���׽ڵ�������
	return TRUE;
}

/************************************************************************
 *���ܣ������ڵ�
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool DoubleLink_Traverse(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *p = list->node;								//��ʱ�ڵ�ָ���׽ڵ�
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
		printf("%d\r\n",*temp);										//��ӡ�ڵ�����
		p = p->next;												//ָ����һ���ڵ�
	}
	return TRUE;
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *		dat:�޸ĵ�ֵ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool DoubleLink_ChangeNodeValue(DoubleLinkList_t *list, unsigned int n, void *dat)
{
	unsigned int i = n;
	DoubleLinkNode_t* temp = list->node->next;						//��ʱ�ڵ�ָ���һ�������ݽڵ�

	if(temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return FALSE;
	}	
	while(temp != NULL && i--)
	{
		temp = temp->next;											//ָ����һ���ڵ㣬ֱ����ָ���ڵ�
	}
	if(temp!=NULL)
	{	
		printf("�޸Ľڵ�%d\r\n",n);
		//temp->data = dat;
		memcpy(temp->data,dat,list->datlen);
		return TRUE;
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
}
/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺lsit:�����ַ
 *		n:��n���ڵ�
 *		dat:�����ֵ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool DoubleLink_InsertNode(DoubleLinkList_t *list, unsigned int n, void *dat)
{
	unsigned int i=n;
	DoubleLinkNode_t *temp,*pNewNode;								//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�
	printf("�ڽڵ�%dǰ�����½ڵ�\r\n",n);
	while(temp != NULL && i--)
	{
		temp = temp->next;											//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
	}
	if(temp != NULL)												//ע������temp��ָ���ڵ��ǰһ���ڵ�
	{
		pNewNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//Ϊ�½ڵ�����ڴ�
		pNewNode->data = (void *)malloc(list->datlen);				//Ϊ��ͨ�ڵ���������ڴ�
		if(pNewNode == NULL)
		{
			printf("�½ڵ�ռ����ʧ�ܣ�\r\n");
			return FALSE;
		}
		//pNewNode->data = dat;
		memcpy(pNewNode->data,dat,list->datlen);
		pNewNode->next = temp->next;								//�½ڵ���
		temp->next = pNewNode;										//ǰһ���ڵ���Ϊ�½ڵ�
		pNewNode->pre = temp;										//�½ڵ�ǰ��Ϊǰһ���ڵ�
		if(pNewNode->next != NULL)									//�½ڵ��̲���NULL����ʾ�½ڵ㲻��β�ڵ㣬����ִ���������
		{
			temp = pNewNode->next;									//��ʱ�ڵ�ָ���½ڵ�ĺ��
			temp->pre = pNewNode;									//��һ���ڵ�ǰ��ָ���½ڵ�
		}
		return TRUE;
	}
	else
	{
		printf("�ýڵ㲻���ڣ�\r\n");
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
bool DoubleLink_DeleteNode(DoubleLinkList_t *list, unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode_t* temp,*pDeleteNode;							//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�
	printf("ɾ���ڵ�%d\r\n",n);
	if(temp->next == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return FALSE;
	}
	while(temp!=NULL && i--)
	{
		temp = temp->next;											//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
	}
	if(temp->next!=NULL)											//ע������temp��ָ���ڵ��ǰһ���ڵ�,����ɾ���׽ڵ�
	{
		pDeleteNode = temp->next;									//temp�����Ҫɾ���Ľڵ�
		temp->next = pDeleteNode->next;								//ǰһ���ڵ���		
		if(pDeleteNode->next != NULL)								//��һ���ڵ㲻��NULL����ʾ��һ���ڵ㲻��β�ڵ㣬����ִ���������
		{
			temp = pDeleteNode->next;								//��ʱ�ڵ㸳ֵΪҪɾ���ڵ�ĺ�һ���ڵ�
			temp->pre = pDeleteNode->pre;							//��һ���ڵ�ǰ��
		}	
		free(pDeleteNode->data);									//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		pDeleteNode->data = NULL;
		free(pDeleteNode);											//�ͷ��ڴ�
		pDeleteNode = NULL;
		return TRUE;
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ��������������������ͷ
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool DoubleLink_Clear(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//��ʱ�ڵ�

	temp = list->node->next;										//��ʱ�ڵ�ָ���׽ڵ�
	list->node->next = NULL;										//�׽ڵ�ָ���ָ��
	if(temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return FALSE;
	}
	while(temp != NULL)
	{
		p = temp->next;												//��ǰ�ڵ��̸�ֵ��p
		if(temp->data != NULL)
			free(temp->data);										//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		temp->data = NULL;
		free(temp);													//�ͷŵ�ǰ�ڵ��ڴ�
		temp = p;
	}
	if(temp==NULL)
	{
		//free(p);													//�ͷ���ʱ����
		//p = NULL;
		printf("�������ɹ���\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *���ܣ�����������������������ͷ
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool DoubleLink_Destroy(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�
	list->datlen = 0;												//�������ݳ�������
	list->node = NULL;												//�׽ڵ�ָ���ָ��
	if(temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return FALSE;
	}
	while(temp != NULL)
	{
		p = temp->next;												//��ǰ�ڵ��̸�ֵ��p
		if(temp->data != NULL)
			free(temp->data);										//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		temp->data = NULL;
		free(temp);													//�ͷŵ�ǰ�ڵ��ڴ�
		temp = p;
	}
	if(temp==NULL)
	{
		//free(p);													//�ͷ���ʱ����
		//p = NULL;
		printf("��������ɹ���\r\n");
		return TRUE;
	}
	return FALSE;
}

/***************************************ѭ������***********************************************************/

/************************************************************************
 *���ܣ���������
 *���룺list:�����ַ
 *		n: ����ڵ�������������׽ڵ�
 *		dat:Ҫ���������Ԫ��ָ�룬��n=0,�Ĳ����ɴ�NULL
 *�����list:�����ַ
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen)
{
	unsigned int i=0;
	DoubleLinkNode_t *pHead,*pTail,*pNode;							//�����׽ڵ㡢β�ڵ㡢��ͨ�ڵ�

	pHead = (DoubleLinkNode_t *)malloc(sizeof(DoubleLinkNode_t));	//Ϊ�׽ڵ㿪�ٿռ䣬�׽ڵ�û������
	if(pHead == NULL)
	{
		printf("�׽ڵ�ռ����ʧ�ܣ�\r\n");
		return FALSE;
	}
	pTail = pHead;//β�ڵ�ָ���׽ڵ�
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//�¿��ٿռ���½ڵ�
		pNode->data = (void *)malloc(datlen);						//Ϊ��ͨ�ڵ���������ڴ�
		if(pNode == NULL || pNode->data == NULL)
		{
			printf("�½ڵ�%d�ռ����ʧ�ܣ�\r\n",i);
			return FALSE;
		}
		//pNode->data = dat[i];
		memcpy(pNode->data, (void *)((unsigned int)dat+i*datlen), datlen);//��ֵ
		pTail->next = pNode;										//�½��ڵ��ǰһ���ڵ���ָ���Լ�
		pNode->pre = pTail;											//�½��ڵ�ǰ��ָ��ǰһ���ڵ�
		pTail = pNode;												//�½ڵ㸳ֵ��β�ڵ㣬β�ڵ�ͱ���˵�ǰ�½��Ľڵ�
	}
	pHead->pre = pTail;												//�׽ڵ�ǰ��ָ��β�ڵ�
	pTail->next = pHead;											//β�ڵ���ָ���׽ڵ㣬��������
	list->datlen = datlen;											//ָ���������ͳ���
	list->node = pHead;												//ָ���׽ڵ�
	list->node->data = NULL;										//һ��Ҫ��ʼ���׽ڵ�������
	return TRUE;
}

/************************************************************************
 *���ܣ������ڵ�
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Traverse(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *p;				
	uchar temp[32];

	printf("��������\r\n");
	if(list->node == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	p = list->node->next;											//�׽ڵ�û�����ݣ�������ʱ�ڵ�ָ���һ����ͨ�ڵ�
	if(p == list->node || p == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(p != list->node)
	{
		memcpy(temp,p->data,list->datlen);
		printf("%d\r\n",*temp);										//��ӡ�ڵ�����
		p = p->next;												//ָ����һ���ڵ�
	}
	return TRUE;
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *		dat:�ı�ڵ��ֵ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_ChangeNodeValue(DoubleLinkList_t * list,unsigned int n, void *dat)
{
	unsigned int i = n;
	DoubleLinkNode_t* temp = list->node->next;						//��ʱ�ڵ�ָ���һ�������ݽڵ�

	if(list->node == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	if(temp == list->node || temp == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(i--)														//ѭ����������ѭ����ѯ����������Ϊ3������4��ָ�����ڵ�0
	{
		temp = temp->next;											//ָ����һ���ڵ㣬ֱ����ָ���ڵ�
		if(temp == list->node)										//ѭ������β����ͷ��ʼ����
		{
			temp = temp->next;
		}
	}
	if(temp != list->node)
	{	
		printf("�޸Ľڵ�%d\r\n",n);
		//temp->data = dat;
		memcpy(temp->data,dat,list->datlen);
		return TRUE;
	} 
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
 *		n:��n���ڵ�
 *		dat:����ڵ��ֵ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_InsertNode(DoubleLinkList_t *list,unsigned int n, void *dat)
{
	unsigned int i = n;
	DoubleLinkNode_t *temp, *pNewNode;								//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�
	printf("�ڽڵ�%d֮ǰ�����½ڵ�\r\n",n);
	if(list->node == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	if(temp->next == list->node || temp->next == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(i--)														//ѭ����������ѭ����ѯ����������Ϊ3������4��ָ�����ڵ�0
	{
		temp = temp->next;											//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
		if(temp == list->node)										//ѭ������β����ͷ��ʼ����
		{
			temp = temp->next;
		}
	}
	if(temp != list->node)											//ע������temp��ָ���ڵ��ǰһ���ڵ�
	{
		pNewNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//Ϊ�½ڵ�����ڴ�
		pNewNode->data = (void *)malloc(list->datlen);				//Ϊ��ͨ�ڵ���������ڴ�
		if(pNewNode == NULL)
		{
			printf("�½ڵ�ռ����ʧ�ܣ�\r\n");
			return FALSE;
		}
		//pNewNode->data = dat;
		memcpy(pNewNode->data,dat,list->datlen);
		pNewNode->next = temp->next;								//�½ڵ���
		temp->next = pNewNode;										//ǰһ���ڵ���Ϊ�½ڵ�
		pNewNode->pre = temp;										//�½ڵ�ǰ��Ϊǰһ���ڵ�
		temp = pNewNode->next;										//��ʱ�ڵ�ָ���½ڵ�ĺ��
		temp->pre = pNewNode;										//��һ���ڵ�ǰ��ָ���½ڵ�
		return TRUE;
	}
	else
	{
		printf("�ýڵ㲻���ڣ�\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ��ڱ�β���ӽڵ�
 *���룺list:�����ַ
 *		dat:����ڵ��ֵ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_AddNode(DoubleLinkList_t *list, void *dat)
{
	DoubleLinkNode_t *temp,*pNewNode;								//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�	
	printf("�ڱ�β�����½ڵ�\r\n");
	if(list->node == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	pNewNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));	//Ϊ�½ڵ�����ڴ�
	pNewNode->data = (void *)malloc(list->datlen);					//Ϊ��ͨ�ڵ���������ڴ�
	if(pNewNode == NULL)
	{
		printf("�½ڵ�ռ����ʧ�ܣ�\r\n");
		return FALSE;
	}
	//pNewNode->data = dat;
	memcpy(pNewNode->data,dat,list->datlen);
	pNewNode->next = temp;											//�½ڵ���ָ���׽ڵ�
	pNewNode->pre = temp->pre;										//�½ڵ�ǰ��ָ����һ��β�ڵ�
	temp->pre = pNewNode;											//�׽ڵ�ǰ��ָ���½ڵ�
	pNewNode->pre->next = pNewNode;									//�½ڵ���Ϊβ�ڵ㣬��ǰ���ĺ�̾����½ڵ㱾��
	return TRUE;
}

/************************************************************************
 *���ܣ�ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
		n:��n���ڵ�,��0��ʼ��
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_DeleteNode(DoubleLinkList_t *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode_t* temp,*pDeleteNode;							//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�
	printf("ɾ���ڵ�%d\r\n",n);
	if(list->node == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	if(temp->next == list->node || temp->next == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(temp->next != list->node && i--)
	{
		temp = temp->next;											//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
	}
	if(temp->next != list->node)									//ע������temp��ָ���ڵ��ǰһ���ڵ�,����ɾ���׽ڵ�
	{
		pDeleteNode = temp->next;									//temp�����Ҫɾ���Ľڵ�
		temp->next = pDeleteNode->next;								//ǰһ���ڵ���
		temp = pDeleteNode->next;									//��ʱ�ڵ㸳ֵΪҪɾ���ڵ�ĺ�һ���ڵ�
		temp->pre = pDeleteNode->pre;								//��һ���ڵ�ǰ��
		free(pDeleteNode->data);									//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		pDeleteNode->data = NULL;
		free(pDeleteNode);											//�ͷ��ڴ�
		pDeleteNode = NULL;
		return TRUE;
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
}

/************************************************************************
 *���ܣ������������
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Clear(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//��ʱ�ڵ�

	temp = list->node->next;										//��ʱ�ڵ�ָ���һ����ͨ�ڵ�
	if(list->node == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	if(temp == list->node || temp == NULL)
	{
		printf("����Ϊ��\r\n");
		return FALSE;
	}
	while(temp != list->node)
	{
		p = temp->next;												//��ǰ�ڵ��̸�ֵ��p
		if(temp->data != NULL)
			free(temp->data);										//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		temp->data = NULL;
		free(temp);													//�ͷŵ�ǰ�ڵ��ڴ�
		temp = p;
	}
	/*����ͷָ�������δ˶δ���,�ر�ע��������ͷ��ڴ棡��Ҫ������������ʱ�������˴��룬�����ε�������д���
	 *��������������󣬲����ٱ����������������ڴ����ע���������ѭ��˫��������𣬷�ѭ��˫�������׽ڵ�ָ��NULL��
	 *�ж�Ϊ temp==NULL ,���Ժ����ͷ�p�ڴ沢�����ͷ��׽ڵ���ڴ棬�׽ڵ㻹�Ǳ����ģ����ڴ�����һϯ֮�أ�
	 *����������ж�Ϊ temp==list �����ͷ�p�����ͷ��׽ڵ���ڴ棬�׽ڵ�Ͳ������ˣ��ʺ�������ñ��������ͻ�����ڴ����
	 */
	if(temp == list->node)
	{
	//	free(p);//
	//	p = NULL;
		list->node->next = list->node;//�׽ڵ���ָ������
		list->node->pre = list->node;//�׽ڵ�ǰ��ָ������
		printf("�������ɹ���\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *���ܣ�������������
 *���룺list:�����ַ
 *�������
 *���أ�TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Destroy(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//��ʱ�ڵ�

	temp = list->node;												//��ʱ�ڵ�ָ���׽ڵ�
	if(temp == NULL)
	{
		printf("��������\r\n");
		return FALSE;
	}
	while(temp != list->node)
	{
		p = temp->next;												//��ǰ�ڵ��̸�ֵ��p
		if(temp->data != NULL)
			free(temp->data);										//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		temp->data = NULL;
		free(temp);													//�ͷŵ�ǰ�ڵ��ڴ�
		temp = p;
	}
	if(temp == list->node)
	{
		if(temp->data != NULL)
			free(temp->data);										//�ͷ����ݵ�ַ,ע���ͷŵ�˳���ܻ�
		temp->data = NULL;
		free(temp);													//�ͷ��׽ڵ�ռ�
		temp = NULL;
		list->node = NULL;
		list->datlen = 0;											//�������ݳ�������
		printf("��������ɹ���\r\n");
		return TRUE;
	}
	return FALSE;
}

void testDoubleLink(void)
{
	int age[4] = {10,11,12,13};
	int dat;
	DoubleLinkList_t teacher;//����һ������

	if(DoubleLink_Create(&teacher, sizeof(age)/sizeof(age[0]), age, sizeof(age[0])))//����4���ڵ������,�������׽ڵ�
		DoubleLink_Traverse(&teacher);		//��������

	dat = 1;
	if(DoubleLink_InsertNode(&teacher, 4, &dat))		//�ڵ�n���ڵ�ǰ�����½ڵ�
		DoubleLink_Traverse(&teacher);		//��������
	
	dat = 2;
	if(DoubleLink_ChangeNodeValue(&teacher, 0, &dat))	//�޸ĵ�3���ڵ��ֵ
		DoubleLink_Traverse(&teacher);		//��������
	
	if(DoubleLink_DeleteNode(&teacher,4))		//ɾ���ڵ�
		DoubleLink_Traverse(&teacher);		//��������
	
	if(DoubleLink_Clear(&teacher))		//�������
		DoubleLink_Traverse(&teacher);		//��������

	if(DoubleLink_Destroy(&teacher))		//ɾ������
		DoubleLink_Traverse(&teacher);		//��������
	
}

void testCycDoubleLink(void)
{
	int age[4] = {10,11,12,13};
	int dat;
	DoubleLinkList_t people;

	if(CycDoubleLink_Create(&people, sizeof(age)/sizeof(age[0]), age, sizeof(age[0])))
		CycDoubleLink_Traverse(&people);		//��������

	dat = 1;
	if(CycDoubleLink_InsertNode(&people, 4, &dat))		//�ڵ�n���ڵ�ǰ�����½ڵ�
		CycDoubleLink_Traverse(&people);		//��������
	
	dat = 2;
	if(CycDoubleLink_ChangeNodeValue(&people, 3, &dat))//�޸ĵ�3���ڵ��ֵ
		CycDoubleLink_Traverse(&people);		//��������
	
	dat = 3;
	if(CycDoubleLink_AddNode(&people, &dat))		//����β�����½ڵ�
		CycDoubleLink_Traverse(&people);		//��������
	if(CycDoubleLink_AddNode(&people, &dat))		//����β�����½ڵ�
		CycDoubleLink_Traverse(&people);		//��������

	if(CycDoubleLink_DeleteNode(&people,12))	//ɾ���ڵ�
		CycDoubleLink_Traverse(&people);		//��������

	if(CycDoubleLink_DeleteNode(&people,0))	//ɾ���ڵ�
		CycDoubleLink_Traverse(&people);		//��������
	
	if(CycDoubleLink_Clear(&people))	//ɾ������
		CycDoubleLink_Traverse(&people);		//��������
	
	if(CycDoubleLink_Destroy(&people))	//ɾ������
		CycDoubleLink_Traverse(&people);		//��������
}