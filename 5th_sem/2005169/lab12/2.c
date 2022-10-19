#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
int main()
{
int r;
r=fork();
if(r==0)
{
printf("The process is child process\n");
printf("child id=%d\n", getpid());
printf("parent id=%d\n",getppid());
}
else
{
printf("The process is the parent process\n");
printf("The process id=%d\n",getpid());
printf("parent id=%d\n",getppid());
}
return 0;
}
