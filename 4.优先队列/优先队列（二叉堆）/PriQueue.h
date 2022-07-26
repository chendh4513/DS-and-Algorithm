#pragma once

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#define MAXSIZE 100
#define MINSIZE 10
#define Mindata -65535

typedef int Item;

typedef struct priorityqueue
{
	int Capacity;
	int size;
	Item* item;
}PriorityQueue;


/* 初始化优先队列*/
bool InitPriorityQueue(int capacity, PriorityQueue* Q);

/* 队列是否空*/
bool IsEmpty(const PriorityQueue Q);

/* 队列是否满*/
bool IsFull(const PriorityQueue Q);

/* 插入元素*/
bool Insert(Item item, PriorityQueue* Q);

/* 删除元素*/
Item DeleteMin(PriorityQueue* Q);

/* 清空优先队列*/
void EmptyQueue(PriorityQueue* Q);

/* 降低关键词的值*/
bool DecreaseItem(int loc, int delt, PriorityQueue* Q);

/* 提高关键词的值*/
bool IncreaseItem(int loc, int delt, PriorityQueue* Q);

/* 删除指定元素*/
bool Delete(int loc, PriorityQueue* Q);

/* 构建堆*/
PriorityQueue BuildHeap(Item A[], int len);




#endif // !PRIORITYQUEUE

