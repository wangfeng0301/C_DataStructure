/*********************************************************************
*字符串：
*参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "string_my.h"

//计算字符串有效长度,不计结束符
int Mystrlen(char * str)
{
	int lenth=0;
	while(*str++ != '\0')
		lenth++;
	return lenth;
}

//字符串str2复制到str1，返回指针指向str1
char *Mystrcpy(char *str1,char *str2)
{
//	int i;
	char *temp = str1;
	while((*str1++ = *str2++)!='\0');

	return temp;
}

//字符串比较
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

//字符串2接到字符串1后面




//atoi函数，实现字符串转换为整数
int Myatoi(char *str)
{
	int temp = 0;
	int i=0;
	int length = Mystrlen(str);//字符串长度
	if(str[0] == '-' || str[0] == '+')//判断首字符是不是正负号		
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
			printf("字符%d不合法！\r\n",i);
			return 0;
		}

	}
	if(str[0]=='-')
		temp = -temp;
	return temp;
}

//计算字符串特征向量
int *findNext(char *P)
{
	int i=0;
	int k=-1;
	int m=Mystrlen(P);//字符串P长度
	int *next = (int *)malloc(m*sizeof(int));//开辟m个int大小空间
	if(m==0)//字符长度为0，退出
		return;
	if(next == NULL)//开辟空间失败
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

	printf("字符串%s转化为整数：%d\r\n",str4,Myatoi(str4));
	printf("字符串转化为整数：%d\r\n",Myatoi(str4));
}