/* ����Ŀδ�ܱ�д��ȷ*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100

/* �жϱ��ʽ�Ƿ�ƽ��*/
bool IsBalance(char* in);
/* ��׺ת��׺���ʽ*/
void InToPost(char* in, char* post);
/* ������*/ //�����������ַ��������޷���ʾ����10������
int Measure(char* post);

int main(void)
{
	int i = 0;
	int res;
	char c;
	char in[MAXSIZE];
	char post[MAXSIZE];
	printf("��������׺���ʽ����������Ϊʮλ�����ڣ�ֻʹ��С���ţ�:");
	c = getchar();

	while (c != '\n')
	{
		in[i++] = c;
		c = getchar();
	}
	in[i] = '\0';
	if (in[0] == '\0')
	{
		printf("δ���յ����룡\n");
		return  1;
	}


	if (!IsBalance(in))
	{
		printf("���ʽ��ƽ��!\n");
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

	//res = Measure(post);//�޷��ó����

	//printf("result = %d", res);
	//return 0;

}