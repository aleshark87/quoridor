#include "lib.h"
/*functions for player 1*/

bool border_boundaries1(char **m, player *p1, player *p2, int move){

    //If the move is equal to: ... check (1) if the face to face is detected and (2) you can move in that way. If not return -1 and then repeat the move
    if(move==11||move==22||move==33||move==44||move==12||move==13||move==21||move==24||move==42||move==43){

        if(face_to_face1(p1,p2,move)==true){ /* here i'll must write control for the barriers check return function */
            switch(move){
                case 11:
                    if(p1->x-4<0){
                        return false;
                    }
                    return true;
                case 22:
                    if(p1->y-4<0){
                        return false;
                    }
                    return true;
                case 33:
                    if(p1->y+4>N-1){
                        return false;
                    }
                    return true;
                case 44:
                    if(p1->x+4>N-1){
                        return false;
                    }
                    return true;
                case 12:
                case 13:
                    if(p1->x!=2){
                        return false;
                    }
                    return true;
                case 21:
                    if((p1->y==2&&p1->x==0)||p1->y!=2){
                        return false;
                    }
                    return true;
                case 24:
                    if((p1->y==2&&p1->x==N-1)||p1->y!=2){
                        return false;
                    }
                    return true;
                case 42:
                case 43:
                    if(p1->x!=N-1-2){
                        return false;
                    }
                    return true;
            }
        }
    }else if(move==1||move==2||move==3||move==4){
        if(face_to_face1(p1,p2,move)==false){
            switch(move){
                case 1:
                    if(p1->x-2<0){
                        return false;
                    }
                    return true;
                case 2:
                    return true;
                case 3:
                    if(p1->y+2>N-1){
                        return false;
                    }
                    return true;
                case 4:
                    if(p1->x+2>N-1){
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
int wall_placing1(char **m,player *p1,player *p2,barrier *b1, barrier *b2){
	int dir;
	bool cl=false,flag=true;
    b1->last++;
    //Direction
	printf("\nType 'v' for vertical or 'h' for horizontal barrier\n");
	scanf("%c",&(b1->direction[b1->last]));
	fflush();
	while((b1->direction[b1->last])!='v'&&(b1->direction[b1->last])!='h'){
        printf("\nInvalid barrier direction, please reinsert: ");
      	scanf("%c",&(b1->direction[b1->last]));
        fflush();
	}

    //Starting position
    if((b1->direction[b1->last])=='v'){
        b1->x1[b1->last]=0;
        b1->y1[b1->last]=1;
        b1->x2[b1->last]=1;
        b1->y2[b1->last]=1;
        b1->x3[b1->last]=2;
        b1->y3[b1->last]=1;
        b1->x4[b1->last]=3;
        b1->y4[b1->last]=1;
    }else{
        b1->x1[b1->last]=1;
        b1->y1[b1->last]=0;
        b1->x2[b1->last]=1;
        b1->y2[b1->last]=1;
        b1->x3[b1->last]=1;
        b1->y3[b1->last]=2;
        b1->x4[b1->last]=1;
        b1->y4[b1->last]=3;
    }

    printf("\nPrint arrows to move the barrier and once you've chosed the position, enter backspace\n");
    print_matrix(m,p1,p2,b1,b2);

    while(cl==false){
        dir=0;
        //While the player does not enter backspace
        while(dir!=-1){
            //Take the barrier movement
            dir=getch_();

            if(dir!=-1&&dir!=0){
                //Barrier border boundaries
                if(dir=barrier1_border_boundaries(m,b1,dir,b1->direction[b1->last])!=0){
                    flag=true;
                } else{
                    flag=false;
                }
                //printf("b1 x1: %d y1: %d x2: %d y2: %d\n",b1->x1[b1->last],b1->y1[b1->last],b1->x2[b1->last],b1->y2[b1->last]);
            }
            if (dir==0){
                printf("\nInvalid direction, please reinsert:\n");
            }
            clear();
            print_matrix(m,p1,p2,b1,b2);
            //If p1 press enter the while will exit because getch() will return -1
        }

        //If flag==false the preovius move before \n was invalid then redo the move. Else, contol if the cells of the new barrier, collide with another that already exist.
        if(flag==true){
            cl=clash1(b1,b2);
            //If clash1 returns true the cell can be inserted
        }
        clear();
        print_matrix(m,p1,p2,b1,b2);
    }
    m[b1->y1[b1->last]][b1->x1[b1->last]]='3';
    m[b1->y2[b1->last]][b1->x2[b1->last]]='3';
	m[b1->y3[b1->last]][b1->x3[b1->last]]='3';
	m[b1->y4[b1->last]][b1->x4[b1->last]]='3';
}
bool clash1(barrier *b1, barrier *b2){
    if(b1->last!=-1&&b2->last!=-1){
        for (int i=0;i<10;i++){
            //Compare x1
            if(b1->x1[b1->last]==b2->x1[i]||b1->x1[b1->last]==b2->x2[i]||b1->x1[b1->last]==b2->y1[i]||b1->x1[b1->last]==b2->y2[i]){
                return false;
            }
            //Compare x2
            if(b1->x2[b1->last]==b2->x1[i]||b1->x2[b1->last]==b2->x2[i]||b1->x2[b1->last]==b2->y1[i]||b1->x2[b1->last]==b2->y2[i]){
                return false;
            }
            //Compare y1
            if(b1->y1[b1->last]==b2->x1[i]||b1->y1[b1->last]==b2->x2[i]||b1->y1[b1->last]==b2->y1[i]||b1->y1[b1->last]==b2->y2[i]){
                return false;
            }
            //Compare y2
            if(b1->y2[b1->last]==b2->x1[i]||b1->y2[b1->last]==b2->x2[i]||b1->y2[b1->last]==b2->y1[i]||b1->y2[b1->last]==b2->y2[i]){
                return false;
            }
        }
    }
    return true;
}
int player1_move(char **m,player *p1, player *p2,barrier *b1, barrier *b2){

    int move,winner=0;

    //Move before controls
    printf("\nPlayer 1. It's your turn. Enter the move: ");
    scanf("%d",&move);
    fflush();
	//border boundaries player_one
    while(border_boundaries1(m,p1,p2,move)==false){
        //Wall placing 5
		if(move==5)
		{
			wall_placing1(m,p1,p2,b1,b2);
			print_debug_matrix(m);
			return winner;
			//Wall placing 5
		}
        printf("\nInvalid movement, reinsert: ");
        scanf("%d",&move);
        fflush();
    }


    switch(move){
        case 1:
            p1->x=(p1->x)-2;
            break;
        case 2:
            p1->y=(p1->y)-2;
            winner=finish_line(p1,p2);
            break;
        case 3:
            p1->y=(p1->y)+2;
            break;
        case 4:
            p1->x=(p1->x)+2;
            break;
        case 11:
            p1->x=p1->x-4;
            break;
        case 22:
            p1->y=p1->y-4;
            break;
        case 33:
            p1->y=p1->y+4;
            break;
        case 44:
            p1->x=p1->x+4;
            break;
        case 12:
            p1->x=p1->x-2;
            p1->y=p1->y-2;
            break;
        case 13:
            p1->x=p1->x-2;
            p1->y=p1->y+2;
            break;
        case 21:
            p1->y=p1->y-2;
            p1->x=p1->x-2;
            break;
        case 24:
            p1->y=p1->y-2;
            p1->x=p1->x+2;
            break;
        case 31:
            p1->y=p1->y+2;
            p1->x=p1->x-2;
            break;
        case 34:
            p1->y=p1->y+2;
            p1->x=p1->x+2;
            break;
        case 42:
            p1->x=p1->x+2;
            p1->y=p1->y-2;
            break;
        case 43:
            p1->x=p1->x+2;
            p1->y=p1->y+2;
            break;
    }
    return winner;
}
// Face to face is a function that controls if the player can jump over the opponent if they are near to each other.
bool face_to_face1(player *p1, player *p2, int move){

    switch(move){
        //Left face to face
        case 1:
        case 11:
        case 12:
        case 13:
            if(p1->x-2==p2->x&&p1->y==p2->y){
                return true;
            }
            return false;
        //Top face to face
        case 2:
        case 22:
        case 21:
        case 24:
            if(p1->y-2==p2->y&&p1->x==p2->x){
                return true;
            }
            return false;
        //Bottom face to face
        case 3:
        case 33:
        case 31:
        case 34:
            if(p1->y+2==p2->y&&p1->x==p2->x){
                return true;
            }
            return false;
        //Right face to face
        case 4:
        case 44:
        case 42:
        case 43:
            if(p1->x+2==p2->x&&p1->y==p2->y){
                return true;
            }
            return false;
    }
    //No face to face
	return false;
}
int barrier1_border_boundaries(char **m, barrier *b1, int move, char mode){

    if(mode=='v'){
        switch(move){
            //left
            case 1:
                //It is enough to control if the x coordinate of the first barrier cell is <0 if we substract -2
                if(b1->x1[b1->last]-2<0){
                    return 0;
                }
                //Else, decrease the coordinates because the barrier is moving left
                b1->x1[b1->last]-=2;
                b1->x2[b1->last]-=2;
                //Left movement completed with success
                return 1;
            case 2:
                //If the barrier movement is upward, the y will decrement by 1
                if(b1->y1[b1->last]-1<0){
                    return 0;
                }
                //Else
                b1->y1[b1->last]-=1;
                b1->y2[b1->last]-=1;
                b1->y3[b1->last]-=1;
                b1->y4[b1->last]-=1;
                //Top movement completed with success
                return 2;
            case 3:
                //If the barrier movement is downward, the y will increment by 1
                if(b1->y2[b1->last]+1>N-1){
                    return 0;
                }
                //Else
                b1->y1[b1->last]+=1;
                b1->y2[b1->last]+=1;
                b1->y3[b1->last]+=1;
                b1->y4[b1->last]+=1;
                //Bottom movement completed with success
                return 3;
            //right
            case 4:
                //It is enought to control if the x cooridinate of the first barrier cell is <0 if we substract -2
                if(b1->x2[b1->last]+2>N-1){
                    return 0;
                }
                //Else, increase the cooridinates because the barrier is moving right
                b1->x1[b1->last]+=2;
                b1->x2[b1->last]+=2;
                b1->x3[b1->last]+=2;
                b1->x4[b1->last]+=2;
                //Left movement completed with success
                return 4;
        }

    }else{
        //It is an horizontal barrier
        switch(move){
            case 1:
                if(b1->x1[b1->last]-1<0){
                    return 0;
                }
                b1->x1[b1->last]-=1;
                b1->x2[b1->last]-=1;
                b1->x3[b1->last]-=1;
                b1->x4[b1->last]-=1;
                return 1;
            case 2:
                //If the barrier overcome the boundaries on the top, both y1 and y2 go under 0, then is enought to control 1 of the two
                if(b1->y1[b1->last]-2<0){
                    return 0;
                }
                b1->y1[b1->last]-=2;
                b1->y2[b1->last]-=2;
                b1->y3[b1->last]-=2;
                b1->y4[b1->last]-=2;
                return 2;
            case 3:
                if(b1->y1[b1->last]+2>N-1){
                    return 0;
                }
                b1->y1[b1->last]+=2;
                b1->y2[b1->last]+=2;
                b1->y3[b1->last]+=2;
                b1->y4[b1->last]+=2;
                return 3;
            case 4:
                if(b1->x2[b1->last]+1>N-1){
                    return 0;
                }
                b1->x1[b1->last]+=1;
                b1->x2[b1->last]+=1;
                b1->x3[b1->last]+=1;
                b1->x4[b1->last]+=1;
                return 4;
        }
    }
    return 0;
}
