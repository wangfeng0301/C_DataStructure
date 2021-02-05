/*********************************************************************
*��������
*���������������������нڵ�С�ڸýڵ㣬���������нڵ���ڸýڵ�
*			�������������нڵ�ֵ����Ψһ���������οɵõ���С��������
*�ο����ϣ������ݽṹ���㷨�������������ԣ��Ժ����
*wangfeng
*E-mail:fengwang0301@163.com
*CSDN:https://blog.csdn.net/u013073067?spm=1001.2101.3001.5343
*GitHub:https://github.com/wangfeng0301
*2019.11.28-2021.2.4
*2021.2.4	�޸ģ�����������������������
**********************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "tree_binary.h"
#include "stack.h"
#include "queue.h"
#include "misc.h"

/************************************************************************/
/* ���ܣ��ж�һ���������Ƿ�Ϊ����                                                     
/* ���룺tree:��������ַ
/* �������
/* ���أ��գ�TRUE ���ǿգ�FALSE
/************************************************************************/
bool BinaryTree_IsEmpty(BinaryTree_t *tree)
{
	if(tree->root == NULL)
		return TRUE;
	else
		return FALSE;
}

/************************************************************************/
/* ���ܣ�����һ��������
/* ���룺tree:��������ַ
/*		datlen:�������ͳ���
/*		rootdat:���ڵ�����
/* �����
/* ���أ�TRUE or FALSE
/************************************************************************/
bool BinaryTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat)
{
	BinaryTreeNode_t *root = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));//���ٽڵ�ռ�
	root->dat = (void *)malloc(datlen);						//�������ݿռ�
	if(root == NULL || root->dat == NULL)
	{
		printf("����ʧ��!\r\n");
		return FALSE;
	}
	memcpy(root->dat, rootdat, datlen);						//���ݸ�ֵ
	tree->root = root;
	tree->root->left = NULL;
	tree->root->right = NULL;
	tree->root->parent = NULL;
	tree->datlen = datlen;
	return TRUE;
}

/************************************************************************/
/* ���ܣ���ĳ�ڵ�����½ڵ�
/* ���룺tree:��������ַ
/*		parent:���ڵ㣬�ڴ˽ڵ�����
/*		dat:Ҫ����ڵ������
/*		LeftRight�������ӽڵ���뻹�����ӽڵ����
/* �������
/* ���أ�TRUE �ɹ���FALSE ʧ��
/* δ����ͨ��
/************************************************************************/
/*bool BinaryTree_InsertNode(BinaryTree_t *tree, BinaryTreeNode_t *parent, void *dat, unsigned char LeftRight)
{
	BinaryTreeNode_t *currentnode = NULL;

	if(parent == NULL)
	{
		printf("����ڵ㴦Ϊ�գ��޷������½ڵ㣡\r\n");
		return FALSE;
	}
	currentnode = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));
	currentnode->dat = (void *)malloc(tree->datlen);
	if(currentnode == NULL || currentnode->dat == NULL)
	{
		printf("����ռ�ʧ��\r\n");
		return FALSE;
	}
	memcpy(currentnode->dat, dat, tree->datlen);			//��ֵ

	//if(LeftRight == Left)
	{
		parent->left->parent = currentnode;
		currentnode->parent = parent;						//��ǰ�ڵ�ָ�򸸽ڵ�
		parent->left = currentnode;							//���ڵ����ӽڵ�ָ��ǰ�ڵ�
	}
	//else if(LeftRight == Right)
	{
		parent->right->parent = currentnode;
		currentnode->parent = parent;						//��ǰ�ڵ�ָ�򸸽ڵ�
		parent->right = currentnode;						//���ڵ����ӽڵ�ָ��ǰ�ڵ�
	}
	return TRUE;	
}*/

/************************************************************************/
/* ���ʵ�ǰ�ڵ�����                                                     */
/* tree:��������ַ
/* cunrrentnode:��ǰ�ڵ�
/* tree:��������ַ
/************************************************************************/
static void visit(BinaryTree_t *tree, BinaryTreeNode_t *currentnode)
{
	long value = void2long(currentnode->dat, tree->datlen);
	printf("%d ",value);
}

