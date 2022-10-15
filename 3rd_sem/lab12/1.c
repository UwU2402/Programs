#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lchild;
int info;
struct node *rchild;
};
struct node *insert(struct node *ptr,int ikey)
{
if(ptr==NULL)
{
ptr=(struct node*)malloc(sizeof(struct node));
ptr->info=ikey;
ptr->lchild=NULL;
ptr->rchild=NULL;
}
else if(ikey<ptr->info)
ptr->lchild=insert(ptr->lchild,ikey);
else if(ikey>ptr->info)
ptr->rchild=insert(ptr->rchild,ikey);
else
printf("Duplicate key\n");
return ptr;
}

