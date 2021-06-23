#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#define C_sok struct sockaddr


void func(int C_soket)
{
	//declaracion_de_variables
	long lengitud1;
	long lengitud2;
	char client1[100000];
	char client2[100000];
	char resultado[100000];
	char auxCorden[100000]; 

	read(C_soket, client1, sizeof(client1));
	lengitud1 = strlen(client1);
	char num1[lengitud1];
	strcpy(num1, client1);



	read(C_soket, client2, sizeof(client2));
	lengitud2 = strlen(client2);
	char num2[lengitud2];
	strcpy(num2, client2);
	
	

	int longest_num;

	if(lengitud1 >= lengitud2){

		longest_num = lengitud1+1;
	}else{

		strcpy(auxCorden, num1);
		strcpy(num1, num2);
		strcpy(num2,auxCorden);

		lengitud1 = strlen(num1);
		lengitud2 = strlen(num2);

		longest_num = lengitud2+1;
	}

	printf("\n Realizando Suma...");
	int acarreo = 0;
	int aux, auxNum1, auxNum2;
	int j = lengitud2 - 1;
	if(lengitud1 >= lengitud2){
		for(int i = lengitud1 - 1; i >= 0; i--){
			auxNum1 = (num1[i]) - '0';
			if (j >= 0){
				auxNum2 = (num2[j]) - '0';
				j--;
			} else {
				auxNum2 = 0;
			}
			aux = auxNum1 + auxNum2 + acarreo;

			if (aux >= 10){
				resultado[i+1] = (aux - 10)+'0';

				acarreo = 1;
			} else {
				resultado[i+1] = (aux)+'0';
				acarreo = 0;
			}
		}
	}
		
	if(resultado[0] = '0'){

		for(int i=0; i<longest_num;i++){

			resultado[i] = resultado[i+1];
		}
	}	

	printf("\nLa resultado es: %s\n", resultado);

	write(C_soket, resultado, sizeof(resultado));
	printf("\nAnswer sent");
	
}

//funcion main
int main(int argc, char const *argv[])
{
	int sockfd, connfd, len;
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

	if ((bind(sockfd, (C_sok*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	connfd = accept(sockfd, (C_sok*)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	func(connfd);

	close(sockfd);
}
