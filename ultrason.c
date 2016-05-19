
#include "globaldefine.h"
// #include "globaldec.h"
#include "global.h"


/*  */
void trigger_signal(void) {
	GPIO_SetValue(0, (1<<24));
	while (trigger<3) {}
	GPIO_ClearValue(0, (1<<24));
}

void bouton_appuye(void) {
	trigger=0;
	echo=0;
	trigger_signal();
	GPIO_IntCmd(0,(1<<25),1);
}

void comparaison(void) {
	//code de comparaison avec un autre tableau
	
	//ouverture(); code de roland pour l'ouverture
	
	
	
}



void retour_echo(void) {
	int i;
	int j=echo;
	while (i<250 & tableau[i]==0) {i++;}
	if (i<250) {
		tableau[i]=j;
		trigger_signal();
}
else {comparaison();}
}	