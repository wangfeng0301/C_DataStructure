/*********************************************************************
*��������
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*2019.11.28
**********************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "tree_binary.h"

/************************************************************************/
/* ����һ��������                                                     
/* parent:		���ڵ�
/* leftchild:	������
/* rightchild:	������
/* ���أ�		���ڵ��ַ
/************************************************************************/
static BinaryTreeNode *CreateBinaryTree(BinaryTreeNode *parent,BinaryTreeNode *leftchild,BinaryTreeNode *rightchild,ValueType data)
{
	BinaryTreeNode *temp = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));	//���ٿռ�
	if(temp == NULL)
	{
		printf("����ʧ��!\r\n");
		return NULL;
	}
	temp->parent = parent;													//���ڵ�
	temp->left = leftchild;													//���ӽڵ�
	temp->right = rightchild;												//���ӽڵ�
	temp->val = data;														//���ݸ�ֵ

	return temp;															//���صĽڵ��ַ�����ڵ�
}

/************************************************************************/
/* ������������ĳ�ڵ�����½ڵ�  
/* parent:���ڵ㣬�ڴ˽ڵ�����
/* currentnode:		��ǰ�ڵ㣬Ҫ����Ľڵ�
/* leftRight��	�����ӽڵ���뻹�����ӽڵ����
/* ���أ�TRUE �ɹ���FALSE ʧ��
/************************************************************************/
static bool InsertBinaryTreeNode(BinaryTreeNode *parent,BinaryTreeNode *currentnode,unsigned char LeftRight)
{
	if(parent == NULL)
	{
		printf("����ڵ㴦Ϊ�գ��޷������½ڵ㣡\r\n");
		return FALSE;
	}
	if(LeftRight == Left)
	{
		parent->left->parent = currentnode;
		currentnode->parent = parent;									//��ǰ�ڵ�ָ�򸸽ڵ�
		parent->left = currentnode;										//���ڵ����ӽڵ�ָ��ǰ�ڵ�
	}
	else if(LeftRight == Right)
	{
		parent->right->parent = currentnode;
		currentnode->parent = parent;									//��ǰ�ڵ�ָ�򸸽ڵ�
		parent->right = currentnode;									//���ڵ����ӽڵ�ָ��ǰ�ڵ�
	}
	return TRUE;	
}

/*************************************************************************************/
/*�����������ڵ�����㷨															 */
/*root:�����������ĸ��ڵ�
/*newpointer:��������½ڵ�
/* �����������ݴ�С���Զ�ѡ����ʵĽڵ���롣���������϶������������ص㣬������С��������
/*************************************************************************************/
void BinarySearchTree_InsertNode(BinaryTreeNode *root,BinaryTreeNode *newpointer)
{
	BinaryTreeNode *pointer = NULL;
	if(root == NULL)														//����ǿ���
	{
		root = newpointer;													//����ָ��newpointer��Ϊ����
		return;
	}
	else
		pointer = root;
	while(pointer != NULL)
	{
		if(newpointer->val.val == pointer->val.val)							//�������Ԫ���򲻲���
		{
			printf("���������Ԫ����ȵ�ֵ %d\r\n",newpointer->val.val);
			return;
		}
		else if(newpointer->val.val < pointer->val.val)						//������ڵ�С�ڵ�ǰ�ڵ�ؼ���ֵ
		{
			if(pointer->left == NULL)										//���pointerû��������
			{
				pointer->left = newpointer;									//newpointer��Ϊpointer������
				newpointer->parent = pointer;
				return;
			}
			else
				pointer = pointer->left;									//�����½�
		}
		else if(newpointer->val.val > pointer->val.val)
		{
			if(pointer->right == NULL)										//���pointerû��������
			{
				pointer->right = newpointer;								//newpointer��Ϊpointer������
				newpointer->parent = pointer;
				return;
			}
			else
				pointer = pointer->right;									//�����½�
		}
	}
}

