#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 17
#define fflush() while(getchar()!='\n')
#ifdef WIN32
#define clear() (system("cls"))
#else
#define clear() (system("clear"))
#endif
struct player{
    int x;
    int y;
    int barriers;
};
typedef struct player player;
int matrix_initialization(char **m);
void print_matrix(char **m,player *plr1,player *plr2);
void start(char **m,player *plr1,player *plr2);
int player1_move(char **m,player *plr1, player *plr2);
int player2_move(char **m,player *plr1, player *plr2);
bool border_boundaries1(char **m,player *plr1, player *plr2,int move);
bool border_boundaries2(char **m,player *plr1, player *plr2,int move);
bool face_to_face1(player *plr1, player *plr2,int move);
bool face_to_face2(player *plr1, player *plr2,int move);
#endif // LIB_H_INCLUDED
