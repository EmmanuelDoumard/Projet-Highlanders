#include "globaldefine.h"
#include "global.h"

//===========================================================//
// But: Init Timer0  pour generer 1 signal à 500Hz (2ms) en interruption
//===========================================================//

// Déclarations variables externes

void T0_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure; // structures pour passer les valeurs d'initialisation d'un timer
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure;
	
	// Timer0  Initialization
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_USVAL;						// Timer en Mode us
	Timer_Config_Structure.PrescaleValue	= TIMER0_TIME_STEP;							// TC incrementé de 1 chaque 10us

	TIM_Init(LPC_TIM0, TIM_TIMER_MODE,&Timer_Config_Structure);
	

	// Configuration of Match channels
	Timer_MatchConfig_Structure.MatchChannel = 0;													// Use channel 0, MR0 for both Timers
	Timer_MatchConfig_Structure.IntOnMatch   = TRUE;											// En Timer IT			 qd MR0 = TC Register
	Timer_MatchConfig_Structure.ResetOnMatch = TRUE;											// En Timer RST			 qd MR0 = TC Register
	Timer_MatchConfig_Structure.StopOnMatch  = FALSE;											// No Stop Timer     qd MR0 = TC Register
	Timer_MatchConfig_Structure.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;	// Toggle MATx.y pin qd MR0 = TC Register
	
	Timer_MatchConfig_Structure.MatchValue = TIMER0_MATCH_VALUE_100us;		// Match Value Timer0
	TIM_ConfigMatch(LPC_TIM0,&Timer_MatchConfig_Structure);								// Config Timer0
	
	
	TIM_Cmd(LPC_TIM0,ENABLE);																							// Start Timer0
	NVIC_EnableIRQ(TIMER0_IRQn);																					// Autoriser interruption
}

/* Code de l'interruption. Est déclenchée si TC = MR, c'est-à-dire toutes les 1MS pour timer 0 */
void TIMER0_IRQHandler(void){
	TIMER0_TEMPS++;
	TIMER0_VAR100US++;
	TIMER0_VAR100USROLAND++;
	trigger++; // cf ultrason
	if (trigger>600 & modeUS==1) {
		bouton_appuye();
	}
	
	if (TIMER0_TEMPS % 10 == 0){
		echo++; // cf ultrason
	}
	
	// Gestion du bip
	if (TIMER0_TEMPS<150000){
		if (TIMER0_VAR100US % MATCH_BIP==0){
			BIP=1; //On active le bip
		}
		if ( BIP && (TIMER0_VAR100US % (MATCH_BIP+DUREE_BIP) == 0)){
			BIP=0; // Après 100*100us (0.1s), on désactive le bip
			TIMER0_VAR100US=1; // On réinitialise l'incrémenteur
			NB_BIP++;
		}
		if ((NB_BIP % 7)==0){  // Tous les 8 bip
			NB_BIP=1;
			MATCH_BIP=MATCH_BIP/2; // On double la vitesse des bips
			TIMER0_VAR100US=1;
		}
		

		
		if ((TIMER0_VAR100US % MATCH_VALUE_FQBIP==0) && BIP ){
			if ((LPC_GPIO1->FIOPIN & 0x200)==0x200){
				LPC_GPIO1->FIOPIN &= ~(1<<9); // Inversion du premier bit pour générer un signal carré de fqce MATCH_VALUE_FQBIP
			}
			else
			{
				LPC_GPIO1->FIOPIN |= (1<<9);
			}
		}
	}
TIM_ClearIntPending(LPC_TIM0,0);
LPC_TIM0->IR|=(1<<0); //Acquittement
}
