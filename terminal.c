#include "LPC17xx.h"
#include "terminal.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_pinsel.h"

#include <stdarg.h>
#include <stdio.h>
#include "global.h"


void init_terminal(void) {
		UART_CFG_Type uart_cfg; // déclaration d'une structure de configuration pour l uart
	  UART_FIFO_CFG_Type uart_fifo_cfg; // déclaration d'une structure de configuration pour la fifo de l uart
		PINSEL_CFG_Type	pconf;  // déclaration d'une structure de configuration pour le pinsel
	
		// P0.3/.2 as UART0 RX/TX
		pconf.Funcnum = 1;
		pconf.OpenDrain	= PINSEL_PINMODE_NORMAL;
		pconf.Pinmode = PINSEL_PINMODE_TRISTATE;
		pconf.Portnum	= 0;
		pconf.Pinnum = 2;
		PINSEL_ConfigPin(&pconf);
	
		pconf.Pinnum = 3;
		PINSEL_ConfigPin(&pconf);

		// Set-up UART0
		uart_cfg.Baud_rate = 9600; 
		uart_cfg.Parity = UART_PARITY_NONE;
		uart_cfg.Databits = UART_DATABIT_8;
		uart_cfg.Stopbits = UART_STOPBIT_1;
		
		UART_Init((LPC_UART_TypeDef*)LPC_UART0, &uart_cfg); // configuration vitesse, parité,taille, stop bits
		
		uart_fifo_cfg.FIFO_Level =UART_FIFO_TRGLEV2;
		uart_fifo_cfg.FIFO_DMAMode = DISABLE ;
		uart_fifo_cfg.FIFO_ResetRxBuf = ENABLE ;
		uart_fifo_cfg.FIFO_ResetTxBuf = ENABLE ;
		UART_FIFOConfig (LPC_UART0,&uart_fifo_cfg); // configuration de l'utilisation des FIFOS 16 byte en TX et RX
		
		
		
		
		// 
}

// procédure non bloquante d'affichage d'un message de taille max 16 octets
// à n'appeler que si l'UART est libre en transmission

void affiche_msg(int n)
{
                   
	 
	 {UART_Send(LPC_UART0,bufferTX,n,NONE_BLOCKING);   // envoi de la chaine à l'UART avec tampon dans la fifo 
   UART_TxCmd((LPC_UART_TypeDef*)LPC_UART0, ENABLE);}	// autorisation de la transmission

 }
 
int tprintf (const  char *fmt, ...)
{
    static  char  buffer[512 + 1];
    va_list vArgs;
		int len;
	
    va_start(vArgs, fmt);
    len = vsprintf((char *)buffer, (char const *)fmt, vArgs);
    va_end(vArgs);

    terminal_puts(buffer);
		return len;
}

void terminal_puts(const char* str) {
		uint8_t *s = (uint8_t *) str;

		while (*s)
		{
			UART_Send((LPC_UART_TypeDef*)LPC_UART0, s++, 1, BLOCKING);
		}
}
