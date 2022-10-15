#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatbeg(struct node *start,int link);
struct node *addatend(struct node *start,int link);
void EvenOdd(struct node *start1,struct node **start2,struct node **start3 );
struct node* mergeLinkedListAlternate(struct node *head1,struct node *head2)
{
    struct node *temp1=head1,*temp2=head2;
    if(temp1==NULL && temp2==NULL)return NULL;
    if(temp1==NULL)return temp2;
    if(temp2==NULL)return temp1;
    struct node *temp11,*temp22;
    while(temp1->link!=NULL && temp2->link!=NULL)
    {
        temp11=temp1->link;
        temp22=temp2->link;
        temp1->link=temp2;
        temp2->link=temp11;
        temp1=temp11;
        temp2=temp22;
    }
    if(temp1->link==NULL)
        temp1->link=temp2;
    else{
        temp11=temp1->link;
        temp1->link=temp2;
        temp2->link=temp11;
    }
    return head1;
}
int main()
{
        struct node *start1=NULL,*start2=NULL,*start3=NULL;
        start1=create_list(start1);
        EvenOdd(start1, &start2, &start3);
        printf("\nOriginal List L1 is :\n");
        display(start1);
        printf("Odd Numbers List L2 is :\n");
        display(start2);
        printf("Even Numbers List L3 is :\n");
        display(start3);
        struct node* temp = mergeLinkedListAlternate(start2,start3);
        printf("After Merge: ");
        display(temp);
        return 0;
}
void EvenOdd(struct node *start1,struct node **start2,struct node **start3 )
{
        struct node *p1=start1, *p2=*start2, *p3=*start3;
        while(p1!=NULL)
        {
                if( (p1->info)%2 != 0 )
                {
                        if(*start2==NULL)
                                *start2 = addatbeg(*start2,p1->info);
                        else
                                *start2 = addatend(*start2,p1->info);
                }
                else{
                        if(*start3==NULL)
                                *start3 = addatbeg(*start3,p1->info);
                        else
                                *start3 = addatend(*start3,p1->info);
                }
                p1=p1->link;
        }
}
struct node *create_list(struct node *start)
{
        int i,n,link;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        if(n==0)
                return start;
        printf("Enter the element to be inserted : ");
        scanf("%d",&link);
        start=addatbeg(start,link);
        for(i=2;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&link);
                start=addatend(start,link);
        }
        return start;
}
void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("Empty\n");
                return;
        }
        p=start;
        while(p!=NULL)
        {
                printf("%d ",p->info);
                p=p->link;
        }
        printf("\n\n");
}
struct node *addatbeg(struct node *start,int link)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=link;
        tmp->link=start;
        start=tmp;
        return start;
}
struct node *addatend(struct node *start,int link)
{
        struct node *p,*tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=link;
        p=start;
        while(p->link!=NULL)
                p=p->link;
        p->link=tmp;
        tmp->link=NULL;
        return start;
}

