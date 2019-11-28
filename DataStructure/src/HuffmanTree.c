#include <stdio.h>
#include <malloc.h>
#include "HuffmanTree.h"

/************************************************************************/
/*�Ը�iΪ�����½��е���                                                 */
/*left:��left��ʼ����ɸѡ
/*���أ���
/************************************************************************/
static void SiftDown(HeapHuffmanTree *heap,int left)
{
	int i = left;							//��left��ʼ����ɸѡ
	int j = 2*i+1;							//i�����ӽڵ�
	HuffmanTree temp = heap->node[i];		//���游�ڵ�

	while(j < heap->CurrentSize)			//�ڵ���С�ڵ�ǰ��С
	{
		if((j < heap->CurrentSize-1) && (heap->node[j].val.val > heap->node[j+1].val.val))//�������ӽڵ㣬�����ӽڵ�С�����ӽڵ�
			j++;							//jָ�����ӽڵ�
		if(temp.val.val > heap->node[j].val.val)	//���ڵ�����ӽڵ�,����λ��
		{
			heap->node[i] = heap->node[j];
			i = j;
			j = 2*i+1;						//���������ߣ����ӽڵ�
		}
		else
			break;							//����������ʱ�˳�
	}
	heap->node[i] = temp;
}

/************************************************************************/
/*���Ͻ��е���                                                 */
/*heap:�ѽṹ��
/*���أ���
/************************************************************************/
static void SiftUp(HeapHuffmanTree *heap,int pos)
{
	int position = pos;							//�ӵ�ǰ��Сλ�ÿ�ʼ���ϵ���
	HuffmanTree temp = heap->node[position];	//���浱ǰֵ
	while((position > 0) && (heap->node[(position-1)/2].val.val > temp.val.val))//δ���������ڵ㣬�Ҹ��ڵ�ȵ�ǰ�ڵ��
	{
		heap->node[position] = heap->node[(position-1)/2];
		position = (position-1)/2;			//���������ڵ�λ��
	}
	heap->node[position] = temp;
}


/************************************************************************/
/*������С�ѽṹ���նѣ�����ֵ������ֵ��MinHeapInsert��������
/*data:������
/*heap:�ѽṹ����
/*size:���ݴ�С
/*���أ���
/************************************************************************/
static void BuildMinHeap(HeapHuffmanTree *heap,int maxsize)
{
//	int i;
	if(maxsize<=0)												//���������ռ�������0
		return;
	heap->MaxSize = maxsize;									//���������
	heap->node = (HuffmanTree *)malloc(heap->MaxSize*sizeof(HuffmanTree));//����maxsize���ռ��С
	heap->CurrentSize = 0;										//��ǰ����Ԫ�ظ���������
	//for(i=0;i<heap->CurrentSize;i++)							//���ݸ�ֵ
	//	heap->node[i].val.val = data[i];

	//for(i = heap->CurrentSize/2-1;i>=0;i--)						//ɸѡ�����ѣ���n/2-1��ʼ
	//{
	//	SiftDown(heap,i);
	//}
}

/************************************************************************/
/*�����½ڵ�                                                       */
/*node:�½ڵ�ֵ
/*heap:�ѽṹ����
/*���أ�
/************************************************************************/
static bool MinHeapInsert(HeapHuffmanTree *heap,HuffmanTree node)
{
	if(heap->CurrentSize == heap->MaxSize)						//���������������false
		return FALSE;
	heap->node[heap->CurrentSize] = node;
	SiftUp(heap,heap->CurrentSize);							//���ϵ���
	heap->CurrentSize++;										//��ǰ��С��1

	return TRUE;
}

