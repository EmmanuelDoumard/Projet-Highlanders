#include "globaldefine.h"
#include "global.h"

	
void EINT3_IRQHandler(void)
{ //a corriger : le bouton poussoir merde, il drain en haut
    if((((LPC_GPIOINT->IO0IntStatF)>>19)& 0x1)==1){
		GPIO_ClearInt(0,(1<<19));	bula=1; 		
			} else if((((LPC_GPIOINT->IO0IntStatR)>>25)& 0x1)==1) { //C'est l'�vent qui se d�clenche pour l'echo montant(car l'echo peut �tre activ� pendant que le bouton est appuy�, pas l'inverse)atR)>>25)& 0x1)==1) { //C'est l'�vent qui se d�clenche pour l'echo
			GPIO_ClearInt(0,(1<<25)); //Aquittement
			echo = 0;
			modeUS = 4; //On a re�u le signal, on peut passer � la suite
			GPIO_IntCmd(0,(1<<25),1); // On attendra la redescente
    } else if((((LPC_GPIOINT->IO0IntStatF)>>26)& 0x1)==1) { //event quand on appuie sur le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			modeUS = 1; //On commence la s�rie de flags
    } else if((((LPC_GPIOINT->IO0IntStatF)>>25)& 0x1)==1) { //retour echo
			GPIO_ClearInt(0,(1<<25)); // Aquittement
			statEcho = echo;
			modeUS = 5;
		} else if((((LPC_GPIOINT->IO0IntStatR)>>26)& 0x1)==1) { //event quand on relache le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			modeUS = 0; //On arr�te
			GPIO_IntCmd(0,(1<<26),1);
    }
	}
