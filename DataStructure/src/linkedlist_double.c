/************************************************************************
 *双向链表包括：创建链表、遍历链表、插入节点、修改某节点值、
 *				删除整个链表、删除某个节点
 *双向循环链表包括：创建链表、遍历链表、插入节点、修改某节点值、
 *				删除整个链表、删除某个节点
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.2
 *2021.2.2  修改，数据类型不受限制
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist_double.h"

/************************************************************************
 *功能：创建链表
 *输入：list:链表起始地址
 *		n 链表节点个数，不包含首节点
 *		dat:要传入的数据元素指针，若n=0,改参数可传NULL
 *		datlen:数据类型的长度
 *输出：list:链表地址
 *返回：TRUE or FALSE
************************************************************************/
bool DoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen)
{
	unsigned int i=0;
	DoubleLinkNode_t *pHead,*pTail,*pNode;							//定义首节点、尾节点、普通节点

	pHead = (DoubleLinkNode_t *)malloc(sizeof(DoubleLinkNode_t));	//为首节点开辟空间，首节点没有数据
	if(pHead == NULL)
	{
		printf("首节点空间分配失败！\r\n");
		return FALSE;
	}
	pHead->pre = NULL;												//首节点前驱指向空
	pTail = pHead;													//尾节点指向首节点
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//新开辟空间给新节点
		pNode->data = (void *)malloc(datlen);						//为普通节点分配数据内存
		if(pNode == NULL || pNode->data == NULL)
		{
			printf("新节点%d空间分配失败！\r\n",i);
			return FALSE;
		}
		//pNode->data = dat[i];
		memcpy(pNode->data, (void *)((unsigned int)dat+i*datlen), datlen);	//赋值
		pTail->next = pNode;										//新建节点的前一个节点后继指向自己
		pNode->pre = pTail;											//新建节点前驱指向前一个节点
		pTail = pNode;												//新节点赋值给尾节点，尾节点就变成了当前新建的节点
	}
	pTail->next = NULL;												//尾节点后继指向空，创建结束
	list->datlen = datlen;											//指定数据类型长度
	list->node = pHead;												//指定首节点
	list->node->data = NULL;										//一定要初始化首节点数据区
	return TRUE;
}