/************************************************************************/
/* ǰ�����ζ�����                                                       */
/************************************************************************/
void BinaryTree_PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		visit(tree, root);							//���ʵ�ǰ�ڵ�
		BinaryTree_PreOrder(tree, root->left);		//ǰ������������
		BinaryTree_PreOrder(tree, root->right);		//ǰ������������
	}
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void BinaryTree_InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		BinaryTree_InOrder(tree, root->left);		//��������������
		visit(tree, root);							//���ʵ�ǰ�ڵ�
		BinaryTree_InOrder(tree, root->right);		//��������������
	}
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void BinaryTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	if(root != NULL)
	{
		BinaryTree_PostOrder(tree, root->left);		//��������������
		BinaryTree_PostOrder(tree, root->right);	//��������������
		visit(tree, root);							//���ʵ�ǰ�ڵ�
	}
}
/************************************************************************/
/* ǰ�����ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void BinaryTree_PreOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t pointertemp;
	LinkStack_t temp;									//����ջ����
	LinkStack_Create(&temp, sizeof(BinaryTreeNode_t));	//����ջ

	while(pointer || !LinkStack_IsEmpty(&temp))			//ջ�ǿ�
	{
		visit(tree, pointer);							//���ʵ�ǰ�ڵ�
		if(pointer->right != NULL)						//�ǿ����ӽڵ���ջ
			LinkStack_Push(&temp, pointer->right);
		if(pointer->left != NULL)						
			pointer = pointer->left;					//��·�½�
		else
		{
			if(LinkStack_Pop(&temp, &pointertemp))		//ջ��Ԫ����ջ
				pointer = pointertemp.parent->right;	//��ѹջ�����ҽڵ�
			else
				pointer = NULL;
		}
	}
	LinkStack_Destroy(&temp);
}
/************************************************************************/
/* �������ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void BinaryTree_InOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t pointertemp;
	LinkStack_t temp;									//����ջ����
	LinkStack_Create(&temp, sizeof(BinaryTreeNode_t));	//����ջ

	while(pointer || !LinkStack_IsEmpty(&temp))			//ջ�ǿ�
	{
		if(pointer)
		{
			LinkStack_Push(&temp, pointer);
			pointer = pointer->left;					//��·�½�
		}
		else
		{
			if(LinkStack_Pop(&temp, &pointertemp))		//ջ��Ԫ����ջ
			{
				visit(tree, &pointertemp);				//���ʵ�ǰ�ڵ�
				pointer = pointertemp.right;			//ָ��ָ�����ӽڵ�
			}
			else
				pointer = NULL;
		}
	}
	LinkStack_Destroy(&temp);
}
/************************************************************************/
/* �������ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void BinaryTree_PostOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t *q = NULL;
	BinaryTreeNode_t pointertemp;
	LinkStack_t temp;									//����ջ����
	LinkStack_Create(&temp, sizeof(BinaryTreeNode_t));	//����ջ
	if(root == NULL)									//�����򷵻�
		return;
	else
		pointer = root;
	while(pointer || !LinkStack_IsEmpty(&temp))			//ջ�ǿ�
	{
		while(pointer != NULL)							//�����ǰָ��ǿգ���ѹջ���½��������ӽڵ�
		{					
			LinkStack_Push(&temp, pointer);				
			pointer = pointer->left;					//����·�½�
		}
		LinkStack_GetTop(&temp, &pointertemp);			//��·�½����ף�ȡջ��Ԫ��
		if(pointertemp.parent == NULL)					//���Ǹ��ڵ㸸�ڵ�Ϊ�յ����
			pointer = root;
		else if(pointertemp.parent->left)				//����ջ���ڵ㸸�ڵ�����ڵ����������Ȼջ���ڵ��Ȼ�Ǹ��ڵ���ҽڵ�
			pointer = pointertemp.parent->left;			
		else
			pointer = pointertemp.parent->right;
		if(pointer->right == NULL || pointer->right == q)//������������
		{
			visit(tree, pointer);
			/* 1.���ȡ���Ľڵ��ҽڵ�Ϊ�գ���Ӧҳ�ڵ������� */
			/* 2.���ȡ���Ľڵ��ҽڵ����q����Ӧ���ӽڵ��Ѿ�������������� */
			/* ���������������Ҫ�����ڵ㵯��ջ */
			LinkStack_Pop(&temp, &pointertemp);				
			q = pointer;
			pointer = NULL;
		}
		else											//���������������
		{
			pointer = pointer->right;					//�����������أ�����������
		}
	}
	LinkStack_Destroy(&temp);
}
/************************************************************************/
/* ������ζ�����                                                       */
/************************************************************************/
void BinaryTree_LevelOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTreeNode_t *pointer = root;
	BinaryTreeNode_t pointertemp, *q = NULL;
	LinkQueue_t queue;
	LinkQueue_Create(&queue, sizeof(BinaryTreeNode_t));	//��������
	if(pointer != NULL)
	{
		LinkQueue_En(&queue, pointer);					//���ڵ������
	}
	while(!LinkQueue_IsEmpty(&queue))					//���зǿ�
	{
		LinkQueue_De(&queue, &pointertemp);
		/* ����LinkQueue_De�������ݲ������ڵ㱾���ַ��Ϣ */
		/* ����Ҫ�жϳ������ڵ�ĵ�ַ���Ա����ѭ�� */
		if(pointertemp.parent == NULL)					//���ǳ����нڵ��Ǹ��ڵ�����
			pointer = root;
		/* q�������ӽڵ� */
		/* ��Ҫ���ǽڵ�û����ڵ����� */
		else if(pointertemp.parent->left == q || pointertemp.parent->left == NULL)
		{
			pointer = pointertemp.parent->right;
			q = NULL;
		}
		else
		{
			pointer = pointertemp.parent->left;
			q = pointer;
		}
		visit(tree, pointer);							//���ʵ�ǰ�ڵ�
		if(pointer->left != NULL)
			LinkQueue_En(&queue,pointer->left);			//������������
		if(pointer->right != NULL)
			LinkQueue_En(&queue,pointer->right);		//������������
	}
	LinkQueue_Destroy(&queue);
}

