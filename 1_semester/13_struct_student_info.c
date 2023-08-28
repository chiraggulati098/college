#include<stdio.h>
#include<string.h>

struct student_info
{
	char name[50];
	int age,roll_no;
}s1;

int main()
{
	strcpy(s1.name,"Chirag Gulati");
	s1.age = 14;
	s1.roll_no = 17252025;
	printf("%s's details:\nroll number: %d\nage: %d\n",s1.name,s1.roll_no,s1.age);
	return 0;
}
