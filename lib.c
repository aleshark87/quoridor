#include "lib.h"

int matrix_initialization(char **m){
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
            if(plr1->x==k&&plr1->y==i){
                printf("1 ");
            }
            else if(plr2->x==k&&plr2->y==i){
                printf("2 ");

            }else{
                if(m[i][k]=='2'){
                    printf("  ");
                }else{
                    printf(". ");
                }
                //printf("%c ",m[i][k]);
            }
        }
        printf("\n");
    }
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

    int move,winner=0;

    //Move before controls
    printf("\nPlayer 1. It's your turn. Enter the move: ");
    scanf("%d",&move);
    fflush();

	//border boundaries player_one
    while(border_boundaries1(m,plr1,plr2,move)==false){
        printf("\nInvalid movement, reinsert: ");
        scanf("%d",&move);
        fflush();
    }


    switch(move){
        case 1:
            plr1->x=(plr1->x)-2;
            break;
        case 2:
            plr1->y=(plr1->y)-2;
            winner=finish_line(plr1,plr2);
            break;
        case 3:
            plr1->y=(plr1->y)+2;
            break;
        case 4:
            plr1->x=(plr1->x)+2;
            break;
        case 11:
            plr1->x=plr1->x-4;
            break;
        case 22:
            plr1->y=plr1->y-4;
            break;
        case 33:
            plr1->y=plr1->y+4;
            break;
        case 44:
            plr1->x=plr1->x+4;
            break;
        case 12:
            plr1->x=plr1->x-2;
            plr1->y=plr1->y-2;
            break;
        case 13:
            plr1->x=plr1->x-2;
            plr1->y=plr1->y+2;
            break;
        case 21:
            plr1->y=plr1->y-2;
            plr1->x=plr1->x-2;
            break;
        case 24:
            plr1->y=plr1->y-2;
            plr1->x=plr1->x+2;
            break;
        case 31:
            plr1->y=plr1->y+2;
            plr1->x=plr1->x-2;
            break;
        case 34:
            plr1->y=plr1->y+2;
            plr1->x=plr1->x+2;
            break;
        case 42:
            plr1->x=plr1->x+2;
            plr1->y=plr1->y-2;
            break;
        case 43:
            plr1->x=plr1->x+2;
            plr1->y=plr1->y+2;
            break;
    }
    return winner;
}
bool border_boundaries1(char **m, player *plr1, player *plr2, int move){

    //If the move is equal to: ... check (1) if the face to face is detected and (2) you can move in that way. If not return -1 and then repeat the move
    if(move==11||move==22||move==33||move==44||move==12||move==13||move==21||move==24||move==42||move==43){

        if(face_to_face1(plr1,plr2,move)==true){ /* here i'll must write control for the barriers check return function */
            switch(move){
                case 11:
                    if(plr1->x-4<0){
                        return false;
                    }
                    return true;
                case 22:
                    if(plr1->y-4<0){
                        return false;
                    }
                    return true;
                case 33:
                    if(plr1->y+4>N-1){
                        return false;
                    }
                    return true;
                case 44:
                    if(plr1->x+4>N-1){
                        return false;
                    }
                    return true;
                case 12:
                case 13:
                    if(plr1->x!=2){
                        return false;
                    }
                    return true;
                case 21:
                    if((plr1->y==2&&plr1->x==0)||plr1->y!=2){
                        return false;
                    }
                    return true;
                case 24:
                    if((plr1->y==2&&plr1->x==N-1)||plr1->y!=2){
                        return false;
                    }
                    return true;
                case 42:
                case 43:
                    if(plr1->x!=N-1-2){
                        return false;
                    }
                    return true;
            }
        }
    }else if(move==1||move==2||move==3||move==4){
        if(face_to_face1(plr1,plr2,move)==false){
            switch(move){
                case 1:
                    if(plr1->x-2<0){
                        return false;
                    }
                    return true;
                case 2:
                    return true;
                case 3:
                    if(plr1->y+2>N-1){
                        return false;
                    }
                    return true;
                case 4:
                    if(plr1->x+2>N-1){
                        return false;
                    }
                    return true;
            }
        }else{
            return false;
        }
    }
    return false;

}

