#pragma once

#ifndef _DISJSET_H
#define NumStes 10

typedef int DisjSet[NumStes + 1];

typedef int Item;

/* 初始化不相交集*/
void InitDisjSet(DisjSet S);

/* (小树并大树)并*/
void Union1(DisjSet S, int root1, int root2);

///* (矮树并高树)并*/
//void Union2(DisjSet S, int root1, int root2);

/* 查*/
int Find(DisjSet S, Item x);
#endif // !_DISJSET_H

