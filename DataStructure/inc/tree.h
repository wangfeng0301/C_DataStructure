#ifndef __TREE_H__
#define __TREE_H__

//�ض�����������
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;

//typedef enum						//ö�����ͣ���־λ
//{
//	Left = 0,
//	Right
//}Flag;
//typedef struct 
//{
//	int val;						//�ڵ�����
//	Flag tag;						//��־λ�����ڷǵݹ��������
//}ValueType;
//typedef struct TreeNode
//{		
//	ValueType val;					//����	
//	struct TreeNode *left;			//���ӽڵ�ָ��
//	struct TreeNode *right;			//���ӽڵ�ָ��
//	struct TreeNode *parent;		//ָ�򸸽ڵ�ָ��
//}TreeNode;
//
//void LevelOrder(TreeNode *root);	//������ζ�����
void testTree();


#endif