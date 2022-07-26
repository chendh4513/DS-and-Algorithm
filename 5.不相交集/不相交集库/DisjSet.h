#pragma once

#ifndef _DISJSET_H
#define NumStes 10

typedef int DisjSet[NumStes + 1];

typedef int Item;

/* ��ʼ�����ཻ��*/
void InitDisjSet(DisjSet S);

/* (С��������)��*/
void Union1(DisjSet S, int root1, int root2);

///* (����������)��*/
//void Union2(DisjSet S, int root1, int root2);

/* ��*/
int Find(DisjSet S, Item x);
#endif // !_DISJSET_H

