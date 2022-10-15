#include<stdio.h>
int main()
{
int n,j=0;
printf("Enter the size of the array: ");
scanf("%d",&n);
int ar[n];
printf("Enter the elements:\n");
for(int i=0;i<n;i++)
scanf("%d",&ar[i]);
for(int i=0;i<n;i++)
{
if(ar[i]%2==0)
{
ar[j]=ar[i];
j++;
}
}
for(int i=0;i<n;i++)
{
if(i<j)
printf("%d ",ar[i]);
else
ar[i]='\0';
}
printf("\n");
return 0;
}
