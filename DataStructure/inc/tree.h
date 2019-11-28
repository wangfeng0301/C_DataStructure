#ifndef __TREE_H__
#define __TREE_H__

//重定义数据类型
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;

//typedef enum						//枚举类型，标志位
//{
//	Left = 0,
//	Right
//}Flag;
//typedef struct 
//{
//	int val;						//节点数据
//	Flag tag;						//标志位，用于非递归后序周游
//}ValueType;
//typedef struct TreeNode
//{		
//	ValueType val;					//数据	
//	struct TreeNode *left;			//左子节点指针
//	struct TreeNode *right;			//右子节点指针
//	struct TreeNode *parent;		//指向父节点指针
//}TreeNode;
//
//void LevelOrder(TreeNode *root);	//广度周游二叉树
void testTree();


#endif