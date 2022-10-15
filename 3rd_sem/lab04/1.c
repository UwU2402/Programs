#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
}*start;
void create_list(int data);
void display()
{
struct node *q;
if(start==NULL)
{
printf("The list is empty.");
return;
}
q=start;
while(q!=NULL)
{
printf("%d",q->info);
q=q->link;
}
}
void create_list(int data)
{
struct node *temp,*q;
temp=malloc(sizeof(struct node));
temp->info=data;
temp->link=NULL;
if (start==NULL)
start=temp;
else
{
q=start;
while(q->link!=NULL)
q=q->link;
q->link=temp;
}
}
start;
void main()
{
int data n,i;
start=NULL;
printf("Enter the no. of nodes: ");
scanf("%d",&data);
}
display();
}
}
}
}
