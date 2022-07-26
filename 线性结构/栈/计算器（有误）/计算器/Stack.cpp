#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/* ջ��ʼ��*/
void InitStack(Stack* S)
{
	S->top = -1;
	S->items = 0;
}

/* ջ�Ƿ�Ϊ��*/
bool StackIsEmpty(const Stack* S)
{
	return S->items == 0;;
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
	if (StackIsEmpty(S))
	{
		printf("��ȡʧ�ܣ�ջΪ��!\n");
		exit(1);
	}

	return S->item[S->top];

}

/* ��ջ*/
bool Push(Item item, Stack* S)
{
	if (StackIsFull(S))
	{
		printf("��ջʧ�ܣ�ջ����!\n");
		return false;
	}

	S->top++;
	S->item[S->top] = item;
	S->items++;

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

	*item = S->item[S->top];
	S->top--;
	S->items--;

	return true;

}

/* ���ջ*/
void EmptyTheStack(Stack* S)
{
	S->top = -1;
	S->items = 0;

}

