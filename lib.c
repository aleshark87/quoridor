#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
viva windows
int matrix_initialization(char **m){
    /*	The function initializes the playing field, assigns
	 *	to zero the playable blocks, to 2 the blocks for the barriers
	 */
    int i,k;
    for(i=0;i<N;i++){
        if((i+1)%2==1){
            for(k=1;k<N;k+=2){
                m[i][k]='2';
            }
            for(k=0;k<N;k+=2){
                m[i][k]='0';
            }
        }else{
            for(k=0;k<N;k++){
                m[i][k]='2';
            }
        }
    }
return 0;
}
void print_matrix(char **m,player *plr1,player *plr2){
    int i,k;
    for(i=0;i<N;i++){
        for(k=0;k<N;k++){
            /*a "+" is printed in the player's position*/
            if((plr1->x==k&&plr1->y==i)||(plr2->x==k&&plr2->y==i)){
                printf("+ ");
            }
            else{
                /*a space is printed if the barriers are empty*/
                if(m[i][k]=='2'){
                    printf("  ");
                }
                /*a dot is printed if the barrier is present*/
                else{
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
    /*player choice*/
    printf("\nMovements: q=left,w=up,e=right\n\n");
}

void start(char **m,player *plr1,player *plr2){
    int half=N/2;
    //player1 starting from the bottom
    plr1->x=half;
    plr1->y=N-1;
    //player2 starting from the top
    plr2->x=half;
    plr2->y=0;

}
int finish_line(player *plr1,player *plr2){
    //if a player reaches the opposite side the game is over
    if(plr1->y==0){
        return 1;
    }
    if(plr2->y==N-1){
        return 2;
    }
    return 0;
}

int player1_move(char **m,player *plr1, player *plr2){
    char move;
    int winner=0;
    //move: q=left,w=up,e=right
    printf("\nPlayer 1. It's your turn. Enter the move: ");
    scanf("%s",&move);
    fflush(stdin);

    move=border_boundaries(m,plr1,plr2,move);

    switch(move){
        case 'q':
            plr1->x=(plr1->x)-2;
            break;
        case 'w':
            plr1->y=(plr1->y)-2;
            winner=finish_line(plr1,plr2);
            break;
        case 'e':
            plr1->x=(plr1->x)+2;
            break;
    }
    return winner;
}
char border_boundaries(char **m,player *plr1, player *plr2,char move){

    while(move!='q'&&move!='w'&&move!='e'){
        printf("\nPlease,enter a valid movement\n");
        scanf("%c",&move);
        fflush(stdin);
    }
        //check of possible movements
    if(plr1->x==N-1){
        while(move=='e'){
            printf("\nPlease,enter a valid movement\n");
            scanf("%c",&move);
            fflush(stdin);
        }
    }
    if(plr1->x==0){
        while(move=='q'){
            printf("\nPlease,enter a valid movement\n");
            scanf("%c",&move);
            fflush(stdin);
        }
    }
    if(plr1->y==0){
        while(move=='w'){
            printf("\nPlease,enter a valid movement\n");
            scanf("%c",&move);
        }
    }
    if(plr1->x==0&&plr1->y==0){
         while(move=='q'||move=='w'){
            printf("\nPlease,enter a valid movement\n");
            scanf("%c",&move);
            fflush(stdin);
        }
    }
    if(plr1->x==N-1&&plr1->y==0){
         while(move=='q'||move=='w'){
            printf("\nPlease,enter a valid movement\n");
            scanf("%c",&move);
            fflush(stdin);
        }
    }
    return move;
}

