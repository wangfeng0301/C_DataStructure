/************************************************************************
 *双向链表包括：创建链表、遍历链表、插入节点、修改某节点值、
 *				删除整个链表、删除某个节点
 *双向循环链表包括：创建链表、遍历链表、插入节点、修改某节点值、
 *				删除整个链表、删除某个节点
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *2019.11.29-2020.12.8
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist_double.h"

/************************************************************************
 *功能：创建链表
 *输入：n 链表节点个数，不包含首节点
 *输出：无
 *返回：链表首地址
************************************************************************/
DoubleLinkNode *Double_CreatLinkList(unsigned int n)
{
	unsigned int i=0;
	DoubleLinkNode *pHead,*pTail,*pNode;//定义首节点、尾节点、普通节点

	pHead = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));//为首节点开辟空间，首节点没有数据
	if(pHead == NULL)
	{
		printf("首节点空间分配失败！\r\n");
		return;
	}
	pHead->pre = NULL;//首节点前驱指向空
	pTail = pHead;//尾节点指向首节点
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//新开辟空间给新节点
		if(pNode == NULL)
		{
			printf("新节点%d空间分配失败！\r\n",i);
			return;
		}
		printf("请输入节点%d数据：",i);
		scanf("%d",&(pNode->Element));
		pTail->next = pNode;//新建节点的前一个节点后继指向自己
		pNode->pre = pTail;//新建节点前驱指向前一个节点
		pTail = pNode;//新节点赋值给尾节点，尾节点就变成了当前新建的节点
	}
	pTail->next = NULL;//尾节点后继指向空，创建结束

	return pHead;
}

/************************************************************************
 *功能：遍历节点
 *输入：list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void Double_TraverseList(DoubleLinkNode *list)
{
	unsigned int i=0;
	DoubleLinkNode *temp;//临时节点

	temp = list->next;//首节点没有数据，所以临时节点指向第一个普通节点
	if(temp == NULL)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(temp != NULL)
	{
		printf("节点%d元素：%d\r\n",i,temp->Element);
		temp = temp->next;//指向下一个节点
		i++;
	}
}

/************************************************************************
 *功能：修改节点n的值
 *输入：n:第n个节点,n从0开始算。只算普通节点
 *		list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void Double_ChangeNodeValue(DoubleLinkNode * list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp;//临时节点

	temp = list->next;//指向第一个有数据节点
	if(temp == NULL)
	{
		printf("链表为空！\r\n");
		return;
	}	
	while(temp!=NULL && i--)
	{
		temp = temp->next;//指向下一个节点，直到到指定节点
	}
	if(temp!=NULL)
	{	
		printf("节点%d修改为：",n);
		scanf("%d",&(temp->Element));
	}
	else
	{
		printf("节点不存在！\r\n");
	}
}
/************************************************************************
 *功能：在第n个节点前插入节点，节点从0开始算，只算普通节点
 *输入：n:第n个节点
 *输出：无
 *返回：无
************************************************************************/
void Double_InsertNode(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode *temp,*pNewNode;//临时节点

	temp = list;//临时节点指向首节点
	printf("在节点%d前插入新节点\r\n",n);
	if(temp->next == NULL)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(temp!=NULL && i--)
	{
		temp = temp->next;//指向下一个节点，直到指向指定节点
	}
	if(temp != NULL)//注意现在temp是指定节点的前一个节点
	{
		pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//为新节点分配内存
		if(pNewNode == NULL)
		{
			printf("新节点空间分配失败！\r\n");
			return;
		}
		printf("请输入新节点数据：");
		scanf("%d",&pNewNode->Element);
		pNewNode->next = temp->next;//新节点后继
		temp->next = pNewNode;//前一个节点后继为新节点
		pNewNode->pre = temp;//新节点前驱为前一个节点
		if(pNewNode->next != NULL)//新节点后继不是NULL，表示新节点不是尾节点，否则不执行下面操作
		{
			temp = pNewNode->next;//临时节点指向新节点的后继
			temp->pre = pNewNode;//后一个节点前驱指向新节点
		}	
	}
	else
	{
		printf("该节点不存在！\r\n");
	}
}
/************************************************************************
 *功能：删除第n个节点，n从0开始算，只算普通节点
 *输入：list:链表地址
		n:第n个节点,从0开始算
 *输出：无
 *返回：无
************************************************************************/
void Double_DeleteNote(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp,*pDeleteNode;//临时节点

	temp = list;//临时节点指向首节点
	printf("删除节点%d\r\n",n);
	if(temp->next == NULL)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(temp!=NULL && i--)
	{
		temp = temp->next;//指向下一个节点，直到指向指定节点
	}
	if(temp->next!=NULL)//注意现在temp是指定节点的前一个节点,不能删除首节点
	{
		pDeleteNode = temp->next;//temp后继是要删除的节点
		temp->next = pDeleteNode->next;//前一个节点后继		
		if(pDeleteNode->next != NULL)//后一个节点不是NULL，表示后一个节点不是尾节点，否则不执行下面操作
		{
			temp = pDeleteNode->next;//临时节点赋值为要删除节点的后一个节点
			temp->pre = pDeleteNode->pre;//后一个节点前驱
		}	
		free(pDeleteNode);//释放内存
		pDeleteNode = NULL;
	}
	else
	{
		printf("节点不存在！\r\n");
	}
}
/************************************************************************
 *功能：删除整个链表，保留链表头
 *输入：list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void Double_DeleteLinkList(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*p;//临时节点

	temp = list->next;//临时节点指向首节点
	list->next = NULL;//首节点指向空
	if(temp == NULL)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(temp!=NULL)
	{
		p = temp->next;//当前节点后继赋值给p
		free(temp);//释放当前节点内存
		temp = p;
	}
	if(temp==NULL)
	{
		free(p);//释放临时变量
		p = NULL;
		printf("删除链表成功！\r\n");
	}
}

/***************************************循环链表***********************************************************/

