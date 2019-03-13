#include "libreria.h"
#define LENGTH 17

int main(){
	char**campo1;
	campo1=(char **)malloc(sizeof(char*)*LENGTH);
	if(campo1==NULL)
		return 1;
	//frega un cazzo dei controlli
	for(int i=0;i<17;++i)
	{
		*(campo1+i)=(char *)malloc(sizeof(char )*LENGTH);
	}
	inizializza_campo(campo1);
	stampa_campo(campo1);
	mossa_pedina(campo1,1,0);
	stampa_campo(campo1);
	return 0;
}

	
