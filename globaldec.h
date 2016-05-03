#include "LPC17xx.h"

// fichier contenant la déclaration des variables globales de l'application
// à inclure seulement dans le main

int toto;

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message à envoyer (max 16)
extern int n;
extern int TIMER0_VAR100US; // Base de temps de 100 us pour timer0, se reset pour des raisons pratique
extern int TIMER0_VAR100USROLAND; // Spécial Roland
extern int TIMER0_TEMPS; // Définit le temps "absolu" depuis le début du timer0 (*100us)
extern int BIP;                // "Booléen" qui indique si le bip est actif
extern int NB_BIP;
extern int MATCH_BIP;
extern int MATCH_VALUE_FQBIP;
extern int echo;
extern int trigger;
