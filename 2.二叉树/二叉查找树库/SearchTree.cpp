#include <stdio.h>
#include <stdlib.h>
#include "SearchTree.h"

/* 初始化树*/
SearchTree InitTree(SearchTree T)
{
	T = NULL;
	return T;
}

/* 查找结点*/
Position FindNode(const SearchTree T, Item item)
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
Position FindMax(const SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

/* 查找最小结点*/
Position FindMin(const SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMax(T->Left);
}

/* 插入结点*/
SearchTree Insert(SearchTree T, Item item)
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
	}
	else if (item > T->item)
		T->Right = Insert(T->Right, item);
	else if (item < T->item)
		T->Left = Insert(T->Left, item);

	return T;
}

/* 删除结点*/
SearchTree Delete(SearchTree T, Item item)
{
	Node* p;

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
		if (T->Left && T->Right)
		{
			p = FindMax(T->Left);
			T->item = p->item;
			p->item = item;
			T->Left = Delete(T->Left, item);
		}
		else
		{
			if (T->Left == NULL && T->Right)
			{
				T->item = T->Right->item;
				p = T->Right;
			}
			else if (T->Right == NULL && T->Left)
			{
				T->item = T->Left->item;
				p = T->Left;
			}
			else
			{
				p = T;
			}
			free(p);
		}
	}
	return T;
}

/* 清空树*/
void EmptyTree(SearchTree T)
{
	if (T != NULL)
	{
		EmptyTree(T->Left);
		EmptyTree(T->Right);
		free(T);
	}
}