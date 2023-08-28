#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char str[100];
	printf("enter a string: ");
	gets(str);
	n = strlen(str);
	for (int i = n-1;i>=0;i--)	{
		printf("%c",str[i]);
	}
	printf("\n");
}
