// fichier contenant l'importation des variables globales de l'application
// à inclure dans les autres fichiers que le main

#include "globaldefine.h"

extern int toto;
extern char bufferTX[16]; // buffer pour l'affichage sur uart0
extern int n;
extern long TIMER0_VAR100US; // Base de temps de 100 us pour timer0
extern long TIMER0_VAR100USROLAND; // Spécial Roland
extern int BIP;                // "Booléen" qui indique si le bip est actif
extern int NB_BIP;
extern int MATCH_BIP;
extern int MATCH_VALUE_FQBIP;
extern int echo;
extern int trigger;
extern int etat;
extern int emi;
extern int message[5];
extern int indice;
extern int messagerec[10];
extern int indicerec;
extern int etatrec;
extern unsigned long compar;