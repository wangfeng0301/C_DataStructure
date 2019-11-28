#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

/************************˳��ջ������ȳ�***********************************/

//����ջ,size:ջ�Ĵ�С
void CreateStack(stack *s,int size)
{
	 s->size = size;
	 s->top = -1;//ջ����Ҳ��ʾ��ǰջ��Ԫ�صĸ�����1
	 s->st = (char *)malloc(size*sizeof(char));//����size���ֽڿռ�
}
//ѹջ
void push(stack *s,char c)
{
	if(s->top < s->size-1)//ջ��С��ջ��������
	{
		(s->top)++;//ջ����1
		s->st[s->top] = c;//ջ��ֵ		
	}
	else
	{
		printf("ջ�����\r\n");
		return;
	}
}

//��ջ
char pop(stack *s)
{
	char temp;
	if(s->top > -1)//ջ�ǿ�
	{
		temp = s->st[s->top];
		(s->top)--;
		return temp;
	}
	else
	{
		printf("ջ��\r\n");
		return 0;
	}
}

//���ջ
void clear(stack *s)
{
	s->top = -1;
}

//��ȡջ��Ԫ�ظ���
int top(stack *s)
{
	return (s->top)+1;
}

/***************************��ʽջ*************************************/
//����ջ,size:ջ�Ĵ�С
void CreateLinkStack(LinkStack *s)
{
	s->size = 0;//��ʼ��Ϊ��ջ
	s->top = NULL;//ָ���
}
//ѹջ
void LSpush(LinkStack *s,int c)//����ײ���ڵ㣬��Ϊ����ڵ�
{
	LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));//���ٿռ�,��СΪLinkNode
	if(s->top == NULL)		//��һ��ѹջ��Ԫ��
	{
		s->top = temp;		//ջ��ָ��ǰ�ռ�
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;//�½��ڵ�ָ��֮ǰ�Ľڵ㣬�൱����֮ǰ�ڵ�������½ڵ�
		s->top = temp;
	}
	s->top->Element = c;	//��ֵ
	s->size++;				//ջ��С��1
}

//��ջ,����ջ��Ԫ��
int LSpop(LinkStack *s)
{
	int temp=0;
	LinkNode *tempNode;//��ʱ�ڵ�
	if(s->top != NULL)//ջ�ǿ�
	{
		temp = s->top->Element;//��ȡԪ��
		tempNode = s->top;//��ǰ�ڵ����ʱ�ڵ�
		s->top = s->top->next;//ָ����һ���ڵ�
		free(tempNode);
		tempNode = NULL;
		s->size--;//ջ���1

		return temp;
	}
	else
	{
		printf("ջ��\r\n");
		return 0;
	}
}

//���ջ
void LSclear(LinkStack *s)
{
	LinkNode *temp;
	while(s->top != 0)
	{
		temp = s->top->next;
		free(s->top);
		s->top = temp;
	}
	if(s->top == NULL)
	{
		s->size = 0;
		printf("��ջ�ɹ���\r\n");
	}
}

/***************************�ݹ��㷨*************************************/

/*n�Ľ׳ˣ��ݹ鷽ʽ*/
long factorial_recursion(long n)
{
	if(n<=1)
		return 1;
	else
		return n*factorial_recursion(n-1);
}
/*n�Ľ׳ˣ�������ʽ*/
long factorial_iteration(long n)
{
	long m=1;
	long i;
	if(n>=0)
	{
		for(i=1;i<=n;i++)
			m = m*i;
	}
	else
	{
		printf("�������Ӧ�ô��ڵ���0��\r\n");
		return 0;
	}
	return m;
}

