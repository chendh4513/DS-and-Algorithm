#include <stdio.h>
#include <stdlib.h>
#include "HashSep1.h"

/* 哈希函数*/
int Hash(Item item, int TableSize);

/* 初始化哈希表*/
bool InitHashTable(int size, HashTable* H)
{
	if (size<MINSIZE || size>MAXSIZE)
	{
		printf("散列表大小不合适!");
		H = NULL;
		return false;
	}
	H = (HashTable*)malloc(sizeof(HashTable));
	if (H == NULL)
	{
		printf("空间分配失败！");
		return false;
	}
	H->TableSize = size;

	H->list = (Node**)malloc(sizeof(Node*) * H->TableSize);
	if(H->list == NULL)
	{
		printf("空间分配失败！");
		return false;
	 } 

	for (int i = 0; i < H->TableSize; i++)
	{
		H->list[i] = (Node*)malloc(sizeof(Node));
		if (H->list[i] == NULL)
		{
			printf("空间分配失败！");
			return false;
		}
		else
			H->list[i]->next = NULL;
	}

	return true;
}

/* 查找元素*/
Position Find(Item item, const HashTable H)
{
	Position loc;
	Node* L;

	L = H.list[Hash(item, H.TableSize)];
	loc = L->next;
	while (loc->item != item)
	{
		loc = loc->next;
	}
	return loc;
}

/* 查找元素前一个元素*/
Position FindPre(Item item, const HashTable H)
{
	Position pre;
	Position loc;
	Node* L;

	L = H.list[Hash(item, H.TableSize)];
	loc = L->next;
	pre = L;
	while (loc->item != item && loc != NULL)
	{
		loc = loc->next;
		pre = pre->next;
	}
	return pre;
}

/* 插入元素*/
bool Insert(Item item, HashTable* H)
{
	Position loc;
	Node* pNew;
	Node* L;

	loc = Find(item, *H);
	if (loc = NULL)
	{
		pNew = (Node*)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("空间分配失败!");
			return false;
		}
		pNew->item = item;
		L = H->list[Hash(item, H->TableSize)];
		pNew->next = L->next;
		L->next = pNew;
	}
	return true;
}

/* 删除元素*/
bool Delete(Item item, HashTable* H)
{
	Position locpre;
	Position loc;

	locpre = FindPre(item, *H);
	if (locpre->next != NULL)
	{
		loc = locpre->next;
		locpre->next = loc->next;
		free(loc);
	}
	return true;
}

/* 清空哈希表*/
void EmptyTable(HashTable* H)
{
	for (int i = 0; i < H->TableSize; i++)
	{
		free(H->list[i]);
	}
	free(H);
}

/* Hash函数*/
int Hash(Item item, int TableSize)
{
	return item % MAXSIZE;
}
