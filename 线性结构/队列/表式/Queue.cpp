#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/* 队列初始化*/
void InitQueue(Queue* pq)
{
	pq->front = -1;
	pq->rear = 0;
	pq->items = 0;
}

/* 队列是否为空*/
bool QueueIsEmpty(const Queue* pq)
{
	return pq->items == 0;
}

/* 队列是否为满*/
bool QueueIsFull(const Queue* pq)
{
	return pq->items == MAXQUEUE;
}

/* 队列长度*/
int QueueLen(const Queue* pq)
{
	return pq->items;
}

/* 将一个元素加入队列*/
bool Enqueue(Item item, Queue* pq)
{

	if (QueueIsFull(pq))
	{
		printf("队列为满！\n");
		return false;
	}

	pq->rear = (pq->rear + 1)%MAXQUEUE;
	pq->item[pq->rear] = item;
	pq->items++;

	return true;
}

/* 将一个元素移除队列*/
bool DeQueue(Item* pitem, Queue* pq)
{

	if (QueueIsEmpty(pq))
	{
		printf("队列为空！\n");
		return false;
	}

	*pitem = pq->item[pq->front];
	pq->front = (pq->front + 1) % MAXQUEUE;
	pq->items--;

	return true;
}

/* 清空队列*/
void EmptyTheQueue(Queue* pq)
{
	pq->front = -1;
	pq->rear = 0;
	pq->items = 0;
}
