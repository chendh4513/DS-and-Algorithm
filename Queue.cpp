#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/* ���г�ʼ��*/
void InitQueue(Queue* pq)
{
	pq->front = -1;
	pq->rear = 0;
	pq->items = 0;
}

/* �����Ƿ�Ϊ��*/
bool QueueIsEmpty(const Queue* pq)
{
	return pq->items == 0;
}

/* �����Ƿ�Ϊ��*/
bool QueueIsFull(const Queue* pq)
{
	return pq->items == MAXQUEUE;
}

/* ���г���*/
int QueueLen(const Queue* pq)
{
	return pq->items;
}

/* ��һ��Ԫ�ؼ������*/
bool Enqueue(Item item, Queue* pq)
{

	if (QueueIsFull(pq))
	{
		printf("����Ϊ����\n");
		return false;
	}

	pq->rear = (pq->rear + 1)%MAXQUEUE;
	pq->item[pq->rear] = item;
	pq->items++;

	return true;
}

/* ��һ��Ԫ���Ƴ�����*/
bool DeQueue(Item* pitem, Queue* pq)
{

	if (QueueIsEmpty(pq))
	{
		printf("����Ϊ�գ�\n");
		return false;
	}

	*pitem = pq->item[pq->front];
	pq->front = (pq->front + 1) % MAXQUEUE;
	pq->items--;

	return true;
}

/* ��ն���*/
void EmptyTheQueue(Queue* pq)
{
	pq->front = -1;
	pq->rear = 0;
	pq->items = 0;
}
