#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "DoubleLink.h"

/*��������
*n ����ڵ�������������׽ڵ�
*/
DoubleLinkNode *CreatDoubleLinkList(unsigned int n)
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

/************************************************************************/
/*�ڵ���������׽ڵ㿪ʼ����
 *list:����*/
/************************************************************************/
void TraverseDoubleList(DoubleLinkNode *list)
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

/************************************************************************/
/*�޸Ľڵ�ֵ
 *n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *list:����*/
/************************************************************************/
void ChangeDoubleNodeValue(DoubleLinkNode * list,unsigned int n)
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
/************************************************************************/
/* �ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *n:��n���ڵ�*/
/************************************************************************/
void InsertDoubleNode(DoubleLinkNode *list,unsigned int n)
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
/************************************************************************/
/*ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�                                                                     */
/************************************************************************/
void DeleteDoubleNote(DoubleLinkNode *list,unsigned int n)
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
		//printf("\r\n");
		//printf("temp      :%x\r\n",temp);
		//printf("temp->next:%x\r\n",temp->next);
		//printf("temp->pre :%x\r\n",temp->pre);
		//printf("pDeleteNode      :%x\r\n",pDeleteNode);
		//printf("pDeleteNode->next:%x\r\n",pDeleteNode->next);
		//printf("pDeleteNode->pre :%x\r\n",pDeleteNode->pre);
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
/************************************************************************/
/* ɾ����������                                                         */
/************************************************************************/
void DeleteDoubleLinkList(DoubleLinkNode *list)
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

/**************************************************************
*����ѭ��˫����
*n ����ڵ�������������׽ڵ�
***************************************************************/
DoubleLinkNode *CreatCycDoubleLinkList(unsigned int n)
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

/************************************************************************/
/*�ڵ���������׽ڵ㿪ʼ����
 *list:����*/
/************************************************************************/
void TraverseCycDoubleList(DoubleLinkNode *list)
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

//************************************************************************/
/*�޸Ľڵ�ֵ
 *n:��n���ڵ�,n��0��ʼ�㡣ֻ����ͨ�ڵ�
 *list:����*/
/************************************************************************/
void ChangeCycDoubleNodeValue(DoubleLinkNode * list,unsigned int n)
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
/************************************************************************/
/* �ڵ�n���ڵ�ǰ����ڵ㣬�ڵ��0��ʼ�㣬ֻ����ͨ�ڵ�
 *n:��n���ڵ�*/
/************************************************************************/
void InsertCycDoubleNode(DoubleLinkNode *list,unsigned int n)
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
/************************************************************************/
/* �ڱ�β�����½ڵ�
/************************************************************************/
void AddCycDoubleNode(DoubleLinkNode *list,unsigned int num)
{
	DoubleLinkNode *temp,*pNewNode;//��ʱ�ڵ�
	temp = list;//��ʱ�ڵ�ָ���׽ڵ�

	printf("�ڱ�β�����½ڵ�\r\n");
	pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//Ϊ�½ڵ�����ڴ�
	//printf("�������½ڵ����ݣ�");
	//scanf("%d",&pNewNode->Element);
	pNewNode->Element = num;

	pNewNode->next = temp;//�½ڵ���ָ���׽ڵ�
	pNewNode->pre = temp->pre;//�½ڵ�ǰ��ָ����һ��β�ڵ�
	temp->pre = pNewNode;//�׽ڵ�ǰ��ָ���½ڵ�
	pNewNode->pre->next = pNewNode;//�½ڵ���Ϊβ�ڵ㣬��ǰ���ĺ�̾����½ڵ㱾��
}
/************************************************************************/
/*ɾ����n���ڵ㣬n��0��ʼ�㣬ֻ����ͨ�ڵ�                                                                     */
/************************************************************************/
void DeleteCycDoubleNote(DoubleLinkNode *list,unsigned int n)
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
		//printf("\r\n");
		//printf("temp      :%x\r\n",temp);
		//printf("temp->next:%x\r\n",temp->next);
		//printf("temp->pre :%x\r\n",temp->pre);
		//printf("pDeleteNode      :%x\r\n",pDeleteNode);
		//printf("pDeleteNode->next:%x\r\n",pDeleteNode->next);
		//printf("pDeleteNode->pre :%x\r\n",pDeleteNode->pre);
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
/************************************************************************/
/* ɾ����������                                                         */
/************************************************************************/
void DeleteCycDoubleLinkList(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*p;//��ʱ�ڵ�
	temp = list->next;//��ʱ�ڵ�ָ���׽ڵ���
	//list->next = NULL;
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
	//if(temp==list)//����ͷָ�������δ˶δ���,�ر�ע��������ͷ��ڴ棡��Ҫ������������ʱ�������˴��룬�����ε�������д���
	                //��������������󣬲����ٱ����������������ڴ����ע���������ѭ��˫��������𣬷�ѭ��˫�������׽ڵ�ָ��NULL��
	                //�ж�Ϊ temp==NULL ,���Ժ����ͷ�p�ڴ沢�����ͷ��׽ڵ���ڴ棬�׽ڵ㻹�Ǳ����ģ����ڴ�����һϯ֮�أ�
	                //����������ж�Ϊ temp==list �����ͷ�p�����ͷ��׽ڵ���ڴ棬�׽ڵ�Ͳ������ˣ��ʺ�������ñ��������ͻ�����ڴ����
	//{
	//	free(p);//
	//	p = NULL;
	//	printf("ɾ������ɹ���\r\n");
	//}
	list->next = list;//�׽ڵ���ָ������
	list->pre = list;//�׽ڵ�ǰ��ָ������
}

