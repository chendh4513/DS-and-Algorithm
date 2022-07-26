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

/* 初始化树*/
AvlTree InitTree(AvlTree T);

/* 查找结点*/
Position FindNode(const AvlTree T);

/* 查找最大结点*/
Position FindMax(const AvlTree T);

/* 查找最小结点*/
Position FindMin(const AvlTree T);

/* 插入结点*/
AvlTree Insert(AvlTree T, Item item);

/* 删除结点*/
AvlTree Delete(AvlTree T, Item item);

/* 清空树*/
void EmptyTree(AvlTree T);

#endif // !_SEARCHTREE_H
