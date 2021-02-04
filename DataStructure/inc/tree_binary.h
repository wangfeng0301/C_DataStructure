#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "type.h"

typedef enum						//枚举类型，标志位
{
	Left = 0,
	Right
}Flag;
typedef struct 
{
	int val;						//节点数据
	Flag tag;						//标志位，用于非递归后序周游
}ValueType_t;
typedef struct BinaryTreeNode
{		
	//ValueType_t val;				//数据	
	void *dat;						//数据
	struct BinaryTreeNode *left;	//左子节点指针
	struct BinaryTreeNode *right;	//右子节点指针
	struct BinaryTreeNode *parent;	//指向父节点指针
}BinaryTreeNode_t;
typedef struct 
{
	BinaryTreeNode_t *root;			//二叉树根节点
	uint datlen;					//节点数据类型长度
}BinaryTree_t;

bool BinaryTree_IsEmpty(BinaryTree_t *tree);
bool BinaryTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat);
bool BinaryTree_InsertNode(BinaryTree_t *tree, BinaryTreeNode_t *parent, void *dat, unsigned char LeftRight);

bool BinarySearchTree_InsertNode(BinaryTree_t *tree, void *dat);
BinaryTreeNode_t* BinarySearchTree_SearchNode(BinaryTree_t *tree, void *dat);
bool BinarySearchTree_DeleteNode(BinaryTree_t *tree, BinaryTreeNode_t *pointer);

void LevelOrder(BinaryTreeNode_t *root);//广度周游二叉树
void testBinaryTree(void);


#endif