/****************************************************************************/
/*��������
*����һ�������ɷ�������Ϊs������n����Ʒ�������ֱ�Ϊw0,w1,...wn-1
*���ܷ����n����Ʒ��ѡ�����ɷ��뱳����������֮������Ϊs��*/
/*
						/	true,   ��s=0
knap_recursion(s,n)=   |	false,  ��s<0��s>0��n<1��
						\	knap_recursion(s-wn-1,n-1,w)||knap_recursion(s,n-1,w),��s>0��n>=1
/****************************************************************************/
//�ݹ鷽��
unsigned char knap_recursion(int s,int n,int* w)
{
	if(0 == s)
		return 1;
	if(s<0 || (s>0 && n<1))
		return 0;
	if(s>0 && n>=1)
	{
		if(knap_recursion(s-w[n-1],n-1,w))
		{
			printf("%d ",w[n-1]);
			return 1;
		}
		else
			return knap_recursion(s,n-1,w);
	}
}

//�ǵݹ鷽����ʹ��ջ
//����1����w[n-1]�����ڽ��У����knap(s-w[n-1],n-1)
//����2����w[n-1]�������ڽ��У����knap(s,n-1)
typedef enum //���ص�ַ����
{
	rd1=0,			//��һ�����������knap(s,n)��Ϸ��ص����ñ���������������
	rd2,			//�ڶ������������knap(s-w[n-1],n-1)��ϣ����ص������ú�����������
	rd3				//���������������knap(s,n-1)��ϣ����ص������ú�����������
}rdType;
typedef struct  
{
	int s,n;		//�����ĳ���������Ʒ����Ŀ
	rdType rd;		//���ص�ַ
	unsigned char k;//�����Ԫ
}KnapNode;

/*����ڵ�ṹ��*/
typedef struct LinkNode_knap
{
	KnapNode node;
	struct LinkNode_knap* next;
}LinkNode_knap;
/*����ṹ��*/
typedef struct
{
	LinkNode_knap *top;	
	int size;
}LinkStack_knap;
/*����ջ,size:ջ�Ĵ�С*/
static void CreateLinkStack_knap(LinkStack_knap *s)
{
	s->size = 0;	//��ʼ��Ϊ��ջ
	s->top = NULL;	//ָ���
}
/*ѹջ*/
static void LSpush_knap(LinkStack_knap *s,KnapNode node)//�����ײ���ڵ㣬��Ϊ����ڵ�
{
	LinkNode_knap *temp = (LinkNode_knap *)malloc(sizeof(LinkNode_knap));//���ٿռ�,��СΪLinkNode_knap
	if(s->top == NULL)				//��һ��ѹջ��Ԫ��
	{
		s->top = temp;				//ջ��ָ��ǰ�ռ�
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;		//�½��ڵ�ָ��֮ǰ�Ľڵ㣬�൱����֮ǰ�ڵ�������½ڵ�
		s->top = temp;
	}
	s->top->node.k = node.k;		//��ֵ
	s->top->node.n = node.n;
	s->top->node.rd = node.rd;
	s->top->node.s = node.s;
	s->size++;						//ջ��С��1
}

