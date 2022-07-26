/*

2020.2.10
冒泡排序 

*/ 

#include <stdio.h> 


void BubbleSort(int* a, int n)
{
	int i,j;
	int temp;
	int count1=0,count2=0; 
	int flag = 1; //使用flag进行标记，若一轮比较中没有交换元素，则程序结束。 
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
	printf("进行了%d次比较，%d次移动\n",count1,count2);
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
