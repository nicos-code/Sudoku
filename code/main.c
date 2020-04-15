#include <stdio.h>
#include <string.h>

#include "resolution.h" //algorithme de resolution du Sudoku
#include "io.h" //gestion des entrees/sorties (input/output)

int main()
{
	/*
	vocabulaire :
	grille : 9x9
	bloc : 3x3
	case : 1x1
	ligne : i cst et j de 0 à 8
	colonne : j cst et i de 0 à 8
	
	matrice ij (pour ligne et col) :
	11 12 13
	21 22 23
	
	exemple de grille :
	0 1 0  0 3 0  0 0 9
	7 4 9  5 2 8  0 1 6
	0 3 6  0 0 7  4 0 0

	9 0 0  7 6 0  5 8 4
	0 0 0  4 5 0  1 0 2
	0 0 0  1 8 0  0 6 0

	0 6 3  0 0 1  0 7 0
	2 9 0  0 0 5  0 0 0
	1 7 5  2 0 6  8 0 0
	*/
	int grille[9][9];
	
	charger_la_grille(grille);
	
	printf("Grille de depart : \n");
	affiche_la_grille(grille);
	printf("\n\n");
	
	int nb_parcours_grille = 0;
	nb_parcours_grille = remplir_la_grille(grille);
	
	printf("Grille completee : \n");
	printf("Nombre de parcours de grille : %i\n", nb_parcours_grille);
	affiche_la_grille(grille);
	
	return 0;
}