int player2_move(char **m,player *plr1, player *plr2){

    int move,winner=0;

    // Move before controls
    printf("\nPlayer 2. It's your turn. Enter the move: ");
    scanf("%d",&move);
    fflush();

    // Border boundaries player_two
    while(border_boundaries2(m,plr1,plr2,move)==false){
        printf("\nInvalid movement, reinsert: ");
        scanf("%d",&move);
        fflush();
    }


    switch(move){
        case 1:
            plr2->x=plr2->x-2;
            break;
        case 2:
            plr2->y=plr2->y+2;
            winner=finish_line(plr1,plr2);
            break;
        case 3:
            plr2->y=plr2->y-2;
            break;
        case 4:
            plr2->x=plr2->x+2;
            break;
        case 11:
            plr2->x=plr2->x-4;
            break;
        case 22:
            plr2->y=plr2->y+4;
            break;
        case 33:
            plr2->y=plr2->y-4;
            break;
        case 44:
            plr2->x=plr2->x+4;
            break;
        case 12:
            plr2->x=plr2->x-2;
            plr2->y=plr2->y+2;
            break;
        case 13:
            plr2->x=plr2->x-2;
            plr2->y=plr2->y-2;
            break;
        case 21:
            plr2->y=plr2->y+2;
            plr2->x=plr2->x-2;
            break;
        case 24:
            plr2->y=plr2->y+2;
            plr1->x=plr1->x+2;
            break;
        case 31:
            plr2->y=plr2->y-2;
            plr2->x=plr2->x-2;
            break;
        case 34:
            plr2->y=plr2->y-2;
            plr2->x=plr2->x+2;
            break;
        case 42:
            plr2->x=plr2->x+2;
            plr2->y=plr2->y+2;
            break;
        case 43:
            plr2->x=plr2->x+2;
            plr2->y=plr2->y-2;
            break;
    }
    return winner;
}

bool border_boundaries2(char **m,player *plr1, player *plr2,int move){

    //If the move is equal to: ... check (1) if the face to face is detected and (2) you can move in that way. If not return -1 and then repeat the move
    if(move==11||move==22||move==33||move==44||move==12||move==13||move==21||move==24||move==42||move==43){

        if(face_to_face2(plr1,plr2,move)==true){ /* here i'll must write control for the barriers check return function */
            switch(move){
                case 11:
                    if(plr2->x-4<0){
                        return false;
                    }
                    return true;
                case 22:
                    if(plr2->y+4>N-1){
                        return false;
                    }
                    return true;
                case 33:
                    if(plr2->y-4<0){
                        return false;
                    }
                    return true;
                case 44:
                    if(plr2->x+4>N-1){
                        return false;
                    }
                    return true;
                case 12:
                case 13:
                    if(plr2->x!=2){
                        return false;
                    }
                    return true;
                case 21:
                    if((plr2->y==N-3&&plr2->x==0)||plr2->y!=N-3){
                        return false;
                    }
                    return true;
                case 24:
                    if((plr2->y==N-3&&plr2->x==N-1)||plr2->y!=N-3){
                        return false;
                    }
                    return true;
                case 42:
                case 43:
                    if(plr2->x!=N-3){
                        return false;
                    }
		   return true;
            }
        }
    // Else, the player entered a normal move
    }else if(move==1||move==2||move==3||move==4){
        if(face_to_face2(plr1,plr2,move)==false){
            switch(move){
                case 1:
                    if(plr2->x-2<0){
                        return false;
                    }
                    return true;
                case 2:
                    return true;
                case 3:
                    if(plr2->y-2<0){
                        return false;
                    }
                    return true;
                case 4:
                    if(plr2->x+2>N-1){
                        return false;
                    }
                    return true;
            }
        }else{
            return false;
        }
    }
    // In all the other cases, return false
    return false;

}

// Face to face is a function that controls if the player can jump over the opponent if they are near to each other.

bool face_to_face1(player *plr1, player *plr2, int move){

    switch(move){
        //Left face to face
        case 1:
        case 11:
        case 12:
        case 13:
            if(plr1->x-2==plr2->x&&plr1->y==plr2->y){
                return true;
            }
            return false;
        //Top face to face
        case 2:
        case 22:
        case 21:
        case 24:
            if(plr1->y-2==plr2->y&&plr1->x==plr2->x){
                return true;
            }
            return false;
        //Bottom face to face
        case 3:
        case 33:
        case 31:
        case 34:
            if(plr1->y+2==plr2->y&&plr1->x==plr2->x){
                return true;
            }
            return false;
        //Right face to face
        case 4:
        case 44:
        case 42:
        case 43:
            if(plr1->x+2==plr2->x&&plr1->y==plr2->y){
                return true;
            }
            return false;
    }
    //No face to face
	return false;
}

//Same function but for p43layer 2

bool face_to_face2(player *plr1, player *plr2,int move){

    switch(move){
        //Left face to face
        case 1:
        case 11:
        case 12:
        case 13:
            if(plr2->x-2==plr1->x&&plr2->y==plr1->y){
                return true;
            }
            return false;
        //Top face to face
        case 2:
        case 22:
        case 21:
        case 24:
            if(plr2->y+2==plr1->y&&plr2->x==plr1->x){
                return true;
            }
            return false;
        //Bottom face to face
        case 3:
        case 33:
        case 31:
        case 34:
            if(plr2->y-2==plr1->y&&plr2->x==plr1->x){
                return true;
            }
            return false;
        //Right face to face
        case 4:
        case 44:
        case 42:
        case 43:
            if(plr2->x+2==plr1->x&&plr2->y==plr1->y){
                return true;
            }
            return false;
    }
    //No face to face
	return false;
}
