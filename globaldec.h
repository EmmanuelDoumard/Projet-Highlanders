#include "LPC17xx.h"

// fichier contenant la d�claration des variables globales de l'application
// � inclure seulement dans le main

int toto;

char bufferTX[16]; // buffer pour l'affichage sur uart0
int n;  // taille du message � envoyer (max 16)