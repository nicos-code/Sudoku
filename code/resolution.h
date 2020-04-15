#ifndef RESOLTION_H
#define RESOLTION_H

int remplir_la_grille(int grille[9][9]);
int remplir_la_case(int grille[9][9], int i, int j);
int verif_col(int grille[9][9], int chiffre_saisir, int j);
int verif_ligne(int grille[9][9], int chiffre_saisir, int i);
int verif_bloc(int grille[9][9], int chiffre_saisir, int i, int j);

#endif //RESOLTION_H
