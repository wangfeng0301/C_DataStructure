#include <stdio.h>
#include <string.h>
#include "linkedlist_single.h"
#include "linkedlist_double.h"
#include "stack.h"
#include "queue.h"
#include "string_my.h"
#include "tree_binary.h"
#include "tree.h"
#include "heap.h"
#include "sort.h"
#include "application.h"

int main()
{
	printf("\r\n**************************���������**************************\r\n");
	testLink();

	printf("\r\n**************************˫�������**************************\r\n");
	testDoubleLink();

	printf("\r\n************************ѭ��˫�������************************\r\n");
	testCycDoubleLink();

	printf("\r\n**************************�ַ�������**************************\r\n");
	testString();

	printf("\r\n****************************ջ����****************************\r\n");
	testStack();

	printf("\r\n*************************��ʽջ����***************************\r\n");
	testLinkStack();

	printf("\r\n**************************�ݹ����****************************\r\n");
	testRecursion();
	
	printf("\r\n***************************���в���***************************\r\n");
	testQueue();

	printf("\r\n************************��ʽ���в���**************************\r\n");
	testLinkQueue();

	printf("\r\n*************************����������***************************\r\n");
	testBinaryTree();

	printf("\r\n****************************�Ѳ���****************************\r\n");
	testHeap();

	printf("\r\n*********************** Huffman������ ************************\r\n");
	testHuffmanTree();

	printf("\r\n***************************������*****************************\r\n");
	testTree();

	printf("\r\n**************************�������****************************\r\n");
	testSort();

	printf("\r\n******************** josephus������� ************************\r\n");
	//josephus(5,2,2);

	system("pause");
	return 0;
}



