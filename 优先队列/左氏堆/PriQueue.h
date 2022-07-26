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


/* ��ʼ�����ȶ���*/
PriorityQueue InitPriorityQueue(void);

/* �����Ƿ��*/
bool IsEmpty(const PriorityQueue Q);

/* Ѱ����СԪ��*/
Item FindMin(const PriorityQueue Q);

/* �ϲ���ʽ��*/
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

/* ������ȶ���*/
void EmptyQueue(PriorityQueue Q);

#define Insert( X , H ) (H = Insert1(( X ), H ));
#define DeleteMin( H ) (H = DeleteMin1( H ));

/* ����Ԫ��*/
PriorityQueue Insert1(Item item, PriorityQueue Q);

/* ɾ��Ԫ��*/
PriorityQueue DeleteMin1(PriorityQueue Q);







#endif // !PRIORITYQUEUE

