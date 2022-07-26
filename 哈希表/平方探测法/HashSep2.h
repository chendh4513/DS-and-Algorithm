#pragma once

#ifndef HASH_SEP_1
#define HASH_SEP_1

#define MAXSIZE 100
#define MINSIZE 10

typedef unsigned int Position;
typedef int Item;
enum Kind {Legitimate, Empty, Deleted};

typedef struct node
{
	Item item;
	enum Kind Info;
}Node;

typedef struct hashtable
{
	int TableSize;
	Node* list;
}HashTable;

/* ��ʼ����ϣ��*/
bool InitHashTable(int size, HashTable* H);

/* ����Ԫ��*/
Position Find(Item item, const HashTable H);

/* ����Ԫ��*/
bool Insert(Item item, HashTable* H);

/* ɾ��Ԫ��*/
bool Delete(Item item, HashTable* H);

/* ��չ�ϣ��*/
void EmptyTable(HashTable* H);


#endif // !HASH_SEP_1

