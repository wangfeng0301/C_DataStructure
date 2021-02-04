#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "type.h"

typedef enum						//ö�����ͣ���־λ
{
	Left = 0,
	Right
}Flag;
typedef struct 
{
	int val;						//�ڵ�����
	Flag tag;						//��־λ�����ڷǵݹ��������
}ValueType_t;
typedef struct BinaryTreeNode
{		
	//ValueType_t val;				//����	
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

bool BinarySearchTree_InsertNode(BinaryTree_t *tree, void *dat);
BinaryTreeNode_t* BinarySearchTree_SearchNode(BinaryTree_t *tree, void *dat);
bool BinarySearchTree_DeleteNode(BinaryTree_t *tree, BinaryTreeNode_t *pointer);

void LevelOrder(BinaryTreeNode_t *root);//������ζ�����
void testBinaryTree(void);


#endif