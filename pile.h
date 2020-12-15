/*
** Auteur   Bruno Poterie
** Projet   FORTH
** Fichier  pile.h
** Date     18/11/2020
** Contenu  interface de la gestion de la pile de donn�es
*/

#ifndef PILE_H
#define PILE_H

#include "forth.h"

extern Retcode PileInit();	// (r�)initialise la pile de donn�es

extern Retcode PilePush(Donnee val); // ajoute la valeur en param�tre sur le sommet de la pile. Retourne 0 si OK, un code d�erreur sinon
extern Retcode PilePop(Donnee *val); // retire la valeur du sommet de la pile et la retourne via le param�tre. Retourne 0 si OK; un code d�erreur sinon
extern Retcode PileGet(Donnee *val); // r�cup�re la valeur au sommet de la pile et la renvoie via le param�tre. Renvoie 0 si OK; un code d�erreur sinon

extern Retcode PilePushN(Donnee val, Index index); // ins�re la valeur pass�e au-dessus de l'�l�ment indiqu� par l'index. PushN(val,0) == Push(val). Retour idem
extern Retcode PilePopN(Donnee *val, Index index); // renvoie et retire l'�l�ment indiqu� par l'index. PopN(val,0) == Pop(val). Retour idem
extern Retcode PileGetN(Donnee *val, Index index); // r�cup�re la valeur de l'�l�ment indiqu� par l'index. GetN(val,0) == Get(val). Retour idem

extern Index PileMax(); // retourne la nombre maximum d'�l�ments dans la pile
extern Index PileTop(); // retourne le nombre d'�l�ments actifs dans la pile

#endif
