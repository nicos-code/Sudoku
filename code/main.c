#include <stdio.h>
#include <string.h>

void affiche_grille(int grille[9][9])
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

int verif_col(int grille[9][9], int chiffre_saisir, int j)
{
    int est_valide = 1;
    int i_temp = 0;
	
	while(i_temp < 9 && est_valide)//on parcours la col
    {
		if(chiffre_saisir == grille[i_temp][j])
		{
		   est_valide = 0;
		}
		i_temp++;
    }
	
    return est_valide;
}

int verif_ligne(int grille[9][9], int chiffre_saisir, int i)
{
    int est_valide = 1;
    int j_temp = 0;
	
	while(j_temp < 9 && est_valide)//on parcours la ligne
    {
		if(chiffre_saisir == grille[i][j_temp])
		{
		   est_valide = 0;
		}
		j_temp++;
    }
	
    return est_valide;
}

int verif_bloc(int grille[9][9], int chiffre_saisir, int i, int j)
{
    int est_valide = 1;
	
	/*
	9 blocs ij: 
	00 01 02
	10 11 12
	20 21 22
	*/
	int const i_bloc = i/3;
	int const j_bloc = j/3;
	
	//bloc_case => case en haut à gauche du bloc
	int const i_bloc_case = 3*i_bloc;
	int const j_bloc_case = 3*j_bloc;
	
	//on parcours le bloc
    int i_temp, j_temp;
	for(i_temp = i_bloc_case; i_temp <= i_bloc_case+2; i_temp++)
	{
		for(j_temp = j_bloc_case; j_temp <= j_bloc_case+2; j_temp++)
		{
			if(chiffre_saisir == grille[i_temp][j_temp])
			{
			   est_valide = 0;
			}
		}
	}
	
	return est_valide;
}

int remplir_la_case(int grille[9][9], int i, int j)
{
	/*
	tableau de taille 9 -> possibilités
	*/
	int chiffre_possible[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};//chiffre 1 ok, chiffre 2 ok...
	int chiffre;
	
	int somme = 0;//pour vérifier l'unicité du chiffre possible
	
	for(chiffre = 1; chiffre <= 9; chiffre++)
	{
		if(verif_col(grille, chiffre, j) && verif_ligne(grille, chiffre, i) && verif_bloc(grille, chiffre, i, j))
		{
			chiffre_possible[chiffre-1] = 1;
		}
		else
		{
			chiffre_possible[chiffre-1] = 0;
		}
		somme += chiffre_possible[chiffre-1];
	}
	
	if(somme == 1)//unicité du chiffre possible
	{
		//cherche le chiffre possible
		chiffre = 1;
		while(chiffre_possible[chiffre-1] == 0)
		{
			chiffre++;
		}
		return chiffre;
	}
	else//sinon pas possible (plusieurs chiffres possibles)
	{
		return 0;
	}
}

int main()
{
	/*
	matrice ij :
	11 12 13
	21 22 23
	
	grille : 9x9
	bloc : 3x3
	case : 1x1
	ligne : i cst et j de 0 à 8
	colonne : j cst et i de 0 à 8
	*/
	int grille[9][9]; /*= {
		{0, 1, 0, 0, 3, 0, 0, 0, 9},
		{7, 4, 9, 5, 2, 8, 0, 1, 6},
		{0, 3, 6, 0, 0, 7, 4, 0, 0},
		{9, 0, 0, 7, 6, 0, 5, 8, 4},
		{0, 0, 0, 4, 5, 0, 1, 0, 2},
		{0, 0, 0, 1, 8, 0, 0, 6, 0},
		{0, 6, 3, 0, 0, 1, 0, 7, 0},
		{2, 9, 0, 0, 0, 5, 0, 0, 0},
		{1, 7, 5, 2, 0, 6, 8, 0, 0}
	};*/
	/*
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
	
	printf("Grille de depart : \n");
	affiche_grille(grille);
	printf("\n\n");
	
	
	int nb_parcours_grille = 0;
	
	while(1)//parcours toute la grille -> tant que la grille n'est pas remplie completement
	{
		int case_modifiee = 0;
		
		for(i = 0; i < 9; i++)//parcours une fois la grille
		{
			for(j = 0; j < 9; j++)
			{
				//pour chaque case : grille[i][j]
				if(grille[i][j] == 0)//on essaie de remplir la case
				{
					int valeur_case = remplir_la_case(grille, i, j);
					if(valeur_case)//1 à 9
					{
						grille[i][j] = valeur_case;
						case_modifiee = 1;
					}
					//sinon 0 : pas possible
				}
				//sinon elle est déja remplie
			}
		}
		
		nb_parcours_grille++;
		
		if(case_modifiee == 0)//termine si on ne modifie aucune case
		{
			break;
		}
	}
	
	printf("Grille completee : \n");
	printf("Nombre de parcours de grille : %i\n", nb_parcours_grille-1);
	affiche_grille(grille);
	
	return 0;
}
