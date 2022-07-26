/* 此项目未能编写正确*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100

/* 判断表达式是否平衡*/
bool IsBalance(char* in);
/* 中缀转后缀表达式*/
void InToPost(char* in, char* post);
/* 计算结果*/ //本函数有误，字符串数组无法表示大于10的数字
int Measure(char* post);

int main(void)
{
	int i = 0;
	int res;
	char c;
	char in[MAXSIZE];
	char post[MAXSIZE];
	printf("请输入中缀表达式（单个数字为十位数以内，只使用小括号）:");
	c = getchar();

	while (c != '\n')
	{
		in[i++] = c;
		c = getchar();
	}
	in[i] = '\0';
	if (in[0] == '\0')
	{
		printf("未接收到输入！\n");
		return  1;
	}


	if (!IsBalance(in))
	{
		printf("表达式不平衡!\n");
		exit(1);
	}


	InToPost(in, post);

	i = 0;
	while (post[i] != '\0')
	{
		printf("%c ", post[i]);
		i++;
	}

	printf("\n");

	//res = Measure(post);//无法得出结果

	//printf("result = %d", res);
	//return 0;

}