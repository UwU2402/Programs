#include <stdio.h>
#include <stdlib.h>
struct node 
{
int num;
struct node * prev;
struct node * next;
}*start, *end;
void create(int n);
void display();
void reverse();
int main()
{
int n;
start=NULL;
end=NULL;
printf("Enter the number of nodes : ");
scanf("%d", &n);
create(n); 
display();
reverse();
return 0;
}
void create(int n)
{
int i,num;
struct node *temp;
if(n>=1)
{
start=(struct node *)malloc(sizeof(struct node));
if(start!=NULL)
{
printf("Enter data for node 1 : "); 
scanf("%d", &num);
start->num=num;
start->prev=NULL;
start->next=NULL;
end= start;
for(i=2;i<=n;i++)
{
temp=(struct node *)malloc(sizeof(struct node));
if(temp!=NULL)
{
printf("Enter data for node %d : ", i);
scanf("%d", &num);
temp->num=num;
temp->prev=end;
temp->next=NULL;
end->next=temp;
end=temp;
}
else
{
printf("Memory can not be allocated.");
break;
}
}
}
else
{
printf(" Memory can not be allocated.");
}
}
}
void display()
{
struct node * tmp;
int n=1;
if(start==NULL)
{
printf("No data found in the List yet.");
}
else
{
tmp=start;
printf("\nLinked list :\n");
while(tmp!=NULL)
{
printf("Node %d : %d\n", n, tmp->num);
n++;
tmp = tmp->next;
}
}
}
void reverse()
{
struct node * tmp;
int n=0;
if(end==NULL)
{
printf("No data found.");
}
else
{
tmp=end;
printf("\nReverse order:\n");
while(tmp!=NULL)
{
printf("Node %d : %d\n", n+1, tmp->num);
n++;
tmp=tmp->prev;
}
}
}
