#include<stdio.h>
#include<string.h>
typedef struct pkt{
char ch1;
char ch2[2];
char ch3;
}p;
void aggregate(p k){
    int number,x,y=1;
    printf("Enter a number\n");
    scanf("%d",&number);
    while(number!=0 && y<=4){
        x=number%10;
        if(y==1){
            k.ch1=x;
        }
        if(y==2){
            k.ch2[0]=x;
        }
        if(y==3){
            k.ch2[1]=x;
        }
        if(y==4){
            k.ch3=x;
        }
        y++;
        number=number/10;
    }
    printf("The aggregate characters are %d\n%d\n%d\n%d\n",k.ch3,k.ch2[1],k.ch2[0],k.ch1);
}
int main(){
    p m;
    aggregate(m);
}
