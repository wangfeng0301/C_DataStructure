#ifndef __MYSTRING_H__
#define __MYSTRING_H__

void *Mymemchr(const void *str, int c, size_t n);
int Mymemcmp(const void *str1, const void *str2, size_t n);
void *Mymemcpy(void *str1, const void *str2, size_t n);
char *Mystrcat(char *dest, const char *src);
char *Mystrncat(char *dest, const char *src, size_t n);
char *Mystrchr(const char *str, int c);

int Mystrlen(char * str);					//计算字符串长度
char *Mystrcpy(char *str1,char *str2);		//将字符串2复制到字符串1中
int Mystrcmp(char* str1,char* str2);

int Myatoi(char *str);//字符串转换为整数
int *findNext(char *P);

void testString(void);

#endif
