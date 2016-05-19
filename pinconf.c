
#include "globaldefine.h"
#include "global.h"

void pin_Configuration(void);

void pin_Configuration(void)
{
  // déclaration des structures de configuration
	PINSEL_CFG_Type maconfig;
	
	// configuration des GPIOs
	// directement dans les registres
	//LPC_GPIO0->FIODIR &= ~(1<<0);
	//LPC_GPIO0 ->FIOMASK = ~(1<<0);
	// en utilisant une fonction 
	GPIO_SetDir(1,0x200,1);
	
	// configuration des pinsel
	maconfig.Portnum = PINSEL_PORT_1;
	maconfig.Pinnum =PINSEL_PIN_9;
	maconfig.Funcnum = PINSEL_FUNC_0;
	maconfig.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);
	
	
	
	// ATTENTION PARTIE ROLANDO A FUSIONNER (problèmes de maconfig)
	// déclaration des structures de configuration
	PINSEL_CFG_Type maconfigRolando;
	
	// configuration des GPIOs

	// en utilisant une fonction 
	// GPIO_SetDir(0,(1<<10),0);
	// LPC_GPIO0 ->FIOMASK =~(1<<10);
	
	// configuration des pinsel
	maconfigRolando.Portnum = PINSEL_PORT_0; //on utilise le port 0
	maconfigRolando.Pinnum =PINSEL_PIN_10;  //sur la broche 10
	maconfigRolando.Funcnum = PINSEL_FUNC_3;  //au mode 3
	maconfigRolando.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfigRolando.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfigRolando);
	
}