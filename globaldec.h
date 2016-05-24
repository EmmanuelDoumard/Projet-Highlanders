#include "LPC17xx.h"

// fichier contenant la déclaration des variables globales de l'application
// à inclure seulement dans le main

int toto;

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message à envoyer (max 16)
long TIMER0_VAR100US=0	;			// Base de temps d'1ms pour timer0
long TIMER0_VAR100USROLAND=0 ; // Spécial Roland
long TIMER0_TEMPS;
int BIP=0;		// "Booléen" qui indique si le bip est actif
int NB_BIP=1; // Incrémenteur du nombre de bips envoyés
int MATCH_BIP=10000; // Intervalle de temps (en *100us) entre deux bips
int MATCH_VALUE_FQBIP=5;
int echo=0;
int trigger=0;


int pos_x;
int pos_y;

