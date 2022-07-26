/*

2022.1.26
在一张8*8棋盘上摆出所以可能的的8个皇后不能互相攻击的情况（即为所以皇后不能处于同一行，同一列，同一对角线） 
递归 

*/ 


#include <stdio.h>
  
int count=0;

/* 当前点是否安全*/
 int notDanger(int row, int j, int (*chess)[8]);
 
 /*递归求解八皇后问题*/ 
  void EightQueue(int row, int n, int (*chess)[8]);
 
 int main()
 {
 	int chess[8][8],i,j;
 	
 	for(i=0; i<8; i++)
 	{
 		for(j=0; j<8; j++)
 		{
 			chess[i][j] = 0;
		 }
	 }
	 
	 EightQueue(0,8,chess);
	 printf("总共有%d种",count); 
	 
	 return 0; 
 }
 
 int notDanger(int row, int j, int (*chess)[8])
{
	int i,k,Flag1=0,Flag2=0,Flag3=0,Flag4=0,Flag5=0;
	//判断列方向有没有危险 (此列全为0则安全，不需要向上判断)
	for(i=0; i<8; i++)
	{
		if(chess[i][j]!=0) 
		{
			Flag1 = 1;
			break;
		}
	}
	//判断左上方
	for(i=row, k=j; i>=0&&k>=0; i--,k--) 
	{
		if(chess[i][k]!=0) 
		{
			Flag2 = 1;
			break;
		}
	}
	//判断右下方 
	for(i=row, k=j; i<8&&k<8; i++,k++) 
	{
		if(chess[i][k]!=0) 
		{
			Flag3 = 1;
			break;
		}
	}
	//判断右上方 
	for(i=row, k=j; i>=0&&k<8; i--,k++) 
	{
		if(chess[i][k]!=0) 
		{
			Flag4 = 1;
			break;
		}
	}
	//判断左下方 
	for(i=row, k=j; i<8&&k>=0; i++,k--) 
	{
		if(chess[i][k]!=0) 
		{
			Flag5 = 1;
			break;
		}
	}
	return !(Flag1||Flag2||Flag3||Flag4||Flag5);
}
 
 
 
 void EightQueue(int row, int n, int (*chess)[8])
{
	int chess2[8][8],i,j;
	
	for(i=0; i<n; i++)
 	{
 		for(j=0; j<8; j++)
 		{
 			chess2[i][j] = chess[i][j];
		 }
	 }
	 
	 if(n==row)//递归结束出口，即第八行已经结束 
	 {
	 	for(i=0; i<n; i++)
 		{
 			for(j=0; j<n; j++)
 			{
 				printf("%d", chess[i][j]);
		 	}
		 	printf("\n");
	 	}
		printf("\n");
		count++;
	 }
	 else//递归条件 (0-7)行 
	 {
	 	for(j=0; j<n; j++)
	 	{
	 		if(notDanger(row,j,chess))//判断是否危险，不危险则执行if里的内容 
			 {
			 	for(i=0; i<n;i++)
			 	{
			 		chess2[row][i] = 0;//将第row行全部置为0 
				 }
				 chess2[row][j] = 1;//将安全的点置为1 
				 
				 EightQueue(row+1,n,chess2) ;//判断下一行 
			  } 
		 }
	 }
 } 
