#include<stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start1,start2,end1,end2;
double cpu_time1,cpu_time2;
int main()
{
int n,i,temp,x,low,high,mid;
printf("Enter no. of elements in the array: ");
scanf("%d",&n);
int arrl[n],arrb[n];
printf("Enter the elements in the array:\n");
for(i=0;i<n;i++)
{
scanf("%d",&temp);
arrl[i]=temp;
arrb[i]=temp;
}
printf("Enter the element to search: ");
scanf("%d",&x);
start1=clock();
for(i=0;i<n;++i)
{
if(arrl[i]==x)
break;
}
end1=clock();
if(i<n)
printf("\nElement found at index %d",i+1);
else
printf("Element not found\n");
cpu_time1= ((double)(end1-start1)) / CLOCKS_PER_SEC;
printf("\nTime taken: %f seconds\n", cpu_time1);
low = 0;
high = n - 1;
mid = (low+high)/2;
start2=clock();
while (low <= high) 
{
if(arrb[mid] < x)
low = mid + 1;
else if 
(arrb[mid] == x) 
{
printf("Element found at location %d", mid+1);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("Element not found\n");
end2=clock();
cpu_time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
printf("\nTime taken: %f seconds\n", cpu_time2);
return 0;
}
