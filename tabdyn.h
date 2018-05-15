/*                            tabDyn.h                                */

#ifndef  __TAB_DYN__      // afin d'eviter les doubles declarations
#define  __TAB_DYN__
#include "mytype.h"

typedef unsigned int Uint;

typedef struct{
    Uint size, top;
    myType **T;
}tabDyn;


/* --- L'init. Il faut créé dynamiquement un tableau de SIZE entiers --- */
tabDyn * constructTabDyn();

/* --- Detruire le tableau --- */
void   destructTabDyn (tabDyn *);

/* --- Affichage du tableau --- */
void   afficheTabDyn(tabDyn *);

/* --- Ajout une valeur. Le tableau peut etre agrandit, donc pt modifie --- */
void   ajout(tabDyn *, myType*);

/* --- Rend la position ou on a ajoute une valeur --- */
int    getFinAdd( tabDyn * ) ;

/* --- rend la taille du tableau --- */
int    getSize( tabDyn * ) ;

/* --- rend la valeur à la position du tableau --- */
myType * getVal( tabDyn *, int ) ;

/* --- rend vrai si on est a la fin du tableau --- */
int    isEnd(tabDyn *) ;

/* --- rend vrai si le tableau est vide --- */
int    isEmpty(tabDyn * ) ;

// ###########################################################################

#endif

