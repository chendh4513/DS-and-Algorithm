#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* 初始化链表*/
void InitLinkList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(*L == NULL)
	{
		printf("初始化失败!");
		exit(1); 
	}
	(*L)->next= NULL;
}

/* 链表是否为空*/
bool LinkListIsEmpty(const LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

/* 当前节点是否为最后一个节点*/
bool NodeIsLast(Node* node, const LinkList L)
{
	Node* p = L;

	while (p->next != NULL)
		p = p->next;
	if (node == p)
		return true;
	else
		return false;
}

/* 队列长度*/
int LinkListLen(const LinkList L)
{
	int count = 0;
	Node* p = L;

	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}

	return count;
}

/* 寻找元素所在节点*/
Position Find(Item item, const LinkList L)
{
	Node* p = L->next;

	while (p != NULL && p->item != item)
		p = p->next;

	if (p == NULL)
	{
		printf("无此元素!\n");
		return p;
	}
	return p;
}

/* 寻找元素所在节点的前一个节点*/
Position FindPrew(Item item, const LinkList L)
{
	Node* p = L;

	while (p->next != NULL && p->next->item != item)
		p = p->next;

	if (NodeIsLast(p,L))
	{
		printf("无此元素!\n");
		return NULL;
	}
	return p;
}

/* 在给定位置之后插入元素*/
bool Insert(Item item, LinkList L, Position p)
{
	Node*  pNew;

	pNew = (Node*)malloc(sizeof(Node));

	if (pNew == NULL)
	{
		printf("分配失败！\n");
		exit(1);
	}

	pNew->item = item;
	pNew->next = p->next;
	p->next = pNew;
	
	return true;

}

/* 删除元素*/
bool Delete(Item item, LinkList L)
{
	Position p;
	Node* node;

	p = FindPrew(item, L);

	if (p == NULL)
	{
		printf("无此元素，删除失败！\n");
		return false;
	}

	node = p->next;
	p->next = node->next;
	free(node);

	return true;

}

/* 删除链表*/
void DeleteLinkList(LinkList L)
{
	Node* p, *temp;

	p = L->next;
	L->next = NULL;

	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}
