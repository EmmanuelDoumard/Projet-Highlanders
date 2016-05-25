
#include "globaldefine.h"
#include "globaldec.h"

 void T0_Init(void);
 void T3_Init(void);
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

	//T2_Init();
	T3_Init();
	emi=1;
	TIM_Cmd(LPC_TIM3,ENABLE);
	//TIM_Cmd(LPC_TIM2,ENABLE);

	// Initialisation Pinpin

	lcd_Initializtion();	
	interface();
	touch_init();

	// Initialisation Guillaume
	
	initTabUS();
	modeUS=0;
	
	
	while(1)
	{
		gros_pater();
	}
	
}


#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif

