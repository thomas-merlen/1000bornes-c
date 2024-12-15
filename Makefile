all: 1000_bornes


Affichage.o: Affichage.c Affichage.h Jeu.h
	gcc -Wall -c Affichage.c

Jeu.o: Jeu.c Jeu.h
	gcc -Wall -c Jeu.c

1000_bornes.o: 1000_bornes.c Jeu.h Jeu.h
	gcc -Wall -c 1000_bornes.c

1000_bornes: 1000_bornes.o Affichage.o Jeu.o
	gcc -o 1000_bornes 1000_bornes.o Affichage.o Jeu.o

clean:
	rm -f 1000_bornes *.o *~

