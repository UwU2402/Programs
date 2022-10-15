#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;         
    struct node *next;
} *head;


void createList(int n);
void deleteList();
void displayList();



int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter the value of k: ");

    deleteList();

    printf("\nData in the list \n");
    displayList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL; 

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode;
                temp = temp->next;
            }
        }

    }
}

void deleteList()
{
    int k;
    scanf("%d",&k);
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    struct node *prev=(struct node *)malloc(sizeof(struct node));
    temp=prev=head;
    // while (temp != NULL && temp->data % k == 0) {
    // head = temp->next;
    // free(temp);
    // temp = head;
    // }
    while (temp != NULL) {
 
        while (temp != NULL && temp->data % k != 0){
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;
        prev->next = temp->next;
 
        free(temp);

        temp = prev->next;
    }
    

}

void displayList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                
        }
    }
}
