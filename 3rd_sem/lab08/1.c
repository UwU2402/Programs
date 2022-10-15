#include <stdio.h>
#include <stdlib.h>
struct node 
{
int data;
struct node * prev;
struct node * next;
}*head, *last;
void createList(int n);
void displayList();
void delete_given_position(int div,int n);
int main()
{
int n, div;
head = NULL;
last = NULL;
printf("\nEnter the total number of nodes in list : "); 
scanf("%d", &n);
createList(n);
printf("\n\nTHE DOUBLY LINKED LIST IS :\n\n");
displayList();
printf("\n\nEnter the number : ");
scanf("%d",&div);
delete_given_position(div,n);
printf("\n\nAFTER DELETION, THE DOUBLY LINKED LIST IS :\n\n");
displayList();
printf("\n");
return 0;
}
void createList(int n)
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
void displayList()
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
void delete_given_position(int div,int n)
{
struct node *temp;
int i;
temp = head;
for(i=0; i<n ; i++)
{
if(temp->data %div==0)
{
temp->prev->next = temp->next; 
temp->next->prev = temp->prev;
temp=temp->next; 
}
else
{
temp = temp->next;
}
}
free(temp); 
}
