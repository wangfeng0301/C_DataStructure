/************************************************************************
 *                 堆                                 
 *利用完全二叉树线性表存储堆数据
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *2019.11.29-2021.1.29
************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "heap.h"

static void SiftDown(Heap_t *heap,int left);			//向下筛选
static void SiftUp(Heap_t *heap,int pos);				//向上筛选
void BuildMinHeap(Heap_t *heap,int *data,int size);	//建立最小堆结构
bool MinHeapInsert(Heap_t *heap,int node);			//插入新节点
int MinHeapRemoveMin(Heap_t *heap);					//删除堆顶，即最小值
static int MinHeapRemove(Heap_t *heap,int pos);		//删除指定下标的元素

/************************************************************************/
/*以parent为根向下进行调整,即大数放在下面                               */
/*parent:父节点编号，从此节点开始调整
/*返回：无
/************************************************************************/
static void SiftDown(Heap_t *heap,int parent)
{
	int child = 2*parent + 1;						//父节点的左子节点编号
	int temp = heap->heapArray[parent];				//保存父节点

	while(child < heap->CurrentSize)				//节点编号小于当前大小
	{
		if((child < heap->CurrentSize-1) && (heap->heapArray[child] > heap->heapArray[child+1]))//若有右子节点，且右子节点小于左子节点
			child++;								//child指向右子节点
		if(temp > heap->heapArray[child])			//父节点大于子节点,交换位置
		{
			heap->heapArray[parent] = heap->heapArray[child];
			parent = child;
			child = 2*parent+1;						//继续向下走，左子节点
		}
		else
			break;									//堆序性满足时退出
	}
	heap->heapArray[parent] = temp;
}

/************************************************************************/
/*向上进行调整                                                 */
/*heap:堆结构体
/*返回：无
/************************************************************************/
static void SiftUp(Heap_t *heap,int pos)
{
	int position = pos;								//从当前大小位置开始向上调整
	int temp = heap->heapArray[position];			//保存当前值
	while((position > 0) && (heap->heapArray[(position-1)/2] > temp))//未调整到根节点，且父节点比当前节点大
	{
		heap->heapArray[position] = heap->heapArray[(position-1)/2];
		position = (position-1)/2;					//调整到父节点位置
	}
	heap->heapArray[position] = temp;
}


/************************************************************************/
/*建立最小堆结构                                                        */
/*data:堆数据
/*heap:堆结构变量
/*size:数据大小
/*返回：无
/************************************************************************/
void BuildMinHeap(Heap_t *heap,int *data,int size)
{
	int i;
	if(heap->MaxSize<=0)										//堆数据最大空间必须大于0
		return;
	heap->heapArray = (int *)malloc(heap->MaxSize*sizeof(int));	//开辟maxsize个空间大小
	heap->CurrentSize = size;									//当前堆中元素个数
	for(i=0;i<heap->CurrentSize;i++)							//数据赋值
		heap->heapArray[i] = data[i];

	for(i = heap->CurrentSize/2-1;i>=0;i--)						//筛选法建堆，从n/2-1开始
	{
		SiftDown(heap,i);
	}
}

/************************************************************************/
/*插入新节点                                                       */
/*node:新节点值
/*heap:堆结构变量
/*返回：
/************************************************************************/
static bool MinHeapInsert(Heap_t *heap,int node)
{
	printf("插入节点数据：%d\r\n",node);
	if(heap->CurrentSize == heap->MaxSize)						//如果堆已满，返回false
		return FALSE;
	heap->heapArray[heap->CurrentSize] = node;
	SiftUp(heap,heap->CurrentSize-1);							//向上调整
	heap->CurrentSize++;										//当前大小加1

	return TRUE;
}

/************************************************************************/
/*从堆顶删除最小值                                                       */
/*heap:堆结构变量
/*返回：堆中最小值
/************************************************************************/
static int MinHeapRemoveMin(Heap_t *heap)
{
	int temp;
	if(0 == heap->CurrentSize)										//当前大小为0，无法删除
	{
		printf("当前堆大小为0，无法删除\r\n");
		return;
	}
	else
	{
		heap->CurrentSize--;										//当前大小减1

		temp = heap->heapArray[0];									//交换堆顶和堆末尾元素
		heap->heapArray[0] = heap->heapArray[heap->CurrentSize];
		heap->heapArray[heap->CurrentSize] = temp;

		if(heap->CurrentSize > 1)									//当前大小大于1，从堆顶开始向下筛选排序
			SiftDown(heap,0);
		return heap->heapArray[heap->CurrentSize];
	}
}

/************************************************************************/
/*删除给定下标的元素                                                      */
/*pos:给定节点下标
/*heap:堆结构变量
/*返回：给定下标节点值
/************************************************************************/
static int MinHeapRemove(Heap_t *heap,int pos)
{
	int temp;
	printf("删除节点%d\r\n",pos);
	if((pos<0) || pos>=heap->CurrentSize)
	{
		printf("节点下标超范围，无法删除\r\n");
		return;
	}
	temp = heap->heapArray[pos];									//保存要删除的节点值
	heap->heapArray[pos] = heap->heapArray[--heap->CurrentSize];	//用堆最后的值替换这里的值
	if(heap->heapArray[(pos-1)/2] > heap->heapArray[pos])			//如果父节点值大于当前值
		SiftUp(heap,pos);											//从当前节点开始向上筛选
	else
		SiftDown(heap,pos);											//否则从此节点开始向下调整
	return temp;													//返回删除的数据
}
/************************************************************************/
/*广度优先遍历最小堆                                                    */
/*heap:堆结构变量
/*返回：无
/************************************************************************/
void MinHeapTraverse(Heap_t *heap)
{
	int i;
	printf("遍历：");
	for(i=0;i<heap->CurrentSize;i++)
		printf("%d ",heap->heapArray[i]);
	printf("\r\n");
}
void testHeap(void)
{
	int HeapVal[9] = {9,9,7,6,20,4,33,2,1};
	Heap_t heap;														//定义一个堆结构变量
	heap.MaxSize = 10;												    //需要指定堆最大空间为10
	BuildMinHeap(&heap,HeapVal,sizeof(HeapVal)/sizeof(HeapVal[0]));		//构建一个堆结构
	MinHeapTraverse(&heap);

	if(TRUE == MinHeapInsert(&heap,22))
		MinHeapTraverse(&heap);

	printf("最小值：%d\r\n",MinHeapRemoveMin(&heap));
	MinHeapTraverse(&heap);

	printf("被删除数据：%d\r\n",MinHeapRemove(&heap,3));
	MinHeapTraverse(&heap);
}