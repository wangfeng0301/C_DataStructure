#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "application.h"
#include "linkedlist_single.h"
#include "linkedlist_double.h"

/************************************************************************
 *问题描述：Josephus问题（约瑟夫环）：n人围一桌，从第s人开始报数，数到第m人出列
 *			从出列下一个人重新开始报数，数到第m人出列，以此类推，依次列出出列的人
 *使用思路：循环双向链表
 *输入：n:总人数
 *		s:从第s人开始报数
 *		m:数到第m人出列
 *输出：无
 *返回：无
************************************************************************/
void josephus(unsigned int n,unsigned int s,unsigned int m)
{
	unsigned int i=0,j=0;
	DoubleLinkNode *person = CycDouble_CreatLinkList(0);//定义一个循环链表，0个有效节点
	DoubleLinkNode *temp = person;//临时节点变量,赋值为首节点
	DoubleLinkNode *p;//存放删除前节点地址
	
	if(n<1)
	{		
		printf("总人数必须大于1！\r\n");
		return;
	}
	if(s>n || s<1)
	{
		printf("开始人数必须小于等于总人数且大于0！\r\n");
		return;
	}
	if(m<1)
	{
		printf("所报数m必须大于0！\r\n");
		return;
	}
	
	for(i=0;i<n;i++)//表尾添加n个节点，表示n个人
		CycDouble_AddNode(person);
	CycDouble_TraverseList(person);//遍历人数及每人编号

	while(s--)//定位到第s人
	{
		temp = temp->next;
	}
	printf("\r\n开始报数人编号：%d\r\n",temp->Element);

	for(j=0;j<n;j++)//输出被淘汰人员编号
	{
		for(i=0;i<m-1;i++)//开始报数，即从开始位置加1，直到加到m
		{
			temp = temp->next;
			if(temp == person)//指到首节点，自动向下
				temp = temp->next;
		}
		p = temp->next;//下一个节点保存到p中
		if(p == person)//指到首节点，自动向下
			p = p->next;
		if(p == person)
		{
			printf("计算完毕\r\n");
			return;
		}
		printf("淘汰第%d人编号:%d\r\n",j+1,temp->Element);//输出当前节点编号
		
		/*删除当前节点*/
		temp->pre->next = temp->next;//被删除节点的前驱的后继指向被删除节点的后继
		temp->next->pre = temp->pre;//被删除节点的后继的前驱指向被删除节点的前驱
		free(temp);//释放被删除节点内存
		
		temp = p;//临时节点指向下一个节点
	}
	printf("\r\n遍历人数及编号\r\n");
	CycDouble_TraverseList(person);//遍历人数及每人编号

	printf("\r\n删除链表\r\n");
	CycDouble_DeleteLinkList(person);

	printf("\r\n删除链表后遍历人数及编号\r\n");
	CycDouble_TraverseList(person);//遍历人数及每人编号
}

/***************************递归算法*************************************/

/*n的阶乘：递归方式*/
long factorial_recursion(long n)
{
	if(n<=1)
		return 1;
	else
		return n*factorial_recursion(n-1);
}
/*n的阶乘：迭代方式*/
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
		printf("输入参数应该大于等于0！\r\n");
		return 0;
	}
	return m;
}

/****************************************************************************/
/*背包问题
*假设一个背包可放入重量为s，现有n件物品，重量分别为w0,w1,...wn-1
*问能否从这n件物品中选择若干放入背包，是重量之和正好为s？*/
/*
						/	true,   当s=0
knap_recursion(s,n)=   |	false,  当s<0或（s>0且n<1）
						\	knap_recursion(s-wn-1,n-1,w)||knap_recursion(s,n-1,w),当s>0且n>=1
/****************************************************************************/
//递归方法
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

//非递归方法，使用栈
//规则1：若w[n-1]包含在解中，求解knap(s-w[n-1],n-1)
//规则2：若w[n-1]不包含在解中，求解knap(s,n-1)
typedef enum //返回地址类型
{
	rd1=0,			//第一种情况，计算knap(s,n)完毕返回到调用本函数的其他函数
	rd2,			//第二种情况，计算knap(s-w[n-1],n-1)完毕，返回到本调用函数继续计算
	rd3				//第三种情况，计算knap(s,n-1)完毕，返回到本调用函数继续计算
}rdType;
typedef struct  
{
	int s,n;		//背包的承重亮和物品的数目
	rdType rd;		//返回地址
	unsigned char k;//结果单元
}KnapNode;

