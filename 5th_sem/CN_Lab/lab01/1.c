#include<stdio.h>
int main()
{
int a,b,*x,*y,c;
printf("Enter two no.s:\n");
scanf("%d%d",&a,&b);
printf("Before swapping:\na=%d\nb=%d\n",a,b);
x=&a;
y=&b;
c=*x;
*x=*y;
*y=c;
printf("After swapping:\na=%d\nb=%d\n",a,b);
return 0;
}
