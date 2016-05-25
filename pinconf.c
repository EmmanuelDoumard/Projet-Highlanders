
#include "globaldefine.h"
#include "global.h"


void pin_Configuration(void)
{
  // déclaration des structures de configuration
	PINSEL_CFG_Type maconfig;
	PINSEL_CFG_Type maconfig2;

	// configuration des pinsel
	maconfig.Portnum = PINSEL_PORT_0; //on utilise le port 0
	maconfig.Pinnum =PINSEL_PIN_10;  //sur la broche 10
	maconfig.Funcnum = PINSEL_FUNC_3;  //au mode 3
	maconfig.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);
	
	
	maconfig2.Portnum = PINSEL_PORT_0; //on utilise le port 0
	maconfig2.Pinnum =PINSEL_PIN_5;  //sur la broche 10
	maconfig2.Funcnum = PINSEL_FUNC_3;  //au mode 3
	maconfig2.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig2.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig2);
 // pour montrer que la variable global x peut être utilisée dans ce fichier
}


