#ifndef _JEU_
#define _JEU_

/* declaration constantes et types utilisateurs */
#define TRUE 1
#define FALSE 0

#define P1 1
#define P2 2

#define FEU_VERT 24
#define FIN_LIMITE  96
#define FIN_PANNE 98
#define FIN_CREVAISON 407
#define FIN_ACCIDENT 18

struct carte{
	char nom[100];
	int valeur; /* stock la valeur de la carte */
};

struct joueur_s{
	int etat; /* variable de type bool pour voir si le joueur peut avancer (init à 0 par défaut)*/
	int bornes; /* stock le nombre de bornes fait par le joueur (init à 0 par défaut)*/ 
	struct carte carte[7]; /* tableau stockant les cartes que le joueur possède */
	int tour; /* stock le nombre de tour (init à 0 par défaut)*/
	int interdiction; /* stock la carte d'interdiction */
};

struct pioche_s{
	struct carte tab_pioche[102];
};

/* declaration de fonctions utilisateurs */
void init_pioche(struct carte tab_pioche[102]); /* initialise le grand tableau avec la pioche de 102 cartes */
void premiere_carte(struct carte carte_joueur[7], struct pioche_s tab_pioche); /* attribue les 6 premiere carte aux joueurs au début de la partie */
void ajouter_carte(struct carte carte_joueur[7], struct pioche_s pioche); /* donne une carte a un joueur a chaque debut de tour */
void retirer_carte(struct carte carte_joueur[7], int indice); /* retire une carte dans la main du joueur */
int ajout_borne(int player_borne, int n); /* ajoute n borne au joueurs */ // n = carte.valeur quand une carte est une carte borne
int changer_etat(int player_etat); /* change l'etat du joueur pour lui permettre de l'avancer ou le stopper */
int est_fini(int player_borne); /* regarde si la partie est fini avant chaque changement de joueur */

#endif
