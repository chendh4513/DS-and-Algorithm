/*

2022.1.26
将n个盘子从x借助y移动到z 
递归 

*/

#include <stdio.h>

void move(int n, char x, char y, char z); 
 
 int main()
 {
 	int n;
 	
 	printf("请输入汉诺塔层数\n");
 	scanf("%d",&n);
 	printf("移动步骤如下：\n");
 	move(n,'x','y','z');
 	
 	return 0;
 }
 
 void move(int n, char x, char y, char z)
{
	if(1==n)
	{
		printf("%c-->%c\n",x,z);
	 } 
	 else
	 {
	 	move(n-1,x,z,y);          //将n-1个盘子从x借助z移动到y
	 	printf("%c-->%c\n",x,z);    //将第n个盘子从x移动到z 
	 	move(n-1,y,x,z);          //将n-1个盘子从y借助x移动到z 
	 }
 } 