/*��ջ,����ջ��Ԫ��*/
static KnapNode LSpop_knap(LinkStack_knap *s)
{
	KnapNode temp;
	LinkNode_knap *tempNode;		//��ʱ�ڵ�
	if(s->top != NULL)				//ջ�ǿ�
	{
		temp.k = s->top->node.k;	//��ȡԪ��
		temp.n = s->top->node.n;
		temp.rd = s->top->node.rd;
		temp.s = s->top->node.s;
		tempNode = s->top;			//��ǰ�ڵ����ʱ�ڵ�
		s->top = s->top->next;		//ָ����һ���ڵ�
		free(tempNode);
		tempNode = NULL;
		s->size--;					//ջ��С��1

		return temp;
	}
	else
	{
		printf("ջ��\r\n");
		return;
	}
}
/*�п�*/
static unsigned char isEmpty_knap(LinkStack_knap *s)
{
	if(s->top != NULL)				//ջ�ǿշ���0
	{
		return 0;
	}
	else
	{
		printf("ջ��\r\n");			//ջ�շ���1
		return 1;
	}
}
/*����ջ�����ݣ���������*/
static unsigned char LStop_knap(LinkStack_knap *s,KnapNode *node)
{
	if(s->size == 0)
	{
		printf("ջΪ�գ����ܶ���ջ��Ԫ��\r\n");
		return 0;
	}
	else
	{
		node->n = s->top->node.n;
		node->rd = s->top->node.rd;
		node->s = s->top->node.s;
		return 1;
	}

}
/*�ǵݹ鷽������ʵ��*/
unsigned char nonRecKnap(int s,int n,int* w)
{				
	//KnapNode *tmp = (KnapNode *)malloc(sizeof(KnapNode));	//�����¿ռ�
	//KnapNode *x = (KnapNode *)malloc(sizeof(KnapNode));		//�����¿ռ�//�������
	KnapNode tmp,x;
	LinkStack_knap knap;									//��ʽջ����

	CreateLinkStack_knap(&knap);							//������ʽջ

	tmp.s = s;												//�ǵݹ麯�����,��ʼ��
	tmp.n = n;
	tmp.rd = rd1;
	LSpush_knap(&knap,tmp);									//����ʼ���Ľڵ��ַѹ��ջ

label0:
	tmp = LSpop_knap(&knap);								//��ջ���鿴ջ��Ԫ�ط��������LSpop_knap����int�ͣ���ǿ��ת���ɵ�ַ��Ȼ��ȡֵ��
	if(tmp.s == 0)											//������ݹ��������
	{
		tmp.k = 1;											//�޸�ջ�������Ԫk,=1��ʾ�н�
		LSpush_knap(&knap,tmp);								//�ٴ�ѹջ
		goto label3;										//ת��ݹ���ڴ���
	}
	if(tmp.s<0 || (tmp.s>0 && tmp.n<1))
	{
		tmp.k = 0;											//�޸�ջ�������Ԫk,=0��ʾ�޽�
		LSpush_knap(&knap,tmp);								//ѹջ
		goto label3;
	}
	LSpush_knap(&knap,tmp);									//��δ����ݹ����

	x.s = tmp.s - w[tmp.n-1];								//���չ���1���д���
	x.n = tmp.n - 1;
	x.rd = rd2;												//����knap(s-w[n-1],n-1)��ϣ����ص������ú�����������
	LSpush_knap(&knap,x);									//ѹջ

	goto label0;
label1:														//����1��Ӧ�ķ��ش���
	x = LSpop_knap(&knap);									//��ջ���鿴ջ��Ԫ�ط��������LSpop_knap����int�ͣ���ǿ��ת���ɵ�ַ��Ȼ��ȡֵ��
	if(tmp.k == 1)											//��ĳ��Ľ����ԪΪ��
	{
		x.k = 1;											//�������ϴ������÷�
		LSpush_knap(&knap,x);								//ѹջ
		printf("%d ",w[(x.n)-1]);							//�����Ӧ��Ʒ
		goto label3;
	}
	LSpush_knap(&knap,x);									//ѹջ,��ĳ��Ľ����ԪΪ��
	
	tmp.s = x.s;											//��ǰ��Ʒ��ѡ�񲻺��ʣ����ݣ����ù���2
	tmp.n = x.n-1;											//���չ���2����ѹջ����
	tmp.rd = rd3;					
	LSpush_knap(&knap,tmp);									//ѹջ

	goto label0;
label2:														//����2��Ӧ�ķ��ش���
	x = LSpop_knap(&knap);									//��ջ���鿴ջ��Ԫ�ط��������LSpop_knap����int�ͣ���ǿ��ת���ɵ�ַ��Ȼ��ȡֵ��
	x.k = tmp.k;											//�����Ԫk�������ϴ������÷�
	LSpush_knap(&knap,x);									//ѹջ
label3:														//�ݹ���ڴ���
	tmp = LSpop_knap(&knap);								//��ջ���鿴ջ��Ԫ�ط��������LSpop_knap����int�ͣ���ǿ��ת���ɵ�ַ��Ȼ��ȡֵ��
	switch(tmp.rd)
	{
		case rd1:return tmp.k;								//�㷨���������ؽ��
		case rd2:goto label1;								//ת�����1�ķ��ش���
		case rd3:goto label2;								//ת�����2�ķ��ش���
	}
}

