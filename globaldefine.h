// fichier contenant l'inclusion des typedef et #define qui servent à toute l'application
// à inclure dans tous les fichiers

#include "lpc17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_i2c.h"

#include "ili_lcd_general.h"
#include "lcd_api.h"
#include "bula.h"
#include "ultrason.h"
#include "infrarouge.h"
#include "touch_panel.h"
#include "timer0.h"

// Déclaration des constantes

#define TIMER0_TIME_STEP			1		// 1 us de Step Timer (25 000/25000)
#define TIMER0_MATCH_VALUE_100us  100 // Match value pour avoir 100 us
#define MATCH_VALUE1 1000 // A utiliser dans l'interruption, correspond a 1
#define DUREE_BIP 1000      // Durée d'un bip (à multiplier par 100us) => 0.1s
#define MATCH_BIP_INIT 10000 // Intervalle de temps initial entre deux bips
