#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>
#define SERVERPORT 6000
int main()
{
int sockfd;
struct sockaddr_in their_addr;
int numbytes;
char arg[30];

if(sockfd=socket(AF_INET,SOCK_DGRAM, 0)==-1)//addr family,udb for dgram,
{perror("socket not created");//defined inside sys/types.h
exit(1);
}
their_addr.sin_family=AF_INET;//family type
//converting port no. to n/w type
their_addr.sin_port=htons(SERVERPORT);//host type to n/w
their_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//lookback addr,when both client and server are running on the same device

printf("enter a message");
gets(arg);//fgets()
if(numbytes=sendto(sockfd,arg,strlen(arg),0,(struct sockaddr *)&their_addr,sizeof their_addr)==-1)
{perror("send error");
exit(1);}
printf("sent %d bytes to %s\n",numbytes,inet_ntoa(their_addr.sin_addr));
close(sockfd);
return 0;
}
