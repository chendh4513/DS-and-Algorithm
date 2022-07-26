#pragma once
#ifndef _STACK_H
#define _STACK_H
#include <stdbool.h>

typedef int Item;

#define MAXSTACK 10

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef struct stack
{
	Node* top;
	int items;
}Stack;

/* ջ��ʼ��*/
void InitStack(Stack* S);

/* ջ�Ƿ�Ϊ��*/
bool StackIsEmpty(const Stack* S);

/* ջ�Ƿ�Ϊ��*/
bool StackIsFull(const Stack* S);

/* ջ����*/
int StackLen(const Stack* S);

/* ����ջ��Ԫ��*/
Item GetTop(const Stack* S);

/* ��ջ*/
bool Push(Item item, Stack* S);

/* ��ջ*/
bool Pop(Item* item, Stack* S);

/* ���ջ*/
void EmptyTheStack(Stack* S);

#endif // !_STACK_H
