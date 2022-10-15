//Let the number "XYZ" be represented as Z->Y->X in the linked list.
// If two such numbers are given in two different linked lists, then with the above representation,
// write a C-program to subtract the second number (represented in the second linked list) from the first number 
//(represented in the first linked list) and store the result in the third linked list with above representation.
#include <stdio.h>
#include<stdlib.h>  
struct node {
    int data;
    struct node* next;
};

int main()
{
    struct node *head1,*head2,*first1,*first2,*second1,*second2,*ptr;
    head1=(struct node *)malloc(sizeof(struct node *)); 
    head2=(struct node *)malloc(sizeof(struct node *));  
    first1=(struct node *)malloc(sizeof(struct node *));  
    first2=(struct node *)malloc(sizeof(struct node *));  
    second1=(struct node *)malloc(sizeof(struct node *));  
    second2=(struct node *)malloc(sizeof(struct node *));
    ptr=(struct node *)malloc(sizeof(struct node *));
    
    head1->next=first1;
    first1->next=second1;
    second1->next=NULL;
    head2->next=first2;
    first2->next=second2;
    second2->next=NULL;
    ptr=head1;
    printf("enter the first linked-list:");
    for(int i=0;i<3;i++)
    {
        scanf("%d",&ptr->data);
        ptr=ptr->next;
    }
    ptr=head2;
    printf("enter the second linked-list:");
    for(int i=0;i<3;i++)
    {
        scanf("%d",&ptr->data);
        ptr=ptr->next;
    }
    int num1,num2;
    num1=(head1->data * 100)+(first1->data * 10)+(second1->data);
    num2=(head2->data * 100)+(first2->data * 10)+(second2->data);

    if (num1>num2){
        if((second1->data - second2->data)<0){
        
        first1->data=first1->data-1;
        second1->data=(10+second1->data) - second2->data;
        }
        else{
            second1->data=(second1->data - second2->data);
        }
        if((first1->data - first2->data)<0){
            head1->data=head1->data-1;
            first1->data=(10+first1->data) - first2->data;
        }
        else{
            first1->data=(first1->data - first2->data);
        }

        head1->data=(head1->data - head2->data);
        ptr=head1;
        printf("Ans: ");
    }
    else{
        if((second2->data - second1->data)<0){
            
            first2->data=first2->data-1;
            second2->data=(10+second2->data) - second1->data;
        }
        else{
            second2->data=(second2->data - second1->data);
        }
        if((first2->data - first1->data)<0){
            head2->data=head2->data-1;
            first2->data=(10+first2->data) - first1->data;
        }
        else{
            first2->data=(first2->data - first1->data);
        }

        head2->data=(head2->data - head1->data);
        ptr=head2;

        printf("Ans: -");
    }

    
    
    for(int i=0;i<3;i++)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    
    return 0;
}

