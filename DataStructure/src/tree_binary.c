/*********************************************************************
*二叉树：
*二叉搜索树：左子树所有节点小于该节点，右子树所有节点大于该节点
*			二叉搜索树所有节点值必须唯一；中序周游可得到由小到大序列
*参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
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
/* 功能：判断一个二叉树是否为空树                                                     
/* 输入：tree:二叉树地址
/* 输出：无
/* 返回：空，TRUE ；非空，FALSE
/************************************************************************/
bool BinaryTree_IsEmpty(BinaryTree_t *tree)
{
	if(tree->root == NULL)
		return TRUE;
	else
		return FALSE;
}

/************************************************************************/
/* 功能：创建一个二叉树
/* 输入：tree:二叉树地址
/*		datlen:数据类型长度
/*		rootdat:根节点数据
/* 输出：
/* 返回：TRUE or FALSE
/************************************************************************/
bool BinaryTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat)
{
	BinaryTreeNode_t *root = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));//开辟节点空间
	root->dat = (void *)malloc(datlen);						//开辟数据空间
	if(root == NULL || root->dat == NULL)
	{
		printf("创建失败!\r\n");
		return FALSE;
	}
	memcpy(root->dat, rootdat, datlen);						//数据赋值
	tree->root = root;
	tree->datlen = datlen;
	return TRUE;
}

/************************************************************************/
/* 功能：在某节点插入新节点
/* 输入：tree:二叉树地址
/*		parent:父节点，在此节点后插入
/*		dat:要插入节点的数据
/*		LeftRight：在左子节点插入还是右子节点插入
/* 输出：无
/* 返回：TRUE 成功；FALSE 失败
/************************************************************************/
bool BinaryTree_InsertNode(BinaryTree_t *tree, BinaryTreeNode_t *parent, void *dat, unsigned char LeftRight)
{
	BinaryTreeNode_t *currentnode = NULL;

	if(parent == NULL)
	{
		printf("插入节点处为空，无法插入新节点！\r\n");
		return FALSE;
	}
	currentnode = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));
	currentnode->dat = (void *)malloc(tree->datlen);
	if(currentnode == NULL || currentnode->dat == NULL)
	{
		printf("申请空间失败\r\n");
		return FALSE;
	}
	memcpy(currentnode->dat, dat, tree->datlen);			//赋值

	if(LeftRight == Left)
	{
		parent->left->parent = currentnode;
		currentnode->parent = parent;						//当前节点指向父节点
		parent->left = currentnode;							//父节点左子节点指向当前节点
	}
	else if(LeftRight == Right)
	{
		parent->right->parent = currentnode;
		currentnode->parent = parent;						//当前节点指向父节点
		parent->right = currentnode;						//父节点右子节点指向当前节点
	}
	return TRUE;	
}

/*************************************************************************************/
/*功能：二叉搜索树是否为空
/*输入：tree:二叉搜索树的地址
/*输出：无
/*返回：空，TRUE ；非空，FALSE
/*************************************************************************************/
bool BinarySearchTree_IsEmpty(BinaryTree_t *tree)
{
	return BinaryTree_IsEmpty(tree);
}

/*************************************************************************************/
/*功能：创建二叉搜索树
/*输入：tree:二叉搜索树的地址
/*输出：无
/*返回：TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat)
{
	return BinaryTree_Create(tree, datlen, rootdat);
}

/*************************************************************************************/
/*功能：二叉搜索树节点插入算法，按照输入数据大小，自动选择合适的节点插入。
/*		插入后需符合二叉搜索树的特点，即左树小，右树大
/*输入：tree:二叉搜索树的地址
/*		dat:待插入新节点的数据
/*输出：无
/*返回：TRUE or FALSE
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
		printf("申请空间失败\r\n");
		return FALSE;
	}
	memcpy(newpointer->dat, dat, tree->datlen);
	/* 若树为空，则新节点作为树根,否则记录根节点 */
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
		if(newvalue == pointervalue)						//存在相等元素则不插入
		{
			printf("存在与插入元素相等的值 %d\r\n",newpointer->dat);
			goto err;
		}
		else if(newvalue < pointervalue)					//待插入节点小于当前节点关键码值
		{
			if(pointer->left == NULL)						//如果pointer没有左子树
			{
				pointer->left = newpointer;					//newpointer作为pointer左子树
				newpointer->parent = pointer;
				return TRUE;
			}
			else
				pointer = pointer->left;					//向左下降
		}
		else if(newvalue > pointervalue)
		{
			if(pointer->right == NULL)						//如果pointer没有右子树
			{
				pointer->right = newpointer;				//newpointer作为pointer右子树
				newpointer->parent = pointer;
				return TRUE;
			}
			else
				pointer = pointer->right;					//向右下降
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
/*功能：二叉搜索树查找节点算法
/*输入：tree:二叉搜索树的地址
/*		dat:要查找节点的数据的指针
/*输出：
/*返回：满足数据值的节点地址
/*************************************************************************************/
BinaryTreeNode_t* BinarySearchTree_SearchNode(BinaryTree_t *tree, void *dat)
{
	BinaryTreeNode_t *pointer = NULL;
	uchar i = 0;
	long datvalue = 0,pointervalue = 0;

	if(BinarySearchTree_IsEmpty(tree))						//如果是空树
	{
		printf("二叉树为空！\r\n");
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
			printf("找到： %d\r\n",pointervalue);
			return pointer;
		}
		else if(datvalue < pointervalue)				//要查找的值小于当前节点值，向左查找
		{
			if(pointer->left == NULL)										
			{
				printf("此二叉树中不存在此值！\r\n");
				return NULL;
			}
			else
				pointer = pointer->left;				//向左下降
		}
		else if(datvalue > pointervalue)				//要查找的值大于当前节点值，向右查找
		{
			if(pointer->right == NULL)					//如果pointer没有右子树
			{
				printf("此二叉树中不存在此值！\r\n");
				return NULL;
			}
			else
				pointer = pointer->right;				//向右下降
		}
	}
}

