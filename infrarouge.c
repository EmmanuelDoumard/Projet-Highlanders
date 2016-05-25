#include "globaldefine.h"
#include "global.h"


//===========================================================//
// But: Init Timer3  pour generer 1 signal à 38kHz
//===========================================================//
void T3_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure;
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure;
	
	// Timer0  Initialization
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_TICKVAL;				
	Timer_Config_Structure.PrescaleValue	= 8;							

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


void T2_Init(void){
	TIM_CAPTURECFG_Type maconfig;
	
	//initialisation du timer en mode capture sur le port 1//
	maconfig.CaptureChannel=1;
	maconfig.RisingEdge=ENABLE;
	maconfig.FallingEdge=ENABLE;
	maconfig.IntOnCaption=ENABLE;
	NVIC_EnableIRQ(TIMER2_IRQn);
	TIM_ConfigCapture(LPC_TIM2,&maconfig);
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

void envoi_message2(void){
	/*interruption pour augmenter i*/
		if (TIMER0_VAR100USROLAND>44 && etat==0){
			TIMER0_VAR100USROLAND=0;
			TIM_Cmd(LPC_TIM3,DISABLE);
			etat=1;
		}
		if(etat==1 && TIMER0_VAR100USROLAND>22 ){
			TIM_Cmd(LPC_TIM3,ENABLE);
			TIMER0_VAR100USROLAND=0;
			if(message[indice]){
				etat=2;
			}
			else{
				etat=3;
			}
		}
		//on envoie les bits 1 à 1 du message
		if (etat==2 && TIMER0_VAR100USROLAND>2){
			TIMER0_VAR100USROLAND=0;
			TIM_Cmd(LPC_TIM3,DISABLE);
			etat=4;
		}
		if (etat==4 && TIMER0_VAR100USROLAND>4){
			TIMER0_VAR100USROLAND=0;
			TIM_Cmd(LPC_TIM3,ENABLE);
			indice++;
			if(indice>4){
				etat=6;
			}
			else{
				if(message[indice]){
					etat=2;
				}
				else{
					etat=3;
				}
			}
		}
		if(etat==3 && TIMER0_VAR100USROLAND>2) {
			TIMER0_VAR100USROLAND=0;
			TIM_Cmd(LPC_TIM3,DISABLE);
			etat=5;
		}
		if(TIMER0_VAR100USROLAND>9 && etat==5){
			TIMER0_VAR100USROLAND=0;
			TIM_Cmd(LPC_TIM3,ENABLE);
			indice++;
			if(indice>4){
				etat=6;
			}
			else{
				if(message[indice]){
					etat=2;
				}
				else{
					etat=3;
				}
			}
		}
		if (TIMER0_VAR100USROLAND>2&& etat==6){
			TIMER0_VAR100USROLAND=0;
			TIM_Cmd(LPC_TIM3,DISABLE);
			etat=7;
		}
		if(TIMER0_VAR100USROLAND>199&& etat==7){
			emi=0;
		}
	;
}


void TIMER2_IRQHandler(void){
	if(indicerec<10)
		{
			recu[indicerec]=LPC_TIM2->CR1;
		}
	TIM_ClearIntPending(LPC_TIM2,1);
	LPC_TIM0->IR|=(1<<0); //Acquittement
}



