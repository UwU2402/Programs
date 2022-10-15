#include<stdio.h>

int main()
{
int n;
printf("Enter the no. of rows and columns of the matrix:\n");
scanf("%d",&n);
int ar1[n][n],ar2[n][n],r[n][n];
printf("Enter the elements of the first matrix:\n");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
scanf("%d",&ar1[i][j]);
}
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
//for(int q=0;q<n;q++)
//{
//for(int p=0;p<n;p++)
//{
r[i][j]=ar1[i][j]+ar1[j][i];
//}
//}
}
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",ar1[i][j]);
}
printf("\n");
}
printf("\n");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",ar1[j][i]);
}
printf("\n");
}
printf("\n");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",r[i][j]);
}
printf("\n");
}
printf("The output matrix in three tuple method is:\n");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(r[i][j]!=0)
printf("%d %d %d\n",i,j,r[i][j]);
}
//printf("\n");
}
return 0;
}
