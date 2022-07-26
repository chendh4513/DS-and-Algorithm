/* 

2022.2.9
’€∞Î≤Â»Î≈≈–Ú
 
*/

#include <stdio.h> 
#include <stdbool.h>

bool Half_Insert_Sort(int* k, int n)
{
	int i,j,temp;
	int low,high,mid;
	for(i=1; i<n; i++)
	{
		temp = k[i];
		low = 0;
		high = i-1;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(k[mid]>temp)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		for(j=i-1; j>=high+1; j--)
		{
			k[j+1] = k[j];
		}
		k[high+1] = temp;
	}
	return true;
}

 int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	Half_Insert_Sort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
