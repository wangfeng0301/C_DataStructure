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
}ValueType;
typedef struct BinaryTreeNode
{		
	ValueType val;					//����	
	struct BinaryTreeNode *left;	//���ӽڵ�ָ��
	struct BinaryTreeNode *right;	//���ӽڵ�ָ��
	struct BinaryTreeNode *parent;	//ָ�򸸽ڵ�ָ��
}BinaryTreeNode;

void LevelOrder(BinaryTreeNode *root);//������ζ�����
void testBinaryTree(void);


#endif