#include "LPC17xx.h"

// fichier contenant la déclaration des variables globales de l'application
// à inclure seulement dans le main

int toto;

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message à envoyer (max 16)