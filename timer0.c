#include "globaldefine.h"
#include "global.h"

//===========================================================//
// But: Init Timer0  pour generer 1 signal à 1ms
//===========================================================//
void T0_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure; // structures pour passer les valeurs d'initialisation d'un timer
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure;
	
	// Timer0  Initialization
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_USVAL;						// Timer en Mode us
	Timer_Config_Structure.PrescaleValue	= TIMER_TIME_STEP;							// TC incrementé de 1 chaque 10us

	TIM_Init(LPC_TIM0, TIM_TIMER_MODE,&Timer_Config_Structure);
	

	// Configuration of Match channels
	Timer_MatchConfig_Structure.MatchChannel = 0;													// Use channel 0, MR0 for both Timers
	Timer_MatchConfig_Structure.IntOnMatch   = FALSE;											// En Timer IT			 qd MR0 = TC Register
	Timer_MatchConfig_Structure.ResetOnMatch = TRUE;											// En Timer RST			 qd MR0 = TC Register
	Timer_MatchConfig_Structure.StopOnMatch  = FALSE;											// No Stop Timer     qd MR0 = TC Register
	Timer_MatchConfig_Structure.ExtMatchOutputType = TIM_EXTMATCH_TOGGLE;	// Toggle MATx.y pin qd MR0 = TC Register
	
	Timer_MatchConfig_Structure.MatchValue = TIMER_MATCH_VALUE_1ms;		// Match Value Timer0
	TIM_ConfigMatch(LPC_TIM0,&Timer_MatchConfig_Structure);								// Config Timer0
	
	
	TIM_Cmd(LPC_TIM0,ENABLE);																							// Start Timer0

	
}