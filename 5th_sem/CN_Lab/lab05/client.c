#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

int main()
{
int sockfd,i; 
char buf[100];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6001);
i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));
for(i=0;i<100;i++)
{
recv(sockfd,buf,100,0);}
printf("%s\n",buf);

for(i=0;i<100;i++)
{
buf[i]='\0';
}
strcpy(buf,"Message from client");
send(sockfd,buf,100,0);

close(sockfd);
return 0;
}
