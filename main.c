#include "libreria.h"
#define LENGTH 17

int main(){
	char**field;
	char**positions;
	field=(char **)malloc(sizeof(char*)*LENGTH);
	//malloc control
	if(field==NULL)
		return 1;
	for(int i=0;i<17;++i)
	{
		*(field+i)=(char *)malloc(sizeof(char )*LENGTH);
	}
	inizializza_campo(field);
	stampa_campo(field);
	move_pedina(field,1,0);
	//giocatore 1 è sopra, giocatore 0 sotto
	print_field(field);
	return 0;
}

	
