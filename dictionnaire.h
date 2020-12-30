/*
** Auteur   Bruno Poterie
** Projet   FORTH
** Fichier  dictionnaire.h
** Date     18/11/2020
** Contenu  interface de la gestion du dictionnaire des mots
*/

#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include "forth.h"

/*
** DEFINITIONS
*/

// types des mots du dictionnaire
typedef enum { MOT_NOYAU, MOT_COMPILE, MOT_VARIABLE, MOT_ANONYME } TypeMot;

// liste des mots du noyau
typedef enum
{
    DICO_NONE
    ,DICO_QUIT
    ,DICO_COMM1, DICO_COMM2, DICO_SLASH, DICO_DEF, DICO_FIN_DEF, DICO_VARIABLE, DICO_DOTTXT, DICO_TXT
    ,DICO_DOT, DICO_DOTS, DICO_SPACE, DICO_SPACES, DICO_EMIT
    ,DICO_GET, DICO_SET
    ,DICO_DROP, DICO_NIP, DICO_DUP, DICO_SWAP, DICO_OVER, DICO_ROT, DICO_MINUSROT, DICO_PICK, DICO_ROLL
    ,DICO_ASKDUP, DICO_TRUE, DICO_FALSE, DICO_INF, DICO_INFEGAL, DICO_EGAL, DICO_DIFF, DICO_ZEROEGAL, DICO_ZERODIFF
    ,DICO_NEGATE, DICO_PLUS, DICO_MOINS, DICO_MULT, DICO_DIV, DICO_MOD, DICO_DIVMOD, DICO_ABS, DICO_MIN, DICO_MAX
} IdNoyau;

// Définition du profil d'une fonction sans paramètre retournant un code d'erreur
// (en fait, il peut y avoir autant de paramètres que l'on veut)
// Cette définition doit nécessairement précéder la déclaration de la structure Entree,
// puisque celle-ci l'utilise
typedef Retcode (*CodeMot)();

// valeurs de composition des flags
#define DICO_EST_SYSTEME    0x0001
#define DICO_EST_STANDARD   0x0002
#define DICO_EST_AMOVIBLE   0x0010
#define DICO_EST_DIRECT     0x0100
#define DICO_EST_INDIRECT   0x0200
#define DICO_EST_CONSTRUIT  0x0400
#define DICO_EST_FONCTEUR   0x0800
// regroupements courants
#define DICO_NOYAU (DICO_EST_SYSTEME|DICO_EST_STANDARD|DICO_EST_DIRECT)
#define DICO_SYSVAR (DICO_EST_SYSTEME|DICO_EST_STANDARD|DICO_EST_INDIRECT)
#define DICO_USERVAR (DICO_EST_AMOVIBLE|DICO_EST_INDIRECT)

// taille maximum de la longueur du nom d'un mot (0 terminal non compris)
#define DICO_NOM_MAX 31

// définition de la structure d'une entrée de dictionnaire
typedef struct
{
    char *mot;
    TypeMot type;
    IdNoyau id;
    int flags;
    Donnee val;
    CodeMot code;
    bool supprimable;
} Entree;

// on définit un type qui référence une entrée - un pointeur, donc
typedef Entree * RefEntree;

/*
** FONCTIONS
*/

// initialise le dictionnaire et charge les entrées "système"
extern Retcode DicoInit();

// indifférent à maj./min.Retourne dans ptr l’adresse de l’entrée si trouvée
// renvoie 0 si trouvé, un code d’erreur sinon
extern Retcode DicoRecherche(char * mot, RefEntree *refptr);

// ajoute une entrée au dictionnaire
// initialise les éléments de l'entrée avec les paramètres
// renvoie l'adresse de l'entrée via le double pointeur refptr (vérifier avant que le pointeur passé n'est pas null)
// ne vérifie pas si il y a doublon
extern Retcode DicoAdd(char * mot,TypeMot type,IdNoyau id,int flags,Donnee val,CodeMot code,RefEntree *refptr);

// cas particulier de DicoAdd : ajout d'une entrée de type variable
// la fonction dont on passera l'adresse pour créer l'entrée (paramètre code de DicoAdd())
// est Code_RefValue() (définie dans noyau.h)
extern Retcode DicoAddVar(char * mot, RefEntree *refptr);

// suppression de la part du dictionnaire postérieur à l'entrée, y incluse (au sens de plus réçent)
extern Retcode DicoSupp(RefEntree ref);

#define NONE "NONE"
#define QUIT "QUIT"
#define COMM1 "("
#define COMM2 ")"
#define SLASH "/"
#define DEF ":"
#define FIN_DEF ";"
#define VARIABLE "VARIABLE"
#define DOTTXT ".\""
#define TXT "\""
#define DOT "."
#define DOTS ".S"
#define SPACE "SPACE"
#define SPACES "SPACES"
#define MOT_DICO_EMIT "EMIT"
#define GET "GET"
#define SET "SET"
#define DROP "DROP"
#define NIP "NIP"
#define DUP "DUP"
#define SWAP "SWAP"
#define OVER "OVER"
#define ROT "ROT"
#define MINUSROT "MINUSROT"
#define PICK "PICK"
#define ROLL "ROLL"
#define ASKDUP "ASKDUP"
#define TRUE "TRUE"
#define FALSE "FALSE"
#define INF "<"
#define SUP ">"
#define EGAL "="
#define DIFF "!="
#define ZEROEGAL "0="
#define ZERODIFF "0!="
#define NEGATE "NEGATE"
#define PLUS "+"
#define MOINS "-"
#define MULT "*"
#define DIV "/"
#define MOD "MOD"
#define DIVMOD "/MOD"
#define ABS "ABS"
#define MIN "MIN"
#define MAX "MAX"

#endif // DICTIONNAIRE_H
