#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item item, Node* pn);
static void CopyToItem(Node* pn, Item* pi);


/* 队列初始化*/
void InitQueue(Queue* pq)
{
	pq->front = pq->rear = NULL;
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
	Node* pnew;

	if (QueueIsFull(pq))
	{
		printf("队列为满！\n");
		return false;
	}

	pnew = (Node*)malloc(sizeof(Node));

	if (pnew == NULL)
	{
		printf("分配失败！\n");
		exit(1);
	}

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))
	{
		pq->front = pnew;
	}
	else
	{
		pq->rear->next = pnew;
	}
	pq->rear = pnew;
	pq->items++;

	return true;
}

/* 将一个元素移除队列*/
bool DeQueue(Item* pitem, Queue* pq)
{
	Node* pt;

	if (QueueIsEmpty(pq))
	{
		printf("队列为空！\n");
		return false;
	}

	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (QueueIsEmpty(pq))
		pq->rear = NULL;
	return true;
}

/* 清空队列*/
void EmptyTheQueue(Queue* pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

/* 以下为queue.cpp内局部函数*/
static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}
