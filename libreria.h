#include <stdio.h>
//posizioni dei giocatori
int row1;
int column1;
int row2;
int column2;
int inizializza_campo(char **campo){
	int i,k;
	for(i=0;i<17;i++){
                if((i+1)%2==1){
                        for(k=1;k<17;k=k+2){
                                campo[i][k]=2;
                        }
                        for(k=0;k<17;k+=2){
                                campo[i][k]=0;
                        }
                }else{
                        for(k=0;k<17;k++){
                                campo[i][k]=2;
                        }
                }
        }
	campo[0][8]=1;
	campo[16][8]=1;
	row1=0;
	column1=8;
	row2=16;
	column2=8;
	return 1;
}
int stampa_campo(char **campo){
	int i,k;
	//scorri righe
	for(i=0;i<17;i++){
		//scorri colonne
		for(k=0;k<17;k++){
			printf("%d ",campo[i][k]);
        }
		printf("\n");
	}
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	return 0;
}
int stampa_campo2(int **campo){
	int i,k;
	i=k=0;
	printf(" _     _     _\n");
	printf("|_| | |_| | |_|\n");
	printf("--- | --- | ---\n");
	printf(" _     _     _\n");
	printf("|_| | |_| | |_|\n");
	printf("--- | --- | ---\n");
	printf(" _     _     _\n");
	printf("|_| | |_| | |_|\n");
	return 1;
}
int mossa_pedina(char **campo,int player,int direzione){
	//direzione 0 destra
	//direzione 1 sopra
	//direzione 2 sinisra
	//direzione 3 sotto
	int row;
	int column;
	//acquisisco la posizione del giocatore giusto
	if(player){
		row=row1;
		column=column1;
	}
	else{
		row=row2;
		column=column2;
	}
	if(direzione==0){
		//controlla se la barriera è "libera"
		if(campo[row][column+1]==2){
			//c'è da prevedere il salto
			if(campo[row][column+2]==1){
				return 2;//mossa bloccata da giocatore 2
			}
			//la posizione precedentemente occupata, torna a 0
			campo[row][column]=0;
			column=column+2;
			campo[row][column]=1;
		}
	}
	//in fondo, restituisco la posizione alle variabili globali
	
	if(player){
		row1=row;
		column1=column;
	}
	else{
		row2=row;
		column2=column;
	}		
	return 0;
}

