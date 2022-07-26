#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stack.h"

#define MAXSIZE 100

/* 二进制转八进制*/
bool BinTwoToEight(char* in, char* out, int len)
{
	Stack S;
	int m, n;
	int i, j;
	int k;
	int r = 0;
	char r1;
	
	m = len / 3;
	n = len % 3;
	k = 0;

	InitStack(&S);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 3; j++)
		{
			r += ((in[i * 3 + j]-48) * pow(2, j));
		}
		r1 = r + 48;
		Push(r1, &S);
		r = 0;
	}
	for (i = 3 * m; i < len; i++)
	{
		r += ((in[i] - 48) * pow(2, i-3*m));
	}
	r1 = r + 48;
	Push(r1, &S);

	while (!StackIsEmpty(&S))
	{
		Pop(&r1, &S);
		out[k++] = r1;
	}
	out[k] = '\0';

	return true;

}

/* 二进制转十进制*/
int BinTwoToTen(char* in, int len)
{
	Stack S;

	int i;
	int sum = 0;

	InitStack(&S);

	for (i = 0; i < len; i++)
	{
		sum += (in[i] - 48) * pow(2, i);
	}

	return sum;
}

/* 二进制转十六进制*/
bool BinTwoToSixteen(char* in, char* out, int len)
{
	Stack S;
	int m, n;
	int i, j;
	int k;
	int r = 0;
	char r1;

	m = len / 4;
	n = len % 4;
	k = 0;

	InitStack(&S);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 4; j++)
		{
			r += ((in[i * 4 + j] - 48) * pow(2, j));
		}
		if (r >= 0 && r < 10)
		{
			r1 = r + 48;
			Push(r1, &S);
		}
		else
		{
			switch (r)
			{
			case 10:
				r1 = 'A';
				Push(r1, &S);
				break;
			case 11:
				r1 = 'B';
				Push(r1, &S);
				break;
			case 12:
				r1 = 'C';
				Push(r1, &S);
				break;
			case 13:
				r1 = 'D';
				Push(r1, &S);
				break;
			case 14:
				r1 = 'E';
				Push(r1, &S);
				break;
			case 15:
				r1 = 'F';
				Push(r1, &S);
				break;
			}
		}
		r = 0;

	}
	for (i = 4 * m; i < len; i++)
	{
		r += ((in[i] - 48) * pow(2, i - 4 * m));
	}
	if (r >= 0 && r < 10)
	{
		r1 = r + 48;
		Push(r1, &S);
	}
	else
	{
		switch (r)
		{
		case 10:
			r1 = 'A';
			Push(r1, &S);
			break;
		case 11:
			r1 = 'B';
			Push(r1, &S);
			break;
		case 12:
			r1 = 'C';
			Push(r1, &S);
			break;
		case 13:
			r1 = 'D';
			Push(r1, &S);
			break;
		case 14:
			r1 = 'E';
			Push(r1, &S);
			break;
		case 15:
			r1 = 'F';
			Push(r1, &S);
			break;
		}
	}
	while (!StackIsEmpty(&S))
	{
		Pop(&r1, &S);
		out[k++] = r1;
	}
	out[k] = '\0';

	return true;
}