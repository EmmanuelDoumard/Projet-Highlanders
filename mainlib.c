
#include "globaldefine.h"
#include "globaldec.h"
#include "infrarouge.h"
/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */



int main(void)
{
	 pin_Configuration();
	T2_Init();
	 T3_Init();
	 T0_Init();
	emi=1;
	TIM_Cmd(LPC_TIM3,ENABLE);
	TIM_Cmd(LPC_TIM2,ENABLE);
	while(1)
	{ 
	}
}

#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif

