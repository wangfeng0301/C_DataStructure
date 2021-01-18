/*********************************************************************
*字符串：实现C标准库<string.h>
*参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "string_my.h"

/************************************************************************
 *功能：在参数 str 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）的位置。
 *输入：str:要执行的内存块
 *		c:以 int 形式传递的值，但是函数在每次字节搜索时是使用该值的无符号字符形式。
 *		n:要被分析的字节数
 *输出：无
 *返回：返回一个指向匹配字节的指针，如果在给定的内存区域未出现字符，则返回 NULL。
************************************************************************/
void *Mymemchr(const void *str, int c, size_t n)
{
	char *temp;
	if(str == NULL)
	{
		printf("字符串为空\r\n");
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
 *功能：把存储区 str1 和存储区 str2 的前 n 个字节进行比较
 *输入：str1:要比较的字符串
 *		str2:要比较的字符串
 *		n:要比较的字节数
 *输出：无
 *返回：str<str2,<0;str1=str2,=0;str1>str2,>0
************************************************************************/
int Mymemcmp(const void *str1, const void *str2, size_t n)
{
	char *temp1,*temp2;
	if(str1 == NULL || str2 == NULL)
	{
		printf("字符串不能为空！\r\n");
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
 *功能：从存储区 str2 复制 n 个字节到存储区 str1
 *输入：str1:目标数组
 *		str2:原数组
 *		n:字节数
 *输出：无
 *返回：指向目标区str1的指针
************************************************************************/
void *Mymemcpy(void *str1, const void *str2, size_t n) 
{
	char *temp1,*temp2;
	if(str1 == NULL || str2 == NULL)
	{
		printf("字符串不能为空！\r\n");
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
 *功能：src 所指向的字符串追加到 dest 所指向的字符串的结尾
 *输入：src:指向要追加的字符串，该字符串不会覆盖目标字符串。
 *		dest:指向目标数组，该数组包含了一个 C 字符串，且足够容纳追加后的字符串。
 *输出：无
 *返回：返回一个指向最终的目标字符串 dest 的指针。
************************************************************************/
char *Mystrcat(char *dest, const char *src)
{
	char *temp = (char *)src;
	char *temp2 = dest;
	int len = strlen(dest);//目标串大小
	while(*temp != 0)
		temp2[len++] = *temp++;
	temp2[len] = 0;//加结束符
	return dest;
}
/************************************************************************
 *功能：把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，直到 n 字符长度为止。
 *输入：src:要追加的字符串。
 *		dest:指向目标数组，该数组包含了一个 C 字符串，且足够容纳追加后的字符串，包括额外的空字符。
 *		n:要追加的最大字符数。
 *输出：无
 *返回：返回一个指向最终的目标字符串 dest 的指针。
************************************************************************/
char *Mystrncat(char *dest, const char *src, size_t n)
{
	char *temp = (char *)src;
	char *temp2 = dest;
	int len = strlen(dest);//目标串大小
	while(n --)
		temp2[len++] = *temp++;
	temp2[len] = 0;//加结束符
	return dest;
}
/************************************************************************
 *功能：在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。
 *输入：src:要被检索的 C 字符串。
 *		c:在 str 中要搜索的字符。
 *输出：无
 *返回：返回在字符串 str 中第一次出现字符 c 的位置，如果未找到该字符则返回 NULL。
************************************************************************/
char *Mystrchr(const char *str, int c)
{
	char *temp;
	if(str == NULL)
	{
		printf("字符串为空\r\n");
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
	printf("[%c] 之后的字符串是 - [%s]\n", ch, retchar);

	printf("\r\nMymemcmp test\r\n");
	ret = Mymemcmp(str1, str2, 5);
	if(ret > 0)
		printf("str2 小于 str1\r\n");
	else if(ret < 0) 
		printf("str1 小于 str2\r\n");
	else 
		printf("str1 等于 str2\r\n");

	printf("\r\nMymemcpy test\r\n");
	printf("使用 memcpy 前: %s\n", str1);
	Mymemcpy(str1, str2, strlen(str2));
	printf("使用 memcpy 后: %s\n", str1);

	printf("\r\nMystrcat test\r\n");
	printf("str5:%s\r\n",str5);
	printf("str1:%s\r\n",str1);
	retchar = Mystrcat(str5,str1);
	printf("链接str5和str1：%s\r\n",retchar);

	printf("\r\nMystrncat test\r\n");
	printf("str5:%s\r\n",str5);
	printf("str1:%s\r\n",str1);
	retchar = Mystrncat(str5,str1,5);
	printf("链接str5和str1：%s\r\n",retchar);

	printf("\r\nMystrchr test\r\n");
	printf("str5:%s\r\n",str5);
	ch = '5';
	retchar = (char*)Mystrchr(str5, ch);
	printf("[%s]中[%c] 之后的字符串是 - [%s]\n", str5, ch, retchar);

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