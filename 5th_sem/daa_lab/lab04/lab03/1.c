#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
int main()
{
int n,i,j;
printf("Enter the no. of numbers to input:");
scanf("%d",&n);
int ar[n];
printf("Enter the numbers:");
for(i=0;i<n;i++)
{
scanf("%d",&ar[i]);
}
selectionSort(ar,n);
printf("\nNo.s in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
//gcd
//for(i=ar[0];i>=1;i--)
//{
for(j=ar[0];j>=1;j--)
{
for(i=0;i<n;i++)
{
if(ar[i]%j!=0)
break;
}
if(i==n-1)
{
printf("%d",j);
break;
}
}
//}
printf("%d",j);
}
