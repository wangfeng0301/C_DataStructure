/************************************************************************
 *                 ��                                 
 *������ȫ���������Ա�洢������
 *�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
 *wangfeng
 *E-mail:fengwang0301@163.com
 *CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
 *GitHub:https://github.com/wangfeng0301
 *2019.11.29-2021.2.4
 *2021.2.4	�޸ģ��淶������
 *			���ӣ����Ѳ���
************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "heap.h"

/************************************************************************/
/*���ܣ��ж���С���Ƿ���
/*���룺heap:�ѽṹ����
/*�������
/*���أ���TRUE,δ��FALSE
/************************************************************************/
bool MinHeap_IsFull(Heap_t *heap)
{
	if(heap->currsize >= heap->maxsize)				//���������������TRUE
		return TRUE;
	else
		return FALSE;
}
/************************************************************************/
/*���ܣ��ж���С���Ƿ��
/*���룺heap:�ѽṹ����
/*�������
/*���أ���TRUE,δ��FALSE
/************************************************************************/
bool MinHeap_IsEmpty(Heap_t *heap)
{
	if(heap->currsize <= 0)				//������ѿգ�����TRUE
		return TRUE;
	else
		return FALSE;
}
/************************************************************************/
/*���ܣ���parentΪ�����½��е���,��������������
/*���룺parent:���ڵ��ţ��Ӵ˽ڵ㿪ʼ����
/*�������
/*���أ���
/************************************************************************/
void MinHeap_SiftDown(Heap_t *heap, int parent)
{
	int child = 2*parent + 1;						//���ڵ�����ӽڵ���
	int temp = heap->array[parent];					//���游�ڵ�

	while(child < heap->currsize)					//�ڵ���С�ڵ�ǰ��С
	{
		/* �������ӽڵ㣬�����ӽڵ�С�����ӽڵ�,����������ӽڵ� */
		if((child < heap->currsize-1) && (heap->array[child] > heap->array[child+1]))
			child++;
		if(temp > heap->array[child])				//���ڵ�����ӽڵ�,����λ��
		{
			heap->array[parent] = heap->array[child];
			parent = child;
			child = 2*parent+1;						//���������ߣ����ӽڵ�
		}
		else
			break;									//����������ʱ�˳�
	}
	heap->array[parent] = temp;
}

/************************************************************************/
/*���ܣ���posΪ�����Ͻ��е���,��С����������
/*���룺pos:��ʼ����λ��
/*�������
/*���أ���
/************************************************************************/
void MinHeap_SiftUp(Heap_t *heap, int pos)
{
	int position = pos;								//�ӵ�ǰ��Сλ�ÿ�ʼ���ϵ���
	int temp = heap->array[position];				//���浱ǰֵ
	/* ��̬�ѣ�leftchild = 2*parent + 1 */
	/* ��̬�ѣ�rightchild = 2*parent + 2 */
	/* ��̬�ѣ�parent = (child-1)/2 */
	/* δ���������ڵ㣬�Ҹ��ڵ�ȵ�ǰ�ڵ�� */
	while((position > 0) && (heap->array[(position-1)/2] > temp))
	{
		heap->array[position] = heap->array[(position-1)/2];
		position = (position-1)/2;					//���������ڵ�λ��
	}
	heap->array[position] = temp;
}

/************************************************************************/
/*���ܣ�������С�ѽṹ 
/*���룺data:������
/*		heap:�ѽṹ����
/*		size:���ݴ�С
/*		maxsize:�����ռ��С
/*�������
/*���أ�TRUE or FALSE
/************************************************************************/
bool MinHeap_Create(Heap_t *heap, int *data, int size, int maxsize)
{
	int i;
	if(maxsize <= 0)									//���������ռ�������0
		return FALSE;
	heap->array = (int *)malloc(maxsize*sizeof(int));	//����maxsize���ռ��С
	if(heap->array == NULL)
		return FALSE;
	heap->currsize = size;								//��ǰ����Ԫ�ظ���
	heap->maxsize = maxsize;
	for(i=0;i<heap->currsize;i++)						//���ݸ�ֵ
		heap->array[i] = data[i];

	for(i = heap->currsize/2-1;i>=0;i--)				//ɸѡ�����ѣ���n/2-1��ʼ
	{
		MinHeap_SiftDown(heap, i);
	}
	return TRUE;
}

