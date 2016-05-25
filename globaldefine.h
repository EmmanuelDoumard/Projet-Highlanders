// fichier contenant l'inclusion des typedef et #define qui servent à toute l'application
// à inclure dans tous les fichiers

#include "lpc17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_uart.h"



// Déclaration des constantes

#define TIMER0_TIME_STEP			100		// 100 us de Step Timer (25 000/250)
#define TIMER0_MATCH_VALUE_100us  1 // Match value pour avoir 100 us
#define MATCH_VALUE1 1000 // A utiliser dans l'interruption, correspond a 1



