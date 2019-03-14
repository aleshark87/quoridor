#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define fflush() while(getchar()!='\n')
#ifdef WIN32
#define clear() (system("cls"))
#else
#define clear() (system("clear"))
#endif
struct player{
    int x;
    int y;
};
typedef struct player player;
int matrix_initialization(char **m);
void print_matrix(char **m,player *plr1,player *plr2);
void start(char **m,player *plr1,player *plr2);
int player1_move(char **m,player *plr1, player *plr2);
int player2_move(char **m,player *plr1, player *plr2);
char border_boundaries1(char **m,player *plr1, player *plr2,char move);
char border_boundaries2(char **m,player *plr1, player *plr2,char move);
char face_to_face1(player *plr1, player *plr2,char move);
char face_to_face2(player *plr1, player *plr2,char move);

#endif // LIB_H_INCLUDED


