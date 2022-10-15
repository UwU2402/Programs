#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *link;
};

void insert();
void display();


struct node *head_node, *first_node, *temp_node = 0, *prev_node, link_node;
int data;

int main() {
  int option = 0;

  printf("Singly Linked List Example - All Operations\n");

  while (option < 3) {

    printf("\nOptions\n");
    printf("1 : Insert into Linked List \n");
    printf("2 : Display Linked List\n");
    printf("Others : Exit()\n");
    printf("Enter your option:");
    scanf("%d", &option);
    switch (option) {
      case 1:
        insert();
        break;
      case 2:
        display();
        break;
      default:
        //option=-1;
        break;
    }
  }

  return 0;
}
void insert()
 {
     int n,value;
     printf("Enter size :");
     scanf("%d",&n);
     struct node *temp;
     for(int i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              head_node=(struct node *) malloc( sizeof(struct node) );
              head_node->data=value;
              head_node->link=NULL;
              temp=head_node;
              continue;
         }
         else
         {
             temp->link= (struct node *) malloc( sizeof(struct node) );
             temp=temp->link;
             temp->data=value;
             temp->link=NULL;
         }
     }
 }
 void display(){
        while (head_node != NULL) {
            printf("%d ",head_node->data);
            head_node= head_node->link;
        }
    }
