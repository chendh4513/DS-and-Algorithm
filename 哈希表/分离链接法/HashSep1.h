#pragma once

#ifndef HASH_SEP_1
#define HASH_SEP_1

#define MAXSIZE 100
#define MINSIZE 10

typedef int Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* Position;

typedef struct hashtable
{
	int TableSize;
	Node** list;
}HashTable;

/* ��ʼ����ϣ��*/
bool InitHashTable(int size, HashTable* H);

/* ����Ԫ��*/
Position Find(Item item, const HashTable H);

/* ����Ԫ��ǰһ��Ԫ��*/
Position FindPre(Item item, const HashTable H);

/* ����Ԫ��*/
bool Insert(Item item, HashTable* H);

/* ɾ��Ԫ��*/
bool Delete(Item item, HashTable* H);

/* ��չ�ϣ��*/
void EmptyTable(HashTable* H);


#endif // !HASH_SEP_1

