#include "LPC17xx.h"
#include "globaldefine.h"

// fichier contenant la déclaration des variables globales de l'application
// à inclure seulement dans le main

int toto;

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message à envoyer (max 16)
long TIMER0_VAR100US=0	;			// Base de temps d'1ms pour timer0
long TIMER0_VAR100USROLAND=0 ; // Spécial Roland
int BIP=0;		// "Booléen" qui indique si le bip est actif
int NB_BIP=0; // Incrémenteur du nombre de bips envoyés
int MATCH_BIP=100000; // Intervalle de temps (en *100us) entre deux bips
int MATCH_VALUE_FQBIP=20;
int echo=0;
int trigger=0;
int message[5]={1,1,1,1,0};
int indice=0;
int emi=0;
int etat=0;
int messagerec[10]={0,0,0,0,0,0,0,0,0,0};
int indicerec=0;
int etatrec=0;
unsigned long compar=0;