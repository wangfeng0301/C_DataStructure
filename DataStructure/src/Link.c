/*单向链表包括：创建链表、遍历链表、插入节点、修改某节点值、删除整个链表、删除某个节点*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "link.h"

/*创建链表
*n 链表节点个数，不包含首节点
*/
LinkNode *CreatLinkList(int n)
{
	int i;
	LinkNode *pHead,*pNode,*pTail;//定义首结点，普通节点，尾节点
	pHead = (LinkNode *)malloc(sizeof(LinkNode));//为头结点分配内存空间，头结点不放数据，指向首节点（第一个节点）
	if(pHead == NULL)//判断是否分配内存成功
	{
		printf("空间分配失败");
		exit(-1);
	}
	pTail = pHead;//尾节点初始指向首结点

	for(i=0;i<n;i++)
	{
		pNode = (LinkNode*)malloc(sizeof(LinkNode));//为普通节点分配内存
		if(pNode == NULL)//判断是否分配内存成功
		{
			printf("空间分配失败");
			exit(-1);
		}
		printf("请输入第%d个节点数据：",i);
		scanf("%d",&(pNode->Element));//给节点元素赋值
		pTail->next = pNode;//尾节点指向新的节点，同时尾节点的前一个节点也指向了pNode
		pTail = pNode;//新节点赋值给尾节点,新节点就变成了尾节点
	}
	pTail->next = NULL;//尾节点指向NULL,结束创建

	return pHead;//返回头节点地址
}

/************************************************************************/
/*修改节点值
 *n:第n个节点,n从0开始算。只算普通节点
 *list:链表*/
/************************************************************************/
void ChangeNodeValue(LinkNode * list,int n)
{
	LinkNode *t = list->next;
	int i=0;
	while(i<n && t!=NULL)//找到第n个节点
	{
		t = t->next;
		i++;
	}
	if(t != NULL)
	{
		printf("输入要修改的值：");
		scanf("%d",&t->Element);
	}
	else
	{
		printf("节点不存在！");
	}
}

/************************************************************************/
/*节点遍历
 *list:链表*/
/************************************************************************/
void TraverseList(LinkNode *list)
{
	LinkNode *p = list->next;
	if(p == NULL)
	{
		printf("链表为空\r\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d\r\n",p->Element);//打印节点数据
		p = p->next;//指向下一个节点
	}
}

/************************************************************************/
/* 在第n个节点前插入节点，节点从0开始算，只算普通节点
 *n:第n个节点*/
/************************************************************************/
void InsertNode(LinkNode *list,int n)
{
	LinkNode *p = list;//定义LinkNode型指针指向首节点
	LinkNode *in;//新插入节点
	printf("在节点%d前插入新节点\r\n",n);
	while(p != NULL && n--)//定位到第n个节点，在此节点前插入新节点
	{
		p = p->next;//
	}
	if(p != NULL)
	{
		in = (LinkNode*)malloc(sizeof(LinkNode));//为新插入节点分配内存
		printf("请输入插入节点的数据：");
		scanf("%d",&in->Element);
		in->next = p->next;//插入节点指向下一个节点
		p->next = in;//源节点指向新插入节点
	}
	else
	{
		printf("节点不存在！\r\n");
	}
}

/************************************************************************/
/*删除第n个节点，n从0开始算，只算普通节点                                                                     */
/************************************************************************/
void DeleteNote(LinkNode *list,int n)
{
	LinkNode *p = list;//定义指针指向首节点
	LinkNode *temp;//临时变量
	printf("第%d个节点将被删除\r\n",n);
	while(p != NULL && n--)//移动到第n个节点，删除
	{
		p = p->next;
	}
	if(p != NULL)
	{
		temp = p->next;
		p->next = temp->next;
		free(temp);//释放临时变量
		temp = NULL;
	}
	else
	{
		printf("被删除节点不存在！\r\n");
	}
}

/************************************************************************/
/* 删除整个链表                                                         */
/************************************************************************/
void DeleteLinkList(LinkNode *list)
{
	LinkNode *p = list->next;//指向首节点后面一个节点
	LinkNode *temp;//临时变量
	list->next = NULL;//首节点指向空指针
	while(p != NULL)//每个节点挨个删除
	{
		temp = p->next;//临时变量指向下一个节点
		free(p);//释放当前节点内存
		p = temp;
	}
	if(p == NULL)
	{
		free(temp);//释放临时变量内存
		temp = NULL;
		printf("删除链表成功！\r\n");
	}
}

void testLink()
{
	LinkNode *student = CreatLinkList(3);//创建3个节点的链表,不包括首节点
	unsigned n=500,s=60,m=51;

	TraverseList(student);//遍历链表
	InsertNode(student,3);//在第n个节点前插入新节点
	TraverseList(student);//遍历链表
	ChangeNodeValue(student,0);//修改第3个节点的值
	TraverseList(student);//遍历链表
	//InsertNode(student,3);//在第n个节点前插入新节点
	//TraverseList(student);//遍历链表
	DeleteNote(student,0);//删除节点
	TraverseList(student);//遍历链表
	DeleteLinkList(student);//删除链表
	TraverseList(student);//遍历链表
}