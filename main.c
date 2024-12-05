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
};

struct pioche_s{
	struct carte tab_pioche[102];
};

/* declaration de fonctions utilisateurs */
void init_pioche(struct carte tab_pioche[102]); /* initialise le grand tableau avec la pioche de 102 cartes */
struct joueur_s jeux(struct joueur_s player1, struct joueur_s player2, struct pioche_s tab_pioche); /* gère la main du joueur au cours de la partie et s'occupe du changement de joueur */
void premiere_carte(struct carte carte_joueur[7], struct pioche_s tab_pioche); /* attribue les 6 premiere carte aux joueurs au début de la partie */
void ajouter_carte(struct carte carte_joueur[7], struct pioche_s pioche); /* donne une carte a un joueur a chaque debut de tour */
void retirer_carte(struct carte carte_joueur[7], struct pioche_s tab_pioche, int indice);
void affichage_progression(struct joueur_s player); /* affiche la progression des joueurs et s'ils ont un malus ou non avant chaque tour */
void affichage_carte(struct carte carte_joueur[7]); /* affiche la main du joueur avant chaque tour */
int ajout_borne(int player_borne, int n); /* ajoute n borne au joueurs */ // n = carte.valeur quand une carte est une carte borne
int changer_etat(int player_etat); /* change l'etat du joueur pour lui permettre de l'avancer ou le stopper */
int est_fini(struct joueur_s player); /* regarde si la partie est fini avant chaque changement de joueur */


/* fonction principale */
int main()
{
    /* declaration et initialisation des variables */
	struct pioche_s pioche;
	init_pioche(pioche.tab_pioche);
	
	struct carte vide = {"0", 0};
	struct carte carte[7] = {vide, vide, vide, vide, vide, vide, vide};
      
	struct joueur_s joueur1 = {0, 0, carte[7], 0};
	struct joueur_s joueur2 = {0, 0, carte[7], 0}; 
	
	premiere_carte(joueur1.carte, pioche);
	premiere_carte(joueur2.carte, pioche);

    int qui_le_tour; 
    qui_le_tour = P1;

	system("clear"); /* permet d'effacer tous le terminal pour une belle interface */


    while (!est_fini(joueur1) || !est_fini(joueur2)){
            if (qui_le_tour == P1){
				printf("Tour du joueur 1\n");
                jeux(joueur1, joueur2, pioche);
                est_fini(joueur1);
                qui_le_tour = P2; 
            } else if (qui_le_tour == P2){
				printf("Tour du joueur 2\n");
                jeux(joueur2, joueur1, pioche);
                est_fini(joueur2);
                qui_le_tour = P1;
            }
    }

    /* valeur fonction */
    return EXIT_SUCCESS;
}

/* definitions des fonctions utilisateurs */
void init_pioche(struct carte pioche[102]){
	struct carte borne25 = {"Ajout Borne 25 kilomètres", 0};
	struct carte borne50 = {"Ajout Borne 50 kilomètres", 0};
	struct carte borne75 = {"Ajout Borne 75 kilomètres", 0};
	struct carte borne100 = {"Ajout Borne 100 kilomètres", 0};
	struct carte borne200 = {"Ajout Borne 200 kilomètres", 0};
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
		/* gère les cartes avec 3 exemplaires */
		if (i<3){
			pioche[n] = panne_essence;
			pioche[n+1] = crevaison;
			pioche[n+2] = accident;
			n+=3;
		}
		/* gère les cartes avec 4 exemplaires */
		if (i<4){
			pioche[n] = limite_vitesse;
			pioche[n+1] = borne200;
			n+=2;
		}
		/* gère les cartes avec 5 exemplaires */
		if (i<5){
			pioche[n] = feu_rouge;
			n+=1;
		}
		/* gère les cartes avec 6 exemplaires */
		if (i<6){
			pioche[n] = fin_limite;
			pioche[n+1] = ajout_essence;
			pioche[n+2] = roue_secours;
			pioche[n+3] = reparation;
			n+=4;
		}
		/* gère les cartes avec 10 exemplaires */
		if (i<10){
			pioche[n] = borne25; 
			pioche[n+1] = borne50;
			pioche[n+2] = borne75;
			n+=3;
		}
		/* gère les cartes avec 12 exemplaires */
		if (i<12){
			pioche[n] = borne100;
			n+=1;
		}
		/* gère les cartes avec 14 exemplaires */
		if (i<14){
			pioche[n] = feu_vert;
			n+=1;
		}
		
	}
}

