/*********************************************************************
*�ַ�����ʵ��C��׼��<string.h>
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "string_my.h"

/************************************************************************
 *���ܣ��ڲ��� str ��ָ����ַ�����ǰ n ���ֽ���������һ�γ����ַ� c��һ���޷����ַ�����λ�á�
 *���룺str:Ҫִ�е��ڴ��
 *		c:�� int ��ʽ���ݵ�ֵ�����Ǻ�����ÿ���ֽ�����ʱ��ʹ�ø�ֵ���޷����ַ���ʽ��
 *		n:Ҫ���������ֽ���
 *�������
 *���أ�����һ��ָ��ƥ���ֽڵ�ָ�룬����ڸ������ڴ�����δ�����ַ����򷵻� NULL��
************************************************************************/
void *Mymemchr(const void *str, int c, size_t n)
{
	char *temp;
	if(str == NULL)
	{
		printf("�ַ���Ϊ��\r\n");
		exit(-1);
	}
	temp = (char*)str;
	while(*temp != 0 && n > 0)
	{
		if(*temp == c)
			return (void *)temp;
		n --;
		temp ++;
	}
	return NULL;
}
/************************************************************************
 *���ܣ��Ѵ洢�� str1 �ʹ洢�� str2 ��ǰ n ���ֽڽ��бȽ�
 *���룺str1:Ҫ�Ƚϵ��ַ���
 *		str2:Ҫ�Ƚϵ��ַ���
 *		n:Ҫ�Ƚϵ��ֽ���
 *�������
 *���أ�str<str2,<0;str1=str2,=0;str1>str2,>0
************************************************************************/
int Mymemcmp(const void *str1, const void *str2, size_t n)
{
	char *temp1,*temp2;
	if(str1 == NULL || str2 == NULL)
	{
		printf("�ַ�������Ϊ�գ�\r\n");
		exit(-1);
	}
	temp1 = (char *)str1;
	temp2 = (char *)str2;
	while(n --)
	{
		if(*temp1 > *temp2)
			return 1;
		else if(*temp1 < *temp2)
			return -1;
		temp1 ++;
		temp2 ++;
	}
	return 0;
}
/************************************************************************
 *���ܣ��Ӵ洢�� str2 ���� n ���ֽڵ��洢�� str1
 *���룺str1:Ŀ������
 *		str2:ԭ����
 *		n:�ֽ���
 *�������
 *���أ�ָ��Ŀ����str1��ָ��
************************************************************************/
void *Mymemcpy(void *str1, const void *str2, size_t n) 
{
	char *temp1,*temp2;
	if(str1 == NULL || str2 == NULL)
	{
		printf("�ַ�������Ϊ�գ�\r\n");
		exit(-1);
	}
	temp1 = (char *)str1;
	temp2 = (char *)str2;
	while(n --)
	{
		*temp1++ = *temp2++;
	}
	return str1;
}
/************************************************************************
 *���ܣ�src ��ָ����ַ���׷�ӵ� dest ��ָ����ַ����Ľ�β
 *���룺src:ָ��Ҫ׷�ӵ��ַ��������ַ������Ḳ��Ŀ���ַ�����
 *		dest:ָ��Ŀ�����飬�����������һ�� C �ַ��������㹻����׷�Ӻ���ַ�����
 *�������
 *���أ�����һ��ָ�����յ�Ŀ���ַ��� dest ��ָ�롣
************************************************************************/
char *Mystrcat(char *dest, const char *src)
{
	char *temp = (char *)src;
	char *temp2 = dest;
	int len = strlen(dest);//Ŀ�괮��С
	while(*temp != 0)
		temp2[len++] = *temp++;
	temp2[len] = 0;//�ӽ�����
	return dest;
}
/************************************************************************
 *���ܣ��� src ��ָ����ַ���׷�ӵ� dest ��ָ����ַ����Ľ�β��ֱ�� n �ַ�����Ϊֹ��
 *���룺src:Ҫ׷�ӵ��ַ�����
 *		dest:ָ��Ŀ�����飬�����������һ�� C �ַ��������㹻����׷�Ӻ���ַ�������������Ŀ��ַ���
 *		n:Ҫ׷�ӵ�����ַ�����
 *�������
 *���أ�����һ��ָ�����յ�Ŀ���ַ��� dest ��ָ�롣
************************************************************************/
char *Mystrncat(char *dest, const char *src, size_t n)
{
	char *temp = (char *)src;
	char *temp2 = dest;
	int len = strlen(dest);//Ŀ�괮��С
	while(n --)
		temp2[len++] = *temp++;
	temp2[len] = 0;//�ӽ�����
	return dest;
}
/************************************************************************
 *���ܣ��ڲ��� str ��ָ����ַ�����������һ�γ����ַ� c��һ���޷����ַ�����λ�á�
 *���룺src:Ҫ�������� C �ַ�����
 *		c:�� str ��Ҫ�������ַ���
 *�������
 *���أ��������ַ��� str �е�һ�γ����ַ� c ��λ�ã����δ�ҵ����ַ��򷵻� NULL��
************************************************************************/
char *Mystrchr(const char *str, int c)
{
	char *temp;
	if(str == NULL)
	{
		printf("�ַ���Ϊ��\r\n");
		exit(-1);
	}
	temp = (char *)str;
	while(*temp != 0)
	{
		if(*temp == c)
			return temp;
		temp ++;
	}
	return NULL;
}
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


void testString(void)
{

	char str1[]="Hello World";
	char str2[]="Thanks";
	char str3[]="abcdaabcab";
	int *next = findNext(str3);
	char str4[]="-1234a56";
	char ch = 'c';
	int ret;
	char *retchar;
	char str5[50] = {"12345"};

	printf("Mymemchr test\r\n");
	retchar = (char*)Mymemchr(str1, ch, strlen(str1));
	printf("[%c] ֮����ַ����� - [%s]\n", ch, retchar);

	printf("\r\nMymemcmp test\r\n");
	ret = Mymemcmp(str1, str2, 5);
	if(ret > 0)
		printf("str2 С�� str1\r\n");
	else if(ret < 0) 
		printf("str1 С�� str2\r\n");
	else 
		printf("str1 ���� str2\r\n");

	printf("\r\nMymemcpy test\r\n");
	printf("ʹ�� memcpy ǰ: %s\n", str1);
	Mymemcpy(str1, str2, strlen(str2));
	printf("ʹ�� memcpy ��: %s\n", str1);

	printf("\r\nMystrcat test\r\n");
	printf("str5:%s\r\n",str5);
	printf("str1:%s\r\n",str1);
	retchar = Mystrcat(str5,str1);
	printf("����str5��str1��%s\r\n",retchar);

	printf("\r\nMystrncat test\r\n");
	printf("str5:%s\r\n",str5);
	printf("str1:%s\r\n",str1);
	retchar = Mystrncat(str5,str1,5);
	printf("����str5��str1��%s\r\n",retchar);

	printf("\r\nMystrchr test\r\n");
	printf("str5:%s\r\n",str5);
	ch = '5';
	retchar = (char*)Mystrchr(str5, ch);
	printf("[%s]��[%c] ֮����ַ����� - [%s]\n", str5, ch, retchar);

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