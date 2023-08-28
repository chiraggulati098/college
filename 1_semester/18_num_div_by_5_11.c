#include<stdio.h>

int main()
{
	int num;
	printf("enter num: ");
	scanf("%d",&num);
	if (num%5==0 && num%11==0)	
		printf("%d is divisible by 5 and 11\n",num);
	else 
		printf("no\n");

	return 0;
}
