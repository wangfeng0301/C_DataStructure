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