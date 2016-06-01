
#include "globaldefine.h"
#include "global.h"
//#include "globaldec.h"


/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */


	
	
void EINT3_IRQHandler(void)
{ //a corriger : le bouton poussoir merde, il drain en haut
    if((((LPC_GPIOINT->IO0IntStatF)>>19)& 0x1)==1){
		bula=1;    GPIO_ClearInt(0,(1<<19));	
	} else if((((LPC_GPIOINT->IO0IntStatF)>>26)& 0x1)==1) { //event quand on appuie sur le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			modeUS = 1; //On commence la série de flags
		trigger = 0;
		LPC_GPIOINT->IO0IntEnR |= (1<<26);
	} else if((((LPC_GPIOINT->IO0IntStatR)>>26)& 0x1)==1) { //event quand on relache le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			modeUS = 0; //On arrête
			LPC_GPIOINT->IO0IntEnF |= (1<<26);
    }
	}
