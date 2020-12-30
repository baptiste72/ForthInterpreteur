/*
** Auteur   Julie Masia / Constantin Chtanko / Baptiste Chauvelier
** Projet   FORTH
** Fichier  dictionnaire.c
** Date     24/12/2020
** Contenu  module de gestion du dictionnaire des mots
*/

#include "dictionnaire.h"
#include "noyau.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Retcode DicoInit()
{
    RefEntree entree = NULL;

    DicoAdd(QUIT, MOT_NOYAU, DICO_QUIT, DICO_NOYAU, 0, Code_Quit, &entree);
	DicoAdd(DUP, MOT_NOYAU, DICO_DUP, DICO_NOYAU, 0, Code_Dup, &entree);
	DicoAdd(SWAP, MOT_NOYAU, DICO_SWAP, DICO_NOYAU, 0, Code_Swap, &entree);
	DicoAdd(ROLL, MOT_NOYAU, DICO_ROLL, DICO_NOYAU, 0, Code_Roll, &entree);
	DicoAdd(PLUS, MOT_NOYAU, DICO_PLUS, DICO_NOYAU, 0, Code_Plus, &entree);
	DicoAdd(DOT, MOT_NOYAU, DICO_DOT, DICO_NOYAU, 0, Code_Dot, &entree);
	DicoAdd(SLASH, MOT_NOYAU, DICO_SLASH, DICO_NOYAU, 0, Code_Slash, &entree);
}

Retcode DicoRecherche(char * mot, RefEntree *refptr)
{
    *refptr = mot;
    return OK;
}

Retcode DicoAdd(char * mot, TypeMot type, IdNoyau id, int flags, Donnee val, CodeMot code, RefEntree *refptr)
{
    RefEntree nouvelleEntree = NULL;
    nouvelleEntree = malloc(sizeof(Entree));    // On alloue la mémoire

    if (nouvelleEntree == NULL)                 // Si le dictionnaire n'a pas été implémenté
        return ERR_NON_IMPL;

    else
    {
        if (strlen(mot) < DICO_NOM_MAX)
                nouvelleEntree->mot = mot;

        nouvelleEntree->type = type;
        nouvelleEntree->id = id;
    	nouvelleEntree->flags = flags;
    	nouvelleEntree->val = val;
    	nouvelleEntree->code = code;

    	*refptr = nouvelleEntree;

        return OK;
    }
}
