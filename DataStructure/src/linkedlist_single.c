/************************************************************************
 *单向链表包括：创建链表、遍历链表、插入节点、修改某节点值、
 *				删除整个链表、删除某个节点
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.2
 *2020.12.7  增加链表翻转
 *2021.2.2   修改，数据类型不受限制
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist_single.h"

/************************************************************************
 *功能：创建链表，通用，不随数据类型改变而改变
 *输入：list:链表起始地址
 *		n：链表节点个数，不包含首节点
 *		dat:要传入的数据元素指针，若n=0,改参数可传NULL
 *		datlen:数据类型的长度
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Link_Create(LinkList_t *list, uint n, void *dat, uint datlen)
{
	uint i;
	LinkNode_t *pHead,*pNode,*pTail;						//定义首结点，普通节点，尾节点
	pHead = (LinkNode_t *)malloc(sizeof(LinkNode_t));		//为头结点分配内存空间，头结点不放数据，指向首节点（第一个节点）
	if(pHead == NULL)										//判断是否分配内存成功
	{
		printf("空间分配失败");
		return FALSE;
	}
	pTail = pHead;											//尾节点初始指向首结点

	for(i=0;i<n;i++)
	{
		pNode = (LinkNode_t *)malloc(sizeof(LinkNode_t));	//为普通节点分配节点结构体内存
		pNode->data = (void *)malloc(datlen);				//为普通节点分配数据内存
		if(pNode == NULL || pNode->data == NULL)			//判断是否分配内存成功
		{
			printf("新节点%d空间分配失败！\r\n",i);
			return FALSE;
		}
		memcpy(pNode->data, (void *)((uint)dat+i*datlen), datlen);//赋值
		//pNode->data = dat[i];
		pTail->next = pNode;								//尾节点指向新的节点，同时尾节点的前一个节点也指向了pNode
		pTail = pNode;										//新节点赋值给尾节点,新节点就变成了尾节点
	}
	pTail->next = NULL;										//尾节点指向NULL,结束创建
	list->datlen = datlen;									//指定数据类型长度
	list->node = pHead;										//指定首节点
	list->node->data = NULL;								//一定要初始化首节点数据区
	return TRUE;
}

/************************************************************************
 *功能：修改节点n的值
 *输入：n:第n个节点,n从0开始算。只算普通节点
 *		list:链表地址
 *		dat:修改后的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Link_ChangeNodeValue(LinkList_t * list,int n, void *dat)
{
	LinkNode_t *t = list->node->next;
	int i = 0;

	while(i < n && t != NULL)								//找到第n个节点
	{
		t = t->next;
		i++;
	}
	if(t != NULL)
	{
		printf("修改节点%d的值\r\n",n);
		//t->data = dat;
		memcpy(t->data,dat,list->datlen);
		return TRUE;
	}
	else
	{
		printf("节点不存在！");
		return FALSE;
	}
}

/************************************************************************
 *功能：遍历节点
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Link_Traverse(LinkList_t *list)
{
	LinkNode_t *p = list->node;
	uchar temp[32];

	printf("遍历链表：\r\n");
	if(p == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	p = p->next;
	if(p == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	while(p != NULL)
	{
		memcpy(temp,p->data,list->datlen);
		printf("%d\r\n",*temp);						//打印节点数据
		p = p->next;								//指向下一个节点
	}
	return TRUE;
}

/************************************************************************
 *功能：在第n个节点前插入节点，节点从0开始算，只算普通节点
 *输入：list:链表地址
 *		n:第n个节点
 *		dat:插入的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Link_InsertNode(LinkList_t *list, int n, void *dat)
{
	LinkNode_t *p = list->node;						//定义LinkNode_t型指针指向首节点
	LinkNode_t *in;									//新插入节点
	printf("在节点%d前插入新节点\r\n",n);
	while(p != NULL && n--)							//定位到第n个节点，在此节点前插入新节点
	{
		p = p->next;
	}
	if(p != NULL)
	{
		in = (LinkNode_t*)malloc(sizeof(LinkNode_t));//为新插入节点分配内存
		in->data = (void *)malloc(list->datlen);	//为普通节点分配数据内存
		if(in == NULL || in->data == NULL)
		{
			printf("空间分配失败\r\n");
			return FALSE;
		}
		//printf("请输入插入节点的数据：");
		//scanf("%d",&in->Element);
		//in->data = dat;
		memcpy(in->data,dat,list->datlen);
		in->next = p->next;							//插入节点指向下一个节点
		p->next = in;								//源节点指向新插入节点
		return TRUE;
	}
	else
	{
		printf("节点不存在！\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：删除第n个节点，n从0开始算，只算普通节点
 *输入：list:链表地址
		n:第n个节点,从0开始算
 *输出：无
 *返回：无
************************************************************************/
bool Link_DeleteNode(LinkList_t *list,int n)
{
	LinkNode_t *p = list->node;						//定义指针指向首节点
	LinkNode_t *temp;								//临时节点变量
	printf("第%d个节点将被删除\r\n",n);
	while(p != NULL && n--)							//移动到第n个节点，删除
	{
		p = p->next;
	}
	if(p != NULL)
	{
		temp = p->next;
		p->next = temp->next;
		free(temp->data);							//释放数据地址,注意释放的顺序不能换
		temp->data = NULL;
		free(temp);									//释放临时节点变量
		temp = NULL;
	}
	else
	{
		printf("被删除节点不存在！\r\n");
		return FALSE;
	}
	return TRUE;
}

