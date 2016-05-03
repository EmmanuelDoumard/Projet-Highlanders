#ifndef SYSTEM_TICK_H
#define SYSTEM_TICK_H

#include "LPC17xx.h"

// Structure du System Tick Timer
typedef struct  {
	__IO uint32_t STCTRL;
	__IO uint32_t STRELOAD;
	__IO uint32_t STCURR;
	__IO uint32_t STCALIB;
} LPC_ST_TypeDef;

#define LPC_STT_BASE 	(LPC_CM3_BASE + 0xE010)
#define LPC_STT				((LPC_ST_TypeDef*) LPC_STT_BASE) 

#endif
