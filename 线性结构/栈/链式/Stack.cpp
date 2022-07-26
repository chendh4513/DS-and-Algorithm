#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

static void CopyToNode(Item item, Node* pn);
static void CopyToItem(Node* pn, Item* pi);

/* ջ��ʼ��*/
void InitStack(Stack* S)
{
	S->top = NULL;
	S->items = 0;
}

/* ջ�Ƿ�Ϊ��*/
bool StackIsEmpty(const Stack* S)
{
	return S->items == 0;
}

/* ջ�Ƿ�Ϊ��*/
bool StackIsFull(const Stack* S)
{
	return S->items == MAXSTACK;
}

/* ջ����*/
int StackLen(const Stack* S)
{
	return S->items;
}

/* ����ջ��Ԫ��*/
Item GetTop(const Stack* S)
{
		if (StackIsFull(S))
	{
		printf("��ȡʧ�ܣ�ջΪ��!\n");
		exit(1);
	}
	
	return S->top->item;
 } 

/* ��ջ*/
bool Push(Item item, Stack* S)
{
	if (StackIsFull(S))
	{
		printf("��ջʧ�ܣ�ջ����!\n");
		return false;
	}
	Node* pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		printf("����ʧ�ܣ�\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = S->top;
	S->top = pnew;
	return true;
}

/* ��ջ*/
bool Pop(Item* item, Stack* S)
{
	if (StackIsEmpty(S))
	{
		printf("��ջʧ�ܣ�ջΪ�գ�\n");
		return false;
	}
	CopyToItem(S->top, item);
	Node* p = S->top;
	S->top = p->next;
	free(p);
	return true;

}

/* ���ջ*/
void EmptyTheStack(Stack* S)
{
	Node* p = S->top;

	while (p)
	{
		S->top = p->next;
		free(p);
		p = S->top;
	}

}


/* �ڲ�����*/
static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}
static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}