//�Ż��ǵݹ鷽����ʹ��ջ
//����1����w[n-1]�����ڽ��У����knap(s-w[n-1],n-1)
//����2����w[n-1]�������ڽ��У����knap(s,n-1)
unsigned char nonRecknapOpt(int s,int n, int* w)
{
	int t,n0 = n;
	unsigned char k = 0;									//�������ʼ��Ϊ0����ʾ����
	KnapNode tmp,x;											//��ʱ����

	LinkStack_knap knap;									//��ʽջ����
	CreateLinkStack_knap(&knap);							//������ʽջ
	tmp.s = s;
	tmp.rd = rd1;
	LSpush_knap(&knap,tmp);									//����ʼ���Ľڵ��ַѹ��ջ

	while(!isEmpty_knap(&knap))
	{
		t = knap.size;										//��ȡջ�Ĵ�С
		LStop_knap(&knap,&tmp);								//��ȡջ��Ԫ�أ���������
		
		while(tmp.s>=0 && (tmp.s<=0 || n0>=t))				//����ȡջ��Ԫ�سɹ����ж��Ƿ���ϳ�������
		{
			if(tmp.s == 0)									//�ﵽ��������
			{
				k = 1;									
				break;
			}
			else											//δ�ﵽ��������
			{
				x.s = tmp.s - w[n0-t];
				x.rd = rd2;
				LSpush_knap(&knap,x);					
			}
			t = knap.size;
			LStop_knap(&knap,&tmp);
		}
		
		while(!isEmpty_knap(&knap))							//���ش���
		{
			tmp = LSpop_knap(&knap);						//����ջ��Ԫ��
			t = knap.size;
			if(tmp.rd == rd1)								//�㷨����
				return k;
			if(tmp.rd == rd2)								//�ӹ���1����
			{
				if(1 == k)									//���Ϊ�棬��ӡ��Ӧ��Ʒ
					printf("%d ",w[n0-t]);
				else										//������ݣ����ù���2��ջ
				{
					LStop_knap(&knap,&x);
					tmp.s = x.s;
					tmp.rd = rd3;
					LSpush_knap(&knap,tmp);
					break;
				}
			}
		}
	}
}

void testStack()
{
	stack data;
	
	CreateStack(&data,10);
	push(&data,10);
	push(&data,20);
	while(data.top > -1)
		printf("data->[%d] = %d\r\n",data.top,pop(&data));	
}

void testLinkStack()
{
	LinkStack linkstack;

	CreateLinkStack(&linkstack);
	LSpush(&linkstack,100);
	LSpush(&linkstack,200);
	LSpush(&linkstack,300);
	printf("%d\r\n",LSpop(&linkstack));
	//printf("%d\r\n",LSpop(&linkstack));
	//printf("%d\r\n",LSpop(&linkstack));
	//printf("%d\r\n",LSpop(&linkstack));
	//printf("%d\r\n",LSpop(&linkstack));
	LSclear(&linkstack);
	printf("%d\r\n",LSpop(&linkstack));
}
void testRecursion()
{
	long n=6;//��׳���
	int w[4] = {8,7,1,9};//�󱳰�������
	printf("%ld�Ľ׳ˣ�%ld\r\n",n,factorial_recursion(n));
	printf("%ld�Ľ׳ˣ�%ld\r\n",n,factorial_iteration(n));

	printf("�ݹ鷽���� ");
	if(knap_recursion(15,4,w))
		printf("�˱��������н�\r\n");
	else
		printf("�˱��������޽�\r\n");

	printf("�ǵݹ鷽����");
	if(nonRecKnap(15,4,w))
		printf("�˱��������н�\r\n");
	else
		printf("�˱��������޽�\r\n");

	printf("�Ż��ķǵݹ鷽����");
	if(nonRecknapOpt(15,4,w))
		printf("�˱��������н�\r\n");
	else
		printf("�˱��������޽�\r\n");
}