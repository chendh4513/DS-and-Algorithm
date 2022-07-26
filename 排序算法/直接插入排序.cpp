/* 

2022.2.9
÷±Ω”≤Â»Î≈≈–Ú 

*/

#include <stdio.h> 
#include <stdbool.h>

bool Direct_Insert_Sort(int* k, int n)
{
	int i,j,temp;
	for(i=1; i<n; i++)
	{
		if(k[i]<k[i-1])
		{
			temp = k[i];
			for(j=i; k[j-1]>temp&&j>0; j--)
			{
					k[j] = k[j-1];
			}
			k[j] = temp;
		}
	}
	return true;
}

 int main()
{
	int i,a[10] = {5,2,6,0,3,9,1,7,4,8};
	
	Direct_Insert_Sort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
