#ifndef _AFFICHAGE_
#define _AFFICHAGE_
#include "Jeu.h"

#define FEU_ROUGE 42
#define LIMITE_VITESSE 69
#define PANNE_ESSENCE 95
#define CREVAISON 406
#define ACCIDENT 17

void affichage_progression(int player_bornes, int player_etat);
void affichage_carte(struct carte carte_joueur[7]);
void affichage_interdiction(int interdiction);


#endif