struct joueur_s jeux(struct joueur_s player1, struct joueur_s player2, struct pioche_s tab_pioche){
	int carte_choisie;

	/* pioche une carte avant de joueur */
	ajouter_carte(player1.carte, tab_pioche);	

	/* saisie utilisateur */
	affichage_carte(player1.carte); /* affiche les cartes du joueur*/
	printf("Quelle carte souhaitez vous utiliser ?\n");
	scanf("%d", &carte_choisie);

	/* si la carte est une interdiction */
	if (player1.carte[carte_choisie].valeur == FEU_ROUGE || player1.carte[carte_choisie].valeur == LIMITE_VITESSE || player1.carte[carte_choisie].valeur == PANNE_ESSENCE || player1.carte[carte_choisie].valeur == CREVAISON || player1.carte[carte_choisie].valeur == ACCIDENT){
		player2.etat = 0;
	}

	/* si la carte leve l'interdiction */
	if (player1.carte[carte_choisie].valeur == FEU_VERT || player1.carte[carte_choisie].valeur == FIN_LIMITE || player1.carte[carte_choisie].valeur == FIN_PANNE || player1.carte[carte_choisie].valeur == FIN_CREVAISON || player1.carte[carte_choisie].valeur == FIN_ACCIDENT){
		player1.etat = 1;
	}

	/* carte borne pour avancer */
	if (player1.carte[carte_choisie].valeur == 25){
		player1.bornes += 25;
	}

	if (player1.carte[carte_choisie].valeur == 50){
		player1.bornes += 50;
	}

	if (player1.carte[carte_choisie].valeur == 75){
		player1.bornes += 75;
	}

	if (player1.carte[carte_choisie].valeur == 100){
		player1.bornes += 100;
	}

	if (player1.carte[carte_choisie].valeur == 200){
		player1.bornes += 200;
	}

	
	retirer_carte(player1.carte, tab_pioche, carte_choisie);	
	
	return player1;
}

void premiere_carte(struct carte carte_joueur[7], struct pioche_s pioche){
        srand(time(NULL));
        int taille_tab_carte = 102; 
		int carte_choisi = 0;
        int i, j; /* variable de boucle */
        
        
        for (i = 0; i < 7; i++){
                carte_choisi = rand() % taille_tab_carte; /* genere une carte aleatoire dans le tableau */
                carte_joueur[i] = pioche.tab_pioche[carte_choisi]; /* l'ajoute dans la main de notre joueur */
				//printf("%d --", carte_joueur[i].valeur);
                /* supprimer les cartes choisies du tableau */
                for (j = carte_choisi; j < taille_tab_carte; j++){
                        pioche.tab_pioche[j] = pioche.tab_pioche[j+1]; 
                }
                taille_tab_carte--;
        }      
}

void ajouter_carte(struct carte carte_joueur[7], struct pioche_s pioche){
        srand(time(NULL));
        int i; /* variable de boucle */
        int carte_aleatoire = rand() % 102; /* genere une carte aleatoire dans le tableau */
        i = carte_aleatoire;
        carte_joueur[6] = pioche.tab_pioche[i];
        
        /* supprime la carte choisies */
        for (i = carte_aleatoire; i < 102; i++){
                      pioche.tab_pioche[i] = pioche.tab_pioche[i + 1];
        }
}

void retirer_carte(struct carte carte_joueur[7], struct pioche_s tab_pioche, int indice){
        struct carte tmp;
        tmp = carte_joueur[6]; /* sauvegarde la derniere carte */
        carte_joueur[6] = carte_joueur[indice]; /* met en derniere position la carte a supprimer */
        carte_joueur[indice] = tmp;
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

void affichage_carte(struct carte carte_joueur[7]){
        int i; /* variable de boucle */
		for (i = 0; i < 7; i++){
			printf("%s (%d), ", carte_joueur[i].nom, i);
		}
}     


int ajout_borne(int player_borne, int n){
	return player_borne + n; 
}

int changer_etat(int player_etat){
	// 	joueur1.etat = changer_etat(joueur1.etat);
	int n;
	if (player_etat == 0){
		n = 1;
	} else if (player_etat == 1){
		n = 0;
	}

	return n;
}

int est_fini(struct joueur_s player){
    if (player.bornes >= 1000){
            return TRUE;
    } else {
            return FALSE;
    }
}