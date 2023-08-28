#include<stdio.h>
#include<string.h>

struct book_info
{
	char name[100],author[100];
	int id;
}b1,b2,b3;

int main()
{
	printf("enter title: ");
	gets(b1.name);
	printf("enter author name: ");
	gets(b1.author);
	printf("enter id: ");
	scanf("%d",&b1.id);
	
	printf("\nthe info is\n\n");
	printf("Title: %s\nAuthor Name: %s\nBook ID: %d\n\n",b1.name,b1.author,b1.id);
	printf("Title: %s\nAuthor Name: %s\nBook ID: %d\n",b2.name,b2.author,b2.id);
	return 0;
}
