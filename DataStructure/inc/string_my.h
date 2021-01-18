#ifndef __MYSTRING_H__
#define __MYSTRING_H__

void *Mymemchr(const void *str, int c, size_t n);
int Mymemcmp(const void *str1, const void *str2, size_t n);
void *Mymemcpy(void *str1, const void *str2, size_t n);
void *Mymemmove(void *str1, const void *str2, size_t n);
void *Mymemset(void *str, int c, size_t n);
char *Mystrcat(char *dest, const char *src);
char *Mystrncat(char *dest, const char *src, size_t n);
char *Mystrchr(const char *str, int c);
int Mystrcmp(const char *str1, const char *str2);
int Mystrncmp(const char *str1, const char *str2, size_t n);
char *Mystrcpy(char *dest, const char *src);

int Mystrlen(char * str);
int Myatoi(char *str);//字符串转换为整数
int *findNext(char *P);

void testString(void);

#endif
