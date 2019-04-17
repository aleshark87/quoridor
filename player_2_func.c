#include "lib.h"
/*functions for player2*/

// Face to face is a function that controls if the player can jump over the opponent if they are near to each other.
bool face_to_face2(player *p1, player *p2,int move){
	switch(move){
        //Left face to face
        case 1:
        case 11:
        case 12:
        case 13:
            if(p2->x-2==p1->x&&p2->y==p1->y){
                return true;
            }
            return false;
        //Top face to face
        case 2:
        case 22:
        case 21:
        case 24:
            if(p2->y+2==p1->y&&p2->x==p1->x){
                return true;
            }
            return false;
        //Bottom face to face
        case 3:
        case 33:
        case 31:
        case 34:
            if(p2->y-2==p1->y&&p2->x==p1->x){
                return true;
            }
            return false;
        //Right face to face
        case 4:
        case 44:
        case 42:
        case 43:
            if(p2->x+2==p1->x&&p2->y==p1->y){
                return true;
            }
            return false;
    }
    //No face to face
	return false;
}
int player2_move(char **m,player *p1, player *p2){

    int move,winner=0;

    // Move before controls
    printf("\nPlayer 2. It's your turn. Enter the move: ");
    scanf("%d",&move);
    fflush();

    // Border boundaries player_two
    while(border_boundaries2(m,p1,p2,move)==false){
        printf("\nInvalid movement, reinsert: ");
        scanf("%d",&move);
        fflush();
    }


    switch(move){
        case 1:
            p2->x=p2->x-2;
            break;
        case 2:
            p2->y=p2->y+2;
            winner=finish_line(p1,p2);
            break;
        case 3:
            p2->y=p2->y-2;
            break;
        case 4:
            p2->x=p2->x+2;
            break;
        case 11:
            p2->x=p2->x-4;
            break;
        case 22:
            p2->y=p2->y+4;
            break;
        case 33:
            p2->y=p2->y-4;
            break;
        case 44:
            p2->x=p2->x+4;
            break;
        case 12:
            p2->x=p2->x-2;
            p2->y=p2->y+2;
            break;
        case 13:
            p2->x=p2->x-2;
            p2->y=p2->y-2;
            break;
        case 21:
            p2->y=p2->y+2;
            p2->x=p2->x-2;
            break;
        case 24:
            p2->y=p2->y+2;
            p1->x=p1->x+2;
            break;
        case 31:
            p2->y=p2->y-2;
            p2->x=p2->x-2;
            break;
        case 34:
            p2->y=p2->y-2;
            p2->x=p2->x+2;
            break;
        case 42:
            p2->x=p2->x+2;
            p2->y=p2->y+2;
            break;
        case 43:
            p2->x=p2->x+2;
            p2->y=p2->y-2;
            break;
    }
    return winner;
}
bool border_boundaries2(char **m,player *p1, player *p2,int move){

    //If the move is equal to: ... check (1) if the face to face is detected and (2) you can move in that way. If not return -1 and then repeat the move
    if(move==11||move==22||move==33||move==44||move==12||move==13||move==21||move==24||move==42||move==43){

        if(face_to_face2(p1,p2,move)==true){ /* here i'll must write control for the barriers check return function */
            switch(move){
                case 11:
                    if(p2->x-4<0){
                        return false;
                    }
                    return true;
                case 22:
                    if(p2->y+4>N-1){
                        return false;
                    }
                    return true;
                case 33:
                    if(p2->y-4<0){
                        return false;
                    }
                    return true;
                case 44:
                    if(p2->x+4>N-1){
                        return false;
                    }
                    return true;
                case 12:
                case 13:
                    if(p2->x!=2){
                        return false;
                    }
                    return true;
                case 21:
                    if((p2->y==N-3&&p2->x==0)||p2->y!=N-3){
                        return false;
                    }
                    return true;
                case 24:
                    if((p2->y==N-3&&p2->x==N-1)||p2->y!=N-3){
                        return false;
                    }
                    return true;
                case 42:
                case 43:
                    if(p2->x!=N-3){
                        return false;
                    }
		    return true;
            }
        }
    // Else, the player entered a normal move
    }else if(move==1||move==2||move==3||move==4){
        if(face_to_face2(p1,p2,move)==false){
            switch(move){
                case 1:
                    if(p2->x-2<0){
                        return false;
                    }
                    return true;
                case 2:
                    return true;
                case 3:
                    if(p2->y-2<0){
                        return false;
                    }
                    return true;
                case 4:
                    if(p2->x+2>N-1){
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