/************************************************************************
 *功能：清空整个链表
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool Link_Clear(LinkList_t *list)
{
	LinkNode_t *p = list->node->next;				//指向第一个普通节点
	LinkNode_t *temp;								//临时节点变量
	list->node->next = NULL;						//首个普通节点指向空指针
	while(p != NULL)								//每个节点挨个删除
	{
		temp = p->next;								//临时变量指向下一个节点
		if(p->data != NULL)
			free(p->data);							//释放数据地址,注意释放的顺序不能换
		p->data = NULL;
		free(p);									//释放当前节点内存
		p = temp;
	}
	if(p == NULL)
	{
		printf("清空链表成功！\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *功能：销毁整个链表
 *输入：list:链表地址
 *输出：无
 *返回：无
************************************************************************/
bool Link_Destroy(LinkList_t *list)
{
	LinkNode_t *p = list->node;						//指向首节点
	LinkNode_t *temp;								//临时节点变量
	list->node = NULL;								//首节点指向空指针
	list->datlen = 0;								//链表数据长度清零
	while(p != NULL)								//每个节点挨个删除
	{
		temp = p->next;								//临时变量指向下一个节点
		if(p->data != NULL)
			free(p->data);							//释放数据地址,注意释放的顺序不能换
		p->data = NULL;
		free(p);									//释放当前节点内存
		p = temp;
	}
	if(p == NULL)
	{
		/*if(p->data != NULL)
			free(p->data);							//释放数据地址,注意释放的顺序不能换
		p->data = NULL;
		free(temp);									//释放临时变量内存
		temp = NULL;*/
		printf("销毁链表成功！\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *功能：翻转整个链表
 *输入：list:链表地址
 *输出：list:翻转后的链表
 *返回：无
************************************************************************/
bool Link_Reverse(LinkList_t *list)
{
	LinkNode_t *currNode;							//当前要插到head后面的node
	LinkNode_t *nextNode;							//相对于当前节点的下一个节点
	LinkNode_t *preNode;							//相对于当前节点的上一个节点
	LinkNode_t *headNode;							//头结点

	if(list->node->next == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	headNode = list->node;
	preNode = list->node->next;
	currNode = preNode->next;
	printf("翻转单项链表\r\n");
	while(preNode->next != NULL)
	{
		nextNode = currNode->next;					//保存next节点
		preNode->next = currNode->next;
		currNode->next = headNode->next;
		headNode->next = currNode;

		currNode = nextNode;
	}
	return TRUE;
}

void testLink(void)
{
	int age[3] = {10,11,12};
	int dat;
	LinkList_t student;//定义一个链表

	if(Link_Create(&student, 3, age, sizeof(age[0])))//创建3个节点的链表,不包括首节点
		Link_Traverse(&student);//遍历链表
	
	dat = 1;
	if(Link_InsertNode(&student,3,&dat))//在第n个节点前插入新节点
		Link_Traverse(&student);//遍历链表

	dat = 2;
	if(Link_ChangeNodeValue(&student,0,&dat))//修改第0个节点的值
		Link_Traverse(&student);//遍历链表

	dat = 3;
	if(Link_InsertNode(&student,3,&dat))//在第n个节点前插入新节点
		Link_Traverse(&student);//遍历链表

	if(Link_DeleteNode(&student,0))//删除节点
		Link_Traverse(&student);//遍历链表
	
	if(Link_Reverse(&student))//翻转链表
		Link_Traverse(&student);//遍历链表

	if(Link_Clear(&student))//翻转链表
		Link_Traverse(&student);//遍历链表
	
	if(Link_Destroy(&student))//删除链表
		Link_Traverse(&student);//遍历链表
}
