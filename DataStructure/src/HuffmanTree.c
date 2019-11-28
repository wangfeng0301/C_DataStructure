#include <stdio.h>
#include <malloc.h>
#include "HuffmanTree.h"

/************************************************************************/
/*以根i为根向下进行调整                                                 */
/*left:从left开始向下筛选
/*返回：无
/************************************************************************/
static void SiftDown(HeapHuffmanTree *heap,int left)
{
	int i = left;							//从left开始向下筛选
	int j = 2*i+1;							//i的左子节点
	HuffmanTree temp = heap->node[i];		//保存父节点

	while(j < heap->CurrentSize)			//节点编号小于当前大小
	{
		if((j < heap->CurrentSize-1) && (heap->node[j].val.val > heap->node[j+1].val.val))//若有右子节点，且右子节点小于左子节点
			j++;							//j指向右子节点
		if(temp.val.val > heap->node[j].val.val)	//父节点大于子节点,交换位置
		{
			heap->node[i] = heap->node[j];
			i = j;
			j = 2*i+1;						//继续向下走，左子节点
		}
		else
			break;							//堆序性满足时退出
	}
	heap->node[i] = temp;
}

/************************************************************************/
/*向上进行调整                                                 */
/*heap:堆结构体
/*返回：无
/************************************************************************/
static void SiftUp(HeapHuffmanTree *heap,int pos)
{
	int position = pos;							//从当前大小位置开始向上调整
	HuffmanTree temp = heap->node[position];	//保存当前值
	while((position > 0) && (heap->node[(position-1)/2].val.val > temp.val.val))//未调整到根节点，且父节点比当前节点大
	{
		heap->node[position] = heap->node[(position-1)/2];
		position = (position-1)/2;			//调整到父节点位置
	}
	heap->node[position] = temp;
}


/************************************************************************/
/*建立最小堆结构，空堆，不赋值。插入值在MinHeapInsert函数进行
/*data:堆数据
/*heap:堆结构变量
/*size:数据大小
/*返回：无
/************************************************************************/
static void BuildMinHeap(HeapHuffmanTree *heap,int maxsize)
{
//	int i;
	if(maxsize<=0)												//堆数据最大空间必须大于0
		return;
	heap->MaxSize = maxsize;									//堆最大容量
	heap->node = (HuffmanTree *)malloc(heap->MaxSize*sizeof(HuffmanTree));//开辟maxsize个空间大小
	heap->CurrentSize = 0;										//当前堆中元素个数，清零
	//for(i=0;i<heap->CurrentSize;i++)							//数据赋值
	//	heap->node[i].val.val = data[i];

	//for(i = heap->CurrentSize/2-1;i>=0;i--)						//筛选法建堆，从n/2-1开始
	//{
	//	SiftDown(heap,i);
	//}
}

/************************************************************************/
/*插入新节点                                                       */
/*node:新节点值
/*heap:堆结构变量
/*返回：
/************************************************************************/
static bool MinHeapInsert(HeapHuffmanTree *heap,HuffmanTree node)
{
	if(heap->CurrentSize == heap->MaxSize)						//如果堆已满，返回false
		return FALSE;
	heap->node[heap->CurrentSize] = node;
	SiftUp(heap,heap->CurrentSize);							//向上调整
	heap->CurrentSize++;										//当前大小加1

	return TRUE;
}

/************************************************************************/
/*从堆顶删除最小值                                                       */
/*heap:堆结构变量
/*返回：堆中最小值
/************************************************************************/
static HuffmanTree MinHeapRemoveMin(HeapHuffmanTree *heap)
{
	HuffmanTree temp;
	if(0 == heap->CurrentSize)									//当前大小为0，无法删除
	{
		printf("当前堆大小为0，无法删除\r\n");
		return;
	}
	else
	{
		heap->CurrentSize--;									//当前大小减1

		temp = heap->node[0];									//交换堆顶和堆末尾元素
		heap->node[0] = heap->node[heap->CurrentSize];
		heap->node[heap->CurrentSize] = temp;

		if(heap->CurrentSize > 1)								//当前大小大于1，从堆顶开始向下筛选排序
			SiftDown(heap,0);
		return (heap->node[heap->CurrentSize]);
	}
}

