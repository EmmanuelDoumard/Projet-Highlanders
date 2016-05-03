// fichier contenant l'inclusion des typedef et #define qui servent à toute l'application
// à inclure dans tous les fichiers

#include "lpc17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_uart.h"
#include "ili_lcd_general.h"
#include "lcd_api.h"
#include "bula.h"



#define TIMER_TIME_STEP			1000			// 1000 us de Step Timer
#define TIMER_MATCH_VALUE_1ms  499 // valeur pour avoir 1 ms 