/*************************************************************************************/
/*�������������ҽڵ��㷨															 */
/*root:�����������ĸ��ڵ�
/*ValueType:Ҫ���ҽڵ������ֵ
/* ���أ���������ֵ�Ľڵ��ַ
/*************************************************************************************/
static BinaryTreeNode* BinarySearchTree_SearchNode(BinaryTreeNode *root,ValueType data)
{
	BinaryTreeNode *pointer = NULL;
	if(root == NULL)														//����ǿ���
	{
		printf("������Ϊ�գ�\r\n");
		return NULL;
	}
	else
		pointer = root;
	while(pointer != NULL)
	{
		if(data.val == pointer->val.val)									//�������Ԫ���򲻲���
		{
			printf("�ҵ��� %d\r\n",pointer->val.val);
			return pointer;
		}
		else if(data.val < pointer->val.val)								//������ڵ�С�ڵ�ǰ�ڵ�ؼ���ֵ
		{
			if(pointer->left == NULL)										//���pointerû��������
			{
				printf("�˶������в����ڴ�ֵ��\r\n");
				return NULL;
			}
			else
				pointer = pointer->left;									//�����½�
		}
		else if(data.val > pointer->val.val)
		{
			if(pointer->right == NULL)										//���pointerû��������
			{
				printf("�˶������в����ڴ�ֵ��\r\n");
				return NULL;
			}
			else
				pointer = pointer->right;									//�����½�
		}
	}
}

/*************************************************************************************/
/*�����������ڵ�ɾ���㷨															 
/*pointer:��ɾ���ڵ�
/*************************************************************************************/
void BinarySearchTree_DeleteNode(BinaryTreeNode *pointer)
{
	BinaryTreeNode *temppointer;											//���ڱ����滻��ɾ���ڵ�Ľڵ�
	BinaryTreeNode *tempparent = NULL;										//���ڱ����滻�ڵ�ĸ��ڵ�
	if(pointer == NULL)														//��ɾ���ڵ㲻����
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return;
	}
	if(pointer->left == NULL)												//�����ɾ���ڵ�������Ϊ��
		temppointer = pointer->right;										//�滻�ڵ㸳ֵΪ��������
	else																	//�滻�ڵ���������Ϊ�գ�����������Ѱ�����ڵ���Ϊ�滻�ڵ�
	{
		temppointer = pointer->left;										//�滻�ڵ㸳ֵΪ������
		while(temppointer->right != NULL)									//Ѱ�������������ڵ㣬����·�½�����
		{
			tempparent = temppointer;										//�����滻�ڵ�ĸ��ڵ�
			temppointer = temppointer->right;								//�����½�
		}
		if(tempparent == NULL)												//����滻�ڵ���Ǳ�ɾ���ڵ�����ӽڵ㣬�򲻻���������whileѭ��
			pointer->left = temppointer->left;								//�滻�ڵ��������ҽӵ���ɾ���ڵ��������
		else
			tempparent->right = temppointer->left;							//�滻�ڵ����������Ϊ�丸�ڵ��������
		temppointer->left = pointer->left;									//�̳�pointer������
		temppointer->right = pointer->right;								//�̳�pointer��������
		temppointer->parent = pointer->parent;								//�̳�pointer�ĸ��ڵ�
	}

	//�������滻�ڵ�����ɾ���ڵ�
	if(pointer->parent == NULL)												//��ɾ���ڵ�Ϊ���ڵ�
		temppointer->parent = NULL;
	else if(pointer->parent->left == pointer)								//��ɾ���ڵ�����丸�ڵ��������
		pointer->parent->left = temppointer;
	else																	//��ɾ���ڵ�����丸�ڵ��������
		pointer->parent->right = temppointer;								

	free(pointer);															//�ͷŽڵ��ڴ�
	pointer = NULL;
	return ;
}

