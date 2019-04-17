#include "lib.h"

/*General functions*/

// This function is similar to getchar() but it execute a desired block of instructions for each characther typed in input.
void print_debug_matrix(char **m){
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<N;k++)
		{
			printf("%c",m[i][k]);
		}
		printf("\n");
	}
	printf("exit debug matrix..press a button\n");
	getchar();
}
int getch_() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");

        //Return the movement

        switch(buf){
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '\n':
                return -1;
        }
        return 0;
}

int matrix_initialization(char **m){
    int i,k;
    for(i=0;i<N;i++){
        //If the row is even then all the odd columns are for barrier placing
        if((i+1)%2==1){
            for(k=1;k<N;k+=2){
                m[i][k]='2';
            }
            //Instead, the even's are for players positioning
            for(k=0;k<N;k+=2){
                m[i][k]='0';
            }
        }else{
        //If the row is odd, all the columns are for barrier placing
            for(k=0;k<N;k++){
                m[i][k]='2';
            }
        }
    }
    return 0;
}
void print_matrix(char **m,player *p1,player *p2, barrier *b1, barrier *b2){
    int i,k,j;

    for(i=0;i<N;i++){
        for(k=0;k<N;k++){

            if(p1->x==k&&p1->y==i){
                printf("1 ");
                continue;

            }
            if(p2->x==k&&p2->y==i){
                printf("2 ");
                continue;
            }
            //Work in progress
            for(j=0;j<=b1->last;j++)
            {
                if((b1->direction[j])=='h')
                {
					if(i==b1->y1[j]&&k==b1->x1[j]||i==b1->y2[j]&&k==b1->x2[j])
					{
						printf("- ");
					}
				}
            }
            for(j=0;j<=b2->last;j++){
                if(i==b2->y1[j]&&k==b2->x1[j]||i==b2->y2[j]&&k==b2->x2[j]){
                    printf("/");
                }
            }
            if(m[i][k]=='2'){
                printf("  ");

            }else if(m[i][k]=='0'){
                printf(". ");
            }


                //printf("%c ",m[i][k]);
        }
        printf("\n");
    }
}

void start(char **m,player *p1,player *p2){
    int half=N/2;
    //player1 starting from the bottom
    p1->x=half;
    p1->y=N-1;
    //player2 starting from the top
    p2->x=half;
    p2->y=0;

}
int finish_line(player *p1,player *p2){
    //if a player reaches the opposite side the game is over
    if(p1->y==0){
        return 1;
    }
    if(p2->y==N-1){
        return 2;
    }
    return 0;
}




