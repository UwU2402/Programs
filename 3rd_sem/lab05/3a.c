#include<stdio.h> 
#include<stdlib.h> 
 struct Node
{
    int data;
    struct Node *next;
}*start;
  
void swap(int *a, int *b); 
void insert(){
     int n,value;
     scanf("%d",&n);
     struct Node *temp;
     for(int i=0;i<n;i++)
     {
         scanf("%d",&value);
if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
void pairWiseSwap(struct Node *head) 
{ 
    struct Node *temp = head; 
    while (temp != NULL && temp->next != NULL) 
    { 
        swap(&temp->data, &temp->next->data); 
        temp = temp->next->next; 
    } 
} 
void swap(int *a, int *b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = 
              (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
       node = node->next; 
    } 
} 
int main() 
{ 
    start = NULL;
    insert();
  
    printf("Linked list before exchanges: "); 
    printList(start); 
  
    pairWiseSwap(start); 
  
    printf("\nLinked list after exchanges: "); 
    printList(start); 
  
    return 0; 
}

