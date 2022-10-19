#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble_sort(int ar[],int num);
void selection_sort(int ar[],int num);
int main()
{
int n1=1,arr1[1000],n2=97554768,arr2[1000],n,arr3[1000],j=0,i=4;
for(int j=0;j<1000;j++)
{
n1=n1+i;
arr1[j]=n1;
printf("%d\t",arr1[j]);
}
printf("\n");
selection_sort(arr1,1000);
for(int j=0;j<1000;j++)
{
n2=n2-i;
arr2[j]=n2;
printf("%d\t",arr2[j]);
}
printf("\n");
srand(time(0));
for(int i=0;i<1000;i++)
{
n=rand();
arr3[i]=n;
printf("%d\t",arr3[i]);
}
printf("\n");
return 0;
}
void selection_sort(int ar[],int num)
{
int x,y,pos,swap;
for(int x=0;x<num-1;x++)
{
pos=x;
for(y=x+1;y<num;y++)
{
if(ar[pos]>ar[y])
pos=y;
}
if(pos!=x)
{
swap=ar[x];
ar[x]=ar[pos];
ar[pos]=swap;
}
}
}
void bubble_sort(int ar[],int num)
{
int i,j,n,temp;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
if(ar[j]>ar[j+1])
{
temp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=temp;
}
}
}
