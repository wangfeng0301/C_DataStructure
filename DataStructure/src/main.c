#include <stdio.h>
#include <string.h>
#include "link.h"
#include "DoubleLink.h"
#include "application.h"
#include "stack.h"
#include "queue.h"
#include "mystring.h"
#include "BinaryTree.h"
#include "heap.h"
#include "tree.h"
#include "sort.h"

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

	printf("\r\n*************************����������***************************\r\n");
	testBinaryTree();

	printf("\r\n****************************�Ѳ���****************************\r\n");
	testHeap();

	printf("\r\n***********************Huffman������**************************\r\n");
	testHuffmanTree();

	printf("\r\n***************************������*****************************\r\n");
	testTree();

	printf("\r\n**************************�������****************************\r\n");
	testSort();

	system("pause");
	return 0;
}



