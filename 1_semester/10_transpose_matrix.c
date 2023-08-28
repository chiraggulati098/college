#include<stdio.h>

int main()
{
        int first[100][100],second[100][100],row,column;
        printf("enter number of rows and columns:\n");
        scanf("%d%d",&row,&column);
        printf("enter terms of 1st matrix:\n");
        for (int i=0;i<row;i++) {
                for (int j=0;j<column;j++)      {
                        scanf("%d",&first[i][j]);
                }
        }
        for (int i=0;i<row;i++) {
                for (int j=0;j<column;j++)      {
                        second[j][i] = first[i][j];
                }
        }
	printf("\nmatrix is:\n");
        for (int i=0;i<row;i++) {
                for (int j=0;j<column;j++)      {
                        printf("%d\t",first[i][j]);
                }
		printf("\n");
        }
	printf("\ntranspose of matrix is:\n");
        for (int i=0;i<row;i++) {
                for (int j=0;j<column;j++)      {
                        printf("%d\t",second[i][j]);
                }
		printf("\n");
        }
}
