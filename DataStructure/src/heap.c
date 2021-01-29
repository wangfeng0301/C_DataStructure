/************************************************************************
 *                 ��                                 
 *������ȫ���������Ա�洢������
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *2019.11.29-2021.1.29
************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "heap.h"

static void SiftDown(Heap_t *heap,int left);			//����ɸѡ
static void SiftUp(Heap_t *heap,int pos);				//����ɸѡ
void BuildMinHeap(Heap_t *heap,int *data,int size);	//������С�ѽṹ
bool MinHeapInsert(Heap_t *heap,int node);			//�����½ڵ�
int MinHeapRemoveMin(Heap_t *heap);					//ɾ���Ѷ�������Сֵ
static int MinHeapRemove(Heap_t *heap,int pos);		//ɾ��ָ���±��Ԫ��

/************************************************************************/
/*��parentΪ�����½��е���,��������������                               */
/*parent:���ڵ��ţ��Ӵ˽ڵ㿪ʼ����
/*���أ���
/************************************************************************/
static void SiftDown(Heap_t *heap,int parent)
{
	int child = 2*parent + 1;						//���ڵ�����ӽڵ���
	int temp = heap->heapArray[parent];				//���游�ڵ�

	while(child < heap->CurrentSize)				//�ڵ���С�ڵ�ǰ��С
	{
		if((child < heap->CurrentSize-1) && (heap->heapArray[child] > heap->heapArray[child+1]))//�������ӽڵ㣬�����ӽڵ�С�����ӽڵ�
			child++;								//childָ�����ӽڵ�
		if(temp > heap->heapArray[child])			//���ڵ�����ӽڵ�,����λ��
		{
			heap->heapArray[parent] = heap->heapArray[child];
			parent = child;
			child = 2*parent+1;						//���������ߣ����ӽڵ�
		}
		else
			break;									//����������ʱ�˳�
	}
	heap->heapArray[parent] = temp;
}

/************************************************************************/
/*���Ͻ��е���                                                 */
/*heap:�ѽṹ��
/*���أ���
/************************************************************************/
static void SiftUp(Heap_t *heap,int pos)
{
	int position = pos;								//�ӵ�ǰ��Сλ�ÿ�ʼ���ϵ���
	int temp = heap->heapArray[position];			//���浱ǰֵ
	while((position > 0) && (heap->heapArray[(position-1)/2] > temp))//δ���������ڵ㣬�Ҹ��ڵ�ȵ�ǰ�ڵ��
	{
		heap->heapArray[position] = heap->heapArray[(position-1)/2];
		position = (position-1)/2;					//���������ڵ�λ��
	}
	heap->heapArray[position] = temp;
}


/************************************************************************/
/*������С�ѽṹ                                                        */
/*data:������
/*heap:�ѽṹ����
/*size:���ݴ�С
/*���أ���
/************************************************************************/
void BuildMinHeap(Heap_t *heap,int *data,int size)
{
	int i;
	if(heap->MaxSize<=0)										//���������ռ�������0
		return;
	heap->heapArray = (int *)malloc(heap->MaxSize*sizeof(int));	//����maxsize���ռ��С
	heap->CurrentSize = size;									//��ǰ����Ԫ�ظ���
	for(i=0;i<heap->CurrentSize;i++)							//���ݸ�ֵ
		heap->heapArray[i] = data[i];

	for(i = heap->CurrentSize/2-1;i>=0;i--)						//ɸѡ�����ѣ���n/2-1��ʼ
	{
		SiftDown(heap,i);
	}
}

/************************************************************************/
/*�����½ڵ�                                                       */
/*node:�½ڵ�ֵ
/*heap:�ѽṹ����
/*���أ�
/************************************************************************/
static bool MinHeapInsert(Heap_t *heap,int node)
{
	printf("����ڵ����ݣ�%d\r\n",node);
	if(heap->CurrentSize == heap->MaxSize)						//���������������false
		return FALSE;
	heap->heapArray[heap->CurrentSize] = node;
	SiftUp(heap,heap->CurrentSize-1);							//���ϵ���
	heap->CurrentSize++;										//��ǰ��С��1

	return TRUE;
}

/************************************************************************/
/*�ӶѶ�ɾ����Сֵ                                                       */
/*heap:�ѽṹ����
/*���أ�������Сֵ
/************************************************************************/
static int MinHeapRemoveMin(Heap_t *heap)
{
	int temp;
	if(0 == heap->CurrentSize)										//��ǰ��СΪ0���޷�ɾ��
	{
		printf("��ǰ�Ѵ�СΪ0���޷�ɾ��\r\n");
		return;
	}
	else
	{
		heap->CurrentSize--;										//��ǰ��С��1

		temp = heap->heapArray[0];									//�����Ѷ��Ͷ�ĩβԪ��
		heap->heapArray[0] = heap->heapArray[heap->CurrentSize];
		heap->heapArray[heap->CurrentSize] = temp;

		if(heap->CurrentSize > 1)									//��ǰ��С����1���ӶѶ���ʼ����ɸѡ����
			SiftDown(heap,0);
		return heap->heapArray[heap->CurrentSize];
	}
}

/************************************************************************/
/*ɾ�������±��Ԫ��                                                      */
/*pos:�����ڵ��±�
/*heap:�ѽṹ����
/*���أ������±�ڵ�ֵ
/************************************************************************/
static int MinHeapRemove(Heap_t *heap,int pos)
{
	int temp;
	printf("ɾ���ڵ�%d\r\n",pos);
	if((pos<0) || pos>=heap->CurrentSize)
	{
		printf("�ڵ��±곬��Χ���޷�ɾ��\r\n");
		return;
	}
	temp = heap->heapArray[pos];									//����Ҫɾ���Ľڵ�ֵ
	heap->heapArray[pos] = heap->heapArray[--heap->CurrentSize];	//�ö�����ֵ�滻�����ֵ
	if(heap->heapArray[(pos-1)/2] > heap->heapArray[pos])			//������ڵ�ֵ���ڵ�ǰֵ
		SiftUp(heap,pos);											//�ӵ�ǰ�ڵ㿪ʼ����ɸѡ
	else
		SiftDown(heap,pos);											//����Ӵ˽ڵ㿪ʼ���µ���
	return temp;													//����ɾ��������
}
/************************************************************************/
/*������ȱ�����С��                                                    */
/*heap:�ѽṹ����
/*���أ���
/************************************************************************/
void MinHeapTraverse(Heap_t *heap)
{
	int i;
	printf("������");
	for(i=0;i<heap->CurrentSize;i++)
		printf("%d ",heap->heapArray[i]);
	printf("\r\n");
}
void testHeap(void)
{
	int HeapVal[9] = {9,9,7,6,20,4,33,2,1};
	Heap_t heap;														//����һ���ѽṹ����
	heap.MaxSize = 10;												    //��Ҫָ�������ռ�Ϊ10
	BuildMinHeap(&heap,HeapVal,sizeof(HeapVal)/sizeof(HeapVal[0]));		//����һ���ѽṹ
	MinHeapTraverse(&heap);

	if(TRUE == MinHeapInsert(&heap,22))
		MinHeapTraverse(&heap);

	printf("��Сֵ��%d\r\n",MinHeapRemoveMin(&heap));
	MinHeapTraverse(&heap);

	printf("��ɾ�����ݣ�%d\r\n",MinHeapRemove(&heap,3));
	MinHeapTraverse(&heap);
}