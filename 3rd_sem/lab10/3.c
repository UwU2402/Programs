#include <stdio.h>
#include <stdlib.h>
//#include<math.h>
struct node 
{
int data;
struct node * prev;
struct node * next;
}*head, *last;
void create(int n);
void display();
void delete(int n);
int main()
{
int n, div;
head = NULL;
last = NULL;
printf("\nEnter the total number of nodes in list : "); 
scanf("%d", &n);
create(n);
printf("\nTHE DOUBLY LINKED LIST IS :\n\n");
display();
printf("\n\nAFTER DELETION, THE DOUBLY LINKED LIST IS :\n\n");
delete(n);
display();
printf("\n");
return 0;
}
void create(int n)
{
int i, data;
struct node *newNode;
if(n >= 1)
{
head = (struct node *)malloc(sizeof(struct node));
printf("\nEnter data of node 1 : ");
scanf("%d", &data);
head->data = data;
head->prev = NULL; 
head->next = NULL; 
last = head;
for(i=2; i<=n; i++)
{
newNode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter data of node %d : ", i);
scanf("%d", &data);
newNode->data = data;
newNode->prev = last; 
newNode->next = NULL;
last->next = newNode;
last = newNode;
}}}
void display()
{
struct node * temp;
int n = 1;
if(head == NULL)
{
printf("\nList is empty.\n");
}
else
{
temp = head;
while(temp != NULL)
{
printf("%d\t", temp->data);
n++;
temp = temp->next;
}}}
void delete(int n)
{
struct node *temp;
int i,j,k=1;
temp = head;
for(i=1;i<=n;i++)
{
for(j=2;j>=k;j++)
{
k=temp->data/j;
if(temp->data%j==0)
{
temp=temp->next;
break;
}
else if((j==k||k+1>j)&&temp->data%j!=0)
{
temp->prev->next = temp->next; 
temp->next->prev = temp->prev;
//temp=temp->next; 
if(i==n)
temp->next=NULL;
//if(i==1)
//temp->prev=NULL;
}
}
}
free(temp);
}
