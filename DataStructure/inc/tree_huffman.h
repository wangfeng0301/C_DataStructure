#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__
#include "type.h"

typedef enum						//ö�����ͣ���־λ
{
	Left = 0,
	Right
}Flag;

typedef struct 
{
	float val;						//�ڵ�����
//	Flag tag;						//��־λ
}ValueType;

typedef struct HuffmanTreeNode
{		
	ValueType val;					//����	
	struct HuffmanTreeNode *left;	//���ӽڵ�ָ��
	struct HuffmanTreeNode *right;	//���ӽڵ�ָ��
	struct HuffmanTreeNode *parent;	//ָ�򸸽ڵ�ָ��
}HuffmanTree;

typedef struct
{
//	float *heapArray;				//��Ŷ����ݵ�����
	int CurrentSize;				//��ǰ����Ԫ����Ŀ
	int MaxSize;					//�ѵ����Ԫ����Ŀ
	HuffmanTree *node;				//HuffmanTree
}HeapHuffmanTree;

void testHuffmanTree(void);


#endif