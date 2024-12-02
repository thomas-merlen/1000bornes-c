/* 1000 Bornes par Matthieu MERLEN et Thomas MERLEN */
/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */

/* declaration constantes et types utilisateurs */
#define TRUE 1
#define FALSE 0

/* declaration des constantes pour les cartes spéciales */
#define FEU_ROUGE 42
#define FEU_VERT 24
#define LIMITE_VITESSE 69
#define FIN_LIMITE  96
#define PANNE_ESSENCE 95
#define FIN_PANNE 98
#define CREVAISON 406
#define FIN_CREVAISON 407
#define ACCIDENT 17
#define FIN_ACCIDENT 18

struct joueur_s{
	int etat; /* variable de type bool pour voir si le joueur peut avancer (init à 0 par défaut)*/
	int bornes; /* stock le nombre de bornes fait par le joueur (init à 0 par défaut)*/ 
	char nom[100];
	int carte[7]; /* tableau stockant les cartes que le joueur possède */
	int tour; /* stock le nombre de tour (init à 0 par défaut)*/
};

struct carte{
	char nom[100];
	int valeur;
};

/* declaration de fonctions utilisateurs */
struct carte init_pioche();
struct joueur_s carte(struct joueur_s player, struct carte tab_carte[102]); /* gère la main du joueur au cours de la partie et s'occupe du changement de joueur */
void affichage_carte(struct joueur_s player); /* affiche la main du joueur avant chaque tour */
struct joueur_s ajout_borne(struct joueur_s player, int n); /* ajoute n borne au joueurs */ // n = carte.valeur quand une carte est une carte borne
struct joueur_s changer_etat(struct joueur_s player); /* change l'etat du joueur pour lui permettre de l'avancer ou le stopper */
int est_fini(struct joueur_s player); /* regarde si la partie est fini avant chaque changement de joueur */


/* fonction principale */
int main()
{
    	
	init_pioche();


	/* declaration et initialisation des variables */
	// Déclarer le tableau des cartes disponibles

	// Appel de la fonction carte 
	//
	// Initialisation du struct

    	/* ici faire quelque chose */

    	/* valeur fonction */
    	return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
struct carte init_pioche(){
	struct carte tab[102];
	struct carte borne = {"Ajout Borne", 0};
	struct carte fin_limite = {"Fin de la limite de vitesse", FIN_LIMITE};
	struct carte ajout_essence = {"Ajout de l'essence", FIN_PANNE}; 
	struct carte roue_secours = {"Equipe une nouvelle roue", FIN_CREVAISON};
	struct carte reparation = {"Répare le véhicule", FIN_ACCIDENT};
	struct carte panne_essence = {"Permet qu'un véhicule adverse tombe en panne", PANNE_ESSENCE};
	struct carte crevaison = {"Crève le pneu d'un adversaire", CREVAISON};
	struct carte accident = {"Provoque un accident pour un adversaire", ACCIDENT};
	struct carte limite_vitesse = {"Donne une limitation de vitesse à un adversaire", LIMITE_VITESSE}; 
	struct carte feu_rouge = {"Met un feu rouge à un adversaure", FEU_ROUGE};
	struct carte feu_vert = {"Vous permet de repartir sur la route", FEU_VERT};

	int i;
	int n = 0;

		
	for (i = 0; i<14; i++){
		/* s'occupe des cartes avec 3 exemplaires */
		if (i < 3){
			tab[n] = panne_essence;
			tab[n+1] = crevaison;
			tab[n+2] = accident;

			n += 3;
		}

		/* s'occupe des cartes avec 4 exemplaires */
		if (i < 4){
			tab[n] = limite_vitesse;
			borne.valeur = 200;
			tab[n+1] = borne;

			n += 2;
		}
		/* s'occupe des cartes avec 5 exemplaires */
		if (i < 5){
			tab[n] = feu_rouge;
			n += 1;
		}
		/* s'occupe des cartes avec 6 exemplaires */
		if (i < 6){
			tab[n] = fin_limite;
			tab[n+1] = ajout_essence;
			tab[n+2] = roue_secours;
			tab[n+3] = reparation;
			n += 4;
		}

		if (i < 10){
			borne.valeur = 25;
			tab[n] = borne;
			borne.valeur = 50;
			tab[n+1] = borne;
			borne.valeur = 75;
			tab[n+2] = borne;
			n += 3;
		}

		if (i < 12){
			borne.valeur = 100;
			tab[n] = borne;
			n += 1;
		}

		tab[n] = feu_vert;
		n += 1;

	}	


	printf("%d ", tab[n-1].valeur);
	printf("%d", n);

	return tab[102];	
}

struct joueur_s ajout_borne(struct joueur_s player, int n){
	player.bornes += n;
	return player;
}

struct joueur_s changer_etat(struct joueur_s player)#
	if (player.etat){
		player.etat = FALSE;
	} else if (!player.etat)
		player.etat = TRUE;
}
