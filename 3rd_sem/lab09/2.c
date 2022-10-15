#include<stdio.h>
struct poly
{
int coeff;
int exp;
};
struct poly p1[50],p2[50],r[50];
int main()
{
int i,n;
int deg1,deg2;
int k=0,l=0,m=0;
printf("Enter the highest degree of poly1:");
scanf("%d",&deg1);
struct poly p1[deg1+1];
for(i=deg1;i>=0;i--)
{
printf("\nEnter the coeff of x^%d :",i);
scanf("%d",&p1[i].coeff);
p1[i].exp = i;
}
printf("\nEnter the highest degree of poly2:");
scanf("%d",&deg2);
struct poly p2[deg2+1];
struct poly r[deg1+deg2+2];
for(i=deg2;i>=0;i--)
{ 
printf("\nEnter the coeff of x^%d :",i);
scanf("%d",&p2[i].coeff);
p2[i].exp = i;
}
printf("\nPolynomial 1 = ");
for(i=deg1;i>=0;i--)
{
printf("%dx^%d",p1[i].coeff,p2[i].exp);
if(i!=0)
printf("+");
}   
printf("\nPolynomial 2 = ");
for(i=deg2;i>=0;i--)
{
printf("%dx^%d",p2[i].coeff,p2[i].exp);
if(i!=0)
printf("+");
}
if(deg1>deg2)
n=deg1;
else
n=deg2;
for(i=n;i>=0;i--)
{
if(p1[i].exp==p2[i].exp)
{
r[i].exp=i;
r[i].coeff=p1[i].coeff+p2[i].coeff;
}
else if(i>deg1)
{
r[i].exp=p2[i].exp;
r[i].coeff=p2[i].coeff;
}
else if(i>deg2)
{
r[i].exp=p1[i].exp;
r[i].coeff=p1[i].coeff;
}
}
printf("\nPolynomial after addition = ");
for(i=n;i>=0;i--)
{
printf("%dx^%d",r[i].coeff,r[i].exp);
if(i!=0)
printf("+");
}
printf("\n");
return 0;
}
