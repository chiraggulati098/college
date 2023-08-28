#include<stdio.h>
#include<string.h>

void strrev(char a[],char b[])
{
	int n = strlen(a);
	int j = 0;
	for (int i = n-1;i>=0;i--)	{
		b[j] = a[i];
		j++;
	}
}

int main()
{
	char str[100], rev_str[100];
	printf("enter a string: ");
	gets(str);
	strrev(str,rev_str);
	if(strcmp(str,rev_str) == 0)
		printf("string is a palindrome\n");
	else
		printf("not a palindrome\n");
	return 0;
}
