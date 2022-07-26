#pragma once

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#define MAXSIZE 100
#define MINSIZE 10
#define Mindata -65535

typedef int Item;

typedef struct node
{
	Item item;
	struct node* left;
	struct node* right;
	int npl;
}Node;

typedef Node* PriorityQueue;


/* 初始化优先队列*/
PriorityQueue InitPriorityQueue(void);

/* 队列是否空*/
bool IsEmpty(const PriorityQueue Q);

/* 寻找最小元素*/
Item FindMin(const PriorityQueue Q);

/* 合并左式堆*/
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

/* 清空优先队列*/
void EmptyQueue(PriorityQueue Q);

#define Insert( X , H ) (H = Insert1(( X ), H ));
#define DeleteMin( H ) (H = DeleteMin1( H ));

/* 插入元素*/
PriorityQueue Insert1(Item item, PriorityQueue Q);

/* 删除元素*/
PriorityQueue DeleteMin1(PriorityQueue Q);







#endif // !PRIORITYQUEUE

