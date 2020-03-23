# Solveur de Sudoku

Ce projet s'inscrit dans le cadre du projet de groupe de première année, à l'INSA Centre-Val de Loire.  
Il est réalisé par Nicolas BÉDRUNES, Arthur JAROUSSEAU, Ewan ROUGIER et Amine ZOUAOUI.

Dans le dossier `code`, il y a le code source ainsi que l'exécutable (`main.exe` pour Windows et `main` pour Linux).

Dans le dossier `grilles`, il y a des grilles de Sudoku qui sont ensuite chargées par le programme.  
Ces grilles sont parues dans le journal *"La République du Centre"*. Le nom d'un fichier commence par sa difficulté (F : Facile, M : Moyen, D : Difficile), puis il y a la date de parution de la grille dans le journal. L'extension est `.sudoku` afin d'identifier qu'il s'agit bien d'une grille de Sudoku.  
Par exemple, la grille parue le 23 décembre 2019 et de niveau facile a pour nom `F-2019-12-23.sudoku`.

## Fonctionnement du programme

**Pour l'instant, ce programme ne fonctionne que en __console__ et pour des Sudoku de __niveau Facile__. Nous sommes en train de travailler à l'implémentation graphique, ainsi qu'à l'amélioration de l'algorithme pour des Sudoku plus difficiles.**

Lorque vous lancez le programme, celui-ci vous demande de charger une grille afin qu'il essaie de la compléter. Le fichier contenant la grille doit se trouver dans le même dossier que l'exécutable ou dans le dossier `grilles`. Il suffit d'indiquer le nom du fichier, mais sans l'extension `.sudoku` (celle-ci sera rajoutée automatiquement).

*Ce projet est en cours de réalisation, des informations complémentaires arriveront prochainement...*