/************************************************************************/
/* ���ʵ�ǰ�ڵ�����                                                     */
/* cunrrentnode:��ǰ�ڵ�
/************************************************************************/
void visit(BinaryTreeNode *currentnode)
{
	printf("%d ",currentnode->val.val);
}
/************************************************************************/
/* �пն�����                                                           */
/* root:���������ڵ�
/************************************************************************/
bool isEmpty_BinaryTree(BinaryTreeNode *root)
{
	if(root != NULL)
		return FALSE;
	else
		return TRUE;
}

/************************************************************************/
/* ǰ�����ζ�����                                                       */
/************************************************************************/
void PreOrder(BinaryTreeNode *root)
{
	if(root != NULL)
	{
		visit(root);				//���ʵ�ǰ�ڵ�
		PreOrder(root->left);		//ǰ������������
		PreOrder(root->right);		//ǰ������������
	}
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void InOrder(BinaryTreeNode *root)
{
	if(root != NULL)
	{
		InOrder(root->left);		//��������������
		visit(root);				//���ʵ�ǰ�ڵ�
		InOrder(root->right);		//��������������
	}
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void PostOrder(BinaryTreeNode *root)
{
	if(root != NULL)
	{
		PostOrder(root->left);		//��������������
		PostOrder(root->right);		//��������������
		visit(root);				//���ʵ�ǰ�ڵ�
	}
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/***************************�ǵݹ鷽��������ζ�����*************************************/
/*����ڵ�ṹ��*/
typedef struct LinkNode_BinaryTree
{
	BinaryTreeNode *node;						//�������ڵ�ָ��
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
static void LSpush_BinaryTree(LinkStack_BinaryTree *s,BinaryTreeNode *node)//�����ײ���ڵ㣬��Ϊ����ڵ�
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
static BinaryTreeNode *LSpop_BinaryTree(LinkStack_BinaryTree *s)
{
	BinaryTreeNode *temp=NULL;				//�������ڵ�ָ��
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
void PreOrderWithoutRecursion(BinaryTreeNode *root)
{
	BinaryTreeNode *pointer = root;
	LinkStack_BinaryTree temp;									//����ջ����
	CreateLinkStack_BinaryTree(&temp);							//����ջ
	LSpush_BinaryTree(&temp,(BinaryTreeNode *)NULL);			//ջ�׼�����

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
void InOrderWithoutRecursion(BinaryTreeNode *root)
{
	BinaryTreeNode *pointer = root;
	LinkStack_BinaryTree temp;									//����ջ����
	CreateLinkStack_BinaryTree(&temp);							//����ջ
//	LSpush_BinaryTree(&temp,(BinaryTreeNode *)NULL);			//ջ�׼�����

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
void PostOrderWithoutRecursion(BinaryTreeNode *root)
{
	BinaryTreeNode *pointer = root;
	LinkStack_BinaryTree temp;								//����ջ����
	CreateLinkStack_BinaryTree(&temp);						//����ջ
//	LSpush_BinaryTree(&temp,(BinaryTreeNode *)NULL);		//ջ�׼�����
	
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
	BinaryTreeNode *node;
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
static void enQueue_BinaryTree(Queue_BinaryTree *q,BinaryTreeNode *node)
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
static BinaryTreeNode * deQueue_BinaryTree(Queue_BinaryTree *q)
{
	QueueNode *temp=NULL;													//��ʱ���нڵ����
	BinaryTreeNode *node=NULL;
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
void LevelOrder(BinaryTreeNode *root)
{
	BinaryTreeNode *pointer = root;
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
	BinaryTreeNode *root;//����һ�����������ڵ�
	BinaryTreeNode *temp;//��ʱ�ڵ�
	ValueType val[10] = {{0,Left},{10,Left},{20,Left},{30,Left},{40,Left},    {35,Left},{25,Left},{15,Left},{5,Left},{66,Left}};
	ValueType testvalue = {3,Left};
	root = CreateBinaryTree(NULL,NULL,NULL,val[2]);//����������

	for(i = 0;i<10;i++)//����10���ڵ㣬���ն�������������ʽ���д�С
	{
		temp = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
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