#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int info;
struct node *link;
}*last;
void create(int data);
void display()
{
struct node *q;
if (last==NULL)
{
printf("Empty list");
return;
}
q=last->link;
while(q!=last)
{
printf("%d",q->info);
q=q->link;
}
printf("%d",last->info);
}
void create(int data)
{
struct node *temp;
temp=malloc(sizeof (struct node));
temp->info=data;
if (last==NULL)
{
last=temp;
temp->link=last;
}
else
{
temp->link=last->link;
last->link= temp;
last=temp;
}
}
void main()
{
int i,data,n;
last=NULL;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&data);
create(data);
}
display();
}
