/*

2022.1.26
��һ��8*8�����ϰڳ����Կ��ܵĵ�8���ʺ��ܻ��๥�����������Ϊ���Իʺ��ܴ���ͬһ�У�ͬһ�У�ͬһ�Խ��ߣ� 
�ݹ� 

*/ 


#include <stdio.h>
  
int count=0;

/* ��ǰ���Ƿ�ȫ*/
 int notDanger(int row, int j, int (*chess)[8]);
 
 /*�ݹ����˻ʺ�����*/ 
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
	 printf("�ܹ���%d��",count); 
	 
	 return 0; 
 }
 
 int notDanger(int row, int j, int (*chess)[8])
{
	int i,k,Flag1=0,Flag2=0,Flag3=0,Flag4=0,Flag5=0;
	//�ж��з�����û��Σ�� (����ȫΪ0��ȫ������Ҫ�����ж�)
	for(i=0; i<8; i++)
	{
		if(chess[i][j]!=0) 
		{
			Flag1 = 1;
			break;
		}
	}
	//�ж����Ϸ�
	for(i=row, k=j; i>=0&&k>=0; i--,k--) 
	{
		if(chess[i][k]!=0) 
		{
			Flag2 = 1;
			break;
		}
	}
	//�ж����·� 
	for(i=row, k=j; i<8&&k<8; i++,k++) 
	{
		if(chess[i][k]!=0) 
		{
			Flag3 = 1;
			break;
		}
	}
	//�ж����Ϸ� 
	for(i=row, k=j; i>=0&&k<8; i--,k++) 
	{
		if(chess[i][k]!=0) 
		{
			Flag4 = 1;
			break;
		}
	}
	//�ж����·� 
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
	 
	 if(n==row)//�ݹ�������ڣ����ڰ����Ѿ����� 
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
	 else//�ݹ����� (0-7)�� 
	 {
	 	for(j=0; j<n; j++)
	 	{
	 		if(notDanger(row,j,chess))//�ж��Ƿ�Σ�գ���Σ����ִ��if������� 
			 {
			 	for(i=0; i<n;i++)
			 	{
			 		chess2[row][i] = 0;//����row��ȫ����Ϊ0 
				 }
				 chess2[row][j] = 1;//����ȫ�ĵ���Ϊ1 
				 
				 EightQueue(row+1,n,chess2) ;//�ж���һ�� 
			  } 
		 }
	 }
 } 
