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

/* 初始化哈希表*/
bool InitHashTable(int size, HashTable* H);

/* 查找元素*/
Position Find(Item item, const HashTable H);

/* 查找元素前一个元素*/
Position FindPre(Item item, const HashTable H);

/* 插入元素*/
bool Insert(Item item, HashTable* H);

/* 删除元素*/
bool Delete(Item item, HashTable* H);

/* 清空哈希表*/
void EmptyTable(HashTable* H);


#endif // !HASH_SEP_1

