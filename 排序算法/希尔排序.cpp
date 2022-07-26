/* 

2022.2.9
Ï£¶ûÅÅÐò 

*/

#include <stdio.h> 
#include <stdbool.h>

bool Shell_Sort(int* k, int n)
{
	int i,j,temp;
	int gap = n;
	do
	{
		gap = gap/2;
		for(i=gap; i<n; i++)
		{
			temp = k[i];
			for(j=i; k[j-gap]>temp&&j>=gap; j-=gap)
			{
				k[j] = k[j-gap];
			}
			k[j] = temp;
		}
	}while(gap>1);
	return true;
}

 int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	Shell_Sort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
