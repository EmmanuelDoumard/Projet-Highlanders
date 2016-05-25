#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"
#include "ili_lcd_general.h"
#include "lcd_api.h"
#ifndef __TOUCH_PANEL_H
#define __TOUCH_PANEL_H
/*
7  6 - 4  3      2     1-0
s  A2-A0 MODE SER/DFR PD1-PD0
*/

#define TOUCH_MSR_Y  0x90   //?X????? addr:1
#define TOUCH_MSR_X  0xD0   //?Y????? addr:3
// ??????: (POWERAVR ?? LPC1768???)
// SPI    <==> SSP1
// TP_CS  <==> P0.6  GPIO
// TP_INT <==> P0.19 ?? (EINT3)

                        /*P0.6 == TOUCH_CS# LOW*/
#define TP_CS_LOW()     GPIO_SetDir (0,(1<<6),1);   \
                        GPIO_ClearValue (0,(1<<6));
#define TP_CS_HIGH()    GPIO_SetDir (0,(1<<6),1);   \
                        GPIO_SetValue (0,(1<<6));

#define TP_DOWN()       (!((GPIO_ReadValue (0)) & (1<<19)))

uint8_t SPI_WriteByte(uint8_t data);
void touch_init(void);
void getpos(void);
void touch_debug(void);


#endif