/*************************************************************************************/
/*功能：二叉搜索树节点删除算法															 
/*输入：tree:搜索二叉树地址
/*		pointer:待删除节点
/*输出：无
/*返回：TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_DeleteNode(BinaryTree_t *tree, BinaryTreeNode_t *pointer)
{
	BinaryTreeNode_t *temppointer;							//用于保存替换被删除节点的节点
	BinaryTreeNode_t *tempparent = NULL;					//用于保存替换节点的父节点
	if(pointer == NULL)										//待删除节点不存在
	{
		printf("节点不存在！\r\n");
		return FALSE;
	}
	if(pointer->left == NULL)								//如果待删除节点左子树为空
		temppointer = pointer->right;						//替换节点赋值为其右子树
	else													//替换节点左子树不为空，在左子树中寻找最大节点作为替换节点
	{
		temppointer = pointer->left;						//替换节点赋值为左子树
		while(temppointer->right != NULL)					//寻找左子树中最大节点，向右路下降即可
		{
			tempparent = temppointer;						//保存替换节点的父节点
			temppointer = temppointer->right;				//向右下降
		}
		if(tempparent == NULL)								//如果替换节点就是被删除节点的左子节点，则不会进入上面的while循环
			pointer->left = temppointer->left;				//替换节点左子树挂接到被删除节点的左子树
		else
			tempparent->right = temppointer->left;			//替换节点的左子树作为其父节点的右子树
		temppointer->left = pointer->left;					//继承pointer左子树
		temppointer->right = pointer->right;				//继承pointer的右子树
		temppointer->parent = pointer->parent;				//继承pointer的父节点
	}

	//下面用替换节点代替待删除节点
	if(pointer->parent == NULL)								//被删除节点为根节点
		temppointer->parent = NULL;
	else if(pointer->parent->left == pointer)				//被删除节点挂在其父节点的左子树
		pointer->parent->left = temppointer;
	else													//被删除节点挂在其父节点的右子树
		pointer->parent->right = temppointer;				

	free(pointer->dat);
	pointer->dat = NULL;
	free(pointer);											//释放节点内存
	pointer = NULL;
	return TRUE;
}

/************************************************************************/
/* 访问当前节点内容                                                     */
/* cunrrentnode:当前节点
/* tree:二叉树地址
/************************************************************************/
void visit(BinaryTree_t *tree, BinaryTreeNode_t *currentnode)
{
	long value = void2long(currentnode->dat, tree->datlen);
	printf("%d ",value);
}

/************************************************************************/
/* 前序周游二叉树                                                       */
/************************************************************************/
void PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		visit(tree, root);				//访问当前节点
		PreOrder(tree, root->left);		//前序周游左子树
		PreOrder(tree, root->right);		//前序周游右子树
	}
}
/************************************************************************/
/* 中序周游二叉树                                                       */
/************************************************************************/
void InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		InOrder(tree, root->left);		//中序周游左子树
		visit(tree, root);				//访问当前节点
		InOrder(tree, root->right);		//中序周游右子树
	}
}
/************************************************************************/
/* 后序周游二叉树                                                       */
/************************************************************************/
void PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		PostOrder(tree, root->left);		//后序周游左子树
		PostOrder(tree, root->right);		//后序周游右子树
		visit(tree, root);				//访问当前节点
	}
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/***************************非递归方法深度周游二叉树*************************************/
/*链表节点结构体*/
typedef struct LinkNode_BinaryTree
{
	BinaryTreeNode_t *node;						//二叉树节点指针
	struct LinkNode_BinaryTree* next;
}LinkNode_BinaryTree;

