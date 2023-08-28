#include<stdio.h>

int main()
{
	int arr[30],search,n,first,last,mid;
	printf("how many terms do you want in the array: ");
	scanf("%d",&n);
	printf("enter terms of array (in ascending order):\n");
	for (int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	printf("enter term to search: ");
	scanf("%d",&search);
	first = 0;
	last = n-1;
	
	while (first < last)	{
		mid = (first + last)/2;
		if (arr[mid]==search)	{
			printf("%d was found at %d index in the array\n",search,mid);
			break;
		}
		else if (search > arr[mid])	{
			first = mid + 1;
		}
		else if (search < arr[mid])	{
			last = mid - 1;
		}
	}
	return 0;
}