/*链表节点结构体*/
typedef struct LinkNode_knap
{
	KnapNode node;
	struct LinkNode_knap* next;
}LinkNode_knap;
/*链表结构体*/
typedef struct
{
	LinkNode_knap *top;	
	int size;
}LinkStack_knap;
/*创建栈,size:栈的大小*/
static void CreateLinkStack_knap(LinkStack_knap *s)
{
	s->size = 0;	//初始化为空栈
	s->top = NULL;	//指向空
}
/*压栈*/
static void LSpush_knap(LinkStack_knap *s,KnapNode node)//向链首插入节点，作为后入节点
{
	LinkNode_knap *temp = (LinkNode_knap *)malloc(sizeof(LinkNode_knap));//开辟空间,大小为LinkNode_knap
	if(s->top == NULL)				//第一个压栈的元素
	{
		s->top = temp;				//栈顶指向当前空间
		s->top->next = NULL;
	}
	else
	{
		temp->next = s->top;		//新建节点指向之前的节点，相当于在之前节点插入了新节点
		s->top = temp;
	}
	s->top->node.k = node.k;		//赋值
	s->top->node.n = node.n;
	s->top->node.rd = node.rd;
	s->top->node.s = node.s;
	s->size++;						//栈大小加1
}

/*出栈,返回栈内元素*/
static KnapNode LSpop_knap(LinkStack_knap *s)
{
	KnapNode temp;
	LinkNode_knap *tempNode;		//临时节点
	if(s->top != NULL)				//栈非空
	{
		temp.k = s->top->node.k;	//提取元素
		temp.n = s->top->node.n;
		temp.rd = s->top->node.rd;
		temp.s = s->top->node.s;
		tempNode = s->top;			//当前节点给临时节点
		s->top = s->top->next;		//指向下一个节点
		free(tempNode);
		tempNode = NULL;
		s->size--;					//栈大小减1

		return temp;
	}
	else
	{
		printf("栈空\r\n");
		return;
	}
}
/*判空*/
static unsigned char isEmpty_knap(LinkStack_knap *s)
{
	if(s->top != NULL)				//栈非空返回0
	{
		return 0;
	}
	else
	{
		printf("栈空\r\n");			//栈空返回1
		return 1;
	}
}
/*返回栈顶内容，但不弹出*/
static unsigned char LStop_knap(LinkStack_knap *s,KnapNode *node)
{
	if(s->size == 0)
	{
		printf("栈为空，不能读出栈顶元素\r\n");
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
/*非递归方法函数实现*/
unsigned char nonRecKnap(int s,int n,int* w)
{				
	//KnapNode *tmp = (KnapNode *)malloc(sizeof(KnapNode));	//开辟新空间
	//KnapNode *x = (KnapNode *)malloc(sizeof(KnapNode));		//开辟新空间//缓冲变量
	KnapNode tmp,x;
	LinkStack_knap knap;									//链式栈变量

	CreateLinkStack_knap(&knap);							//创建链式栈

	tmp.s = s;												//非递归函数入口,初始化
	tmp.n = n;
	tmp.rd = rd1;
	LSpush_knap(&knap,tmp);									//将初始化的节点地址压入栈

label0:
	tmp = LSpop_knap(&knap);								//出栈，查看栈顶元素分情况处理。LSpop_knap返回int型，需强制转换成地址，然后取值。
	if(tmp.s == 0)											//若满足递归出口条件
	{
		tmp.k = 1;											//修改栈顶结果单元k,=1表示有解
		LSpush_knap(&knap,tmp);								//再次压栈
		goto label3;										//转向递归出口处理
	}
	if(tmp.s<0 || (tmp.s>0 && tmp.n<1))
	{
		tmp.k = 0;											//修改栈顶结果单元k,=0表示无解
		LSpush_knap(&knap,tmp);								//压栈
		goto label3;
	}
	LSpush_knap(&knap,tmp);									//尚未满足递归出口

	x.s = tmp.s - w[tmp.n-1];								//按照规则1进行处理
	x.n = tmp.n - 1;
	x.rd = rd2;												//计算knap(s-w[n-1],n-1)完毕，返回到本调用函数继续计算
	LSpush_knap(&knap,x);									//压栈

	goto label0;
label1:														//规则1对应的返回处理
	x = LSpop_knap(&knap);									//出栈，查看栈顶元素分情况处理。LSpop_knap返回int型，需强制转换成地址，然后取值。
	if(tmp.k == 1)											//若某层的结果单元为真
	{
		x.k = 1;											//把真结果上传给调用方
		LSpush_knap(&knap,x);								//压栈
		printf("%d ",w[(x.n)-1]);							//输出对应物品
		goto label3;
	}
	LSpush_knap(&knap,x);									//压栈,若某层的结果单元为假
	
	tmp.s = x.s;											//当前物品的选择不合适，回溯，调用规则2
	tmp.n = x.n-1;											//按照规则2进行压栈处理
	tmp.rd = rd3;					
	LSpush_knap(&knap,tmp);									//压栈

	goto label0;
label2:														//规则2对应的返回处理
	x = LSpop_knap(&knap);									//出栈，查看栈顶元素分情况处理。LSpop_knap返回int型，需强制转换成地址，然后取值。
	x.k = tmp.k;											//结果单元k的内容上传给调用方
	LSpush_knap(&knap,x);									//压栈
label3:														//递归出口处理
	tmp = LSpop_knap(&knap);								//出栈，查看栈顶元素分情况处理。LSpop_knap返回int型，需强制转换成地址，然后取值。
	switch(tmp.rd)
	{
		case rd1:return tmp.k;								//算法结束并返回结果
		case rd2:goto label1;								//转向规则1的返回处理处
		case rd3:goto label2;								//转向规则2的返回处理处
	}
}

//优化非递归方法，使用栈
//规则1：若w[n-1]包含在解中，求解knap(s-w[n-1],n-1)
//规则2：若w[n-1]不包含在解中，求解knap(s,n-1)
unsigned char nonRecknapOpt(int s,int n, int* w)
{
	int t,n0 = n;
	unsigned char k = 0;									//结果，初始化为0，表示错误
	KnapNode tmp,x;											//临时变量

	LinkStack_knap knap;									//链式栈变量
	CreateLinkStack_knap(&knap);							//创建链式栈
	tmp.s = s;
	tmp.rd = rd1;
	LSpush_knap(&knap,tmp);									//将初始化的节点地址压入栈

	while(!isEmpty_knap(&knap))
	{
		t = knap.size;										//获取栈的大小
		LStop_knap(&knap,&tmp);								//获取栈顶元素，但不弹出
		
		while(tmp.s>=0 && (tmp.s<=0 || n0>=t))				//若获取栈顶元素成功，判断是否符合出口条件
		{
			if(tmp.s == 0)									//达到出口条件
			{
				k = 1;									
				break;
			}
			else											//未达到出口条件
			{
				x.s = tmp.s - w[n0-t];
				x.rd = rd2;
				LSpush_knap(&knap,x);					
			}
			t = knap.size;
			LStop_knap(&knap,&tmp);
		}
		
		while(!isEmpty_knap(&knap))							//返回处理
		{
			tmp = LSpop_knap(&knap);						//读出栈顶元素
			t = knap.size;
			if(tmp.rd == rd1)								//算法结束
				return k;
			if(tmp.rd == rd2)								//从规则1返回
			{
				if(1 == k)									//结果为真，打印对应物品
					printf("%d ",w[n0-t]);
				else										//否则回溯，采用规则2进栈
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
void testRecursion()
{
	long n=6;//求阶乘用
	int w[4] = {8,7,1,9};//求背包问题用
	printf("%ld的阶乘：%ld\r\n",n,factorial_recursion(n));
	printf("%ld的阶乘：%ld\r\n",n,factorial_iteration(n));

	printf("递归方法： ");
	if(knap_recursion(15,4,w))
		printf("此背包问题有解\r\n");
	else
		printf("此背包问题无解\r\n");

	printf("非递归方法：");
	if(nonRecKnap(15,4,w))
		printf("此背包问题有解\r\n");
	else
		printf("此背包问题无解\r\n");

	printf("优化的非递归方法：");
	if(nonRecknapOpt(15,4,w))
		printf("此背包问题有解\r\n");
	else
		printf("此背包问题无解\r\n");
}