/*链表栈结构体*/
typedef struct
{
	LinkNode_BinaryTree *top;					//指向栈顶
	int size;
}LinkStack_BinaryTree;

/************************************************************************/
/* 创建栈                                                     */
/* size:栈的大小
/************************************************************************/
static void CreateLinkStack_BinaryTree(LinkStack_BinaryTree *s)
{
	s->size = 0;	//初始化为空栈
	s->top = NULL;	//指向空
}
/************************************************************************/
/* 压栈                                                     */
/* s：二叉树链式栈首地址
/* node: 要插入的二叉树节点
/************************************************************************/
static void LSpush_BinaryTree(LinkStack_BinaryTree *s,BinaryTreeNode_t *node)//向链首插入节点，作为后入节点
{
	LinkNode_BinaryTree *temp = (LinkNode_BinaryTree *)malloc(sizeof(LinkNode_BinaryTree));//开辟空间,大小为LinkNode_BinaryTree
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
	s->top->node = node;			//二叉树节点地址赋值
	s->size++;						//栈大小加1
}

/************************************************************************/
/* 出栈
/* s：二叉树链式栈首地址
/* 返回：栈顶的二叉树节点地址
/************************************************************************/
static BinaryTreeNode_t *LSpop_BinaryTree(LinkStack_BinaryTree *s)
{
	BinaryTreeNode_t *temp=NULL;				//二叉树节点指针
	LinkNode_BinaryTree *tempNode=NULL;		//临时栈节点
	if(s->top != NULL)						//栈非空
	{
		temp = s->top->node;				//提取元素
		tempNode = s->top;					//当前节点给临时节点
		s->top = s->top->next;				//指向下一个节点
		free(tempNode);
		tempNode = NULL;
		s->size--;							//栈大小减1

		return temp;						//返回二叉树节点指针
	}
	else
	{
		printf("栈空\r\n");
		return NULL;
	}
}
/************************************************************************/
/* 判空栈
/************************************************************************/
static bool isStackEmpty_BinaryTree(LinkStack_BinaryTree *s)
{
	if(s->top != NULL)				//栈非空返回0
	{
		return FALSE;
	}
	else
	{
		printf("栈空\r\n");			//栈空返回1
		return TRUE;
	}
}

/************************************************************************/
/* 清除栈
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
		printf("清栈成功！\r\n");
	}
}
/************************************************************************/
/* 前序周游二叉树,非递归方法                                            */
/************************************************************************/
void PreOrderWithoutRecursion(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	LinkStack_BinaryTree temp;									//定义栈变量
	CreateLinkStack_BinaryTree(&temp);							//创建栈
	LSpush_BinaryTree(&temp,(BinaryTreeNode_t *)NULL);			//栈底监视哨

	while(pointer || !isStackEmpty_BinaryTree(&temp))			//栈非空
	{
		visit(pointer);											//访问当前节点
		if(pointer->right != NULL)								//非空右子节点入栈
			LSpush_BinaryTree(&temp,pointer->right);
		if(pointer->left != NULL)						
			pointer = pointer->left;							//左路下降
		else
			pointer = LSpop_BinaryTree(&temp);					//栈顶元素退栈
	}
}
/************************************************************************/
/* 中序周游二叉树,非递归方法                                            */
/************************************************************************/
void InOrderWithoutRecursion(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	LinkStack_BinaryTree temp;									//定义栈变量
	CreateLinkStack_BinaryTree(&temp);							//创建栈
//	LSpush_BinaryTree(&temp,(BinaryTreeNode_t *)NULL);			//栈底监视哨

	while(pointer || !isStackEmpty_BinaryTree(&temp))			//栈非空
	{
		if(pointer)
		{
			LSpush_BinaryTree(&temp,pointer);
			pointer = pointer->left;							//左路下降
		}
		else
		{
			pointer = LSpop_BinaryTree(&temp);					//栈顶元素退栈
			visit(pointer);										//访问当前节点
			pointer = pointer->right;							//指针指向右子节点
		}
	}
}
/************************************************************************/
/* 后序周游二叉树,非递归方法                                            */
/************************************************************************/
void PostOrderWithoutRecursion(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	LinkStack_BinaryTree temp;								//定义栈变量
	CreateLinkStack_BinaryTree(&temp);						//创建栈
//	LSpush_BinaryTree(&temp,(BinaryTreeNode_t *)NULL);		//栈底监视哨
	
	if(root == NULL)										//空树则返回
		return;
	else
		pointer = root;
	while(pointer || !isStackEmpty_BinaryTree(&temp))		//栈非空
	{
		while(pointer != NULL)								//如果当前指针非空，则压栈并下降到最左子节点
		{					
			pointer->val.tag = Left;						//标志位为Left,表示进入左子树
			LSpush_BinaryTree(&temp,pointer);				
			pointer = pointer->left;						//从左路下降
		}
		pointer = LSpop_BinaryTree(&temp);					//左路下降到底，弹出栈顶元素
		if(pointer->val.tag == Left)						//如果从左子树返回
		{
			pointer->val.tag= Right;						//标志位为Right,表示进入右子树
			LSpush_BinaryTree(&temp,pointer);				
			pointer = pointer->right;
		}
		else												//如果从右子树返回
		{
			visit(pointer);									//访问当前节点
			pointer = NULL;									//置pointer指针为空，以便继续弹出栈
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/********************************广度周游二叉树*************************************/
typedef struct QueueNode
{
	BinaryTreeNode_t *node;
	struct QueueNode *next;
}QueueNode;
typedef struct  Queue_BinaryTree
{
	int size;											//队列大小
	QueueNode *queuenode;								//队列节点
	QueueNode *front;									//队头
	QueueNode *rear;									//队尾
}Queue_BinaryTree;
//创建队列
static void CreateQueue_BinrayTree(Queue_BinaryTree *q)
{
	q->queuenode = NULL;
	q->rear = NULL;
	q->front = NULL;
	q->size = 0;
}

//进队列
static void enQueue_BinaryTree(Queue_BinaryTree *q,BinaryTreeNode_t *node)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));				//开辟空间
	temp->node = node;														//赋值
	temp->next = NULL;
	if(q->front == NULL)													//队头为空，即队列为空
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->rear->next = temp;												//队尾后放入新节点
		q->rear = temp;														//队尾指向新节点
	}
	q->size ++;																//队列大小加1
}

