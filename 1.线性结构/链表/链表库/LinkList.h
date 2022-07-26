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

/* ��ʼ������*/
void InitLinkList(LinkList* L);

/* �����Ƿ�Ϊ��*/
bool LinkListIsEmpty(const LinkList L);

/* ��ǰ�ڵ��Ƿ�Ϊ���һ���ڵ�*/
bool NodeIsLast(Node* node, const LinkList L);

/* ���г���*/
int LinkListLen(const LinkList L);

/* Ѱ��Ԫ�����ڽڵ�*/
Position Find( Item item, const LinkList L);

/* Ѱ��Ԫ�����ڽڵ��ǰһ���ڵ�*/
Position FindPrew(Item item, const LinkList L);

/* ����Ԫ��*/
bool Insert(Item item, LinkList L, Position p);

/* ɾ��Ԫ��*/
bool Delete(Item item, LinkList L);

/* ɾ������*/
void DeleteLinkList(LinkList L);

#endif // !_LIST_H
