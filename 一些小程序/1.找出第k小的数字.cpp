/*

2022.1.20
接受用户输入， 找出第k小的数字 

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
	printf("请输入%d个数字：",n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d", a+i);
	}
	
	int b[k];
	for(int i = 0; i<k; i++)//将a数组前k个元素置于b数组中 
	{
		b[i] = a[i];
	 } 
	 
	 for(int i = 0; i<k; i++)//对b数组元素采取冒泡排序，从小到大 
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
	 	
	 for(int i = k; i<n; i++)//将a数组中第k个元素以后的元素放在b数组中正确的位置上 
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
	 printf("第%d个数字为：%d",k,b[k-1]);
	 
	 return 0;
 } 
