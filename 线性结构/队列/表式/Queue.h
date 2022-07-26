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

/* 队列初始化*/
void InitQueue(Queue* pq);

/* 队列是否为空*/
bool QueueIsEmpty(const Queue* pq);

/* 队列是否为满*/
bool QueueIsFull(const Queue* pq);

/* 队列长度*/
int QueueLen(const Queue* pq);

/* 将一个元素加入队列*/
bool Enqueue(Item item, Queue* pq);

/* 将一个元素移除队列*/
bool DeQueue(Item* pitem, Queue* pq);

/* 清空队列*/
void EmptyTheQueue(Queue* pq);

#endif //_QUEUE_H