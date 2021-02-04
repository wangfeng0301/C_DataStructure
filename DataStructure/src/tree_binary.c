/*********************************************************************
*��������
*���������������������нڵ�С�ڸýڵ㣬���������нڵ���ڸýڵ�
*			�������������нڵ�ֵ����Ψһ���������οɵõ���С��������
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*E-mail:fengwang0301@163.com
*CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
*GitHub:https://github.com/wangfeng0301
*2019.11.28-2021.2.3
**********************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "tree_binary.h"
#include "misc.h"

/************************************************************************/
/* ���ܣ��ж�һ���������Ƿ�Ϊ����                                                     
/* ���룺tree:��������ַ
/* �������
/* ���أ��գ�TRUE ���ǿգ�FALSE
/************************************************************************/
bool BinaryTree_IsEmpty(BinaryTree_t *tree)
{
	if(tree->root == NULL)
		return TRUE;
	else
		return FALSE;
}

/************************************************************************/
/* ���ܣ�����һ��������
/* ���룺tree:��������ַ
/*		datlen:�������ͳ���
/*		rootdat:���ڵ�����
/* �����
/* ���أ�TRUE or FALSE
/************************************************************************/
bool BinaryTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat)
{
	BinaryTreeNode_t *root = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));//���ٽڵ�ռ�
	root->dat = (void *)malloc(datlen);						//�������ݿռ�
	if(root == NULL || root->dat == NULL)
	{
		printf("����ʧ��!\r\n");
		return FALSE;
	}
	memcpy(root->dat, rootdat, datlen);						//���ݸ�ֵ
	tree->root = root;
	tree->datlen = datlen;
	return TRUE;
}

/************************************************************************/
/* ���ܣ���ĳ�ڵ�����½ڵ�
/* ���룺tree:��������ַ
/*		parent:���ڵ㣬�ڴ˽ڵ�����
/*		dat:Ҫ����ڵ������
/*		LeftRight�������ӽڵ���뻹�����ӽڵ����
/* �������
/* ���أ�TRUE �ɹ���FALSE ʧ��
/************************************************************************/
bool BinaryTree_InsertNode(BinaryTree_t *tree, BinaryTreeNode_t *parent, void *dat, unsigned char LeftRight)
{
	BinaryTreeNode_t *currentnode = NULL;

	if(parent == NULL)
	{
		printf("����ڵ㴦Ϊ�գ��޷������½ڵ㣡\r\n");
		return FALSE;
	}
	currentnode = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));
	currentnode->dat = (void *)malloc(tree->datlen);
	if(currentnode == NULL || currentnode->dat == NULL)
	{
		printf("����ռ�ʧ��\r\n");
		return FALSE;
	}
	memcpy(currentnode->dat, dat, tree->datlen);			//��ֵ

	if(LeftRight == Left)
	{
		parent->left->parent = currentnode;
		currentnode->parent = parent;						//��ǰ�ڵ�ָ�򸸽ڵ�
		parent->left = currentnode;							//���ڵ����ӽڵ�ָ��ǰ�ڵ�
	}
	else if(LeftRight == Right)
	{
		parent->right->parent = currentnode;
		currentnode->parent = parent;						//��ǰ�ڵ�ָ�򸸽ڵ�
		parent->right = currentnode;						//���ڵ����ӽڵ�ָ��ǰ�ڵ�
	}
	return TRUE;	
}

/*************************************************************************************/
/*���ܣ������������Ƿ�Ϊ��
/*���룺tree:�����������ĵ�ַ
/*�������
/*���أ��գ�TRUE ���ǿգ�FALSE
/*************************************************************************************/
bool BinarySearchTree_IsEmpty(BinaryTree_t *tree)
{
	return BinaryTree_IsEmpty(tree);
}

