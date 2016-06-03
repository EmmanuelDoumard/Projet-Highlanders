
#include "globaldefine.h"
// #include "globaldec.h"
#include "global.h"



void initTabUS(void) {
	int i;
	for(i=0;i<250;i++) {
		tableau[i] = 0; //C'est ici qu'on met le tableau à 0
		validation[i] = 0;
	}
}


void GROS_PATER_2(void) {
	if(modeUS == 1) {
			if(modeEnregistrement ==1) {
				if(nbr < 248) {
					tableau[nbr] = statEcho;
					modeEnregistrement = 0;
				} else {
					comparaison();
					modeEnregistrement = 0;
					modeUS = 0;
					GPIO_IntCmd(0,(1<<26),1);
				}
			}}
}

void comparaison(void) {
	int i=0;
	if (root==1) {
		while(i<250) {
			validation[i]=tableau[i];
			i++;
		}
		root = 0;
	} else if (etalon == 1) {
		distance_set();
		} else {
		if(comparaison_tableau()>0) {
			modeUS = 0;
			ultravalid=1;
		}
	}
}


	int comparaison_tableau(void) {
		int i;
		int val=25;
		for(i=0;i<249;i++) {
			if(tableau[i]<(validation[i]*0.75) || tableau[i]>(validation[i]*1.5)) {
			val--;
		}
		}
		
		
		return val;
		
	}
	
	void distance_set(void) {
		int i;
		distance = 0;
		for(i=0;i<249;i++) {
			distance=distance+tableau[i];
		}
		distance = distance/38000;
		if(distance<1 && distance >99) {
			distance = 0;
		}
		
	}
