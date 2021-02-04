/************************************************************************
 *                 堆                                 
 *利用完全二叉树线性表存储堆数据
 *参考资料：《数据结构与算法》张铭，王腾蛟，赵海燕等
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.4
 *2021.2.4	修改，规范函数名
 *			增加，最大堆操作
************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "heap.h"

/************************************************************************/
/*功能：判断最小堆是否满
/*输入：heap:堆结构变量
/*输出：无
/*返回：满TRUE,未满FALSE
/************************************************************************/
bool MinHeap_IsFull(Heap_t *heap)
{
	if(heap->currsize >= heap->maxsize)				//如果堆已满，返回TRUE
		return TRUE;
	else
		return FALSE;
}
/************************************************************************/
/*功能：判断最小堆是否空
/*输入：heap:堆结构变量
/*输出：无
/*返回：空TRUE,未空FALSE
/************************************************************************/
bool MinHeap_IsEmpty(Heap_t *heap)
{
	if(heap->currsize <= 0)				//如果堆已空，返回TRUE
		return TRUE;
	else
		return FALSE;
}
/************************************************************************/
/*功能：以parent为根向下进行调整,即大数放在下面
/*输入：parent:父节点编号，从此节点开始调整
/*输出：无
/*返回：无
/************************************************************************/
void MinHeap_SiftDown(Heap_t *heap, int parent)
{
	int child = 2*parent + 1;						//父节点的左子节点编号
	int temp = heap->array[parent];					//保存父节点

	while(child < heap->currsize)					//节点编号小于当前大小
	{
		/* 若有右子节点，且右子节点小于左子节点,则需调整右子节点 */
		if((child < heap->currsize-1) && (heap->array[child] > heap->array[child+1]))
			child++;
		if(temp > heap->array[child])				//父节点大于子节点,交换位置
		{
			heap->array[parent] = heap->array[child];
			parent = child;
			child = 2*parent+1;						//继续向下走，左子节点
		}
		else
			break;									//堆序性满足时退出
	}
	heap->array[parent] = temp;
}

/************************************************************************/
/*功能：以pos为根向上进行调整,即小数放在上面
/*输入：pos:开始调整位置
/*输出：无
/*返回：无
/************************************************************************/
void MinHeap_SiftUp(Heap_t *heap, int pos)
{
	int position = pos;								//从当前大小位置开始向上调整
	int temp = heap->array[position];				//保存当前值
	/* 静态堆，leftchild = 2*parent + 1 */
	/* 静态堆，rightchild = 2*parent + 2 */
	/* 静态堆，parent = (child-1)/2 */
	/* 未调整到根节点，且父节点比当前节点大 */
	while((position > 0) && (heap->array[(position-1)/2] > temp))
	{
		heap->array[position] = heap->array[(position-1)/2];
		position = (position-1)/2;					//调整到父节点位置
	}
	heap->array[position] = temp;
}

/************************************************************************/
/*功能：建立最小堆结构 
/*输入：data:堆数据
/*		heap:堆结构变量
/*		size:数据大小
/*		maxsize:堆最大空间大小
/*输出：无
/*返回：TRUE or FALSE
/************************************************************************/
bool MinHeap_Create(Heap_t *heap, int *data, int size, int maxsize)
{
	int i;
	if(maxsize <= 0)									//堆数据最大空间必须大于0
		return FALSE;
	heap->array = (int *)malloc(maxsize*sizeof(int));	//开辟maxsize个空间大小
	if(heap->array == NULL)
		return FALSE;
	heap->currsize = size;								//当前堆中元素个数
	heap->maxsize = maxsize;
	for(i=0;i<heap->currsize;i++)						//数据赋值
		heap->array[i] = data[i];

	for(i = heap->currsize/2-1;i>=0;i--)				//筛选法建堆，从n/2-1开始
	{
		MinHeap_SiftDown(heap, i);
	}
	return TRUE;
}

