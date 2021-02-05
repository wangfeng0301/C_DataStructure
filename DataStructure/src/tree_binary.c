/*********************************************************************
*二叉树：
*二叉搜索树：左子树所有节点小于该节点，右子树所有节点大于该节点
*			二叉搜索树所有节点值必须唯一；中序周游可得到由小到大序列
*参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
*wangfeng
*E-mail:fengwang0301@163.com
*CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
*GitHub:https://github.com/wangfeng0301
*2019.11.28-2021.2.4
*2021.2.4	修改，二叉树不受数据类型限制
**********************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "tree_binary.h"
#include "stack.h"
#include "queue.h"
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
	tree->root->left = NULL;
	tree->root->right = NULL;
	tree->root->parent = NULL;
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
/* 未调试通过
/************************************************************************/
/*bool BinaryTree_InsertNode(BinaryTree_t *tree, BinaryTreeNode_t *parent, void *dat, unsigned char LeftRight)
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

	//if(LeftRight == Left)
	{
		parent->left->parent = currentnode;
		currentnode->parent = parent;						//当前节点指向父节点
		parent->left = currentnode;							//父节点左子节点指向当前节点
	}
	//else if(LeftRight == Right)
	{
		parent->right->parent = currentnode;
		currentnode->parent = parent;						//当前节点指向父节点
		parent->right = currentnode;						//父节点右子节点指向当前节点
	}
	return TRUE;	
}*/

/************************************************************************/
/* 访问当前节点内容                                                     */
/* tree:二叉树地址
/* cunrrentnode:当前节点
/* tree:二叉树地址
/************************************************************************/
static void visit(BinaryTree_t *tree, BinaryTreeNode_t *currentnode)
{
	long value = void2long(currentnode->dat, tree->datlen);
	printf("%d ",value);
}

/************************************************************************/
/* 前序周游二叉树                                                       */
/************************************************************************/
void BinaryTree_PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		visit(tree, root);							//访问当前节点
		BinaryTree_PreOrder(tree, root->left);		//前序周游左子树
		BinaryTree_PreOrder(tree, root->right);		//前序周游右子树
	}
}
/************************************************************************/
/* 中序周游二叉树                                                       */
/************************************************************************/
void BinaryTree_InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		BinaryTree_InOrder(tree, root->left);		//中序周游左子树
		visit(tree, root);							//访问当前节点
		BinaryTree_InOrder(tree, root->right);		//中序周游右子树
	}
}
/************************************************************************/
/* 后序周游二叉树                                                       */
/************************************************************************/
void BinaryTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		BinaryTree_PostOrder(tree, root->left);		//后序周游左子树
		BinaryTree_PostOrder(tree, root->right);	//后序周游右子树
		visit(tree, root);							//访问当前节点
	}
}
/************************************************************************/
/* 前序周游二叉树,非递归方法                                            */
/************************************************************************/
void BinaryTree_PreOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t pointertemp;
	LinkStack_t temp;									//定义栈变量
	LinkStack_Create(&temp, sizeof(BinaryTreeNode_t));	//创建栈

	while(pointer || !LinkStack_IsEmpty(&temp))			//栈非空
	{
		visit(tree, pointer);							//访问当前节点
		if(pointer->right != NULL)						//非空右子节点入栈
			LinkStack_Push(&temp, pointer->right);
		if(pointer->left != NULL)						
			pointer = pointer->left;					//左路下降
		else
		{
			if(LinkStack_Pop(&temp, &pointertemp))		//栈顶元素退栈
				pointer = pointertemp.parent->right;	//被压栈的是右节点
			else
				pointer = NULL;
		}
	}
	LinkStack_Destroy(&temp);
}
/************************************************************************/
/* 中序周游二叉树,非递归方法                                            */
/************************************************************************/
void BinaryTree_InOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t pointertemp;
	LinkStack_t temp;									//定义栈变量
	LinkStack_Create(&temp, sizeof(BinaryTreeNode_t));	//创建栈

	while(pointer || !LinkStack_IsEmpty(&temp))			//栈非空
	{
		if(pointer)
		{
			LinkStack_Push(&temp, pointer);
			pointer = pointer->left;					//左路下降
		}
		else
		{
			if(LinkStack_Pop(&temp, &pointertemp))		//栈顶元素退栈
			{
				visit(tree, &pointertemp);				//访问当前节点
				pointer = pointertemp.right;			//指针指向右子节点
			}
			else
				pointer = NULL;
		}
	}
	LinkStack_Destroy(&temp);
}
/************************************************************************/
/* 后序周游二叉树,非递归方法                                            */
/************************************************************************/
void BinaryTree_PostOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t *q = NULL;
	BinaryTreeNode_t pointertemp;
	LinkStack_t temp;									//定义栈变量
	LinkStack_Create(&temp, sizeof(BinaryTreeNode_t));	//创建栈
	if(root == NULL)									//空树则返回
		return;
	else
		pointer = root;
	while(pointer || !LinkStack_IsEmpty(&temp))			//栈非空
	{
		while(pointer != NULL)							//如果当前指针非空，则压栈并下降到最左子节点
		{					
			LinkStack_Push(&temp, pointer);				
			pointer = pointer->left;					//从左路下降
		}
		LinkStack_GetTop(&temp, &pointertemp);			//左路下降到底，取栈顶元素
		if(pointertemp.parent == NULL)					//考虑根节点父节点为空的情况
			pointer = root;
		else if(pointertemp.parent->left)				//考虑栈顶节点父节点无左节点的情况，则必然栈顶节点必然是父节点的右节点
			pointer = pointertemp.parent->left;			
		else
			pointer = pointertemp.parent->right;
		if(pointer->right == NULL || pointer->right == q)//从右子树返回
		{
			visit(tree, pointer);
			/* 1.如果取出的节点右节点为空（对应页节点的情况） */
			/* 2.如果取出的节点右节点等于q（对应右子节点已经遍历过的情况） */
			/* 上述两种情况都需要将本节点弹出栈 */
			LinkStack_Pop(&temp, &pointertemp);				
			q = pointer;
			pointer = NULL;
		}
		else											//如果从右子树返回
		{
			pointer = pointer->right;					//从左子树返回，访问右子树
		}
	}
	LinkStack_Destroy(&temp);
}
/************************************************************************/
/* 广度周游二叉树                                                       */
/************************************************************************/
void BinaryTree_LevelOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t pointertemp, *q = NULL;
	LinkQueue_t queue;
	LinkQueue_Create(&queue, sizeof(BinaryTreeNode_t));	//创建队列
	if(pointer != NULL)
	{
		LinkQueue_En(&queue, pointer);					//根节点入队列
	}
	while(!LinkQueue_IsEmpty(&queue))					//队列非空
	{
		LinkQueue_De(&queue, &pointertemp);
		/* 由于LinkQueue_De弹出数据不包含节点本身地址信息 */
		/* 所以要判断出弹出节点的地址，以便后续循环 */
		if(pointertemp.parent == NULL)					//考虑出队列节点是根节点的情况
			pointer = root;
		/* q保存左子节点 */
		/* 还要考虑节点没有左节点的情况 */
		else if(pointertemp.parent->left == q || pointertemp.parent->left == NULL)
		{
			pointer = pointertemp.parent->right;
			q = NULL;
		}
		else
		{
			pointer = pointertemp.parent->left;
			q = pointer;
		}
		visit(tree, pointer);							//访问当前节点
		if(pointer->left != NULL)
			LinkQueue_En(&queue,pointer->left);			//左子树进队列
		if(pointer->right != NULL)
			LinkQueue_En(&queue,pointer->right);		//右子树进队列
	}
	LinkQueue_Destroy(&queue);
}

