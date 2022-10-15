#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
} *head;
void initialize()
{
head = NULL;
}
void insert(int num) 
{
struct node* new = (struct node*) malloc(sizeof(struct node));
new->data=num;
new->next=head;
head=new;
printf("Inserted Element : %d\n", num);
}
void reverse(struct node* Ptr) 
{
if (Ptr == NULL)
return;   
if(Ptr->next == NULL)
{
head = Ptr;
return;   
}
reverse(Ptr->next);
Ptr->next->next = Ptr;  
Ptr->next = NULL;               
}
void print(struct node *Ptr) 
{
while (Ptr != NULL) 
{
printf("%d", Ptr->data);
Ptr = Ptr->next;
if(Ptr != NULL)
printf("-->");
}
}
int main() {
initialize();
insert(1);  
insert(2); 
insert(3); 
insert(4);
insert(5);
printf("\nLinked List\n");
print(head);
reverse(head);
printf("\nReversed Linked List\n");
print(head);
printf("\n");
return 0;
}
