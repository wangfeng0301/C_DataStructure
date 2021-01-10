/************************************************************************
 *˫�������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *˫��ѭ�������������������������������ڵ㡢�޸�ĳ�ڵ�ֵ��
 *				ɾ����������ɾ��ĳ���ڵ�
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *2019.11.29-2020.12.8
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist_double.h"

/************************************************************************
 *���ܣ���������
 *���룺n ����ڵ�������������׽ڵ�
 *�������
 *���أ������׵�ַ
************************************************************************/
DoubleLinkNode *Double_CreatLinkList(unsigned int n)
{
	unsigned int i=0;
	DoubleLinkNode *pHead,*pTail,*pNode;//�����׽ڵ㡢β�ڵ㡢��ͨ�ڵ�

	pHead = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));//Ϊ�׽ڵ㿪�ٿռ䣬�׽ڵ�û������
	if(pHead == NULL)
	{
		printf("�׽ڵ�ռ����ʧ�ܣ�\r\n");
		return;
	}
	pHead->pre = NULL;//�׽ڵ�ǰ��ָ���
	pTail = pHead;//β�ڵ�ָ���׽ڵ�
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//�¿��ٿռ���½ڵ�
		if(pNode == NULL)
		{
			printf("�½ڵ�%d�ռ����ʧ�ܣ�\r\n",i);
			return;
		}
		printf("������ڵ�%d���ݣ�",i);
		scanf("%d",&(pNode->Element));
		pTail->next = pNode;//�½��ڵ��ǰһ���ڵ���ָ���Լ�
		pNode->pre = pTail;//�½��ڵ�ǰ��ָ��ǰһ���ڵ�
		pTail = pNode;//�½ڵ㸳ֵ��β�ڵ㣬β�ڵ�ͱ���˵�ǰ�½��Ľڵ�
	}
	pTail->next = NULL;//β�ڵ���ָ��գ���������

	return pHead;
}

/************************************************************************
 *���ܣ������ڵ�
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void Double_TraverseList(DoubleLinkNode *list)
{
	unsigned int i=0;
	DoubleLinkNode *temp;//��ʱ�ڵ�

	temp = list->next;//�׽ڵ�û�����ݣ�������ʱ�ڵ�ָ���һ����ͨ�ڵ�
	if(temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(temp != NULL)
	{
		printf("�ڵ�%dԪ�أ�%d\r\n",i,temp->Element);
		temp = temp->next;//ָ����һ���ڵ�
		i++;
	}
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *�������
 *���أ���
************************************************************************/
void Double_ChangeNodeValue(DoubleLinkNode * list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp;//��ʱ�ڵ�

	temp = list->next;//ָ���һ�������ݽڵ�
	if(temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}	
	while(temp!=NULL && i--)
	{
		temp = temp->next;//ָ����һ���ڵ㣬ֱ����ָ���ڵ�
	}
	if(temp!=NULL)
	{	
		printf("�ڵ�%d�޸�Ϊ��",n);
		scanf("%d",&(temp->Element));
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
	}
}
/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺n:��n���ڵ�
 *�������
 *���أ���
