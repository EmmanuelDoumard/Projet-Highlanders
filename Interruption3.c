
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
  
	
	
	/*
    if(GPIO_GetIntStatus(0,25,1)) {
				GPIO_ClearInt(0,25);
        retour_echo();
    } else if(GPIO_GetIntStatus(0,26,1)) {
				GPIO_ClearInt(0,26);
				modeUS=1;
        bouton_appuye();
			
    } else if(GPIO_GetIntStatus(0,19,1)) {*/
			GPIO_ClearInt(0, 1<<19);  
			getpos();
			convert();
			LCD_fill_rect(pos_x-300,pos_y,5,5,Black,Black);
		//}
	}