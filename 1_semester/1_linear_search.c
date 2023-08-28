#include<stdio.h>

int main()
{
	int arr[5],search;
	printf("enter 5 terms for the array:\n");
	for (int i=0;i<5;i++)	{
		scanf("%d",&arr[i]);
	}
	printf("enter what you want to search: ");
	scanf("%d",&search);
	for (int i=0;i<5;i++)	{
		if (arr[i]==search)	{
			printf("%d was found at position %d\n",search,i+1);
			break;
		}
		if (i==4)	{
			printf("%d was not found in the array\n",search);
		}
	}
	return 0;
}
