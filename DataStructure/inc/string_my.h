#ifndef __MYSTRING_H__
#define __MYSTRING_H__

void *Mymemchr(const void *str, int c, size_t n);
int Mymemcmp(const void *str1, const void *str2, size_t n);
void *Mymemcpy(void *str1, const void *str2, size_t n);
char *Mystrcat(char *dest, const char *src);
char *Mystrncat(char *dest, const char *src, size_t n);
char *Mystrchr(const char *str, int c);

int Mystrlen(char * str);					//�����ַ�������
char *Mystrcpy(char *str1,char *str2);		//���ַ���2���Ƶ��ַ���1��
int Mystrcmp(char* str1,char* str2);

int Myatoi(char *str);//�ַ���ת��Ϊ����
int *findNext(char *P);

void testString(void);

#endif
