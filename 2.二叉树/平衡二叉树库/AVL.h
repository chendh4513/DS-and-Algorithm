#pragma once
#ifndef _SEARCHTREE_H
#define _SEARCHTREE_H

#include <stdbool.h>

#define Deleted 65535

typedef int Item;

typedef struct node
{
	Item item;
	struct node* Left;
	struct node* Right;
	int height;
} Node;

typedef Node* Position;
typedef Node* AvlTree;

/* ��ʼ����*/
AvlTree InitTree(AvlTree T);

/* ���ҽ��*/
Position FindNode(const AvlTree T);

/* ���������*/
Position FindMax(const AvlTree T);

/* ������С���*/
Position FindMin(const AvlTree T);

/* ������*/
AvlTree Insert(AvlTree T, Item item);

/* ɾ�����*/
AvlTree Delete(AvlTree T, Item item);

/* �����*/
void EmptyTree(AvlTree T);

#endif // !_SEARCHTREE_H