/******************************************** ���������� *******************************************************/
/*************************************************************************************/
/*���ܣ������������Ƿ�Ϊ��
/*���룺tree:�����������ĵ�ַ
/*�������
/*���أ��գ�TRUE ���ǿգ�FALSE
/*************************************************************************************/
bool BinarySearchTree_IsEmpty(BinaryTree_t *tree)
{
	return BinaryTree_IsEmpty(tree);
}

/*************************************************************************************/
/*���ܣ���������������
/*���룺tree:�����������ĵ�ַ
/*�������
/*���أ�TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_Create(BinaryTree_t *tree, uint datlen, void *rootdat)
{
	return BinaryTree_Create(tree, datlen, rootdat);
}

/*************************************************************************************/
/*���ܣ������������ڵ�����㷨�������������ݴ�С���Զ�ѡ����ʵĽڵ���롣
/*		���������϶������������ص㣬������С��������
/*���룺tree:�����������ĵ�ַ
/*		dat:�������½ڵ������
/*�������
/*���أ�TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_InsertNode(BinaryTree_t *tree, void *dat)
{
	BinaryTreeNode_t *pointer = NULL;
	BinaryTreeNode_t *newpointer = NULL;
	BinaryTreeNode_t *temp;
	long newvalue = 0,pointervalue = 0;
	uchar i = 0;

	newpointer = (BinaryTreeNode_t *)malloc(sizeof(BinaryTreeNode_t));
	newpointer->dat = (void *)malloc(tree->datlen);
	if(newpointer == NULL || newpointer->dat == NULL)
	{
		printf("����ռ�ʧ��\r\n");
		return FALSE;
	}
	memcpy(newpointer->dat, dat, tree->datlen);
	newpointer->left = NULL;
	newpointer->right = NULL;
	newpointer->parent = NULL;
	/* ����Ϊ�գ����½ڵ���Ϊ����,�����¼���ڵ� */
	if(tree->root == NULL)
	{
		tree->root = newpointer;
		return TRUE;
	}
	else
		pointer = tree->root;
	while(pointer != NULL)
	{
		newvalue = void2long(newpointer->dat, tree->datlen);
		pointervalue = void2long(pointer->dat, tree->datlen);
		if(newvalue == pointervalue)						//�������Ԫ���򲻲���
		{
			printf("���������Ԫ����ȵ�ֵ %d\r\n",newpointer->dat);
			goto err;
		}
		else if(newvalue < pointervalue)					//������ڵ�С�ڵ�ǰ�ڵ�ؼ���ֵ
		{
			if(pointer->left == NULL)						//���pointerû��������
			{
				temp = pointer->left;
				pointer->left = newpointer;					//newpointer��Ϊpointer������
				newpointer->parent = pointer;
				newpointer->left = temp;
				return TRUE;
			}
			else
				pointer = pointer->left;					//�����½�
		}
		else if(newvalue > pointervalue)
		{
			if(pointer->right == NULL)						//���pointerû��������
			{
				temp = pointer->right;
				pointer->right = newpointer;				//newpointer��Ϊpointer������
				newpointer->parent = pointer;
				newpointer->right = temp;
				return TRUE;
			}
			else
				pointer = pointer->right;					//�����½�
		}
	}
