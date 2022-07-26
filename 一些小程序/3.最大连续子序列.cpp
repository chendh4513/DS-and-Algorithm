/*

2020.1.21
寻找最大连续子序列 

*/ 

#include <stdio.h>

/* 遍历(n^2)*/
int MaxSubsequenceSum1(const int a[], int n);
/* 递归(nlogn)*/ 
int MaxSubsequenceSum2(const int a[], int n);
int Max(int a, int b, int c);
int MaxSubSum(const int a[], int left, int right);

int MaxSubsequenceSum1(const int a[], int n)
{
	int i,j;
	int sum = 0;
	int max = 0;
	
	for(i = 0; i<n, i++)
	{
		for(j = i; j<n; j++)
		{
			sum += a[j];//从i开始，各长度的序列和结果依次和max比较 
			
			if(sum > max)
				max = sum;
			
		}
		sum = 0
	}
	
	return max;
}

int MaxSubsequenceSum2(const int a[], int n)
{
	return MaxSubSum(a, 0, n - 1);
}

int Max(int a, int b, int c)
{
	if (a >= b)
	{
		if (b >= c)
			return a;
		else
		{
			if (a >= c)
				return a;
			else
				return c;
		}
	}
	else
	{
		if (c >= b)
			return c;
		else
			return b;
	}
}

int MaxSubSum(const int a[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right)
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}

	center = (left + right) / 2;

	MaxLeftSum = MaxSubSum(a, left, center);//左半部分最大子序列 
	MaxRightSum = MaxSubSum(a, center + 1, right);//右半部分最大子序列 

	MaxLeftBorderSum = 0;
	MaxRightBorderSum = 0;
	LeftBorderSum = 0;
	RightBorderSum = 0;

	for (i = left; i <= center; i++)//包含左半部分最右元素的最大子序列 
	{
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	for (i = center+1; i <= right; i++)//包含右半部分最左元素的最大子序列 
	{
		RightBorderSum += a[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);

}



