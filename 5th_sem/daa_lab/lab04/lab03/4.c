#include <stdio.h>
void selection_sort(int arr[], int n)
{
    int i,j,position,swap;
    for(i = 0; i < n - 1; i++)
    {
        position=i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[position] > arr[j])
            position=j;
        }
        if(position != i)
        {
            swap=arr[i];
            arr[i]=arr[position];
            arr[position]=swap;
        }
    }
}
int main(){
    int n,sum=0;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++){ 
        scanf("%d", &arr[i]); 
    }
    selection_sort(arr,n);
    for(int i=1;i<n;i++)
    {
        sum+=arr[i];
    }

    printf("Max contagious sum: %d", sum);
    return 0;
}
