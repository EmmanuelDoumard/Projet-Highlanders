// fichier contenant l'importation des variables globales de l'application
// à inclure dans les autres fichiers que le main

#include "globaldefine.h"

extern char bufferTX[64]; // buffer pour l'affichage sur uart0
extern int n;
extern char code[5];
extern int root;
extern int etalon;

// Variables Manu

extern int TIMER0_VAR100US; // Base de temps de 100 us pour timer0, se reset pour des raisons pratique
extern int TIMER0_TEMPS; // Définit le temps "absolu" depuis le début du timer0 (*100us)
extern int BIP;                // "Booléen" qui indique si le bip est actif
extern int NB_BIP;
extern int MATCH_BIP;
extern int MATCH_VALUE_FQBIP;
extern int ENABLE_BIP;
extern int BIP_DECOMPTE;

extern int I2C0_clockrate; // clockrate de I2C0...???

// Variables Benoît

extern int pos_x;
extern int pos_y;
extern int current;
extern int var_F5;
extern int old_F5;
extern int bula;

// Variables Roland

extern int TIMER0_VAR100USROLAND; // Spécial Roland
extern int etat;
extern int emi;
extern int message[5];
extern int indice;
extern int indicerec;
extern int messagerec[5];
extern int etatrec;
extern unsigned long compar;

// Variables Guillaume

extern int echo;
extern int trigger;
extern int nbr;
extern int tableau[250];
extern int modeUS;
extern int statEcho;
extern int validation[250];
