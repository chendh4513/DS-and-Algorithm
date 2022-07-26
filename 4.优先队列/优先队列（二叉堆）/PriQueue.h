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


/* ��ʼ�����ȶ���*/
bool InitPriorityQueue(int capacity, PriorityQueue* Q);

/* �����Ƿ��*/
bool IsEmpty(const PriorityQueue Q);

/* �����Ƿ���*/
bool IsFull(const PriorityQueue Q);

/* ����Ԫ��*/
bool Insert(Item item, PriorityQueue* Q);

/* ɾ��Ԫ��*/
Item DeleteMin(PriorityQueue* Q);

/* ������ȶ���*/
void EmptyQueue(PriorityQueue* Q);

/* ���͹ؼ��ʵ�ֵ*/
bool DecreaseItem(int loc, int delt, PriorityQueue* Q);

/* ��߹ؼ��ʵ�ֵ*/
bool IncreaseItem(int loc, int delt, PriorityQueue* Q);

/* ɾ��ָ��Ԫ��*/
bool Delete(int loc, PriorityQueue* Q);

/* ������*/
PriorityQueue BuildHeap(Item A[], int len);




#endif // !PRIORITYQUEUE

