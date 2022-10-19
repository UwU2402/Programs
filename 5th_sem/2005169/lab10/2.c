#include<stdio.h>
int main()
{
   
    int pros[] = {1, 2, 3},i,j,temp,end,ct[3],wt[3],tat[3];
    double avgwt,avgtat,tt;
    int n = sizeof pros / sizeof pros[0];
    int at[] = {0, 2, 5};
    int bt[] = {5, 4, 7}=xt[];
    for(i=0;i<2;i++)
    {
    for(j=i+1;j<2;j++)
    {
    if(at[i]>ar[j])
    {
    temp=at[i];
    at[i]=at[j];
    at[j]=temp;
    temp=bt[i];
    bt[i]=br[j];
    bt[j]=temp;
    }
    }
    }
    int least=2;
    bt[2]=1000;
    for(t=0;y<3;t++)
    {
    least=2;
    for(i=0;i<3;i++)
    {
    if(at[i]<=t&&b[t]<b[least]&&b[i]>0)
    least=i;
    }
    b[least]--;
    if(b[least]==0)
    {
    y++;
    end=time+1;
    ct[least]=end;
    wt[least]=end-at[least]-xt[least];
    }
    }
    printf("Procs BT AT WT TAT CT\n");
    for(i=0;i<3;i++)
    {
    printf("   %d  %d  %d  %d  %d  %d\n",i+1,at[i],xt[i],wt[i],tat[i],ct);
    
    avgwt=avgwt+wt[i];
    tt=tt+tat[i];
    }
    printf("Average waiting time = %f",(avgwt /3);
printf("\nAverage turn around time = %f",(tt /3);
    printf("\n");
    return 0;
}