/************************************************************************/
/*���ܣ������½ڵ� 
/*���룺heap:�ѽṹ����
/*		node:�ڵ�ֵ
/*�������
/*���أ�TRUE or FALSE
/************************************************************************/
bool MinHeap_Insert(Heap_t *heap,int node)
{
	printf("����ڵ����ݣ�%d\r\n",node);
	if(MinHeap_IsFull(heap))
		return FALSE;
	heap->array[heap->currsize] = node;
	MinHeap_SiftUp(heap, heap->currsize);			//���ϵ���
	heap->currsize++;								//��ǰ��С��1

	return TRUE;
}

/************************************************************************/
/*���ܣ��ӶѶ�ɾ����Сֵ  
/*���룺heap:�ѽṹ����
/*		node:�ڵ�ֵ
/*�����ɾ���ڵ��ֵ
/*���أ�TRUE or FALSE
/************************************************************************/
bool MinHeap_RemoveMin(Heap_t *heap, int *node)
{
	int temp;
	if(MinHeap_IsEmpty(heap))						//��ǰ��СΪ0���޷�ɾ��
	{
		printf("��ǰ�Ѵ�СΪ0���޷�ɾ��\r\n");
		return FALSE;
	}
	else
	{
		heap->currsize--;							//��ǰ��С��1

		temp = heap->array[0];						//�����Ѷ��Ͷ�ĩβԪ��
		heap->array[0] = heap->array[heap->currsize];
		heap->array[heap->currsize] = temp;

		if(heap->currsize > 1)						//��ǰ��С����1���ӶѶ���ʼ����ɸѡ����
			MinHeap_SiftDown(heap, 0);
		*node = heap->array[heap->currsize];
		return TRUE;
	}
}

/************************************************************************/
/*���ܣ�ɾ�������±��Ԫ�� 
/*���룺heap:�ѽṹ����
/*		node:�ڵ�ֵ
/*		pos:ɾ���ڵ�ı��
/*�����ɾ���ڵ��ֵ
/*���أ�TRUE or FALSE
/************************************************************************/
bool MinHeap_Remove(Heap_t *heap, int *node, int pos)
{
	printf("ɾ���ڵ�%d\r\n",pos);
	if(MinHeap_IsEmpty(heap))
	{
		printf("��ǰ�Ѵ�СΪ0���޷�ɾ��\r\n");
		return FALSE;
	}
	if((pos<0) || pos >= heap->currsize)
	{
		printf("�ڵ��±곬��Χ���޷�ɾ��\r\n");
		return FALSE;
	}
	*node = heap->array[pos];						//����Ҫɾ���Ľڵ�ֵ
	heap->array[pos] = heap->array[--heap->currsize];//�ö�����ֵ�滻�����ֵ
	if(heap->array[(pos-1)/2] > heap->array[pos])	//������ڵ�ֵ���ڵ�ǰֵ
		MinHeap_SiftUp(heap,pos);					//�ӵ�ǰ�ڵ㿪ʼ����ɸѡ
	else
		MinHeap_SiftDown(heap,pos);					//����Ӵ˽ڵ㿪ʼ���µ���
	return TRUE;									//����ɾ��������
}
/************************************************************************/
/*���ܣ�������ȱ�����С��  
/*���룺heap:�ѽṹ����
/*�������
/*���أ���
/************************************************************************/
void MinHeap_Traverse(Heap_t *heap)
{
	int i;
	printf("������");
	for(i=0;i<heap->currsize;i++)
		printf("%d ",heap->array[i]);
	printf("\r\n");
}
/************************************************************************/
/*���ܣ����ٶ�
/*���룺heap:�ѽṹ����
/*�������
/*���أ���
/************************************************************************/
void MinHeap_Destroy(Heap_t *heap)
{
	heap->currsize = 0;
	heap->maxsize = 0;
	free(heap->array);
	heap->array = NULL;
}

