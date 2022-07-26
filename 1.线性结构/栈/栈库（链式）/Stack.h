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

/* 栈初始化*/
void InitStack(Stack* S);

/* 栈是否为空*/
bool StackIsEmpty(const Stack* S);

/* 栈是否为满*/
bool StackIsFull(const Stack* S);

/* 栈长度*/
int StackLen(const Stack* S);

/* 返回栈顶元素*/
Item GetTop(const Stack* S);

/* 入栈*/
bool Push(Item item, Stack* S);

/* 出栈*/
bool Pop(Item* item, Stack* S);

/* 清空栈*/
void EmptyTheStack(Stack* S);

#endif // !_STACK_H
