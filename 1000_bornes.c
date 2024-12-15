/* 1000 Bornes par Matthieu MERLEN et Thomas MERLEN */
/* declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdio.h> /* printf */
#include <time.h> /* gere l'aleatoire de notre script */

#include "Affichage.h"
#include "Jeu.h"

/* fonction principale */
int main()
{
	/* demande le nom des joueurs */
	char nom_joueur1[20];
	char nom_joueur2[20]; 

	printf("Joueur 1, quelle est votre nom ? : ");
    scanf("%s", nom_joueur1);

	printf("Joueur 2, quelle est votre nom ? : ");
    scanf("%s", nom_joueur2);

	/* gere l'aleatoire dans notre jeux */
	srand(time(NULL));

    /* declaration et initialisation des variables */
	struct pioche_s pioche;
	init_pioche(pioche.tab_pioche);
	
	struct carte vide = {"0", 0};

	struct carte carte1[7] = {vide, vide, vide, vide, vide, vide, vide};
	struct carte carte2[7] = {vide, vide, vide, vide, vide, vide, vide};
      
	struct joueur_s joueur1 = {0, 0, carte1[7], 0, FEU_ROUGE};
	struct joueur_s joueur2 = {0, 0, carte2[7], 0, FEU_ROUGE}; 
	
	premiere_carte(joueur1.carte, pioche);
	premiere_carte(joueur2.carte, pioche);

	/* les joueurs commencent au feu rouge */
	joueur1.interdiction = FEU_ROUGE; 
	joueur2.interdiction = FEU_ROUGE;

    int qui_le_tour; /* variable pour gerer le tour */
    qui_le_tour = P1; /* le joueur 1 commence la partie */

	system("clear"); /* permet d'effacer tous le terminal pour une belle interface */

	int carte_choisie;
	int carte_debarasser;

	int fini;
	fini = FALSE; 

    while (fini == FALSE){
            if (qui_le_tour == P1){
				system("clear"); /* permet d'effacer tous le terminal pour une belle interface */
				printf("Tour du joueur %s\n\n", nom_joueur1);

				affichage_interdiction(joueur1.interdiction); /* affiche la progression du joueur */

				/* pioche une carte avant de jouer */
                ajouter_carte(joueur1.carte, pioche);

				/* saisie utilisateur*/
				affichage_progression(joueur1.bornes, joueur1.etat);
				affichage_carte(joueur1.carte); /* affiche les cartes du joueur */
				printf("\nQuelle carte souhaitez vous utiliser ? (0-6) (7 si vous ne pouvez pas jouer): ");
				scanf("%d", &carte_choisie);

				if (carte_choisie <= 6){

					/* si la carte est une interdiction */
					if (joueur1.carte[carte_choisie].valeur == FEU_ROUGE || joueur1.carte[carte_choisie].valeur == LIMITE_VITESSE || joueur1.carte[carte_choisie].valeur == PANNE_ESSENCE || joueur1.carte[carte_choisie].valeur == CREVAISON || joueur1.carte[carte_choisie].valeur == ACCIDENT){
						joueur2.etat = 0;
						joueur2.interdiction = joueur1.carte[carte_choisie].valeur;
					}

					/* si la carte supprime une interdiction */
					if ((joueur1.carte[carte_choisie].valeur == FEU_VERT && joueur1.interdiction == FEU_ROUGE) || (joueur1.carte[carte_choisie].valeur == FIN_LIMITE && joueur1.interdiction == LIMITE_VITESSE) || (joueur1.carte[carte_choisie].valeur == FIN_PANNE && joueur1.interdiction == PANNE_ESSENCE) || (joueur1.carte[carte_choisie].valeur == FIN_CREVAISON && joueur1.interdiction == CREVAISON) || (joueur1.carte[carte_choisie].valeur == FIN_ACCIDENT && joueur1.interdiction == ACCIDENT)){
						joueur1.etat = 1;
						joueur1.interdiction = FALSE;
					}

					/* carte borne pour avancer */
					if ((joueur1.carte[carte_choisie].valeur == 25 || joueur1.carte[carte_choisie].valeur == 50 || joueur1.carte[carte_choisie].valeur == 75 || joueur1.carte[carte_choisie].valeur == 100 || joueur1.carte[carte_choisie].valeur == 200) && joueur1.etat == 1){
						joueur1.bornes = ajout_borne(joueur1.bornes, joueur1.carte[carte_choisie].valeur);
					}			

					/* retire la carte de la main du joueur */
					retirer_carte(joueur1.carte, carte_choisie);					

				} else if (carte_choisie == 7){
					printf("Choissisez une carte à enlever de votre main pour la remplacer (0-6) : ");
					scanf("%d", &carte_debarasser);

					retirer_carte(joueur1.carte, carte_debarasser);
				}


				/* verifie si le joueur a atteint 1000 bornes */
                if (est_fini(joueur1.bornes) == TRUE){
					fini = TRUE;
					affichage_progression(joueur1.bornes, joueur1.etat);
				}

			 	/* change le tour */
                qui_le_tour = P2; 
				
            } else if (qui_le_tour == P2){
				system("clear"); /* permet d'effacer tous le terminal pour une belle interface */
				printf("Tour du joueur %s\n\n", nom_joueur2);

				affichage_interdiction(joueur2.interdiction);

				/* pioche une carte avant de jouer */
                ajouter_carte(joueur2.carte, pioche);

				/* saisie utilisateur */
				affichage_progression(joueur2.bornes, joueur2.etat); /* affiche la progression du joueur */
				affichage_carte(joueur2.carte); /* affiche les cartes du joueur */
				printf("\nQuelle carte souhaitez vous utiliser ? (0-6) (7 si vous ne pouvez pas jouer): ");
				scanf("%d", &carte_choisie);

				if (carte_choisie <= 6){

					/* si la carte est une interdiction */
					if (joueur2.carte[carte_choisie].valeur == FEU_ROUGE || joueur2.carte[carte_choisie].valeur == LIMITE_VITESSE || joueur2.carte[carte_choisie].valeur == PANNE_ESSENCE || joueur2.carte[carte_choisie].valeur == CREVAISON || joueur2.carte[carte_choisie].valeur == ACCIDENT){
						joueur1.etat = 0;
						joueur1.interdiction = joueur2.carte[carte_choisie].valeur;
					}

					/* si la carte supprime une interdiction */
					if ((joueur2.carte[carte_choisie].valeur == FEU_VERT && joueur2.interdiction == FEU_ROUGE) || (joueur2.carte[carte_choisie].valeur == FIN_LIMITE && joueur2.interdiction == LIMITE_VITESSE) || (joueur2.carte[carte_choisie].valeur == FIN_PANNE && joueur2.interdiction == PANNE_ESSENCE) || (joueur2.carte[carte_choisie].valeur == FIN_CREVAISON && joueur2.interdiction == CREVAISON) || (joueur2.carte[carte_choisie].valeur == FIN_ACCIDENT && joueur2.interdiction == ACCIDENT)){
						joueur2.etat = 1;
						joueur2.interdiction = FALSE;
					}

					/* carte borne pour avancer */
					if ((joueur2.carte[carte_choisie].valeur == 25 || joueur2.carte[carte_choisie].valeur == 50 || joueur2.carte[carte_choisie].valeur == 75 || joueur2.carte[carte_choisie].valeur == 100 || joueur2.carte[carte_choisie].valeur == 200) && joueur2.etat == 1){
						joueur2.bornes = ajout_borne(joueur2.bornes, joueur2.carte[carte_choisie].valeur);
					}						

					/* retire la carte de la main du joueur */
					retirer_carte(joueur2.carte, carte_choisie);

				} else if (carte_choisie == 7){
					printf("Choissisez une carte à enlever de votre main pour la remplacer (0-6) : ");
					scanf("%d", &carte_debarasser);

					retirer_carte(joueur2.carte, carte_debarasser);
				}

				/* verifie si le joueur a atteint 1000 bornes */
                if (est_fini(joueur2.bornes) == TRUE){
					fini = TRUE;
					affichage_progression(joueur2.bornes, joueur2.etat);
				}
				
			 	/* change le tour */
                qui_le_tour = P1;
            }
    }

    /* valeur fonction */
    return EXIT_SUCCESS;
}