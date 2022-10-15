#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *link;
};

void insert();
void display();
void traverse();
void delete();
void reverse();
void create();

struct node *head_node, *first_node, *temp_node = 0, *prev_node, link_node;
int data;

int main() {
  int option = 0;

  printf("Singly Linked List Example - All Operations\n");

  while (option < 3) {

    printf("\nOptions\n");
    printf("1 : Create into Linked List \n");
    printf("2 : Traverse Linked List\n");
    printf("3 : Insert into Linked List \n");
    printf("4 : Delete into Linked List \n");
    printf("5 : Reverse into Linked List \n");
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
       case 3:
        insert();
       case 4:
        delete();
       case 5:
        reverse();
      default:
        break;
    }
  }

  return 0;
}
void create()
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
void insert()
{}
void traverse()
{}
void delete()
void reverse()
