#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

/* ���ؽϴ��ֵ*/
static int Max(int a, int b);

/* ������*/
static int Height(const AvlTree T);

/* ����ת*/
static AvlTree SingleRatateLeft(AvlTree T);

/* �ҵ���ת*/
static AvlTree SingleRatateRight(AvlTree T);

/* ����˫��*/
static AvlTree DoubleeRatateLeft(AvlTree T);

/* ����˫��*/
static AvlTree DoubleeRatateRight(AvlTree T);

/* ��ʼ����*/
AvlTree InitTree(AvlTree T)
{
	T = NULL;
	return T;
}

/* ���ҽ��*/
Position FindNode(const AvlTree T, Item item)
{
	if (T == NULL)
		return NULL;
	if (T->item = item)
		return T;
	else if (T->item > item)
		return FindNode(T->Left, item);
	else
		return FindNode(T->Left, item);
}

/* ���������*/
Position FindMax(const AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

/* ������С���*/
Position FindMin(const AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMax(T->Left);
}

/* ������*/
AvlTree Insert(AvlTree T, Item item)
{
	if (T == NULL)
	{
		T = (Node*)malloc(sizeof(Node));
		if (T == NULL)
		{
			printf("����ʧ�ܣ�");
			exit(1);
		}
		T->item = item;
		T->Left = T->Right = NULL;
		T->height = 0;
	}
	else if (item > T->item)
	{
		T->Right = Insert(T->Right, item);
		if (Height(T->Right) - Height(T->Right) == 2)
		{
			if (item > T->Right->item)
				T = SingleRatateRight(T);
			else
				T = DoubleeRatateRight(T);
		}
	}
	else if (item < T->item)
	{
		T->Left = Insert(T->Left, item);
		if (Height(T->Left) - Height(T->Left) == -2)
		{
			if (item > T->Left->item)
				T = SingleRatateLeft(T);
			else
				T = DoubleeRatateLeft(T);
		}
	}

	T->height = 1 + Max(Height(T->Left), Height(T->Right));
	return T;
}

/* ɾ�����*/
AvlTree Delete(AvlTree T, Item item)
{

	if (T == NULL)
	{
		printf("�޴˽ڵ㣡");
	}
	else if (item > T->item)
		T->Right = Delete(T->Right, item);
	else if (item < T->item)
		T->Left = Delete(T->Left, item);
	else
	{
		T->item = Deleted;
		T->height = -1;
	}
	return T;
}

/* �����*/
void EmptyTree(AvlTree T)
{
	if (T != NULL)
	{
		EmptyTree(T->Left);
		EmptyTree(T->Right);
		free(T);
	}
}

/* ����Ϊ�ڲ�����-----------------------------------------*/

/* ���ؽϴ��ֵ*/
static int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

/* ������*/
static int Height(const AvlTree T)
{
	return T->height;
}

/* ����ת*/
static AvlTree SingleRatateLeft(AvlTree T)
{
	Position T1;                                                                                   
																							          
	T1 = T->Left;																		     	
	T->Left = T1->Right;																	   
	T1->Right = T;																		   	  

	T->height = 1 + Max(Height(T->Left), Height(T->Right));
	T1->height = 1 + Max(Height(T1->Left), Height(T1->Right));

	return T1;
}

/* �ҵ���ת*/
static AvlTree SingleRatateRight(AvlTree T)
{
	Position T1;

	T1 = T->Right;
	T->Right = T1->Left;
	T1->Left = T;

	T->height = 1 + Max(Height(T->Left), Height(T->Right));
	T1->height = 1 + Max(Height(T1->Left), Height(T1->Right));

	return T1;
}

/* ����˫��*/
static AvlTree DoubleeRatateLeft(AvlTree T)
{
	T->Left = SingleRatateLeft(T->Left);

	return SingleRatateRight(T);
}

/* ����˫��*/
static AvlTree DoubleeRatateRight(AvlTree T)
{
	T->Right = SingleRatateRight(T->Right);

	return SingleRatateLeft(T);
}
