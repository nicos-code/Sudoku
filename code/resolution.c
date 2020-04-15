#include "resolution.h"

int remplir_la_grille(int grille[9][9])
{
	int i, j;
	int nb_parcours_grille = 0;
	int case_modifiee = 1;
	
	while(case_modifiee)//parcours toute la grille -> tant qu'on peut remplir la grille
	{
		case_modifiee = 0;
		
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
	}
	
	return nb_parcours_grille-1;//car on parcours une fois la grille sans aucune modification pour sortir du while
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