err:
	free(newpointer->dat);
	newpointer->dat = NULL;
	free(newpointer);
	newpointer = NULL;
	return FALSE;
}

/*************************************************************************************/
/*���ܣ��������������ҽڵ��㷨
/*���룺tree:�����������ĵ�ַ
/*		dat:Ҫ���ҽڵ�����ݵ�ָ��
/*�����
/*���أ���������ֵ�Ľڵ��ַ
/*************************************************************************************/
BinaryTreeNode_t* BinarySearchTree_SearchNode(BinaryTree_t *tree, void *dat)
{
	BinaryTreeNode_t *pointer = NULL;
	uchar i = 0;
	long datvalue = 0,pointervalue = 0;

	if(BinarySearchTree_IsEmpty(tree))						//����ǿ���
	{
		printf("������Ϊ�գ�\r\n");
		return NULL;
	}
	else
		pointer = tree->root;
	while(pointer != NULL)
	{
		datvalue = void2long(dat, tree->datlen);
		pointervalue = void2long(pointer->dat, tree->datlen);
		if(datvalue == pointervalue)									
		{
			printf("�ҵ��� %d\r\n",pointervalue);
			return pointer;
		}
		else if(datvalue < pointervalue)				//Ҫ���ҵ�ֵС�ڵ�ǰ�ڵ�ֵ���������
		{
			if(pointer->left == NULL)										
			{
				printf("�˶������в����ڴ�ֵ��\r\n");
				return NULL;
			}
			else
				pointer = pointer->left;				//�����½�
		}
		else if(datvalue > pointervalue)				//Ҫ���ҵ�ֵ���ڵ�ǰ�ڵ�ֵ�����Ҳ���
		{
			if(pointer->right == NULL)					//���pointerû��������
			{
				printf("�˶������в����ڴ�ֵ��\r\n");
				return NULL;
			}
			else
				pointer = pointer->right;				//�����½�
		}
	}
	printf("�˶������в����ڴ�ֵ��\r\n");
	return NULL;
}

