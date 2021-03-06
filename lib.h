#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
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
};
struct barrier{
    char x1[10];
    char y1[10];
    char x2[10];
    char y2[10];
    char x3[10];
    char y3[10];
    char x4[10];
    char y4[10];
    char direction[10];
    int last;
    int num;
};
typedef struct barrier barrier;
typedef struct player player;
int matrix_initialization(char **m);
void print_matrix(char **m,player *plr1,player *plr2,barrier *b1,barrier *b2);
void start(char **m,player *plr1,player *plr2);
int player1_move(char **m,player *plr1, player *plr2,barrier *b1,barrier *b2);
int player2_move(char **m,player *plr1, player *plr2);
bool border_boundaries1(char **m,player *plr1, player *plr2,int move);
bool border_boundaries2(char **m,player *plr1, player *plr2,int move);
bool face_to_face1(player *plr1, player *plr2,int move);
bool face_to_face2(player *plr1, player *plr2,int move);
int getch_(void);
int wall_placing1(char **m,player *plr1,player *plr2,barrier *b1, barrier *b2);
int barrier1_border_boundaries(char **m, barrier *b1,int move, char mode);
bool clash1(barrier *b1,barrier *b2);
int finish_line(player *p1,player *p2);
void print_debug_matrix(char **m);
#endif // LIB_H_INCLUDED
