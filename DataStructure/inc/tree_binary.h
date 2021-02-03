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

bool BinaryTree_Create(BinaryTree_t *tree, uint datlen);

void LevelOrder(BinaryTreeNode_t *root);//������ζ�����
void testBinaryTree(void);


#endif