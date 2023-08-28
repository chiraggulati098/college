#include<stdio.h>

int main()
{
	int arr[100],n;
	printf("enter num of elements: ");
	scanf("%d",&n);
	printf("enter %d elements:\n",n);
	for (int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nnow the array is:\n");
	for (int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n\nreverse of the array is:\n");
	for (int i=n-1;i>=0;i--)
		printf("%d\t",arr[i]);
	printf("end\n");

	return 0;
}
