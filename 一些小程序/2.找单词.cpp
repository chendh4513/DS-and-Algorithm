/*

2022.1.20
�ڸ�������ĸ�б����ҳ��ض����� 

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
				for (m = 0, n = j, p = k; m < len && n < 4; m++)//��������
				{
					if (list[i][m] != guess[n++][p])
					{
						break;
					}


				}

				if (list[i][m-1] == guess[n - 1][p] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && p < 4; m++)//��������
				{
					if (list[i][m] != guess[n][p++])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n ][p - 1] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && n >= 0; m++)//��������
				{
					if (list[i][m] != guess[n--][p])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n + 1][p] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && p >= 0; m++)//��������
				{
					if (list[i][m] != guess[n][p--])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n ][p + 1] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && n < 4 && p >= 0; m++)//����������
				{
					if (list[i][m] != guess[n++][p--])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n - 1][p + 1] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && n < 4 && p < 4; m++)//����������
				{
					if (list[i][m] != guess[n++][p++])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n - 1][p - 1] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && n >= 0 && p >= 0; m++)//����������
				{
					if (list[i][m] != guess[n--][p--])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n + 1][p + 1] && m  == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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

				for (m = 0, n = j, p = k; m < len && n >= 0 && p < 4; m++)//����������
				{
					if (list[i][m] != guess[n--][p++])
					{
						break;
					}
				}

				if (list[i][m - 1] == guess[n + 1][p - 1] && m == len)//�ѶԴ˵���������ĸ�������жԱ�ͨ�����������һ����ĸҲ��ͬ
					key = true;

				if (key == true)//�Ա�ͨ������ӡ�õ���
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
			printf("δ���ҵ���\n");
		}
		key = false;
		stop = false;
	}
	return 0;
}

