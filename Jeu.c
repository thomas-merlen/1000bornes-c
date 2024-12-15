#include <stdio.h>
#include <time.h>

#include "Affichage.h"
#include "Jeu.h"


/* definitions des fonctions utilisateurs */
void init_pioche(struct carte pioche[102]){
	struct carte borne25 = {"Borne 25 km - Ajoute 25 kilomètres", 25};
	struct carte borne50 = {"Borne 50 km - Ajoute 50 kilomètres", 50};
	struct carte borne75 = {"Borne 75 km - Ajoute 75 kilomètres", 75};
	struct carte borne100 = {"Borne 100 km - Ajoute 100 kilomètres", 100};
	struct carte borne200 = {"Borne 200 km - Ajoute 200 kilomètres", 200};
	struct carte fin_limite = {"Fin Limite de Vitesse - Met fin au contrôle de police", FIN_LIMITE};
	struct carte ajout_essence = {"Plein Carburant - Ajoute du gasoil", FIN_PANNE}; 
	struct carte roue_secours = {"Roue de secours - Equipe une nouvelle roue", FIN_CREVAISON};
	struct carte reparation = {"Répare le véhicule - Passage chez Norauto ", FIN_ACCIDENT};
	struct carte panne_essence = {"Siphone le réservoir - Permet que le véhicule adverse tombe en panne", PANNE_ESSENCE};
	struct carte crevaison = {"Crevaison - Crève le pneu d'un adversaire", CREVAISON};
	struct carte accident = {"Accident - Provoque un accident pour l'adversaire", ACCIDENT};
	struct carte limite_vitesse = {"Limite de vitesse - Le véhicule adverse doit subir un contrôle de police", LIMITE_VITESSE}; 
	struct carte feu_rouge = {"Feu Rouge - Immobilise l'adversaire à un feu rouge", FEU_ROUGE};
	struct carte feu_vert = {"Feu Vert - Vous permet de repartir sur la route, il était long ce feu", FEU_VERT};

	int i; /* variable de boucle */
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

void premiere_carte(struct carte carte_joueur[7], struct pioche_s pioche){
        int taille_tab_carte = 102; 
		int carte_choisi = 0;
        int i, j; /* variables de boucle */
        
        for (i = 0; i < 7; i++){
                carte_choisi = rand() % taille_tab_carte + 1; /* genere une carte aleatoire dans le tableau */
                carte_joueur[i] = pioche.tab_pioche[carte_choisi]; /* l'ajoute dans la main de notre joueur */
				//printf("%d --", carte_joueur[i].valeur);
                /* supprimer les cartes choisies du tableau */
                for (j = carte_choisi; j < taille_tab_carte; j++){
                        pioche.tab_pioche[j] = pioche.tab_pioche[j+1]; /* on remplace la carte choisie par la carte suivante et on le fait pour toutes les cartes*/
                }
                taille_tab_carte--;
        }      
}

void ajouter_carte(struct carte carte_joueur[7], struct pioche_s pioche){
        int i; /* variable de boucle */
        int carte_aleatoire = rand() % 102; /* genere une carte aleatoire dans le tableau */
        i = carte_aleatoire;
        carte_joueur[6] = pioche.tab_pioche[i];
        
        /* supprime la carte choisies */
        for (i = carte_aleatoire; i < 102; i++){
                      pioche.tab_pioche[i] = pioche.tab_pioche[i + 1]; /* on remplace la carte choisie par la carte suivante et on le fait pour toutes les cartes*/
        }
}

void retirer_carte(struct carte carte_joueur[7], int indice){
        struct carte tmp; /* variable temporaire */
        tmp = carte_joueur[6]; /* sauvegarde la derniere carte */
        carte_joueur[6] = carte_joueur[indice]; /* met en derniere position la carte a supprimer */
		carte_joueur[indice] = tmp;
}

int ajout_borne(int player_borne, int n){
	return player_borne + n;
}

int changer_etat(int player_etat){
	int n;
	if (player_etat == 0){
		n = 1;
	} else if (player_etat == 1){
		n = 0;
	}

	return n;
}

int est_fini(int player_borne){
    if (player_borne >= 1000){
            return TRUE;
    } else {
            return FALSE;
    }
}