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

Donnee *pile = NULL;    // Pile de donn�es
Index top = 0;          // Initialisation du sommet

Retcode PileInit()
{
    pile = malloc(MAX_PILE_D * sizeof(Donnee)); // On alloue la m�moire

    if (pile == NULL)                           // Si la pile n'a pas �t� impl�ment�
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
        *(pile + top++) = val; // On ajoute la valeur au sommet de la pile et on incr�mente le sommet
        return OK;
    }
}

Retcode PilePop(Donnee *val)
{
    if (pile == NULL)               // Si la pile est vide
        return ERR_PILE_VIDE;

    else
    {
        *val = *(pile + --top);     // On d�cr�mente le sommet et on r�cup�re la valeur au sommet de la pile
        *(pile + top--) = 0;        // On met � 0 la valeur au sommet de la pile et on d�cr�mente le sommet
        return OK;
    }
}

Retcode PileGet(Donnee *val)
{
    if (top == 0)                   // Si la pile est vide
        return ERR_PILE_VIDE;

    else
    {
        *val = *(pile + --top);     // On d�cr�mente le sommet et on r�cup�re la valeur au sommet de la pile
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

        *(pile + index) = val;                                              // On ajoute la valeur � l'index
        top++;                                                              // On incr�mente le sommmet
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
        *val = *(pile + index);                                             // On r�cup�re la valeur � l'index
        *(pile + index) = 0;                                                // On remet � 0 la valeur � l'index
        top--;                                                              // On d�cr�mente le sommet

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
        *val = *(pile + index); // On r�cup�re la valeur � l'index
        return OK;
    }
}

Index PileMax()
{
    return MAX_PILE_D;  // On retourne le nombre maximum d'�l�ments dans la pile
}

Index PileTop()
{
    return top; // On retourne le nombre d'�l�ments actifs dans la pile
}
