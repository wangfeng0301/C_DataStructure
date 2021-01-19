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
 *功能：从存储区 str2 复制 n 个字节到存储区 str1
 *		与Mymemcpy不同的是，该函数在目标区域和源区域重叠时依然有效。
 *		如果出现覆区域重叠的情况，函数执行后会改变源目标的值
 *输入：str1:目标数组
 *		str2:原数组
 *		n:字节数
 *输出：无
 *返回：指向目标区str1的指针
************************************************************************/
void *Mymemmove(void *str1, const void *str2, size_t n)
{
	char *dst = (char *)str1;
	char *src = (char *)str2;

	if(dst > src && src + n > dst)//目标区域在源区域之后，且有覆盖，此时需要从后向前赋值
	{
		dst += n - 1;
		src += n - 1;
		while(n --)
			*dst-- = *src--;
	}
	else
	{
		while(n --)
			*dst++ = *src++;
	}
	return dst;
}
/************************************************************************
 *功能：复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符
 *输入：str:要填充的内存块
 *		c:被设置的值
 *		n:字节数
 *输出：无
 *返回：返回一个指向存储区 str 的指针
************************************************************************/
void *Mymemset(void *str, int c, size_t n)
{
	char *temp = str;
	while(n --)
		*temp++ = (char)c;
	return str;
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
/************************************************************************
 *功能：把 str1 所指向的字符串和 str2 所指向的字符串进行比较
 *输入：str1:要进行比较的第一个字符串。
 *		str2:要进行比较的第二个字符串。
 *输出：无
 *返回：返回值小于 0，则表示 str1 小于 str2。
 *		返回值大于 0，则表示 str1 大于 str2。
 *		返回值等于 0，则表示 str1 等于 str2。
************************************************************************/
int Mystrcmp(const char *str1, const char *str2)
{
	char *temp1,*temp2;
	if(str1 == NULL || str2 == NULL)
	{
		printf("字符串不能为空！\r\n");
		exit(-1);
	}
	temp1 = (char *)str1;
	temp2 = (char *)str2;
	while(*temp1 != 0 || *temp2 != 0)
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
 *功能：把 str1 和 str2 进行比较，最多比较前 n 个字节
 *输入：str1:要进行比较的第一个字符串。
 *		str2:要进行比较的第二个字符串。
 *		n:要比较的最大字符数
 *输出：无
 *返回：返回值小于 0，则表示 str1 小于 str2。
 *		返回值大于 0，则表示 str1 大于 str2。
 *		返回值等于 0，则表示 str1 等于 str2。
************************************************************************/
int Mystrncmp(const char *str1, const char *str2, size_t n)
{
	char *temp1,*temp2;
	if(str1 == NULL || str2 == NULL)
	{
		printf("字符串不能为空！\r\n");
		exit(-1);
	}
	temp1 = (char *)str1;
	temp2 = (char *)str2;
	while((*temp1 != 0 && *temp2 != 0) && n--)
	{
		if(*temp1 > *temp2)
			return 1;
		else if(*temp1 < *temp2)
			return -1;
		temp1 ++;
		temp2 ++;
	}
	if(n)//由于字符串结束而提前结束
	{
		if(*temp1 == 0 && *temp2 != 0)//str1比str2短
			return -1;
		else if(*temp1 != 0 && *temp2 == 0)//str1比str2长
			return 1;
		else
			return 0;
	}
	return 0;
}
/************************************************************************
 *功能：把 str1 和 str2 进行比较，结果取决于 LC_COLLATE 的位置设置
 *输入：str1:要进行比较的第一个字符串。
 *		str2:要进行比较的第二个字符串。
 *输出：无
 *返回：返回值小于 0，则表示 str1 小于 str2。
 *		返回值大于 0，则表示 str1 大于 str2。
 *		返回值等于 0，则表示 str1 等于 str2。
************************************************************************/
int Mystrcoll(const char *str1, const char *str2)
{

}
/************************************************************************
 *功能：把 src 所指向的字符串复制到 dest
 *输入：dest:指向用于存储复制内容的目标数组。
 *		src:要复制的字符串。
 *输出：无
 *返回：返回一个指向最终的目标字符串 dest 的指针。
************************************************************************/
char *Mystrcpy(char *dest, const char *src)
{
	char *temp = dest;
	while((*dest++ = *src++)!='\0');

	return temp;
}
/************************************************************************
 *功能：把 src 所指向的字符串复制到 dest，最多复制 n 个字符。当 src 的长度小于 n 时，dest 的剩余部分将用空字节填充。
 *输入：dest:指向用于存储复制内容的目标数组。
 *		src:要复制的字符串。
 *		n:要从源中复制的字符数。
 *输出：无
 *返回：返回最终复制的字符串
************************************************************************/
char *Mystrncpy(char *dest, const char *src, size_t n)
{
	char *temp = dest;
	while((*dest++ = *src++)!='\0' && n)
		n--;
	while(n)//src长度<n
	{
		*dest++ = 0;
		n--;
	}

	return temp;
}
/************************************************************************
 *功能：检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符
 *输入：str1:要被检索的 C 字符串。
 *		str2:该字符串包含了要在 str1 中进行匹配的字符列表。
 *输出：无
 *返回：返回 str1 开头连续都不含字符串 str2 中字符的字符数。
************************************************************************/
size_t Mystrcspn(const char *str1, const char *str2)
{
	// map有32个字节的大小，也就是256个bit，可把map看做一个2维数组[32][8]
    unsigned char map[32] = {0};
	int count = 0;

    // 每个ASCII码(设为c)有7bit，共128个。
    // map数组作为位图记录每个ASCII码是否出现过。map一个字节可以记录8个ASCII码
	// 如“0”的ASCII码是48，那么map[48/8]就是“0”在位图中的第几个字节
	// 而48 & 7（换成二进制就是0011 0000 & 0000 0111）可以定位到这个字节的第几个bit
    while(*str2)
    {
        map[*str2 >> 3] |= (1 << (*str2 & 7));
        str2++;
    }

    map[0] |= 1;//0在ascii中表示空，所以前面*str退出时一定是空，所以置位
    while(!(map[*str1 >> 3] & (1 << (*str1 & 7))))
    {
        count++;
        str1++;
    }

    return count;
}
//计算字符串有效长度,不计结束符
int Mystrlen(char * str)
{
	int lenth=0;
	while(*str++ != '\0')
		lenth++;
	return lenth;
}




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
	char src[]="Hello World";
	char src2[]="Hello World";
	char * dst,*dst2;
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

	printf("\r\nMymemmove test\r\n");
	dst = &src[5];
	printf("源字符串:%s\r\n",src);
	printf("目标字符串:%s\r\n",dst);
	Mymemcpy(dst, src, 6);
	printf("使用 Mymemcpy 后,源字符串: %s\n", src);
	printf("使用 Mymemcpy 后,目标字符串: %s\n", dst);
	dst2 = &src2[5];
	printf("源字符串:%s\r\n",src2);
	printf("目标字符串:%s\r\n",dst2);
	Mymemmove(dst, src2, 6);
	printf("使用 Mymemmove 后,源字符串: %s\n", src2);
	printf("使用 Mymemmove 后,目标字符串: %s\n", dst2);
	printf("使用 Mymemcpy 错误！\n");
	printf("使用 Mymemmove 正确！\n");

	printf("\r\nMymemset test\r\n");
	Mymemset(src2,'A',sizeof(src2)-1);
	printf("src2:%s\r\n",src2);

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

	printf("\r\nMystrcmp test\r\n");
	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);
	ret = Mystrcmp(str1, str2);
	if(ret > 0)
		printf("str2 小于 str1\r\n");
	else if(ret < 0) 
		printf("str1 小于 str2\r\n");
	else 
		printf("str1 等于 str2\r\n");

	printf("\r\nMystrncmp test\r\n");
	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);
	ret = Mystrncmp(str1, str2,5);
	if(ret > 0)
		printf("str2 小于 str1\r\n");
	else if(ret < 0) 
		printf("str1 小于 str2\r\n");
	else 
		printf("str1 等于 str2\r\n");

	printf("\r\nMystrcpy test\r\n");
	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);
	Mystrcpy(str1,str2);
	//strcpy(str1,str2);
	printf("str1:%s\r\n",str1);
	printf("str1-str2= %d\r\n",Mystrcmp(str1,str2));

	printf("\r\nMystrncpy test\r\n");
	memset(str1,0,sizeof(str1));
	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);
	//Mystrncpy(str1,str2,10);
	Mystrncpy(str1,str2,3);
	//strncpy(str1,str2,1);
	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);





	printf("str1:%s\r\n",str1);
	printf("str2:%s\r\n",str2);

	printf("Mystrlen(str1):%d\r\n",Mystrlen(str1));
	printf("Mystrlen(str2):%d\r\n",Mystrlen(str2));
	printf("str1-str2= %d\r\n",Mystrcmp(str1,str2));

	printf("字符串%s转化为整数：%d\r\n",str4,Myatoi(str4));
	printf("字符串转化为整数：%d\r\n",Myatoi(str4));
}