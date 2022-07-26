#include <stdio.h>
#include <stdlib.h>
#include "PriQueue.h"

/* �ݹ�ϲ�*/
static PriorityQueue Merge1(PriorityQueue Q1, PriorityQueue Q2);

/* ��������*/
static void SwapChild(PriorityQueue Q);

/* ��ʼ�����ȶ���*/
PriorityQueue InitPriorityQueue(void)
{
	PriorityQueue Q;

	Q = NULL;
	Q->npl = -1;
	Q->left = Q->right = NULL;

	return Q;
}

/* �����Ƿ��*/
bool IsEmpty(const PriorityQueue Q)
{
	return Q == NULL;
}

/* Ѱ����СԪ��*/
Item FindMin(const PriorityQueue Q)
{
	if (IsEmpty(Q))
	{
		printf("�գ�");
		exit(1);
	}

	return Q->item;
}

/* �ϲ���ʽ��*/
PriorityQueue Merge(PriorityQueue Q1, PriorityQueue Q2)
{
	if (NULL == Q1)
		return Q2;
	if (NULL == Q2)
		return Q1;
	if (Q1->item < Q2->item)
		return Merge1(Q1, Q2);
	else
		return Merge1(Q2, Q1);
}

/* ������ȶ���*/
void EmptyQueue(PriorityQueue Q)
{
	if (NULL == Q)
		return;
	if (NULL == Q->left && NULL == Q->right)
		free(Q);
	if (Q->left)
		EmptyQueue(Q->left);
	if (Q->right)
		EmptyQueue(Q->right);
}

/* ����Ԫ��*/
PriorityQueue Insert1(Item item, PriorityQueue Q)
{
	PriorityQueue SingleQueue;

	SingleQueue = (Node*)malloc(sizeof(Node));

	if (NULL == SingleQueue)
	{
		printf("�ռ����ʧ�ܣ�");
		exit(1);
	}
	SingleQueue->item = item; 
	SingleQueue->left == SingleQueue->right == NULL;
	SingleQueue->npl == 0;
	Q == Merge(SingleQueue, Q);

	return Q;
}

/* ɾ��Ԫ��*/
PriorityQueue DeleteMin1(PriorityQueue Q)
{
	if (IsEmpty(Q))
	{
		printf("�գ�");
		exit(1);
	}

	PriorityQueue Q1, Q2;

	Q1 = Q->left;
	Q2 = Q->right;
	free(Q);

	return Merge(Q1, Q2);

}

/* �ݹ�ϲ�*/
PriorityQueue Merge1(PriorityQueue Q1, PriorityQueue Q2)
{
	if (NULL == Q1->left)
		Q1->left = Q2;
	else
	{
		Q1->right = Merge(Q1->right, Q2);
		if (Q1->left->npl < Q1->right->npl)
			SwapChild(Q1);

		Q1->npl = Q1->right->npl + 1;
	}

	return Q1;
}

/* ��������*/
void SwapChild(PriorityQueue Q)
{
	Node* temp;

	temp = Q->left;
	Q->left = Q->right;
	Q->right = temp;
}