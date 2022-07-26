#include <stdio.h>
#include <stdlib.h>
#include "PriQueue.h"

/* ��ʼ�����ȶ���*/
bool InitPriorityQueue(int capacity, PriorityQueue* Q)
{

	if (capacity > MAXSIZE || capacity < MINSIZE)
	{
		printf("��С�����ʣ�");
		return false;
	}

	Q = (PriorityQueue*)malloc(sizeof(PriorityQueue));

	if (Q == NULL)
	{
		printf("�ռ����ʧ�ܣ�");
		return false;
	}

	Q->item = (Item*)malloc(sizeof(Item) * (capacity + 1));

	if (Q->item == NULL)
	{
		printf("�ռ����ʧ�ܣ�");
		return false;
	}

	Q->Capacity = capacity;
	Q->size = 0;
	Q->item[0] = Mindata;

	return true;
}


/* �����Ƿ��*/
bool IsEmpty(const PriorityQueue Q)
{
	return Q.size == 0;
}

/* �����Ƿ���*/
bool IsFull(const PriorityQueue Q)
{
	return Q.size == Q.Capacity;
}


/* ����Ԫ��*/
bool Insert(Item item, PriorityQueue* Q)
{
	if (IsFull(*Q))
	{
		printf("����������");
		return false;
	}

	int i;

	for (i = ++Q->size ; Q->item[i / 2] > item ; i /= 2)
		Q->item[i] = Q->item[i / 2];

	Q->item[i] = item;

	return true;
}

/* ɾ��Ԫ��*/
Item DeleteMin(PriorityQueue* Q)
{
	if (IsEmpty(*Q))
	{
		printf("����Ϊ�գ�");
		return false;
	}
	
	Item MinItem = Q->item[1];
	Item LastItem = Q->item[Q->size--];
	int child,i;

	for (i = 1; 2 * i <= Q->size; i = child)
	{
		child = 2 * i;
		if (child != Q->size && Q->item[child + 1] < Q->item[child])
			child++;
		if (LastItem > Q->item[child])
			Q->item[i] = Q->item[child];
		else
			break;
	}

	Q->item[i] = LastItem;

	return LastItem;
}

/* ������ȶ���*/
void EmptyQueue(PriorityQueue* Q)
{
	free(Q->item);
	free(Q);
}

/* ���͹ؼ��ʵ�ֵ*/
bool DecreaseItem(int loc, int delt, PriorityQueue* Q)
{
	if (loc > Q->size)
	{
		printf("�޴�Ԫ�أ�");
		return false;
	}

	int itemloc = Q->item[loc] - delt;

	while (Q->item[loc / 2] > itemloc )
	{
		Q->item[loc] = Q->item[loc / 2];
		loc /= 2;
	}

	Q->item[loc] = itemloc;

	return true;
}

/* ��߹ؼ��ʵ�ֵ*/
bool IncreaseItem(int loc, int delt, PriorityQueue* Q)
{
	if (loc > Q->size)
	{
		printf("�޴�Ԫ�أ�");
		return false;
	}

	int itemloc = Q->item[loc] + delt;
	int child = 2 * loc;
	if (child + 1 <= Q->size && Q->item[child + 1] > Q->item[child])
		child++;
	while (Q->item[child] < itemloc && 2 * child <= Q->size)
	{
		Q->item[loc] = Q->item[child];
		loc = child;
		child = 2 * loc;
		if (child + 1 <= Q->size && Q->item[child + 1] > Q->item[child])
			child++;
	}
	if (2 * child > Q->size)
	{
		if (Q->item[child] < itemloc)
		{
			Q->item[loc] = Q->item[child];
			loc = child;
		}
	}
	Q->item[loc] = itemloc;

	return true;

}

/* ɾ��ָ��Ԫ��*/
bool Delete(int loc, PriorityQueue* Q)
{
	if (loc > Q->size)
	{
		printf("�޴�Ԫ�أ�");
		return false;
	}

	IncreaseItem(loc, Q->item[Q->size] - Q->item[loc], Q);
	Q->size--;

	return true;
}

/* ������*/
PriorityQueue BuildHeap(Item A[], int len)
{
	PriorityQueue Q;
	InitPriorityQueue(len, &Q);
	for (int i = 0; i < len; i++)
		Insert(A[i], &Q);

	return Q;
}

