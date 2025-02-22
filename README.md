# 1000 Bornes

**Programmeurs**: Thomas MERLEN & Matthieu MERLEN  
**GitHub**: [https://github.com/thomas-merlen/1000bornes-c](https://github.com/thomas-merlen/1000bornes-c)  
**Date**: 15/12/2025

## Description du jeu

Le jeu de **1000 Bornes** consiste à parcourir en premier les 1000 bornes à l'aide de cartes piochées aléatoirement.

Il y a 3 types de cartes :
- **Bornes** (qui vous permettent d'avancer),
- **Attaques** (pour saboter le véhicule de l'autre),
- **Parades** (pour contrer les attaques adverses).

Votre but est simple : parcourir les 1000 bornes en premier tout en contrant les différentes attaques de vos adversaires.

Cette première version vous propose de jouer en **1 vs 1**.

## Règles du jeu

Voici un rappel des différentes règles du **1000 Bornes** :
- Chaque joueur possède toujours 6 cartes dans sa main.
- Chaque joueur pioche une carte avant chaque tour.
- Pour commencer la partie, le joueur doit avoir la carte **Feu Vert**.
- S'il est impossible de jouer, le joueur entre 7 et choisit une carte à enlever.
- La partie se termine quand le premier joueur a atteint les 1000 bornes.

Les cartes sont générées aléatoirement, j'espère que vous vous sentez chanceux aujourd'hui.

## Contenances de la pioche

**Cartes Bornes** :
- 12 Bornes 100 km
- 10 Bornes 25 km
- 10 Bornes 50 km
- 10 Bornes 75 km
- 04 Bornes 200 km

**Cartes Attaques** :
- 05 Feu Rouge
- 04 Limite De Vitesse
- 03 Pannes Essences
- 03 Crevaisons
- 03 Accident

**Cartes Parades** :
- 14 Feu Vert
- 06 Fin Limitation De Vitesse
- 06 Ajout Essence
- 06 Roue De Secours
- 06 Réparations

## Installation

Décompacter l'archive du jeu ce qui crée un répertoire 1000_Bornes.
Dans un terminal Linux/Unix, se placer dans le répertoire du jeu et utiliser la commande make.

## Comment jouer

Lancer le programme 1000_bornes.
Sous Linux, commande ./1000_bornes