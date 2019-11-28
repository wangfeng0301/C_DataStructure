#ifndef __HEAP_H__
#define __HEAP_H__

//�ض�����������
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif
typedef unsigned char	bool;

/*�ѽṹ��*/
typedef struct 
{
	int *heapArray;									//��Ŷ����ݵ�����
	int CurrentSize;								//��ǰ����Ԫ����Ŀ
	int MaxSize;									//�ѵ����Ԫ����Ŀ
}Heap;

void BuildMinHeap(Heap *heap,int *data,int size);	//������С�ѽṹ
bool MinHeapInsert(Heap *heap,int node);			//�����½ڵ�
int MinHeapRemoveMin(Heap *heap);					//ɾ���Ѷ�������Сֵ
void testHeap();


#endif