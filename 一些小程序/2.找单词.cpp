/*

2022.1.20
在给出的字母列表中找出特定单词 

*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char guess[4][4] = { 't','h','i','s','w','a','t','s','o','a','h','g','f','g','d','t' };

	const char* list[4] = {"this","two","fat","that" };

	int len;
	int i, j, k, m, n, p;
	bool key = false;
	bool stop = false;

	for (i = 0; i < 4; i++)
	{
		len = strlen(list[i]);
		for (j = 0; j < 4 && stop == false; j++)
		{
			for ( k = 0; k < 4 && stop == false; k++)
			{
				for (m = 0, n = j, p = k; m < len && n < 4; m++)//向下搜索
				{
					if (list[i][m] != guess[n++][p])
					{
						break;
					}


				}

				if (list[i][m-1] == guess[n - 1][p] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n++, p);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && p < 4; m++)//向右搜索
				{
					if (list[i][m] != guess[n][p++])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n ][p - 1] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n, p++);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && n >= 0; m++)//向上搜索
				{
					if (list[i][m] != guess[n--][p])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n + 1][p] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n--, p);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && p >= 0; m++)//向左搜索
				{
					if (list[i][m] != guess[n][p--])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n ][p + 1] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n, p--);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && n < 4 && p >= 0; m++)//向左下搜索
				{
					if (list[i][m] != guess[n++][p--])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n - 1][p + 1] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n++, p--);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && n < 4 && p < 4; m++)//向右下搜索
				{
					if (list[i][m] != guess[n++][p++])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n - 1][p - 1] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n++, p++);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && n >= 0 && p >= 0; m++)//向左上搜索
				{
					if (list[i][m] != guess[n--][p--])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n + 1][p + 1] && m  == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n--, p--);
					}
					printf("\n");
					stop = true;
					break;
				}

				for (m = 0, n = j, p = k; m < len && n >= 0 && p < 4; m++)//向右上搜索
				{
					if (list[i][m] != guess[n--][p++])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n + 1][p - 1] && m == len)//已对此单词所有字母挨个进行对比通过，并且最后一个字母也相同
					key = true;

				if (key == true)//对比通过，打印该单词
				{
					int n = j;
					int p = k;
					printf("%s:", list[i]);
					for (int m = 0; m < len; m++)
					{
						printf("(%d , %d) ", n--, p++);
					}
					printf("\n");
					stop = true;
					break;
				}
			}
		}
		if (key == false)
		{
			printf("%s:", list[i]);
			printf("未查找到！\n");
		}
		key = false;
		stop = false;
	}
	return 0;
}