/************************************************************************/
/*�ӶѶ�ɾ����Сֵ                                                       */
/*heap:�ѽṹ����
/*���أ�������Сֵ
/************************************************************************/
static HuffmanTree MinHeapRemoveMin(HeapHuffmanTree *heap)
{
	HuffmanTree temp;
	if(0 == heap->CurrentSize)									//��ǰ��СΪ0���޷�ɾ��
	{
		printf("��ǰ�Ѵ�СΪ0���޷�ɾ��\r\n");
		return;
	}
	else
	{
		heap->CurrentSize--;									//��ǰ��С��1

		temp = heap->node[0];									//�����Ѷ��Ͷ�ĩβԪ��
		heap->node[0] = heap->node[heap->CurrentSize];
		heap->node[heap->CurrentSize] = temp;

		if(heap->CurrentSize > 1)								//��ǰ��С����1���ӶѶ���ʼ����ɸѡ����
			SiftDown(heap,0);
		return (heap->node[heap->CurrentSize]);
	}
}

/************************************************************************/
/*���ٶ�                                                       */
/*heap:�ѽṹ����
/*���أ���
/************************************************************************/
static void DeleteMinHeap(HeapHuffmanTree *heap)
{
	int i=0;
	HuffmanTree *temp=NULL;
	if(heap->MaxSize<0)
		return;

	temp = heap->node;
	free(temp);				//�ͷ��ڴ�,ֱ�ӵ���free���ܰ����пռ��ͷ�
	temp = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*����Huffman��
/*weight:Ȩֵ����
/*n:Ԫ������
/*���أ�HuffmanTree����ָ��
/*���ڹ���������û�ж�Ϊ1�Ľ�㣬��һ����n��Ҷ�ӵĹ�����������2��n-1����㣬
/*������һ����СΪ2��n-1 ��һά�����Ź��������ĸ�����㡣 ����ÿ�����ͬʱ
/*��������˫����Ϣ�ͺ��ӽ�����Ϣ�����Թ���һ����̬��������
/************************************************************************/
HuffmanTree* BulidHuffmanTree(float *weight,int n)
{
	int i=0;
	int m = 2*n-1;								//Huffman���нڵ�����
	HuffmanTree *parent;						//���ڵ㣬�ϲ�ʱʹ�ã��¿��ٵĿռ���Ǹ��ڵ�;rootΪ���ڵ㣬������󷵻�
	HuffmanTree firstchild,secondchild;			//��ŴӶ��е����İ�����Сֵ�Ľڵ������ֵ
	HuffmanTree* huffmantree = (HuffmanTree *)malloc(n*sizeof(HuffmanTree));//�ȿ���n��HuffmanTreeNode�ṹ���С�����ռ䣬��ΪҶ�ڵ�

	HeapHuffmanTree heap;						//����һ���ѽṹ����
	BuildMinHeap(&heap,n);						//����һ���յ���С�ѣ�����ȡ��Сֵ

	for(i = 0;i<n;i++)							//��ʼ��n���ڵ㻥����������Ǹ��ڵ�
	{
		huffmantree[i].left = NULL;
		huffmantree[i].right = NULL;
		huffmantree[i].parent = NULL;	
		huffmantree[i].val.val = weight[i];							//Ȩֵ��ʼ��
		MinHeapInsert(&heap,huffmantree[i]);						//��ǰ�ڵ������У�����
	}
	printf("���ԣ������ʾ�ѣ�");
	for(i=0;i<heap.CurrentSize;i++)
		printf("%f ",heap.node[i].val.val);
	printf("\r\n");

	for(i=0;i<n-1;i++)												//ͨ��n-1�κϲ��õ�Huffman����n��Ҷ�ڵ����,
	{
		parent = (HuffmanTree*)malloc(sizeof(HuffmanTree));			//ǰ���Ѿ�������n���ռ�,������n-1����һ����2*n-1���ڵ�
		
		firstchild = MinHeapRemoveMin(&heap);						//ȡ������СȨֵ�Ľڵ�,firstchild�ڵ���ֵ<=secondchild�ڵ��е�ֵ
		secondchild = MinHeapRemoveMin(&heap);

		/*��������if�����Ϊ���ж϶����������ڵ��ǲ���Ҷ�ڵ㣬�����Ҷ�ڵ�����������ռ�huffmantree��*/
		if(firstchild.left == NULL && firstchild.right == NULL)		//�����ӽڵ㶼�ǿգ�˵������Ҷ�ڵ�
		{
			//huffmantree->left = firstchild.left;					//�����ӽڵ㲻�ø�ֵ�ˣ�ǰ���ʼ����ʱ��ֵ���ˣ���ָ��NULL
			//huffmantree->right = firstchild.right;
			huffmantree->parent = parent;
			parent->left = huffmantree;								//���ڵ�����ӽڵ�ָ��ǰ
			huffmantree->val.val = firstchild.val.val;
			huffmantree ++;											//ָ����һ��Ҷ�ڵ�
		}
		else														//����ӽڵ㲻�ǿգ�˵���䲻��Ҷ�ڵ�,�����Ǳ��Ҷ�ڵ�ĸ��ڵ�
		{
			firstchild.left->parent->parent = parent;				//firstchild.left->parent�����䱾���ַ
			parent->left = firstchild.left->parent;					//���ڵ�����ӽڵ�ָ���Լ�
		}
		if(secondchild.left == NULL && secondchild.right == NULL)	//�����ӽڵ㶼�ǿգ�˵������Ҷ�ڵ�
		{
			//huffmantree->left = secondchild.left;					//�����ӽڵ㲻�ø�ֵ�ˣ�ǰ���ʼ����ʱ��ֵ���ˣ���ָ��NULL
			//huffmantree->right = secondchild.right;
			huffmantree->parent = parent;
			parent->right = huffmantree;							//���ڵ�����ӽڵ�ָ��ǰ
			huffmantree->val.val = secondchild.val.val;
			huffmantree ++;											//ָ����һ��Ҷ�ڵ�
		}
		else
		{
			secondchild.right->parent->parent = parent;				//firstchild.left->parent�����䱾���ַ
			parent->right = secondchild.right->parent;				//���ڵ�����ӽڵ�ָ���Լ�
		}

		parent->parent = NULL;										//���ڵ�ĸ��ڵ�ָ���
		parent->val.val = firstchild.val.val+secondchild.val.val;
		MinHeapInsert(&heap,*parent);								//�����ڵ��ٷ����������
	}
	DeleteMinHeap(&heap);											//������С�ѣ��ͷ��ڴ�
	return parent;													//�������ĸ��ڵ㣬����Huffman���ĸ��ڵ�	
}

/************************************************************************/
/* ��ӡֵ                                                       */
/************************************************************************/
static visit(HuffmanTree *root)
{
	printf("%f ",root->val.val);
}
/************************************************************************/
/* ǰ�����ζ�����                                                       */
/************************************************************************/
void PreOrderHuffmanTree(HuffmanTree *root)
{
	if(root != NULL)
	{
		visit(root);							//���ʵ�ǰ�ڵ�
		PreOrderHuffmanTree(root->left);		//ǰ������������
		PreOrderHuffmanTree(root->right);		//ǰ������������
	}
}
/************************************************************************/
/*����Ȩֵ��·���˻�,���·��(δ���3)
/*
/*n:Ҷ�ڵ㣬��Ȩֵ����
/************************************************************************/
void path(HuffmanTree *huffmantree,int n)
{
	//HuffmanTree *temp;
	//printf("\r\n");
	//while(n--)
	//{
	//	temp = huffmantree;								//��λ�����ڵ�
	//	while(temp!=NULL)								//δ����Ҷ�ڵ�֮ǰһֱѭ��
	//	{
	//		printf("%f ",temp->val.val);				//�����ǰ�ڵ�
	//		temp = temp->left;
	//	}
	//	printf("\r\n");
	//}
	
}



void testHuffmanTree()
{
	float weight[10]={10,20,30,40,50,45,35,25,15,5};//Ȩֵ
	int n =10;										//��Ȩ������һ��
	HuffmanTree * huffmantree;						//����
	huffmantree = BulidHuffmanTree(weight,n);		//����hufffman��

	path(huffmantree,n);
	printf("\r\nǰ�����\r\n");
	PreOrderHuffmanTree(huffmantree);
}