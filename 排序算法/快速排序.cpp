/*

2020.2.10
����ȡ�з�����
ֱ�Ӳ��뷨����С����Ч�� 

*/


#define MAX_LENGTH_INSERT_SORT 7
#include <stdio.h> 


void swap(int* k, int low, int high)
{
	int temp;
	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

void Direct_Insert_Sort(int* k, int n)
{
	int i,j,temp;
	for(i=1; i<n; i++)
	{
		temp = k[i];
		for(j=i; k[j-1]>temp&&j>0; j--)
		{
			k[j] = k[j-1];
		}
		k[j] = temp;
	}
}

//ʹ������ȡ�з���ѡ���׼�� 
//�Ż�С���������ʽ 
int Partition(int* k, int low, int high)
{
	int point;
	int mid = (high+low)/2;
	
	if(k[low]>k[high])//����ȡ�з� 
	{
		swap(k,low,high);
	}
	if(k[mid]>k[high])
	{
		swap(k,mid,high);
	}
	if(k[low]<k[mid])
	{
		swap(k,low,mid);
	}
	
	point = k[low];
	while(low<high)
	{
		while(low<high && k[high]>=point)
		{
			high--;
		}
		k[low] = k[high];
		while(low<high && k[low]<=point)
		{
			low++;
		}
		k[high] = k[low];
	 } 
	 k[low] = point;
	 return low;
}
 
void Quick_Sort_2(int* k, int low,int high)
{
	int point;
	
	if(high-low>MAX_LENGTH_INSERT_SORT)//�Ż�С��������ʽ 
	{
		point = Partition(k,low,high);
		
		Quick_Sort_2(k,low,point-1);
		
		Quick_Sort_2(k,point+1,high);
	}
	else
	{
		Direct_Insert_Sort(k+low,high-low+1);
	}
}

 int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	Quick_Sort_2(a,0,9);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
