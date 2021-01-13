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

	printf("\r\n************************¡¥ Ω∂”¡–≤‚ ‘**************************\r\n");
	testLinkQueue();

	printf("\r\n*************************∂˛≤Ê ˜≤‚ ‘***************************\r\n");
	testBinaryTree();

	printf("\r\n****************************∂—≤‚ ‘****************************\r\n");
	testHeap();

	printf("\r\n*********************** Huffman ˜≤‚ ‘ ************************\r\n");
	testHuffmanTree();

	printf("\r\n*************************** ˜≤‚ ‘*****************************\r\n");
	testTree();

	printf("\r\n**************************≈≈–Ú≤‚ ‘****************************\r\n");
	testSort();

	printf("\r\n******************** josephusŒ Ã‚≤‚ ‘ ************************\r\n");
	//josephus(5,2,2);

	system("pause");
	return 0;
}



