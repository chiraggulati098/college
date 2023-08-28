#include<stdio.h>

int main()
{
	int first[100][100],second[100][100],row,column;
	printf("enter number of rows and columns:\n");
	scanf("%d%d",&row,&column);
	printf("enter terms of 1st matrix:\n");
	for (int i=0;i<row;i++)	{
		for (int j=0;j<column;j++)	{
			scanf("%d",&first[i][j]);
		}
	}
	printf("enter terms of 2nd matrix:\n");
	for (int i=0;i<row;i++)	{
		for (int j=0;j<column;j++)	{
			scanf("%d",&second[i][j]);
		}
	}
	for (int i=0;i<row;i++)	{
		for (int j=0;j<column;j++)	{
			printf("%d\t",first[i][j]+second[i][j]);
		}
		printf("\n");
	}
}
