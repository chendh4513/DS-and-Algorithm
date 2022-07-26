#include <stdio.h>
#include <stdlib.h>
#include "HashSep1.h"

/* ��ϣ����*/
int Hash(Item item, int TableSize);

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

	H->list = (Node**)malloc(sizeof(Node*) * H->TableSize);
	if(H->list == NULL)
	{
		printf("�ռ����ʧ�ܣ�");
		return false;
	 } 

	for (int i = 0; i < H->TableSize; i++)
	{
		H->list[i] = (Node*)malloc(sizeof(Node));
		if (H->list[i] == NULL)
		{
			printf("�ռ����ʧ�ܣ�");
			return false;
		}
		else
			H->list[i]->next = NULL;
	}

	return true;
}

/* ����Ԫ��*/
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

/* ����Ԫ��ǰһ��Ԫ��*/
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

/* ����Ԫ��*/
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
			printf("�ռ����ʧ��!");
			return false;
		}
		pNew->item = item;
		L = H->list[Hash(item, H->TableSize)];
		pNew->next = L->next;
		L->next = pNew;
	}
	return true;
}

/* ɾ��Ԫ��*/
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

/* ��չ�ϣ��*/
void EmptyTable(HashTable* H)
{
	for (int i = 0; i < H->TableSize; i++)
	{
		free(H->list[i]);
	}
	free(H);
}

/* Hash����*/
int Hash(Item item, int TableSize)
{
	return item % MAXSIZE;
}
