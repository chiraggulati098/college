#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	int len1, len2;
	printf("enter a string: ");
	gets(str);
	len1 = strlen(str);
	for (int i = 0;str[i]!='\0';i++)	{
		len2 = i+1;
	}
	printf("length of string using strlen() is %d\nlength of string without using strlen() is %d\n",len1,len2);
}
