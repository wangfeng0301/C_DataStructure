#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

//�ض�����������
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;

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
void testBinaryTree();


#endif