
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
    
    if(((LPC_GPIO0->FIOPIN>>25)&(1<<0))==1) {
				GPIO_ClearInt(0,25);
        retour_echo();
    } else if(((LPC_GPIO0->FIOPIN>>26)&(1<<0))==1) {
				GPIO_ClearInt(0,26);
				modeUS=1;
        bouton_appuye();
			
    }
	}