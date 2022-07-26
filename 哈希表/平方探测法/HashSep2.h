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

/* 初始化哈希表*/
bool InitHashTable(int size, HashTable* H);

/* 查找元素*/
Position Find(Item item, const HashTable H);

/* 插入元素*/
bool Insert(Item item, HashTable* H);

/* 删除元素*/
bool Delete(Item item, HashTable* H);

/* 清空哈希表*/
void EmptyTable(HashTable* H);


#endif // !HASH_SEP_1

