
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
	 /*
	 pin_Configuration();
	 T0_Init();
	 init_terminal();
	if (LPC_UART0->LSR & UART_LSR_THRE)       // regarde si l'UART est occup�e en transmission
	{n=sprintf(bufferTX,"Hello ca va bien");
	 affiche_msg(n) ; }
	 while ((LPC_UART0->LSR & UART_LSR_THRE) != UART_LSR_THRE) ;      // regarde si l'UART est occup�e en transmission
	{n=sprintf(bufferTX,"Oui et toi ?");
	 affiche_msg(n) ; }
	 */
	lcd_Initializtion();
	lcd_clear(Green);
	
	interface();
	

	
	
	while(1)
	{ toto++; 
		
	}		;
	
}


#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif

