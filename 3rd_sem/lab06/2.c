#include <stdio.h>
#include<stdlib.h>
#define size 10
int top=-1;
int stack[size];
void Push();
void Pop();
void Display();
int main()
{
int choice;
while(1)
{
printf("1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:Push();
break;
case 2:Pop();
break;
case 3:Display();
break;
case 4:exit(1);
default:"Invalid Choice.\n";
break;
}
}
return 0;
}
void Push()
{
int element;
if(top==(size-1))
{
printf("Stack Overflow.\n");
return;
}
else
{
printf("Enter the element:");
scanf("%d",&element);
top=top+1;
stack[top]=element;
}
}
void Pop()
{
if(top==-1)
{
printf("Stack Underflow.\n");
return;
}
else
{
printf("The popped element is %d.\n",stack[top]);
top=top-1;
}
}
void Display()
{
int i;
if(top==-1)
{
printf("Stack is empty.\n");
}
else
{ 
for(i=top;i>=0;i--)
printf("%d \n",stack[i]);
}
}