************************************************************************/
void Double_InsertNode(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode *temp,*pNewNode;//��ʱ�ڵ�

	temp = list;//��ʱ�ڵ�ָ���׽ڵ�
	printf("�ڽڵ�%dǰ�����½ڵ�\r\n",n);
	if(temp->next == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(temp!=NULL && i--)
	{
		temp = temp->next;//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
	}
	if(temp != NULL)//ע������temp��ָ���ڵ��ǰһ���ڵ�
	{
		pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//Ϊ�½ڵ�����ڴ�
		if(pNewNode == NULL)
		{
			printf("�½ڵ�ռ����ʧ�ܣ�\r\n");
			return;
		}
		printf("�������½ڵ����ݣ�");
		scanf("%d",&pNewNode->Element);
		pNewNode->next = temp->next;//�½ڵ���
		temp->next = pNewNode;//ǰһ���ڵ���Ϊ�½ڵ�
		pNewNode->pre = temp;//�½ڵ�ǰ��Ϊǰһ���ڵ�
		if(pNewNode->next != NULL)//�½ڵ��̲���NULL����ʾ�½ڵ㲻��β�ڵ㣬����ִ���������
		{
			temp = pNewNode->next;//��ʱ�ڵ�ָ���½ڵ�ĺ��
			temp->pre = pNewNode;//��һ���ڵ�ǰ��ָ���½ڵ�
		}	
	}
	else
	{
		printf("�ýڵ㲻���ڣ�\r\n");
	}
}
/************************************************************************
 *���ܣ�ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
		n:��n���ڵ�,��0��ʼ��
 *�������
 *���أ���
************************************************************************/
void Double_DeleteNote(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp,*pDeleteNode;//��ʱ�ڵ�

	temp = list;//��ʱ�ڵ�ָ���׽ڵ�
	printf("ɾ���ڵ�%d\r\n",n);
	if(temp->next == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(temp!=NULL && i--)
	{
		temp = temp->next;//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
	}
	if(temp->next!=NULL)//ע������temp��ָ���ڵ��ǰһ���ڵ�,����ɾ���׽ڵ�
	{
		pDeleteNode = temp->next;//temp�����Ҫɾ���Ľڵ�
		temp->next = pDeleteNode->next;//ǰһ���ڵ���		
		if(pDeleteNode->next != NULL)//��һ���ڵ㲻��NULL����ʾ��һ���ڵ㲻��β�ڵ㣬����ִ���������
		{
			temp = pDeleteNode->next;//��ʱ�ڵ㸳ֵΪҪɾ���ڵ�ĺ�һ���ڵ�
			temp->pre = pDeleteNode->pre;//��һ���ڵ�ǰ��
		}	
		free(pDeleteNode);//�ͷ��ڴ�
		pDeleteNode = NULL;
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
	}
}
/************************************************************************
 *���ܣ�ɾ������������������ͷ
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void Double_DeleteLinkList(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*p;//��ʱ�ڵ�

	temp = list->next;//��ʱ�ڵ�ָ���׽ڵ�
	list->next = NULL;//�׽ڵ�ָ���
	if(temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(temp!=NULL)
	{
		p = temp->next;//��ǰ�ڵ��̸�ֵ��p
		free(temp);//�ͷŵ�ǰ�ڵ��ڴ�
		temp = p;
	}
	if(temp==NULL)
	{
		free(p);//�ͷ���ʱ����
		p = NULL;
		printf("ɾ������ɹ���\r\n");
	}
}

/***************************************ѭ������***********************************************************/

/************************************************************************
 *���ܣ���������
 *���룺n ����ڵ�������������׽ڵ�
 *�������
 *���أ������׵�ַ
************************************************************************/
DoubleLinkNode *CycDouble_CreatLinkList(unsigned int n)
{
	unsigned int i=0;
	DoubleLinkNode *pHead,*pTail,*pNode;//�����׽ڵ㡢β�ڵ㡢��ͨ�ڵ�

	pHead = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));//Ϊ�׽ڵ㿪�ٿռ䣬�׽ڵ�û������
	if(pHead == NULL)
	{
		printf("�׽ڵ�ռ����ʧ�ܣ�\r\n");
		return;
	}
	pTail = pHead;//β�ڵ�ָ���׽ڵ�
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//�¿��ٿռ���½ڵ�
		if(pNode == NULL)
		{
			printf("�½ڵ�%d�ռ����ʧ�ܣ�\r\n",i);
			return;
		}
		printf("������ڵ�%d���ݣ�",i);
		scanf("%d",&(pNode->Element));
		pTail->next = pNode;//�½��ڵ��ǰһ���ڵ���ָ���Լ�
		pNode->pre = pTail;//�½��ڵ�ǰ��ָ��ǰһ���ڵ�
		pTail = pNode;//�½ڵ㸳ֵ��β�ڵ㣬β�ڵ�ͱ���˵�ǰ�½��Ľڵ�
	}
	pHead->pre = pTail;//�׽ڵ�ǰ��ָ��β�ڵ�
	pTail->next = pHead;//β�ڵ���ָ���׽ڵ㣬��������

	return pHead;
}

