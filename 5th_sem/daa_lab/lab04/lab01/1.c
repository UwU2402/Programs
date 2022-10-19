#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
srand(time(0));
for(int i=0;i<1000;i++)
printf("%d\t",rand());
return 0;
}
