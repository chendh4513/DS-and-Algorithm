#include <stdio.h>
#include <stdlib.h>
#include "HashSep1.h"

/* 哈希函数*/
Position Hash(Item item, int TableSize);


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

	H->list = (Node*)malloc(sizeof(Node) * H->TableSize);

	if (H->list == NULL)
	{
		printf("空间分配失败！");
		return false;
	}
	for (int i = 0; i < H->TableSize; i++)
	{
		H->list[i].Info = Empty;
	}

	return true;
}

/* 查找元素*/
Position Find(Item item, const HashTable H)
{
	Position loc;
	int num;

	num = 0;
	loc = Hash(item, H.TableSize);
	while (H.list[loc].Info != Empty && H.list[loc].item != item)
	{
		loc += 2 * num++ - 1;
		if (loc >= H.TableSize)
			loc -= H.TableSize;
	}

	return loc;

}

/* 插入元素*/
bool Insert(Item item, HashTable* H)
{
	Position loc;

	loc = Find(item, *H);
	if (H->list[loc].Info != Legitimate)
	{
		H->list[loc].Info = Legitimate;
		H->list[loc].item = item;
	}
	return true;
}

/* 删除元素*/
bool Delete(Item item, HashTable* H)
{
	Position loc;

	loc = Find(item, *H);
	if (H->list[loc].Info == Legitimate)
	{
		H->list[loc].Info = Empty;
	}
	return true;
}

/* 清空哈希表*/
void EmptyTable(HashTable* H)
{
	free(H->list);
	free(H);
}

/* Hash函数*/
Position Hash(Item item, int TableSize)
{
	return item % MAXSIZE;
}