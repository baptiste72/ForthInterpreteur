/*
** Auteur   Julie Masia / Constantin Chtanko / Baptiste Chauvelier
** Projet   FORTH
** Fichier  pile.c
** Date     30/11/2020
** Contenu  module de gestion de la pile
*/

#include "pile.h"
#include <stdlib.h>

#define MAX_PILE_D 5    // Taille maximum de la pile

Donnee *pile = NULL;    // Pile de données
Index top = 0;          // Initialisation du sommet

Retcode PileInit()
{
    pile = malloc(MAX_PILE_D * sizeof(Donnee)); // On alloue la mémoire

    if (pile == NULL)                           // Si la pile n'a pas été implémenté
        return ERR_NON_IMPL;

    else
        return OK;
}

Retcode PilePush(Donnee val)
{
    if (top > MAX_PILE_D - 1)  // Si l'on sort de la pile
        return ERR_PILE_OUT;

    else
    {
        *(pile + top++) = val; // On ajoute la valeur au sommet de la pile et on incrémente le sommet
        return OK;
    }
}

Retcode PilePop(Donnee *val)
{
    if (pile == NULL)               // Si la pile est vide
        return ERR_PILE_VIDE;

    else
    {
        *val = *(pile + --top);     // On décrémente le sommet et on récupère la valeur au sommet de la pile
        *(pile + top--) = 0;        // On met à 0 la valeur au sommet de la pile et on décrémente le sommet
        return OK;
    }
}

Retcode PileGet(Donnee *val)
{
    if (top == 0)                   // Si la pile est vide
        return ERR_PILE_VIDE;

    else
    {
        *val = *(pile + --top);     // On décrémente le sommet et on récupère la valeur au sommet de la pile
        return OK;
    }
}

Retcode PilePushN(Donnee val, Index index)
{
    if (top > MAX_PILE_D - 1)                                               // Si l'on sort de la pile
        return ERR_PILE_OUT;

    else
    {
        for (Index iteration = top; iteration > index; iteration--)
            *(pile + iteration) = *(pile + (iteration - 1));                // On remonte les valeurs de la pile

        *(pile + index) = val;                                              // On ajoute la valeur à l'index
        top++;                                                              // On incrémente le sommmet
        return OK;
    }
}

Retcode PilePopN(Donnee *val, Index index)
{
    if (pile == NULL)                                                       // Si la pile est vide
        return ERR_PILE_VIDE;

    else if (index >= top)                                                  // Si l'on sort de la pile
        return ERR_PILE_OUT;

    else
    {
        *val = *(pile + index);                                             // On récupère la valeur à l'index
        *(pile + index) = 0;                                                // On remet à 0 la valeur à l'index
        top--;                                                              // On décrémente le sommet

        for (Index iteration = index; iteration < top; iteration++)
            *(pile + iteration) = *(pile + (iteration + 1));                // On descend les valeurs de la pile

        return OK;
    }
}

Retcode PileGetN(Donnee *val, Index index)
{
    if (pile == NULL)           // Si la pile est vide
        return ERR_PILE_VIDE;

    else if (index >= top)      // Si l'on sort de la pile
        return ERR_PILE_OUT;

    else
    {
        *val = *(pile + index); // On récupère la valeur à l'index
        return OK;
    }
}

Index PileMax()
{
    return MAX_PILE_D;  // On retourne le nombre maximum d'éléments dans la pile
}

Index PileTop()
{
    return top; // On retourne le nombre d'éléments actifs dans la pile
}
