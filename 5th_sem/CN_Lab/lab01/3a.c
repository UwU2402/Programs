#include<stdio.h>
int main(){
int variable = 0x12345678; /* 4 byte integer containing some value */
char byte0, byte1, byte2, byte3; /* Variables to hold the char-values */
byte0 = ((char*)(&variable))[0];
byte1 = ((char*)(&variable))[1];
byte2 = ((char*)(&variable))[2];
byte3 = ((char*)(&variable))[3];
printf("byte0= %c\n",byte0);
printf("byte1= %c\n",byte1);
printf("byte2= %c\n",byte2);
printf("byte3= %c\n",byte3);

}
