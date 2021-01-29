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
	ValueType_t val;					//数据	
	struct BinaryTreeNode *left;	//左子节点指针
	struct BinaryTreeNode *right;	//右子节点指针
	struct BinaryTreeNode *parent;	//指向父节点指针
}BinaryTreeNode_t;

void LevelOrder(BinaryTreeNode_t *root);//广度周游二叉树
void testBinaryTree(void);


#endif