/*************************************************************************************/
/*���ܣ���������������
/*���룺tree:�����������ĵ�ַ
/*�������
/*���أ�TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat)
{
	return BinaryTree_Create(tree, datlen, rootdat);
}

/*************************************************************************************/
/*���ܣ������������ڵ�����㷨�������������ݴ�С���Զ�ѡ����ʵĽڵ���롣
/*		���������϶������������ص㣬������С��������
/*���룺tree:�����������ĵ�ַ
/*		dat:�������½ڵ������
/*�������
/*���أ�TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_InsertNode(BinaryTree_t *tree, void *dat)
{
	BinaryTreeNode_t *pointer = NULL;
	BinaryTreeNode_t *newpointer = NULL;
	long newvalue = 0,pointervalue = 0;
	uchar i = 0;

	newpointer = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));
	newpointer->dat = (void *)malloc(tree->datlen);
	if(newpointer == NULL || newpointer->dat == NULL)
	{
		printf("����ռ�ʧ��\r\n");
		return FALSE;
	}
	memcpy(newpointer->dat, dat, tree->datlen);
	/* ����Ϊ�գ����½ڵ���Ϊ����,�����¼���ڵ� */
	if(tree->root == NULL)
	{
		tree->root = newpointer;
		return TRUE;
	}
	else
		pointer = tree->root;
	while(pointer != NULL)
	{
		newvalue = void2long(newpointer->dat, tree->datlen);
		pointervalue = void2long(pointer->dat, tree->datlen);
		if(newvalue == pointervalue)						//�������Ԫ���򲻲���
		{
			printf("���������Ԫ����ȵ�ֵ %d\r\n",newpointer->dat);
			goto err;
		}
		else if(newvalue < pointervalue)					//������ڵ�С�ڵ�ǰ�ڵ�ؼ���ֵ
		{
			if(pointer->left == NULL)						//���pointerû��������
			{
				pointer->left = newpointer;					//newpointer��Ϊpointer������
				newpointer->parent = pointer;
				return TRUE;
			}
			else
				pointer = pointer->left;					//�����½�
		}
		else if(newvalue > pointervalue)
		{
			if(pointer->right == NULL)						//���pointerû��������
			{
				pointer->right = newpointer;				//newpointer��Ϊpointer������
				newpointer->parent = pointer;
				return TRUE;
			}
			else
				pointer = pointer->right;					//�����½�
		}
	}
err:
	free(newpointer->dat);
	newpointer->dat = NULL;
	free(newpointer);
	newpointer = NULL;
	return FALSE;
}

/*************************************************************************************/
/*���ܣ��������������ҽڵ��㷨
/*���룺tree:�����������ĵ�ַ
/*		dat:Ҫ���ҽڵ�����ݵ�ָ��
/*�����
/*���أ���������ֵ�Ľڵ��ַ
/*************************************************************************************/
BinaryTreeNode_t* BinarySearchTree_SearchNode(BinaryTree_t *tree, void *dat)
{
	BinaryTreeNode_t *pointer = NULL;
	uchar i = 0;
	long datvalue = 0,pointervalue = 0;

	if(BinarySearchTree_IsEmpty(tree))						//����ǿ���
	{
		printf("������Ϊ�գ�\r\n");
		return NULL;
	}
	else
		pointer = tree->root;
	while(pointer != NULL)
	{
		datvalue = void2long(dat, tree->datlen);
		pointervalue = void2long(pointer->dat, tree->datlen);
		if(datvalue == pointervalue)									
		{
			printf("�ҵ��� %d\r\n",pointervalue);
			return pointer;
		}
		else if(datvalue < pointervalue)				//Ҫ���ҵ�ֵС�ڵ�ǰ�ڵ�ֵ���������
		{
			if(pointer->left == NULL)										
			{
				printf("�˶������в����ڴ�ֵ��\r\n");
				return NULL;
			}
			else
				pointer = pointer->left;				//�����½�
		}
		else if(datvalue > pointervalue)				//Ҫ���ҵ�ֵ���ڵ�ǰ�ڵ�ֵ�����Ҳ���
		{
			if(pointer->right == NULL)					//���pointerû��������
			{
				printf("�˶������в����ڴ�ֵ��\r\n");
				return NULL;
			}
			else
				pointer = pointer->right;				//�����½�
		}
	}
}

