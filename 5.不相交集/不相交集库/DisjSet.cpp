#include <stdio.h>
#include "DisjSet.h"

/* ��ʼ�����ཻ��*/
void InitDisjSet(DisjSet S)
{
	for (int i = NumStes; i > 0; i--)
	{
		S[i] = 0;
	}
}

/* (С��������)��*/
void Union1(DisjSet S, int root1, int root2)
{
	if (S[root1] > S[root2])
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
	else
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
}

///* (����������)��*/
//void Union2(DisjSet S, int root1, int root2)
//{
//	if (S[root1] > S[root2])
//	{
//		S[root1] = root2;
//	}
//	else
//	{
//		if (S[root1] == S[root2])
//			S[root1]--;
//		S[root2] = root1;
//	}
//}

/* ��*/
int Find(DisjSet S, Item x)
{
	int root = x;
	while (root > 0)
	{
		root = S[root];
	}
	int pre;
	while (x > 0)
	{
		pre = S[x];
		S[x] = root;
		x = pre;
	}
	return root;
}