/************************************************************************
 *���ܣ������ڵ�
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void CycDouble_TraverseList(DoubleLinkNode *list)
{
	unsigned int i=0;
	DoubleLinkNode *temp;//��ʱ�ڵ�

	temp = list->next;//�׽ڵ�û�����ݣ�������ʱ�ڵ�ָ���һ����ͨ�ڵ�
	if(temp == list || temp == NULL)
	{
		printf("����Ϊ�գ�\r\n");
		return 0;
	}
	while(temp != list)
	{
		printf("�ڵ�%dԪ�أ�%d\r\n",i,temp->Element);
		temp = temp->next;//ָ����һ���ڵ�
		i++;
	}
}

/************************************************************************
 *���ܣ��޸Ľڵ�n��ֵ
 *���룺n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *		list:�����ַ
 *�������
 *���أ���
************************************************************************/
void CycDouble_ChangeNodeValue(DoubleLinkNode * list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp;//��ʱ�ڵ�

	temp = list->next;//ָ���һ�������ݽڵ�
	if(temp == list)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}	
	while( i--)//ѭ����������ѭ����ѯ����������Ϊ3������4��ָ�����ڵ�0
	{
		temp = temp->next;//ָ����һ���ڵ㣬ֱ����ָ���ڵ�
		if(temp == list)//ѭ������β����ͷ��ʼ����
		{
			temp = temp->next;
		}
	}
	if(temp!=list)
	{	
		printf("�ڵ�%d�޸�Ϊ��",n);
		scanf("%d",&(temp->Element));
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
	}
}
/************************************************************************
 *���ܣ��ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺n:��n���ڵ�
 *�������
 *���أ���
************************************************************************/
void CycDouble_InsertNode(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode *temp,*pNewNode;//��ʱ�ڵ�

	temp = list;//��ʱ�ڵ�ָ���׽ڵ�
	printf("�ڽڵ�%d֮ǰ�����½ڵ�\r\n",n);
	if(temp->next == list)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(i--)//ѭ����������ѭ����ѯ����������Ϊ3������4��ָ�����ڵ�0
	{
		temp = temp->next;//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
		if(temp == list)//ѭ������β����ͷ��ʼ����
		{
			temp = temp->next;
		}
	}
	if(temp != list)//ע������temp��ָ���ڵ��ǰһ���ڵ�
	{
		pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//Ϊ�½ڵ�����ڴ�
		if(pNewNode == NULL)
		{
			printf("�½ڵ�ռ����ʧ�ܣ�\r\n");
			return;
		}
		printf("�������½ڵ����ݣ�");
		scanf("%d",&pNewNode->Element);
		pNewNode->next = temp->next;//�½ڵ���
		temp->next = pNewNode;//ǰһ���ڵ���Ϊ�½ڵ�
		pNewNode->pre = temp;//�½ڵ�ǰ��Ϊǰһ���ڵ�
		temp = pNewNode->next;//��ʱ�ڵ�ָ���½ڵ�ĺ��
		temp->pre = pNewNode;//��һ���ڵ�ǰ��ָ���½ڵ�
	}
	else
	{
		printf("�ýڵ㲻���ڣ�\r\n");
	}
}
/************************************************************************
 *���ܣ��ڱ�β���ӽڵ�,����Ϊ�ղ���ֱ�ӷ���
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void CycDouble_AddNode(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*pNewNode;//��ʱ�ڵ�

	temp = list;//��ʱ�ڵ�ָ���׽ڵ�	
	printf("�ڱ�β�����½ڵ�\r\n");

	pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//Ϊ�½ڵ�����ڴ�
	if(pNewNode == NULL)
	{
		printf("�½ڵ�ռ����ʧ�ܣ�\r\n");
		return;
	}
	printf("�������½ڵ����ݣ�");
	scanf("%d",&pNewNode->Element);
	pNewNode->next = temp;//�½ڵ���ָ���׽ڵ�
	pNewNode->pre = temp->pre;//�½ڵ�ǰ��ָ����һ��β�ڵ�
	temp->pre = pNewNode;//�׽ڵ�ǰ��ָ���½ڵ�
	pNewNode->pre->next = pNewNode;//�½ڵ���Ϊβ�ڵ㣬��ǰ���ĺ�̾����½ڵ㱾��
}
/************************************************************************
 *���ܣ�ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�
 *���룺list:�����ַ
		n:��n���ڵ�,��0��ʼ��
 *�������
 *���أ���
************************************************************************/
void CycDouble_DeleteNote(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp,*pDeleteNode;//��ʱ�ڵ�
	temp = list;//��ʱ�ڵ�ָ���׽ڵ�
	printf("ɾ���ڵ�%d\r\n",n);
	if(temp->next == list)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(temp->next!=list && i--)
	{
		temp = temp->next;//ָ����һ���ڵ㣬ֱ��ָ��ָ���ڵ�
	}
	if(temp->next != list)//ע������temp��ָ���ڵ��ǰһ���ڵ�,����ɾ���׽ڵ�
	{
		pDeleteNode = temp->next;//temp�����Ҫɾ���Ľڵ�
		temp->next = pDeleteNode->next;//ǰһ���ڵ���
		temp = pDeleteNode->next;//��ʱ�ڵ㸳ֵΪҪɾ���ڵ�ĺ�һ���ڵ�
		temp->pre = pDeleteNode->pre;//��һ���ڵ�ǰ��
		free(pDeleteNode);//�ͷ��ڴ�
		pDeleteNode = NULL;
	}
	else
	{
		printf("�ڵ㲻���ڣ�\r\n");
	}
}
/************************************************************************
 *���ܣ�ɾ����������
 *���룺list:�����ַ
 *�������
 *���أ���
************************************************************************/
void CycDouble_DeleteLinkList(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*p;//��ʱ�ڵ�

	temp = list->next;//��ʱ�ڵ�ָ���׽ڵ���
	if(temp == list)
	{
		printf("����Ϊ�գ�\r\n");
		return;
	}
	while(temp!=list)
	{
		p = temp->next;//��ǰ�ڵ��̸�ֵ��p
		free(temp);//�ͷŵ�ǰ�ڵ��ڴ�
		temp = p;
	}
	/*����ͷָ�������δ˶δ���,�ر�ע��������ͷ��ڴ棡��Ҫ������������ʱ�������˴��룬�����ε�������д���
	 *��������������󣬲����ٱ����������������ڴ����ע���������ѭ��˫��������𣬷�ѭ��˫�������׽ڵ�ָ��NULL��
	 *�ж�Ϊ temp==NULL ,���Ժ����ͷ�p�ڴ沢�����ͷ��׽ڵ���ڴ棬�׽ڵ㻹�Ǳ����ģ����ڴ�����һϯ֮�أ�
	 *����������ж�Ϊ temp==list �����ͷ�p�����ͷ��׽ڵ���ڴ棬�׽ڵ�Ͳ������ˣ��ʺ�������ñ��������ͻ�����ڴ����
	 */
	if(temp==list)
	{
	//	free(p);//
	//	p = NULL;
		printf("ɾ������ɹ���\r\n");
	}
	list->next = list;//�׽ڵ���ָ������
	list->pre = list;//�׽ڵ�ǰ��ָ������
}

