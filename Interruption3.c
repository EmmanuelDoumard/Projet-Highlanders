#include "globaldefine.h"
#include "global.h"

	
void EINT3_IRQHandler(void)
{ //a corriger : le bouton poussoir merde, il drain en haut
    if((((LPC_GPIOINT->IO0IntStatF)>>19)& 0x1)==1){
		bula=1;    GPIO_ClearInt(0,(1<<19));	
		} else if((((LPC_GPIOINT->IO0IntStatF)>>26)& 0x1)==1) { //event quand on appuie sur le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			modeUS = 1; //On commence la série de flags
    } else if((((LPC_GPIOINT->IO0IntStatR)>>26)& 0x1)==1) { //event quand on relache le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			modeUS = 0; //On arrête
			GPIO_IntCmd(0,(1<<26),1);
    }
	}
