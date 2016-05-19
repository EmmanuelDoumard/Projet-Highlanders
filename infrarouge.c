#include "globaldefine.h"
#include "global.h"

//===========================================================//
// But: Init Timer0  pour generer 1 signal à 1ms
//===========================================================//
void T3_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure;
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure;
	
	// Timer0  Initialization
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_TICKVAL;	//mets le prescale en micro secondes				
	Timer_Config_Structure.PrescaleValue	= 8;	//mets la valeur a 1000 micro ssecondes						

	TIM_Init(LPC_TIM3, TIM_TIMER_MODE,&Timer_Config_Structure); // selectionne le timer 3 , en mode Timer , et l'initialise avec les valeurs contenues dans Timer_Config_Structure 
	

	// Configuration of Match channels
	Timer_MatchConfig_Structure.MatchChannel = 0;			 //	indique qu'on match sur le channel 0 			
	Timer_MatchConfig_Structure.IntOnMatch   = FALSE;						//indique pas d'interruption				
	Timer_MatchConfig_Structure.ResetOnMatch = TRUE;						//reset a chaque match pour avoir un timer qui ne s'arrete pas
	Timer_MatchConfig_Structure.StopOnMatch  = FALSE;						//le timer continue malgré le match				
	Timer_MatchConfig_Structure.ExtMatchOutputType = TIM_EXTMATCH_TOGGLE; 		//configure en mode toggle
	
	Timer_MatchConfig_Structure.MatchValue = 40;	 // configure la valeur de comparaison à celle nécessaire pour avoir un match toutes les ms
	TIM_ConfigMatch(LPC_TIM3,&Timer_MatchConfig_Structure);				//selectionne le timer 0 , avec les options dans la configuration établie précédemment			
																

	
}

void envoi_message(int *message){
	int indice=0;
	TIMER0_VAR100USROLAND=0;
	/*interruption pour augmenter i*/
		TIM_Cmd(LPC_TIM3,ENABLE);
		while (TIMER0_VAR100USROLAND<=44){
		}
		TIMER0_VAR100USROLAND=0;
		TIM_Cmd(LPC_TIM3,DISABLE);
		while(TIMER0_VAR100USROLAND<=22){
		}
		//on envoie les bits 1 à 1 du message
		while (indice <=4){
			TIMER0_VAR100USROLAND=0;
			if (message[indice]==1){
				TIM_Cmd(LPC_TIM3,ENABLE);
				while(TIMER0_VAR100USROLAND<=2){
				}
				TIMER0_VAR100USROLAND=0;
				TIM_Cmd(LPC_TIM3,DISABLE);
				while(TIMER0_VAR100USROLAND<=4){
				}
			}
			else {
				TIMER0_VAR100USROLAND=0;
				TIM_Cmd(LPC_TIM3,ENABLE);
				while(TIMER0_VAR100USROLAND<=2){
				}
				TIMER0_VAR100USROLAND=0;
				TIM_Cmd(LPC_TIM3,DISABLE);
				while(TIMER0_VAR100USROLAND<=9){
				}
			}
			indice++;
		}
		TIM_Cmd(LPC_TIM3,ENABLE);
		while (TIMER0_VAR100USROLAND<=2){
		}
		TIMER0_VAR100USROLAND=0;
		TIM_Cmd(LPC_TIM3,DISABLE);
		while(TIMER0_VAR100USROLAND<=199){
		}
		TIMER0_VAR100USROLAND=0;
;
}