/************************************************************************
 *功能：遍历节点
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool DoubleLink_Traverse(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *p = list->node;								//临时节点指向首节点
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
		printf("%d\r\n",*temp);										//打印节点数据
		p = p->next;												//指向下一个节点
	}
	return TRUE;
}

/************************************************************************
 *功能：修改节点n的值
 *输入：n:第n个节点,n从0开始算。只算普通节点
 *		list:链表地址
 *		dat:修改的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool DoubleLink_ChangeNodeValue(DoubleLinkList_t *list, unsigned int n, void *dat)
{
	unsigned int i = n;
	DoubleLinkNode_t* temp = list->node->next;						//临时节点指向第一个有数据节点

	if(temp == NULL)
	{
		printf("链表为空！\r\n");
		return FALSE;
	}	
	while(temp != NULL && i--)
	{
		temp = temp->next;											//指向下一个节点，直到到指定节点
	}
	if(temp!=NULL)
	{	
		printf("修改节点%d\r\n",n);
		//temp->data = dat;
		memcpy(temp->data,dat,list->datlen);
		return TRUE;
	}
	else
	{
		printf("节点不存在！\r\n");
		return FALSE;
	}
}
/************************************************************************
 *功能：在第n个节点前插入节点，节点从0开始算，只算普通节点
 *输入：lsit:链表地址
 *		n:第n个节点
 *		dat:插入的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool DoubleLink_InsertNode(DoubleLinkList_t *list, unsigned int n, void *dat)
{
	unsigned int i=n;
	DoubleLinkNode_t *temp,*pNewNode;								//临时节点

	temp = list->node;												//临时节点指向首节点
	printf("在节点%d前插入新节点\r\n",n);
	while(temp != NULL && i--)
	{
		temp = temp->next;											//指向下一个节点，直到指向指定节点
	}
	if(temp != NULL)												//注意现在temp是指定节点的前一个节点
	{
		pNewNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//为新节点分配内存
		pNewNode->data = (void *)malloc(list->datlen);				//为普通节点分配数据内存
		if(pNewNode == NULL)
		{
			printf("新节点空间分配失败！\r\n");
			return FALSE;
		}
		//pNewNode->data = dat;
		memcpy(pNewNode->data,dat,list->datlen);
		pNewNode->next = temp->next;								//新节点后继
		temp->next = pNewNode;										//前一个节点后继为新节点
		pNewNode->pre = temp;										//新节点前驱为前一个节点
		if(pNewNode->next != NULL)									//新节点后继不是NULL，表示新节点不是尾节点，否则不执行下面操作
		{
			temp = pNewNode->next;									//临时节点指向新节点的后继
			temp->pre = pNewNode;									//后一个节点前驱指向新节点
		}
		return TRUE;
	}
	else
	{
		printf("该节点不存在！\r\n");
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
bool DoubleLink_DeleteNode(DoubleLinkList_t *list, unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode_t* temp,*pDeleteNode;							//临时节点

	temp = list->node;												//临时节点指向首节点
	printf("删除节点%d\r\n",n);
	if(temp->next == NULL)
	{
		printf("链表为空！\r\n");
		return FALSE;
	}
	while(temp!=NULL && i--)
	{
		temp = temp->next;											//指向下一个节点，直到指向指定节点
	}
	if(temp->next!=NULL)											//注意现在temp是指定节点的前一个节点,不能删除首节点
	{
		pDeleteNode = temp->next;									//temp后继是要删除的节点
		temp->next = pDeleteNode->next;								//前一个节点后继		
		if(pDeleteNode->next != NULL)								//后一个节点不是NULL，表示后一个节点不是尾节点，否则不执行下面操作
		{
			temp = pDeleteNode->next;								//临时节点赋值为要删除节点的后一个节点
			temp->pre = pDeleteNode->pre;							//后一个节点前驱
		}	
		free(pDeleteNode->data);									//释放数据地址,注意释放的顺序不能换
		pDeleteNode->data = NULL;
		free(pDeleteNode);											//释放内存
		pDeleteNode = NULL;
		return TRUE;
	}
	else
	{
		printf("节点不存在！\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：清除整个链表，保留链表头
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool DoubleLink_Clear(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//临时节点

	temp = list->node->next;										//临时节点指向首节点
	list->node->next = NULL;										//首节点指向空指针
	if(temp == NULL)
	{
		printf("链表为空！\r\n");
		return FALSE;
	}
	while(temp != NULL)
	{
		p = temp->next;												//当前节点后继赋值给p
		if(temp->data != NULL)
			free(temp->data);										//释放数据地址,注意释放的顺序不能换
		temp->data = NULL;
		free(temp);													//释放当前节点内存
		temp = p;
	}
	if(temp==NULL)
	{
		//free(p);													//释放临时变量
		//p = NULL;
		printf("清除链表成功！\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *功能：销毁整个链表，不保留链表头
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool DoubleLink_Destroy(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//临时节点

	temp = list->node;												//临时节点指向首节点
	list->datlen = 0;												//链表数据长度清零
	list->node = NULL;												//首节点指向空指针
	if(temp == NULL)
	{
		printf("链表为空！\r\n");
		return FALSE;
	}
	while(temp != NULL)
	{
		p = temp->next;												//当前节点后继赋值给p
		if(temp->data != NULL)
			free(temp->data);										//释放数据地址,注意释放的顺序不能换
		temp->data = NULL;
		free(temp);													//释放当前节点内存
		temp = p;
	}
	if(temp==NULL)
	{
		//free(p);													//释放临时变量
		//p = NULL;
		printf("销毁链表成功！\r\n");
		return TRUE;
	}
	return FALSE;
}

/***************************************循环链表***********************************************************/

