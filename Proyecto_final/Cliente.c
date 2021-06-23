#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define C_sok struct sockaddr

void func(int C_soket)
{
	char buff[1000];
	char num1[1000];
	char num2[1000];
	char resultado[1000];

	bzero(buff, sizeof(buff));
	bzero(resultado,sizeof(resultado));
	bzero(num1, sizeof(num1));
	bzero(num2,sizeof(num2));


	printf("Enter number 1 : ");
	scanf("%s", &num1);

	write(C_soket, num1, sizeof(num1));
	
	printf("Enter number 2 : ");
	scanf("%s", &num2);

	write(C_soket, num2, sizeof(num2));
	

	bzero(buff, sizeof(buff));
	bzero(resultado,sizeof(resultado));

	read(C_soket, buff, sizeof(buff));
	strcpy(resultado,buff);
	printf("The answer from Server : %s\n", resultado);
}

int main(int argc, char **argv)
{

	if(argc<2){
		printf("<host> <puerto>\n");
    	return 1;
  	}

	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (connect(sockfd, (C_sok*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		return -1;
	}
	else
		printf("connected to the server..\n");

	func(sockfd);

	close(sockfd);
}


