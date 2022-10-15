#include<stdio.h>
int main()
{
int a=2513;
char ch;
int n=a;
while(n!=0)
{
int num=n%10;
ch=(char)(48+num);
printf("%c ",ch);
n=n/10;
}
return 0;
}
