/* 1000 Bornes par Matthieu MERLEN et Thomas MERLEN */
/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */
#include <time.h> /* gere l'aleatoire de notre script */

/* declaration constantes et types utilisateurs */
#define TRUE 1
#define FALSE 0

#define P1 1
#define P2 2

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

struct carte{
	char nom[100];
	int valeur; /* stock la valeur de la carte */
};

struct joueur_s{
	int etat; /* variable de type bool pour voir si le joueur peut avancer (init à 0 par défaut)*/
	int bornes; /* stock le nombre de bornes fait par le joueur (init à 0 par défaut)*/ 
	struct carte carte[7]; /* tableau stockant les cartes que le joueur possède */
	int tour; /* stock le nombre de tour (init à 0 par défaut)*/
	int qui_le_tour; /* stock c'est a quelle joueur de jouer */
};

struct pioche_s{
	struct carte tab_pioche[102];
};

/* declaration de fonctions utilisateurs */
void init_pioche(struct pioche_s tab_pioche); /* initialise le grand tableau avec la pioche de 102 cartes */
struct joueur_s carte(struct joueur_s player, struct pioche_s tab_pioche); /* gère la main du joueur au cours de la partie et s'occupe du changement de joueur */
void premiere_carte(struct joueur_s player, struct pioche_s tab_pioche); /* attribue les 6 premiere carte aux joueurs au début de la partie */
void ajouter_carte(struct joueur_s player, struct pioche_s tab_pioche); /* donne une carte a un joueur a chaque debut de tour */
void retirer_carte(struct joueur_s player, struct pioche_s tab_pioche, int indice);
void affichage_progression(struct joueur_s player); /* affiche la progression des joueurs et s'ils ont un malus ou non avant chaque tour */
void affichage_carte(struct joueur_s player); /* affiche la main du joueur avant chaque tour */
struct joueur_s ajout_borne(struct joueur_s player, int n); /* ajoute n borne au joueurs */ // n = carte.valeur quand une carte est une carte borne
struct joueur_s changer_etat(struct joueur_s player); /* change l'etat du joueur pour lui permettre de l'avancer ou le stopper */
int est_fini(struct joueur_s player); /* regarde si la partie est fini avant chaque changement de joueur */


/* fonction principale */
int main()
{
    	/* declaration et initialisation des variables */
	struct pioche_s test;
	init_pioche(test);

    	/* valeur fonction */
    	return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
void init_pioche(struct pioche_s tab_pioche){
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

	tab_pioche.tab_pioche[0] = panne_essence;
	printf("%d", tab_pioche.tab_pioche[0].valeur);		
}

struct joueur_s carte(struct joueur_s player, struct pioche_s tab_pioche){
	// PIOCHER UNE CARTE AVANT CHAQUE TOUR

	// DECIDE QUEL CARTE JOUER
	// ACTION CARTE
	
	// ENLEVER LA CARTE UTILISER
	
	// CHANGE LE TOUR
	
	return player;
}

void premiere_carte(struct joueur_s player, struct pioche_s tab_pioche){
        srand(time(NULL));
        int taille_tab_carte = 102; 
        int i, j; /* variable de boucle */
        
        
        for (i = 0; i < 7; i++){
                int carte_choisi = rand() % taille_tab_carte; /* genere une carte aleatoire dans le tableau */
                player.carte[i] = tab_pioche.tab_pioche[i]; /* l'ajoute dans la main de notre joueur */
                /* supprimer les cartes choisies du tableau */
                for (j = carte_choisi; j < taille_tab_carte; j++){
                        tab_pioche.tab_pioche[j] = tab_pioche.tab_pioche[j+1]; 
                }
                taille_tab_carte--;
        }      
}

void ajouter_carte(struct joueur_s player, struct pioche_s tab_pioche){
        srand(time(NULL));
        int i; /* variable de boucle */
        int carte_aleatoire = rand() % 102; /* genere une carte aleatoire dans le tableau */
        player.carte[6] = tab_pioche.tab_pioche[i];
        
        /* supprime la carte choisies */
        for (i = carte_aleatoire; i < 102; i++){
                      tab_pioche.tab_pioche[i] = tab_pioche.tab_pioche[i + 1];
        }
}

void retirer_carte(struct joueur_s player, struct pioche_s tab_pioche, int indice){
        struct carte tmp;
        tmp = player.carte[6]; /* sauvegarde la derniere carte */
        player.carte[6] = player.carte[indice]; /* met en derniere position la carte a supprimer */
        player.carte[indice] = tmp;
}
        
        

void affichage_progression(struct joueur_s player){
        char *etat_joueur;
        
        if (player.etat){
                etat_joueur = "Vous pouvez avancer !";
        } else if (!player.etat){
                etat_joueur = "Vous êtes bloquer, posez la carte nécessaire !";
        }

	if (player.bornes >= 0 && player.bornes <= 100){
		printf("|--------- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 100 && player.bornes <= 200){
	        printf("||-------- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 200 && player.bornes <= 300){
	        printf("|||------- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 300 && player.bornes <= 400){
	        printf("||||------ %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 400 && player.bornes <= 500){
	        printf("|||||----- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 500 && player.bornes <= 600){
	        printf("||||||---- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 600 && player.bornes <= 700){
	        printf("|||||||-- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 700 && player.bornes <= 800){
	        printf("||||||||-- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes > 800 && player.bornes <= 900){
	        printf("|||||||||- %dkm %s\n", player.bornes, etat_joueur);
	} else if (player.bornes >= 1000){
	        printf("|||||||||| %dkm %s\n Bravo vous avez gagner !\n", player.bornes, etat_joueur);
        }       
}
	        
struct joueur_s ajout_borne(struct joueur_s player, int n){
	player.bornes += n; 
	return player;
}

struct joueur_s changer_etat(struct joueur_s player){
	if (player.etat){
		player.etat = FALSE;
	} else if (!player.etat){
		player.etat = TRUE;
	}

	return player;
}

int est_fini(struct joueur_s player){
        if (player.bornes >= 1000){
                return TRUE;
        } else {
                return FALSE;
        }
}
