#include <stdio.h>
#include "Affichage.h"
#include "Jeu.h"

void affichage_progression(int player_bornes, int player_etat){
		if (player_bornes >= 0 && player_bornes <= 100){
			printf("\n|--------- %dkm \n\n", player_bornes);
		} else if (player_bornes > 100 && player_bornes <= 200){
				printf("||-------- %dkm \n\n", player_bornes);
		} else if (player_bornes > 200 && player_bornes <= 300){
				printf("|||------- %dkm \n\n", player_bornes);
		} else if (player_bornes > 300 && player_bornes <= 400){
				printf("||||------ %dkm \n\n", player_bornes);
		} else if (player_bornes > 400 && player_bornes <= 500){
				printf("|||||----- %dkm \n\n", player_bornes);
		} else if (player_bornes > 500 && player_bornes <= 600){
				printf("||||||---- %dkm \n\n", player_bornes);
		} else if (player_bornes > 600 && player_bornes <= 700){
				printf("|||||||-- %dkm \n\n", player_bornes);
		} else if (player_bornes > 700 && player_bornes <= 800){
				printf("||||||||-- %dkm \n\n", player_bornes);
		} else if (player_bornes > 800 && player_bornes <= 900){
				printf("|||||||||- %dkm \n\n", player_bornes);
		} else if (player_bornes >= 1000){
				printf("|||||||||| %dkm \n Bravo vous avez gagner !\n Merci d'avoir jouer à notre 1000 bornes !\n", player_bornes);
			}       
}

void affichage_carte(struct carte carte_joueur[7]){
        int i; /* variable de boucle */
		for (i = 0; i < 7; i++){
			printf("%s (%d), \n", carte_joueur[i].nom, i);
	}
}     

void affichage_interdiction(int interdiction){
	if (interdiction == FEU_ROUGE){
		printf("Vous êtes arreter au feu rouge, déclencher le feu vert !\n\n");
	} else if (interdiction == LIMITE_VITESSE){
		printf("Vous êtes fait prendre par les flics, en allez vous avec une fin de limite de vitesse !\n\n");
	} else if (interdiction == PANNE_ESSENCE){
		printf("Arrêtez vous à la station essence, vous êtes à sec !\n\n");
	} else if (interdiction == CREVAISON){
		printf("Vous avez crever, monter votre roue de secours !\n\n");
	} else if (interdiction == ACCIDENT){
		printf("Vous avez eu un accident ! Tous vas bien ? Faite réparer au plus vite votre voiture ! \n\n");
	}
}