/*************************************************************************************/
/*���ܣ������������ڵ�ɾ���㷨															 
/*���룺tree:������������ַ
/*		pointer:��ɾ���ڵ�
/*�������
/*���أ�TRUE or FALSE
/*************************************************************************************/
bool BinarySearchTree_DeleteNode(BinaryTree_t *tree, BinaryTreeNode_t *pointer)
{
	BinaryTreeNode_t *temppointer;							//���ڱ����滻��ɾ���ڵ�Ľڵ�
	BinaryTreeNode_t *tempparent = NULL;					//���ڱ����滻�ڵ�ĸ��ڵ�
	if(pointer == NULL)										//��ɾ���ڵ㲻����
	{
		printf("�ڵ㲻���ڣ�\r\n");
		return FALSE;
	}
	if(pointer->left == NULL)								//�����ɾ���ڵ�������Ϊ��
		temppointer = pointer->right;						//�滻�ڵ㸳ֵΪ��������
	else													//�滻�ڵ���������Ϊ�գ�����������Ѱ�����ڵ���Ϊ�滻�ڵ�
	{
		temppointer = pointer->left;						//�滻�ڵ㸳ֵΪ������
		while(temppointer->right != NULL)					//Ѱ�������������ڵ㣬����·�½�����
		{
			tempparent = temppointer;						//�����滻�ڵ�ĸ��ڵ�
			temppointer = temppointer->right;				//�����½�
		}
		if(tempparent == NULL)								//����滻�ڵ���Ǳ�ɾ���ڵ�����ӽڵ㣬�򲻻���������whileѭ��
			pointer->left = temppointer->left;				//�滻�ڵ��������ҽӵ���ɾ���ڵ��������
		else
			tempparent->right = temppointer->left;			//�滻�ڵ����������Ϊ�丸�ڵ��������
		temppointer->left = pointer->left;					//�̳�pointer������
		temppointer->right = pointer->right;				//�̳�pointer��������
		temppointer->parent = pointer->parent;				//�̳�pointer�ĸ��ڵ�
	}

	//�������滻�ڵ�����ɾ���ڵ�
	if(pointer->parent == NULL)								//��ɾ���ڵ�Ϊ���ڵ�
		temppointer->parent = NULL;
	else if(pointer->parent->left == pointer)				//��ɾ���ڵ�����丸�ڵ��������
		pointer->parent->left = temppointer;
	else													//��ɾ���ڵ�����丸�ڵ��������
		pointer->parent->right = temppointer;				

	free(pointer->dat);
	pointer->dat = NULL;
	free(pointer);											//�ͷŽڵ��ڴ�
	pointer = NULL;
	return TRUE;
}
/************************************************************************/
/* ǰ�����ζ�����                                                       */
/************************************************************************/
void BinarySearchTree_PreOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PreOrder(tree, root);
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void BinarySearchTree_InOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_InOrder(tree, root);
}
/************************************************************************/
/* �������ζ�����                                                       */
/************************************************************************/
void BinarySearchTree_PostOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PostOrder(tree, root);
}
/************************************************************************/
/* ǰ�����ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void BinarySearchTree_PreOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PreOrderNonRecursion(tree, root);
}
/************************************************************************/
/* �������ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void BinarySearchTree_InOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_InOrderNonRecursion(tree, root);
}
/************************************************************************/
/* �������ζ�����,�ǵݹ鷽��                                            */
/************************************************************************/
void BinarySearchTree_PostOrderNonRecursion(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_PostOrderNonRecursion(tree, root);
}
/************************************************************************/
/* ������ζ�����                                                       */
/************************************************************************/
void BinarySearchTree_LevelOrder(BinaryTree_t *tree, BinaryTreeNode_t *root)
{
	BinaryTree_LevelOrder(tree, root);
}

void testBinaryTree(void)
{
	unsigned char i=0;
	BinaryTree_t root;
	int val[10] = {0,1,2,3,4,5,6,7,8,9};
	int tempval;
	BinaryTreeNode_t *temp;//��ʱ�ڵ�

	if(!BinaryTree_Create(&root, sizeof(val[0]), &val[9]))//����������
	{
		printf("����������ʧ��\r\n");
		return;
	}

	for(i = 0;i<3;i++)//����10���ڵ㣬���ն�������������ʽ���д�С
	//for(i = 4;i>0;i--)//����10���ڵ㣬���ն�������������ʽ���д�С
	{
		tempval = i+1;
		BinarySearchTree_InsertNode(&root, &tempval);
	}
	printf("\r\n���������\r\n");
	BinarySearchTree_InOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_InOrderNonRecursion(&root, root.root);

	printf("\r\nǰ�������\r\n");
	BinarySearchTree_PreOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_PreOrderNonRecursion(&root, root.root);

	printf("\r\n���������\r\n");
	BinarySearchTree_PostOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_PostOrderNonRecursion(&root, root.root);

	printf("\r\n������Σ�\r\n");
	BinaryTree_LevelOrder(&root, root.root);
	printf("\r\n\r\n");

	if(NULL != (temp = BinarySearchTree_SearchNode(&root, &val[1])))
		BinarySearchTree_DeleteNode(&root, temp);//ɾ���ڵ�
	printf("���������\r\n");
	BinarySearchTree_InOrder(&root, root.root);
	printf("\r\n");
	BinaryTree_InOrderNonRecursion(&root, root.root);
}