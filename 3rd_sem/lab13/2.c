#include<stdio.h>
#include<stdlib.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
int arr[]={13,5,11,15,59,27,19,3,92,5};
printf("\tMerge sort:");
printf("\n\tArray before sorting:\t");
for(int i=0;i<10;i++)
printf("%d\t",arr[i]);
mergesort(arr,0,9);
printf("\n\tArray after sorting:\t");
for(int i=0;i<10;i++)
printf("%d\t",arr[i]);
printf("\n");
return 0;
}
void mergesort(int arr[],int low,int up)
{
int mid;
if(low<up)
{
mid=(low+up)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,up);
merge(arr,low,mid,up);
}
}
void merge(int arr[],int low,int mid,int up)
{
int size,*b,first,second,idx,i;
size=up-low+1;
b=(int*)malloc(size * sizeof(int));
first=low;
second=mid+1;
idx=0;
while(first<=mid&&second<=up)
{
if(arr[first]<=arr[second])
{
b[idx]=arr[first];
first++;
idx++;
}
else
{
b[idx]=arr[second];
second++;
idx++;
}
}
while(first<=mid)
{
b[idx]=arr[first];
idx++;
first++;
}
while(second<=up)
{
b[idx]=arr[second];
idx++;
second++;
}
idx=0;
for(i=low;i<up;i++)
{
arr[i]=b[idx];
idx++;
}
free (b);
}