/*************************************************** ���� **************************************************/
/************************************************************************/
/*���ܣ��ж������Ƿ���
/*���룺heap:�ѽṹ����
/*�������
/*���أ���TRUE,δ��FALSE
/************************************************************************/
bool MaxHeap_IsFull(Heap_t *heap)
{
	return MinHeap_IsFull(heap);
}
/************************************************************************/
/*���ܣ��ж������Ƿ��
/*���룺heap:�ѽṹ����
/*�������
/*���أ���TRUE,δ��FALSE
/************************************************************************/
bool MaxHeap_IsEmpty(Heap_t *heap)
{
	return MinHeap_IsEmpty(heap);
}
/************************************************************************/
/*���ܣ���parentΪ�����½��е���,��С����������
/*���룺parent:���ڵ��ţ��Ӵ˽ڵ㿪ʼ����
/*�������
/*���أ���
/************************************************************************/
void MaxHeap_SiftDown(Heap_t *heap,int parent)
{
	int child = 2 * parent + 1;						//parent�����ӽڵ�
	int temp = heap->array[parent];					//���游�ڵ�

	while(child < heap->currsize)					//�ӽڵ���С�ڵ�ǰ��С
	{
		/* �������ӽڵ㣬�����ӽڵ�С�����ӽڵ�,����������ӽڵ� */
		if((child < heap->currsize-1) && (heap->array[child] < heap->array[child+1]))
			child ++;								//childָ�����ӽڵ�
		if(temp < heap->array[child])				//���ڵ�С���ӽڵ�,����λ��
		{
			heap->array[parent] = heap->array[child];
			parent = child;
			child = 2 * parent + 1;					//���������ߣ����ӽڵ�
		}
		else
			break;									//����������ʱ�˳�
	}
	heap->array[parent] = temp;
}

/************************************************************************/
/*���ܣ���posΪ�����Ͻ��е���,��������������
/*���룺pos:��ʼ����λ��
/*�������
/*���أ���
/************************************************************************/
void MaxHeap_SiftUp(Heap_t *heap,int pos)
{
	int position = pos;							//�ӵ�ǰ��Сλ�ÿ�ʼ���ϵ���
	int temp = heap->array[position];			//���浱ǰֵ
	/* δ���������ڵ㣬�Ҹ��ڵ�ȵ�ǰ�ڵ�С */
	while((position > 0) && (heap->array[(position-1)/2] < temp))
	{
		heap->array[position] = heap->array[(position-1)/2];
		position = (position-1)/2;				//���������ڵ�λ��
	}
	heap->array[position] = temp;
}

