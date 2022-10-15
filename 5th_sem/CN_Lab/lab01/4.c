#include<stdio.h>
#include<string.h>
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
void split(struct pkt k)
{
int num,x,y=1,n=0;
printf("Enter a no.:");
scanf("%d",&num);
while(num!=0&&y<=4)
{
x=num%10;
if(y==1)
k.ch1=x;
if(y==2)
k.ch2[0]=x;
if(y==3)
k.ch2[1]=x;
if(y==4)
k.ch3=x;
y++;
num=num/10;
}
n=n*10+(k.ch3-'0');
n=n*10+(k.ch2[1]-'0');
n=n*10+(k.ch2[0]-'0');
n=n*10+(k.ch1-'0');
printf("The characters are%d\n%d\n%d\n%d\n",k.ch3,k.ch2[1],k.ch2[0],k.ch1);
printf("After concatenating:%d",n);
}
int main()
{
struct pkt m;
split(m);
return 0;
}
