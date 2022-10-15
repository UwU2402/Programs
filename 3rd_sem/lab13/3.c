#include<stdio.h>
void insertionsort(int[],int);
int main()
{
int arr[]={13,5,11,15,59,27,19,3,92,5};
printf("\tInsertion sort:\n");
printf("\tArray before sorting:\t");
for(int i=0;i<10;i++)
printf("%d\t",arr[i]);
insertionsort(arr,9);
printf("\n\tArray after sorting:\t");
for(int i=0;i<10;i++)
printf("%d\t",arr[i]);
printf("\n");
return 0;
}
void insertionsort(int a[],int size)
{
int i,j,temp;
for(i=1;i<size;i++)
{
temp=a[i];
j=i-1;
while(j>=0&&a[j]>temp)
{
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
}
}
