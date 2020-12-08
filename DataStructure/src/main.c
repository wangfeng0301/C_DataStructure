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
	printf("\r\n**************************µ•¡¥±Ì≤‚ ‘**************************\r\n");
	testLink();

	printf("\r\n**************************À´¡¥±Ì≤‚ ‘**************************\r\n");
	testDoubleLink();

	printf("\r\n************************—≠ª∑À´¡¥±Ì≤‚ ‘************************\r\n");
	testCycDoubleLink();

	printf("\r\n**************************◊÷∑˚¥Æ≤‚ ‘**************************\r\n");
	testString();

	printf("\r\n****************************’ª≤‚ ‘****************************\r\n");
	testStack();

	printf("\r\n*************************¡¥ Ω’ª≤‚ ‘***************************\r\n");
	testLinkStack();

	printf("\r\n**************************µ›πÈ≤‚ ‘****************************\r\n");
	testRecursion();
	
	printf("\r\n***************************∂”¡–≤‚ ‘***************************\r\n");
	testQueue();

	printf("\r\n*************************∂˛≤Ê ˜≤‚ ‘***************************\r\n");
	testBinaryTree();

	printf("\r\n****************************∂—≤‚ ‘****************************\r\n");
	testHeap();

	printf("\r\n***********************Huffman ˜≤‚ ‘**************************\r\n");
	testHuffmanTree();

	printf("\r\n*************************** ˜≤‚ ‘*****************************\r\n");
	testTree();

	printf("\r\n**************************≈≈–Ú≤‚ ‘****************************\r\n");
	testSort();

	system("pause");
	return 0;
}



