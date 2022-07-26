#pragma once
#ifndef _LIST_H

typedef int Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* LinkList;
typedef Node* Position;

/* 初始化链表*/
void InitLinkList(LinkList* L);

/* 链表是否为空*/
bool LinkListIsEmpty(const LinkList L);

/* 当前节点是否为最后一个节点*/
bool NodeIsLast(Node* node, const LinkList L);

/* 队列长度*/
int LinkListLen(const LinkList L);

/* 寻找元素所在节点*/
Position Find( Item item, const LinkList L);

/* 寻找元素所在节点的前一个节点*/
Position FindPrew(Item item, const LinkList L);

/* 插入元素*/
bool Insert(Item item, LinkList L, Position p);

/* 删除元素*/
bool Delete(Item item, LinkList L);

/* 删除链表*/
void DeleteLinkList(LinkList L);

#endif // !_LIST_H
