
#include "globaldefine.h"
// #include "globaldec.h"
#include "global.h"



void initTabUS(void) {
	int i;
	for(i=0;i<250;i++) {
		tableau[i] = 0; //C'est ici qu'on met le tableau à 0
	}
}


void GROS_PATER_2(void) {
	if(modeUS == 1) {
			if(modeEnregistrement ==1) {
				if(nbr < 248) {
					tableau[nbr] = statEcho;
					modeEnregistrement = 0;
				} else {
					comparaison();
					modeEnregistrement = 0;
					modeUS = 0;
					GPIO_IntCmd(0,(1<<26),1);
				}
			}}
}

void comparaison(void) {
	int i=0;
	if (root==1) {
		while(i<250) {
			validation[i]=tableau[i];
			i++;
		}
		root = 0;
	} else {
		/*if(comparaison_tableau()==1) {
			//ouverture(); code de roland pour l'ouverture
		}*/
	}
}


	int comparaison_tableau(void) {
		int moy=0;
		int moy2=0;
		float ec1=0;
		float ec2=0;
		int i;
		int val=1;
		for(i=0;i<250;i++) {
			moy=moy+tableau[i];
			moy2=moy2+validation[i];
		}
		if((moy<(moy2*0.9)) || (moy>(moy2*1.1))) { //ecart de 10% : moyenne
			val=0;
		}
		for(i=0;i<250;i++) {
			ec1=ec1+((moy-tableau[i])*(moy-tableau[i]));
			ec2=ec2+((moy2-validation[i])*(moy2-validation[i]));
		}
		if((ec1<(ec2*0.9)) || (ec1>(ec2*1.1))) { //ecart de 10% : ecart type
			val=0;
		}
		
		return val;
		
	}
