#include <stdio.h>
#include <stdlib.h>
#include "functions.c"
#define N 17
int main()
{
    int winner=0;
    char **matr;
    player p1,p2;

    //matrix allocation
    matr=(char**)malloc(N*sizeof(char*));
    if(matr==NULL){
        return 1;
    }
    for(int i=0;i<N;i++){
        *(matr+i)=(char*)malloc(N*sizeof(char));
    }

    matrix_initialization(matr);
    start(matr,&p1,&p2);
    print_matrix(matr,&p1,&p2);

    while(1){
        //player1 firts move
        if((winner=player1_move(matr,&p1,&p2))!=0){
            system("clear");
            printf("\nAND THE WINNER IS... PLAYER %d!!\n",winner);
            return 0;
        }
        system("clear");
        print_matrix(matr,&p1,&p2);

        //player2 move
    }

    return 0;
}