/*************************************************************************************/
/*���ܣ������������ڵ�ɾ���㷨															 
/*���룺tree:������������ַ
/*		pointer:��ɾ���ڵ�
/*�������
/*���أ�TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_DeleteNode(BinaryTree_t *tree, BinaryTreeNode_t *pointer)
{
	BinaryTreeNode_t *temppointer;							//���ڱ����滻��ɾ���ڵ�Ľڵ�
	BinaryTreeNode_t *tempparent = NULL;					//���ڱ����滻�ڵ�ĸ��ڵ�
	if(pointer == NULL)										//��ɾ���ڵ㲻����
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
	if(pointer->left == NULL)								//�����ɾ���ڵ�������Ϊ��
		temppointer = pointer->right;						//�滻�ڵ㸳ֵΪ��������
	else													//�滻�ڵ���������Ϊ�գ�����������Ѱ�����ڵ���Ϊ�滻�ڵ�
	{
		temppointer = pointer->left;						//�滻�ڵ㸳ֵΪ������
		while(temppointer->right != NULL)					//Ѱ�������������ڵ㣬����·�½�����
		{
			tempparent = temppointer;						//�����滻�ڵ�ĸ��ڵ�
			temppointer = temppointer->right;				//�����½�
		}
		if(tempparent == NULL)								//����滻�ڵ���Ǳ�ɾ���ڵ�����ӽڵ㣬�򲻻���������whileѭ��
			pointer->left = temppointer->left;				//�滻�ڵ��������ҽӵ���ɾ���ڵ��������
		else
			tempparent->right = temppointer->left;			//�滻�ڵ����������Ϊ�丸�ڵ��������
		temppointer->left = pointer->left;					//�̳�pointer������
		temppointer->right = pointer->right;				//�̳�pointer��������
		temppointer->parent = pointer->parent;				//�̳�pointer�ĸ��ڵ�
	}

	//�������滻�ڵ�����ɾ���ڵ�
	if(pointer->parent == NULL)								//��ɾ���ڵ�Ϊ���ڵ�
		temppointer->parent = NULL;
	else if(pointer->parent->left == pointer)				//��ɾ���ڵ�����丸�ڵ��������
		pointer->parent->left = temppointer;
	else													//��ɾ���ڵ�����丸�ڵ��������
		pointer->parent->right = temppointer;				

	free(pointer->dat);
	pointer->dat = NULL;
	free(pointer);											//�ͷŽڵ��ڴ�
	pointer = NULL;
	return TRUE;
}

/************************************************************************/
/* ���ʵ�ǰ�ڵ�����                                                     */
/* cunrrentnode:��ǰ�ڵ�
/* tree:��������ַ
/************************************************************************/
void visit(BinaryTree_t *tree, BinaryTreeNode_t *currentnode)
{
	long value = void2long(currentnode->dat, tree->datlen);
	printf("%d ",value);
}

/************************************************************************/
/* ǰ�����ζ�����                                                       */
/************************************************************************/
void PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		visit(tree, root);				//���ʵ�ǰ�ڵ�
		PreOrder(tree, root->left);		//ǰ������������
		PreOrder(tree, root->right);		//ǰ������������
	}
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		InOrder(tree, root->left);		//��������������
		visit(tree, root);				//���ʵ�ǰ�ڵ�
		InOrder(tree, root->right);		//��������������
	}
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		PostOrder(tree, root->left);		//��������������
		PostOrder(tree, root->right);		//��������������
		visit(tree, root);				//���ʵ�ǰ�ڵ�
	}
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/***************************�ǵݹ鷽��������ζ�����*************************************/
/*����ڵ�ṹ��*/
typedef struct LinkNode_BinaryTree
{
	BinaryTreeNode_t *node;						//�������ڵ�ָ��
	struct LinkNode_BinaryTree* next;
}LinkNode_BinaryTree;

/*����ջ�ṹ��*/
typedef struct
{
	LinkNode_BinaryTree *top;					//ָ��ջ��
	int size;
}LinkStack_BinaryTree;

/************************************************************************/
/* ����ջ                                                     */
/* size:ջ�Ĵ�С
/************************************************************************/
static void CreateLinkStack_BinaryTree(LinkStack_BinaryTree *s)
{
	s->size = 0;	//��ʼ��Ϊ��ջ
	s->top = NULL;	//ָ���
}
/************************************************************************/
/* ѹջ                                                     */
/* s����������ʽջ�׵�ַ
/* node: Ҫ����Ķ������ڵ�
/************************************************************************/
static void LSpush_BinaryTree(LinkStack_BinaryTree *s,BinaryTreeNode_t *node)//�����ײ���ڵ㣬��Ϊ����ڵ�
{
	LinkNode_BinaryTree *temp = (LinkNode_BinaryTree *)malloc(sizeof(LinkNode_BinaryTree));//���ٿռ�,��СΪLinkNode_BinaryTree
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
	s->top->node = node;			//�������ڵ��ַ��ֵ
	s->size++;						//ջ��С��1
}

