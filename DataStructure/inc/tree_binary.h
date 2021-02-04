#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "type.h"

typedef struct BinaryTreeNode
{		
	void *dat;						//����
	struct BinaryTreeNode *left;	//���ӽڵ�ָ��
	struct BinaryTreeNode *right;	//���ӽڵ�ָ��
	struct BinaryTreeNode *parent;	//ָ�򸸽ڵ�ָ��
}BinaryTreeNode_t;
typedef struct 
{
	BinaryTreeNode_t *root;			//���������ڵ�
	uint datlen;					//�ڵ��������ͳ���
}BinaryTree_t;

bool BinaryTree_IsEmpty(BinaryTree_t *tree);
bool BinaryTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat);
bool BinaryTree_InsertNode(BinaryTree_t *tree, BinaryTreeNode_t *parent, void *dat, unsigned char LeftRight);
void BinaryTree_PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinaryTree_InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinaryTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinaryTree_PreOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinaryTree_PostOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinaryTree_LevelOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);//������ζ�����

bool BinarySearchTree_InsertNode(BinaryTree_t *tree, void *dat);
BinaryTreeNode_t* BinarySearchTree_SearchNode(BinaryTree_t *tree, void *dat);
bool BinarySearchTree_DeleteNode(BinaryTree_t *tree, BinaryTreeNode_t *pointer);
void BinarySearchTree_PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinarySearchTree_InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinarySearchTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinarySearchTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinarySearchTree_PreOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinarySearchTree_PostOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root);
void BinarySearchTree_LevelOrder(BinaryTree_t *tree, BinaryTreeNode_t *root);//������ζ�����

void testBinaryTree(void);


#endif