/************************************************************************
 *功能：创建链表
 *输入：list:链表地址
 *		n: 链表节点个数，不包含首节点
 *		dat:要传入的数据元素指针，若n=0,改参数可传NULL
 *输出：list:链表地址
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Create(DoubleLinkList_t *list, unsigned int n, void *dat, unsigned int datlen)
{
	unsigned int i=0;
	DoubleLinkNode_t *pHead,*pTail,*pNode;							//定义首节点、尾节点、普通节点

	pHead = (DoubleLinkNode_t *)malloc(sizeof(DoubleLinkNode_t));	//为首节点开辟空间，首节点没有数据
	if(pHead == NULL)
	{
		printf("首节点空间分配失败！\r\n");
		return FALSE;
	}
	pTail = pHead;//尾节点指向首节点
	for(i=0;i<n;i++)
	{
		pNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//新开辟空间给新节点
		pNode->data = (void *)malloc(datlen);						//为普通节点分配数据内存
		if(pNode == NULL || pNode->data == NULL)
		{
			printf("新节点%d空间分配失败！\r\n",i);
			return FALSE;
		}
		//pNode->data = dat[i];
		memcpy(pNode->data, (void *)((unsigned int)dat+i*datlen), datlen);//赋值
		pTail->next = pNode;										//新建节点的前一个节点后继指向自己
		pNode->pre = pTail;											//新建节点前驱指向前一个节点
		pTail = pNode;												//新节点赋值给尾节点，尾节点就变成了当前新建的节点
	}
	pHead->pre = pTail;												//首节点前驱指向尾节点
	pTail->next = pHead;											//尾节点后继指向首节点，创建结束
	list->datlen = datlen;											//指定数据类型长度
	list->node = pHead;												//指定首节点
	list->node->data = NULL;										//一定要初始化首节点数据区
	return TRUE;
}

/************************************************************************
 *功能：遍历节点
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Traverse(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *p;				
	uchar temp[32];

	printf("遍历链表：\r\n");
	if(list->node == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	p = list->node->next;											//首节点没有数据，所以临时节点指向第一个普通节点
	if(p == list->node || p == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	while(p != list->node)
	{
		memcpy(temp,p->data,list->datlen);
		printf("%d\r\n",*temp);										//打印节点数据
		p = p->next;												//指向下一个节点
	}
	return TRUE;
}

/************************************************************************
 *功能：修改节点n的值
 *输入：n:第n个节点,n从0开始算。只算普通节点
 *		list:链表地址
 *		dat:改变节点的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_ChangeNodeValue(DoubleLinkList_t * list,unsigned int n, void *dat)
{
	unsigned int i = n;
	DoubleLinkNode_t* temp = list->node->next;						//临时节点指向第一个有数据节点

	if(list->node == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	if(temp == list->node || temp == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	while(i--)														//循环链表，可以循环查询。如链表长度为3，输入4，指定到节点0
	{
		temp = temp->next;											//指向下一个节点，直到到指定节点
		if(temp == list->node)										//循环到表尾，从头开始计数
		{
			temp = temp->next;
		}
	}
	if(temp != list->node)
	{	
		printf("修改节点%d\r\n",n);
		//temp->data = dat;
		memcpy(temp->data,dat,list->datlen);
		return TRUE;
	} 
	else
	{
		printf("节点不存在！\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：在第n个节点前插入节点，节点从0开始算，只算普通节点
 *输入：list:链表地址
 *		n:第n个节点
 *		dat:插入节点的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_InsertNode(DoubleLinkList_t *list,unsigned int n, void *dat)
{
	unsigned int i = n;
	DoubleLinkNode_t *temp, *pNewNode;								//临时节点

	temp = list->node;												//临时节点指向首节点
	printf("在节点%d之前插入新节点\r\n",n);
	if(list->node == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	if(temp->next == list->node || temp->next == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	while(i--)														//循环链表，可以循环查询。如链表长度为3，输入4，指定到节点0
	{
		temp = temp->next;											//指向下一个节点，直到指向指定节点
		if(temp == list->node)										//循环到表尾，从头开始计数
		{
			temp = temp->next;
		}
	}
	if(temp != list->node)											//注意现在temp是指定节点的前一个节点
	{
		pNewNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));//为新节点分配内存
		pNewNode->data = (void *)malloc(list->datlen);				//为普通节点分配数据内存
		if(pNewNode == NULL)
		{
			printf("新节点空间分配失败！\r\n");
			return FALSE;
		}
		//pNewNode->data = dat;
		memcpy(pNewNode->data,dat,list->datlen);
		pNewNode->next = temp->next;								//新节点后继
		temp->next = pNewNode;										//前一个节点后继为新节点
		pNewNode->pre = temp;										//新节点前驱为前一个节点
		temp = pNewNode->next;										//临时节点指向新节点的后继
		temp->pre = pNewNode;										//后一个节点前驱指向新节点
		return TRUE;
	}
	else
	{
		printf("该节点不存在！\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：在表尾增加节点
 *输入：list:链表地址
 *		dat:插入节点的值
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_AddNode(DoubleLinkList_t *list, void *dat)
{
	DoubleLinkNode_t *temp,*pNewNode;								//临时节点

	temp = list->node;												//临时节点指向首节点	
	printf("在表尾插入新节点\r\n");
	if(list->node == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	pNewNode = (DoubleLinkNode_t*)malloc(sizeof(DoubleLinkNode_t));	//为新节点分配内存
	pNewNode->data = (void *)malloc(list->datlen);					//为普通节点分配数据内存
	if(pNewNode == NULL)
	{
		printf("新节点空间分配失败！\r\n");
		return FALSE;
	}
	//pNewNode->data = dat;
	memcpy(pNewNode->data,dat,list->datlen);
	pNewNode->next = temp;											//新节点后继指向首节点
	pNewNode->pre = temp->pre;										//新节点前驱指向上一个尾节点
	temp->pre = pNewNode;											//首节点前驱指向新节点
	pNewNode->pre->next = pNewNode;									//新节点作为尾节点，其前驱的后继就是新节点本身
	return TRUE;
}

/************************************************************************
 *功能：删除第n个节点，n从0开始算，只算普通节点
 *输入：list:链表地址
		n:第n个节点,从0开始算
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_DeleteNode(DoubleLinkList_t *list,unsigned int n)
{
	unsigned int i=n;
	DoubleLinkNode_t* temp,*pDeleteNode;							//临时节点

	temp = list->node;												//临时节点指向首节点
	printf("删除节点%d\r\n",n);
	if(list->node == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	if(temp->next == list->node || temp->next == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	while(temp->next != list->node && i--)
	{
		temp = temp->next;											//指向下一个节点，直到指向指定节点
	}
	if(temp->next != list->node)									//注意现在temp是指定节点的前一个节点,不能删除首节点
	{
		pDeleteNode = temp->next;									//temp后继是要删除的节点
		temp->next = pDeleteNode->next;								//前一个节点后继
		temp = pDeleteNode->next;									//临时节点赋值为要删除节点的后一个节点
		temp->pre = pDeleteNode->pre;								//后一个节点前驱
		free(pDeleteNode->data);									//释放数据地址,注意释放的顺序不能换
		pDeleteNode->data = NULL;
		free(pDeleteNode);											//释放内存
		pDeleteNode = NULL;
		return TRUE;
	}
	else
	{
		printf("节点不存在！\r\n");
		return FALSE;
	}
}

/************************************************************************
 *功能：清除整个链表
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Clear(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//临时节点

	temp = list->node->next;										//临时节点指向第一个普通节点
	if(list->node == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	if(temp == list->node || temp == NULL)
	{
		printf("链表为空\r\n");
		return FALSE;
	}
	while(temp != list->node)
	{
		p = temp->next;												//当前节点后继赋值给p
		if(temp->data != NULL)
			free(temp->data);										//释放数据地址,注意释放的顺序不能换
		temp->data = NULL;
		free(temp);													//释放当前节点内存
		temp = p;
	}
	/*保留头指针则屏蔽此段代码,特别注意这里的释放内存！需要销毁整个链表时，启动此代码，并屏蔽掉最后两行代码
	 *且销毁整个代码后，不能再遍历链表，否则会出现内存错误。注意这里与非循环双链表的区别，非循环双链表中首节点指向NULL，
	 *判断为 temp==NULL ,所以后续释放p内存并不是释放首节点的内存，首节点还是保留的，在内存中有一席之地；
	 *但是这里的判断为 temp==list ，即释放p就是释放首节点的内存，首节点就不存在了，故后续如果用遍历函数就会出现内存错误。
	 */
	if(temp == list->node)
	{
	//	free(p);//
	//	p = NULL;
		list->node->next = list->node;//首节点后继指向自身
		list->node->pre = list->node;//首节点前驱指向自身
		printf("清除链表成功！\r\n");
		return TRUE;
	}
	return FALSE;
}