//出队列
static BinaryTreeNode_t * deQueue_BinaryTree(Queue_BinaryTree *q)
{
	QueueNode *temp=NULL;													//临时队列节点变量
	BinaryTreeNode_t *node=NULL;
	if(q->front == NULL || 0 == q->size )
	{
		printf("队列为空\r\n");
		return NULL;
	}
	else
	{
		q->size --;															//队列大小减1
		temp = q->front;													//读出数据
		node = temp->node;
		q->front = temp->next;												//对头指向下一个节点
		free(temp);															//释放空间
		temp = NULL;		
		return node;														//返回队首地址
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
/* 广度周游二叉树                                                       */
/************************************************************************/
void LevelOrder(BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	Queue_BinaryTree queue;
	CreateQueue_BinrayTree(&queue);											//创建队列

	if(pointer != NULL)
	{
		enQueue_BinaryTree(&queue,pointer);									//根节点入队列
	}
	while(!isQueueEmpty_BinaryTree(&queue))									//队列非空
	{
		pointer = deQueue_BinaryTree(&queue);								//获取队列队首节点地址
		visit(pointer);														//访问当前节点
		if(pointer->left != NULL)
			enQueue_BinaryTree(&queue,pointer->left);						//左子树进队列
		if(pointer->right != NULL)
			enQueue_BinaryTree(&queue,pointer->right);						//右子树进队列
	}
}



void testBinaryTree(void)
{
	unsigned char i=0;
	BinaryTreeNode_t *root;//定义一个二叉树根节点
	BinaryTreeNode_t *temp;//临时节点
	ValueType_t val[10] = {{0,Left},{10,Left},{20,Left},{30,Left},{40,Left},    {35,Left},{25,Left},{15,Left},{5,Left},{66,Left}};
	ValueType_t testvalue = {3,Left};
	root = CreateBinaryTree(NULL,NULL,NULL,val[2]);//创建二叉树

	for(i = 0;i<10;i++)//插入10个节点，按照二叉搜索树的形式排列大小
	{
		temp = (BinaryTreeNode_t*)malloc(sizeof(BinaryTreeNode_t));
		temp->left = NULL;
		temp->right = NULL;
		temp->val = val[i];
		BinarySearchTree_InsertNode(root,temp);
	}
	printf("\r\n中序遍历：\r\n");
	InOrder(root);
	printf("\r\n");
	InOrderWithoutRecursion(root);

	printf("\r\n前序遍历：\r\n");
	PreOrder(root);
	printf("\r\n");
	PreOrderWithoutRecursion(root);

	printf("\r\n后序遍历：\r\n");
	PostOrder(root);
	printf("\r\n");
	PostOrderWithoutRecursion(root);

	printf("\r\n广度周游：\r\n");
	LevelOrder(root);
	printf("\r\n\r\n");

	if(NULL != (temp = BinarySearchTree_SearchNode(root,testvalue)))
		BinarySearchTree_DeleteNode(temp);//删除节点
	printf("中序遍历：\r\n");
	InOrder(root);
	printf("\r\n");
	InOrderWithoutRecursion(root);
}