void testDoubleLink(void)
{
	DoubleLinkNode *teacher = Double_CreatLinkList(4);//����4���ڵ������,�������׽ڵ�
	
	Double_TraverseList(teacher);		//��������
	Double_InsertNode(teacher,4);		//�ڵ�n���ڵ�ǰ�����½ڵ�
	Double_TraverseList(teacher);		//��������
	Double_ChangeNodeValue(teacher,0);	//�޸ĵ�3���ڵ��ֵ
	Double_TraverseList(teacher);		//��������
	Double_DeleteNote(teacher,4);		//ɾ���ڵ�
	Double_TraverseList(teacher);		//��������
	Double_DeleteLinkList(teacher);		//ɾ������
	Double_TraverseList(teacher);		//��������
	
}
void testCycDoubleLink(void)
{
	DoubleLinkNode *people = CycDouble_CreatLinkList(10);

	CycDouble_TraverseList(people);		//��������
	CycDouble_InsertNode(people,4);		//�ڵ�n���ڵ�ǰ�����½ڵ�
	CycDouble_TraverseList(people);		//��������
	CycDouble_ChangeNodeValue(people,10);//�޸ĵ�3���ڵ��ֵ
	CycDouble_TraverseList(people);		//��������
	CycDouble_AddNode(people);		//����β�����½ڵ�
	CycDouble_AddNode(people);		//����β�����½ڵ�
	CycDouble_TraverseList(people);		//��������
	CycDouble_DeleteNote(people,12);	//ɾ���ڵ�
	CycDouble_TraverseList(people);		//��������
	CycDouble_DeleteNote(people,12);	//ɾ���ڵ�
	CycDouble_TraverseList(people);		//��������
	CycDouble_DeleteLinkList(people);	//ɾ������
	CycDouble_TraverseList(people);		//��������
}