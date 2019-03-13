#include "libreria.h"
#define LENGTH 17

int main(){
	char**campo1;
	inizializza_campo(campo1);
	stampa_campo(campo1);
	mossa_pedina(campo1,1,0);
	//giocatore 1 è sopra, giocatore 0 sotto
	stampa_campo(campo1);
	return 0;
}

	
