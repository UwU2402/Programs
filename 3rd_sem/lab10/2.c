#include<stdio.h>
int main()
{
int x[2],y[2],X,Y;
for(int i=0;i<2;i++)
{
printf("Enter the polynomial %d:\n",i+1);
printf("Enter the coef of 'x':");
scanf("%d",&x[i]);
printf("Enter the coef of 'y':");
scanf("%d",&y[i]);
printf("Polynomial 1: %dx+%dy\n",x[i],y[i]);
}
X=x[0]+x[1];
Y=y[0]+y[1];
printf("After addition: %dx+%dy",X,Y);
return 0;
}
