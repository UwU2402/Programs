#include<stdio.h>
int main()
{
int i,j,n,time,count,flag=0,tq;
int at[10],bt[10],rt[10];
float wt=0,tat=0;
printf("Enter no. of process: ");
scanf("%d",&n);
count=n;
printf("Enter Time Quantum:\t");
scanf("%d",&tq);
for(i=0;i<n;i++)
{
printf("Enter Arrival Time and Burst Time for Process %d :",i+1);
scanf("%d%d",&at[i],&bt[i]);
rt[i]=bt[i];
}
printf("Process\tTAT\tWT\n");
for(time=0,i=0;count!=0;)
{
if(rt[i]<=tq && rt[i]>0)
{
time+=rt[i];
rt[i]=0;
flag=1;
}
else if(rt[i]>0)
{
rt[i]-=tq;
time+=tq;
}
if(rt[i]==0 && flag==1)
{
count--;
printf("P[%d]\t%d\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
wt+=time-at[i]-bt[i];
tat+=time-at[i];
flag=0;
}
if(i==n-1)
i=0;
else if(at[i+1]<=time)
i++;
else
i=0;
}
printf("\nAverage Waiting Time= %f\n",(wt/n));
printf("Avg Turnaround Time = %f",(tat/n));
return 0;
}
