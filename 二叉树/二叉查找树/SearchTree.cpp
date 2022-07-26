#include <stdio.h>
#include <stdlib.h>
#include "SearchTree.h"

/* ��ʼ����*/
SearchTree InitTree(SearchTree T)
{
	T = NULL;
	return T;
}

/* ���ҽ��*/
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

/* ���������*/
Position FindMax(const SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

/* ������С���*/
Position FindMin(const SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMax(T->Left);
}

/* ������*/
SearchTree Insert(SearchTree T, Item item)
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
	}
	else if (item > T->item)
		T->Right = Insert(T->Right, item);
	else if (item < T->item)
		T->Left = Insert(T->Left, item);

	return T;
}

/* ɾ�����*/
SearchTree Delete(SearchTree T, Item item)
{
	Node* p;

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

/* �����*/
void EmptyTree(SearchTree T)
{
	if (T != NULL)
	{
		EmptyTree(T->Left);
		EmptyTree(T->Right);
		free(T);
	}
}