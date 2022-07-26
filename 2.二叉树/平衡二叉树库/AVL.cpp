#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

/* 返回较大的值*/
static int Max(int a, int b);

/* 求树高*/
static int Height(const AvlTree T);

/* 左单旋转*/
static AvlTree SingleRatateLeft(AvlTree T);

/* 右单旋转*/
static AvlTree SingleRatateRight(AvlTree T);

/* 左右双旋*/
static AvlTree DoubleeRatateLeft(AvlTree T);

/* 右左双旋*/
static AvlTree DoubleeRatateRight(AvlTree T);

/* 初始化树*/
AvlTree InitTree(AvlTree T)
{
	T = NULL;
	return T;
}

/* 查找结点*/
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

/* 查找最大结点*/
Position FindMax(const AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

/* 查找最小结点*/
Position FindMin(const AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMax(T->Left);
}

/* 插入结点*/
AvlTree Insert(AvlTree T, Item item)
{
	if (T == NULL)
	{
		T = (Node*)malloc(sizeof(Node));
		if (T == NULL)
		{
			printf("插入失败！");
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

/* 删除结点*/
AvlTree Delete(AvlTree T, Item item)
{

	if (T == NULL)
	{
		printf("无此节点！");
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

/* 清空树*/
void EmptyTree(AvlTree T)
{
	if (T != NULL)
	{
		EmptyTree(T->Left);
		EmptyTree(T->Right);
		free(T);
	}
}

/* 以下为内部函数-----------------------------------------*/

/* 返回较大的值*/
static int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

/* 求树高*/
static int Height(const AvlTree T)
{
	return T->height;
}

/* 左单旋转*/
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

/* 右单旋转*/
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

/* 左右双旋*/
static AvlTree DoubleeRatateLeft(AvlTree T)
{
	T->Left = SingleRatateLeft(T->Left);

	return SingleRatateRight(T);
}

/* 右左双旋*/
static AvlTree DoubleeRatateRight(AvlTree T)
{
	T->Right = SingleRatateRight(T->Right);

	return SingleRatateLeft(T);
}