/************************************************************************
 *功能：创建链表
 *输入：n 链表节点个数，不包含首节点
 *输出：无
 *返回：链表首地址
************************************************************************/
DoubleLinkNode *CycDouble_CreatLinkList(unsigned int n)
{
	unsigned int i=0;
	DoubleLinkNode *pHead,*pTail,*pNode;//定义首节点、尾节点、普通节点

	pHead = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode));//为首节点开辟空间，首节点没有数据
	if(pHead == NULL)
	{
		printf("首节点空间分配失败！\r\n");
		return;
	}
	pTail = pHead;//尾节点指向首节点
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//新开辟空间给新节点
		if(pNode == NULL)
		{
			printf("新节点%d空间分配失败！\r\n",i);
			return;
		}
		printf("请输入节点%d数据：",i);
		scanf("%d",&(pNode->Element));
		pTail->next = pNode;//新建节点的前一个节点后继指向自己
		pNode->pre = pTail;//新建节点前驱指向前一个节点
		pTail = pNode;//新节点赋值给尾节点，尾节点就变成了当前新建的节点
	}
	pHead->pre = pTail;//首节点前驱指向尾节点
	pTail->next = pHead;//尾节点后继指向首节点，创建结束

	return pHead;
}

/************************************************************************
 *功能：遍历节点
 *输入：list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void CycDouble_TraverseList(DoubleLinkNode *list)
{
	unsigned int i=0;
	DoubleLinkNode *temp;//临时节点

	temp = list->next;//首节点没有数据，所以临时节点指向第一个普通节点
	if(temp == list || temp == NULL)
	{
		printf("链表为空！\r\n");
		return 0;
	}
	while(temp != list)
	{
		printf("节点%d元素：%d\r\n",i,temp->Element);
		temp = temp->next;//指向下一个节点
		i++;
	}
}

/************************************************************************
 *功能：修改节点n的值
 *输入：n:第n个节点,n从0开始算。只算普通节点
 *		list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void CycDouble_ChangeNodeValue(DoubleLinkNode * list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp;//临时节点

	temp = list->next;//指向第一个有数据节点
	if(temp == list)
	{
		printf("链表为空！\r\n");
		return;
	}	
	while( i--)//循环链表，可以循环查询。如链表长度为3，输入4，指定到节点0
	{
		temp = temp->next;//指向下一个节点，直到到指定节点
		if(temp == list)//循环到表尾，从头开始计数
		{
			temp = temp->next;
		}
	}
	if(temp!=list)
	{	
		printf("节点%d修改为：",n);
		scanf("%d",&(temp->Element));
	}
	else
	{
		printf("节点不存在！\r\n");
	}
}
/************************************************************************
 *功能：在第n个节点前插入节点，节点从0开始算，只算普通节点
 *输入：n:第n个节点
 *输出：无
 *返回：无
************************************************************************/
void CycDouble_InsertNode(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode *temp,*pNewNode;//临时节点

	temp = list;//临时节点指向首节点
	printf("在节点%d之前插入新节点\r\n",n);
	if(temp->next == list)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(i--)//循环链表，可以循环查询。如链表长度为3，输入4，指定到节点0
	{
		temp = temp->next;//指向下一个节点，直到指向指定节点
		if(temp == list)//循环到表尾，从头开始计数
		{
			temp = temp->next;
		}
	}
	if(temp != list)//注意现在temp是指定节点的前一个节点
	{
		pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//为新节点分配内存
		if(pNewNode == NULL)
		{
			printf("新节点空间分配失败！\r\n");
			return;
		}
		printf("请输入新节点数据：");
		scanf("%d",&pNewNode->Element);
		pNewNode->next = temp->next;//新节点后继
		temp->next = pNewNode;//前一个节点后继为新节点
		pNewNode->pre = temp;//新节点前驱为前一个节点
		temp = pNewNode->next;//临时节点指向新节点的后继
		temp->pre = pNewNode;//后一个节点前驱指向新节点
	}
	else
	{
		printf("该节点不存在！\r\n");
	}
}
/************************************************************************
 *功能：在表尾增加节点,链表为空不能直接返回
 *输入：list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void CycDouble_AddNode(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*pNewNode;//临时节点

	temp = list;//临时节点指向首节点	
	printf("在表尾插入新节点\r\n");

	pNewNode = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));//为新节点分配内存
	if(pNewNode == NULL)
	{
		printf("新节点空间分配失败！\r\n");
		return;
	}
	printf("请输入新节点数据：");
	scanf("%d",&pNewNode->Element);
	pNewNode->next = temp;//新节点后继指向首节点
	pNewNode->pre = temp->pre;//新节点前驱指向上一个尾节点
	temp->pre = pNewNode;//首节点前驱指向新节点
	pNewNode->pre->next = pNewNode;//新节点作为尾节点，其前驱的后继就是新节点本身
}
/************************************************************************
 *功能：删除第n个节点，n从0开始算，只算普通节点
 *输入：list:链表地址
		n:第n个节点,从0开始算
 *输出：无
 *返回：无
************************************************************************/
void CycDouble_DeleteNote(DoubleLinkNode *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode* temp,*pDeleteNode;//临时节点
	temp = list;//临时节点指向首节点
	printf("删除节点%d\r\n",n);
	if(temp->next == list)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(temp->next!=list && i--)
	{
		temp = temp->next;//指向下一个节点，直到指向指定节点
	}
	if(temp->next != list)//注意现在temp是指定节点的前一个节点,不能删除首节点
	{
		pDeleteNode = temp->next;//temp后继是要删除的节点
		temp->next = pDeleteNode->next;//前一个节点后继
		temp = pDeleteNode->next;//临时节点赋值为要删除节点的后一个节点
		temp->pre = pDeleteNode->pre;//后一个节点前驱
		free(pDeleteNode);//释放内存
		pDeleteNode = NULL;
	}
	else
	{
		printf("节点不存在！\r\n");
	}
}
/************************************************************************
 *功能：删除整个链表
 *输入：list:链表地址
 *输出：无
 *返回：无
************************************************************************/
void CycDouble_DeleteLinkList(DoubleLinkNode *list)
{
	DoubleLinkNode *temp,*p;//临时节点

	temp = list->next;//临时节点指向首节点后继
	if(temp == list)
	{
		printf("链表为空！\r\n");
		return;
	}
	while(temp!=list)
	{
		p = temp->next;//当前节点后继赋值给p
		free(temp);//释放当前节点内存
		temp = p;
	}
	/*保留头指针则屏蔽此段代码,特别注意这里的释放内存！需要销毁整个链表时，启动此代码，并屏蔽掉最后两行代码
	 *且销毁整个代码后，不能再遍历链表，否则会出现内存错误。注意这里与非循环双链表的区别，非循环双链表中首节点指向NULL，
	 *判断为 temp==NULL ,所以后续释放p内存并不是释放首节点的内存，首节点还是保留的，在内存中有一席之地；
	 *但是这里的判断为 temp==list ，即释放p就是释放首节点的内存，首节点就不存在了，故后续如果用遍历函数就会出现内存错误。
	 */
	if(temp==list)
	{
	//	free(p);//
	//	p = NULL;
		printf("删除链表成功！\r\n");
	}
	list->next = list;//首节点后继指向自身
	list->pre = list;//首节点前驱指向自身
}

