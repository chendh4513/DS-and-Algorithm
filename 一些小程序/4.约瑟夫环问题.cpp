/*

2022.1.26
n个人排成环，数到三的人依次自杀，然后顺延下一位继续开始从一开始数 
循环链表 

*/ 
#include<stdio.h>
include<stdlib.h>



typedef struct node
{
	int data;
	struct node* next;
}Node;
typedef Node* CLinkList;

void FindPrior(Node* target, Node** prior)
{
	while ((*prior)->next != target)
	{
		*prior = (*prior)->next;
	}
}

/* 初始化指定长度链表*/
void InitList(CLinkList* L, int i);

/* 约瑟夫算法*/
void Josephus(CLinkList* L, int count, int* out);


int main()
{
	CLinkList L;
	int i;
	int* out;
	int k;

	printf("请输入人数：");
	scanf_s("%d", &i);

	out = (int*)malloc(sizeof(int)*i);

	InitList(&L, i);
	Josephus(&L, i, out);

	for (k = 0; k < i; k++)
	{
		printf("第%d个死的人是%d号\n", k+1, out[k]);
	}


	return 0;
}

void InitList(CLinkList* L, int i)//初始化链表，链表结点元素为相应编号 
{
	Node* target, * s;
	int k = 1;

	(*L) = (CLinkList)malloc(sizeof(Node));
	if ((*L) == NULL)
	{
		printf("初始化失败");
		exit(1);
	}
	target = (*L);
	target->data = k++;
	while (i - 1)
	{

		s = (CLinkList)malloc(sizeof(Node));
		if (s == NULL)
		{
			printf("初始化失败");
			exit(1);
		}
		target->next = s;
		s->data = k++;
		target = s;
		i--;
	}
	target->next = (*L);

}

void Josephus(CLinkList* L, int count, int* out)
{
	int k = 0;
	int i = 0;
	Node* prior;
	Node* target;
	target = prior = *L;

	FindPrior(target, &prior);

	while (count)
	{
		k++;
		if (k == 3)//数到三则删除结点 
		{
			prior->next = target->next;
			out[i++] = target->data;
			free(target);
			count--;
			target = prior->next;
			k = 0;
			continue;
		}
		else//否则继续向后数 
		{
			prior = prior->next;
			target = target->next;
		}
	}
}
