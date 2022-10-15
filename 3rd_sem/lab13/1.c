#include<stdio.h>
void quicksort(int[],int,int);
int split(int[],int,int);
int main()
{
int arr[]={13,4,11,15,59,27,19,3,92,5};
printf("\tQuick sort:\n");
printf("\tArray before sorting:\t");
for(int i=0;i<10;i++)
printf("%d\t",arr[i]);
quicksort(arr,0,9);
printf("\n\tArray after sorting:\t");
for(int i=0;i<10;i++)
printf("%d\t",arr[i]);
printf("\n");
return 0;
}
void quicksort(int a[],int low,int up)
{
int i;
if(up>low)
{
i=split(a,low,up);
quicksort(a,low,i-1);
quicksort(a,i+1,up);
}
}
int split(int a[],int low,int up)
{
int p,q,num,temp;
p=low+1;
q=up;
num=a[low];
while(q>=p)
{
while(a[p]<num)
p++;
while(a[q]>num)
q--;
if(q>p)
{
temp=a[p];
a[p]=a[q];
a[q]=temp;
}
}
temp=a[low];
a[low]=a[q];
a[q]=temp;
return q;
}
