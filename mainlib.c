
#include "globaldefine.h"
#include "globaldec.h"

 void T0_Init(void);
 void T3_Init(void);
 void T1_Init(void);
 void pin_Configuration(void);
 void envoi_message(int*);
 void touch_init(void);

/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */



int main(void)
{
	// Initialisation Manu
	
	pin_Configuration();
	T0_Init();

	// Initialisation Rolando

	T2_Init();
	T3_Init();
	TIM_Cmd(LPC_TIM2,ENABLE);

	// Initialisation Pinpin

	lcd_Initializtion();	
	interface();
	touch_init();

	// Initialisation Guillaume
	
	pin_Configuration();
	initTabUS();
	T1_Init();
	modeUS=0;
	
	
	while(1)
	{
		GROS_PATER_2();
		
		if(valida==1){
			valida=0;
			validada();		
		}
		if(ultravalid==1){
			ultravalid=0;
			sprintf(code,"%d",1362);
			validada();
		}
		if(bula==1 && modeUS==0){
			bula=0;
			if(etatzer==1){
				interface();
			};		
			if(etatzer<0){				
				pos_x=0;
				pos_y=0;
				getpos();
				convert();
				input();
			} else{
				etatzer--;
			};
		}	
				
		if(old>-1){
			raz(old);
			old=-1;
			}
				
	}
}


#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif

