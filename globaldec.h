#include "LPC17xx.h"

// fichier contenant la d�claration des variables globales de l'application
// � inclure seulement dans le main

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message � envoyer (max 16)

// Variables Manu

	//Timer0
	long TIMER0_VAR100US=0	;			// Base de temps d'1ms pour timer0
	long TIMER0_TEMPS;
	int MATCH_BIP=10000; // Intervalle de temps (en *100us) entre deux bips
	int MATCH_VALUE_FQBIP=5;
	int BIP=0;		// "Bool�en" qui indique si le bip est actif
	int NB_BIP=1; // Incr�menteur du nombre de bips envoy�s

// Variables Beno�t


// Variables Roland

long TIMER0_VAR100USROLAND=0 ; // Sp�cial Roland sur Timer0

// Variables Guillaume

int echo=0;
int trigger=0;
int tableau[250];
int modeUS;