/************************************************************************/
/* ��ջ
/* s����������ʽջ�׵�ַ
/* ���أ�ջ���Ķ������ڵ��ַ
/************************************************************************/
static BinaryTreeNode_t *LSpop_BinaryTree(LinkStack_BinaryTree *s)
{
	BinaryTreeNode_t *temp=NULL;				//�������ڵ�ָ��
	LinkNode_BinaryTree *tempNode=NULL;		//��ʱջ�ڵ�
	if(s->top != NULL)						//ջ�ǿ�
	{
		temp = s->top->node;				//��ȡԪ��
		tempNode = s->top;					//��ǰ�ڵ����ʱ�ڵ�
		s->top = s->top->next;				//ָ����һ���ڵ�
		free(tempNode);
		tempNode = NULL;
		s->size--;							//ջ��С��1

		return temp;						//���ض������ڵ�ָ��
	}
	else
	{
		printf("ջ��\r\n");
		return NULL;
	}
}
/************************************************************************/
/* �п�ջ
/************************************************************************/
static bool isStackEmpty_BinaryTree(LinkStack_BinaryTree *s)
{
	if(s->top != NULL)				//ջ�ǿշ���0
	{
		return FALSE;
	}
	else
	{
		printf("ջ��\r\n");			//ջ�շ���1
		return TRUE;
	}
}

/************************************************************************/
/* ���ջ
/************************************************************************/
static void LSclear_Binary(LinkStack_BinaryTree *s)
{
	LinkNode_BinaryTree *temp=NULL;
	while(s->top != NULL)
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
/************************************************************************/
/* ǰ�����ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void PreOrderWithoutRecursion(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	LinkStack_BinaryTree temp;									//����ջ����
	CreateLinkStack_BinaryTree(&temp);							//����ջ
	LSpush_BinaryTree(&temp,(BinaryTreeNode_t *)NULL);			//ջ�׼�����

	while(pointer || !isStackEmpty_BinaryTree(&temp))			//ջ�ǿ�
	{
		visit(pointer);											//���ʵ�ǰ�ڵ�
		if(pointer->right != NULL)								//�ǿ����ӽڵ���ջ
			LSpush_BinaryTree(&temp,pointer->right);
		if(pointer->left != NULL)						
			pointer = pointer->left;							//��·�½�
		else
			pointer = LSpop_BinaryTree(&temp);					//ջ��Ԫ����ջ
	}
}
/************************************************************************/
/* �������ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void InOrderWithoutRecursion(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	LinkStack_BinaryTree temp;									//����ջ����
	CreateLinkStack_BinaryTree(&temp);							//����ջ
//	LSpush_BinaryTree(&temp,(BinaryTreeNode_t *)NULL);			//ջ�׼�����

	while(pointer || !isStackEmpty_BinaryTree(&temp))			//ջ�ǿ�
	{
		if(pointer)
		{
			LSpush_BinaryTree(&temp,pointer);
			pointer = pointer->left;							//��·�½�
		}
		else
		{
			pointer = LSpop_BinaryTree(&temp);					//ջ��Ԫ����ջ
			visit(pointer);										//���ʵ�ǰ�ڵ�
			pointer = pointer->right;							//ָ��ָ�����ӽڵ�
		}
	}
}
/************************************************************************/
/* �������ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void PostOrderWithoutRecursion(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	LinkStack_BinaryTree temp;								//����ջ����
	CreateLinkStack_BinaryTree(&temp);						//����ջ
//	LSpush_BinaryTree(&temp,(BinaryTreeNode_t *)NULL);		//ջ�׼�����
	
	if(root == NULL)										//�����򷵻�
		return;
	else
		pointer = root;
	while(pointer || !isStackEmpty_BinaryTree(&temp))		//ջ�ǿ�
	{
		while(pointer != NULL)								//�����ǰָ��ǿգ���ѹջ���½��������ӽڵ�
		{					
			pointer->val.tag = Left;						//��־λΪLeft,��ʾ����������
			LSpush_BinaryTree(&temp,pointer);				
			pointer = pointer->left;						//����·�½�
		}
		pointer = LSpop_BinaryTree(&temp);					//��·�½����ף�����ջ��Ԫ��
		if(pointer->val.tag == Left)						//���������������
		{
			pointer->val.tag= Right;						//��־λΪRight,��ʾ����������
			LSpush_BinaryTree(&temp,pointer);				
			pointer = pointer->right;
		}
		else												//���������������
		{
			visit(pointer);									//���ʵ�ǰ�ڵ�
			pointer = NULL;									//��pointerָ��Ϊ�գ��Ա��������ջ
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/********************************������ζ�����*************************************/
typedef struct QueueNode
{
	BinaryTreeNode_t *node;
	struct QueueNode *next;
}QueueNode;
typedef struct  Queue_BinaryTree
{
	int size;											//���д�С
	QueueNode *queuenode;								//���нڵ�
	QueueNode *front;									//��ͷ
	QueueNode *rear;									//��β
}Queue_BinaryTree;
//��������
static void CreateQueue_BinrayTree(Queue_BinaryTree *q)
{
	q->queuenode = NULL;
	q->rear = NULL;
	q->front = NULL;
	q->size = 0;
}

//������
static void enQueue_BinaryTree(Queue_BinaryTree *q,BinaryTreeNode_t *node)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));				//���ٿռ�
	temp->node = node;														//��ֵ
	temp->next = NULL;
	if(q->front == NULL)													//��ͷΪ�գ�������Ϊ��
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->rear->next = temp;												//��β������½ڵ�
		q->rear = temp;														//��βָ���½ڵ�
	}
	q->size ++;																//���д�С��1
}

