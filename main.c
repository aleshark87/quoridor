#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int winner;
    char **matr;
    player p1,p2;
    barrier b1,b2;

    //Matrix allocation
    matr=(char**)malloc(N*sizeof(char*));
    if(matr==NULL){
        return 1;
    }
    for(int i=0;i<N;i++){
        *(matr+i)=(char*)malloc(N*sizeof(char));
    }

    //Barrier array initialization
    for(int i=0;i<10;i++){
        b1.x1[i]=-1;
        b1.y1[i]=-1;
        b1.x2[i]=-1;
        b1.y2[i]=-1;
    }
    b1.last=-1;
    b2.last=-1;

    matrix_initialization(matr);
    start(matr,&p1,&p2);
    print_matrix(matr,&p1,&p2,&b1,&b2);

    while(1){
        //player1 firts move
        if(player1_move(matr,&p1,&p2,&b1,&b2)==1){
            clear();
            printf("\nAND THE WINNER IS... PLAYER 1!!\n");
            return 0;
        }
        clear();
        print_matrix(matr,&p1,&p2,&b1,&b2);

        //player2 move
        if(player2_move(matr,&p1,&p2)==2){
            clear();
            printf("\nAND THE WINNER IS... PLAYER 2!!\n");
            return 0;
        }
        clear();
        print_matrix(matr,&p1,&p2,&b1,&b2);
        //player2 move
    }

    return 0;
}
