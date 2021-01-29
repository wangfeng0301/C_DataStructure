#ifndef __HEAP_H__
#define __HEAP_H__
#include "type.h"
/*�ѽṹ��*/
typedef struct 
{
	int *heapArray;									//��Ŷ����ݵ�����
	int CurrentSize;								//��ǰ����Ԫ����Ŀ
	int MaxSize;									//�ѵ����Ԫ����Ŀ
}Heap_t;

void BuildMinHeap(Heap_t *heap,int *data,int size);	//������С�ѽṹ
bool MinHeapInsert(Heap_t *heap,int node);			//�����½ڵ�
int MinHeapRemoveMin(Heap_t *heap);					//ɾ���Ѷ�������Сֵ
void testHeap(void);


#endif