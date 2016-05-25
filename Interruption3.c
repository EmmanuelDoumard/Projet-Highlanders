
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
    
    if(GPIO_GetIntStatus(0,25,1)) { //C'est l'évent qui se déclenche pour l'echo (car l'echo peut être activé pendant que le bouton est appuyé, pas l'inverse)
			GPIO_ClearInt(0,25); //Aquittement
			statEcho = echo;
			modeUS = 3; //On a reçu le signal, on peut passer à la suite
    } else if(GPIO_GetIntStatus(0,26,1)) { //event quand on appuie sur le bouton
			GPIO_ClearInt(0,26); // aquittement
			initTabUS();
			modeUS = 1; //On commence la série de flags
			
    } else if(GPIO_GetIntStatus(0,19,1)) {
			GPIO_ClearInt(0, 1<<19);  
			getpos();
			convert();
			LCD_fill_rect(pos_x-300,pos_y,5,5,Black,Black);
		}
	}