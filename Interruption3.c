
#include "globaldefine.h"
#include "global.h"



/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */


void EINT3_IRQHandler(void)
{
 			 
			pos_x=0;
			pos_y=0;
			getpos();
			convert();
			input();
			if(pos_x && pos_y){
				LCD_fill_rect(65,67,261,264,Black,Black);
			GPIO_ClearInt(0, 1<<19); 
			}
}