//������
static BinaryTreeNode_t * deQueue_BinaryTree(Queue_BinaryTree *q)
{
	QueueNode *temp=NULL;													//��ʱ���нڵ����
	BinaryTreeNode_t *node=NULL;
	if(q->front == NULL || 0 == q->size )
	{
		printf("����Ϊ��\r\n");
		return NULL;
	}
	else
	{
		q->size --;															//���д�С��1
		temp = q->front;													//��������
		node = temp->node;
		q->front = temp->next;												//��ͷָ����һ���ڵ�
		free(temp);															//�ͷſռ�
		temp = NULL;		
		return node;														//���ض��׵�ַ
	}
}
static bool isQueueEmpty_BinaryTree(Queue_BinaryTree *q)
{
	if(q->front == NULL || 0 == q->size )
		return TRUE;
	else
		return FALSE;
}
/************************************************************************/
/* ������ζ�����                                                       */
/************************************************************************/
void LevelOrder(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	Queue_BinaryTree queue;
	CreateQueue_BinrayTree(&queue);											//��������

	if(pointer != NULL)
	{
		enQueue_BinaryTree(&queue,pointer);									//���ڵ������
	}
	while(!isQueueEmpty_BinaryTree(&queue))									//���зǿ�
	{
		pointer = deQueue_BinaryTree(&queue);								//��ȡ���ж��׽ڵ��ַ
		visit(pointer);														//���ʵ�ǰ�ڵ�
		if(pointer->left != NULL)
			enQueue_BinaryTree(&queue,pointer->left);						//������������
		if(pointer->right != NULL)
			enQueue_BinaryTree(&queue,pointer->right);						//������������
	}
}



void testBinaryTree(void)
{
	unsigned char i=0;
	BinaryTreeNode_t *root;//����һ�����������ڵ�
	BinaryTreeNode_t *temp;//��ʱ�ڵ�
	ValueType_t val[10] = {{0,Left},{10,Left},{20,Left},{30,Left},{40,Left},    {35,Left},{25,Left},{15,Left},{5,Left},{66,Left}};
	ValueType_t testvalue = {3,Left};
	root = CreateBinaryTree(NULL,NULL,NULL,val[2]);//����������

	for(i = 0;i<10;i++)//����10���ڵ㣬���ն�������������ʽ���д�С
	{
		temp = (BinaryTreeNode_t*)malloc(sizeof(BinaryTreeNode_t));
		temp->left = NULL;
		temp->right = NULL;
		temp->val = val[i];
		BinarySearchTree_InsertNode(root,temp);
	}
	printf("\r\n���������\r\n");
	InOrder(root);
	printf("\r\n");
	InOrderWithoutRecursion(root);

	printf("\r\nǰ�������\r\n");
	PreOrder(root);
	printf("\r\n");
	PreOrderWithoutRecursion(root);

	printf("\r\n���������\r\n");
	PostOrder(root);
	printf("\r\n");
	PostOrderWithoutRecursion(root);

	printf("\r\n������Σ�\r\n");
	LevelOrder(root);
	printf("\r\n\r\n");

	if(NULL != (temp = BinarySearchTree_SearchNode(root,testvalue)))
		BinarySearchTree_DeleteNode(temp);//ɾ���ڵ�
	printf("���������\r\n");
	InOrder(root);
	printf("\r\n");
	InOrderWithoutRecursion(root);
}