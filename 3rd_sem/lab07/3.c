#include<stdio.h>
int main()
{
    int m,n,i,j,count;
    int arr[m][n];
    printf("Enter the no of rows:");
    scanf("%d",&m);
    printf("\nEnter the no of columns:");
    scanf("%d",&n);
    printf("\nEnter the array elements:\n");
    printf("\nYou are only allowed to enter 1 and 0\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if((arr[i][j]!=1)&&(arr[i][j]!=0))
            {
                break;
            }
        }
    }
    printf("\nThe original matrix is:\n");
    for( i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\nThe matrix after operation is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            count=0;
            for(int k=0;k<n;k++)
            {
                if((arr[i][j]==0)&&(arr[i][k]==1))
                {
                    count=count+1;
                }
            }
            if(count==n-1)
            {
                arr[i][j]=1;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",arr[i][j]);
            printf("  ");
        }
        printf("\n");
    }
    return 0;
}
