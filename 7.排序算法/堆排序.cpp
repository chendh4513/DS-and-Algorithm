/* 

2022.2.9
������ 

*/ 

#include <stdio.h> 

void swap(int* k, int i, int j)
{
	int temp;
	
	temp = k[i];
	k[i] = k[j];
	k[j] = temp;
}

void HeapAdjust(int* k, int s, int n)//���µ���������ʹ���϶Ѷ��� 
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

void Heap_Sort(int* k, int n)//���м���ǰ��ÿ���ڵ����ν������µ��������������Ժ�ɹ������� 
{
	int i;
	for(i=n/2; i>0; i--)
	{
		HeapAdjust(k,i,n);
	}
	for(i=n; i>1; i--)//�������� 
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
