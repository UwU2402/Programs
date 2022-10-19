#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("The total no. of customers:");
    scanf("%d",&n);
    int arr[n];
    int ii,count=0;
    float ff;
    //printf("Enter the billing amount corresponding to their ID:");
    for(int i=0;i<n;i++)
    {
        printf("Enter the bill amount whose customerID is %d",i);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        ff=sqrt(arr[i]);
        ii=ff;
        if(ii==ff)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}


