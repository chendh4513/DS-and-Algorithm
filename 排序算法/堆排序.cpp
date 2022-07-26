/* 

2022.2.9
堆排序 

*/ 

#include <stdio.h> 

void swap(int* k, int i, int j)
{
	int temp;
	
	temp = k[i];
	k[i] = k[j];
	k[j] = temp;
}

void HeapAdjust(int* k, int s, int n)//向下调整子树，使符合堆定义 
{
	int i,temp;
	
	temp = k[s];
	for(i=2*s; i<=n; i*=2)
	{
		if(i<n && k[i]<k[i+1])
		{
			i++;
		}
		if(temp>=k[i])
		{
			break;
		}
		k[s] = k[i];
		s = i;
	}
	k[s] = temp;

}

void Heap_Sort(int* k, int n)//对中间往前的每个节点依次进行向下调整，调整至根以后成功建立堆 
{
	int i;
	for(i=n/2; i>0; i--)
	{
		HeapAdjust(k,i,n);
	}
	for(i=n; i>1; i--)//进行排序 
	{
		swap(k,1,i);
		HeapAdjust(k,1,i-1);
	}
}

 int main()
{
	int i,a[10] = {-1,5,2,6,0,3,9,1,7,4};
	
	Heap_Sort(a,9);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
