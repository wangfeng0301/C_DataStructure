#ifndef __HEAP_H__
#define __HEAP_H__

//重定义数据类型
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;

/*堆结构体*/
typedef struct 
{
	int *heapArray;									//存放堆数据的数组
	int CurrentSize;								//当前堆中元素数目
	int MaxSize;									//堆的最大元素数目
}Heap;

void BuildMinHeap(Heap *heap,int *data,int size);	//建立最小堆结构
bool MinHeapInsert(Heap *heap,int node);			//插入新节点
int MinHeapRemoveMin(Heap *heap);					//删除堆顶，即最小值
void testHeap();


#endif