/*Josephus���⣺n��Χһ�����ӵ�s�˿�ʼ������������m�˳���
*�ӳ�����һ�������¿�ʼ������������m�˳��У��Դ�����
*/
void josephus(unsigned int n,unsigned int s,unsigned int m)
{
	unsigned int i=0,j=0;
	DoubleLinkNode *person = CreatCycDoubleLinkList(0);//����һ��ѭ������0����Ч�ڵ�
	DoubleLinkNode *temp=person;//��ʱ�ڵ����,��ֵΪ�׽ڵ�
	DoubleLinkNode *p;//���ɾ��ǰ�ڵ��ַ
	if(n<1)
	{		
		printf("�������������1��");
		return;
	}
	if(s>n || s<1)
	{
		printf("��ʼ��������С�ڵ����������Ҵ���0��");
		return;
	}
	if(m<1)
	{
		printf("������m�������0��");
		return;
	}

	for(i=0;i<n;i++)//��β���n���ڵ㣬��ʾn����
		AddCycDoubleNode(person,i+1);
	TraverseCycDoubleList(person);//����������ÿ�˱��

	while(s--)//��λ����s��
	{
		temp = temp->next;
	}
	printf("\r\n��ʼ�����˱�ţ�%d\r\n",temp->Element);

	for(j=0;j<n;j++)//�������̭��Ա���
	{
		for(i=0;i<m-1;i++)//��ʼ���������ӿ�ʼλ�ü�1��ֱ���ӵ�m
		{
			temp = temp->next;
			if(temp == person)//ָ���׽ڵ㣬�Զ�����
				temp = temp->next;
		}
		p = temp->next;//��һ���ڵ㱣�浽p��
		if(p == person)//ָ���׽ڵ㣬�Զ�����
			p = p->next;
		if(p == person)
		{
			printf("�������\r\n");
			return;
		}
		printf("��̭��%d�˱�ţ�%d\r\n",j+1,temp->Element);//�����ǰ�ڵ���

		/*ɾ����ǰ�ڵ�*/
		temp->pre->next = temp->next;//��ɾ���ڵ��ǰ���ĺ��ָ��ɾ���ڵ�ĺ��
		temp->next->pre = temp->pre;//��ɾ���ڵ�ĺ�̵�ǰ��ָ��ɾ���ڵ��ǰ��
		free(temp);//�ͷű�ɾ���ڵ��ڴ�

		temp = p;//��ʱ�ڵ�ָ����һ���ڵ�
	}
	printf("\r\n�������������\r\n");
	TraverseCycDoubleList(person);//����������ÿ�˱��

	printf("\r\nɾ������\r\n");
	DeleteCycDoubleLinkList(person);

	printf("\r\nɾ�������������������\r\n");
	TraverseCycDoubleList(person);//����������ÿ�˱��

}


void testDoubleLink()
{
	DoubleLinkNode *teacher = CreatDoubleLinkList(4);//����4���ڵ������,�������׽ڵ�
	
	TraverseDoubleList(teacher);		//��������
	InsertDoubleNode(teacher,4);		//�ڵ�n���ڵ�ǰ�����½ڵ�
	TraverseDoubleList(teacher);		//��������
	ChangeDoubleNodeValue(teacher,0);	//�޸ĵ�3���ڵ��ֵ
	TraverseDoubleList(teacher);		//��������
	DeleteDoubleNote(teacher,4);		//ɾ���ڵ�
	TraverseDoubleList(teacher);		//��������
	DeleteDoubleLinkList(teacher);		//ɾ������
	TraverseDoubleList(teacher);		//��������
	
}
void testCycDoubleLink()
{
	DoubleLinkNode *people = CreatCycDoubleLinkList(10);
	unsigned n=500,s=60,m=51;

	TraverseCycDoubleList(people);		//��������
	InsertCycDoubleNode(people,4);		//�ڵ�n���ڵ�ǰ�����½ڵ�
	TraverseCycDoubleList(people);		//��������
	ChangeCycDoubleNodeValue(people,10);//�޸ĵ�3���ڵ��ֵ
	TraverseCycDoubleList(people);		//��������
	AddCycDoubleNode(people,111);		//����β�����½ڵ�
	AddCycDoubleNode(people,112);		//����β�����½ڵ�
	TraverseCycDoubleList(people);		//��������
	DeleteCycDoubleNote(people,12);		//ɾ���ڵ�
	TraverseCycDoubleList(people);		//��������
	DeleteCycDoubleNote(people,12);		//ɾ���ڵ�
	TraverseCycDoubleList(people);		//��������
	DeleteCycDoubleLinkList(people);	//ɾ������
	TraverseCycDoubleList(people);		//��������

	printf("josephus���⣺\r\n");
	josephus(n,s,m);
}