/************************************************************************/
/*功能：插入新节点 
/*输入：heap:堆结构变量
/*		node:节点值
/*输出：无
/*返回：TRUE or FALSE
/************************************************************************/
bool MinHeap_Insert(Heap_t *heap,int node)
{
	printf("插入节点数据：%d\r\n",node);
	if(MinHeap_IsFull(heap))
		return FALSE;
	heap->array[heap->currsize] = node;
	MinHeap_SiftUp(heap, heap->currsize);			//向上调整
	heap->currsize++;								//当前大小加1

	return TRUE;
}

/************************************************************************/
/*功能：从堆顶删除最小值  
/*输入：heap:堆结构变量
/*		node:节点值
/*输出：删除节点的值
/*返回：TRUE or FALSE
/************************************************************************/
bool MinHeap_RemoveMin(Heap_t *heap, int *node)
{
	int temp;
	if(MinHeap_IsEmpty(heap))						//当前大小为0，无法删除
	{
		printf("当前堆大小为0，无法删除\r\n");
		return FALSE;
	}
	else
	{
		heap->currsize--;							//当前大小减1

		temp = heap->array[0];						//交换堆顶和堆末尾元素
		heap->array[0] = heap->array[heap->currsize];
		heap->array[heap->currsize] = temp;

		if(heap->currsize > 1)						//当前大小大于1，从堆顶开始向下筛选排序
			MinHeap_SiftDown(heap, 0);
		*node = heap->array[heap->currsize];
		return TRUE;
	}
}

/************************************************************************/
/*功能：删除给定下标的元素 
/*输入：heap:堆结构变量
/*		node:节点值
/*		pos:删除节点的标号
/*输出：删除节点的值
/*返回：TRUE or FALSE
/************************************************************************/
bool MinHeap_Remove(Heap_t *heap, int *node, int pos)
{
	printf("删除节点%d\r\n",pos);
	if(MinHeap_IsEmpty(heap))
	{
		printf("当前堆大小为0，无法删除\r\n");
		return FALSE;
	}
	if((pos<0) || pos >= heap->currsize)
	{
		printf("节点下标超范围，无法删除\r\n");
		return FALSE;
	}
	*node = heap->array[pos];						//保存要删除的节点值
	heap->array[pos] = heap->array[--heap->currsize];//用堆最后的值替换这里的值
	if(heap->array[(pos-1)/2] > heap->array[pos])	//如果父节点值大于当前值
		MinHeap_SiftUp(heap,pos);					//从当前节点开始向上筛选
	else
		MinHeap_SiftDown(heap,pos);					//否则从此节点开始向下调整
	return TRUE;									//返回删除的数据
}
/************************************************************************/
/*功能：广度优先遍历最小堆  
/*输入：heap:堆结构变量
/*输出：无
/*返回：无
/************************************************************************/
void MinHeap_Traverse(Heap_t *heap)
{
	int i;
	printf("遍历：");
	for(i=0;i<heap->currsize;i++)
		printf("%d ",heap->array[i]);
	printf("\r\n");
}
/************************************************************************/
/*功能：销毁堆
/*输入：heap:堆结构变量
/*输出：无
/*返回：无
/************************************************************************/
void MinHeap_Destroy(Heap_t *heap)
{
	heap->currsize = 0;
	heap->maxsize = 0;
	free(heap->array);
	heap->array = NULL;
}

