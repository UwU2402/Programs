#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);

int main()
{
      start=NULL;
      insert();
      display(start);
      printf("\n");
      
    return 0;

}


 void insert()
 {
     int n,value,i;
     printf("Enter the Size of list:");
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
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

void display(struct Node *head)
{
  
  int count=0;

     struct Node *p,*q,*r,*s;
        p=q=r=s=(struct Node *) malloc( sizeof(struct Node) );
        p=q=r=s=head;
        q=p->next;
        r=q->next;
        s=r->next;
    while (p != NULL) {

          
        if ((p->data) + (q->data) == (r->data)) {
            printf("%d %d Sum: %d\n",p->data,q->data,r->data);
            count++;
        }
        if ((p->data) + (q->data)+(r->data) == (s->data)) {
            printf("%d %d %d Sum: %d\n",p->data,q->data,r->data,s->data);
            count++;
        }
        p=p->next;
        q=p->next;
        r=q->next;
        s=r->next;
      
   }
      

}



