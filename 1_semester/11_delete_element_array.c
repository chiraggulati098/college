#include<stdio.h>

int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9},n;
	for (int i=0;i<10;i++)	{
		printf("%d\t",arr[i]);
	}
	printf("enter the index of the element you want to delete: ");
	scanf("%d",&n);
	for (int i=n;i<10;i++)	{
		if (i==9)	{
			continue;
		}
		arr[i]=arr[i+1];
	}
	for (int i=0;i<9;i++)	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