/************************************************************************
 *功能：销毁整个链表
 *输入：list:链表地址
 *输出：无
 *返回：TRUE or FALSE
************************************************************************/
bool CycDoubleLink_Destroy(DoubleLinkList_t *list)
{
	DoubleLinkNode_t *temp,*p;										//临时节点

	temp = list->node;												//临时节点指向首节点
	if(temp == NULL)
	{
		printf("链表不存在\r\n");
		return FALSE;
	}
	while(temp != list->node)
	{
		p = temp->next;												//当前节点后继赋值给p
		if(temp->data != NULL)
			free(temp->data);										//释放数据地址,注意释放的顺序不能换
		temp->data = NULL;
		free(temp);													//释放当前节点内存
		temp = p;
	}
	if(temp == list->node)
	{
		if(temp->data != NULL)
			free(temp->data);										//释放数据地址,注意释放的顺序不能换
		temp->data = NULL;
		free(temp);													//释放首节点空间
		temp = NULL;
		list->node = NULL;
		list->datlen = 0;											//链表数据长度清零
		printf("销毁链表成功！\r\n");
		return TRUE;
	}
	return FALSE;
}

void testDoubleLink(void)
{
	int age[4] = {10,11,12,13};
	int dat;
	DoubleLinkList_t teacher;//定义一个链表

	if(DoubleLink_Create(&teacher, sizeof(age)/sizeof(age[0]), age, sizeof(age[0])))//创建4个节点的链表,不包括首节点
		DoubleLink_Traverse(&teacher);		//遍历链表

	dat = 1;
	if(DoubleLink_InsertNode(&teacher, 4, &dat))		//在第n个节点前插入新节点
		DoubleLink_Traverse(&teacher);		//遍历链表
	
	dat = 2;
	if(DoubleLink_ChangeNodeValue(&teacher, 0, &dat))	//修改第3个节点的值
		DoubleLink_Traverse(&teacher);		//遍历链表
	
	if(DoubleLink_DeleteNode(&teacher,4))		//删除节点
		DoubleLink_Traverse(&teacher);		//遍历链表
	
	if(DoubleLink_Clear(&teacher))		//清除链表
		DoubleLink_Traverse(&teacher);		//遍历链表

	if(DoubleLink_Destroy(&teacher))		//删除链表
		DoubleLink_Traverse(&teacher);		//遍历链表
	
}

