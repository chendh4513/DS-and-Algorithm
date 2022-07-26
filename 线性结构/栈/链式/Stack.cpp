#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

static void CopyToNode(Item item, Node* pn);
static void CopyToItem(Node* pn, Item* pi);

/* Õ»³õÊ¼»¯*/
void InitStack(Stack* S)
{
	S->top = NULL;
	S->items = 0;
}

/* Õ»ÊÇ·ñÎª¿Õ*/
bool StackIsEmpty(const Stack* S)
{
	return S->items == 0;
}

/* Õ»ÊÇ·ñÎªÂú*/
bool StackIsFull(const Stack* S)
{
	return S->items == MAXSTACK;
}

/* Õ»³¤¶È*/
int StackLen(const Stack* S)
{
	return S->items;
}

/* ·µ»ØÕ»¶¥ÔªËØ*/
Item GetTop(const Stack* S)
{
		if (StackIsFull(S))
	{
		printf("¶ÁÈ¡Ê§°Ü£¬Õ»Îª¿Õ!\n");
		exit(1);
	}
	
	return S->top->item;
 } 

/* ÈëÕ»*/
bool Push(Item item, Stack* S)
{
	if (StackIsFull(S))
	{
		printf("ÈëÕ»Ê§°Ü£¬Õ»ÒÑÂú!\n");
		return false;
	}
	Node* pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		printf("·ÖÅäÊ§°Ü£¡\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = S->top;
	S->top = pnew;
	return true;
}

/* ³öÕ»*/
bool Pop(Item* item, Stack* S)
{
	if (StackIsEmpty(S))
	{
		printf("³öÕ»Ê§°Ü£¬Õ»Îª¿Õ£¡\n");
		return false;
	}
	CopyToItem(S->top, item);
	Node* p = S->top;
	S->top = p->next;
	free(p);
	return true;

}

/* Çå¿ÕÕ»*/
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


/* ÄÚ²¿º¯Êý*/
static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}
static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}
