#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *create(struct node *r,int v){
	struct node *curr;
	if(r==NULL){
		curr=malloc(sizeof(struct node));
		curr->left=NULL;
		curr->right=NULL;
		curr->data=v;
		return curr;
	}
	else if(v>r->data){
		r->right=create(r->right,v);
		return r;
	}
	else if(v<r->data){
		r->left=create(r->left,v);
		return r;
	}
	else{
		return r;
	}
}
void preorder(struct node *rep){
	if(rep==NULL){
		return ;
	}
	printf("%d ",rep->data);
	preorder(rep->left);
    preorder(rep->right);
}
void inorder(struct node *rep){
	if(rep==NULL){
		return;
	}
	inorder(rep->left);
	printf("%d ",rep->data);
    inorder(rep->right);
}
void postorder(struct node *rep){
	if(rep==NULL){
		return;
	}
	postorder(rep->right);
	postorder(rep->left);
	printf("%d ",rep->data);
}
struct node * searching(struct node *r,int ele){
    if(r==NULL){
    	printf("\nNot Found!\n");
    	return r;
    }
    if(ele>r->data){
    	return searching(r->right,ele);
	}
	else if(ele<r->data){
		return searching(r->left,ele);
   }
   else if(ele==r->data){
   	printf("\nData found!\n");
   }
}
struct node *casea(struct node *root, struct node *par,struct node *ptr)
{
	if(par==NULL)
		root=NULL;
	else if(ptr==par->left)
		par->left=NULL;
	else
		par->right=NULL;
	free(ptr);
	return root;
}
struct node *caseb(struct node *root, struct node *par, struct node *ptr)
{
	struct node *child;
	if(ptr->left!=NULL)
		child=ptr->left;
	else
		child=ptr->right;
	if(par==NULL)
		root==child;
	else if(ptr==par->left)
		par->left=child;
	else
		par->right=child;
	free(ptr);
	return(root);
}
struct node *casec(struct node *root, struct node *par, struct node *ptr)
{
	struct node *succ, *parsucc;
	parsucc=ptr;
	succ=ptr->right;
	while(succ->left!=NULL)
	{
		parsucc=succ;
		succ=succ->left;
	}
	ptr->data=succ->data;
	if(succ->left==NULL && succ->right==NULL)
		root=casea(root,parsucc,succ);
	else
		root=caseb(root,parsucc,succ);
	return root;
}
struct node *delete(struct node *root, int dele)
{
	struct node *par,*ptr;
	ptr=root;par=NULL;
	while(ptr!=NULL)
	{
		if(dele==ptr->data)
			break;
		par=ptr;
		if(dele<ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	if(ptr==NULL)
		printf("Element not present in BST.\n");
		else if(ptr->left!=NULL && ptr->right!=NULL)
			root=casec(root,par,ptr);
		else if(ptr->left!=NULL)
			root=caseb(root,par,ptr);
		else if(ptr->right!=NULL)
			root=caseb(root,par,ptr);
		else
			root=casea(root,par,ptr);
		return root;
}
int main(){
	struct node *root=NULL;int start=1;
	while(start){
		//printf("\nEnter 1 to Continue and 0 to Quit ");
		printf("\nCHOICES-->\n");
	    printf("\n0.EXIT\n1.CREATE\n2.INORDER TRAVERSAL\n3.PRE ORDER TRAVERSAL\n4.POST ORDER TRAVERSAL\n");
		printf("5.SEARCH\n6.DELETE AN ELEMENT.\n");
		int choice;
		printf("\nEnter Choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				start=0;
				break;
			case 1:
				printf("\nEnter the number of Nodes to be inserted:\n");
				int num,i;
				scanf("%d",&num);
				printf("\nEnter Data:\n");
				int value;
				for(i=0;i<num;i++){
					scanf("%d",&value);
					root=create(root,value);
				}
				break;
			case 2:
			    printf("\nIN ORDER DISPLAY:-\n");		
					inorder(root);
					break;
			case 3:
			    printf("\nPRE ORDER DISPLAY:-\n");
			    preorder(root);
				break;
			case 4:
			    printf("\nPOST ORDER DISPLAY:-\n");
				postorder(root);
				break;
			case 5:
			    printf("\nEnter Element to be searched in BST:\n");
				int search;
				struct node *ptr;
				scanf("%d",&search);
				ptr=searching(root,search);
			    break;
			case 6:
				printf("Enter the Element to be deleted from BST:\n");
				int dele;
				scanf("%d",&dele);
				root=delete(root,dele);
				printf("Element deleted.\n");
				break;
			default:
				printf("Please enetr correct Choice.\n");
				break;
		}
	}

}
