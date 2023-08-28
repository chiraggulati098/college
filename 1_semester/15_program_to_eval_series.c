#include<stdio.h>

float fact(int i)
{
	if (i == 1)
		return i;
	else if (i==0)
		return 1;
	else
		return i*fact(i-1);
}

float power(int x,int i)
{
	float power_x = 1.0;
	for (int n = 1;n <= i;n++)	{
		power_x *= x;
	}
	return power_x;
}

int main()
{
	int x,np=1;
	double sum=0.0;
	printf("enter x: ");
	scanf("%d",&x);
	for (int i=0;i<10;i++)	{
		sum += np*(power(x,i)/fact(i));
		np = -1 * np;
	}
	printf("sum is %lf\n",sum);
	return 0;
}
