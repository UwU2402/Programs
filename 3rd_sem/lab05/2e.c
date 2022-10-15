#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int expo;
    struct node* link;
};
struct node* create(struct node*);
struct node* insert(struct node*,int,int);
void display(struct node*);
void poly_Add(struct node*,struct node*);
void poly_Mul(struct node*,struct node*);
int main(){
    struct node* start1=NULL;
    struct node* start2=NULL;
    printf("Enter the first Polynomial\n");
    
    start1=create(start1);
    printf("\nEnter the second polynomial\n");
    
    start2=create(start2);
    printf("\nPOLYNOMIAL 1 IS:\n");
    display(start1);
    printf("\nPOLYNOMIAL 2 IS:\n");
    display(start2);
    poly_Add(start1,start2);
    poly_Mul(start1,start2);
    
}
struct node* create(struct node* start){
    int i,n,ex,co;
    printf("\nEnter the number of the terms \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("\nEnter the co-efficient and exponent for the term %d :",i);
        scanf("%d%d",&co,&ex);
        start=insert(start,co,ex);
    }
    return start;
}
struct node* insert(struct node* start,int co,int ex){
    struct node*p,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=co;
    temp->expo=ex;
    if(start==NULL||ex>start->expo){
        temp->link=start;
        start=temp;
    }else{
        p=start;
        while(p->link!=NULL && p->link->expo>=ex)
            p=p->link;
        temp->link=p->link;
        p->link=temp;
    }
        return start;
    }
    void display(struct node *p){
        while(p!=NULL){
            printf("%dx^%d",p->coef,p->expo);
            p=p->link;
            if(p!=NULL){
                printf("+");
            }else{
                printf("\n");
            }
        }
    }
    void poly_Add(struct node *p1, struct node *p2){
        struct node *start3=NULL;
        while(p1!=NULL && p2!=NULL){
            if(p1->expo>p2->expo){
                start3=insert(start3,p1->coef,p1->expo);
                p1=p1->link;
            }else if(p2->expo>p1->expo){
                start3=insert(start3,p2->coef,p2->expo);
                p2=p2->link;
            }else if(p2->expo==p1->expo){
                start3=insert(start3,(p1->coef+p2->coef),p1->expo);
                p1=p1->link;
                p2=p2->link;
            }
        }
        while(p1!=NULL){
            start3=insert(start3,p1->coef,p1->expo);
            p1=p1->link;
        }
        while(p2!=NULL){
            start3=insert(start3,p2->coef,p1->expo);
            p2=p2->link;
        }
        printf("\n\nTHE SUM IS :");
        display(start3);
    }
    void poly_Mul(struct node *p1,struct node *p2){
        struct node *start3=NULL;
        struct node *p2_beg=p2;
        while(p1!=NULL){
            p2=p2_beg;
            while(p2!=NULL){
                start3=insert(start3,(p1->coef*p2->coef),(p1->expo+p2->expo));
                p2=p2->link;
            }
            p1=p1->link;
        }
        printf("\n\nTHE PRODUCT IS :");
        display(start3);
    }

