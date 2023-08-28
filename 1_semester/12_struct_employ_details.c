#include<stdio.h>
#include<string.h>

struct employee	
{
	int id;
	char name[50];
}e1,e2;

int main()
{
	e1.id = 118;
	e2.id = 89;
	strcpy(e1.name,"Chirag Gulati");
	strcpy(e2.name,"Aayush Kakkar");
	printf("employee 1 details:\nid: %d\nname: %s\n\nemployee 2 details:\nid: %d\nname: %s\n",e1.id,e1.name,e2.id,e2.name);
	return 0;
}
