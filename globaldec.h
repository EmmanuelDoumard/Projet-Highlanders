#include "LPC17xx.h"

// fichier contenant la déclaration des variables globales de l'application
// à inclure seulement dans le main

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message à envoyer (max 16)
char code[5]="BULA";
int root=0;
int etalon=0;

// Variables Manu

//Timer0
long TIMER0_VAR100US=0	;			// Base de temps d'1ms pour timer0
long TIMER0_TEMPS=0;
int MATCH_BIP=10000; // Intervalle de temps (en *100us) entre deux bips
int MATCH_VALUE_FQBIP=5;
int BIP=0;		// "Booléen" qui indique si le bip est actif
int NB_BIP=1; // Incrémenteur du nombre de bips envoyés
int ENABLE_BIP=0;
int BIP_DECOMPTE=0;

//i2c

int I2C0_clockrate=100000; // 100 000 Hz (100kbpm ?) pour la clockrate de I2C0...???

// Variables Benoît

int pos_x=0;
int pos_y=0;
int current=-1;
int bula=0;
int etatzer=0;
int old=-1;
int valida=-1;
int ultravalid=0;

// Variables Roland

long TIMER0_VAR100USROLAND=0 ; // Spécial Roland sur Timer0

int message[5]={1,1,1,1,0};
int indice=0;
int emi=0;
int etat=0;
int messagerec[5]={0,0,0,0,0};
int indicerec=0;
int etatrec=0;
unsigned long compar=0;
int lancement=0;

// Variables Guillaume

int echo=0;
int trigger=0;
int nbr=0;
int modeEnregistrement;
int indic=0;
int tableau[250];
int modeUS;
int statEcho;
int validation[250];
