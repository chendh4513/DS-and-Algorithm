#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item item, Node* pn);
static void CopyToItem(Node* pn, Item* pi);


/* ���г�ʼ��*/
void InitQueue(Queue* pq)
{
	pq->front = pq->rear = NULL;
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
	Node* pnew;

	if (QueueIsFull(pq))
	{
		printf("����Ϊ����\n");
		return false;
	}

	pnew = (Node*)malloc(sizeof(Node));

	if (pnew == NULL)
	{
		printf("����ʧ�ܣ�\n");
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

/* ��һ��Ԫ���Ƴ�����*/
bool DeQueue(Item* pitem, Queue* pq)
{
	Node* pt;

	if (QueueIsEmpty(pq))
	{
		printf("����Ϊ�գ�\n");
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

/* ��ն���*/
void EmptyTheQueue(Queue* pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

/* ����Ϊqueue.cpp�ھֲ�����*/
static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}
