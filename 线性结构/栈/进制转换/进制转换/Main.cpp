#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define MAXSIZE 100

/* 二进制转八进制*/
bool BinTwoToEight(char* in, char* out, int len);
/* 二进制转十进制*/
int BinTwoToTen(char* in, int len);
/* 二进制转十六进制*/
bool BinTwoToSixteen(char* in, char* out, int len);

int main()
{
	Stack S;
	char in[MAXSIZE];
	char* out1;
	int sum2;
	char* out3;
	char m;
	int i, len;

	i = 0;
	len = 0;

	InitStack(&S);

	printf("请输入二进制数，以#结尾：");
	m = getchar();
	while (m != '#')
	{
		Push(m, &S);
		m = getchar();
	}

	while (!StackIsEmpty(&S))
	{
		Pop(&m, &S);
		in[i++] = m;
		len++;
	}

	out1 = (char*)malloc(sizeof(char) * (len + 1));
	out3 = (char*)malloc(sizeof(char) * (len + 1));

	in[i] = '\0';



	BinTwoToEight(in,out1,len);

	i = 0;
	printf("O");
	while (out1[i] != '\0')
	{
		printf("%c", out1[i]);
		i++;
	}
	printf("\n");

	sum2 = BinTwoToTen(in, len);

	i = 0;
	printf("D");
	printf("%d",sum2);

	printf("\n");

	BinTwoToSixteen(in, out3, len);

	i = 0;
	printf("H");
	while (out3[i] != '\0')
	{
		printf("%c", out3[i]);
		i++;
	}
	printf("\n");


	return 0;

}