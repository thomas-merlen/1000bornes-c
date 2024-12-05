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

void init_pioche(struct carte tab_pioche[102]); /* initialise le grand tableau avec la pioche de 102 cartes */
void premiere_carte(struct carte carte_joueur[7], struct pioche_s tab_pioche); /* attribue les 6 premiere carte aux joueurs au début de la partie */
void affichage_carte(struct carte carte_joueur[7]); /* affiche la main du joueur avant chaque tour */
int ajout_borne(int player_borne, int n); /* ajoute n borne au joueurs */ // n = carte.valeur quand une carte est une carte borne



int main(){
	struct pioche_s pioche;
	init_pioche(pioche.tab_pioche);
	printf("%d\n", pioche.tab_pioche[0].valeur);

	struct carte vide = {"0", 2};
	struct carte carte[7] = {vide, vide, vide, vide, vide, vide, vide};
      
	struct joueur_s joueur1 = {0, 0, carte[7], 0};
	struct joueur_s joueur2 = {0, 0, carte[7], 0}; 

	premiere_carte(joueur1.carte, pioche);
	printf("%d\n", joueur1.carte[2].valeur);

	affichage_carte(joueur1.carte);

	ajout_borne(joueur1.bornes, 50);
	printf("\nBorne = %d", joueur1.bornes);

    return EXIT_SUCCESS;
}

void init_pioche(struct carte pioche[102]){
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
			borne.valeur = 200;
			pioche[n+1] = borne;
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
			borne.valeur = 25;
			pioche[n] = borne; 
			borne.valeur = 50;
			pioche[n+1] = borne;
			borne.valeur = 75;
			pioche[n+2] = borne;
			n+=3;
		}
		/* gère les cartes avec 12 exemplaires */
		if (i<12){
			borne.valeur = 100;
			pioche[n] = borne;
			n+=1;
		}
		/* gère les cartes avec 14 exemplaires */
		if (i<14){
			pioche[n] = feu_vert;
			n+=1;
		}
		
	}
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

void affichage_carte(struct carte carte_joueur[7]){
        int i; /* variable de boucle */
        
        for (i = 0; i < 7; i++){
              printf("%s (%d), ", carte_joueur[i].nom, i);
        }       
}

int ajout_borne(int player_borne, int n){
	return player_borne + n; 
}