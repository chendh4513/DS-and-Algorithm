#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/* Õ»³õÊ¼»¯*/
void InitStack(Stack* S)
{
	S->top = -1;
	S->items = 0;
}

/* Õ»ÊÇ·ñÎª¿Õ*/
bool StackIsEmpty(const Stack* S)
{
	return S->items == 0;;
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
	if (StackIsEmpty(S))
	{
		printf("¶ÁÈ¡Ê§°Ü£¬Õ»Îª¿Õ!\n");
		exit(1);
	}

	return S->item[S->top];

}

/* ÈëÕ»*/
bool Push(Item item, Stack* S)
{
	if (StackIsFull(S))
	{
		printf("ÈëÕ»Ê§°Ü£¬Õ»ÒÑÂú!\n");
		return false;
	}

	S->top++;
	S->item[S->top] = item;
	S->items++;

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

	*item = S->item[S->top];
	S->top--;
	S->items--;

	return true;

}

/* Çå¿ÕÕ»*/
void EmptyTheStack(Stack* S)
{
	S->top = -1;
	S->items = 0;

}

