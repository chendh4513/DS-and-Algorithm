#include <stdio.h>
#include <stdlib.h>
#include "HashSep1.h"

/* ��ϣ����*/
Position Hash(Item item, int TableSize);


/* ��ʼ����ϣ��*/
bool InitHashTable(int size, HashTable* H)
{
	if (size<MINSIZE || size>MAXSIZE)
	{
		printf("ɢ�б��С������!");
		H = NULL;
		return false;
	}
	H = (HashTable*)malloc(sizeof(HashTable));
	if (H == NULL)
	{
		printf("�ռ����ʧ�ܣ�");
		return false;
	}
	H->TableSize = size;

	H->list = (Node*)malloc(sizeof(Node) * H->TableSize);

	if (H->list == NULL)
	{
		printf("�ռ����ʧ�ܣ�");
		return false;
	}
	for (int i = 0; i < H->TableSize; i++)
	{
		H->list[i].Info = Empty;
	}

	return true;
}

/* ����Ԫ��*/
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

/* ����Ԫ��*/
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

/* ɾ��Ԫ��*/
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

/* ��չ�ϣ��*/
void EmptyTable(HashTable* H)
{
	free(H->list);
	free(H);
}

/* Hash����*/
Position Hash(Item item, int TableSize)
{
	return item % MAXSIZE;
}