/*

2020.2.10
ð������ 

*/ 

#include <stdio.h> 


void BubbleSort(int* a, int n)
{
	int i,j;
	int temp;
	int count1=0,count2=0; 
	int flag = 1; //ʹ��flag���б�ǣ���һ�ֱȽ���û�н���Ԫ�أ����������� 
	for(i=0; i<n-1&&flag; i++)
	{
		flag = 0;
		for(j=0; j<n-i-1; j++)
		{
			count1++;
			if(a[j]>a[j+1])
			{
				count2++;
				temp = a[j] ;
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
	}
	printf("������%d�αȽϣ�%d���ƶ�\n",count1,count2);
}

int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	BubbleSort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
