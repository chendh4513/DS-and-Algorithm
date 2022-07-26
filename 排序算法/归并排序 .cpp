/*

2022.2.10
归并排序 

*/


#define MAXSIZE 10
#include <stdio.h> 


//实现归并 
void merging(int* a, int low, int mid, int high)
{
	int i,j,k;
	int temp[MAXSIZE];
	
	for(k=low; k<=high; k++)
	{
		temp[k] = a[k];
	}
	for(i=low,j=mid+1,k=low; i<=mid && j<=high;)
	{
		if(temp[i]<=temp[j])
		{
			a[k++] = temp[i++];
		}
		else
		{
			a[k++] = temp[j++];
		}
	}
	while(i<=mid)
	{
		a[k++] = temp[i++];
	}
	while(j<=high)
	{
		a[k++] = temp[j++];
	}
}

//递归算法 
void Merge_Sort(int* k, int low, int high)
{
	
	int mid; 
	if(low<high)
	{
	mid = (low + high) / 2;
	Merge_Sort(k,low,mid);
	Merge_Sort(k,mid+1,high);
	merging(k,low,mid,high);
	}
}

 int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	Merge_Sort(a,0,9);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
