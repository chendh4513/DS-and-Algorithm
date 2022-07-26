#pragma once
#ifndef _SEARCHTREE_H
#define _SEARCHTREE_H

#include <stdbool.h>

typedef int Item;

typedef struct node
{
	Item item;
	struct node* Left;
	struct node* Right;
} Node;

typedef Node* Position;
typedef Node* SearchTree;

/* ��ʼ����*/
SearchTree InitTree(SearchTree T);

/* ���ҽ��*/
Position FindNode(const SearchTree T);

/* ���������*/
Position FindMax(const SearchTree T);

/* ������С���*/
Position FindMin(const SearchTree T);

/* ������*/
SearchTree Insert(SearchTree T, Item item);

/* ɾ�����*/
SearchTree Delete(SearchTree T, Item item);

/* �����*/
void EmptyTree(SearchTree T);

#endif // !_SEARCHTREE_H
