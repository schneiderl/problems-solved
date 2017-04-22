#include <stdio.h>
#include <winsock.h>
#include <windows.h>
#include <locale.h>
#include <unistd.h>

WSADATA data; 
SOCKET winsock; 
SOCKADDR_IN sock; 

int bytes; 

const int MAX_HITS = 1;
int c1hits = 0;
int c2hits = 0;

char boardc1[100]; 
char boardc2[100]; 
char buffer[5];


int main(){
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


    if(bind(winsock, (SOCKADDR*)&sock, sizeof(sock))==SOCKET_ERROR){
        printf("%s\n", "Erro no binding");
        return -1; 
    }

    listen(winsock,1);

    //since the game only have two players
    SOCKET client1; 
    SOCKET client2;
    SOCKET winbuff;
    if((client1 = socket(AF_INET, SOCK_STREAM,0))==SOCKET_ERROR){
        printf("%s\n", "Erro na inicialização do socket");
        return -1; 
    }
    if((client2 = socket(AF_INET, SOCK_STREAM,0))==SOCKET_ERROR){
        printf("%s\n", "Erro na inicialização do socket");
        return -1; 
    }
    printf("%s\n", "Server executando.");
    int c = 0; 
    while(c<2){
        winbuff = winsock; 
        while((winsock=accept(winsock,0,0))==SOCKET_ERROR){
            printf("%s\n", "err");
            sleep(1);
        }

        switch(c){
            case 0: client1 = winsock; winsock = winbuff; printf("%s\n",  "c1 conectado"); c++; break; 
            case 1: client2 = winsock; winsock = winbuff; printf("%s\n",  "c2 conectado"); c++; break;
        }

    }

    //avisando os clientes de que os dois estao conectados
    send(client1, "X", 1, 0);
    send(client2, "X", 1, 0);


    memset(boardc1, 0, 100); memset(boardc2, 0, 100); 
    //temos os sockets pros clientes. vamos inicializar o board.
    recv(client1, boardc1, 100, 0);
    recv(client2, boardc2, 100, 0);
    int turno = 0 ;
    

    while(1){
        memset(buffer, 0, 1); 
        // send(client1, "C", 1, 0);
        // bytes = recv(client1, buffer, 1, 0);
        // printf("%s\n", "aaaa");
        // if(bytes==-1){
        //     send(client2, "D", 1, 0);
        //     printf("%s\n", "Falha de conexão");
        //     return 0;
        // } else{
        //     send(client2, "G", 1, 0);
        // }
        // printf("%s\n", "aaaa");
        // bytes = recv(client2, buffer, 1, 0);
        // if(bytes==-1){
        //     send(client1, "D", 1, 0);
        //     printf("%s\n", "Falha de conexão");
        //     return 0;
        // } else{
        //     send(client1, "G", 1, 0);
        // }
        if((turno%2)==0){
            printf("%s\n", "Turno do C1");
            send(client1, "P", 1, 0);
            send(client2, "E", 1, 0);
            bytes = recv(client1, buffer, 5, 0);
        } else{
            printf("%s\n", "Turno do C2");
            send(client1, "E", 1, 0);
            send(client2, "P", 1, 0);
            bytes = recv(client2, buffer, 5, 0);
        }

        if(bytes==-1){
            //Houve DC
            printf("%s\n", "Falha na conexão");
            return 0;
        }


        //pegar as strings das posicoes de fato
        char cx[4]; char cy[4];
        memcpy(cx, &buffer[0],2); cx[2] = '\0';
        memcpy(cy, &buffer[3],2); cy[2] = '\0';
        int x = atoi(cx); int y = atoi(cy);
        int pos = (y*10) + x;
        if(turno%2==0){
            char helper[3]; //obrigado C
            memcpy(helper, &boardc2[pos],1); helper[1] = '\0';
            if(strcmp(helper,"X") == 0){
                c1hits++;
                boardc2[pos] = 'H';
                send(client1, "H", 1, 0);
            } else{
                boardc2[pos] = 'M';
                send(client1, "M", 1, 0);
            }
        } else{
            char helper[3]; //obrigado C
            memcpy(helper, &boardc1[pos],1); helper[1] = '\0';
            if(strcmp(helper,"X") == 0){
                c2hits++; 
                boardc1[pos] = 'H';
                send(client2, "H", 1, 0);
            } else{
                boardc1[pos] = 'M';
                send(client2, "M", 1, 0);
            }


        }

        if(turno%2==0){
            send(client2, boardc2, strlen(boardc2), 0);
        } else{
            send(client1, boardc1, strlen(boardc1), 0);
        }
        
        if(c1hits == MAX_HITS ) {
            send(client1, "W", 1, 0);
            send(client2, "L", 1, 0);
        }

        if(c2hits == MAX_HITS ) {
            send(client2, "W", 1, 0);
            send(client1, "L", 1, 0);
        }

        //atualizar os boards dos clientes

        turno++;
    }




    return 0;

}