void testDoubleLink(void)
{
	DoubleLinkNode *teacher = Double_CreatLinkList(4);//创建4个节点的链表,不包括首节点
	
	Double_TraverseList(teacher);		//遍历链表
	Double_InsertNode(teacher,4);		//在第n个节点前插入新节点
	Double_TraverseList(teacher);		//遍历链表
	Double_ChangeNodeValue(teacher,0);	//修改第3个节点的值
	Double_TraverseList(teacher);		//遍历链表
	Double_DeleteNote(teacher,4);		//删除节点
	Double_TraverseList(teacher);		//遍历链表
	Double_DeleteLinkList(teacher);		//删除链表
	Double_TraverseList(teacher);		//遍历链表
	
}
void testCycDoubleLink(void)
{
	DoubleLinkNode *people = CycDouble_CreatLinkList(10);

	CycDouble_TraverseList(people);		//遍历链表
	CycDouble_InsertNode(people,4);		//在第n个节点前插入新节点
	CycDouble_TraverseList(people);		//遍历链表
	CycDouble_ChangeNodeValue(people,10);//修改第3个节点的值
	CycDouble_TraverseList(people);		//遍历链表
	CycDouble_AddNode(people);		//在链尾插入新节点
	CycDouble_AddNode(people);		//在链尾插入新节点
	CycDouble_TraverseList(people);		//遍历链表
	CycDouble_DeleteNote(people,12);	//删除节点
	CycDouble_TraverseList(people);		//遍历链表
	CycDouble_DeleteNote(people,12);	//删除节点
	CycDouble_TraverseList(people);		//遍历链表
	CycDouble_DeleteLinkList(people);	//删除链表
	CycDouble_TraverseList(people);		//遍历链表
}