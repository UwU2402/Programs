#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left, *right;
};
struct node *newNode(int data)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->data  = data;
temp->left  = temp->right = NULL;
return (temp);
}
int getCount(struct node *root, int low, int high)
{
if (!root)
return 0;
if (root->data == high && root->data == low)
return 1;
if (root->data <= high && root->data >= low)
return 1 + getCount(root->left, low, high) +
                    getCount(root->right, low, high);
else if (root->data < low)
return getCount(root->right, low, high);
else return getCount(root->left, low, high);
}
int main()
{
struct node *root = newNode(10);
root->left        = newNode(5);
root->right       = newNode(50);
root->left->left  = newNode(1);
root->right->left = newNode(40);
root->right->right = newNode(100);
int l = 5;
int h = 45;
printf("Count of nodes between [ %d ,  %d ] is %d ",l,h,getCount(root, l, h));
return 0;
}
