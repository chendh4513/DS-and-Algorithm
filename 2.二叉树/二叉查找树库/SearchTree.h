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

/* 初始化树*/
SearchTree InitTree(SearchTree T);

/* 查找结点*/
Position FindNode(const SearchTree T);

/* 查找最大结点*/
Position FindMax(const SearchTree T);

/* 查找最小结点*/
Position FindMin(const SearchTree T);

/* 插入结点*/
SearchTree Insert(SearchTree T, Item item);

/* 删除结点*/
SearchTree Delete(SearchTree T, Item item);

/* 清空树*/
void EmptyTree(SearchTree T);

#endif // !_SEARCHTREE_H
