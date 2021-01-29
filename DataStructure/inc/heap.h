#ifndef __HEAP_H__
#define __HEAP_H__
#include "type.h"
/*堆结构体*/
typedef struct 
{
	int *heapArray;									//存放堆数据的数组
	int CurrentSize;								//当前堆中元素数目
	int MaxSize;									//堆的最大元素数目
}Heap_t;

void BuildMinHeap(Heap_t *heap,int *data,int size);	//建立最小堆结构
bool MinHeapInsert(Heap_t *heap,int node);			//插入新节点
int MinHeapRemoveMin(Heap_t *heap);					//删除堆顶，即最小值
void testHeap(void);


#endif