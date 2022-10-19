#include<stdio.h>
void WT(int pros[],int n,int bt[],int wt[], int at[])
{
int st[n];
st[0] = at[0];
wt[0] = 0;
for (int i = 1; i < n ; i++)
{
st[i] = st[i-1] + bt[i-1];
wt[i] = st[i] - at[i];
if (wt[i] < 0)
wt[i] = 0;
}
}
void TAT(int pros[], int n, int bt[],int wt[], int tat[])
{
for (int i = 0; i < n ; i++)
tat[i] = bt[i] + wt[i];
}
void AVGT(int pros[], int n, int bt[], int at[])
{
int wt[n], tat[n];
WT(pros, n, bt, wt, at);
TAT(pros, n, bt, wt, tat);
printf("Procs BT AT WT TAT CT\n");
int totwt = 0, tottat = 0;
for (int i = 0 ; i < n ; i++)
{
totwt = totwt + wt[i];
tottat = tottat + tat[i];
int ct = tat[i] + at[i];
printf("   %d  %d  %d  %d  %d  %d\n",i+1,bt[i],at[i],wt[i],tat[i],ct);
    }
 printf("Average waiting time = %f",(float)totwt / (float)n);
printf("\nAverage turn around time = %f",(float)tottat / (float)n);
}
int main()
{
   
    int pros[] = {1, 2, 3};
    int n = sizeof pros / sizeof pros[0];
    int at[] = {0, 2, 5};
    int bt[] = {5, 4, 7};
    AVGT(pros, n, bt, at);
    printf("\n");
    return 0;
}
