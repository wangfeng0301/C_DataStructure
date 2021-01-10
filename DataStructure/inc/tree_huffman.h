#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__
#include "type.h"

typedef enum						//枚举类型，标志位
{
	Left = 0,
	Right
}Flag;

typedef struct 
{
	float val;						//节点数据
//	Flag tag;						//标志位
}ValueType;

typedef struct HuffmanTreeNode
{		
	ValueType val;					//数据	
	struct HuffmanTreeNode *left;	//左子节点指针
	struct HuffmanTreeNode *right;	//右子节点指针
	struct HuffmanTreeNode *parent;	//指向父节点指针
}HuffmanTree;

typedef struct
{
//	float *heapArray;				//存放堆数据的数组
	int CurrentSize;				//当前堆中元素数目
	int MaxSize;					//堆的最大元素数目
	HuffmanTree *node;				//HuffmanTree
}HeapHuffmanTree;

void testHuffmanTree(void);


#endif