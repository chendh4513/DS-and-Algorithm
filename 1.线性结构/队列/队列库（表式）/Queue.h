#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdbool.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct queue
{
	Item item[MAXQUEUE];
	int front;
	int rear;
	int items;
} Queue;

/* ���г�ʼ��*/
void InitQueue(Queue* pq);

/* �����Ƿ�Ϊ��*/
bool QueueIsEmpty(const Queue* pq);

/* �����Ƿ�Ϊ��*/
bool QueueIsFull(const Queue* pq);

/* ���г���*/
int QueueLen(const Queue* pq);

/* ��һ��Ԫ�ؼ������*/
bool Enqueue(Item item, Queue* pq);

/* ��һ��Ԫ���Ƴ�����*/
bool DeQueue(Item* pitem, Queue* pq);

/* ��ն���*/
void EmptyTheQueue(Queue* pq);

#endif //_QUEUE_H