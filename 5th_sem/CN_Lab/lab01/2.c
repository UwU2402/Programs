#include<stdio.h>
struct info
{
int roll;
char name[50];
float cgpa;
};
void display(struct info *st)
{
printf("Student roll:%d\nName:%s\nCGPA:%0.2f\n",st->roll,st->name,st->cgpa );
}
int main()
{
struct info stud;
printf("Enter student roll: ");
scanf("%d",&stud.roll);
printf("Enter student name: ");
scanf("%s",stud.name);
printf("Enter student CGPA: ");
scanf("%f",&stud.cgpa);
display(&stud);
return 0;
}
