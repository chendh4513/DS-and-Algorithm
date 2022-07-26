/*

2022.1.26
n�����ųɻ�������������������ɱ��Ȼ��˳����һλ������ʼ��һ��ʼ�� 
ѭ������ 

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

/* ��ʼ��ָ����������*/
void InitList(CLinkList* L, int i);

/* Լɪ���㷨*/
void Josephus(CLinkList* L, int count, int* out);


int main()
{
	CLinkList L;
	int i;
	int* out;
	int k;

	printf("������������");
	scanf_s("%d", &i);

	out = (int*)malloc(sizeof(int)*i);

	InitList(&L, i);
	Josephus(&L, i, out);

	for (k = 0; k < i; k++)
	{
		printf("��%d����������%d��\n", k+1, out[k]);
	}


	return 0;
}

void InitList(CLinkList* L, int i)//��ʼ������������Ԫ��Ϊ��Ӧ��� 
{
	Node* target, * s;
	int k = 1;

	(*L) = (CLinkList)malloc(sizeof(Node));
	if ((*L) == NULL)
	{
		printf("��ʼ��ʧ��");
		exit(1);
	}
	target = (*L);
	target->data = k++;
	while (i - 1)
	{

		s = (CLinkList)malloc(sizeof(Node));
		if (s == NULL)
		{
			printf("��ʼ��ʧ��");
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
		if (k == 3)//��������ɾ����� 
		{
			prior->next = target->next;
			out[i++] = target->data;
			free(target);
			count--;
			target = prior->next;
			k = 0;
			continue;
		}
		else//������������ 
		{
			prior = prior->next;
			target = target->next;
		}
	}
}
