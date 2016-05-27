
#include "globaldefine.h"
// #include "globaldec.h"
#include "global.h"


/*  */
void trigger_signal(void) {
	GPIO_SetValue(0, (1<<24)); //Envoi d'un signal trigger
	while (echo<3) {}
	GPIO_ClearValue(0, (1<<24));
}

void bouton_appuye(void) {
	trigger=0;
	echo=0;
	GPIO_IntCmd(0,(1<<25),1);
	trigger_signal();
}

void comparaison(void) {
	//code de comparaison avec un autre tableau
	modeUS=0; //fin du mode US à venir
	//ouverture(); code de roland pour l'ouverture
	
	
	GPIO_ClearValue(0, (1<<24));
	GPIO_IntCmd(0,(1<<26),0);
}



void retour_echo(void) {
	int i;
	int j=echo;
	while (i<250 & tableau[i]==0) {i++;}
	if (i<250) {
		tableau[i]=j;
}
else {comparaison();}
}	
