#include "io.h"

void charger_la_grille(int grille[9][9])
{
	//demande le nom du fichier afin de charger une grille
	char fichier_nom[100];
	FILE *fichier = NULL;
	do
	{
		printf("Entrez le nom du fichier contenant la grille : ");
		scanf("%s", fichier_nom);
		strcat(fichier_nom, ".sudoku");
		fichier = fopen(fichier_nom, "r");
		
		if(fichier == NULL)
		{
			char fichier_nom_grilles[111] = "../grilles/";
			strcat(fichier_nom_grilles, fichier_nom);
			fichier = fopen(fichier_nom_grilles, "r");
			if(fichier == NULL)
			{				
				printf("Erreur a l'ouverture du fichier %s\n", fichier_nom);
			}
		}
		
	}while(fichier == NULL);
	
	printf("Le fichier %s a ete ouvert :-)\n", fichier_nom);
	
	//lecture du fichier afin de remplir la grille
	int i, j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			fscanf(fichier, "%i", &grille[i][j]);
		}
	}
	
	fclose(fichier);
}

void affiche_la_grille(int grille[9][9])
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf("%i ", grille[i][j]);
			if( (j+1)%3 == 0)//separation entre les blocs
			{
				printf(" ");
			}
		}
		printf("\n");
		if( (i+1)%3 == 0)//separation entre les blocs
		{
			printf("\n");
		}
	}
}