/************************************************************************/
/*���ܣ��������ѽṹ 
/*���룺data:������
/*		heap:�ѽṹ����
/*		size:���ݴ�С
/*		maxsize:�����ռ��С
/*�������
/*���أ�TRUE or FALSE
/************************************************************************/
bool MaxHeap_Create(Heap_t *heap, int *data, int size, int maxsize)
{
	int i;
	if(maxsize <= 0)							//���������ռ�������0
		return FALSE;
	heap->array = (int *)malloc(maxsize*sizeof(int));//����maxsize���ռ��С
	if(heap->array == NULL)
		return FALSE;
	heap->currsize = size;						//��ǰ����Ԫ�ظ���
	heap->maxsize = maxsize;					//�������ֵ
	//heap->array = data;						//�����ݿռ�����ⲿ���٣������Ļ��Ϳ���ʡȥ��ֵ����
	for(i=0;i<heap->currsize;i++)				//���ݸ�ֵ
		heap->array[i] = data[i];

	for(i = heap->currsize/2-1;i>=0;i--)		//ɸѡ�����ѣ���n/2-1��ʼ
	{
		MaxHeap_SiftDown(heap, i);
	}
	return TRUE;
}
/************************************************************************/
/*���ܣ������½ڵ� 
/*���룺heap:�ѽṹ����
/*		node:�ڵ�ֵ
/*�������
/*���أ�TRUE or FALSE
/************************************************************************/
bool MaxHeap_Insert(Heap_t *heap,int node)
{
	printf("����ڵ����ݣ�%d\r\n",node);
	if(MaxHeap_IsFull(heap))
		return FALSE;
	heap->array[heap->currsize] = node;
	MaxHeap_SiftUp(heap, heap->currsize);			//���ϵ���
	heap->currsize++;								//��ǰ��С��1

	return TRUE;
}
/************************************************************************/
/*���ܣ��ӶѶ�ɾ�����ֵ  
/*���룺heap:�ѽṹ����
/*		node:�ڵ�ֵ
/*�����ɾ���ڵ��ֵ
/*���أ�TRUE or FALSE
/************************************************************************/
bool MaxHeap_RemoveMax(Heap_t *heap, int *node)
{
	int temp;
	if(MinHeap_IsEmpty(heap))						//��ǰ��СΪ0���޷�ɾ��
	{
		printf("��ǰ�Ѵ�СΪ0���޷�ɾ��\r\n");
		return FALSE;
	}
	else
	{
		heap->currsize--;							//��ǰ��С��1

		temp = heap->array[0];						//�����Ѷ��Ͷ�ĩβ�ڵ㣨��¼��
		heap->array[0] = heap->array[heap->currsize];
		heap->array[heap->currsize] = temp;

		if(heap->currsize > 1)						//��ǰ��С����1���ӶѶ���ʼ����ɸѡ����
			MaxHeap_SiftDown(heap, 0);
		*node =  heap->array[heap->currsize];
		return TRUE;
	}
}
/************************************************************************/
/*���ܣ�ɾ�������±��Ԫ�� 
/*���룺heap:�ѽṹ����
/*		node:�ڵ�ֵ
/*		pos:ɾ���ڵ�ı��
/*�����ɾ���ڵ��ֵ
/*���أ�TRUE or FALSE
/************************************************************************/
bool MaxHeap_Remove(Heap_t *heap, int *node, int pos)
{
	printf("ɾ���ڵ�%d\r\n",pos);
	if(MinHeap_IsEmpty(heap))
	{
		printf("��ǰ�Ѵ�СΪ0���޷�ɾ��\r\n");
		return FALSE;
	}
	if((pos<0) || pos >= heap->currsize)
	{
		printf("�ڵ��±곬��Χ���޷�ɾ��\r\n");
		return FALSE;
	}
	*node = heap->array[pos];						//����Ҫɾ���Ľڵ�ֵ
	heap->array[pos] = heap->array[--heap->currsize];//�ö�����ֵ�滻�����ֵ
	if(heap->array[(pos-1)/2] > heap->array[pos])	//������ڵ�ֵ���ڵ�ǰֵ
		MaxHeap_SiftDown(heap,pos);					//�ӵ�ǰ�ڵ㿪ʼ����ɸѡ
	else
		MaxHeap_SiftUp(heap,pos);					//����Ӵ˽ڵ㿪ʼ���µ���
	return TRUE;									//����ɾ��������
}
/************************************************************************/
/*���ܣ�������ȱ�����С��  
/*���룺heap:�ѽṹ����
/*�������
/*���أ���
/************************************************************************/
void MaxHeap_Traverse(Heap_t *heap)
{
	MinHeap_Traverse(heap);
}
/************************************************************************/
/*���ܣ����ٶ�
/*���룺heap:�ѽṹ����
/*�������
/*���أ���
/************************************************************************/
void MaxHeap_Destroy(Heap_t *heap)
{
	MinHeap_Destroy(heap);
}



void testHeap(void)
{
	int HeapVal[9] = {9,9,7,6,20,4,33,2,1};
	int temp;
	Heap_t heap;									//����һ���ѽṹ����
	
	MinHeap_Create(&heap, HeapVal, sizeof(HeapVal)/sizeof(HeapVal[0]), 10);
	MinHeap_Traverse(&heap);
	if(TRUE == MinHeap_Insert(&heap,10))
		MinHeap_Traverse(&heap);

	if(MinHeap_RemoveMin(&heap, &temp))
		printf("��Сֵ��%d\r\n",temp);
	MinHeap_Traverse(&heap);

	if(MinHeap_Remove(&heap, &temp, 3))
		printf("��ɾ�����ݣ�%d\r\n", temp);
	MinHeap_Traverse(&heap);
	while(!MinHeap_IsEmpty(&heap))
	{
		if(MinHeap_RemoveMin(&heap, &temp))
			printf("��Сֵ��%d\r\n",temp);
	}
	MinHeap_Destroy(&heap);

	printf("\r\n\r\n");
	MaxHeap_Create(&heap, HeapVal, sizeof(HeapVal)/sizeof(HeapVal[0]), 10);
	MaxHeap_Traverse(&heap);
	if(TRUE == MaxHeap_Insert(&heap, 10))
		MaxHeap_Traverse(&heap);

	if(MaxHeap_RemoveMax(&heap, &temp))
		printf("���ֵ��%d\r\n", temp);
	MaxHeap_Traverse(&heap);

	if(MaxHeap_Remove(&heap, &temp, 3))
		printf("��ɾ�����ݣ�%d\r\n", temp);
	MaxHeap_Traverse(&heap);
	while(!MaxHeap_IsEmpty(&heap))
	{
		if(MaxHeap_RemoveMax(&heap, &temp))
			printf("���ֵ��%d\r\n",temp);
	}
	MaxHeap_Destroy(&heap);
}