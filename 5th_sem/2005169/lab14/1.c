#include<stdio.h>
/*struct node
{
int id;
//int at;
int bt;
struct *next;
};*/
#define n=5;
int procs[n], front=-1, rear=-1, bt[n];
int main()
{
//int bt[n];
for(i=0;i<n;i++)
{
printf("Enter BT of process %d: ",i+1);
scanf("%d",&bt[i]);
}
}
void queue(int t)
{
if(rear==n-1)
printf("Queue is full");
else
{
if(front==-1)
front=0;
rear++;
bt[rear]=t;
}
}

