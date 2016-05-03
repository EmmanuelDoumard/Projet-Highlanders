
#include "globaldefine.h"
#include "globaldec.h"

#include "ili_lcd_general.h"
#include "terminal.h"

 void T0_Init(void);
 void pin_Configuration(void);

/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */



int main(void)
{
	 
	pin_Configuration();
	T0_Init();
	 
	lcd_Initializtion();	
	interface();
	while(1)
	{	
	}		;
	
}


#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif

