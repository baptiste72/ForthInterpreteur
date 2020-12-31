/*
** Auteur   Julie Masia / Constantin Chtanko / Baptiste Chauvelier
** Projet   FORTH
** Fichier  testpile.c
** Date     30/11/2020
** Contenu  module de test de la pile
*/

#include "pile.h"
#include <stdio.h>

int main(int argc, char * argv[])
{
    Donnee recupValeur;

    PileInit();
    // Etat de la pile ()

    PilePush(5);
    // Etat de la pile (5)

    PilePush(9);
    // Etat de la pile (5, 9)

    PilePush(2);
    // Etat de la pile (5, 9, 2)

    PilePush(3);
    // Etat de la pile (5, 9, 2, 3)

    PilePush(1);
    // Etat de la pile (5, 9, 2, 3, 1)

    PileGet(&recupValeur);
    // Etat de la pile (5, 9, 2, 3, 1)
    // On est censé récupérer la valeur 1
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 4);
    // Etat de la pile (5, 9, 2, 3, 1)
    // On est censé récupérer la valeur 1
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 3);
    // Etat de la pile (5, 9, 2, 3, 1)
    // On est censé récupérer la valeur 3
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 2);
    // Etat de la pile (5, 9, 2, 3, 1)
    // On est censé récupérer la valeur 2
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 1);
    // Etat de la pile (5, 9, 2, 3, 1)
    // On est censé récupérer la valeur 9
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 0);
    // Etat de la pile (5, 9, 2, 3, 1)
    // On est censé récupérer la valeur 5
    printf("%ld\n", recupValeur);

    PilePopN(&recupValeur, 0);
    // Etat de la pile (9, 2, 3, 1)
    // On est censé récupérer la valeur 5
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 0);
    // Etat de la pile (9, 2, 3, 1)
    // On est censé récupérer la valeur 9
    printf("%ld\n", recupValeur);

    PilePopN(&recupValeur, 0);
    // Etat de la pile (2, 3, 1)
    // On est censé récupérer la valeur 9
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 0);
    // Etat de la pile (2, 3, 1)
    // On est censé récupérer la valeur 2
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 1);
    // Etat de la pile (2, 3, 1)
    // On est censé récupérer la valeur 3
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 2);
    // Etat de la pile (2, 3, 1)
    // On est censé récupérer la valeur 1
    printf("%ld\n", recupValeur);

    PilePushN(8, 0);
    // Etat de la pile (8, 2, 3, 1)

    PileGetN(&recupValeur, 0);
    // Etat de la pile (8, 2, 3, 1)
    // On est censé récupérer la valeur 8
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 1);
    // Etat de la pile (8, 2, 3, 1)
    // On est censé récupérer la valeur 2
    printf("%ld\n", recupValeur);

    PilePushN(4, 2);
    // Etat de la pile (8, 2, 4, 3, 1)

    PileGetN(&recupValeur, 2);
    // Etat de la pile (8, 2, 4, 3, 1)
    // On est censé récupérer la valeur 4
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 1);
    // Etat de la pile (8, 2, 4, 3, 1)
    // On est censé récupérer la valeur 2
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 3);
    // Etat de la pile (8, 2, 4, 3, 1)
    // On est censé récupérer la valeur 3
    printf("%ld\n", recupValeur);

    PilePop(&recupValeur);
    // Etat de la pile (8, 2, 4, 3)
    // On est censé récupérer la valeur 1
    printf("%ld\n", recupValeur);

    PileGet(&recupValeur);
    // Etat de la pile (8, 2, 4, 3)
    // On est censé récupérer la valeur 3
    printf("%ld\n", recupValeur);

    PilePushN(7, 4);
    // Etat de la pile (8, 2, 4, 3, 7)

    PileGet(&recupValeur);
    // Etat de la pile (8, 2, 4, 3, 7)
    // On est censé récupérer la valeur 7
    printf("%ld\n", recupValeur);

    PilePopN(&recupValeur, 3);
    // Etat de la pile (8, 2, 4, 7)
    // On est censé récupérer la valeur 3
    printf("%ld\n", recupValeur);

    PileGetN(&recupValeur, 3);
    // Etat de la pile (8, 2, 4, 7)
    // On est censé récupérer la valeur 7
    printf("%ld\n", recupValeur);

    PilePush(10);
    // Etat de la pile (8, 2, 4, 7, 10)

    PileGet(&recupValeur);
    // Etat de la pile (8, 2, 4, 7, 10)
    // On est censé récupérer la valeur 10
    printf("%ld\n", recupValeur);

    PilePop(&recupValeur);
    // Etat de la pile (8, 2, 4, 7, 10)
    // On est censé récupérer la valeur 10
    printf("%ld\n", recupValeur);

    PileInit();
    // Etat de la pile ()

    PilePushN(6, 0);
    // Etat de la pile (6)

    PileGet(&recupValeur);
    // Etat de la pile (6)
    // On est censé récupérer la valeur 6
    printf("%ld\n", recupValeur);

    return 0;
}
