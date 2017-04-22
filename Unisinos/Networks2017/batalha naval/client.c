#include <stdio.h>
#include <winsock.h>
#include <windows.h>
#include <locale.h>
#include <unistd.h>

WSADATA data; 
SOCKET winsock; 
SOCKADDR_IN sock; 

int g_bytes; 
char buffer[1];
char boardbuffer[102]; 
char opponentbuffer[102]; 

void printGrid(){
	printf("%s\n", "     Você                     Oponente");
	printf("%s\n", "  0 1 2 3 4 5 6 7 8 9     0 1 2 3 4 5 6 7 8 9" );

	for (int i = 0; i < 10; ++i){
		printf("%d ", i);
		for (int j = 0; j < 10; ++j){
			printf("%c ", boardbuffer[i*10+j]);
		}
		printf("    ");
		for (int j = 0; j < 10; ++j){
			printf("%c ", opponentbuffer[i*10+j]);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[]){
	
	memset(opponentbuffer, 0, 102); //informação mantida localmente. só precisa ser limpa 
	strcpy(opponentbuffer, "????????????????????????????????????????????????????????????????????????????????????????????????????\0");

	if(WSAStartup(MAKEWORD(1,1), &data)==SOCKET_ERROR){
		printf("%s\n", "Erro na inicialização do winsock");
		return -1; 
	}

	if((winsock = socket(AF_INET, SOCK_STREAM,0))==SOCKET_ERROR){
		printf("%s\n", "Erro na inicialização do socket");
		return -1; 
	}

	sock.sin_family=AF_INET; 
	sock.sin_port=htons(1234);
	sock.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(connect(winsock, (SOCKADDR*)&sock, sizeof(sock))==SOCKET_ERROR){
		printf("%s\n", "Erro ao se conectar");
		return -1; 
	} else{
		printf("%s\n", "conectado" );
	}
	memset(buffer, 0, 1); 
	recv(winsock, buffer, 1, 0);
	memset(boardbuffer, 0, 102); 
















	if (argc==2){

		FILE *inputfile;
		inputfile = fopen(argv[1], "r");
		int c; 
		int counter = 0;
		 while(1){
		 	c = fgetc(inputfile);
		 	if( feof(inputfile)){ break; } // EOF
		 	if(c!='\n'){
		// 		boardbuffer[counter] = c; 
		 		counter++; 
		 	}

		 }
		 //boardbuffer[counter] = '\0';
	} else{
		printf("%s\n", "Erro nos parâmetros");
		return 0;
	}
	//printf("%s\n", boardbuffer);
	return 0; 



	strcpy(boardbuffer, "**************************************X*************************************************************\0");
	send(winsock, boardbuffer, strlen(boardbuffer), 0);
	
	while((strcmp(buffer, "W")!=0 && strcmp(buffer, "L")!=0)){
	 	//pegar versão atualizada do board no server
		//memset(boardbuffer, 0,100);
		printGrid();
		memset(buffer, 0, 1);

		//Garantir conexão
		int bytes; 
		bytes = recv(winsock, buffer, 1, 0);
		if(bytes==-1){
			printf("%s\n", "Falha na conexão");
			return 0;
		}
		if(strcmp(buffer, "P") == 0){
			// Jogando
			printf("%s", "Jogada:");
			char jogada[5]; scanf("%5s", jogada);
			send(winsock, jogada, strlen(jogada), 0);
			memset(buffer, 0, 1); 
			recv(winsock, buffer, 1, 0);

			char cx[4]; char cy[4];
			memcpy(cx, &jogada[0],2); cx[2] = '\0';
			memcpy(cy, &jogada[3],2); cy[2] = '\0';
			int x = atoi(cx); int y = atoi(cy);
			if(strcmp(buffer, "H") == 0){
			//Acertou o oponente
				printf("%s\n", "HIT");
				opponentbuffer[(y*10)+x] = 'H';
			} else{
			//Errou o oponente
				printf("%s\n", "MISS");
				opponentbuffer[(y*10)+x] = 'M';
			}
		} else{
			// Esperando
			printf("%s\n", "Aguardando turno do oponente.");
			recv(winsock, boardbuffer, 102, 0);
		}

	}	

	if((strcmp(buffer, "W")==0)){
		printf("%s\n", "Você Venceu!");
	} else{
		printf("%s\n", "Você perdeu!");
	}


	return 0; 
}

// H = HIT
// M = MISS
// W = WIN
// L = LOSE
// * = MAR
// X = BARCO
// E = ESPERANDO