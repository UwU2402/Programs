#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
int a ;
int b ;
int c ;
int d ;
int e ;
int f ;
int g ;
int h ;
int i ;
b=fork();
if (b == 0) //it's child
{
d= fork();
if(d==0)
{
h=fork();
if(h==0)
{
i=fork();
if(i==0)
printf("%d: I\n", getpid());
else
printf("%d: H\n", getpid());
}
else
printf("%d: D\n", getpid());
}
else
{
e=fork();
if(e==0)
printf("%d: E\n", getpid());
else
{
f=fork();
if(f==0)
printf("%d: F\n", getpid());
else
printf("%d: B\n", getpid());
}
}
}
else
{
c=fork();
if(c==0){
g=fork();
if(g==0)
printf("%d: G\n", getpid());
else
printf("%d: C\n", getpid());
}
else
printf("%d: A\n", getpid());
}
return 0;
}
