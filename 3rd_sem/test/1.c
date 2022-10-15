#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct infix
{
int stack[MAX];
int top,n;
char *s;
};
void infix(struct infix *);
void setexpr(struct infix *,char *);
void push(struct infix *,char);
char pop(struct infix *);
void convert (struct infix *);
int prio(char);
void show(struct infix);
int main()
{
struct infix p;
char expr[MAX];
infix(&p);
printf("Enter an infix expression:\n");
gets(expr);
setexpr(&p,expr);
convert(&p);
printf("Postfix expression:\n");
show(p);
return 0;
}
void infix(struct infix *p)
{
p->top=-1;
strcpy(p->target,"");
strcpy(p->stack,"");
p->t=p->target;
p->s="";
}
void setexpr(struct infix *p,char *str)
{
p->s=str;
}
void push (struct infix *p,char c)
{
if(p->top==MAX)
printf("Stack full\n");
else
{
p->top++;
p->stack[p->top]=c;
}
}
char pop(struct infix *p)
{
if(p->top==-1)
{
printf("Stack is empty\n");
return -1;
}
else
{
char item=p->stack[p->top];
p->top--;
return item;
}
}
void convert(struct infix *p)
char opr;
while (*(p->s))
{
if(*(p->s)==' '||*(p->s)=='\t')
{
p->s++;
continue;
}
if (isdigit(*(p->s))||isalpha(*(p->s)))
{
while(isdigit(*(p->s))||isalpha(*(p->s)))
{
*(p->t)=*(p
}
}
}
