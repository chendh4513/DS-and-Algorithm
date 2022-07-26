/*

2022.2.9
简单选择排序
 
*/
#include <stdio.h> 
#include <stdbool.h> 

bool Select_Sort(int* a, int n)
{
	int i,j,temp;
	int min;
	int count1=0, count2=0;
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			count1++;
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		if(min!=i)
		{
			count2++;
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
	printf("进行了%d次比较，%d次移动\n",count1,count2);
	return true;
 } 
 
 int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	Select_Sort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
