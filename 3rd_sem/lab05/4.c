#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;
void createList(int n);
void displayList();
void reverseList();
int main()
{
    int n, data, choice=1;
    head = NULL;
    last = NULL;
    while(choice != 0)
    {
        
       // printf("============================================\n");
        printf("DOUBLY LINKED LIST TO CIRCULAR PROGRAM \n");
        //printf("============================================\n");
        printf("1. Create List\n");
        
        printf("2. Transform list\n");
        printf("0. Exit\n");
        //printf("--------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            
            case 2:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-2");
        }
        printf("\n\n");
    }
    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *newNode;
    if(n >= 1)
    {
   
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;
            last->next = newNode; 
            last = newNode; 
        }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        last->next=head;
    }
}
void displayList()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
            if(temp->next==head){
                temp->next=head->prev;
            }
        }
    }
    printf("LIST Transformed SUCCESSFULLY.\n");
}

