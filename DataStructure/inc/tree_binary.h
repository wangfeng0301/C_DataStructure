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
	ValueType_t val;					//����	
	struct BinaryTreeNode *left;	//���ӽڵ�ָ��
	struct BinaryTreeNode *right;	//���ӽڵ�ָ��
	struct BinaryTreeNode *parent;	//ָ�򸸽ڵ�ָ��
}BinaryTreeNode_t;

void LevelOrder(BinaryTreeNode_t *root);//������ζ�����
void testBinaryTree(void);


#endif