void testCycDoubleLink(void)
{
	int age[4] = {10,11,12,13};
	int dat;
	DoubleLinkList_t people;

	if(CycDoubleLink_Create(&people, sizeof(age)/sizeof(age[0]), age, sizeof(age[0])))
		CycDoubleLink_Traverse(&people);		//遍历链表

	dat = 1;
	if(CycDoubleLink_InsertNode(&people, 4, &dat))		//在第n个节点前插入新节点
		CycDoubleLink_Traverse(&people);		//遍历链表
	
	dat = 2;
	if(CycDoubleLink_ChangeNodeValue(&people, 3, &dat))//修改第3个节点的值
		CycDoubleLink_Traverse(&people);		//遍历链表
	
	dat = 3;
	if(CycDoubleLink_AddNode(&people, &dat))		//在链尾插入新节点
		CycDoubleLink_Traverse(&people);		//遍历链表
	if(CycDoubleLink_AddNode(&people, &dat))		//在链尾插入新节点
		CycDoubleLink_Traverse(&people);		//遍历链表

	if(CycDoubleLink_DeleteNode(&people,12))	//删除节点
		CycDoubleLink_Traverse(&people);		//遍历链表

	if(CycDoubleLink_DeleteNode(&people,0))	//删除节点
		CycDoubleLink_Traverse(&people);		//遍历链表
	
	if(CycDoubleLink_Clear(&people))	//删除链表
		CycDoubleLink_Traverse(&people);		//遍历链表
	
	if(CycDoubleLink_Destroy(&people))	//删除链表
		CycDoubleLink_Traverse(&people);		//遍历链表
}