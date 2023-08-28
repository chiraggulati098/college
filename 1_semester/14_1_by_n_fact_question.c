#include<stdio.h>

float fact(int i)
{
	if (i==1)
		return i;
	else
		return i*fact(i-1);
}

int main()
{
	int num;
	float sum;
	printf("enter num: ");
	scanf("%d",&num);
	for (int i=1;i<=num;i++)	{
		sum += (1/fact(i));
	}
	printf("sum is %f\n",sum);
	return 0;
}
