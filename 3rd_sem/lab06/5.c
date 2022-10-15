#include <stdio.h>
int main()
{
    int i,j,r,c,h=0,a=0,b=0;
    printf("Enter the no of rows: ");
    scanf("%d",&r);
    printf("Enter the no of cols: ");
    scanf("%d",&c);
    int mat[r][c];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            printf("Element for (%d,%d): ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    printf("\nThe matrix is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d  ",mat[i][j]);
            if(mat[i][j]!=0)
            {
                if(i>a)
                {
                    a=i;
                }
                if(j>b)
                {
                    b=j;
                }
                h++;
            }
        }
        printf("\n");
    }
    int t1[h+1][3],t2[h+1][3],s[h+1][3],z=1;
    t1[0][0]=r;
    t1[0][1]=c;
    t1[0][2]=h;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(mat[i][j]!=0)
            {
                t1[z][0]=i+1;
                t1[z][1]=j+1;
                t1[z][2]=mat[i][j];
                z++;
            }
    printf("\n3-tuple form:\n");
    for(i=0;i<h+1;i++)
    {
        for (j=0;j<3;j++)
            printf("%d  ",t1[i][j]);
        printf("\n");
    }
    t2[0][0]=a+1;
    t2[0][1]=b+1;
    t2[0][2]=h;
    for(i=1;i<h+1;i++)
        for(j=0;j<3;j++)
            t2[i][j]=t1[i][j];
    printf("\nReduced form:\n");
    for(i=0;i<h+1;i++)
    {
        for (j=0;j<3;j++)
            printf("%d  ",t2[i][j]);
        printf("\n");
    }
    for(i=0;i<h+1;i++)
        for(j=0;j<3;j++)
            s[i][j]=t1[i][j]+t2[i][j];
    printf("\nSum of two 3-tuple matrices is:\n");
    for(i=0;i<h+1;i++)
    {
        for(j=0;j<3;j++)
            printf("%d  ",s[i][j]);
        printf("\n");
    }
    return 0;
}
