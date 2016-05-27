
#include "globaldefine.h"
// #include "globaldec.h"
#include "global.h"


/*  */
void initTabUS(void) {
	int i;
	for(i=0;i<50;i++) {
		tableau[i] = 0; //C'est ici qu'on met le tableau à 0
	}
}

void debut_signal(void) {
	trigger=0; //On initialise le timer, pour savoir quand le relancer
	GPIO_IntCmd(0,(1<<25),0); //on lance le mode interruption de l'echo
	GPIO_SetValue(0, (1<<24)); //on met la sortie du trigger sur ON
	modeUS = 2; //la tâche a été effectuée, on passe à l'étape 2
}

void fin_signal(void) {
	echo=0; //On réinitialise l'echo. La prochaine qu'on le prendra, ce sera le timer du temps écoulé depuis la fin du trigger
	GPIO_ClearValue(0, (1<<24)); //on éteint le trigger. Le signal est envoyé, rien a faire jusqu'a ce que modeUS passe à 4, signal que le retour de l'echo s'est effectué
	modeUS=3;
}

void comparaison(void) {
	//code de comparaison avec un autre tableau
	modeUS=0; //fin du mode US à venir
	//ouverture(); code de roland pour l'ouverture
	GPIO_IntCmd(0,(1<<26),0);
	initTabUS();
}

void retour_echo(void) {
	int i;
	while (i<50 & tableau[i]==0) {i++;}
	if (i<250) {
		tableau[i]=statEcho;
		modeUS = 6;
}
else {modeUS = 7;}
}	


void gros_pater(void) {
	if(modeUS!=0) { //Je ne sais pas si ça optimise, mais on va pas faire tout les tests si modeUS est simplement égal à 0
			switch(modeUS) { //On rentre dans les différentes étapes de ma boucle
				case 1 : //Premier cas : le bouton a été appuyé, on entame le lancement du signal. Ou alors on relance le signal si trigger est à plus de 60ms et que la condition 3 est faite
					debut_signal();
					break;
				case 2 : // Ici, c'est l'attente que quelques µs le temps que le signal trigger soit envoyé
					if(trigger>1) {
						fin_signal();
					}
					break;
				case 3 : //Fin de l'envoi du signal, on fait keud en attendant le reour de echo
					break;
				case 4 : //On attend la redescente de echo
					break;
				case 5 : //Ici, c'est le remplissage du tableau après que l'echo soit entré
					retour_echo();
					break;
				case 6 : //On est en attente après avoir rempli la tableau, le temps que trigger aie fait 60ms
					break;
				case 7 : //Si on est ici, c'est que le tableau est rempli
					comparaison();
					break;
				default : //Ici, c'est une erreur
					break;
			}
		}
	}