#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "application.h"
#include "DoubleLink.h"
#include "link.h"

///*Josephus���⣺n��Χһ�����ӵ�s�˿�ʼ������������m�˳���
//*�ӳ�����һ�������¿�ʼ������������m�˳��У��Դ�����
//*/
//void josephus(unsigned int n,unsigned int s,unsigned int m)
//{
//	unsigned int i=0,j=0;
//	DoubleLinkNode *person = CreatCycDoubleLinkList(0);//����һ��ѭ������0����Ч�ڵ�
//	DoubleLinkNode *temp=person;//��ʱ�ڵ����,��ֵΪ�׽ڵ�
//	DoubleLinkNode *p;//���ɾ��ǰ�ڵ��ַ
//	if(n<1)
//	{		
//		printf("�������������1��");
//		return;
//	}
//	if(s>n || s<1)
//	{
//		printf("��ʼ��������С�ڵ����������Ҵ���0��");
//		return;
//	}
//	if(m<1)
//	{
//		printf("������m�������0��");
//		return;
//	}
//	
//	for(i=0;i<n;i++)//��β���n���ڵ㣬��ʾn����
//		AddCycDoubleNode(person,i+1);
//	TraverseCycDoubleList(person);//����������ÿ�˱��
//
//	while(s--)//��λ����s��
//	{
//		temp = temp->next;
//	}
//	printf("\r\n��ʼ�����˱�ţ�%d\r\n",temp->Element);
//
//	for(j=0;j<n;j++)//�������̭��Ա���
//	{
//		for(i=0;i<m-1;i++)//��ʼ���������ӿ�ʼλ�ü�1��ֱ���ӵ�m
//		{
//			temp = temp->next;
//			if(temp == person)//ָ���׽ڵ㣬�Զ�����
//				temp = temp->next;
//		}
//		p = temp->next;//��һ���ڵ㱣�浽p��
//		if(p == person)//ָ���׽ڵ㣬�Զ�����
//			p = p->next;
//		if(p == person)
//		{
//			printf("�������\r\n");
//			return;
//		}
//		printf("��̭��%d�˱�ţ�%d\r\n",j+1,temp->Element);//�����ǰ�ڵ���
//		
//		/*ɾ����ǰ�ڵ�*/
//		temp->pre->next = temp->next;//��ɾ���ڵ��ǰ���ĺ��ָ��ɾ���ڵ�ĺ��
//		temp->next->pre = temp->pre;//��ɾ���ڵ�ĺ�̵�ǰ��ָ��ɾ���ڵ��ǰ��
//		free(temp);//�ͷű�ɾ���ڵ��ڴ�
//		
//		temp = p;//��ʱ�ڵ�ָ����һ���ڵ�
//	}
//	printf("\r\n�������������\r\n");
//	TraverseCycDoubleList(person);//����������ÿ�˱��
//
//	printf("\r\nɾ������\r\n");
//	DeleteCycDoubleLinkList(person);
//
//	printf("\r\nɾ�������������������\r\n");
//	TraverseCycDoubleList(person);//����������ÿ�˱��
//
//}