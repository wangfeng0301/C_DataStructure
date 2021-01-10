/*********************************************************************
*�ַ�����
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "string_my.h"

//�����ַ�����Ч����,���ƽ�����
int Mystrlen(char * str)
{
	int lenth=0;
	while(*str++ != '\0')
		lenth++;
	return lenth;
}

//�ַ���str2���Ƶ�str1������ָ��ָ��str1
char *Mystrcpy(char *str1,char *str2)
{
//	int i;
	char *temp = str1;
	while((*str1++ = *str2++)!='\0');

	return temp;
}

//�ַ����Ƚ�
int Mystrcmp(char* str1,char* str2)
{
	int i=0;
	while(str1[i]!='\0' || str2[i]!='\0')
	{
		if(str1[i] > str2[i])
			return 1;
		else if(str1[i] < str2[i])
			return -1;
		i++;
	}
	return 0;
}

//�ַ���2�ӵ��ַ���1����




//atoi������ʵ���ַ���ת��Ϊ����
int Myatoi(char *str)
{
	int temp = 0;
	int i=0;
	int length = Mystrlen(str);//�ַ�������
	if(str[0] == '-' || str[0] == '+')//�ж����ַ��ǲ���������		
		i++;
	while(i<length)
	{
		if(str[i]>'0'&&str[i]<'9')
		{
			temp = temp*10+(str[i]-'0');
			i++;
		}
		else
		{
			printf("�ַ�%d���Ϸ���\r\n",i);
			return 0;
		}

	}
	if(str[0]=='-')
		temp = -temp;
	return temp;
}

//�����ַ�����������
int *findNext(char *P)
{
	int i=0;
	int k=-1;
	int m=Mystrlen(P);//�ַ���P����
	int *next = (int *)malloc(m*sizeof(int));//����m��int��С�ռ�
	if(m==0)//�ַ�����Ϊ0���˳�
		return;
	if(next == NULL)//���ٿռ�ʧ��
		return;
	next[0] = -1;
	while(i<m)
	{
		while(k>=0 && P[i]!=P[k])
			k=next[k];
		i++;
		k++;
		if(i==m) break;
		if(P[i] == P[k])
			next[i] = next[k];
		else
			next[i] = k;
	}
	return next;
}


void testString()
{

	char str1[]="Hello World";
	char str2[]="Thanks";
	char str3[]="abcdaabcab";
	int *next = findNext(str3);
	char str4[]="-1234a56";


	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);

	printf("Mystrlen(str1):%d\r\n",Mystrlen(str1));
	printf("Mystrlen(str2):%d\r\n",Mystrlen(str2));
	printf("str1-str2= %d\r\n",Mystrcmp(str1,str2));

	strcpy(str1,str2);
	printf("\r\nstr1:%s\r\n",str1);
	Mystrcpy(str1,str2);
	printf("\r\nstr1:%s\r\n",str1);
	printf("str1-str2= %d\r\n",Mystrcmp(str1,str2));

	printf("�ַ���%sת��Ϊ������%d\r\n",str4,Myatoi(str4));
	printf("�ַ���ת��Ϊ������%d\r\n",Myatoi(str4));
}