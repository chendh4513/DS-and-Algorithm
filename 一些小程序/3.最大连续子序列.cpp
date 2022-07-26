/*

2020.1.21
Ѱ��������������� 

*/ 

#include <stdio.h>

/* ����(n^2)*/
int MaxSubsequenceSum1(const int a[], int n);
/* �ݹ�(nlogn)*/ 
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
			sum += a[j];//��i��ʼ�������ȵ����кͽ�����κ�max�Ƚ� 
			
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

	MaxLeftSum = MaxSubSum(a, left, center);//��벿����������� 
	MaxRightSum = MaxSubSum(a, center + 1, right);//�Ұ벿����������� 

	MaxLeftBorderSum = 0;
	MaxRightBorderSum = 0;
	LeftBorderSum = 0;
	RightBorderSum = 0;

	for (i = left; i <= center; i++)//������벿������Ԫ�ص���������� 
	{
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	for (i = center+1; i <= right; i++)//�����Ұ벿������Ԫ�ص���������� 
	{
		RightBorderSum += a[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);

}



