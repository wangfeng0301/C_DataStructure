#ifndef __HEAP_H__
#define __HEAP_H__
#include "type.h"
/*堆结构体*/
typedef struct 
{
	int *array;			//存放堆数据的数组
	int currsize;		//当前堆中元素数目
	int maxsize;		//堆的最大元素数目
}Heap_t;

bool MinHeap_IsFull(Heap_t *heap);
bool MinHeap_IsEmpty(Heap_t *heap);
void MinHeap_SiftDown(Heap_t *heap, int parent);
void MinHeap_SiftUp(Heap_t *heap, int pos);
bool MinHeap_Create(Heap_t *heap, int *data, int size, int maxsize);
bool MinHeap_Insert(Heap_t *heap,int node);
bool MinHeap_RemoveMin(Heap_t *heap, int *node);
bool MinHeap_Remove(Heap_t *heap, int *node, int pos);
void MinHeap_Traverse(Heap_t *heap);
void MinHeap_Destroy(Heap_t *heap);

bool MaxHeap_IsFull(Heap_t *heap);
bool MaxHeap_IsEmpty(Heap_t *heap);
void MaxHeap_SiftDown(Heap_t *heap, int parent);
void MaxHeap_SiftUp(Heap_t *heap, int pos);
bool MaxHeap_Create(Heap_t *heap, int *data, int size, int maxsize);
bool MaxHeap_Insert(Heap_t *heap,int node);
bool MaxHeap_RemoveMin(Heap_t *heap, int *node);
bool MaxHeap_Remove(Heap_t *heap, int *node, int pos);
void MaxHeap_Traverse(Heap_t *heap);
void MaxHeap_Destroy(Heap_t *heap);


void testHeap(void);

#endif