/************************************************************************/
/*销毁堆                                                       */
/*heap:堆结构变量
/*返回：无
/************************************************************************/
static void DeleteMinHeap(HeapHuffmanTree *heap)
{
	int i=0;
	HuffmanTree *temp=NULL;
	if(heap->MaxSize<0)
		return;

	temp = heap->node;
	free(temp);				//释放内存,直接调用free就能把所有空间释放
	temp = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*建立Huffman树
/*weight:权值数组
/*n:元素数量
/*返回：HuffmanTree类型指针
/*由于哈夫曼树中没有度为1的结点，则一棵有n个叶子的哈夫曼树共有2×n-1个结点，
/*可以用一个大小为2×n-1 的一维数组存放哈夫曼树的各个结点。 由于每个结点同时
/*还包含其双亲信息和孩子结点的信息，所以构成一个静态三叉链表。
/************************************************************************/
HuffmanTree* BulidHuffmanTree(float *weight,int n)
{
	int i=0;
	int m = 2*n-1;								//Huffman树中节点数量
	HuffmanTree *parent;						//父节点，合并时使用，新开辟的空间就是父节点;root为根节点，用于最后返回
	HuffmanTree firstchild,secondchild;			//存放从堆中弹出的包含最小值的节点的所有值
	HuffmanTree* huffmantree = (HuffmanTree *)malloc(n*sizeof(HuffmanTree));//先开辟n个HuffmanTreeNode结构体大小连续空间，作为叶节点

	HeapHuffmanTree heap;						//定义一个堆结构变量
	BuildMinHeap(&heap,n);						//建立一个空的最小堆，方便取最小值

	for(i = 0;i<n;i++)							//初始化n个节点互相独立，都是根节点
	{
		huffmantree[i].left = NULL;
		huffmantree[i].right = NULL;
		huffmantree[i].parent = NULL;	
		huffmantree[i].val.val = weight[i];							//权值初始化
		MinHeapInsert(&heap,huffmantree[i]);						//当前节点放入堆中，排序
	}
	printf("测试，输出显示堆：");
	for(i=0;i<heap.CurrentSize;i++)
		printf("%f ",heap.node[i].val.val);
	printf("\r\n");

	for(i=0;i<n-1;i++)												//通过n-1次合并得到Huffman树，n是叶节点个数,
	{
		parent = (HuffmanTree*)malloc(sizeof(HuffmanTree));			//前面已经开辟了n个空间,加上这n-1个，一共是2*n-1个节点
		
		firstchild = MinHeapRemoveMin(&heap);						//取两个最小权值的节点,firstchild节点中值<=secondchild节点中的值
		secondchild = MinHeapRemoveMin(&heap);

		/*下面两个if语句是为了判断读出的两个节点是不是叶节点，如果是叶节点则放在连续空间huffmantree中*/
		if(firstchild.left == NULL && firstchild.right == NULL)		//左右子节点都是空，说明其是叶节点
		{
			//huffmantree->left = firstchild.left;					//左右子节点不用赋值了，前面初始化的时候赋值过了，都指向NULL
			//huffmantree->right = firstchild.right;
			huffmantree->parent = parent;
			parent->left = huffmantree;								//父节点的左子节点指向当前
			huffmantree->val.val = firstchild.val.val;
			huffmantree ++;											//指向下一个叶节点
		}
		else														//如果子节点不是空，说明其不是叶节点,且其是别的叶节点的父节点
		{
			firstchild.left->parent->parent = parent;				//firstchild.left->parent就是其本身地址
			parent->left = firstchild.left->parent;					//父节点的左子节点指向自己
		}
		if(secondchild.left == NULL && secondchild.right == NULL)	//左右子节点都是空，说明其是叶节点
		{
			//huffmantree->left = secondchild.left;					//左右子节点不用赋值了，前面初始化的时候赋值过了，都指向NULL
			//huffmantree->right = secondchild.right;
			huffmantree->parent = parent;
			parent->right = huffmantree;							//父节点的右子节点指向当前
			huffmantree->val.val = secondchild.val.val;
			huffmantree ++;											//指向下一个叶节点
		}
		else
		{
			secondchild.right->parent->parent = parent;				//firstchild.left->parent就是其本身地址
			parent->right = secondchild.right->parent;				//父节点的左子节点指向自己
		}

		parent->parent = NULL;										//父节点的父节点指向空
		parent->val.val = firstchild.val.val+secondchild.val.val;
		MinHeapInsert(&heap,*parent);								//将父节点再放入堆中排序
	}
	DeleteMinHeap(&heap);											//销毁最小堆，释放内存
	return parent;													//返回最后的父节点，就是Huffman树的根节点	
}

/************************************************************************/
/* 打印值                                                       */
/************************************************************************/
static visit(HuffmanTree *root)
{
	printf("%f ",root->val.val);
}
/************************************************************************/
/* 前序周游二叉树                                                       */
/************************************************************************/
void PreOrderHuffmanTree(HuffmanTree *root)
{
	if(root != NULL)
	{
		visit(root);							//访问当前节点
		PreOrderHuffmanTree(root->left);		//前序周游左子树
		PreOrderHuffmanTree(root->right);		//前序周游右子树
	}
}
/************************************************************************/
/*计算权值与路径乘积,输出路径(未完成3)
/*
/*n:叶节点，即权值个数
/************************************************************************/
void path(HuffmanTree *huffmantree,int n)
{
	//HuffmanTree *temp;
	//printf("\r\n");
	//while(n--)
	//{
	//	temp = huffmantree;								//定位到根节点
	//	while(temp!=NULL)								//未遇到叶节点之前一直循环
	//	{
	//		printf("%f ",temp->val.val);				//输出当前节点
	//		temp = temp->left;
	//	}
	//	printf("\r\n");
	//}
	
}



void testHuffmanTree()
{
	float weight[10]={10,20,30,40,50,45,35,25,15,5};//权值
	int n =10;										//与权重数量一致
	HuffmanTree * huffmantree;						//定义
	huffmantree = BulidHuffmanTree(weight,n);		//构造hufffman树

	path(huffmantree,n);
	printf("\r\n前序遍历\r\n");
	PreOrderHuffmanTree(huffmantree);
}