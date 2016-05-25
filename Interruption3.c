
#include "globaldefine.h"
#include "global.h"
//#include "globaldec.h"


/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */


	
	
void EINT3_IRQHandler(void)
{
    
    if((((LPC_GPIOINT->IO0IntStatR)>>25)& 0x1)==1) { //C'est l'�vent qui se d�clenche pour l'echo (car l'echo peut �tre activ� pendant que le bouton est appuy�, pas l'inverse)
			GPIO_ClearInt(0,(1<<25)); //Aquittement
			statEcho = echo;
			modeUS = 4; //On a re�u le signal, on peut passer � la suite
    } else if((((LPC_GPIOINT->IO0IntStatR)>>26)& 0x1)==1) { //event quand on appuie sur le bouton
			GPIO_ClearInt(0,(1<<26)); // aquittement
			initTabUS();
			modeUS = 1; //On commence la s�rie de flags
			
    }
	}