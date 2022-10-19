#include<stdio.h>
int main()
{
int i,j,n,time,count=0,least;
float avgwt=0,avgtat=0,end;
printf("Enter total no. of process:");
scanf("%d",&n);
int at[n],bt[n],pri[n],procs[n],wt[n],tat[n],ct[n],x[n];
for(i=0;i<n;i++)
{
printf("Enter AT, BT and priority of process %d: ",i+1);
scanf("%d%d%d",&at[i],&bt[i],&pri[i]);
}
for(i=0;i<n;i++)
x[i]=bt[i];
//procs[i]=i+1;
pri[n-1]=99;
for(time=0;count!=n;time++)
{
least=9;
for(i=0;i<n;i++)
{
if(at[i]<=time&&pri[least]>pri[i]&&bt[i]>0)
least=i;
}
bt[least]=bt[least]-1;
if(bt[least]==0)
{
count++;
wt[least]=time+1-at[least]-x[least];
tat[least]=time+1-at[least];
end=time+1;
ct[least]=end;
}
}
printf("Priority\tArrival-time\t Bust-time\t Waiting-time\t Turnaround-time\t Completion-time\n");
for (i = 0; i < n; i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",pri[i], at[i], x[i],wt[i], tat[i], ct[i]);
avgwt = avgwt + wt[i];
avgtat = avgtat + tat[i];
}
printf("Average waiting time: %f", (avgwt / n));
printf("\nAverage Turnaround time: %f\n", (avgtat / n));
return 0;
}