/******************************************** 二叉搜索树 *******************************************************/
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
	BinaryTreeNode_t *temp;
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
	newpointer->left = NULL;
	newpointer->right = NULL;
	newpointer->parent = NULL;
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
				temp = pointer->left;
				pointer->left = newpointer;					//newpointer作为pointer左子树
				newpointer->parent = pointer;
				newpointer->left = temp;
				return TRUE;
			}
			else
				pointer = pointer->left;					//向左下降
		}
		else if(newvalue > pointervalue)
		{
			if(pointer->right == NULL)						//如果pointer没有右子树
			{
				temp = pointer->right;
				pointer->right = newpointer;				//newpointer作为pointer右子树
				newpointer->parent = pointer;
				newpointer->right = temp;
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
	printf("此二叉树中不存在此值！\r\n");
	return NULL;
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
/* 前序周游二叉树                                                       */
/************************************************************************/
void BinarySearchTree_PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PreOrder(tree, root);
}
/************************************************************************/
/* 中序周游二叉树                                                       */
/************************************************************************/
void BinarySearchTree_InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_InOrder(tree, root);
}
/************************************************************************/
/* 后序周游二叉树                                                       */
/************************************************************************/
void BinarySearchTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PostOrder(tree, root);
}
/************************************************************************/
/* 前序周游二叉树,非递归方法                                            */
/************************************************************************/
void BinarySearchTree_PreOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PreOrderNonRecursion(tree, root);
}
/************************************************************************/
/* 中序周游二叉树,非递归方法                                            */
/************************************************************************/
void BinarySearchTree_InOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_InOrderNonRecursion(tree, root);
}
/************************************************************************/
/* 后序周游二叉树,非递归方法                                            */
/************************************************************************/
void BinarySearchTree_PostOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PostOrderNonRecursion(tree, root);
}
/************************************************************************/
/* 广度周游二叉树                                                       */
/************************************************************************/
void BinarySearchTree_LevelOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_LevelOrder(tree, root);
}

void testBinaryTree(void)
{
	unsigned char i=0;
	BinaryTree_t root;
	int val[10] = {0,1,2,3,4,5,6,7,8,9};
	int tempval;
	BinaryTreeNode_t *temp;//临时节点

	if(!BinaryTree_Create(&root, sizeof(val[0]), &val[9]))//创建二叉树
	{
		printf("创建二叉树失败\r\n");
		return;
	}

	for(i = 0;i<3;i++)//插入10个节点，按照二叉搜索树的形式排列大小
	//for(i = 4;i>0;i--)//插入10个节点，按照二叉搜索树的形式排列大小
	{
		tempval = i+1;
		BinarySearchTree_InsertNode(&root, &tempval);
	}
	printf("\r\n中序遍历：\r\n");
	BinarySearchTree_InOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_InOrderNonRecursion(&root, root.root);

	printf("\r\n前序遍历：\r\n");
	BinarySearchTree_PreOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_PreOrderNonRecursion(&root, root.root);

	printf("\r\n后序遍历：\r\n");
	BinarySearchTree_PostOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_PostOrderNonRecursion(&root, root.root);

	printf("\r\n广度周游：\r\n");
	BinaryTree_LevelOrder(&root, root.root);
	printf("\r\n\r\n");

	if(NULL != (temp = BinarySearchTree_SearchNode(&root, &val[1])))
		BinarySearchTree_DeleteNode(&root, temp);//删除节点
	printf("中序遍历：\r\n");
	BinarySearchTree_InOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_InOrderNonRecursion(&root, root.root);
}