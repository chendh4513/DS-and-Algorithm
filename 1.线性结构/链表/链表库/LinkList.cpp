#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* ��ʼ������*/
void InitLinkList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(*L == NULL)
	{
		printf("��ʼ��ʧ��!");
		exit(1); 
	}
	(*L)->next= NULL;
}

/* �����Ƿ�Ϊ��*/
bool LinkListIsEmpty(const LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

/* ��ǰ�ڵ��Ƿ�Ϊ���һ���ڵ�*/
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

/* ���г���*/
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

/* Ѱ��Ԫ�����ڽڵ�*/
Position Find(Item item, const LinkList L)
{
	Node* p = L->next;

	while (p != NULL && p->item != item)
		p = p->next;

	if (p == NULL)
	{
		printf("�޴�Ԫ��!\n");
		return p;
	}
	return p;
}

/* Ѱ��Ԫ�����ڽڵ��ǰһ���ڵ�*/
Position FindPrew(Item item, const LinkList L)
{
	Node* p = L;

	while (p->next != NULL && p->next->item != item)
		p = p->next;

	if (NodeIsLast(p,L))
	{
		printf("�޴�Ԫ��!\n");
		return NULL;
	}
	return p;
}

/* �ڸ���λ��֮�����Ԫ��*/
bool Insert(Item item, LinkList L, Position p)
{
	Node*  pNew;

	pNew = (Node*)malloc(sizeof(Node));

	if (pNew == NULL)
	{
		printf("����ʧ�ܣ�\n");
		exit(1);
	}

	pNew->item = item;
	pNew->next = p->next;
	p->next = pNew;
	
	return true;

}

/* ɾ��Ԫ��*/
bool Delete(Item item, LinkList L)
{
	Position p;
	Node* node;

	p = FindPrew(item, L);

	if (p == NULL)
	{
		printf("�޴�Ԫ�أ�ɾ��ʧ�ܣ�\n");
		return false;
	}

	node = p->next;
	p->next = node->next;
	free(node);

	return true;

}

/* ɾ������*/
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
