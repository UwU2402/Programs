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
struct node *search(struct node *ptr,int skey)
{
if(ptr==NULL)
return NULL;
else if(skey<ptr->info)
return search(ptr->lchild,skey);
else if(skey>ptr->info)
return search(ptr->rchild,skey);
else
return ptr;
}
struct node *case_a(struct node *root,struct node *par, struct node *ptr)
{
if(par==NULL)
root=NULL;
else if(ptr==par->lchild)
par->lchild=NULL;
else
par->rchild=NULL;
free(ptr);
return root;
}
struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
struct node *child;
if(ptr->lchild!=NULL)
child=ptr->lchild;
else
child=ptr->rchild;
if(par==NULL)
root=child;
else if(ptr==par->lchild)
par->lchild=child;
else
par->rchild=child;
free(ptr);
return root;
}
struct node *case_c(struct node *root,struct node *par,struct node *ptr)
{
struct node *succ,*parsucc;
parsucc=ptr;
succ=ptr->rchild;
while(succ->lchild!=NULL)
{
parsucc=succ;
succ=succ->lchild;
}
ptr->info=succ->info;
if(succ->lchild==NULL&&succ->rchild==NULL)
root=case_a(root,parsucc,succ);
else
root=case_b(root,parsucc,succ);
return root;
}
struct node *del(struct node *root,int dkey)
{
struct node *par,*ptr;
ptr=root;
par=NULL;
while(ptr!=NULL)
{
if(dkey==ptr->info)
 break;
par=ptr;
if(dkey<ptr->info)
ptr=ptr->lchild;
else
ptr=ptr->rchild;
}
if(ptr==NULL)
printf("Key not present.\n");
else if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
{
root=case_c(root,par,ptr);
printf("Key is deleted\n");
}
else if(ptr->lchild!=NULL)
{
root=case_b(root,par,ptr);
printf("Key is deleted\n");
}
else if(ptr->rchild!=NULL)
{
root=case_b(root,par,ptr);
printf("Key is deleted\n");
}
else
{
root=case_a(root,par,ptr);
printf("Key is deleted\n");
}
return root;
}
void preorder(struct node *ptr)
{
if(ptr==NULL)
return;
printf("%d",ptr->info);
preorder(ptr->lchild);
preorder(ptr->rchild);
}
void inorder(struct node *ptr)
{
if(ptr==NULL)
return;
inorder(ptr->lchild);
printf("%d",ptr->info);
inorder(ptr->rchild);
}
void postorder(struct node *ptr)
{
if(ptr==NULL)
return;
postorder(ptr->lchild);
postorder(ptr->rchild);
printf("%d",ptr->info);
}
void main()
{
struct node *root=NULL,*ptr;
int choice,k,n=1;
while(n==1)
{
printf("Enter choice:\n1. Insert\n2. Search\n3. Delete\n4. Traverse\n5. Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter the key to be inserted: ");
       scanf("%d",&k);
       root=insert(root,k);
       break;
case 2:printf("Enter the key to be searched: ");
       scanf("%d",&k);
       ptr=search(root,k);
       if(ptr==NULL)
       printf("Key is not present\n");
       else
       printf("Key is present\n");
       break;
case 3:printf("Enter the key to be deleted: ");
       scanf("%d",&k);
       root=del(root,k);
       break;
case 4:preorder(root);
       printf("\n");
       inorder(root);
       printf("\n");
       postorder(root);
       printf("\n");
       break;
case 5:n=0;
       break;
default:printf("Please enter apppropriate choice\n");
        break;
}
}
}
