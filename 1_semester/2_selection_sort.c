#include<stdio.h>

int main()
{
	int min,arr[5],buffer;
	printf("enter 5 terms:\n");
	for (int i=0;i<5;i++)	{
		scanf("%d",&arr[i]);
	}
	for (int a=0;a<5;a++)	{
		min = arr[a];
		for (int i=a+1;i<5;i++)	{
			if (min > arr[i])	{
				min = arr[i];
				buffer = arr[a];
				arr[a] = min;
				arr[i] = buffer;
			}
		}
	}
	for (int i=0;i<5;i++)	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
