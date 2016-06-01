#include "lpc17xx.h"

#include "lpc17xx_gpio.h"

void GPIO_Configuration(void);

void GPIO_Configuration(void)
{
  GPIO_SetDir(0,0,0) ; /* port 0.0 en entrée
	
  // LPC_GPIO0->FIODIR |=(1<<2)|(1<<3); /* LEDs sur PORT0[23] definies en Output    */
	LPC_GPIO0 ->FIOMASK = ~((1<<2)|(1<<3)); /* masque pour n'accéder que à ces 2 bits lors des écritures ou lectures du port*/
	LPC_GPIO2->FIODIR  &= ~( (1<<10) | (1<<11) ); /* BP sur PORT2[11 10] definies en input    */
	LPC_GPIO2 ->FIOMASK = ~((1<<10)|(1<<11)); /* masque pour n'accéder que à ces 2 bits lors des écritures ou lectures du port*/
	

}