/*************************************************** 最大堆 **************************************************/
/************************************************************************/
/*功能：判断最大堆是否满
/*输入：heap:堆结构变量
/*输出：无
/*返回：满TRUE,未满FALSE
/************************************************************************/
bool MaxHeap_IsFull(Heap_t *heap)
{
	return MinHeap_IsFull(heap);
}
/************************************************************************/
/*功能：判断最大堆是否空
/*输入：heap:堆结构变量
/*输出：无
/*返回：空TRUE,未空FALSE
/************************************************************************/
bool MaxHeap_IsEmpty(Heap_t *heap)
{
	return MinHeap_IsEmpty(heap);
}
/************************************************************************/
/*功能：以parent为根向下进行调整,即小数放在下面
/*输入：parent:父节点编号，从此节点开始调整
/*输出：无
/*返回：无
/************************************************************************/
void MaxHeap_SiftDown(Heap_t *heap,int parent)
{
	int child = 2 * parent + 1;						//parent的左子节点
	int temp = heap->array[parent];					//保存父节点

	while(child < heap->currsize)					//子节点编号小于当前大小
	{
		/* 若有右子节点，且右子节点小于左子节点,则需调整右子节点 */
		if((child < heap->currsize-1) && (heap->array[child] < heap->array[child+1]))
			child ++;								//child指向右子节点
		if(temp < heap->array[child])				//父节点小于子节点,交换位置
		{
			heap->array[parent] = heap->array[child];
			parent = child;
			child = 2 * parent + 1;					//继续向下走，左子节点
		}
		else
			break;									//堆序性满足时退出
	}
	heap->array[parent] = temp;
}

/************************************************************************/
/*功能：以pos为根向上进行调整,即大数放在上面
/*输入：pos:开始调整位置
/*输出：无
/*返回：无
/************************************************************************/
void MaxHeap_SiftUp(Heap_t *heap,int pos)
{
	int position = pos;							//从当前大小位置开始向上调整
	int temp = heap->array[position];			//保存当前值
	/* 未调整到根节点，且父节点比当前节点小 */
	while((position > 0) && (heap->array[(position-1)/2] < temp))
	{
		heap->array[position] = heap->array[(position-1)/2];
		position = (position-1)/2;				//调整到父节点位置
	}
	heap->array[position] = temp;
}

/************************************************************************/
/*功能：建立最大堆结构 
/*输入：data:堆数据
/*		heap:堆结构变量
/*		size:数据大小
/*		maxsize:堆最大空间大小
/*输出：无
/*返回：TRUE or FALSE
/************************************************************************/
bool MaxHeap_Create(Heap_t *heap, int *data, int size, int maxsize)
{
	int i;
	if(maxsize <= 0)							//堆数据最大空间必须大于0
		return FALSE;
	heap->array = (int *)malloc(maxsize*sizeof(int));//开辟maxsize个空间大小
	if(heap->array == NULL)
		return FALSE;
	heap->currsize = size;						//当前堆中元素个数
	heap->maxsize = maxsize;					//设置最大值
	//heap->array = data;						//堆数据空间可以外部开辟，那样的话就可以省去赋值过程
	for(i=0;i<heap->currsize;i++)				//数据赋值
		heap->array[i] = data[i];

	for(i = heap->currsize/2-1;i>=0;i--)		//筛选法建堆，从n/2-1开始
	{
		MaxHeap_SiftDown(heap, i);
	}
	return TRUE;
}
/************************************************************************/
/*功能：插入新节点 
/*输入：heap:堆结构变量
/*		node:节点值
/*输出：无
/*返回：TRUE or FALSE
/************************************************************************/
bool MaxHeap_Insert(Heap_t *heap,int node)
{
	printf("插入节点数据：%d\r\n",node);
	if(MaxHeap_IsFull(heap))
		return FALSE;
	heap->array[heap->currsize] = node;
	MaxHeap_SiftUp(heap, heap->currsize);			//向上调整
	heap->currsize++;								//当前大小加1

	return TRUE;
}
/************************************************************************/
/*功能：从堆顶删除最大值  
/*输入：heap:堆结构变量
/*		node:节点值
/*输出：删除节点的值
/*返回：TRUE or FALSE
/************************************************************************/
bool MaxHeap_RemoveMax(Heap_t *heap, int *node)
{
	int temp;
	if(MinHeap_IsEmpty(heap))						//当前大小为0，无法删除
	{
		printf("当前堆大小为0，无法删除\r\n");
		return FALSE;
	}
	else
	{
		heap->currsize--;							//当前大小减1

		temp = heap->array[0];						//交换堆顶和堆末尾节点（记录）
		heap->array[0] = heap->array[heap->currsize];
		heap->array[heap->currsize] = temp;

		if(heap->currsize > 1)						//当前大小大于1，从堆顶开始向下筛选排序
			MaxHeap_SiftDown(heap, 0);
		*node =  heap->array[heap->currsize];
		return TRUE;
	}
}
/************************************************************************/
/*功能：删除给定下标的元素 
/*输入：heap:堆结构变量
/*		node:节点值
/*		pos:删除节点的标号
/*输出：删除节点的值
/*返回：TRUE or FALSE
/************************************************************************/
bool MaxHeap_Remove(Heap_t *heap, int *node, int pos)
{
	printf("删除节点%d\r\n",pos);
	if(MinHeap_IsEmpty(heap))
	{
		printf("当前堆大小为0，无法删除\r\n");
		return FALSE;
	}
	if((pos<0) || pos >= heap->currsize)
	{
		printf("节点下标超范围，无法删除\r\n");
		return FALSE;
	}
	*node = heap->array[pos];						//保存要删除的节点值
	heap->array[pos] = heap->array[--heap->currsize];//用堆最后的值替换这里的值
	if(heap->array[(pos-1)/2] > heap->array[pos])	//如果父节点值大于当前值
		MaxHeap_SiftDown(heap,pos);					//从当前节点开始向上筛选
	else
		MaxHeap_SiftUp(heap,pos);					//否则从此节点开始向下调整
	return TRUE;									//返回删除的数据
}
/************************************************************************/
/*功能：广度优先遍历最小堆  
/*输入：heap:堆结构变量
/*输出：无
/*返回：无
/************************************************************************/
void MaxHeap_Traverse(Heap_t *heap)
{
	MinHeap_Traverse(heap);
}
/************************************************************************/
/*功能：销毁堆
/*输入：heap:堆结构变量
/*输出：无
/*返回：无
/************************************************************************/
void MaxHeap_Destroy(Heap_t *heap)
{
	MinHeap_Destroy(heap);
}



void testHeap(void)
{
	int HeapVal[9] = {9,9,7,6,20,4,33,2,1};
	int temp;
	Heap_t heap;									//定义一个堆结构变量
	
	MinHeap_Create(&heap, HeapVal, sizeof(HeapVal)/sizeof(HeapVal[0]), 10);
	MinHeap_Traverse(&heap);
	if(TRUE == MinHeap_Insert(&heap,10))
		MinHeap_Traverse(&heap);

	if(MinHeap_RemoveMin(&heap, &temp))
		printf("最小值：%d\r\n",temp);
	MinHeap_Traverse(&heap);

	if(MinHeap_Remove(&heap, &temp, 3))
		printf("被删除数据：%d\r\n", temp);
	MinHeap_Traverse(&heap);
	while(!MinHeap_IsEmpty(&heap))
	{
		if(MinHeap_RemoveMin(&heap, &temp))
			printf("最小值：%d\r\n",temp);
	}
	MinHeap_Destroy(&heap);

	printf("\r\n\r\n");
	MaxHeap_Create(&heap, HeapVal, sizeof(HeapVal)/sizeof(HeapVal[0]), 10);
	MaxHeap_Traverse(&heap);
	if(TRUE == MaxHeap_Insert(&heap, 10))
		MaxHeap_Traverse(&heap);

	if(MaxHeap_RemoveMax(&heap, &temp))
		printf("最大值：%d\r\n", temp);
	MaxHeap_Traverse(&heap);

	if(MaxHeap_Remove(&heap, &temp, 3))
		printf("被删除数据：%d\r\n", temp);
	MaxHeap_Traverse(&heap);
	while(!MaxHeap_IsEmpty(&heap))
	{
		if(MaxHeap_RemoveMax(&heap, &temp))
			printf("最大值：%d\r\n",temp);
	}
	MaxHeap_Destroy(&heap);
}