
#include "global.h"
#include "globaldefine.h"

// Initialisation de la mémoire i2c


void I2C0_Init(void){
	
	LPC_I2C_TypeDef I2C_Config_Struct;
	
	I2C_Init(LPC_I2C0,I2C0clockrate);
	I2C_IntCmd(LPC_I2C0,ENABLE);
	
	
	I2C_Start (LPC_I2C0);
	
	// Transmettre les infos
	
	I2C_Stop (LPC_I2C0);
	LPC_DeInit(LPC_I2C0);
}
