/*

2022.1.20
�����û����룬 �ҳ���kС������ 

*/ 



#include <stdio.h>
#define MAX 10

int main()
{
	int temp;
	int n,k;
	int a[MAX];
	
	n = MAX;
	k = MAX/2;
	printf("������%d�����֣�",n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d", a+i);
	}
	
	int b[k];
	for(int i = 0; i<k; i++)//��a����ǰk��Ԫ������b������ 
	{
		b[i] = a[i];
	 } 
	 
	 for(int i = 0; i<k; i++)//��b����Ԫ�ز�ȡð�����򣬴�С���� 
	 {
	 	for(int j = k-1; j>i; j--)
	 	{
	 		if(b[j]<b[j-1])
	 		{
	 			temp = b[j];
				 b[j] = b[j-1];
				 b[j-1] = temp;	
			 }
		 }
	 }
	 
	for(int i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for(int i = 0; i<k; i++)
	{
		printf("%d ", b[i]);
	}	
	printf("\n");
	 	
	 for(int i = k; i<n; i++)//��a�����е�k��Ԫ���Ժ��Ԫ�ط���b��������ȷ��λ���� 
	 {
	 	for(int j = 0; j<k-1; j++)
	 	{
	 		if(b[j]<a[i] && b[j+i]>a[i])
	 		{
	 			b[j+1] = a[i];
			 }
		 }
	 }
	 
	for(int i = 0; i<k; i++)
	{
		printf("%d ", b[i]);
	}	
	printf("\n");
	 printf("��%d������Ϊ��%d",k,b[k-1]);
	 
	 return 0;
 } 
