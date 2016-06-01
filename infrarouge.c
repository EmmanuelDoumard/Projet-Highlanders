#include "globaldefine.h"
#include "global.h"
#include "infrarouge.h"


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
	
	Timer_MatchConfig_Structure.MatchValue = 41;	 // configure la valeur de comparaison à celle nécessaire pour avoir un match toutes les ms
	TIM_ConfigMatch(LPC_TIM3,&Timer_MatchConfig_Structure);				//selectionne le timer 0 , avec les options dans la configuration établie précédemment			
																

	
}

/*on initialise le timer 2 en mode capture, pour lui faire mesurer toutes les µs et on gère la reception par interruption*/
void T2_Init(void){
	TIM_CAPTURECFG_Type maconfig;
	TIM_TIMERCFG_Type		Timer_Config_Structure;
	
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_USVAL;				
	Timer_Config_Structure.PrescaleValue	= 1;	
	
	TIM_Init(LPC_TIM2, TIM_TIMER_MODE,&Timer_Config_Structure);
	
	maconfig.CaptureChannel=1;
	maconfig.RisingEdge=ENABLE;
	maconfig.FallingEdge=ENABLE;
	maconfig.IntOnCaption=ENABLE;
	NVIC_EnableIRQ(TIMER2_IRQn);
	TIM_ConfigCapture(LPC_TIM2,&maconfig);
}

/*envoi du message stocké dans la variable globale message, on gère tout cela grâce a l'interruption sur le timer 0 toutes les 100µs pour gérer les différentes temps demandés*/
void envoi_message2(void){

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
			etat=0;
			emi=0;
			indice=0;
			TIMER0_VAR100USROLAND=0;
			lancement=0;
		}
	;
}

/*gestion de l'interruption de capture du timer 2 en matchant la valeur actuelle du compteur - celle correspondant au dernier front, en ajoutant une certaine marge car l'émission n'est pas infiniment précise*/
void TIMER2_IRQHandler(void){

	if(indicerec==4){
		etatrec=0;
	}
	switch (etatrec){
		case 0:
			if((LPC_TIM2->CR1-compar) > 8800 & (LPC_TIM2->CR1-compar) < 9200){
				etatrec=1;
			}
			else{
				etatrec=0;
			}
		break;
		case 1:
			if((LPC_TIM2->CR1-compar) > 4300 & (LPC_TIM2->CR1-compar) < 4700){
				etatrec=2;
				indicerec=0;
			}
			else{
				etatrec=0;
			}
		break;
		case 2:
			if((LPC_TIM2->CR1-compar) > 560 & (LPC_TIM2->CR1-compar) < 640){
				etatrec=3;
			}
			else{
				etatrec=0;
			}
		break;
		case 3:
			if((LPC_TIM2->CR1-compar) > 950 & (LPC_TIM2->CR1-compar) < 1050){
				etatrec=2;
				messagerec[indicerec]=1;
				indicerec+=1;
			}
			else{
				if((LPC_TIM2->CR1-compar) > 1900 & (LPC_TIM2->CR1-compar) < 2100){
				etatrec=2;
				messagerec[indicerec]=0;
				indicerec+=1;
				}
				else{
					etatrec=0;
				}
			}
		break;
		}
	compar=LPC_TIM2->CR1;
	LPC_TIM0->IR|=(1<<0);
	TIM_ClearIntPending(LPC_TIM2,TIM_CR1_INT);
}

/*procédure d'envoi de message passé en paramètre, pour cela on recopie le tableau paramètre dans la variable globale message, puis on lance le timer, on reset la variable qui mesure les 100µs et on passe la variable d'emission à 1*/
void envoyermsg(int m[5]){
	message[0]=m[0];
	message[1]=m[1];
	message[2]=m[2];
	message[3]=m[3];
	message[4]=m[4];
	TIM_Cmd(LPC_TIM3,ENABLE);
	TIMER0_VAR100USROLAND=0;
	emi=1;
	etat=0;
}
