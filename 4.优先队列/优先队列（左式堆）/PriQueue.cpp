#include <stdio.h>
#include <stdlib.h>
#include "PriQueue.h"

/* 递归合并*/
static PriorityQueue Merge1(PriorityQueue Q1, PriorityQueue Q2);

/* 交换孩子*/
static void SwapChild(PriorityQueue Q);

/* 初始化优先队列*/
PriorityQueue InitPriorityQueue(void)
{
	PriorityQueue Q;

	Q = NULL;
	Q->npl = -1;
	Q->left = Q->right = NULL;

	return Q;
}

/* 队列是否空*/
bool IsEmpty(const PriorityQueue Q)
{
	return Q == NULL;
}

/* 寻找最小元素*/
Item FindMin(const PriorityQueue Q)
{
	if (IsEmpty(Q))
	{
		printf("空！");
		exit(1);
	}

	return Q->item;
}

/* 合并左式堆*/
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

/* 清空优先队列*/
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

/* 插入元素*/
PriorityQueue Insert1(Item item, PriorityQueue Q)
{
	PriorityQueue SingleQueue;

	SingleQueue = (Node*)malloc(sizeof(Node));

	if (NULL == SingleQueue)
	{
		printf("空间分配失败！");
		exit(1);
	}
	SingleQueue->item = item; 
	SingleQueue->left == SingleQueue->right == NULL;
	SingleQueue->npl == 0;
	Q == Merge(SingleQueue, Q);

	return Q;
}

/* 删除元素*/
PriorityQueue DeleteMin1(PriorityQueue Q)
{
	if (IsEmpty(Q))
	{
		printf("空！");
		exit(1);
	}

	PriorityQueue Q1, Q2;

	Q1 = Q->left;
	Q2 = Q->right;
	free(Q);

	return Merge(Q1, Q2);

}

/* 递归合并*/
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

/* 交换孩子*/
void SwapChild(PriorityQueue Q)
{
	Node* temp;

	temp = Q->left;
	Q->left = Q->right;
	Q->right = temp;
}